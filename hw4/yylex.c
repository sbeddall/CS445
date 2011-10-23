%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "structures.h"
  #include "tree.h"
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
<C_COMMENT>"\n" {LINENO++;}
<C_COMMENT>.    { }

[ \t]
 
\n { LINENO++; } 

"break" { eval(_BREAK);  yylval.n = makeNode(_BREAK, NULL,  YYDup(), 0); return _BREAK; }
"case" {  eval(_CASE);  yylval.n = makeNode(_CASE, NULL,  YYDup(), 0); return _CASE; }
"catch" { eval(_CATCH);  yylval.n = makeNode(_CATCH, NULL,  YYDup(), 0);  return _CATCH; } 
"class" { eval(_CLASS);   yylval.n = makeNode(_CLASS, NULL,  YYDup(), 0); return _CLASS; }
"const" { eval(_CONST); yylval.n = makeNode(_CONST, NULL,  YYDup(), 0); return _CONST; }
"continue" { eval(_CONTINUE);  yylval.n = makeNode(_CONTINUE, NULL,  YYDup(), 0);  return _CONTINUE; }
"default" { eval(_DEFAULT);  yylval.n = makeNode(_DEFAULT, NULL,  YYDup(), 0); return _DEFAULT; }
"do" { eval(_DO);  yylval.n = makeNode(_DO, NULL,  YYDup(), 0); return _DO; }
"else" { eval(_ELSE);  yylval.n = makeNode(_ELSE, NULL,  YYDup(), 0); return _ELSE; } 
"extends" { eval(_EXTENDS);  yylval.n = makeNode(_EXTENDS, NULL,  YYDup(), 0); return _EXTENDS; }
"finally" { eval(_FINALLY);  yylval.n = makeNode(_FINALLY, NULL,  YYDup(), 0); return _FINALLY; }
"for" { eval(_FOR);  yylval.n = makeNode(_FOR, NULL,  YYDup(), 0); return _FOR; }
"function" { eval(_FUNCTION);  yylval.n = makeNode(_FUNCTION, NULL,  YYDup(), 0); return _FUNCTION; }
"if" { eval(_IF); yylval.n = makeNode(_IF, NULL,  YYDup(), 0);  return _IF; }
"implements" { eval(_IMPLEMENTS); yylval.n = makeNode(_IMPLEMENTS, NULL,  YYDup(), 0);  return _IMPLEMENTS; }
"import" { eval(_IMPORT);  yylval.n = makeNode(_IMPORT, NULL,  YYDup(), 0); return _IMPORT; }
"interface" { eval(_INTERFACE);  yylval.n = makeNode(_INTERFACE, NULL,  YYDup(), 0); return _INTERFACE; }
"null"|"NULL" { eval(_NULL);  yylval.n = makeNode(_NULL, NULL,  YYDup(), 0); return _NULL; }
"package" { eval(_PACKAGE);  yylval.n = makeNode(_PACKAGE, NULL,  YYDup(), 0);  return _PACKAGE; }
"private" { eval(_PRIVATE);  yylval.n = makeNode(_PRIVATE, NULL,  YYDup(), 0); return _PRIVATE; }
"protected" { eval(_PROTECTED);  yylval.n = makeNode(_PROTECTED, NULL,  YYDup(), 0); return _PROTECTED; }
"public" { eval(_PUBLIC);  yylval.n = makeNode(_PUBLIC, NULL,  YYDup(), 0); return _PUBLIC; }
"return" { eval(_RETURN); yylval.n = makeNode(_RETURN, NULL,  YYDup(), 0);  return _RETURN; }
"super" { eval(_SUPER);  yylval.n = makeNode(_SUPER, NULL,  YYDup(), 0); return _SUPER; }
"switch" { eval(_SWITCH);  yylval.n = makeNode(_SWITCH, NULL,  YYDup(), 0); return _SWITCH; }
"this" { eval(_THIS);  yylval.n = makeNode(_THIS, NULL,  YYDup(), 0); return _THIS; }
"throw" { eval(_THROW);  yylval.n = makeNode(_THROW, NULL,  YYDup(), 0); return _THROW; }
"to" { eval(_TO);  yylval.n = makeNode(_TO, NULL,  YYDup(), 0); return _TO; }
"try" { eval(_TRY);  yylval.n = makeNode(_TRY, NULL,  YYDup(), 0); return _TRY; }
"use" { eval(_USE);  yylval.n = makeNode(_USE, NULL,  YYDup(), 0); return _USE; }
"var" { eval(_VAR); yylval.n = makeNode(_VAR, NULL,  YYDup(), 0); return _VAR; }
"while" { eval(_WHILE);  yylval.n = makeNode(_WHILE, NULL,  YYDup(), 0); return _WHILE; }
"with" { eval(_WITH);  yylval.n = makeNode(_WITH, NULL,  YYDup(), 0); return _WITH; }  
"each" { eval(_EACH);  yylval.n = makeNode(_EACH, NULL,  YYDup(), 0); return _EACH; }
"get" { eval(_GET);  yylval.n = makeNode(_GET, NULL,  YYDup(), 0); return _GET; }
"set" { eval(_SET);  yylval.n = makeNode(_SET, NULL,  YYDup(), 0); return _SET; }
"namespace" { eval(_NAMESPACE);   yylval.n = makeNode(_NAMESPACE, NULL,  YYDup(), 0); return _NAMESPACE; }
"dynamic" { eval(_DYNAMIC);   yylval.n = makeNode(_DYNAMIC, NULL,  YYDup(), 0); return _DYNAMIC; }
"final" { eval(_FINAL);   yylval.n = makeNode(_FINAL, NULL,  YYDup(), 0); return _FINAL; }
"native" { eval(_NATIVE);  yylval.n = makeNode(_NATIVE, NULL,  YYDup(), 0); return _NATIVE; }
"override" { eval(_OVERRIDE);   yylval.n = makeNode(_OVERRIDE, NULL,  YYDup(), 0); return _OVERRIDE; }
"static" { eval(_STATIC);  yylval.n = makeNode(_STATIC, NULL,  YYDup(), 0);  return _STATIC; }


