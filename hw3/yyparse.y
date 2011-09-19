%{
#include "tree.h"
#include "structures.h"
#include "defines.h"

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

%token IDENT 358

%%

 //start of grammar
program:  
    sourceElements
    ;

sourceElements:
    sourceStatement 
    | sourceElements sourceElement
    ;

sourceElement:
    statement 
    | functionDeclaration
    ;

// statements
statement:
   block
   | variableStatement
   | emptyStatement
   | expressionStatement
   | ifStatement
   | iterationStatement
   | continueStatement
   | breakStatement
   | returnStatement
   | withStatement
   | labelledStatement
   | switchStatement
   | throwStatement
   | tryStatement
   ;

/*
block:
     LBRACE RBRACE	
     | LBRACE statementList RBRACE
     ;

statementList:
    statement
    | statementList statement
    ;

variableStatement:
	VAR  variableDeclarationList SEMI
	;

variableDeclarationList:
	/*
	 * SPEC:
	 * variableDeclaration
	 * | variableDeclarationList COMMA variableDeclaration
	 */
/*	variableDeclaration (variableDeclarationTail)*
	;

variableDeclarationTail:
	COMMA variableDeclaration
	;

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

variableDeclaration:
	identifier (initialiser)?
	;

variableDeclarationNoln:
	identifier (initialiserNoln)?
	;

initialiser:
	EQ assignmentExpression
	;	

initialiserNoln:
	EQ assignmentExpressionNoln
	;

emptyStatement:
	;

expressionStatement:
	/* [lookahead not a member of {{, function}}  expression SEMI
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




