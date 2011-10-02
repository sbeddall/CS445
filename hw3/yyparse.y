%{
#include "tree.h"
#include "structures.h"
#include <stdlib.h>
#include <stdio.h>

// better error reporting
#define YYERROR_VERBOSE
  extern char* yytext;
  extern int LINENO;
  extern int failed;
  extern char* FILENAME;

  extern token* YYTOKEN;
  
  // bison requires that you supply this function
void yyerror(const char *msg)
{
  failed++;
  printf("Filename: %s\n", FILENAME);
  printf("ERROR(PARSER): %s, %s\nLine Number: %d\n", msg, yytext, LINENO);
}

%}


%union {
  struct node* n;
}

%token <node*> _BREAK 261 
%token <node*> _CASE 363  
%token <node*> _CATCH 262  
%token <node*> _CLASS 263 
%token <node*>  _CONST 264 
%token <node*>  _CONTINUE 265 
%token <node*>  _DEFAULT 266 
%token <node*>  _DO 362  
%token <node*>  _ELSE 267  
%token <node*>  _EXTENDS 268 
%token <node*>  _FINALLY 270 
%token <node*>  _FOR 271 
%token <node*>  _FUNCTION 272 
%token <node*>  _IF 273 
%token <node*>  _IMPLEMENTS 274
%token <node*>  _IMPORT 275 
%token <node*>  _INTERFACE 276 
%token <node*>  _INTERNAL 277 
%token <node*>  _NULL 278 
%token <node*>  _PACKAGE 279 
%token <node*>  _PRIVATE 280 
%token <node*>  _PROTECTED 281 
%token <node*>  _PUBLIC 282 
%token <node*>  _RETURN 283
%token <node*>  _SUPER 284 
%token <node*>  _SWITCH 285 
%token <node*>  _THIS 286 
%token <node*>  _THROW 287
%token <node*>  _TO 288 
%token <node*>  _TRY 289 
%token <node*>  _USE 290 
%token <node*>  _VAR 291 
%token <node*>  _WHILE 292
%token <node*>  _WITH 293 
  
//SYNTACTICAL KEYWORDS
%token <node*>  _EACH 294
%token <node*>  _GET 295 
%token <node*>  _SET 296 
%token <node*>  _NAMESPACE 297
%token <node*>  _INCLUDE 298
%token <node*>  _DYNAMIC 299
%token <node*>  _FINAL 300 
%token <node*>  _NATIVE 301
%token <node*>  _OVERRIDE 302
%token <node*>  _STATIC 303  
//SYNTACTICAL ELEMENTS
//punctuation
%token <node*>  LPAREN 304
%token <node*>  RPAREN 305 
%token <node*>  LBRACE 306
%token <node*>  RBRACE 307 
%token <node*>  LBRACKET 308
%token <node*>  RBRACKET 309
%token <node*>  SEMICOLON 310
%token <node*>  QUOTES 311
%token <node*>  COMMA 312
%token <node*>  COLON 313
//operators
%token <node*>  PLUS 314// +
%token <node*>  MINUS 315// -
%token <node*>  MULTIPLY 316// *
%token <node*>  DIVIDE 317// /
%token <node*>  MODULO 318// %
%token <node*>  LESSTHAN 319//<
%token <node*>  GREATERTHAN 320//>
%token <node*>  EQUALSEQUALS 321//==
%token <node*>  STRICTEQUALS 322//===
%token <node*>  STRICTNOTEQ 323//!==
%token <node*>  GTHANEQ 324// >=
%token <node*>  LTHANEQ 325// <=
%token <node*>  NOTEQUAL 326//!=
%token <node*>  NOT 327//!
%token <node*>  NOTEQUALEQUAL 328
%token <node*>  LOGICALAND 329// && Logical AND
%token <node*>  LOGICALOR 330//|| Logical OR
  
//BOOLEANS
%token <node*>  _TRUE 334 
%token <node*>  _FALSE 335
  
//OPERATORS
//initialization
%token <node*>  ARRAY 336//[] Initializes an array
%token <node*>  OBJECT 337//{x:y} Initializes an object
%token <node*>  FUNCTION 338//f(x) Calls a function
%token <node*>  ACCESSDOT 339//x.y 
 //%token <node*>  ACCESSBRACKET 340//x[y] Accesses a property
%token <node*>  INCREMENT 341//++
%token <node*>  DECREMENT 342//--	
  
//OBJECT COMMANDS
%token <node*>  _NEW 343//new Calls a constructor
%token <node*>  _DELETE 344//delete Deletes a property
%token <node*>  _TYPEOF 345//typeof Returns type information
%token <node*>  _AS 347//as Checks data type
%token <node*>  _IN 348//in Checks for object properties
%token <node*>  _INSTANCEOF 349//instanceof Checks prototype chain
%token <node*>  _IS 350//is Checks data type
  
//what is this? punctuation?
%token <node*>  _TERNARY 351// ?:
  
