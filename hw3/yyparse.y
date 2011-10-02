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

%token <n> _BREAK 261 
%token <n> _CASE 363  
%token <n> _CATCH 262  
%token <n> _CLASS 263 
%token <n>  _CONST 264 
%token <n>  _CONTINUE 265 
%token <n>  _DEFAULT 266 
%token <n>  _DO 362  
%token <n>  _ELSE 267  
%token <n>  _EXTENDS 268 
%token <n>  _FINALLY 270 
%token <n>  _FOR 271 
%token <n>  _FUNCTION 272 
%token <n>  _IF 273 
%token <n>  _IMPLEMENTS 274
%token <n>  _IMPORT 275 
%token <n>  _INTERFACE 276 
%token <n>  _INTERNAL 277 
%token <n>  _NULL 278 
%token <n>  _PACKAGE 279 
%token <n>  _PRIVATE 280 
%token <n>  _PROTECTED 281 
%token <n>  _PUBLIC 282 
%token <n>  _RETURN 283
%token <n>  _SUPER 284 
%token <n>  _SWITCH 285 
%token <n>  _THIS 286 
%token <n>  _THROW 287
%token <n>  _TO 288 
%token <n>  _TRY 289 
%token <n>  _USE 290 
%token <n>  _VAR 291 
%token <n>  _WHILE 292
%token <n>  _WITH 293 
  
//SYNTACTICAL KEYWORDS
%token <n>  _EACH 294
%token <n>  _GET 295 
%token <n>  _SET 296 
%token <n>  _NAMESPACE 297
%token <n>  _INCLUDE 298
%token <n>  _DYNAMIC 299
%token <n>  _FINAL 300 
%token <n>  _NATIVE 301
%token <n>  _OVERRIDE 302
%token <n>  _STATIC 303  
//SYNTACTICAL ELEMENTS
//punctuation
%token <n>  LPAREN 304
%token <n>  RPAREN 305 
%token <n>  LBRACE 306
%token <n>  RBRACE 307 
%token <n>  LBRACKET 308
%token <n>  RBRACKET 309
%token <n>  SEMICOLON 310
%token <n>  QUOTES 311
%token <n>  COMMA 312
%token <n>  COLON 313
//operators
%token <n>  PLUS 314// +
%token <n>  MINUS 315// -
%token <n>  MULTIPLY 316// *
%token <n>  DIVIDE 317// /
%token <n>  MODULO 318// %
%token <n>  LESSTHAN 319//<
%token <n>  GREATERTHAN 320//>
%token <n>  EQUALSEQUALS 321//==
%token <n>  STRICTEQUALS 322//===
%token <n>  STRICTNOTEQ 323//!==
%token <n>  GTHANEQ 324// >=
%token <n>  LTHANEQ 325// <=
%token <n>  NOTEQUAL 326//!=
%token <n>  NOT 327//!
%token <n>  NOTEQUALEQUAL 328
%token <n>  LOGICALAND 329// && Logical AND
%token <n>  LOGICALOR 330//|| Logical OR
  
//BOOLEANS
%token <n>  _TRUE 334 
%token <n>  _FALSE 335
  
//OPERATORS
//initialization
%token <n>  ARRAY 336//[] Initializes an array
%token <n>  OBJECT 337//{x:y} Initializes an object
%token <n>  FUNCTION 338//f(x) Calls a function
%token <n>  ACCESSDOT 339//x.y 
 //%token <n>  ACCESSBRACKET 340//x[y] Accesses a property
%token <n>  INCREMENT 341//++
%token <n>  DECREMENT 342//--	
  
//OBJECT COMMANDS
%token <n>  _NEW 343//new Calls a constructor
%token <n>  _DELETE 344//delete Deletes a property
%token <n>  _TYPEOF 345//typeof Returns type information
%token <n>  _AS 347//as Checks data type
%token <n>  _IN 348//in Checks for object properties
%token <n>  _INSTANCEOF 349//instanceof Checks prototype chain
%token <n>  _IS 350//is Checks data type
  
//what is this? punctuation?
%token <n>  _TERNARY 351// ?:
  
