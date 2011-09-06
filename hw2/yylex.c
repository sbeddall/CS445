%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "structures.h"
  
  extern token* YYTOKEN;
  extern int LINENO;
  
  
  
  //RESERVED WORDS
  //  #define _AS
  
  #define _BREAK 261 
  #define _CASE 262 
  #define _CATCH 262  
  #define _CLASS 263 
  #define _CONST 264 
  #define _CONTINUE 265 
  #define _DEFAULT 266 
    //  #define _DELETE 
  #define _DO 266  
  #define _ELSE 267  
  #define _EXTENDS 268 
    //  #define _FALSE 269 
  #define _FINALLY 270 
  #define _FOR 271 
  #define _FUNCTION 272 
  #define _IF 273 
  #define _IMPLEMENTS 274
  #define _IMPORT 275 
    //  #define _IN
    //  #define _INSTANCEOF
  #define _INTERFACE 276 
  #define _INTERNAL 277; 
    //  #define _IS
    //  #define _NATIVE
    //  #define _NEW 
  #define _NULL 278 
  #define _PACKAGE 279 
  #define _PRIVATE 280 
  #define _PROTECTED 281 
  #define _PUBLIC 282 
  #define _RETURN 283
  #define _SUPER 284 
  #define _SWITCH 285 
  #define _THIS 286 
  #define _THROW 287
  #define _TO 288 
  #define _TRY 289 
    //  #define _TYPEOF
  #define _USE 290 
  #define _VAR 291 
    //  #define _VOID
  #define _WHILE 292
  #define _WITH 293 
  
    //SYNTACTICAL KEYWORDS
  #define _EACH 294
  #define _GET 295 
  #define _SET 296 
  #define _NAMESPACE 297
  #define _INCLUDE 298;
  #define _DYNAMIC 299
  #define _FINAL 300 
  #define _NATIVE 301
  #define _OVERRIDE 302
  #define _STATIC 303  
  //SYNTACTICAL ELEMENTS
  //punctuation
  #define LPAREN 304
  #define RPAREN 305 
  #define LBRACE 306
  #define RBRACE 307 
  #define LBRACKET 308
  #define RBRACKET 309
  #define SEMICOLON 310
  #define QUOTES 311
  #define COMMA 312
  #define COLON 313
  //math
  #define PLUS 314// +
  #define MINUS 315// -
  #define MULTIPLY 316// *
  #define DIVIDE 317// /
  #define MODULO 318// %
  //logical 
  #define LESSTHAN 319//<
  #define GREATERTHAN 320//>
  #define EQUALSEQUALS 321//==
  #define STRICTEQUALS 322//===
  #define STRICTNOTEQ 323//!==
  #define GTHANEQ 324// >=
  #define LTHANEQ 325// <=
  #define NOTEQUAL 326//!=
  #define NOT 327//!
  #define NOTEQUALEQUAL 328
  #define LOGICALAND 329// && Logical AND
  #define LOGICALOR 330//|| Logical OR
  
  //LITERALS
  #define STRING 331
  #define NUMBER 332
  #define _TRUE 334 
  #define _FALSE 335
  
  //OPERATORS
  //initialization
  #define ARRAY 336//[] Initializes an array
  #define OBJECT 337//{x:y} Initializes an object
  //access
  #define FUNCTION 338//f(x) Calls a function
  #define ACCESSDOT 339//x.y 
  #define ACCESSBRACKET 340//x[y] Accesses a property
  #define INCREMENT 341//++
  #define DECREMENT 342//--	
  
  //OBJECT COMMANDS
  #define _NEW 343//new Calls a constructor
  #define _DELETE 344//delete Deletes a property
  #define _TYPEOF 345//typeof Returns type information
  #define _VOID 346//returns undefined value
  #define _AS 347//as Checks data type
  #define _IN 348//in Checks for object properties
  #define _INSTANCEOF 349//instanceof Checks prototype chain
  #define _IS 350//is Checks data type
  
  //what is this?
  #define _TERNARY 351// ?:
  
  //ASSIGNMENT
  #define ASSIGN 352//=
  #define MULTIPLYEQ 353// *= Multiplication assignment
  #define DIVIDEEQ 354// /= Division assignment
  #define MODULOEQ 355// %= Modulo assignment
  #define PLUSEQ 356// += Addition assignment
  #define MINUSEQ 357// -= Subtraction assignment  
  
  //misc
  #define IDENT 358
  #define OTHER 400
 
%}
%option noyywrap


%%

[ \t]
 
"\n" {  LINENO++; } 

