%{
#include "tree.h"
#include "structures.h"
#include <stdlib.h>
#include <stdio.h>
#include "symbolTable.h"
#include "enums.h"
#include <string.h>




#ifdef DEBUG 
#define yyerror(const char* msg) yyerrorVerbose(const char* msg)
#endif  

// better error reporting
#define YYERROR_VERBOSE
  extern char* yytext;
  extern int LINENO;
  extern int failed;
  extern char* FILENAME;
  extern node* head;
  extern token* YYTOKEN;
  extern int status;
  extern symbolTable* global_table;
  
  
  //#define eval(x) evalToYYToken(x, yytext)

  // bison requires that you supply this function
void  yyerror(const char* msg){
  status = -2;
}

void yyerrorVerbose(const char *msg)
{  
 
  printf("Filename: %s\n", FILENAME);
  printf("ERROR(PARSER): %s, %s\nLine Number: %d\n", msg, yytext, LINENO); 
  //change exit status 
  status = -2;
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
  
//native types not already covered
%token <n>  _UINT 359
%token <n>  _INT 360
%token <n>  _BOOLEAN 361
%token <n>  _STRING 331
%token <n>  _NUMBER 332
%token <n>  _VOID 367


 //%token <n>  _VOID 346//returns undefined value
%token <n>  STRINGLIT 365
%token <n>  NUMBERLIT 366
  
//misc 
%token <n>  IDENT 358
%token <n>  OTHER 400



%type <n> nativeType
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
%type <n> objectInitializer
%type <n> newObject
%type <n> arrayAccessor
%type <n> functionCall
%type <n> ternaryExpression
%type <n> block 
%type <n> importStatement 
%type <n> functionStatement 
%type <n> forStatement
%type <n> ifStatement 
%type <n> whileStatement 
%type <n> continueStatement 
%type <n> breakStatement
%type <n> withStatement 
%type <n> throwStatement 
%type <n> tryStatement 
%type <n> iterationStatement
%type <n> superStatement
%type <n> classStatement
%type <n> packageStatement
%type <n> returnStatement
%type <n> assignStatement
%type <n> getterSetter
%type <n> valueList
%type <n> as
%type <n> functionDeclaration
%type <n> logicalOperator
%type <n> accessValue
%type <n> optionalForIncrement
%type <n> assign
%type <n> functionHeader
%type <n> elseStatement
%type <n> prefixKeyword
%type <n> suffixKeyword
%type <n> modifier
%type <n> modifierPrefix
%type <n> modifierSuffix
%type <n> optionalForConditional
%type <n> finally
%type <n> catch



%left PLUS MINUS MULTIPLY DIVIDE

%%

 //start of grammar
program:  
   sourceElements { $$ = makeNode(program, global_table, NULL, 1, $1); head = $$; } //
   ;

sourceElements:
   sourceElement {$$ = $1}
   | sourceElement sourceElements {$$ = makeNode(sourceElements, NULL, NULL, 2, $1, $2); }    
   ;

sourceElement:
   statement {$$ = $1}    
   ;

// statements
statement:
   block {$$ = $1}
   | variableDeclaration {$$ = $1}
   | importStatement {$$ = $1}
   | functionStatement {$$ = $1}
   | forStatement {$$ = $1}
   | ifStatement {$$ = $1}
   | whileStatement {$$ = $1}
   | continueStatement {$$ = $1}
   | breakStatement {$$ = $1}
   | withStatement {$$ = $1}
     //| switchStatement //is this really the last one remaining?
   | throwStatement {$$ = $1}
   | tryStatement {$$ = $1}
   | iterationStatement {$$ = $1}
   | superStatement {$$ = $1}
   | classStatement {$$ = $1}
   | packageStatement {$$ = $1}
   | returnStatement {$$ = $1}
   | assignStatement {$$ = $1}
   ;

importStatement:
   _IMPORT variableName SEMICOLON {$$ = makeNode(importStatement, NULL, NULL, 3, $1, $2, $3);}
   ;
/*
Modulename:
    IDENT
    | IDENT ACCESSDOT moduleName
    ;
*/
block:
   LBRACE RBRACE {$$ = makeNode(block, makeTable(NULL), NULL, 2, $1, $2);}
   | LBRACE sourceElements RBRACE {$$ = makeNode(block, makeTable(NULL), NULL, 3, $1, $2, $3);}
   | objectInitializer {$$ = $1}
   ;

variableDeclaration //1 
   : variableKind variableDeclarationList SEMICOLON {$$ = makeNode(variableDeclaration, NULL, NULL, 3, $1, $2, $3);}
   | modifier variableKind variableDeclarationList SEMICOLON {$$ = makeNode(variableDeclaration, NULL, NULL, 4, $1, $2, $3, $4);}
   ; 

variableDeclarationList:
   variableBinding {$$ = $1}
   | variableDeclarationList COMMA variableBinding {$$ = makeNode(variableDeclarationList, NULL, NULL, 3, $1, $2, $3);} 
   ;
    
variableBinding: 
   variableName optionalVariableType variableInitialization {$$ = makeNode(variableBinding, NULL, NULL, 3, $1, $2, $3);
     $$->nodeType = strdup( getOptionalNodeType( $2) );
     if($1 != NULL) 
       $1->nodeType = strdup( getOptionalNodeType( $2) ); 
     if($3 != NULL) 
       $3->nodeType = strdup( getOptionalNodeType( $2) ); 
     if($2 != NULL){ 
       $2->nodeType = strdup( getOptionalNodeType( $2) );
     }
   }
   ;

variableName:
   IDENT {$$ = $1 }
   | IDENT ACCESSDOT variableName {$$ = makeNode(variableName, NULL, NULL, 3, $1, $2, $3);}
   ;

optionalVariableType
   : /* empty */ {$$ = NULL;}
   | COLON variableName {$$ = makeNode(optionalVariableType, NULL, NULL, 2, $1, $2); }
   | COLON nativeType { $$ = makeNode(optionalVariableType, NULL, NULL, 2, $1, $2); }
   ;

variableKind
   : _VAR { $$ = $1 }
   | _CONST {$$ = $1} 
   ;

variableInitialization
   : /* empty */ {$$ = NULL;}
   | ASSIGN value {$$ = makeNode(variableInitialization, NULL, NULL, 2, $1, $2);}
   ;

assignStatement:
   variableName assign value SEMICOLON {$$ = makeNode(assignStatement, NULL, NULL, 4, $1, $2, $3, $4);}
   ;

valueList:
   value {$$ = $1}
   | valueList COMMA value {$$ = makeNode(valueList, NULL, NULL, 3, $1, $2, $3);}
   ;

value:
   newObject {$$ = $1}
   | STRINGLIT {$$ = $1}
   | objectInitializer {$$ = $1}
   | _NULL {$$ = $1}
   | _THIS {$$ = $1}
   | _TRUE {$$ = $1}
   | _FALSE {$$ = $1}
   | expression {$$ = $1}
   | expr {$$ = $1}
   ;

mathValue:
   NUMBERLIT {$$ = $1}
   | arrayAccessor {$$ = $1} 
   | variableName {$$ = $1} 
   | functionCall {$$ = $1} 
   | ternaryExpression {$$ = $1} 
   | MINUS mathValue {$$ = makeNode(mathValue, NULL, NULL, 2, $1, $2);} 
   | PLUS mathValue {$$ = makeNode(mathValue, NULL, NULL, 2, $1, $2);} 
   ;

expr:
   mathValue {$$ = $1 }
   | expr PLUS expr {$$ = makeNode(expr, NULL, NULL, 3, $1, $2, $3); }
   | expr MINUS expr {$$ = makeNode(expr, NULL, NULL, 3, $1, $2, $3); } 
   | expr MULTIPLY expr {$$ = makeNode(expr, NULL, NULL, 3, $1, $2, $3); }
   | expr DIVIDE expr {$$ = makeNode(expr, NULL, NULL, 3, $1, $2, $3); }
   | expr MODULO expr {$$ = makeNode(expr, NULL, NULL, 3, $1, $2, $3); }
   | expr INCREMENT {$$ = makeNode(expr, NULL, NULL, 2, $1, $2); }
   | expr DECREMENT {$$ = makeNode(expr, NULL, NULL, 2, $1, $2); }
   ;

nativeType:
   _UINT { $$ = $1 }
   | _INT { $$ = $1 }
   | _BOOLEAN { $$ = $1 }
   | _NUMBER { $$ = $1 }
   | _STRING { $$ = $1 }
   | _VOID { $$ = $1 }
   | _NULL { $$ = $1 }
   ;

newObject:
   _NEW IDENT LPAREN RPAREN optionalVariableType as {$$ = makeNode(newObject, NULL, NULL, 6, $1, $2, $3, $4, $5, $6); }
   | _NEW IDENT LPAREN valueList RPAREN optionalVariableType as  {$$ = makeNode(newObject, NULL, NULL, 7, $1, $2, $3, $4, $5, $6, $7); }
   ;

as:
   _AS variableName {$$ = makeNode(as, NULL, NULL, 2, $1, $2)};
   | /*empty*/ {$$ = NULL}
   ;

functionStatement:
   functionCall SEMICOLON {$$ = makeNode(functionStatement, NULL, NULL, 2, $1, $2);}
   | functionDeclaration {$$ = $1}
   ;

functionDeclaration:
   _FUNCTION getterSetter IDENT functionHeader {$$ = makeNode(functionDeclaration, NULL, NULL, 4, $1, $2, $3, $4); $3->targetScope = $4->targetScope; }
   | modifier _FUNCTION getterSetter IDENT functionHeader {$$ = makeNode(functionDeclaration, NULL, NULL, 5, $1, $2, $3, $4, $5); $4->targetScope = $5->targetScope;}    
   ;

getterSetter:
   _GET {$$=$1}
   | _SET {$$=$1}
   | /*empty*/ {$$=NULL}
   ;

functionCall:
   variableName LPAREN valueList RPAREN  {$$ = makeNode(functionCall, NULL, NULL, 3, $1, $2, $3);}
   | variableName LPAREN RPAREN  {$$ = makeNode(functionCall, NULL, NULL, 3, $1, $2, $3);}
   ;

functionHeader:
   LPAREN variableDeclarationList RPAREN block {$$ = makeNode(functionHeader, NULL, NULL, 4, $1, $2, $3, $4); $$->targetScope = $4->table;} 
   | LPAREN variableDeclarationList RPAREN COLON variableName block {$$ = makeNode(functionHeader, NULL, NULL, 6, $1, $2, $3, $4, $5, $6); $$->targetScope = $6->table;}
   | LPAREN RPAREN block {$$ = makeNode(functionHeader, NULL, NULL, 3, $1, $2, $3); $$->targetScope = $3->table;}
   | LPAREN RPAREN COLON variableName block {$$ = makeNode(functionHeader, NULL, NULL, 5, $1, $2, $3, $4, $5); $$->targetScope = $5->table; }
   ;

packageStatement:
   _PACKAGE variableName block {$$ = makeNode(packageStatement, NULL, NULL, 3, $1, $2, $3); $2->targetScope = $3->table;}
   | _PACKAGE block {$$ = makeNode(packageStatement, NULL, NULL, 2, $1, $2);}
   ;
   
ternaryExpression:
   expression _TERNARY value COLON value {$$ = makeNode(ternaryExpression, NULL, NULL, 5, $1, $2, $3, $4, $5);}
   ;

objectInitializer:
   LBRACE variableDeclarationList RBRACE optionalVariableType {$$ = makeNode(objectInitializer, NULL, NULL, 4, $1, $2, $3, $4);} 
   ;

superStatement:
   _SUPER LPAREN value RPAREN SEMICOLON {$$ = makeNode(superStatement, NULL, NULL, 5, $1, $2, $3, $4, $5);}
   ;

returnStatement:
   _RETURN value SEMICOLON {$$ = makeNode(returnStatement, NULL, NULL, 3, $1, $2, $3);}
   | _RETURN functionCall SEMICOLON {$$ = makeNode(returnStatement, NULL, NULL, 3, $1, $2, $3);}
   | _RETURN LBRACKET RBRACKET SEMICOLON {$$ = makeNode(returnStatement, NULL, NULL, 4, $1, $2, $3, $4);}
   ;

classStatement:
   _CLASS IDENT block {$$ = makeNode(classStatement, NULL, NULL, 3, $1, $2, $3); $2->targetScope = $3->table; }
   | modifier _CLASS IDENT block {$$ = makeNode(classStatement, NULL, NULL, 4, $1, $2, $3, $4); $3->targetScope = $4->table;  }
   | _CLASS IDENT _EXTENDS IDENT block {$$ = makeNode(classStatement, NULL, NULL, 5, $1, $2, $3, $4, $5); $2->targetScope = $5->table;   }
   | modifier _CLASS IDENT _EXTENDS IDENT block {$$ = makeNode(classStatement, NULL, NULL, 6, $1, $2, $3, $4, $5, $6); $3->targetScope = $6->table; }
   ;

modifier:
   modifierPrefix modifierSuffix  {$$ = makeNode(modifier, NULL, NULL, 2, $1, $2);}
   | modifierPrefix {$$ = $1}
   | modifierSuffix {$$ = $1}
   ;

modifierSuffix:
   suffixKeyword {$$ = $1}
   | suffixKeyword modifierSuffix {$$ = makeNode(modifierSuffix, NULL, NULL, 2, $1, $2);}

modifierPrefix:
   prefixKeyword {$$ = $1}
   | prefixKeyword modifierPrefix {$$ = makeNode(modifierPrefix, NULL, NULL, 2, $1, $2);}
   ;

prefixKeyword:
   _PUBLIC {$$ = $1}
   | _PRIVATE {$$ = $1}
   | _PROTECTED {$$ = $1}
   | _OVERRIDE {$$ = $1}
   ;

suffixKeyword:
   _DYNAMIC {$$ = $1} 
   | _FINAL {$$ = $1} 
   | _NATIVE {$$ = $1}
   | _STATIC {$$ = $1} 
   | _GET {$$ = $1}
   | _SET { $$ = $1}
   ;

assign:
   ASSIGN  {$$ = $1}// =
   | MULTIPLYEQ  {$$ = $1}// *= Multiplication assignment
   | DIVIDEEQ  {$$ = $1}// /= Division assignment
   | MODULOEQ  {$$ = $1}// %= Modulo assignment
   | PLUSEQ  {$$ = $1}// += Addition assignment
   | MINUSEQ  {$$ = $1}// -= Subtraction assignment  
   ;

ifStatement:
   _IF expression statement {$$ = makeNode(ifStatement, NULL, NULL, 3, $1, $2, $3);}
   | _IF expression statement elseStatement {$$ = makeNode(ifStatement, NULL, NULL, 4, $1, $2, $3, $4);}
   ;

elseStatement:
   _ELSE statement {$$ = makeNode(elseStatement, NULL, NULL, 2, $1, $2);}
   ;

expression:
   LPAREN value logicalOperator expression RPAREN {$$ = makeNode(expression, NULL, NULL, 5, $1, $2, $3, $4, $5);}
   | LPAREN value RPAREN {$$ = makeNode(expression, NULL, NULL, 3, $1, $2, $3);}
   ;

whileStatement:
   _WHILE value block {$$ = makeNode(whileStatement, NULL, NULL, 3, $1, $2, $3);}
   ;

forStatement:
   _FOR LPAREN variableDeclaration SEMICOLON optionalForConditional SEMICOLON optionalForIncrement SEMICOLON {$$ = makeNode(forStatement, NULL, NULL, 8, $1, $2, $3, $4, $5,$6, $7, $8);}
   | _FOR LPAREN _VAR variableName optionalVariableType _IN value RPAREN {$$ = makeNode(forStatement, NULL, NULL, 8, $1, $2, $3, $4, $5,$6, $7, $8);}
   | _FOR _EACH LPAREN _VAR variableName optionalVariableType _IN value RPAREN {$$ = makeNode(forStatement, NULL, NULL, 9, $1, $2, $3, $4, $5,$6, $7, $8, $9);}
   ;

optionalForConditional:
  /* empty */ {$$ = NULL}
  | mathValue {$$ = $1}
  ;

optionalForIncrement:
  /* empty */ {$$ = NULL}
  | mathValue {$$ = $1}
  ;

arrayAccessor:
   variableName LBRACKET accessValue RBRACKET {$$ = makeNode(arrayAccessor, NULL, NULL, 4, $1, $2, $3, $4);}
   | variableName LBRACKET RBRACKET {$$ = makeNode(arrayAccessor, NULL, NULL, 3, $1, $2, $3);}
   ;

accessValue:
   NUMBERLIT {$$ = $1}
   | variableName {$$ = $1}
   ;

logicalOperator: 
   LESSTHAN {$$ = $1}
   | GREATERTHAN {$$ = $1}
   | EQUALSEQUALS {$$ = $1}
   | STRICTEQUALS {$$ = $1}
   | STRICTNOTEQ {$$ = $1}
   | GTHANEQ {$$ = $1}
   | LTHANEQ {$$ = $1}
   | NOTEQUAL {$$ = $1}
   | NOT {$$ = $1}
   | NOTEQUALEQUAL {$$ = $1} 
   | LOGICALAND {$$ = $1}
   | LOGICALOR {$$ = $1}
   ;

iterationStatement:
   variableName INCREMENT SEMICOLON {$$ = makeNode(iterationStatement, NULL, NULL, 3, $1, $2, $3);}
   | variableName DECREMENT SEMICOLON {$$ = makeNode(iterationStatement, NULL, NULL, 3, $1, $2, $3);}
   ;

throwStatement:
   _THROW value SEMICOLON {$$ = makeNode(throwStatement, NULL, NULL, 3, $1, $2, $3);}
   ;

tryStatement:
   _TRY statement catch {$$ = makeNode(tryStatement, NULL, NULL, 3, $1, $2, $3);}
   | _TRY statement finally {$$ = makeNode(tryStatement, NULL, NULL, 3, $1, $2, $3);}
   | _TRY statement catch finally {$$ = makeNode(tryStatement, NULL, NULL, 4, $1, $2, $3, $4);}
   ;

catch:
   _CATCH LPAREN value RPAREN statement {$$ = makeNode(catch, NULL, NULL, 5, $1, $2, $3, $4, $5);}
   ;

finally:
   _FINALLY statement {$$ = makeNode(finally, NULL, NULL, 2, $1, $2);}
   ;

withStatement:
   _WITH LPAREN expression RPAREN statement {$$ = makeNode(withStatement, NULL, NULL, 5, $1, $2, $3, $4, $5);}
   ;
		    
continueStatement:
   _CONTINUE SEMICOLON {$$ = makeNode(continueStatement, NULL, NULL, 2, $1, $2);}
   | _CONTINUE value SEMICOLON {$$ = makeNode(continueStatement, NULL, NULL, 3, $1, $2, $3);}
   ;

breakStatement: 
   _BREAK SEMICOLON {$$ = makeNode(breakStatement, NULL, NULL, 2, $1, $2);}
   | _BREAK value SEMICOLON {$$ = makeNode(breakStatement, NULL, NULL, 3, $1, $2, $3);}
   ;

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






