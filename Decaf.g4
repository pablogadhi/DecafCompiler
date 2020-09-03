grammar Decaf;

@parser::postinclude {
#include "../structs/symb_table.h"
#include "../structs/error_item.h"
}

@parser::declarations {
shared_ptr<SymbolTable> table_head = make_shared<SymbolTable>("__global__");
shared_ptr<SymbolTable> table_top;
ErrorHandler *e_handler;
int scope_counter = 0;
}

@parser::members {
SymbolTable symbol_table();
void set_error_handler(ErrorHandler*);
}

@parser::definitions {
SymbolTable DecafParser::symbol_table() {
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
}:
	'class' 'Program' '{' (declaration[table_head])* '}';

declaration[shared_ptr<SymbolTable> table]:
	structDeclaration[$table]
	| varDeclaration[$table, nullptr]
	| methodDeclaration[$table];

varDeclaration[shared_ptr<SymbolTable> table, int *struct_size]
	locals[string name, string d_type, int size, int line, int pos]
	@after {
if($struct_size != nullptr){
  *struct_size += $size;
  table->add_type($name, $d_type, $table->id(), $size, e_handler->get_lambda(IDENT_DEFINED, $line, $pos, vector<string>{$name, $table->id()}));
} else {
  table->add_symbol($name, $d_type, $table->id(), $size, e_handler->get_lambda(IDENT_DEFINED, $line, $pos, vector<string>{$name, $table->id()}));
}
  }:
	varType[$table] ID ';' {$name = $ID.text; $d_type = $varType.d_type; $size = $varType.size; $line = $ID.line; $pos = $ID.pos;
    }
	| varType[$table] ID '[' NUM ']' ';' {
$name = $ID.text; $d_type = $varType.d_type; $size = $varType.size * stoi($NUM.text); $line = $ID.line; $pos = $ID.pos;
if(stoi($NUM.text) <= 0){
  e_handler->get_lambda(WRONG_NUM_ARRAY, $NUM.line, $NUM.pos)();
}
    };

structDeclaration[shared_ptr<SymbolTable> table]
	returns[string d_type, int size, shared_ptr<SymbolTable> new_table]
	locals[int l_size = 0]
	@after {
    $size = $l_size;
  }:
	'struct' ID {
$new_table = make_shared<SymbolTable>($ID.text, $table);
  } '{' (
		varDeclaration[$new_table, &$l_size]
	)* '}' {
table->add_type($ID.text, "struct", $table->id(), $l_size, e_handler->get_lambda(IDENT_DEFINED, $ID.line, $ID.pos, vector<string>{$ID.text, $table->id()}));
table->add_child($new_table);
$d_type = $ID.text;
    };

varType[shared_ptr<SymbolTable> table]
	returns[string d_type, int size]:
	'int' {$d_type = "int"; $size = 4;}
	| 'char' {$d_type = "char"; $size = 1;}
	| 'boolean' {$d_type = "boolean"; $size = 1;}
	| 'struct' ID {
auto struct_name = $ID.text;
Type type_ctr;
if(get_where<Type>(table->types(), [struct_name](Type& t){ return t.name() == struct_name && t.type() == "struct";}, &type_ctr)){
  $d_type = type_ctr.name(); $size = type_ctr.size();
} else {
  // add_sem_error($ID.line, $ID.pos, "Struct " + $ID.text + " is undefined!");
}}
	| structDeclaration[$table] {$d_type = $structDeclaration.d_type; $size = $structDeclaration.size;
    }
	| 'void';

methodDeclaration[shared_ptr<SymbolTable> table]
	locals[vector<string> params, shared_ptr<SymbolTable> new_table]:
	methodType ID {$new_table = make_shared<SymbolTable>($ID.text, $table);} '(' (
		parameter[&$params] (',' parameter[&$params])*
	)? ')' block[$new_table, $ID.text] {
table->add_method($ID.text, $methodType.d_type, $table->id(), $params, e_handler->get_lambda(IDENT_DEFINED, $ID.line, $ID.pos, vector<string>{$ID.text, $table->id()}));
table->add_child($new_table);
    };

methodType
	returns[string d_type]:
	'int' {$d_type = "int";}
	| 'char' {$d_type = "char";}
	| 'boolean' {$d_type = "boolean";}
	| 'void' {$d_type = "void";};

parameter[vector<string> *meth_params]:
	parameterType ID {meth_params->push_back($parameterType.d_type);}
	| parameterType ID '[' ']';

parameterType
	returns[string d_type]:
	'int' {$d_type = "int";}
	| 'char' {$d_type = "char";}
	| 'boolean' {$d_type = "boolean";};

block[shared_ptr<SymbolTable> table, string method_name]
	locals[shared_ptr<SymbolTable> new_table]:
	{
if(method_name == ""){
  $new_table = make_shared<SymbolTable>($table->id() + "_" + to_string(scope_counter), $table);
  scope_counter++;
  table->add_method($new_table->id(), "void", $table->id(), vector<string>{});
  table->add_child($new_table);
} else {
  $new_table = $table;
}
  } '{' (
		varDeclaration[$new_table, nullptr]
	)* (statement[$new_table])* '}';

statement[shared_ptr<SymbolTable> table]:
	'if' '(' expression[$table] ')' block[$table, ""] (
		'else' block[$table, ""]
	)?
	| 'while' '(' expression[$table] ')' block[$table, ""]
	| 'return' (expression[$table])? ';'
	| methodCall[$table] ';'
	| block[$table, ""]
	| location[$table] '=' expression[$table]
	| (expression[$table])? ';';

location[shared_ptr<SymbolTable> table]
	returns[string d_type]: (
		ID
		| ID '[' expression[$table] ']'
	) {
Symbol out;
if(recursive_lookup<Symbol>($table, [&](shared_ptr<SymbolTable> t){return t->symbols();}, [&](Symbol &s){return s.name() == $ID.text;}, &out)){
  $d_type = out.type();
} else {
  e_handler->get_lambda(IDENT_NOT_DEFINED, $ID.line, $ID.pos, vector<string>{$ID.text})();
}
  } ('.' location[$table])?;

expression[shared_ptr<SymbolTable> table]
	returns[string d_type]:
	location[$table]
	| methodCall[$table]
	| literal {$d_type = $literal.d_type;}
	| '(' expression[$table] ')'
	| '!' expression[$table]
	| '-' expression[$table]
	// | low_arith_expr[$table] | eq_expr[$table]
	| expression[$table] arith_high_op expression[$table]
	| expression[$table] arith_low_op expression[$table]
	| expression[$table] rel_op expression[$table]
	| expression[$table] eq_op expression[$table]
	| expression[$table] '&&' expression[$table]
	| expression[$table] '||' expression[$table];

// low_arith_expr[shared_ptr<SymbolTable> table] returns[string d_type]: high_arith_expr[$table] (
// arith_low_op high_arith_expr[$table] )*;

// high_arith_expr[shared_ptr<SymbolTable> table]: expression[$table] (arith_high_op
// expression[$table])*;

// or_expr[shared_ptr<SymbolTable> table]: and_expr[$table] ('||' and_expr[$table])*;

// and_expr[shared_ptr<SymbolTable> table]: eq_expr[$table] ('&&' eq_expr[$table])*;

// eq_expr[shared_ptr<SymbolTable> table]: rel_expr[$table] (rel_op rel_expr[$table])*;

// rel_expr[shared_ptr<SymbolTable> table]: expression[$table] (rel_op expression[$table])*;

methodCall[shared_ptr<SymbolTable> table]
	locals[vector<string> arg_types]:
	ID '(' (
		arg[&$arg_types, $table] (
			',' arg[&$arg_types, $table]
		)*
	)? ')';

arg[vector<string> *method_arg_types, shared_ptr<SymbolTable> table]:
	expression[$table] {method_arg_types->push_back($expression.d_type);};

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