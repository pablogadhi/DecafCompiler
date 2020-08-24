grammar Decaf;

fragment LETTER: [a-zA-Z];
fragment DIGIT: [0-9];
ID: LETTER (LETTER | DIGIT)*;
NUM: DIGIT (DIGIT)*;
//TODO Change CHAR definition to the right one
CHAR: LETTER;
WS: [ \t\r\n]+ -> channel(HIDDEN);

program: 'class' 'Program' '{' (declaration)* '}';
declaration:
	structDeclaration
	| varDeclaration
	| methodDeclaration;
varDeclaration: varType ID ';' | varType ID '[' NUM ']' ';';
structDeclaration: 'struct' ID '{' (varDeclaration)* '}';
varType:
	'int'
	| 'char'
	| 'boolean'
	| 'struct' ID
	| structDeclaration
	| 'void';
//TODO Make sure this is the right translation of a*, 
methodDeclaration:
	methodType ID '(' (parameter (',' parameter)*)? ')' block;
methodType: 'int' | 'char' | 'boolean' | 'void';
parameter: parameterType ID | parameterType ID '[' ']';
parameterType: 'int' | 'char' | 'boolean';
block: '{' (varDeclaration)* (statement)* '}';
statement:
	'if' '(' expression ')' block ('else' block)?
	| 'while' '(' expression ')' block
	| 'return' (expression)? ';'
	| methodCall ';'
	| block
	| location '=' expression
	| (expression)? ';';
location: (ID | ID '[' expression ']') ('.' location)?;
expression:
	location
	| methodCall
	| literal
	| '(' expression ')'
	| '!' expression
	| '-' expression
	| expression arith_high_precedence expression
	| expression arith_low_precedence expression
	| expression rel_op expression
	| expression eq_op expression
	| expression cond_and expression
	| expression cond_or expression;
//TODO Make sure this is the right translation of a*, 
methodCall: ID '(' (arg (',' arg)*)? ')';
arg: expression;
// op: arith_op | rel_op | eq_op | cond_op;
arith_op: arith_high_precedence | arith_low_precedence;
arith_high_precedence: '*' | '/' | '%';
arith_low_precedence: | '+' | '-';
rel_op: '<' | '<=' | '>' | '>=';
eq_op: '==' | '!=';
// cond_op: cond_and | cond_or;
cond_and: '&&';
cond_or: '||';
literal: int_literal | char_literal | bool_literal;
int_literal: NUM;
char_literal: '\'' CHAR '\'';
bool_literal: 'true' | 'false';