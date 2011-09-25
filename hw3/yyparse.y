%{
#include "tree.h"
#include "structures.h"


// better error reporting
#define YYERROR_VERBOSE

// bison requires that you supply this function
void yyerror(const char *msg)
{
      printf("ERROR(PARSER): %s\n", msg);
}

%}


%union {
  int var;  
 }
%token _BREAK 261 
%token _CASE 363  
%token _CATCH 262  
%token _CLASS 263 
%token _CONST 264 
%token _CONTINUE 265 
%token _DEFAULT 266 
%token _DO 362  
%token _ELSE 267  
%token _EXTENDS 268 
%token _FINALLY 270 
%token _FOR 271 
%token _FUNCTION 272 
%token _IF 273 
%token _IMPLEMENTS 274
%token _IMPORT 275 
%token _INTERFACE 276 
%token _INTERNAL 277 
%token _NULL 278 
%token _PACKAGE 279 
%token _PRIVATE 280 
%token _PROTECTED 281 
%token _PUBLIC 282 
%token _RETURN 283
%token _SUPER 284 
%token _SWITCH 285 
%token _THIS 286 
%token _THROW 287
%token _TO 288 
%token _TRY 289 
%token _USE 290 
%token _VAR 291 
%token _WHILE 292
%token _WITH 293 
  
//SYNTACTICAL KEYWORDS
%token _EACH 294
%token _GET 295 
%token _SET 296 
%token _NAMESPACE 297
%token _INCLUDE 298
%token _DYNAMIC 299
%token _FINAL 300 
%token _NATIVE 301
%token _OVERRIDE 302
%token _STATIC 303  
//SYNTACTICAL ELEMENTS
//punctuation
%token LPAREN 304
%token RPAREN 305 
%token LBRACE 306
%token RBRACE 307 
%token LBRACKET 308
%token RBRACKET 309
%token SEMICOLON 310
%token QUOTES 311
%token COMMA 312
%token COLON 313
//operators
%token PLUS 314// +
%token MINUS 315// -
%token MULTIPLY 316// *
%token DIVIDE 317// /
%token MODULO 318// %
%token LESSTHAN 319//<
%token GREATERTHAN 320//>
%token EQUALSEQUALS 321//==
%token STRICTEQUALS 322//===
%token STRICTNOTEQ 323//!==
%token GTHANEQ 324// >=
%token LTHANEQ 325// <=
%token NOTEQUAL 326//!=
%token NOT 327//!
%token NOTEQUALEQUAL 328
%token LOGICALAND 329// && Logical AND
%token LOGICALOR 330//|| Logical OR
  
//BOOLEANS
%token _TRUE 334 
%token _FALSE 335
  
//OPERATORS
//initialization
%token ARRAY 336//[] Initializes an array
%token OBJECT 337//{x:y} Initializes an object
%token FUNCTION 338//f(x) Calls a function
%token ACCESSDOT 339//x.y 
%token ACCESSBRACKET 340//x[y] Accesses a property
%token INCREMENT 341//++
%token DECREMENT 342//--	
  
//OBJECT COMMANDS
%token _NEW 343//new Calls a constructor
%token _DELETE 344//delete Deletes a property
%token _TYPEOF 345//typeof Returns type information
%token _VOID 346//returns undefined value
%token _AS 347//as Checks data type
%token _IN 348//in Checks for object properties
%token _INSTANCEOF 349//instanceof Checks prototype chain
%token _IS 350//is Checks data type
  
//what is this? punctuation?
%token _TERNARY 351// ?:
  
//ASSIGNMENT
%token ASSIGN 352//=
%token MULTIPLYEQ 353// *= Multiplication assignment
%token DIVIDEEQ 354// /= Division assignment
%token MODULOEQ 355// %= Modulo assignment
%token PLUSEQ 356// += Addition assignment
%token MINUSEQ 357// -= Subtraction assignment  
  
//TYPES not already covered
%token _UINT 359
%token _INT 360
%token _BOOLEAN 361
%token _STRING 331
%token _NUMBER 332
  
//misc 
%token IDENT 358
%token OTHER 400


%%

 //start of grammar
program:  
    sourceElements
    ;

