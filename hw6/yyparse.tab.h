
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _BREAK = 261,
     _CASE = 363,
     _CATCH = 262,
     _CLASS = 263,
     _CONST = 264,
     _CONTINUE = 265,
     _DEFAULT = 266,
     _DO = 362,
     _ELSE = 267,
     _EXTENDS = 268,
     _FINALLY = 270,
     _FOR = 271,
     _FUNCTION = 272,
     _IF = 273,
     _IMPLEMENTS = 274,
     _IMPORT = 275,
     _INTERFACE = 276,
     _INTERNAL = 277,
     _NULL = 278,
     _PACKAGE = 279,
     _PRIVATE = 280,
     _PROTECTED = 281,
     _PUBLIC = 282,
     _RETURN = 283,
     _SUPER = 284,
     _SWITCH = 285,
     _THIS = 286,
     _THROW = 287,
     _TO = 288,
     _TRY = 289,
     _USE = 290,
     _VAR = 291,
     _WHILE = 292,
     _WITH = 293,
     _EACH = 294,
     _GET = 295,
     _SET = 296,
     _NAMESPACE = 297,
     _INCLUDE = 298,
     _DYNAMIC = 299,
     _FINAL = 300,
     _NATIVE = 301,
     _OVERRIDE = 302,
     _STATIC = 303,
     LPAREN = 304,
     RPAREN = 305,
     LBRACE = 306,
     RBRACE = 307,
     LBRACKET = 308,
     RBRACKET = 309,
     SEMICOLON = 310,
     QUOTES = 311,
     COMMA = 312,
     COLON = 313,
     PLUS = 314,
     MINUS = 315,
     MULTIPLY = 316,
     DIVIDE = 317,
     MODULO = 318,
     LESSTHAN = 319,
     GREATERTHAN = 320,
     EQUALSEQUALS = 321,
     STRICTEQUALS = 322,
     STRICTNOTEQ = 323,
     GTHANEQ = 324,
     LTHANEQ = 325,
     NOTEQUAL = 326,
     NOT = 327,
     NOTEQUALEQUAL = 328,
     LOGICALAND = 329,
     LOGICALOR = 330,
     _TRUE = 334,
     _FALSE = 335,
     ARRAY = 336,
     OBJECT = 337,
     FUNCTION = 338,
     ACCESSDOT = 339,
     INCREMENT = 341,
     DECREMENT = 342,
     _NEW = 343,
     _DELETE = 344,
     _TYPEOF = 345,
     _AS = 347,
     _IN = 348,
     _INSTANCEOF = 349,
     _IS = 350,
     _TERNARY = 351,
     ASSIGN = 352,
     MULTIPLYEQ = 353,
     DIVIDEEQ = 354,
     MODULOEQ = 355,
     PLUSEQ = 356,
     MINUSEQ = 357,
     _UINT = 359,
     _INT = 360,
     _BOOLEAN = 361,
     _STRING = 331,
     _NUMBER = 332,
     _VOID = 367,
     STRINGLIT = 365,
     NUMBERLIT = 366,
     IDENT = 358,
     OTHER = 400
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 51 "yyparse.y"

  struct node* n;



/* Line 1676 of yacc.c  */
#line 163 "yyparse.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


