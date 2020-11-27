grammar Decaf;

@parser::postinclude {
#include "../structs/symb_table.h"
#include "../structs/triple.h"
#include "../structs/error_item.h"
}

@parser::declarations {
shared_ptr<SymbolTable> table_head = make_shared<SymbolTable>(Method("__global__", ""));
shared_ptr<SymbolTable> table_top;
ErrorHandler *e_handler;
int scope_counter = 0;
}

@parser::members {
pair<SymbolTable, vector<vector<string>>> symbol_table();
shared_ptr<SymbolTable> &symbols();
void set_error_handler(ErrorHandler*);
}

@parser::definitions {
pair<SymbolTable, vector<vector<string>>> DecafParser::symbol_table() {
  return table_head->flatten();
}

shared_ptr<SymbolTable> &DecafParser::symbols() {
	return table_head;
}

void DecafParser::set_error_handler(ErrorHandler *handler) {
  e_handler = handler;
}
}

program
	locals[Method main]
	@init {
table_head->init_basic_types();
table_top = table_head;
  }
	@after {
if(!get_where<Method>(table_head->methods(), [](Method& m){return m.name() == "main" && m.param_signature().size() == 0;}, &$main)){
  e_handler->get_lambda(NO_MAIN, 0, 0)();
  }
}: 'class' 'Program' '{' (declaration)* '}';

declaration:
	structDeclaration
	| varDeclaration[nullptr]
	| methodDeclaration;

varDeclaration[int *struct_size]
	locals[string name, string d_type, int size, int line, int pos]
	@after {
if($struct_size != nullptr){
  *struct_size += $size;
  table_top->add_type($name, $d_type, $size, e_handler->get_lambda(IDENT_DEFINED, $line, $pos, vector<string>{$name, table_top->name()}));
} else {
  table_top->add_symbol($name, $d_type, $size, e_handler->get_lambda(IDENT_DEFINED, $line, $pos, vector<string>{$name, table_top->name()}));
}
  }:
	varType ID ';' {$name = $ID.text; $d_type = $varType.d_type; $size = $varType.size; $line = $ID.line; $pos = $ID.pos;
    }
	| varType ID '[' NUM ']' ';' {
$name = $ID.text; $d_type = $varType.d_type; $size = $varType.size * stoi($NUM.text) ; $line = $ID.line; $pos = $ID.pos;
if(stoi($NUM.text) <= 0){
  e_handler->get_lambda(WRONG_NUM_ARRAY, $NUM.line, $NUM.pos)();
}
    };

structDeclaration
	returns[string d_type, int size, shared_ptr<SymbolTable> new_table]
	locals[int l_size = 0]
	@after {
    $size = $l_size;
  }:
	'struct' ID {
$new_table = make_shared<SymbolTable>(Method($ID.text, "struct"), table_top);
table_top = $new_table;
  } '{' (varDeclaration[&$l_size])* '}' {
table_top = table_top->parent();
table_top->add_type($ID.text, "struct", $l_size, e_handler->get_lambda(IDENT_DEFINED, $ID.line, $ID.pos, vector<string>{$ID.text, table_top->name()}));
table_top->add_child($new_table);
$d_type = $ID.text;
    };

varType
	returns[string d_type, int size]:
	'int' {$d_type = "int"; $size = 4;}
	| 'char' {$d_type = "char"; $size = 1;}
	| 'boolean' {$d_type = "boolean"; $size = 1;}
	| 'struct' ID {
auto struct_name = $ID.text;
Type type_ctr;
if(recursive_lookup<Type>(table_top, [&](shared_ptr<SymbolTable> table){return table->types();}, [struct_name](Type& t){ return t.name() == struct_name && t.type() == "struct";}, &type_ctr)){
  $d_type = type_ctr.name(); $size = type_ctr.size();
} else {
  e_handler->get_lambda(IDENT_NOT_DEFINED, $ID.line, $ID.pos, vector<string>{struct_name});
}}
	| structDeclaration {$d_type = $structDeclaration.d_type; $size = $structDeclaration.size;
    }
	| 'void' {$d_type = "void"; $size = 0;};