"internal" { eval(_INTERNAL);  yylval.n = makeNode(_INTERNAL, NULL,  YYDup(), 0); return _INTERNAL; }
"include" { eval(_INCLUDE);  yylval.n = makeNode(_INCLUDE, NULL,  YYDup(), 0); return _INCLUDE; }

"new" { eval(_NEW);   yylval.n = makeNode(_NEW, NULL,  YYDup(), 0); return _NEW; }
"delete" { eval(_DELETE);  yylval.n = makeNode(_DELETE, NULL,  YYDup(), 0); return _DELETE; }
"typeof" { eval(_TYPEOF);  yylval.n = makeNode(_TYPEOF, NULL,  YYDup(), 0); return _TYPEOF; }
"as"  { eval(_AS);   yylval.n = makeNode(_AS, NULL,  YYDup(), 0); return _AS; }
"in"  { eval(_IN);  yylval.n = makeNode(_IN, NULL,  YYDup(), 0); return _IN; }
"instanceof"  { eval(_INSTANCEOF);  yylval.n = makeNode(_INSTANCEOF, NULL,  YYDup(), 0); return _INSTANCEOF; } 
"is"  { eval(_IS);   yylval.n = makeNode(_IS, NULL,  YYDup(), 0); return _IS; } 

[a-zA-Z_][a-zA-Z0-9_]* { eval(IDENT); yylval.n = makeNode(IDENT, NULL,  YYDup(), 0); return IDENT;}

\. { eval(ACCESSDOT); yylval.n = makeNode(ACCESSDOT, NULL,  YYDup(), 0); return ACCESSDOT; }
\, { eval(COMMA); yylval.n = makeNode(COMMA, NULL,  YYDup(), 0); return COMMA;}
\[ { eval(LBRACKET);  yylval.n = makeNode(LBRACKET, NULL,  YYDup(), 0); return LBRACKET; }
\] { eval(RBRACKET);  yylval.n = makeNode(RBRACKET, NULL,  YYDup(), 0); return RBRACKET; }
\( { eval(LPAREN);  yylval.n = makeNode(LPAREN, NULL,  YYDup(), 0); return LPAREN;}
\) { eval(RPAREN);  yylval.n = makeNode(RPAREN, NULL,  YYDup(), 0); return RPAREN; }
"{" { eval(LBRACE);  yylval.n = makeNode(LBRACE, NULL,  YYDup(), 0); return LBRACE; }
"}" { eval(RBRACE);  yylval.n = makeNode(RBRACE, NULL,  YYDup(), 0); return RBRACE; }
";" { eval(SEMICOLON); yylval.n = makeNode(SEMICOLON, NULL,  YYDup(), 0); return SEMICOLON; }