//ASSIGNMENT
%token <n>  ASSIGN 352//=
%token <n>  MULTIPLYEQ 353// *= Multiplication assignment
%token <n>  DIVIDEEQ 354// /= Division assignment
%token <n>  MODULOEQ 355// %= Modulo assignment
%token <n>  PLUSEQ 356// += Addition assignment
%token <n>  MINUSEQ 357// -= Subtraction assignment  
  
//TYPES not already covered
%token <n>  _UINT 359
%token <n>  _INT 360
%token <n>  _BOOLEAN 361
%token <n>  _STRING 331
%token <n>  _NUMBER 332
 //%token <n>  _VOID 346//returns undefined value
%token <n>  STRINGLIT
%token <n>  NUMBERLIT
  
//misc 
%token <n>  IDENT 358
%token <n>  OTHER 400


%type <n> variableName
%type <n> variableBinding
%type <n> variableDeclarationList
%type <n> variableDeclaration
%type <n> optionalVariableType
%type <n> variableInitialization
%type <n> variableKind
%type <n> value
%type <n> mathValue
%type <n> expr
%type <n> expression
%type <n> sourceElements
%type <n> sourceElement
%type <n> statement
%type <n> program

%left PLUS MINUS MULTIPLY DIVIDE

%%

 //start of grammar
program:  
sourceElements { traverseTree($1, 0); } //
   ;

sourceElements:
   sourceElement {$$ = makeNode(NULL, YYDup(), 1, $1);}
   | sourceElement sourceElements {$$ = makeNode(NULL, YYDup(), 2, $1, $2); }    
   ;

sourceElement:
   statement {$$ = makeNode(NULL, YYDup(), 1, $1);}    
   ;

// statements
statement:
   block
   | variableDeclaration {$$ = makeNode(NULL, YYDup(), 1, $1);}
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

variableDeclaration //1 
   : variableKind variableDeclarationList SEMICOLON {$$ = makeNode(NULL, YYDup(), 3, $1, $2, $3);}
//   | modifier variableKind variableDeclarationList SEMICOLON {$$ = makeNode(yytext, YYDup(), 4, $1, $2, $3, $4);}
   ; 

variableDeclarationList:
   variableBinding {$$ = makeNode(NULL, YYDup(), 1, $1);}
   | variableDeclarationList COMMA variableBinding {$$ = makeNode(NULL, YYDup(), 3, $1, makeNode(",", YYDup(), 0), $3);} 
   ;
    
variableBinding: 
   variableName optionalVariableType variableInitialization {$$ = makeNode(NULL, YYDup(), 3, $1, $2, $3);}
   ;

variableName:
   IDENT {$$ = $1 }
   | IDENT ACCESSDOT variableName {$$ = makeNode(NULL, YYDup(), 3, $1, $2, $3);}
   ;

optionalVariableType
   : /* empty */ {$$ = NULL;}
   | COLON variableName {$$ = makeNode(NULL, YYDup(), 2, $1, $2); }
   ;

variableKind
   : _VAR { $$ = $1 }
   | _CONST {$$ = $1} 
   ;

variableInitialization
   : /* empty */ {$$ = NULL;}
   | ASSIGN value {$$ = makeNode(NULL, YYDup(), 2, $1, $2);}
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
//   newObject
//   | STRINGLIT
//   | objectInitializer
//   | _NULL
//   | _THIS
//   | _TRUE
//   | _FALSE
//   | expression
   | expr {$$ = makeNode(NULL, YYDup(), 1, $1);}
   ;

mathValue:
   NUMBERLIT {$$ = $1}
//   | arrayAccessor
//   | variableName
//   | functionCall
//   | ternaryExpression
//   | MINUS mathValue
//   | PLUS  mathValue 
   ;

expr:
   mathValue {$$ = makeNode(NULL, YYDup(), 1, $1); }
  //  | expr PLUS expr 
  // | expr MINUS expr
  // | expr MULTIPLY expr
  // | expr DIVIDE expr
  // | expr INCREMENT
  // | expr DECREMENT 
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