methodDeclaration
	locals[vector<Symbol> params, shared_ptr<SymbolTable> new_table, string alias]:
	methodType ID '(' (
		parameter[&$params] (',' parameter[&$params])*
	)? ')' {
vector<string> param_types;
transform($params.begin(), $params.end(), back_inserter(param_types), [](Symbol &s){return s.type();});
$new_table = make_shared<SymbolTable>(Method($ID.text, $methodType.d_type, param_types), table_top);
$alias = $ID.text + "_" + to_string(scope_counter);
scope_counter++;
table_top->add_method($ID.text, $methodType.d_type, param_types, $alias, e_handler->get_lambda(IDENT_DEFINED, $ID.line, $ID.pos, vector<string>{$ID.text, table_top->name()}));
table_top->add_child($new_table);
for(auto &symb: $params){
  $new_table->add_symbol(symb.name(), symb.type(), symb.size());
}
table_top = $new_table;
  } block[$ID.text] {
table_top = table_top->parent();
    };

methodType
	returns[string d_type]:
	'int' {$d_type = "int";}
	| 'char' {$d_type = "char";}
	| 'boolean' {$d_type = "boolean";}
	| 'void' {$d_type = "void";};

parameter[vector<Symbol> *meth_params]:
	parameterType ID {meth_params->push_back(Symbol($ID.text, $parameterType.d_type, $parameterType.size, 0));
    }
	//TODO Check if this is allowed
	| parameterType ID '[' ']';

parameterType
	returns[string d_type, int size]:
	'int' {$d_type = "int"; $size = 4;}
	| 'char' {$d_type = "char"; $size = 1;}
	| 'boolean' {$d_type = "boolean"; $size = 1;};

block[string method_name]
	returns[vector<int> next_list]
	locals[shared_ptr<SymbolTable> new_table]
	@init {
if(method_name == ""){
  $new_table = make_shared<SymbolTable>(Method(table_top->name() + "_" + to_string(scope_counter), table_top->id().type()), table_top);
  scope_counter++;
  table_top->add_method($new_table->name(), table_top->id().type(), vector<string>{});
  table_top->add_child($new_table);
  table_top = $new_table;
}
  }
	@after {
if(method_name == ""){
  table_top = table_top->parent();
}
  }:
	'{' (varDeclaration[nullptr])* (
		statement {$next_list = $statement.next_list;}
	)* '}';

statement
	returns[vector<int> next_list]:
	'if' '(' expression {
if($expression.d_type != "boolean"){
  e_handler->get_lambda(EXPR_TYPE_ERROR, $expression.start->getLine(), $expression.start->getCharPositionInLine()+ 1, vector<string>{$expression.d_type, "boolean"})();
}
} ')' true_block = block[""] ('else' false_block = block[""])? # ifStatement
	| 'while' '(' expression {
if($expression.d_type != "boolean"){
  e_handler->get_lambda(EXPR_TYPE_ERROR, $expression.start->getLine(), $expression.start->getCharPositionInLine(), vector<string>{$expression.d_type, "boolean"})();
}
  } ')' block[""] # whileStatement
	| r = 'return' (
		expression {
if($expression.d_type != table_top->id().type()){
  e_handler->get_lambda(WRONG_RETURN_TYPE, $r.line, $r.pos, vector<string>{table_top->name(), table_top->id().type(), $expression.d_type})();
}
  }
	)? ';'				# returnStatement
	| methodCall ';'	# methodCallStatement
	| block[""]			# blockStatement
	| location '=' expression {
if($location.d_type != $expression.d_type){
  e_handler->get_lambda(EXPR_TYPE_ERROR, $expression.start->getLine(), $expression.start->getCharPositionInLine(), vector<string>{$expression.d_type, $location.d_type})();
} 
}	# assignStatement
	| (expression)? ';'																																																											# exprStatement;