"break" { evalToYYToken(_BREAK, yytext); return _BREAK; }
"case" { evalToYYToken(_CASE,yytext); return _CASE; }
"catch" { evalToYYToken(_CATCH,yytext); return _CATCH; } 
"class" { evalToYYToken(_CLASS,yytext); return _CLASS; }
"const" { evalToYYToken(_CONST,yytext); return _CONST; }
"continue" { evalToYYToken(_CONTINUE,yytext); return _CONTINUE; }
"default" { evalToYYToken(_DEFAULT,yytext); return _DEFAULT; }
"do" { evalToYYToken(_DO,yytext); return _DO; }
"else" { evalToYYToken(_ELSE,yytext); return _ELSE; } 
"extends" { evalToYYToken(_EXTENDS,yytext); return _EXTENDS; }
"finally" { evalToYYToken(_FINALLY,yytext); return _FINALLY; }
"for" { evalToYYToken(_FOR,yytext); return _FOR; }
"function" { evalToYYToken(_FUNCTION,yytext); return _FUNCTION; }
"if" { evalToYYToken(_IF,yytext); return _IF; }
"implements" { evalToYYToken(_IMPLEMENTS,yytext); return _IMPLEMENTS; }
"import" {evalToYYToken(_IMPORT, yytext); return _IMPORT; }
"interface" { evalToYYToken(_INTERFACE,yytext); return _INTERFACE; }
"null"|"NULL" { evalToYYToken(_NULL,yytext); return _NULL; }
"package" { evalToYYToken(_PACKAGE,yytext);  return _PACKAGE; }
"private" { evalToYYToken(_PRIVATE,yytext); return _PRIVATE; }
"protected" { evalToYYToken(_PROTECTED,yytext); return _PROTECTED; }
"public" { evalToYYToken(_PUBLIC,yytext); return _PUBLIC; }
"return" { evalToYYToken(_RETURN,yytext);return _RETURN; }
"super" { evalToYYToken(_SUPER,yytext); return _SUPER; }
"switch" { evalToYYToken(_SWITCH,yytext); return _SWITCH; }
"this" { evalToYYToken(_THIS,yytext); return _THIS; }
"throw" { evalToYYToken(_THROW,yytext); return _THROW; }
"to" { evalToYYToken(_TO,yytext); return _TO; }
"try" { evalToYYToken(_TRY,yytext); return _TRY; }
"use" { evalToYYToken(_USE,yytext); return _USE; }
"var" { evalToYYToken(_VAR,yytext); return _VAR; }
"while" { evalToYYToken(_WHILE,yytext); return _WHILE; }
"with" { evalToYYToken(_WITH,yytext); return _WITH; }  
"each" { evalToYYToken(_EACH,yytext); return _EACH; }
"get" { evalToYYToken(_GET,yytext); return _GET; }
"set" { evalToYYToken(_SET,yytext); return _SET; }
"namespace" { evalToYYToken(_NAMESPACE,yytext); return _NAMESPACE; }
"dynamic" { evalToYYToken(_DYNAMIC,yytext); return _DYNAMIC; }
"final" { evalToYYToken(_FINAL,yytext); return _FINAL; }
"native" { evalToYYToken(_NATIVE,yytext); return _NATIVE; }
"override" { evalToYYToken(_OVERRIDE,yytext); return _OVERRIDE; }
"static" { evalToYYToken(_STATIC,yytext); return _STATIC; }


"new" { evalToYYToken(_NEW,yytext); return _NEW; }
"delete" { evalToYYToken(_DELETE,yytext); return _DELETE; }
"typeof" { evalToYYToken(_TYPEOF,yytext);  return _TYPEOF; }
"void" {evalToYYToken(_VOID,yytext);   return _VOID; }
"as"  { evalToYYToken(_AS, yytext); return _AS; }
"in"  { evalToYYToken(_IN, yytext); return _IN; }
"instanceof"  { evalToYYToken(_INSTANCEOF, yytext); return _INSTANCEOF; } 
"is"  { evalToYYToken(_IS, yytext); return _IS; } 

[a-zA-Z^\n][a-zA-Z0-9^\n]* { evalToYYToken(IDENT, yytext); return IDENT;}

\[ { evalToYYToken(LBRACKET, yytext); return LBRACKET; }
\] { evalToYYToken(RBRACKET, yytext);  return RBRACKET; } 

\= { evalToYYToken(ASSIGN, yytext); return ASSIGN; }

\"[.^\n]+\" { evalToYYToken(STRING, yytext); return STRING; }

[0-9]*'.'?[0-9]* { evalToYYToken(NUMBER, yytext); return NUMBER; }

"?:" { evalToYYToken(_TERNARY, yytext); return _TERNARY; }

"*=" { evalToYYToken(MULTIPLYEQ, yytext); return MULTIPLYEQ; }
"/=" { evalToYYToken(DIVIDEEQ, yytext); return DIVIDEEQ; }
"%=" { evalToYYToken(MODULOEQ, yytext); return MODULOEQ; }
"+=" { evalToYYToken(PLUSEQ, yytext); return PLUSEQ; }
"-=" { evalToYYToken(MINUSEQ, yytext); return MINUSEQ; }

. { evalToYYToken(OTHER, yytext); return OTHER; }

%%