\".+\"|\'.+\' { eval(STRINGLIT); yylval.n = makeNode(STRINGLIT, NULL,  YYDup(), 0);  return STRINGLIT; }

\" { eval(QUOTES);  yylval.n = makeNode(QUOTES, NULL,  YYDup(), 0); return QUOTES; }

\: { eval(COLON);  yylval.n = makeNode(COLON, NULL,  YYDup(), 0); return COLON; }

\= { eval(ASSIGN); yylval.n = makeNode(ASSIGN, NULL,  YYDup(),0);  return ASSIGN; }
  
  \< { eval(LESSTHAN);  yylval.n = makeNode(LESSTHAN, NULL,  YYDup(), 0); return LESSTHAN; }
\> { eval(GREATERTHAN);  yylval.n = makeNode(GREATERTHAN, NULL,  YYDup(), 0); return GREATERTHAN; }
"==" { eval(EQUALSEQUALS);  yylval.n = makeNode(EQUALSEQUALS, NULL,  YYDup(), 0); return EQUALSEQUALS; }
"===" { eval(STRICTEQUALS);  yylval.n = makeNode(STRICTEQUALS, NULL,  YYDup(), 0); return STRICTEQUALS; }
"!==" { eval(STRICTNOTEQ);  yylval.n = makeNode(STRICTNOTEQ, NULL,  YYDup(), 0); return STRICTNOTEQ; }
">=" { eval(GTHANEQ);  yylval.n = makeNode(GTHANEQ, NULL,  YYDup(), 0); return GTHANEQ; }
"<=" { eval(LTHANEQ);  yylval.n = makeNode(LTHANEQ, NULL,  YYDup(), 0); return LTHANEQ; }
"!=" { eval(NOTEQUAL);  yylval.n = makeNode(NOTEQUAL, NULL,  YYDup(), 0); return NOTEQUAL; }
\! { eval(NOT);  yylval.n = makeNode(NOT, NULL,  YYDup(), 0); return NOT; }
"&&" { eval(LOGICALAND);  yylval.n = makeNode(LOGICALAND, NULL,  YYDup(), 0); return LOGICALAND; }
"||" { eval(LOGICALOR);  yylval.n = makeNode(LOGICALOR, NULL,  YYDup(), 0); return LOGICALOR; }

"//".* { }

[0-9]*['.']?[0-9]* { eval(NUMBERLIT);  yylval.n = makeNode(NUMBERLIT, NULL,  YYDup(), 0); return NUMBERLIT; }

"?" { eval(_TERNARY);  yylval.n = makeNode(_TERNARY, NULL,  YYDup(), 0); return _TERNARY; }

"*=" { eval(MULTIPLYEQ);   yylval.n = makeNode(MULTIPLYEQ, NULL,  YYDup(), 0); return MULTIPLYEQ; }
"/=" { eval(DIVIDEEQ);  yylval.n = makeNode(DIVIDEEQ, NULL,  YYDup(), 0); return DIVIDEEQ; }
"%=" { eval(MODULOEQ);  yylval.n = makeNode(MODULOEQ, NULL,  YYDup(), 0); return MODULOEQ; }
"+=" { eval(PLUSEQ);  yylval.n = makeNode(PLUSEQ, NULL,  YYDup(), 0); return PLUSEQ; }
"-=" { eval(MINUSEQ);  yylval.n = makeNode(MINUSEQ, NULL,  YYDup(), 0); return MINUSEQ; }
"++" { eval(INCREMENT);  yylval.n = makeNode(INCREMENT, NULL,  YYDup(), 0); return INCREMENT; }

"+" { eval(PLUS); yylval.n = makeNode(PLUS, NULL,  YYDup(), 0); return PLUS; } 
"-" { eval(MINUS); yylval.n = makeNode(MINUS, NULL,  YYDup(), 0); return MINUS;  }
"/" { eval(DIVIDE); yylval.n = makeNode(DIVIDE, NULL,  YYDup(), 0); return DIVIDE; }
"%" { eval(MODULO);  yylval.n = makeNode(MODULO, NULL,  YYDup(), 0); return MODULO; }
"*" { eval(MULTIPLY);  yylval.n = makeNode(MULTIPLY, NULL,  YYDup(), 0); return MULTIPLY; }


. {  }

%%

int yywrap(){ return -1; }
