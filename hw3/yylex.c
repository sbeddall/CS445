%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "structures.h"
  #include "defines.h" 
  extern token* YYTOKEN;
  extern int LINENO;
  

  #define eval(x) evalToYYToken(x, yytext)

  
  //C comments  http://stackoverflow.com/questions/2130097/problem-getting-c-style-comments-in-flex-lex

//%option noyywrap

%}

%x C_COMMENT

%%

"/*"            { BEGIN(C_COMMENT); }
<C_COMMENT>"*/" { BEGIN(INITIAL); }
<C_COMMENT>.    { }

[ \t]
 
\n { LINENO++; } 

"break" { eval(_BREAK); return _BREAK; }
"case" { eval(_CASE); return _CASE; }
"catch" { eval(_CATCH); return _CATCH; } 
"class" { eval(_CLASS); return _CLASS; }
"const" { eval(_CONST); return _CONST; }
"continue" { eval(_CONTINUE); return _CONTINUE; }
"default" { eval(_DEFAULT); return _DEFAULT; }
"do" { eval(_DO); return _DO; }
"else" { eval(_ELSE); return _ELSE; } 
"extends" { eval(_EXTENDS); return _EXTENDS; }
"finally" { eval(_FINALLY); return _FINALLY; }
"for" { eval(_FOR); return _FOR; }
"function" { eval(_FUNCTION); return _FUNCTION; }
"if" { eval(_IF); return _IF; }
"implements" { eval(_IMPLEMENTS); return _IMPLEMENTS; }
"import" {eval(_IMPORT); return _IMPORT; }
"interface" { eval(_INTERFACE); return _INTERFACE; }
"null"|"NULL" { eval(_NULL); return _NULL; }
"package" { eval(_PACKAGE);  return _PACKAGE; }
"private" { eval(_PRIVATE); return _PRIVATE; }
"protected" { eval(_PROTECTED); return _PROTECTED; }
"public" { eval(_PUBLIC); return _PUBLIC; }
"return" { eval(_RETURN);return _RETURN; }
"super" { eval(_SUPER); return _SUPER; }
"switch" { eval(_SWITCH); return _SWITCH; }
"this" { eval(_THIS); return _THIS; }
"throw" { eval(_THROW); return _THROW; }
"to" { eval(_TO); return _TO; }
"try" { eval(_TRY); return _TRY; }
"use" { eval(_USE); return _USE; }
"var" { eval(_VAR); return _VAR; }
"while" { eval(_WHILE); return _WHILE; }
"with" { eval(_WITH); return _WITH; }  
"each" { eval(_EACH); return _EACH; }
"get" { eval(_GET); return _GET; }
"set" { eval(_SET); return _SET; }
"namespace" { eval(_NAMESPACE); return _NAMESPACE; }
"dynamic" { eval(_DYNAMIC); return _DYNAMIC; }
"final" { eval(_FINAL); return _FINAL; }
"native" { eval(_NATIVE); return _NATIVE; }
"override" { eval(_OVERRIDE); return _OVERRIDE; }
"static" { eval(_STATIC); return _STATIC; }


"internal" { eval(_INTERNAL); return _INTERNAL; }
"include" { eval(_INCLUDE); return _INCLUDE; }

"new" { eval(_NEW); return _NEW; }
"delete" { eval(_DELETE); return _DELETE; }
"typeof" { eval(_TYPEOF);  return _TYPEOF; }
"void" {eval(_VOID);   return _VOID; }
"as"  { eval(_AS); return _AS; }
"in"  { eval(_IN); return _IN; }
"instanceof"  { eval(_INSTANCEOF); return _INSTANCEOF; } 
"is"  { eval(_IS); return _IS; } 

[a-zA-Z][a-zA-Z0-9]* { eval(IDENT); return IDENT;}

\[ { eval(LBRACKET); return LBRACKET; }
\] { eval(RBRACKET);  return RBRACKET; }
\( { eval(LPAREN); return LPAREN;}
\) { eval(RPAREN); return RPAREN; }
"{" { eval(LBRACE); return LBRACE; }
"}" { eval(RBRACE); return RBRACE; }
";" { eval(SEMICOLON); return SEMICOLON; }
\".+\"|\'.+\' { eval(_STRING); return _STRING; }

\" { eval(QUOTES); return QUOTES; }

\: { eval(COLON); return COLON; }

\= { eval(ASSIGN); return ASSIGN; }
  
\< { eval(LESSTHAN); return LESSTHAN; }
\> { eval(GREATERTHAN); return GREATERTHAN; }
"==" { eval(EQUALSEQUALS); return EQUALSEQUALS; }
"===" { eval(STRICTEQUALS); return STRICTEQUALS; }
"!==" { eval(STRICTNOTEQ); return STRICTNOTEQ; }
">=" { eval(GTHANEQ); return GTHANEQ; }
"<=" { eval(LTHANEQ); return LTHANEQ; }
"!=" { eval(NOTEQUAL); return NOTEQUAL; }
\! { eval(NOT); return NOT; }
"&&" { eval(LOGICALAND); return LOGICALAND; }
"||" { eval(LOGICALOR); return LOGICALOR; }

"//"* { }

[0-9]*['.']?[0-9]* { eval(_NUMBER); return _NUMBER; }

"?:" { eval(_TERNARY); return _TERNARY; }

"*=" { eval(MULTIPLYEQ); return MULTIPLYEQ; }
"/=" { eval(DIVIDEEQ); return DIVIDEEQ; }
"%=" { eval(MODULOEQ); return MODULOEQ; }
"+=" { eval(PLUSEQ); return PLUSEQ; }
"-=" { eval(MINUSEQ); return MINUSEQ; }

. {  }

%%

int yywrap(){ return -1; }
