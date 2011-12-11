
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "yyparse.y"

#include "tree.h"
#include "structures.h"
#include <stdlib.h>
#include <stdio.h>
#include "symbolTable.h"
#include "enums.h"
#include <string.h>
#include "semanticAnalysis.h"
#include "codeGen.h"

  
#if (DEBUG == 1) 
  //##define yyerror(msg) yyerrorVerbose(msg)
#endif  
  
// better error reporting

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
#define YYERROR_VERBOSE
void  yyerror(const char* msg){
  status = -2;
  if(DEBUG == 1){
   printf("Filename: %s\n", FILENAME);
   printf("ERROR(PARSER): %s, %s\nLine Number: %d\n", msg, yytext, LINENO); 
  }

}

 
 void yyerrorVerbose(const char *msg)
 { 
   status = -2;
 }



/* Line 189 of yacc.c  */
#line 123 "yyparse.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
#line 51 "yyparse.y"

  struct node* n;



/* Line 214 of yacc.c  */
#line 270 "yyparse.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 282 "yyparse.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  109
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   553

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  106
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  169
/* YYNRULES -- Number of states.  */
#define YYNSTATES  294

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   401

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     3,     5,     6,     7,     8,     9,    11,    12,     2,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    99,   100,     2,    74,    75,    76,    77,    78,    79,
       2,    80,    81,    82,    83,    84,     2,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,   104,    96,
      97,    98,    10,     4,     2,   102,   103,   101,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     105,     2
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    46,    48,    52,    55,    59,    61,    65,
      70,    72,    76,    80,    82,    86,    87,    90,    93,    95,
      97,    98,   101,   106,   108,   112,   114,   116,   118,   120,
     122,   124,   126,   128,   130,   132,   134,   136,   138,   140,
     143,   146,   148,   152,   156,   160,   164,   168,   171,   174,
     176,   178,   180,   182,   184,   186,   188,   195,   203,   206,
     207,   210,   212,   217,   223,   225,   227,   228,   233,   237,
     242,   249,   253,   259,   263,   266,   272,   277,   283,   287,
     291,   296,   300,   305,   311,   318,   321,   323,   325,   327,
     330,   332,   335,   337,   339,   341,   343,   345,   347,   349,
     351,   353,   355,   357,   359,   361,   363,   365,   367,   371,
     376,   379,   385,   389,   393,   402,   411,   421,   422,   424,
     425,   427,   432,   436,   438,   440,   442,   444,   446,   448,
     450,   452,   454,   456,   458,   460,   462,   464,   468,   472,
     476,   480,   484,   489,   495,   498,   504,   507,   511,   514
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     107,     0,    -1,   108,    -1,   109,    -1,   109,   108,    -1,
     110,    -1,   112,    -1,   113,    -1,   111,    -1,   128,    -1,
     149,    -1,   145,    -1,   148,    -1,   161,    -1,   162,    -1,
     160,    -1,   156,    -1,   157,    -1,   155,    -1,   136,    -1,
     138,    -1,   133,    -1,   137,    -1,   120,    -1,    18,   116,
      53,    -1,    49,    50,    -1,    49,   108,    50,    -1,   135,
      -1,   118,   114,    53,    -1,   139,   118,   114,    53,    -1,
     115,    -1,   114,    55,   115,    -1,   116,   117,   119,    -1,
     104,    -1,   104,    79,   116,    -1,    -1,    56,   116,    -1,
      56,   125,    -1,    34,    -1,     7,    -1,    -1,    90,   122,
      -1,   116,   144,   122,    53,    -1,   122,    -1,   121,    55,
     122,    -1,   126,    -1,   102,    -1,   135,    -1,    21,    -1,
      29,    -1,    74,    -1,    75,    -1,   147,    -1,   124,    -1,
     103,    -1,   152,    -1,   116,    -1,   131,    -1,   134,    -1,
      58,   123,    -1,    57,   123,    -1,   123,    -1,   124,    57,
     124,    -1,   124,    58,   124,    -1,   124,    59,   124,    -1,
     124,    60,   124,    -1,   124,    61,   124,    -1,   124,    80,
      -1,   124,    81,    -1,    96,    -1,    97,    -1,    98,    -1,
     100,    -1,    99,    -1,   101,    -1,    21,    -1,    82,   104,
      47,    48,   117,   127,    -1,    82,   104,    47,   121,    48,
     117,   127,    -1,    85,   116,    -1,    -1,   131,    53,    -1,
     129,    -1,    15,   130,   104,   132,    -1,   139,    15,   130,
     104,   132,    -1,    38,    -1,    39,    -1,    -1,   116,    47,
     121,    48,    -1,   116,    47,    48,    -1,    47,   114,    48,
     112,    -1,    47,   114,    48,    56,   116,   112,    -1,    47,
      48,   112,    -1,    47,    48,    56,   116,   112,    -1,    22,
     116,   112,    -1,    22,   112,    -1,   147,    89,   122,    56,
     122,    -1,    49,   114,    50,   117,    -1,    27,    47,   122,
      48,    53,    -1,    26,   122,    53,    -1,    26,   131,    53,
      -1,    26,    51,    52,    53,    -1,     6,   104,   112,    -1,
     139,     6,   104,   112,    -1,     6,   104,    12,   104,   112,
      -1,   139,     6,   104,    12,   104,   112,    -1,   141,   140,
      -1,   141,    -1,   140,    -1,   143,    -1,   143,   140,    -1,
     142,    -1,   142,   141,    -1,    25,    -1,    23,    -1,    24,
      -1,    45,    -1,    42,    -1,    43,    -1,    44,    -1,    46,
      -1,    38,    -1,    39,    -1,    90,    -1,    91,    -1,    92,
      -1,    93,    -1,    94,    -1,    95,    -1,    16,   147,   110,
      -1,    16,   147,   110,   146,    -1,    11,   110,    -1,    47,
     122,   154,   147,    48,    -1,    47,   122,    48,    -1,    35,
     122,   112,    -1,    14,    47,   113,    53,   150,    53,   151,
      53,    -1,    14,    47,    34,   116,   117,    86,   122,    48,
      -1,    14,    37,    47,    34,   116,   117,    86,   122,    48,
      -1,    -1,   123,    -1,    -1,   123,    -1,   116,    51,   153,
      52,    -1,   116,    51,    52,    -1,   103,    -1,   116,    -1,
      62,    -1,    63,    -1,    64,    -1,    65,    -1,    66,    -1,
      67,    -1,    68,    -1,    69,    -1,    70,    -1,    71,    -1,
      72,    -1,    73,    -1,   116,    80,    53,    -1,   116,    81,
      53,    -1,    30,   122,    53,    -1,    32,   110,   158,    -1,
      32,   110,   159,    -1,    32,   110,   158,   159,    -1,     5,
      47,   122,    48,   110,    -1,    13,   110,    -1,    36,    47,
     147,    48,   110,    -1,     8,    53,    -1,     8,   122,    53,
      -1,     3,    53,    -1,     3,   122,    53,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   250,   250,   254,   255,   259,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   275,   276,   277,   278,
     279,   280,   281,   282,   286,   295,   296,   297,   301,   302,
     306,   307,   311,   324,   325,   329,   330,   331,   335,   336,
     340,   341,   345,   349,   350,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   366,   367,   368,   369,   370,   371,
     372,   376,   377,   378,   379,   380,   381,   382,   383,   387,
     388,   389,   390,   391,   392,   393,   397,   398,   402,   403,
     407,   408,   412,   413,   417,   418,   419,   423,   424,   428,
     429,   430,   431,   435,   436,   449,   453,   457,   461,   462,
     463,   467,   468,   469,   470,   474,   475,   476,   480,   481,
     484,   485,   489,   490,   491,   492,   496,   497,   498,   499,
     500,   501,   505,   506,   507,   508,   509,   510,   514,   515,
     519,   523,   524,   528,   532,   533,   534,   538,   539,   543,
     544,   548,   549,   553,   554,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   573,   574,   578,
     582,   583,   584,   588,   592,   596,   600,   601,   605,   606
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_BREAK", "_CASE", "_CATCH", "_CLASS",
  "_CONST", "_CONTINUE", "_DEFAULT", "_DO", "_ELSE", "_EXTENDS",
  "_FINALLY", "_FOR", "_FUNCTION", "_IF", "_IMPLEMENTS", "_IMPORT",
  "_INTERFACE", "_INTERNAL", "_NULL", "_PACKAGE", "_PRIVATE", "_PROTECTED",
  "_PUBLIC", "_RETURN", "_SUPER", "_SWITCH", "_THIS", "_THROW", "_TO",
  "_TRY", "_USE", "_VAR", "_WHILE", "_WITH", "_EACH", "_GET", "_SET",
  "_NAMESPACE", "_INCLUDE", "_DYNAMIC", "_FINAL", "_NATIVE", "_OVERRIDE",
  "_STATIC", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACKET",
  "RBRACKET", "SEMICOLON", "QUOTES", "COMMA", "COLON", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "MODULO", "LESSTHAN", "GREATERTHAN",
  "EQUALSEQUALS", "STRICTEQUALS", "STRICTNOTEQ", "GTHANEQ", "LTHANEQ",
  "NOTEQUAL", "NOT", "NOTEQUALEQUAL", "LOGICALAND", "LOGICALOR", "_TRUE",
  "_FALSE", "ARRAY", "OBJECT", "FUNCTION", "ACCESSDOT", "INCREMENT",
  "DECREMENT", "_NEW", "_DELETE", "_TYPEOF", "_AS", "_IN", "_INSTANCEOF",
  "_IS", "_TERNARY", "ASSIGN", "MULTIPLYEQ", "DIVIDEEQ", "MODULOEQ",
  "PLUSEQ", "MINUSEQ", "_UINT", "_INT", "_BOOLEAN", "_STRING", "_NUMBER",
  "_VOID", "STRINGLIT", "NUMBERLIT", "IDENT", "OTHER", "$accept",
  "program", "sourceElements", "sourceElement", "statement",
  "importStatement", "block", "variableDeclaration",
  "variableDeclarationList", "variableBinding", "variableName",
  "optionalVariableType", "variableKind", "variableInitialization",
  "assignStatement", "valueList", "value", "mathValue", "expr",
  "nativeType", "newObject", "as", "functionStatement",
  "functionDeclaration", "getterSetter", "functionCall", "functionHeader",
  "packageStatement", "ternaryExpression", "objectInitializer",
  "superStatement", "returnStatement", "classStatement", "modifier",
  "modifierSuffix", "modifierPrefix", "prefixKeyword", "suffixKeyword",
  "assign", "ifStatement", "elseStatement", "expression", "whileStatement",
  "forStatement", "optionalForConditional", "optionalForIncrement",
  "arrayAccessor", "accessValue", "logicalOperator", "iterationStatement",
  "throwStatement", "tryStatement", "catch", "finally", "withStatement",
  "continueStatement", "breakStatement", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   401,   261,   363,   262,   263,   264,   265,   266,
     362,   267,   268,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   334,   335,   336,   337,   338,   339,
     341,   342,   343,   344,   345,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   359,   360,   361,   331,
     332,   367,   365,   366,   358,   400
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   106,   107,   108,   108,   109,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   111,   112,   112,   112,   113,   113,
     114,   114,   115,   116,   116,   117,   117,   117,   118,   118,
     119,   119,   120,   121,   121,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   123,   123,   123,   123,   123,   123,
     123,   124,   124,   124,   124,   124,   124,   124,   124,   125,
     125,   125,   125,   125,   125,   125,   126,   126,   127,   127,
     128,   128,   129,   129,   130,   130,   130,   131,   131,   132,
     132,   132,   132,   133,   133,   134,   135,   136,   137,   137,
     137,   138,   138,   138,   138,   139,   139,   139,   140,   140,
     141,   141,   142,   142,   142,   142,   143,   143,   143,   143,
     143,   143,   144,   144,   144,   144,   144,   144,   145,   145,
     146,   147,   147,   148,   149,   149,   149,   150,   150,   151,
     151,   152,   152,   153,   153,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   155,   155,   156,
     157,   157,   157,   158,   159,   160,   161,   161,   162,   162
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     3,     1,     3,     4,
       1,     3,     3,     1,     3,     0,     2,     2,     1,     1,
       0,     2,     4,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     3,     3,     3,     3,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     6,     7,     2,     0,
       2,     1,     4,     5,     1,     1,     0,     4,     3,     4,
       6,     3,     5,     3,     2,     5,     4,     5,     3,     3,
       4,     3,     4,     5,     6,     2,     1,     1,     1,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     4,
       2,     5,     3,     3,     8,     8,     9,     0,     1,     0,
       1,     4,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     4,     5,     2,     5,     2,     3,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    39,     0,     0,    86,     0,     0,     0,
     113,   114,   112,     0,     0,     0,     0,    38,     0,     0,
     120,   121,   116,   117,   118,   115,   119,     0,    33,     0,
       2,     3,     5,     8,     6,     7,     0,     0,    23,     9,
      81,     0,    21,    27,    19,    22,    20,     0,   107,   106,
     110,   108,    11,    12,    10,    18,    16,    17,    15,    13,
      14,    48,    49,     0,     0,   168,     0,     0,    50,    51,
       0,    46,    54,    56,     0,    61,    53,    45,    57,    58,
      47,    52,    55,     0,   166,     0,     0,     0,    84,    85,
       0,     0,     0,    94,     0,     0,     0,    57,     0,     0,
       0,     0,     0,    25,     0,     0,    30,    35,     0,     1,
       4,     0,     0,     0,   122,   123,   124,   125,   126,   127,
       0,     0,    35,    80,     0,    86,     0,   105,   111,   109,
       0,    60,     0,    59,     0,     0,   169,     0,     0,     0,
       0,     0,    67,    68,     0,     0,   101,   167,     0,     0,
       0,     0,     0,   128,    24,    93,     0,    98,    99,     0,
     159,     0,     0,   160,   161,   133,     0,    26,    35,     0,
       0,    40,    34,    88,     0,    43,   157,   158,     0,    28,
       0,     0,     0,   132,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,     0,     0,   142,   143,
     144,     0,    62,    63,    64,    65,    66,     0,     0,     0,
      35,   137,     0,    82,     0,   129,   100,     0,     0,   164,
     162,     0,    96,    31,    75,    69,    70,    71,    73,    72,
      74,    36,    37,     0,    32,    87,     0,    42,     0,   102,
       0,    29,     0,    35,     0,   141,     0,   103,    35,     0,
     138,     0,     0,     0,   130,    97,     0,   165,    41,    44,
       0,    83,   131,    79,    35,    95,     0,     0,   139,     0,
      91,     0,     0,   104,     0,    76,    79,     0,     0,   140,
       0,     0,     0,    89,   163,    78,    77,     0,   135,   134,
      92,     0,   136,    90
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    29,    30,    31,    32,    33,    34,    35,   105,   106,
      73,   171,    37,   234,    38,   174,   175,    75,    76,   232,
      77,   275,    39,    40,    90,    78,   213,    42,    79,    43,
      44,    45,    46,    47,    48,    49,    50,    51,   120,    52,
     215,    81,    53,    54,   251,   280,    82,   201,   196,    55,
      56,    57,   163,   164,    58,    59,    60
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -164
static const yytype_int16 yypact[] =
{
     331,   339,   -76,  -164,   358,   -27,   100,    -5,   -56,   -42,
    -164,  -164,  -164,    -6,    31,   435,   331,  -164,   435,    70,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,   286,    63,    99,
    -164,   331,  -164,  -164,  -164,  -164,    30,   -56,  -164,  -164,
    -164,    90,  -164,  -164,  -164,  -164,  -164,   121,  -164,   115,
      42,   115,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,   435,   -56,  -164,    -1,    -1,  -164,  -164,
      46,  -164,  -164,    43,    98,  -164,   135,  -164,  -164,  -164,
    -164,    71,  -164,     5,  -164,   110,   120,   488,  -164,  -164,
      72,   331,   124,  -164,   125,   127,   133,   134,   435,   136,
      48,   125,    -5,  -164,   140,     8,  -164,   407,   -56,  -164,
    -164,   370,   138,   144,  -164,  -164,  -164,  -164,  -164,  -164,
     435,    79,   142,  -164,    95,   100,   -56,  -164,  -164,  -164,
     480,  -164,    71,  -164,   154,   -33,  -164,    -1,    -1,    -1,
      -1,    -1,  -164,  -164,   435,   101,  -164,  -164,   168,   -56,
     153,    25,   160,   197,  -164,  -164,   157,  -164,  -164,   171,
    -164,   173,   331,   209,  -164,  -164,   175,  -164,   142,   -56,
      84,   139,  -164,  -164,    24,  -164,  -164,  -164,   172,  -164,
       6,   126,   113,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,    -5,   401,  -164,  -164,
    -164,   174,   -31,   -31,   -31,   -31,   135,   176,   125,   -56,
     142,    -1,   -44,  -164,   331,  -164,  -164,   178,   435,  -164,
    -164,   331,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,   435,  -164,  -164,   435,  -164,   129,  -164,
     160,  -164,   180,   142,    34,  -164,   435,  -164,   142,   149,
    -164,   183,    39,    52,  -164,  -164,   189,  -164,  -164,  -164,
     125,  -164,  -164,   155,   142,  -164,   156,   435,    -1,   -56,
    -164,    81,   331,  -164,   -56,  -164,   155,   435,   193,  -164,
     190,   125,   -56,  -164,  -164,  -164,  -164,   198,  -164,  -164,
    -164,   125,  -164,  -164
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,  -164,   102,  -164,   -10,  -164,    -8,   137,   -34,    76,
       0,  -163,   -45,  -164,  -164,    50,    21,   -55,   -25,  -164,
    -164,   -28,  -164,  -164,   130,    13,     9,  -164,  -164,    20,
    -164,  -164,  -164,   163,   122,   201,  -164,  -164,  -164,  -164,
    -164,     7,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,    96,  -164,  -164,  -164
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      36,    93,   126,   121,   252,   222,   100,    27,    92,    94,
      86,   131,   133,    41,    91,    61,    36,   145,   238,   198,
      87,    80,    74,    62,    80,    85,    97,   107,    83,    41,
     141,    36,     3,    80,    96,    80,    99,   122,    80,   101,
      41,    63,    63,    64,    41,    95,    63,   249,    28,   142,
     143,    66,    67,   161,    27,    27,    66,    67,   168,    17,
      28,   162,    28,   169,   122,    10,    11,    12,    68,    69,
     199,    28,   235,   132,   132,   146,    70,   111,    98,   236,
     263,   153,   264,    80,   130,   266,   155,    25,    27,   236,
     111,    36,   182,   165,   135,   269,    71,    72,    28,   109,
     271,   276,    72,    28,    41,   224,   126,   169,   172,   166,
     112,   113,   202,   203,   204,   205,   206,   102,    80,   159,
     114,   115,   116,   117,   118,   119,   122,   124,     3,   104,
      27,    80,   179,   110,   169,   200,   125,   282,    88,    89,
      80,   178,   108,   123,   132,   132,   132,   132,   132,   210,
     134,   136,   219,    20,    21,    17,   250,    22,    23,    24,
     144,    26,    36,   147,    80,   207,   241,   148,   169,   122,
     231,   127,   239,   129,    27,    41,   152,   154,   253,   156,
     225,   226,   227,   228,   229,   230,   157,   158,    28,   160,
     167,   176,   137,   138,   139,   140,   141,   177,   170,   180,
     247,   197,   209,   242,   254,   208,   211,   212,   214,   248,
     216,   257,   122,   279,    36,   142,   143,    80,   132,   217,
     218,    36,   162,   221,   150,   237,   245,    41,   262,   233,
     240,   255,   246,   260,    41,   267,   268,   272,    80,   256,
     274,   288,   277,   289,   270,   223,   292,   244,   286,   261,
     151,   128,   273,    80,   258,   181,    80,   259,     0,   220,
       0,     0,   284,   283,     0,     0,    80,   265,     0,   281,
       0,     0,    36,   290,   285,   132,     0,     0,     0,     0,
       0,     0,   291,   293,     0,    41,     0,    80,   278,     1,
       0,     0,     2,     3,     4,     0,     0,    80,   287,     0,
       5,     6,     7,     0,     8,     0,     0,     0,     9,    10,
      11,    12,    13,    14,     0,     0,    15,     0,    16,     0,
      17,    18,    19,     0,    20,    21,     0,     0,    22,    23,
      24,    25,    26,     0,     1,    27,   103,     2,     3,     4,
       0,     0,     0,     0,     0,     5,     6,     7,     0,     8,
       0,     0,     0,     9,    10,    11,    12,    13,    14,     0,
      61,    15,     0,    16,     0,    17,    18,    19,    62,    20,
      21,     0,     0,    22,    23,    24,    25,    26,     0,    61,
      27,     0,     0,     0,     0,     0,    63,    62,    64,     0,
      28,    61,    65,     0,     0,     0,    66,    67,     0,    62,
       0,     0,     0,     0,     0,    63,     0,    64,     0,     0,
       0,    84,     0,    68,    69,    66,    67,    63,   173,    64,
       0,    70,    61,     0,     0,     0,     0,    66,    67,     0,
      62,     0,    68,    69,     0,    28,     0,     0,     0,     0,
      70,    71,    72,    28,    68,    69,     0,     0,    63,   243,
      64,     0,    70,     0,   111,     0,    61,     0,    66,    67,
      71,    72,    28,   170,    62,     0,     0,     0,     0,     0,
       0,     0,    71,    72,    28,    68,    69,     0,     0,     0,
       0,     0,    63,    70,    64,     0,     0,   112,   113,     0,
       0,     0,    66,    67,     0,     3,     0,   114,   115,   116,
     117,   118,   119,    71,    72,    28,     0,     0,     0,    68,
      69,    10,    11,    12,     0,     0,     0,    70,     0,     0,
       0,     0,   149,     0,     0,     0,    20,    21,   183,     0,
      22,    23,    24,    25,    26,     0,     0,    71,    72,    28,
       0,     0,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195
};

