%{
#include "tree.h"
#include "structures.h"


// better error reporting
#define YYERROR_VERBOSE
  extern char* yytext;
  extern int LINENO;
  extern int failed;
  extern char* FILENAME;
  
// bison requires that you supply this function
void yyerror(const char *msg)
{
  failed++;
  printf("Filename: %s\n", FILENAME);
  printf("ERROR(PARSER): %s, %s\nLine Number: %d\n", msg, yytext, LINENO);
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
 //%token ACCESSBRACKET 340//x[y] Accesses a property
%token INCREMENT 341//++
%token DECREMENT 342//--	
  
//OBJECT COMMANDS
%token _NEW 343//new Calls a constructor
%token _DELETE 344//delete Deletes a property
%token _TYPEOF 345//typeof Returns type information
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
 //%token _VOID 346//returns undefined value
%token STRINGLIT
%token NUMBERLIT
  
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
   | variableDeclaration
   | importStatement
   | functionStatement
   | forStatement
   | ifStatement
   | whileStatement
   | continueStatement
   | breakStatement
   | withStatement
     //| switchStatement
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
as:
   _AS value
   | 
   ;

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
   | NUMBERLIT
   | STRINGLIT
   | variableName
   | objectInitializer
   | arrayAccessor
   | _NULL
   | functionCall
   | _THIS
   | ternaryExpression
   | _TRUE
   | _FALSE
   ;

newObject:
   _NEW IDENT LPAREN RPAREN optionalVariableType
   | _NEW IDENT LPAREN variableDeclarationList RPAREN optionalVariableType
   ;

functionStatement:
   functionCall
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
   variableName LPAREN valueList RPAREN SEMICOLON
   | variableName LPAREN RPAREN SEMICOLON 
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
   LPAREN variableName logicalOperator expression RPAREN
   | LPAREN variableName RPAREN
   | variableName
   ;

whileStatement:
   _WHILE expression block
   ;

forStatement:
   _FOR LPAREN _VAR IDENT expression SEMICOLON mathExpression RPAREN block
   | _FOR _EACH LPAREN _VAR variableName _IN value RPAREN block 
   ;

arrayAccessor:
   value LBRACKET accessValue RBRACKET
   | value LBRACKET RBRACKET
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

mathExpression:
   variableName INCREMENT
   | variableName DECREMENT
   | variableName pemd variableName
   | variableName as variableName
   ;

pemd:
   MULTIPLY
   | DIVIDE
   | MODULO
   ;

as:
   PLUS
   | MINUS
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






