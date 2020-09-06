grammar Decaf;

@parser::postinclude {
#include "../structs/symb_table.h"
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
void set_error_handler(ErrorHandler*);
}

@parser::definitions {
pair<SymbolTable, vector<vector<string>>> DecafParser::symbol_table() {
  return table_head->flatten();
}

void DecafParser::set_error_handler(ErrorHandler *handler){
  e_handler = handler;
}
}

fragment LETTER:[a-zA-Z];
fragment DIGIT: [0-9];
ID: LETTER (LETTER | DIGIT)*;
NUM: DIGIT (DIGIT)*;
//TODO Change CHAR definition to the right one
CHAR: '\'' LETTER '\'';
WS: [ \t\r\n]+ -> channel(HIDDEN);

program
	@init {
table_head->init_basic_types();
table_top = table_head;
  }
	@after {
if(!get_where<Method>(table_head->methods(), [](Method& m){return m.name() == "main" && m.param_signature().size() == 0;})){
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
$name = $ID.text; $d_type = $varType.d_type; $size = $varType.size * stoi($NUM.text); $line = $ID.line; $pos = $ID.pos;
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
if(get_where<Type>(table_top->types(), [struct_name](Type& t){ return t.name() == struct_name && t.type() == "struct";}, &type_ctr)){
  $d_type = type_ctr.name(); $size = type_ctr.size();
} else {
  e_handler->get_lambda(IDENT_NOT_DEFINED, $ID.line, $ID.pos, vector<string>{struct_name});
}}
	| structDeclaration {$d_type = $structDeclaration.d_type; $size = $structDeclaration.size;
    }
	| 'void' {$d_type = "void"; $size = 0;};

methodDeclaration
	locals[vector<string> params, shared_ptr<SymbolTable> new_table]:
	methodType ID '(' (
		parameter[&$params] (',' parameter[&$params])*
	)? ')' {
$new_table = make_shared<SymbolTable>(Method($ID.text, $methodType.d_type, $params), table_top);
table_top = $new_table;
  } block[$ID.text] {
table_top = table_top->parent();
table_top->add_method($ID.text, $methodType.d_type, $params, e_handler->get_lambda(IDENT_DEFINED, $ID.line, $ID.pos, vector<string>{$ID.text, table_top->name()}));
table_top->add_child($new_table);
    };

methodType
	returns[string d_type]:
	'int' {$d_type = "int";}
	| 'char' {$d_type = "char";}
	| 'boolean' {$d_type = "boolean";}
	| 'void' {$d_type = "void";};

parameter[vector<string> *meth_params]:
	parameterType ID {meth_params->push_back($parameterType.d_type);}
	//TODO Check if this is allowed
	| parameterType ID '[' ']';

parameterType
	returns[string d_type]:
	'int' {$d_type = "int";}
	| 'char' {$d_type = "char";}
	| 'boolean' {$d_type = "boolean";};

block[string method_name]
	locals[shared_ptr<SymbolTable> new_table]
	@init {
if(method_name == ""){
  $new_table = make_shared<SymbolTable>(Method(table_top->name() + "_" + to_string(scope_counter), ""), table_top);
  scope_counter++;
  table_top->add_method($new_table->name(), "void", vector<string>{});
  table_top->add_child($new_table);
  table_top = $new_table;
}
  }
	@after {
if(method_name == ""){
  table_top = table_top->parent();
}
  }: '{' (varDeclaration[nullptr])* (statement)* '}';

statement:
	'if' '(' expression ')' block[""] ('else' block[""])?
	| 'while' '(' expression ')' block[""]
	| r = 'return' (
		expression {
if($expression.d_type != table_top->id().type()){
  e_handler->get_lambda(WRONG_RETURN_TYPE, $r.line, $r.pos, vector<string>{table_top->name(), table_top->id().type(), $expression.d_type})();
}
  }
	)? ';'
	| methodCall ';'
	| block[""]
	| location '=' expression
	| (expression)? ';';

location
	returns[string d_type]
	locals[bool array_check = false]: (
		ID
		| ID '[' expression ']' {$array_check = true;}
	) {
Symbol out;
if(recursive_lookup<Symbol>(table_top, [&](shared_ptr<SymbolTable> t){return t->symbols();}, [&](Symbol &s){return s.name() == $ID.text;}, &out)){
  $d_type = out.type();
} else {
  e_handler->get_lambda(IDENT_NOT_DEFINED, $ID.line, $ID.pos, vector<string>{$ID.text})();
}
  } ('.' location {$d_type = $location.d_type;})?;

expression
	returns[string d_type]:
	location {$d_type = $location.d_type;}
	| methodCall {
if($methodCall.d_type == "void"){
  e_handler->get_lambda(NO_RETURN_IN_EXPR, $methodCall.line, $methodCall.pos, vector<string>{$methodCall.text})();
}
  }
	| literal {$d_type = $literal.d_type;}
	| '(' expression ')'
	| '!' expression
	| '-' expression
	// | low_arith_expr | eq_expr
	| expression arith_high_op expression
	| expression arith_low_op expression
	| expression rel_op expression
	| expression eq_op expression
	| expression '&&' expression
	| expression '||' expression;

// low_arith_expr[shared_ptr<SymbolTable> table] returns[string d_type]: high_arith_expr[$table] (
// arith_low_op high_arith_expr[$table] )*;

// high_arith_expr[shared_ptr<SymbolTable> table]: expression[$table] (arith_high_op
// expression[$table])*;

// or_expr[shared_ptr<SymbolTable> table]: and_expr[$table] ('||' and_expr[$table])*;

// and_expr[shared_ptr<SymbolTable> table]: eq_expr[$table] ('&&' eq_expr[$table])*;

// eq_expr[shared_ptr<SymbolTable> table]: rel_expr[$table] (rel_op rel_expr[$table])*;

// rel_expr[shared_ptr<SymbolTable> table]: expression[$table] (rel_op expression[$table])*;

methodCall
	returns[string d_type, int line, int pos]
	locals[vector<string> arg_types]:
	ID '(' (
		arg[&$arg_types] (',' arg[&$arg_types])*
	)? ')' {
Method out;
if(!get_where<Method>(table_head->methods(), [&](Method &m){return m.name() == $ID.text && m.param_signature() == $arg_types;}, &out)){
  auto msg_parts = vector<string>{$ID.text};
  msg_parts.insert(msg_parts.end(), $arg_types.begin(), $arg_types.end());
  e_handler->get_lambda(NO_METHOD_WITH_SIGN, $ID.line, $ID.pos, msg_parts)();
}else{
  $d_type = out.type(); $line = $ID.line; $pos = $ID.pos;
}
  };

arg[vector<string> *method_arg_types]:
	expression {method_arg_types->push_back($expression.d_type);};

arith_high_op: '*' | '/' | '%';

arith_low_op: '+' | '-';

rel_op: '<' | '<=' | '>' | '>=';

eq_op: '==' | '!=';

literal
	returns[string d_type]:
	int_literal {$d_type = "int";}
	| char_literal {$d_type = "char";}
	| bool_literal {$d_type = "boolean";};

int_literal: NUM;

char_literal: CHAR;

bool_literal: 'true' | 'false';