location
	returns[string d_type, shared_ptr<Address> addr]
	locals[bool array_check = false, shared_ptr<SymbolTable> old_top, Symbol out, Type type_info]: (
		ID
		| ID '[' expression ']' {$array_check = true;}
	) {
shared_ptr<SymbolTable> parent_table;
if(recursive_lookup<Symbol>(table_top, [&](shared_ptr<SymbolTable> t){return t->symbols();}, [&](Symbol &s){return s.name() == $ID.text;}, parent_table, &$out)){
  $d_type = $out.type();
  if($array_check){
    recursive_lookup<Type>(table_top, [&](shared_ptr<SymbolTable> t){return t->types();}, [&](Type &t){return t.name() == $out.type();}, &$type_info);
    if($type_info.size() == $out.size()){
      e_handler->get_lambda(IDENT_NOT_ARRAY, $ID.line, $ID.pos, vector<string>{$ID.text})();
    } else if($expression.d_type != "int"){
      e_handler->get_lambda(INDEX_NOT_INT, $ID.line, $ID.pos, vector<string>{$ID.text})();
    } 
  }
} else {
  e_handler->get_lambda(IDENT_NOT_DEFINED, $ID.line, $ID.pos, vector<string>{$ID.text})();
}
  } (
		'.' {
$old_top = table_top;
if(parent_table != nullptr){
auto children = parent_table->children();
if(children.find(Method($ID.text, "")) != children.end()){
  table_top = children[Method($ID.text, "")];
}
  }
} child = location {
$d_type = $location.d_type;
table_top = $old_top;
}
	)?;

expression
	returns[string d_type, shared_ptr<Address> addr, vector<int> false_list, vector<int> true_list]:
	'(' expression ')' {$d_type = $expression.d_type;} # parensExpr
	| literal {
$d_type = $literal.d_type;
} # literalExpr
	| methodCall {
if($methodCall.d_type == "void"){
  e_handler->get_lambda(NO_RETURN_IN_EXPR, $methodCall.line, $methodCall.pos, vector<string>{$methodCall.text})();
}else{
  $d_type = $methodCall.d_type;
}
} # methodCallExpr
	| location {
$d_type = $location.d_type;
} # locationExpr
	| '!' expression {
if($expression.d_type != "boolean"){
  e_handler->get_lambda(OPERAND_TYPE_MISSMATCH, $expression.start->getLine(), $expression.start->getCharPositionInLine(), vector<string>{"boolean"})();
}else{
	$d_type = $expression.d_type;
} 
} # notExpr
	| '-' expression {
// TODO Check the expression type
$d_type = $expression.d_type;
} # minusExpr
	| lexpr = expression arith_high_op rexpr = expression {
if($lexpr.d_type != "int" || $rexpr.d_type != "int"){
  e_handler->get_lambda(OPERAND_TYPE_MISSMATCH, $lexpr.start->getLine(), $lexpr.start->getCharPositionInLine(), vector<string>{"int"})();
}else{
	$d_type = $lexpr.d_type;
}
} # aritHighExpr
	| lexpr = expression arith_low_op rexpr = expression {
if($lexpr.d_type != "int" || $rexpr.d_type != "int"){
  e_handler->get_lambda(OPERAND_TYPE_MISSMATCH, $lexpr.start->getLine(), $lexpr.start->getCharPositionInLine(), vector<string>{"int"})();
}else{
	$d_type = $lexpr.d_type;
} 
} # aritLowExpr
	| lexpr = expression rel_op rexpr = expression {
if($lexpr.d_type != "int" || $rexpr.d_type != "int"){
  e_handler->get_lambda(OPERAND_TYPE_MISSMATCH, $lexpr.start->getLine(), $lexpr.start->getCharPositionInLine(), vector<string>{"int"})();
}else{
  $d_type = "boolean";
}
} # relExpr
	| lexpr = expression op = eq_op rexpr = expression {
auto valid_types = vector<string>{"int", "char", "boolean"};
if($lexpr.d_type != $rexpr.d_type){
  e_handler->get_lambda(OPERAND_TYPE_MISSMATCH, $lexpr.start->getLine(), $lexpr.start->getCharPositionInLine(), vector<string>{$lexpr.d_type})();
}else if(find(valid_types.begin(), valid_types.end(), $lexpr.d_type) == valid_types.end()){
  e_handler->get_lambda(CAN_NOT_USE_OPERATOR, $lexpr.start->getLine(), $lexpr.start->getCharPositionInLine(), vector<string>{$lexpr.d_type})();
}else if(find(valid_types.begin(), valid_types.end(), $rexpr.d_type) == valid_types.end()){
  e_handler->get_lambda(CAN_NOT_USE_OPERATOR, $rexpr.start->getLine(), $rexpr.start->getCharPositionInLine(), vector<string>{$rexpr.d_type})();
}else{
  $d_type = "boolean";
}
} # eqExpr
	| lexpr = expression and_op rexpr = expression {
if($lexpr.d_type != "boolean" || $rexpr.d_type != "boolean"){
  e_handler->get_lambda(OPERAND_TYPE_MISSMATCH, $lexpr.start->getLine(), $lexpr.start->getCharPositionInLine(), vector<string>{"boolean"})();
}else{
  $d_type = "boolean";
} 
} # andExpr
	| lexpr = expression or_op rexpr = expression {
if($lexpr.d_type != "boolean" || $rexpr.d_type != "boolean"){
  e_handler->get_lambda(OPERAND_TYPE_MISSMATCH, $lexpr.start->getLine(), $lexpr.start->getCharPositionInLine(), vector<string>{"boolean"})();
}else{
  $d_type = "boolean";
}
} # orExpr;