static const yytype_int16 yycheck[] =
{
       0,     9,    47,    37,    48,   168,    16,    49,     8,     9,
      37,    66,    67,     0,     7,    21,    16,    12,    12,    52,
      47,     1,     1,    29,     4,     4,    13,    27,   104,    16,
      61,    31,     7,    13,    13,    15,    15,    37,    18,    18,
      27,    47,    47,    49,    31,    51,    47,   210,   104,    80,
      81,    57,    58,     5,    49,    49,    57,    58,    50,    34,
     104,    13,   104,    55,    64,    23,    24,    25,    74,    75,
     103,   104,    48,    66,    67,    83,    82,    47,    47,    55,
     243,    91,    48,    63,    63,   248,    94,    45,    49,    55,
      47,    91,   126,   101,    51,    56,   102,   103,   104,     0,
      48,   264,   103,   104,    91,    21,   151,    55,   108,   102,
      80,    81,   137,   138,   139,   140,   141,    47,    98,    98,
      90,    91,    92,    93,    94,    95,   126,     6,     7,    27,
      49,   111,    53,    31,    55,   135,    15,    56,    38,    39,
     120,   120,    79,    53,   137,   138,   139,   140,   141,   149,
     104,    53,   162,    38,    39,    34,   211,    42,    43,    44,
      89,    46,   162,    53,   144,   144,    53,    47,    55,   169,
     170,    49,   180,    51,    49,   162,   104,    53,   212,    52,
      96,    97,    98,    99,   100,   101,    53,    53,   104,    53,
      50,    53,    57,    58,    59,    60,    61,    53,    56,   104,
     208,    47,    34,   196,   214,   104,    53,    47,    11,   209,
      53,   221,   212,   268,   214,    80,    81,   197,   211,    48,
      47,   221,    13,    48,    87,    53,    52,   214,    48,    90,
     104,    53,    56,   104,   221,    86,    53,    48,   218,   218,
      85,    48,    86,    53,   252,   169,    48,   197,   276,   240,
      87,    50,   260,   233,   233,   125,   236,   236,    -1,   163,
      -1,    -1,   272,   271,    -1,    -1,   246,   246,    -1,   269,
      -1,    -1,   272,   281,   274,   268,    -1,    -1,    -1,    -1,
      -1,    -1,   282,   291,    -1,   272,    -1,   267,   267,     3,
      -1,    -1,     6,     7,     8,    -1,    -1,   277,   277,    -1,
      14,    15,    16,    -1,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    30,    -1,    32,    -1,
      34,    35,    36,    -1,    38,    39,    -1,    -1,    42,    43,
      44,    45,    46,    -1,     3,    49,    50,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    14,    15,    16,    -1,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    -1,
      21,    30,    -1,    32,    -1,    34,    35,    36,    29,    38,
      39,    -1,    -1,    42,    43,    44,    45,    46,    -1,    21,
      49,    -1,    -1,    -1,    -1,    -1,    47,    29,    49,    -1,
     104,    21,    53,    -1,    -1,    -1,    57,    58,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    47,    -1,    49,    -1,    -1,
      -1,    53,    -1,    74,    75,    57,    58,    47,    48,    49,
      -1,    82,    21,    -1,    -1,    -1,    -1,    57,    58,    -1,
      29,    -1,    74,    75,    -1,   104,    -1,    -1,    -1,    -1,
      82,   102,   103,   104,    74,    75,    -1,    -1,    47,    48,
      49,    -1,    82,    -1,    47,    -1,    21,    -1,    57,    58,
     102,   103,   104,    56,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   102,   103,   104,    74,    75,    -1,    -1,    -1,
      -1,    -1,    47,    82,    49,    -1,    -1,    80,    81,    -1,
      -1,    -1,    57,    58,    -1,     7,    -1,    90,    91,    92,
      93,    94,    95,   102,   103,   104,    -1,    -1,    -1,    74,
      75,    23,    24,    25,    -1,    -1,    -1,    82,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    38,    39,    48,    -1,
      42,    43,    44,    45,    46,    -1,    -1,   102,   103,   104,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,     8,    14,    15,    16,    18,    22,
      23,    24,    25,    26,    27,    30,    32,    34,    35,    36,
      38,    39,    42,    43,    44,    45,    46,    49,   104,   107,
     108,   109,   110,   111,   112,   113,   116,   118,   120,   128,
     129,   131,   133,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   145,   148,   149,   155,   156,   157,   160,   161,
     162,    21,    29,    47,    49,    53,    57,    58,    74,    75,
      82,   102,   103,   116,   122,   123,   124,   126,   131,   134,
     135,   147,   152,   104,    53,   122,    37,    47,    38,    39,
     130,   147,   116,   112,   116,    51,   122,   131,    47,   122,
     110,   122,    47,    50,   108,   114,   115,   116,    79,     0,
     108,    47,    80,    81,    90,    91,    92,    93,    94,    95,
     144,   114,   116,    53,     6,    15,   118,   140,   141,   140,
     122,   123,   147,   123,   104,    51,    53,    57,    58,    59,
      60,    61,    80,    81,    89,    12,   112,    53,    47,    34,
     113,   139,   104,   110,    53,   112,    52,    53,    53,   122,
      53,     5,    13,   158,   159,   112,   147,    50,    50,    55,
      56,   117,   116,    48,   121,   122,    53,    53,   122,    53,
     104,   130,   114,    48,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,   154,    47,    52,   103,
     116,   153,   124,   124,   124,   124,   124,   122,   104,    34,
     116,    53,    47,   132,    11,   146,    53,    48,    47,   110,
     159,    48,   117,   115,    21,    96,    97,    98,    99,   100,
     101,   116,   125,    90,   119,    48,    55,    53,    12,   112,
     104,    53,   147,    48,   121,    52,    56,   112,   116,   117,
     123,   150,    48,   114,   110,    53,   122,   110,   122,   122,
     104,   132,    48,   117,    48,   122,   117,    86,    53,    56,
     112,    48,    48,   112,    85,   127,   117,    86,   122,   123,
     151,   116,    56,   112,   110,   116,   127,   122,    48,    53,
     112,   116,    48,   112
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 250 "yyparse.y"
    { (yyval.n) = makeNode(program, global_table, NULL, 1, (yyvsp[(1) - (1)].n)); head = (yyval.n); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 254 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 255 "yyparse.y"
    {(yyval.n) = makeNode(sourceElements, NULL, NULL, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 259 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 264 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 265 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 266 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 267 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 268 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 269 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 270 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 271 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 272 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 273 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 275 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 276 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 277 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 278 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 279 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 280 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 281 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 282 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 286 "yyparse.y"
    {(yyval.n) = makeNode(importStatement, NULL, NULL, 1, (yyvsp[(2) - (3)].n));;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 295 "yyparse.y"
    {(yyval.n) = makeNode(block, makeTable(NULL), NULL, 0);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 296 "yyparse.y"
    {(yyval.n) = makeNode(block, makeTable(NULL), NULL, 1, (yyvsp[(2) - (3)].n));;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 297 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 301 "yyparse.y"
    {(yyval.n) = makeNode(variableDeclaration, NULL, NULL, 2, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n));;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 302 "yyparse.y"
    {(yyval.n) = makeNode(variableDeclaration, NULL, NULL, 3, (yyvsp[(1) - (4)].n), (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n));;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 306 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 307 "yyparse.y"
    {(yyval.n) = makeNode(variableDeclarationList, NULL, NULL, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n));;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 311 "yyparse.y"
    {(yyval.n) = makeNode(variableBinding, NULL, NULL, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n));
     (yyval.n)->nodeType = strdup( getOptionalNodeType( (yyvsp[(2) - (3)].n)) );
     if((yyvsp[(1) - (3)].n) != NULL) 
       (yyvsp[(1) - (3)].n)->nodeType = strdup( getOptionalNodeType( (yyvsp[(2) - (3)].n)) ); 
     if((yyvsp[(3) - (3)].n) != NULL) 
       (yyvsp[(3) - (3)].n)->nodeType = strdup( getOptionalNodeType( (yyvsp[(2) - (3)].n)) ); 
     if((yyvsp[(2) - (3)].n) != NULL){ 
       (yyvsp[(2) - (3)].n)->nodeType = strdup( getOptionalNodeType( (yyvsp[(2) - (3)].n)) );
     }
   ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 324 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n) ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 325 "yyparse.y"
    {(yyval.n) = makeNode(variableName, NULL, NULL, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 329 "yyparse.y"
    {(yyval.n) = NULL;;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 330 "yyparse.y"
    {(yyval.n) = makeNode(optionalVariableType, NULL, NULL, 1, (yyvsp[(2) - (2)].n)); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 331 "yyparse.y"
    { (yyval.n) = makeNode(optionalVariableType, NULL, NULL, 1, (yyvsp[(2) - (2)].n)); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 335 "yyparse.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n) ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 336 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 340 "yyparse.y"
    {(yyval.n) = NULL;;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 341 "yyparse.y"
    {(yyval.n) = makeNode(variableInitialization, NULL, NULL, 1, (yyvsp[(2) - (2)].n));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 345 "yyparse.y"
    {(yyval.n) = makeNode(assignStatement, NULL, NULL, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n)); (yyval.n)->operator = (yyvsp[(2) - (4)].n)->label;;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 349 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 350 "yyparse.y"
    {(yyval.n) = makeNode(valueList, NULL, NULL, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n));;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 354 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 355 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 356 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 357 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 358 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 359 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 360 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 361 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 362 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 366 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 367 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 368 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 369 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 370 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 371 "yyparse.y"
    {(yyval.n) = makeNode(mathValue, NULL, NULL, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); (yyval.n)->operator = MINUS;;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 372 "yyparse.y"
    {(yyval.n) = makeNode(mathValue, NULL, NULL, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n)); (yyval.n)->operator = PLUS;;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 376 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 377 "yyparse.y"
    {(yyval.n) = makeNode(expr, NULL, NULL, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); (yyval.n)->operator = PLUS;;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 378 "yyparse.y"
    {(yyval.n) = makeNode(expr, NULL, NULL, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); (yyval.n)->operator = MINUS;;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 379 "yyparse.y"
    {(yyval.n) = makeNode(expr, NULL, NULL, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); (yyval.n)->operator = MULTIPLY;;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 380 "yyparse.y"
    {(yyval.n) = makeNode(expr, NULL, NULL, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); (yyval.n)->operator = DIVIDE;;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 381 "yyparse.y"
    {(yyval.n) = makeNode(expr, NULL, NULL, 2, (yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n)); (yyval.n)->operator = MODULO;;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 382 "yyparse.y"
    {(yyval.n) = makeNode(expr, NULL, NULL, 1, (yyvsp[(2) - (2)].n)); (yyval.n)->operator = INCREMENT;;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 383 "yyparse.y"
    {(yyval.n) = makeNode(expr, NULL, NULL, 1, (yyvsp[(2) - (2)].n)); (yyval.n)->operator = DECREMENT;;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 387 "yyparse.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n) ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 388 "yyparse.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n) ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 389 "yyparse.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n) ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 390 "yyparse.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n) ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 391 "yyparse.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n) ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 392 "yyparse.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n) ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 393 "yyparse.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n) ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 397 "yyparse.y"
    {(yyval.n) = makeNode(newObject, NULL, NULL, 3, (yyvsp[(2) - (6)].n), (yyvsp[(5) - (6)].n), (yyvsp[(6) - (6)].n)); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 398 "yyparse.y"
    {(yyval.n) = makeNode(newObject, NULL, NULL, 4, (yyvsp[(2) - (7)].n), (yyvsp[(4) - (7)].n), (yyvsp[(6) - (7)].n), (yyvsp[(7) - (7)].n)); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 402 "yyparse.y"
    {(yyval.n) = makeNode(as, NULL, NULL, 1, (yyvsp[(2) - (2)].n));}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 403 "yyparse.y"
    {(yyval.n) = NULL;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 407 "yyparse.y"
    {(yyval.n) = makeNode(functionStatement, NULL, NULL, 1, (yyvsp[(1) - (2)].n));;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 408 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 412 "yyparse.y"
    {(yyval.n) = makeNode(functionDeclaration, NULL, NULL, 3, (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); (yyvsp[(3) - (4)].n)->targetScope = (yyvsp[(4) - (4)].n)->targetScope; ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 413 "yyparse.y"
    {(yyval.n) = makeNode(functionDeclaration, NULL, NULL, 4, (yyvsp[(1) - (5)].n), (yyvsp[(3) - (5)].n), (yyvsp[(4) - (5)].n), (yyvsp[(5) - (5)].n)); (yyvsp[(4) - (5)].n)->targetScope = (yyvsp[(5) - (5)].n)->targetScope;;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 417 "yyparse.y"
    {(yyval.n)=(yyvsp[(1) - (1)].n);}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 418 "yyparse.y"
    {(yyval.n)=(yyvsp[(1) - (1)].n);}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 419 "yyparse.y"
    {(yyval.n)=NULL;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 423 "yyparse.y"
    {(yyval.n) = makeNode(functionCall, NULL, NULL, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n));;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 424 "yyparse.y"
    {(yyval.n) = makeNode(functionCall, NULL, NULL, 1, (yyvsp[(1) - (3)].n));;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 428 "yyparse.y"
    {(yyval.n) = makeNode(functionHeader, NULL, NULL, 2, (yyvsp[(2) - (4)].n), (yyvsp[(4) - (4)].n)); (yyval.n)->targetScope = (yyvsp[(4) - (4)].n)->table; ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 429 "yyparse.y"
    {(yyval.n) = makeNode(functionHeader, NULL, NULL, 3, (yyvsp[(2) - (6)].n), (yyvsp[(5) - (6)].n), (yyvsp[(6) - (6)].n)); (yyval.n)->targetScope = (yyvsp[(6) - (6)].n)->table; ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 430 "yyparse.y"
    {(yyval.n) = makeNode(functionHeader, NULL, NULL, 1, (yyvsp[(3) - (3)].n)); (yyval.n)->targetScope = (yyvsp[(3) - (3)].n)->table; ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 431 "yyparse.y"
    {(yyval.n) = makeNode(functionHeader, NULL, NULL, 2, (yyvsp[(4) - (5)].n), (yyvsp[(5) - (5)].n)); (yyval.n)->targetScope = (yyvsp[(5) - (5)].n)->table; ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 435 "yyparse.y"
    {(yyval.n) = makeNode(packageStatement, NULL, NULL, 2, (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); (yyvsp[(2) - (3)].n)->targetScope = (yyvsp[(3) - (3)].n)->table;;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 436 "yyparse.y"
    {
     token* tok = (token*)malloc(sizeof(token));
     tok->category = IDENT;
     tok->text = newLabel();
     tok->lineno = YYTOKEN->lineno;
     tok->filename = strdup(FILENAME);
     node* token = makeNode(IDENT, NULL, tok, 0);
     (yyval.n) = makeNode(packageStatement, NULL, NULL, 2, token, (yyvsp[(2) - (2)].n));
     token->targetScope = (yyvsp[(2) - (2)].n)->table;
   ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 449 "yyparse.y"
    {(yyval.n) = makeNode(ternaryExpression, NULL, NULL, 3, (yyvsp[(1) - (5)].n), (yyvsp[(3) - (5)].n), (yyvsp[(5) - (5)].n));;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 453 "yyparse.y"
    {(yyval.n) = makeNode(objectInitializer, NULL, NULL, 2, (yyvsp[(2) - (4)].n), (yyvsp[(4) - (4)].n));;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 457 "yyparse.y"
    {(yyval.n) = makeNode(superStatement, NULL, NULL, 1, (yyvsp[(3) - (5)].n));;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 461 "yyparse.y"
    {(yyval.n) = makeNode(returnStatement, NULL, NULL, 1, (yyvsp[(2) - (3)].n));;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 462 "yyparse.y"
    {(yyval.n) = makeNode(returnStatement, NULL, NULL, 1, (yyvsp[(2) - (3)].n));;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 463 "yyparse.y"
    {(yyval.n) = makeNode(returnStatement, NULL, NULL, 0);;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 467 "yyparse.y"
    {(yyval.n) = makeNode(classStatement, NULL, NULL, 2, (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n)); (yyvsp[(2) - (3)].n)->targetScope = (yyvsp[(3) - (3)].n)->table; ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 468 "yyparse.y"
    {(yyval.n) = makeNode(classStatement, NULL, NULL, 3, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n)); (yyvsp[(3) - (4)].n)->targetScope = (yyvsp[(4) - (4)].n)->table;  ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 469 "yyparse.y"
    {(yyval.n) = makeNode(classStatement, NULL, NULL, 3, (yyvsp[(2) - (5)].n), (yyvsp[(4) - (5)].n), (yyvsp[(5) - (5)].n)); (yyvsp[(2) - (5)].n)->targetScope = (yyvsp[(5) - (5)].n)->table;   ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 470 "yyparse.y"
    {(yyval.n) = makeNode(classStatement, NULL, NULL, 4, (yyvsp[(1) - (6)].n), (yyvsp[(3) - (6)].n), (yyvsp[(5) - (6)].n), (yyvsp[(6) - (6)].n)); (yyvsp[(3) - (6)].n)->targetScope = (yyvsp[(6) - (6)].n)->table; ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 474 "yyparse.y"
    {(yyval.n) = makeNode(modifier, NULL, NULL, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n));;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 475 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 476 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 480 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 481 "yyparse.y"
    {(yyval.n) = makeNode(modifierSuffix, NULL, NULL, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n));;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 484 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 485 "yyparse.y"
    {(yyval.n) = makeNode(modifierPrefix, NULL, NULL, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n));;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 489 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 490 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 491 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 492 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 496 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 497 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 498 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 499 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 500 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 501 "yyparse.y"
    { (yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 505 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 506 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 507 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 508 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 509 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 510 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 514 "yyparse.y"
    {(yyval.n) = makeNode(ifStatement, NULL, NULL, 2, (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n));;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 515 "yyparse.y"
    {(yyval.n) = makeNode(ifStatement, NULL, NULL, 3, (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n));;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 519 "yyparse.y"
    {(yyval.n) = makeNode(elseStatement, NULL, NULL, 1, (yyvsp[(2) - (2)].n));;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 523 "yyparse.y"
    {(yyval.n) = makeNode(expression, NULL, NULL, 2, (yyvsp[(2) - (5)].n), (yyvsp[(4) - (5)].n)); (yyval.n)->operator = (yyvsp[(3) - (5)].n)->label;;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 524 "yyparse.y"
    {(yyval.n) = makeNode(expression, NULL, NULL, 1, (yyvsp[(2) - (3)].n));;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 528 "yyparse.y"
    {(yyval.n) = makeNode(whileStatement, NULL, NULL, 2, (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n));;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 532 "yyparse.y"
    {(yyval.n) = makeNode(forStatement, NULL, NULL, 3, (yyvsp[(3) - (8)].n), (yyvsp[(5) - (8)].n), (yyvsp[(7) - (8)].n));;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 533 "yyparse.y"
    {(yyval.n) = makeNode(forStatement, NULL, NULL, 3, (yyvsp[(4) - (8)].n), (yyvsp[(5) - (8)].n), (yyvsp[(7) - (8)].n));;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 534 "yyparse.y"
    {(yyval.n) = makeNode(forStatement, NULL, NULL, 3, (yyvsp[(5) - (9)].n), (yyvsp[(6) - (9)].n), (yyvsp[(8) - (9)].n));;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 538 "yyparse.y"
    {(yyval.n) = NULL;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 539 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 543 "yyparse.y"
    {(yyval.n) = NULL;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 544 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 548 "yyparse.y"
    {(yyval.n) = makeNode(arrayAccessor, NULL, NULL, 2, (yyvsp[(1) - (4)].n), (yyvsp[(3) - (4)].n));;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 549 "yyparse.y"
    {(yyval.n) = makeNode(arrayAccessor, NULL, NULL, 3, (yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n));;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 553 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 554 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 558 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 559 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 560 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 561 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 562 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 563 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 564 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 565 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 566 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 567 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 568 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 569 "yyparse.y"
    {(yyval.n) = (yyvsp[(1) - (1)].n);}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 573 "yyparse.y"
    {(yyval.n) = makeNode(iterationStatement, NULL, NULL, 1, (yyvsp[(1) - (3)].n));;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 574 "yyparse.y"
    {(yyval.n) = makeNode(iterationStatement, NULL, NULL, 1, (yyvsp[(1) - (3)].n));;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 578 "yyparse.y"
    {(yyval.n) = makeNode(throwStatement, NULL, NULL, 1, (yyvsp[(2) - (3)].n));;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 582 "yyparse.y"
    {(yyval.n) = makeNode(tryStatement, NULL, NULL, 2, (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n));;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 583 "yyparse.y"
    {(yyval.n) = makeNode(tryStatement, NULL, NULL, 2, (yyvsp[(2) - (3)].n), (yyvsp[(3) - (3)].n));;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 584 "yyparse.y"
    {(yyval.n) = makeNode(tryStatement, NULL, NULL, 3, (yyvsp[(2) - (4)].n), (yyvsp[(3) - (4)].n), (yyvsp[(4) - (4)].n));;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 588 "yyparse.y"
    {(yyval.n) = makeNode(catch, NULL, NULL, 2, (yyvsp[(3) - (5)].n), (yyvsp[(5) - (5)].n));;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 592 "yyparse.y"
    {(yyval.n) = makeNode(finally, NULL, NULL, 1, (yyvsp[(2) - (2)].n));;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 596 "yyparse.y"
    {(yyval.n) = makeNode(withStatement, NULL, NULL, 2, (yyvsp[(3) - (5)].n), (yyvsp[(5) - (5)].n));;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 600 "yyparse.y"
    {(yyval.n) = makeNode(continueStatement, NULL, NULL, 0);;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 601 "yyparse.y"
    {(yyval.n) = makeNode(continueStatement, NULL, NULL, 1, (yyvsp[(2) - (3)].n));;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 605 "yyparse.y"
    {(yyval.n) = makeNode(breakStatement, NULL, NULL, 2, (yyvsp[(1) - (2)].n), (yyvsp[(2) - (2)].n));;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 606 "yyparse.y"
    {(yyval.n) = makeNode(breakStatement, NULL, NULL, 1, (yyvsp[(2) - (3)].n));;}
    break;



/* Line 1455 of yacc.c  */
#line 3030 "yyparse.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