//ASSIGNMENT
%token <node*>  ASSIGN 352//=
%token <node*>  MULTIPLYEQ 353// *= Multiplication assignment
%token <node*>  DIVIDEEQ 354// /= Division assignment
%token <node*>  MODULOEQ 355// %= Modulo assignment
%token <node*>  PLUSEQ 356// += Addition assignment
%token <node*>  MINUSEQ 357// -= Subtraction assignment  
  
//TYPES not already covered
%token <node*>  _UINT 359
%token <node*>  _INT 360
%token <node*>  _BOOLEAN 361
%token <node*>  _STRING 331
%token <node*>  _NUMBER 332
 //%token <node*>  _VOID 346//returns undefined value
%token <node*>  STRINGLIT
%token <node*>  NUMBERLIT
  
//misc 
%token <node*>  IDENT 358
%token <node*>  OTHER 400


%left PLUS MINUX MULTIPLY DIVIDE

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
   | variableDeclaration
   | importStatement
   | functionStatement
   | forStatement
   | ifStatement
   | whileStatement
   | continueStatement
   | breakStatement
   | withStatement
     //| switchStatement //is this really the last one remaining?
   | throwStatement
   | tryStatement
   | iterationStatement
   | superStatement
   | classStatement 
   | packageStatement
   | returnStatement
   | assignStatement
   ;

importStatement:
   _IMPORT variableName SEMICOLON
   ;
/*
moduleName:
    IDENT
    | IDENT ACCESSDOT moduleName
    ;
*/
block:
   LBRACE RBRACE	
   | LBRACE sourceElements RBRACE
   | objectInitializer
   ;

variableDeclaration
   : variableKind variableDeclarationList SEMICOLON
   | modifier variableKind variableDeclarationList SEMICOLON
   ;

variableDeclarationList:
   variableBinding
   | variableDeclarationList COMMA variableBinding
   ;
    
variableBinding: 
   variableName optionalVariableType variableInitialization
   ;

variableName:
   IDENT
   | IDENT ACCESSDOT variableName
   ;

optionalVariableType
  : /* empty */
  | COLON variableName
  ;

variableKind: 
   _VAR
   | _CONST
   ;

variableInitialization
  : /* empty */
  | ASSIGN value
  ;

assignStatement:
   variableName assign value SEMICOLON
   ;


/*
variableDeclaration
    : modifier _VAR variableDeclarationList SEMICOLON
    | _VAR variableDeclarationList SEMICOLON
    | modifier _VAR variableConstruct assign value SEMICOLON
    | _VAR variableConstruct assign value SEMICOLON
    | modifier _CONST variableDeclarationList SEMICOLON
    | _CONST variableDeclarationList SEMICOLON
    | modifier _CONST variableConstruct assign value as SEMICOLON
    | _CONST variableConstruct assign value as SEMICOLON
    ;


//Error with this. this will allow a declaration list with leading private static etc
variableStatement:
    modifier _VAR variableDeclarationList SEMICOLON
    | modifier _VAR variableConstruct assign value SEMICOLON
    | _VAR variableDeclarationList SEMICOLON
    | _VAR variableConstruct assign value as SEMICOLON
    | modifier _CONST variableDeclarationList SEMICOLON
    | modifier _CONST  variableConstruct assign value as SEMICOLON
    | _CONST variableDeclarationList SEMICOLON
    | _CONST variableConstruct assign value as SEMICOLON 
    | variableConstruct assign value SEMICOLON   
    ;
*/

/*variableDeclarationList:
   variableConstruct 
   | variableConstruct COMMA variableDeclarationList
   ;*/

/*variableConstruct:
   value COLON value 
   | value 
   ;*/
valueList:
   value
   | valueList COMMA value
   ;

value:
   newObject
   | STRINGLIT
   | objectInitializer
   | _NULL
   | _THIS
   | _TRUE
   | _FALSE
   | expression
   | expr
   ;

mathValue:
   NUMBERLIT
   | arrayAccessor
   | variableName
   | functionCall
   | ternaryExpression
   | MINUS mathValue
   | PLUS  mathValue 
   ;

expr:
  mathValue
  | expr PLUS expr 
  | expr MINUS expr
  | expr MULTIPLY expr
  | expr DIVIDE expr
  | expr INCREMENT
  | expr DECREMENT 
  ;

newObject:
   _NEW IDENT LPAREN RPAREN optionalVariableType as
   | _NEW IDENT LPAREN valueList RPAREN optionalVariableType as
   ;

as:
   _AS variableName
   | /*empty*/ 
   ;

functionStatement:
   functionCall SEMICOLON
   | functionDeclaration
   ;

functionDeclaration:
   _FUNCTION getterSetter IDENT functionHeader
   | modifier _FUNCTION getterSetter IDENT functionHeader    
   ;

getterSetter:
   _GET
   | _SET
   | /*empty*/
   ;

