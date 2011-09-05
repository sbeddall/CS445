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
  #define QUOTES 359
  #define OTHER 400
 
%}
%option noyywrap

%%
     //RESERVED WORDS
    //  #define _AS 
"break" { evalToYYToken(_BREAK, yytext); return _BREAK; }
"case" { return _CASE; }
"catch" { return _CATCH; } 
"class" { return _CLASS; }
"const" { return _CONST; }
"continue" { return _CONTINUE; }
"default" { return _DEFAULT; }
"do" { return _DO; }
"else" { return _ELSE; } 
"extends" { return _EXTENDS; }
"finally" { return _FINALLY; }
"for" { return _FOR; }
"function" { return _FUNCTION; }
"if" { return _IF; }
"implements" { return _IMPLEMENTS; }
"import" {evalToYYToken(_IMPORT, yytext); return _IMPORT; }
"interface" { return _INTERFACE; }
"internal" { return _INTERNAL; }
"null"|"NULL" { return _NULL; }
"package" { return _PACKAGE; }
"private" { return _PRIVATE; }
"protected" { return _PROTECTED; }
"public" { return _PUBLIC; }
"return" { return _RETURN; }
"super" { return _SUPER; }
"switch" { return _SWITCH; }
"this" { return _THIS; }
"throw" { return _THROW; }
"to" { return _TO; }
"try" { return _TRY; }
"use" { return _USE; }
"var" { return _VAR; }
"while" { return _WHILE; }
"with" { return _WITH; }  
"each" { return _EACH; }
"get" { return _GET; }
"set" { return _SET; }
"namespace" { return _NAMESPACE; }
"include" { return _INCLUDE; }
"dynamic" { return _DYNAMIC; }
"final" { return _FINAL; }
"native" { return _NATIVE; }
"override" { return _OVERRIDE; }
"static" { return _STATIC; }

"new" { return _NEW; }
"delete" { return _DELETE; }
"typeof" {   return _TYPEOF; }
"void" {   return _VOID; }
"as"  { return _AS; }
"in"  { return _IN; }
"instanceof"  { return _INSTANCEOF; } 
"is"  { return _IS; } 


[a-zA-Z][a-zA-Z0-9]* { evalToYYToken(IDENT, yytext); return IDENT;}

\[ { evalToYYToken(LBRACKET, yytext); return LBRACKET; }
\] { evalToYYToken(RBRACKET, yytext);  return RBRACKET; } 

\= { evalToYYToken(ASSIGN, yytext); return ASSIGN; }

\"[.]+\" { evalToYYToken(STRING, yytext); return STRING; }

[0-9]*'.'?[0-9]* { evalToYYToken(NUMBER, yytext); return NUMBER; }

"?:" { evalToYYToken(_TERNARY, yytext); return _TERNARY; }

"*=" { evalToYYToken(MULTIPLYEQ, yytext); return MULTIPLYEQ; }
"/=" { evalToYYToken(DIVIDEEQ, yytext); return DIVIDEEQ; }
"%=" { evalToYYToken(MODULOEQ, yytext); return MODULOEQ; }
"+=" { evalToYYToken(PLUSEQ, yytext); return PLUSEQ; }
"-=" { evalToYYToken(MINUSEQ, yytext); return MINUSEQ; }
'\n' {LINENO++;}

. { evalToYYToken(OTHER, yytext); return OTHER; }

%%
