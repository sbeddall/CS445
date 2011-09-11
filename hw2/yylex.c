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
  #define _INTERNAL 277 
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
  #define _INCLUDE 298
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
  
    //TYPES no already covered
  #define _UINT 359
  #define _INT 360
  #define _BOOLEAN 361
  #define _STRING 331
  #define _NUMBER 332
  
  //misc
  #define IDENT 358
  #define OTHER 400

  #define eval(x) evalToYYToken(x, yytext)

  
  //C comments  http://stackoverflow.com/questions/2130097/problem-getting-c-style-comments-in-flex-lex

//%option noyywrap

%}

%%

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


\"[.^\n]+\" { eval(_STRING); return _STRING; }

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