methodCall
	returns[string d_type, int line, int pos, shared_ptr<Address> addr]
	locals[vector<string> arg_types, Method out]:
	ID '(' (
		arg[&$arg_types] (',' arg[&$arg_types])*
	)? ')' {
if(!get_where<Method>(table_head->methods(), [&](Method &m){return m.name() == $ID.text && m.param_signature() == $arg_types;}, &$out)){
  auto msg_parts = vector<string>{$ID.text};
  msg_parts.insert(msg_parts.end(), $arg_types.begin(), $arg_types.end());
  e_handler->get_lambda(NO_METHOD_WITH_SIGN, $ID.line, $ID.pos, msg_parts)();
}
$d_type = $out.type(); $line = $ID.line; $pos = $ID.pos;
  };

arg[vector<string> *method_arg_types]:
	expression {method_arg_types->push_back($expression.d_type);};

arith_high_op
	returns[Operator op]:
	'*' {$op = Operator::MUL;}
	| '/' {$op = Operator::DIV;}
	| '%' {$op = Operator::MOD;};

arith_low_op
	returns[Operator op]:
	'+' {$op = Operator::SUM;}
	| '-' {$op = Operator::MINUS;};

rel_op
	returns[Operator op]:
	'<' {$op = Operator::LESS;}
	| '<=' {$op = Operator::LESS_EQ;}
	| '>' {$op = Operator::GREATER; }
	| '>=' {$op = Operator::GREATER_EQ;};

eq_op
	returns[Operator op]:
	'==' {$op = Operator::EQ;}
	| '!=' {$op = Operator::NOT_EQ;};

and_op: '&&';

or_op: '||';

literal
	returns[string d_type, shared_ptr<Address> addr]:
	int_literal {$d_type = "int";}			# intLiteral
	| char_literal {$d_type = "char";}		# charLiteral
	| bool_literal {$d_type = "boolean";}	# boolLiteral;

int_literal: NUM;

char_literal: CHAR;

bool_literal: 'true' | 'false';

fragment LETTER: [a-zA-Z];
fragment DIGIT: [0-9];
ID: LETTER (LETTER | DIGIT)*;
NUM: DIGIT (DIGIT)*;
//TODO Change CHAR definition to the right one
CHAR: '\'' LETTER '\'';
WS: [ \t\r\n]+ -> channel(HIDDEN);