functionCall:
   variableName LPAREN valueList RPAREN
   | variableName LPAREN RPAREN
   ;

functionHeader:
    LPAREN variableDeclarationList RPAREN block
    | LPAREN variableDeclarationList RPAREN COLON variableName block
    | LPAREN RPAREN block
    | LPAREN RPAREN COLON variableName block
    ;

packageStatement:
   _PACKAGE variableName block 
   ;
   
ternaryExpression:
   expression _TERNARY value COLON value
   ;

objectInitializer:
   LBRACE variableDeclarationList RBRACE optionalVariableType
   ;

superStatement:
   _SUPER LPAREN value RPAREN SEMICOLON
   ;

returnStatement:
   _RETURN value SEMICOLON
   | _RETURN functionCall SEMICOLON
   | _RETURN LBRACKET RBRACKET SEMICOLON
   ;

classStatement:
   _CLASS IDENT block
   | modifier _CLASS IDENT block
   | _CLASS IDENT _EXTENDS IDENT block
   | modifier _CLASS IDENT _EXTENDS IDENT block
   ;

modifier:
   modifierPrefix modifierSuffix 
   | modifierPrefix
   | modifierSuffix
   ;

modifierSuffix:
   suffixKeyword 
   | suffixKeyword modifierSuffix

modifierPrefix:
   prefixKeyword
   | prefixKeyword modifierPrefix
   ;

prefixKeyword:
   _PUBLIC
   | _PRIVATE
   | _PROTECTED
   | _OVERRIDE
   ;

suffixKeyword:
   _DYNAMIC 
   | _FINAL 
   | _NATIVE
   | _STATIC 
   | _GET
   ;

assign:
   ASSIGN // =
   | MULTIPLYEQ // *= Multiplication assignment
   | DIVIDEEQ // /= Division assignment
   | MODULOEQ // %= Modulo assignment
   | PLUSEQ // += Addition assignment
   | MINUSEQ // -= Subtraction assignment  
   ;

ifStatement:
    _IF expression statement 
    | _IF expression statement elseStatement
    ;

elseStatement:
   _ELSE statement
   ;

expression:
   LPAREN value logicalOperator expression RPAREN
   | LPAREN value RPAREN
   ;

whileStatement:
   _WHILE value block
   ;

forStatement:
  _FOR LPAREN variableDeclaration SEMICOLON optionalForConditional SEMICOLON optionalForIncrement SEMICOLON
  | _FOR LPAREN _VAR variableName optionalVariableType _IN value RPAREN
  | _FOR _EACH LPAREN _VAR variableName optionalVariableType _IN value RPAREN
  ;

optionalForConditional:
  /* empty */
  | mathValue
  ;

optionalForIncrement:
  /* empty */
  | mathValue
  ;

arrayAccessor:
   variableName LBRACKET accessValue RBRACKET
   | variableName LBRACKET RBRACKET
   ;

accessValue:
   NUMBERLIT
   | variableName
   ;

logicalOperator:
   LESSTHAN //<
   | GREATERTHAN //>
   | EQUALSEQUALS //==
   | STRICTEQUALS //===
   | STRICTNOTEQ //!==
   | GTHANEQ // >=
   | LTHANEQ // <=
   | NOTEQUAL //!=
   | NOT //!
   | NOTEQUALEQUAL 
   | LOGICALAND // && Logical AND
   | LOGICALOR //|| Logical OR
   ;

iterationStatement:
   variableName INCREMENT SEMICOLON
   | variableName DECREMENT SEMICOLON
   ;

throwStatement:
   _THROW value SEMICOLON
   ;

tryStatement:
   _TRY statement catch
   | _TRY statement finally
   | _TRY statement catch finally
   ;

catch:
   _CATCH LPAREN value RPAREN statement
   ;

finally:
   _FINALLY statement
   ;

withStatement:
   _WITH LPAREN expression RPAREN statement
   ;
		    
continueStatement:
   _CONTINUE SEMICOLON
   | _CONTINUE value SEMICOLON
   ;

breakStatement:
   _BREAK SEMICOLON
   | _BREAK value SEMICOLON
   ;

/*switchStatement:
	_SWITCH LPAREN expression RPAREN caseBlock
	;*/
/*
iterationStatement:
	DO statement WHILE LPAREN expression RPAREN SEMN
	| WHILE LPAREN expression RPAREN statement
	| FOR LPAREN (
		( SEMI (expression)? SEMI (expression)? RPAREN statement
		| 'var' variableDeclarationListNoln SEMI (expression)? SEMI (expression)? RPAREN statement
		| leftHandSideExpression 'in' expression RPAREN statement	
		| 'var' variableDeclarationNoln 'in' expression RPAREN statement
		)
	;
 	



*/

/*
type:
   
   ;
*/
/*
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
returnStatement:
	RETURN /* [no line terminator here]/ (expression)? SEMI
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

*/