sourceElements:
    sourceElement
    | sourceElement sourceElements    
    ;

sourceElement:
    statement    
    ;

// statements
statement:
   block
   | variableStatement
   | importStatement
   // | emptyStatement
   //| expressionStatement
   //| ifStatement
   //| iterationStatement
   //| continueStatement
   //| breakStatement
   //| returnStatement
   //| withStatement
   //| labelledStatement
   //| switchStatement
   //| throwStatement
   //| tryStatement
   ;

importStatement:
   _IMPORT moduleName SEMICOLON
   ;

moduleName:
    IDENT
    | IDENT ACCESSDOT moduleName
    ;

block:
     LBRACE RBRACE	
     | LBRACE sourceElements RBRACE
     ;

variableStatement:
    _VAR variableDeclarationList SEMICOLON
    _VAR IDENT ASSIGN value SEMICOLON
    ;

variableDeclarationList:
          IDENT
          | IDENT variableDeclarationTail
	  | variableDeclarationTail //this will parse var , 
	  ;

variableDeclarationTail:
	COMMA IDENT
	;

value:
     _STRING
     | _NUMBER
     ;


						     /*
variableDeclarationListNoln:
	/*
	 * SPEC:
	 * variableDeclarationNoln
	 * | variableDeclarationListNoln COMMA variableDeclarationNoln
	 
	variableDeclarationNoln (variableDeclarationListNolnTail)*
	;

variableDeclarationListNolnTail:
	COMMA variableDeclarationNoln
	;
				/*
variableDeclarationNoln:
	identifier (initialiserNoln)?
	;

initialiser:
	EQ assignmentExpression
	;	

initialiserNoln:
	EQ assignmentExpressionNoln
	;
				*/
/*emptyStatement:
	;
/*
expressionStatement:
	/* [lookahead not a member of {{, function}}  expression SMI
	;
				    /*
ifStatement:
	IF LPAREN expression RPAREN statement ELSE statement
	| IF LPAREN expression RPAREN statement
	;

iterationStatement:
	DO statement WHILE LPAREN expression RPAREN SEMI
	| WHILE LPAREN expression RPAREN statement
	| FOR LPAREN (
		(expressionNoln)? SEMI (expression)? SEMI (expression)? RPAREN statement
		| 'var' variableDeclarationListNoln SEMI (expression)? SEMI (expression)? RPAREN statement
		| leftHandSideExpression 'in' expression RPAREN statement	
		| 'var' variableDeclarationNoln 'in' expression RPAREN statement
		)
	;
 			    
continueStatement:
	CONTINUE /* [ no line terminator here ]  (identifier)? SEMI
	;

breakStatement:
	BREAK /* [ no line terminator here ]  (identifier)? SEMI
	;

returnStatement:
	RETURN /* [no line terminator here]/ (expression)? SEMI
	;

withStatement:
	WITH LPAREN expression RPAREN statement
	;

switchStatement:
	SWITCH LPAREN expression RPAREN caseBlock
	;

caseBlock:
	LBRACE (caseClauses)? RBRACE
	| LBRACE (caseClauses)? defaultClause (caseClauses)? RBRACE
	;

caseClauses:
	caseClause
        | caseClauses caseClause
	;

caseClause:
	CASE expression COLON statementList
	| CASE expression COLON 
	;

defaultClause:
	DEFAULT COLON statementList
        | DEFAULT COLON 
	;

labelledStatement:
	identifier COLON statement
	;

throwStatement:
	THROW /* [no line terminator here]  expression SEMI
	;
							   /*
tryStatement:
	TRY block catch_
	| TRY block finally_
	| TRY block catch_ finally_
	;

catch_:
	CATCH LPAREN identifier RPAREN block
	;

finally_:
	FINALLY block
	;*/

/* A.5 Functions and Programs */
/*
functionDeclaration:
	'function' identifier LPAREN (formalParameterList)? LBRACE functionBody RBRACE
	;

functionExpression:
	'function' (identifier)? LPAREN (formalParameterList)? LBRACE functionBody RBRACE
	;

formalParameterList:
	identifier  
        | formalParameterList COMMA identifier
	;

formalParameterListTail:
	COMMA identifier
	;

functionBody:
	sourceElements
	;
*/






