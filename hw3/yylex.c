%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "structures.h"
  #include "yyparse.tab.h"
  //#include "defines.h" 
  extern token* YYTOKEN;
  extern int LINENO;
   

  #define eval(x) evalToYYToken(x, yytext)

  
  //C comments  http://stackoverflow.com/questions/2130097/problem-getting-c-style-comments-in-flex-lex

//%option noyywrap


//"void" {    return _VOID; }
%}

%x C_COMMENT

%%

"/*"            { BEGIN(C_COMMENT); }
<C_COMMENT>"*/" { BEGIN(INITIAL); }
<C_COMMENT>.    { }

[ \t]
 
\n { LINENO++; } 

"break" {   return _BREAK; }
"case" {   return _CASE; }
"catch" {   return _CATCH; } 
"class" {   return _CLASS; }
"const" {   return _CONST; }
"continue" {   return _CONTINUE; }
"default" {   return _DEFAULT; }
"do" {   return _DO; }
"else" {   return _ELSE; } 
"extends" {   return _EXTENDS; }
"finally" {   return _FINALLY; }
"for" {   return _FOR; }
"function" {   return _FUNCTION; }
"if" {   return _IF; }
"implements" {   return _IMPLEMENTS; }
"import" {  return _IMPORT; }
"interface" {   return _INTERFACE; }
"null"|"NULL" {   return _NULL; }
"package" {    return _PACKAGE; }
"private" {   return _PRIVATE; }
"protected" {   return _PROTECTED; }
"public" {   return _PUBLIC; }
"return" {  return _RETURN; }
"super" {   return _SUPER; }
"switch" {   return _SWITCH; }
"this" {   return _THIS; }
"throw" {   return _THROW; }
"to" {   return _TO; }
"try" {   return _TRY; }
"use" {   return _USE; }
"var" {   return _VAR; }
"while" {   return _WHILE; }
"with" {   return _WITH; }  
"each" {   return _EACH; }
"get" {   return _GET; }
"set" {   return _SET; }
"namespace" {   return _NAMESPACE; }
"dynamic" {   return _DYNAMIC; }
"final" {   return _FINAL; }
"native" {   return _NATIVE; }
"override" {   return _OVERRIDE; }
"static" {   return _STATIC; }


"internal" {   return _INTERNAL; }
"include" {   return _INCLUDE; }

"new" {   return _NEW; }
"delete" {   return _DELETE; }
"typeof" {    return _TYPEOF; }
"as"  {   return _AS; }
"in"  {   return _IN; }
"instanceof"  {   return _INSTANCEOF; } 
"is"  {   return _IS; } 

[a-zA-Z_][a-zA-Z0-9_]* {   return IDENT;}

\. { return ACCESSDOT; }
\, { return COMMA;}
\[ {   return LBRACKET; }
\] {    return RBRACKET; }
\( {   return LPAREN;}
\) {   return RPAREN; }
"{" {   return LBRACE; }
"}" {   return RBRACE; }
";" {   return SEMICOLON; }

\".+\"|\'.+\' {   return STRINGLIT; }

\" {   return QUOTES; }

\: {   return COLON; }

\= {   return ASSIGN; }
  
\< {   return LESSTHAN; }
\> {   return GREATERTHAN; }
"==" {   return EQUALSEQUALS; }
"===" {   return STRICTEQUALS; }
"!==" {   return STRICTNOTEQ; }
">=" {   return GTHANEQ; }
"<=" {   return LTHANEQ; }
"!=" {   return NOTEQUAL; }
\! {   return NOT; }
"&&" {   return LOGICALAND; }
"||" {   return LOGICALOR; }

"//".* { }

[0-9]*['.']?[0-9]* {   return NUMBERLIT; }

"?" {   return _TERNARY; }


"++" { return INCREMENT; }
"--" { return DECREMENT; }
"*=" {   return MULTIPLYEQ; }
"/=" {   return DIVIDEEQ; }
"%=" {   return MODULOEQ; }
"+=" {   return PLUSEQ; }
"-=" {   return MINUSEQ; }

. {  }

%%

int yywrap(){ return -1; }
