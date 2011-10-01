
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


// better error reporting
#define YYERROR_VERBOSE
  extern char* yytext;
  extern int LINENO;
  extern int failed;
  extern char* FILENAME;
  
// bison requires that you supply this function
void yyerror(const char *msg)
{
  failed++;
  printf("Filename: %s\n", FILENAME);
  printf("ERROR(PARSER): %s, %s\nLine Number: %d\n", msg, yytext, LINENO);
}



/* Line 189 of yacc.c  */
#line 96 "yyparse.tab.c"

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
     STRINGLIT = 402,
     NUMBERLIT = 403,
     IDENT = 358,
     OTHER = 400
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 24 "yyparse.y"

  int var;  
 


/* Line 214 of yacc.c  */
#line 242 "yyparse.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 254 "yyparse.tab.c"

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
#define YYFINAL  104
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   418

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  152
/* YYNRULES -- Number of states.  */
#define YYNSTATES  269

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   403

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
      88,    89,    90,    91,    92,    93,    94,    95,   103,    96,
      97,    98,    10,     4,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     104,     2,   101,   102
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    46,    48,    52,    55,    59,    61,    65,
      70,    72,    76,    80,    82,    86,    87,    90,    92,    94,
      95,    98,   103,   106,   107,   109,   113,   115,   117,   119,
     121,   123,   125,   127,   129,   131,   133,   135,   137,   143,
     150,   152,   154,   159,   165,   167,   169,   170,   176,   181,
     186,   193,   197,   203,   207,   213,   218,   224,   228,   232,
     237,   241,   246,   252,   259,   262,   264,   266,   268,   271,
     273,   276,   278,   280,   282,   284,   286,   288,   290,   292,
     294,   296,   298,   300,   302,   304,   306,   310,   315,   318,
     324,   328,   330,   334,   344,   354,   359,   363,   365,   367,
     369,   371,   373,   375,   377,   379,   381,   383,   385,   387,
     389,   391,   395,   399,   402,   405,   409,   413,   415,   417,
     419,   421,   423,   427,   431,   435,   440,   446,   449,   455,
     458,   462,   465
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     106,     0,    -1,   107,    -1,   108,    -1,   108,   107,    -1,
     109,    -1,   111,    -1,   112,    -1,   110,    -1,   124,    -1,
     145,    -1,   141,    -1,   144,    -1,   157,    -1,   158,    -1,
     156,    -1,   152,    -1,   153,    -1,   149,    -1,   132,    -1,
     134,    -1,   129,    -1,   133,    -1,   119,    -1,    18,   115,
      53,    -1,    49,    50,    -1,    49,   107,    50,    -1,   131,
      -1,   117,   113,    53,    -1,   135,   117,   113,    53,    -1,
     114,    -1,   113,    55,   114,    -1,   115,   116,   118,    -1,
     103,    -1,   103,    79,   115,    -1,    -1,    56,   115,    -1,
      34,    -1,     7,    -1,    -1,    90,   122,    -1,   115,   140,
     122,    53,    -1,    85,   122,    -1,    -1,   122,    -1,   121,
      55,   122,    -1,   123,    -1,   102,    -1,   101,    -1,   115,
      -1,   131,    -1,   146,    -1,    21,    -1,   127,    -1,    29,
      -1,   130,    -1,    74,    -1,    75,    -1,    82,   103,    47,
      48,   116,    -1,    82,   103,    47,   113,    48,   116,    -1,
     127,    -1,   125,    -1,    15,   126,   103,   128,    -1,   135,
      15,   126,   103,   128,    -1,    38,    -1,    39,    -1,    -1,
     115,    47,   121,    48,    53,    -1,   115,    47,    48,    53,
      -1,    47,   113,    48,   111,    -1,    47,   113,    48,    56,
     115,   111,    -1,    47,    48,   111,    -1,    47,    48,    56,
     115,   111,    -1,    22,   115,   111,    -1,   143,    89,   122,
      56,   122,    -1,    49,   113,    50,   116,    -1,    27,    47,
     122,    48,    53,    -1,    26,   122,    53,    -1,    26,   127,
      53,    -1,    26,    51,    52,    53,    -1,     6,   103,   111,
      -1,   135,     6,   103,   111,    -1,     6,   103,    12,   103,
     111,    -1,   135,     6,   103,    12,   103,   111,    -1,   137,
     136,    -1,   137,    -1,   136,    -1,   139,    -1,   139,   136,
      -1,   138,    -1,   138,   137,    -1,    25,    -1,    23,    -1,
      24,    -1,    45,    -1,    42,    -1,    43,    -1,    44,    -1,
      46,    -1,    38,    -1,    90,    -1,    91,    -1,    92,    -1,
      93,    -1,    94,    -1,    95,    -1,    16,   143,   109,    -1,
      16,   143,   109,   142,    -1,    11,   109,    -1,    47,   115,
     148,   143,    48,    -1,    47,   115,    48,    -1,   115,    -1,
      35,   143,   111,    -1,    14,    47,    34,   103,   143,    53,
     150,    48,   111,    -1,    14,    37,    47,    34,   115,    86,
     122,    48,   111,    -1,   122,    51,   147,    52,    -1,   122,
      51,    52,    -1,   102,    -1,   115,    -1,    62,    -1,    63,
      -1,    64,    -1,    65,    -1,    66,    -1,    67,    -1,    68,
      -1,    69,    -1,    70,    -1,    71,    -1,    72,    -1,    73,
      -1,   115,    80,    53,    -1,   115,    81,    53,    -1,   115,
      80,    -1,   115,    81,    -1,   115,   151,   115,    -1,   115,
     120,   115,    -1,    59,    -1,    60,    -1,    61,    -1,    57,
      -1,    58,    -1,    30,   122,    53,    -1,    32,   109,   154,
      -1,    32,   109,   155,    -1,    32,   109,   154,   155,    -1,
       5,    47,   122,    48,   109,    -1,    13,   109,    -1,    36,
      47,   143,    48,   109,    -1,     8,    53,    -1,     8,   122,
      53,    -1,     3,    53,    -1,     3,   122,    53,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   157,   157,   161,   162,   166,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   182,   183,   184,   185,
     186,   187,   188,   189,   193,   202,   203,   204,   208,   209,
     213,   214,   218,   222,   223,   226,   228,   232,   233,   236,
     238,   242,   273,   274,   287,   288,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   307,   308,
     312,   313,   317,   318,   322,   323,   324,   328,   329,   333,
     334,   335,   336,   340,   344,   348,   352,   356,   357,   358,
     362,   363,   364,   365,   369,   370,   371,   375,   376,   379,
     380,   384,   385,   386,   387,   391,   392,   393,   394,   395,
     399,   400,   401,   402,   403,   404,   408,   409,   413,   417,
     418,   419,   423,   427,   428,   432,   433,   437,   438,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   457,   458,   462,   463,   464,   465,   469,   470,   471,
     475,   476,   480,   484,   485,   486,   490,   494,   498,   502,
     503,   507,   508
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
  "STRINGLIT", "NUMBERLIT", "IDENT", "OTHER", "$accept", "program",
  "sourceElements", "sourceElement", "statement", "importStatement",
  "block", "variableDeclaration", "variableDeclarationList",
  "variableBinding", "variableName", "optionalVariableType",
  "variableKind", "variableInitialization", "assignStatement", "as",
  "valueList", "value", "newObject", "functionStatement",
  "functionDeclaration", "getterSetter", "functionCall", "functionHeader",
  "packageStatement", "ternaryExpression", "objectInitializer",
  "superStatement", "returnStatement", "classStatement", "modifier",
  "modifierSuffix", "modifierPrefix", "prefixKeyword", "suffixKeyword",
  "assign", "ifStatement", "elseStatement", "expression", "whileStatement",
  "forStatement", "arrayAccessor", "accessValue", "logicalOperator",
  "iterationStatement", "mathExpression", "pemd", "throwStatement",
  "tryStatement", "catch", "finally", "withStatement", "continueStatement",
  "breakStatement", 0
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
     332,   402,   403,   358,   400
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   105,   106,   107,   107,   108,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   110,   111,   111,   111,   112,   112,
     113,   113,   114,   115,   115,   116,   116,   117,   117,   118,
     118,   119,   120,   120,   121,   121,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   123,   123,
     124,   124,   125,   125,   126,   126,   126,   127,   127,   128,
     128,   128,   128,   129,   130,   131,   132,   133,   133,   133,
     134,   134,   134,   134,   135,   135,   135,   136,   136,   137,
     137,   138,   138,   138,   138,   139,   139,   139,   139,   139,
     140,   140,   140,   140,   140,   140,   141,   141,   142,   143,
     143,   143,   144,   145,   145,   146,   146,   147,   147,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   149,   149,   150,   150,   150,   150,   151,   151,   151,
     120,   120,   152,   153,   153,   153,   154,   155,   156,   157,
     157,   158,   158
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     3,     1,     3,     4,
       1,     3,     3,     1,     3,     0,     2,     1,     1,     0,
       2,     4,     2,     0,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     6,
       1,     1,     4,     5,     1,     1,     0,     5,     4,     4,
       6,     3,     5,     3,     5,     4,     5,     3,     3,     4,
       3,     4,     5,     6,     2,     1,     1,     1,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     4,     2,     5,
       3,     1,     3,     9,     9,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     2,     2,     3,     3,     1,     1,     1,
       1,     1,     3,     3,     3,     4,     5,     2,     5,     2,
       3,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    38,     0,     0,    66,     0,     0,     0,
      92,    93,    91,     0,     0,     0,     0,    37,     0,     0,
      99,    95,    96,    97,    94,    98,     0,    33,     0,     2,
       3,     5,     8,     6,     7,     0,     0,    23,     9,    61,
      60,    21,    27,    19,    22,    20,     0,    86,    85,    89,
      87,    11,    12,    10,    18,    16,    17,    15,    13,    14,
      52,    54,     0,     0,   151,    56,    57,     0,    48,    47,
      49,     0,    46,    53,    55,    50,     0,    51,     0,   149,
       0,     0,     0,    64,    65,     0,   111,     0,     0,     0,
       0,     0,    53,     0,     0,     0,     0,     0,    25,     0,
       0,    30,    35,     0,     1,     4,     0,     0,     0,   100,
     101,   102,   103,   104,   105,     0,     0,    35,     0,    66,
       0,    84,    90,    88,     0,     0,     0,   152,     0,     0,
      80,   150,     0,     0,     0,   106,    24,    73,     0,    77,
      78,     0,   142,     0,     0,   143,   144,   112,     0,    26,
      35,     0,     0,    39,    34,     0,     0,    44,   131,   132,
       0,    28,     0,     0,     0,   110,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,     0,     0,
     116,   117,   118,     0,     0,     0,     0,     0,     0,    62,
       0,   107,    79,     0,     0,   147,   145,     0,    75,    31,
      36,     0,    32,    68,     0,     0,    41,     0,    81,     0,
      29,     0,    35,     0,   115,     0,    82,     0,     0,     0,
       0,   108,    76,     0,   148,    40,    67,    45,     0,    63,
     109,    58,    35,    74,     0,     0,     0,    71,     0,     0,
      83,    59,     0,    43,     0,     0,     0,    69,   146,     0,
     140,   141,   137,   138,   139,   133,   134,     0,     0,     0,
       0,    72,     0,   114,    42,   136,   135,   113,    70
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    28,    29,    30,    31,    32,    33,    34,   100,   101,
      70,   153,    36,   202,    37,   258,   156,    71,    72,    38,
      39,    85,    73,   189,    41,    74,    42,    43,    44,    45,
      46,    47,    48,    49,    50,   115,    51,   191,    76,    52,
      53,    77,   183,   178,    54,   244,   259,    55,    56,   145,
     146,    57,    58,    59
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -123
static const yytype_int16 yypact[] =
{
     291,   -10,   -88,  -123,     4,    22,   157,   -43,   -56,   -56,
    -123,  -123,  -123,   118,    20,   299,   291,  -123,   -43,    33,
    -123,  -123,  -123,  -123,  -123,  -123,   246,     5,    96,  -123,
     291,  -123,  -123,  -123,  -123,    69,   -56,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,    34,  -123,    39,    31,
      39,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,   -56,   -56,  -123,  -123,  -123,    -3,  -123,  -123,
     -15,    80,  -123,  -123,  -123,  -123,    49,  -123,    17,  -123,
     102,    62,    83,  -123,  -123,    43,  -123,   291,    89,   109,
     122,   103,   124,   299,   115,    37,   109,   -43,  -123,   131,
      44,  -123,   297,   -56,  -123,  -123,   283,   132,   136,  -123,
    -123,  -123,  -123,  -123,  -123,   299,   117,   143,   101,   157,
     -56,  -123,  -123,  -123,   345,   160,   -32,  -123,   299,   105,
    -123,  -123,   177,   114,   165,   211,  -123,  -123,   173,  -123,
    -123,    47,  -123,   186,   291,   224,  -123,  -123,   190,  -123,
     143,   -56,   -56,   151,  -123,   191,    56,   194,  -123,  -123,
     120,  -123,    26,   144,   127,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,   -43,   -45,
    -123,  -123,  -123,   196,    57,   109,   -56,   -43,   -42,  -123,
     291,  -123,  -123,   203,   299,  -123,  -123,   291,  -123,  -123,
    -123,   299,  -123,  -123,   204,   299,  -123,   164,  -123,   165,
    -123,   215,   143,    64,  -123,   299,  -123,   188,   222,    72,
      74,  -123,  -123,    84,  -123,   194,  -123,   194,   109,  -123,
    -123,  -123,   143,   194,   299,   -56,   -56,  -123,    78,   291,
    -123,  -123,    92,   170,   229,   109,   -56,  -123,  -123,   109,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,   299,   -56,   -56,
     109,  -123,   109,  -123,   194,  -123,  -123,  -123,  -123
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,    18,  -123,   -14,  -123,   -44,  -123,   -31,   128,
       0,  -122,   237,  -123,  -123,  -123,  -123,     8,  -123,  -123,
    -123,   166,     1,    77,  -123,  -123,     9,  -123,  -123,  -123,
    -123,   184,   238,  -123,  -123,  -123,  -123,  -123,    28,  -123,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
     148,  -123,  -123,  -123
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -112
static const yytype_int16 yytable[] =
{
      35,    40,    95,   212,    62,   116,   219,    86,    88,    89,
      75,    60,    80,    75,    92,    78,    35,    40,    86,    61,
     180,    91,    75,    94,    75,    60,   102,    40,   198,   129,
      35,    40,   106,    61,   130,    87,   117,    62,   207,    63,
     118,     3,   143,    64,    99,   137,    96,    27,   105,   119,
     144,    62,   147,    63,    10,    11,    12,    79,    27,    81,
      27,    27,   124,   117,    65,    66,    26,    93,    17,    82,
     181,    27,    67,   135,  -111,    26,    24,    20,    65,    66,
      97,    21,    22,    23,   103,    25,    67,    35,    40,   164,
     231,    68,    69,    27,   150,   193,   104,    86,   126,   151,
     125,   141,    75,   154,   204,    68,    69,    27,   126,   132,
     241,   205,   232,   215,   157,    75,   106,   133,   208,   151,
     117,    26,   238,   160,    75,   148,   182,    26,   236,   151,
     195,   126,   239,   127,   246,   126,   184,    75,   128,    60,
     249,   216,   136,   126,    35,    40,   134,    61,   213,   107,
     108,   117,   200,   126,   126,   131,   139,   220,    26,   109,
     110,   111,   112,   113,   114,    62,   126,    63,   142,    90,
     161,   126,   151,   206,   138,   237,   221,   140,    86,   117,
     210,   149,   151,   224,   240,   158,   217,    86,   117,   159,
      35,    40,    65,    66,   247,    83,    84,    35,    40,   152,
      67,   261,   223,    75,   162,   263,   211,   179,   185,   225,
      75,   186,   188,   227,    75,   218,   267,   187,   268,    68,
      69,    27,   190,   233,    75,   248,   192,   250,   251,   252,
     253,   254,   121,   194,   123,   243,   245,   144,   197,    35,
      40,   201,   242,    75,   203,   126,   262,   209,   214,     1,
     255,   256,     2,     3,     4,   257,   222,   226,   265,   266,
       5,     6,     7,   230,     8,   264,    75,   228,     9,    10,
      11,    12,    13,    14,   234,   235,    15,   260,    16,   199,
      17,    18,    19,   120,    20,   163,   229,   122,    21,    22,
      23,    24,    25,   196,     1,    26,    98,     2,     3,     4,
       0,     0,     0,     0,    60,     5,     6,     7,     0,     8,
       0,     0,    61,     9,    10,    11,    12,    13,    14,     0,
      60,    15,     0,    16,     0,    17,    18,    19,    61,    20,
      62,   155,    63,    21,    22,    23,    24,    25,     0,     0,
      26,     0,     0,     0,   106,     0,    62,     0,    63,    27,
       0,     0,     0,   152,     0,     0,     0,    65,    66,     0,
       0,     0,     0,     0,     0,    67,     0,     0,     0,     0,
       0,     0,     0,    65,    66,     0,     0,   107,   108,     0,
       0,    67,     0,     0,    68,    69,    27,   109,   110,   111,
     112,   113,   114,   165,    27,     0,     0,     0,     0,     0,
      68,    69,    27,     0,     0,     0,     0,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177
};

static const yytype_int16 yycheck[] =
{
       0,     0,    16,    48,    47,    36,    48,     7,     8,     9,
       1,    21,     4,     4,    13,   103,    16,    16,    18,    29,
      52,    13,    13,    15,    15,    21,    26,    26,   150,    12,
      30,    30,    47,    29,    78,     7,    36,    47,    12,    49,
       6,     7,     5,    53,    26,    89,    18,   103,    30,    15,
      13,    47,    96,    49,    23,    24,    25,    53,   103,    37,
     103,   103,    62,    63,    74,    75,    49,    47,    34,    47,
     102,   103,    82,    87,    89,    49,    45,    38,    74,    75,
      47,    42,    43,    44,    79,    46,    82,    87,    87,   120,
     212,   101,   102,   103,    50,    48,     0,    97,    51,    55,
     103,    93,    93,   103,    48,   101,   102,   103,    51,    47,
     232,    55,    48,    56,   106,   106,    47,    34,   162,    55,
     120,    49,    48,   115,   115,    97,   126,    49,    56,    55,
     144,    51,    48,    53,    56,    51,   128,   128,    89,    21,
      48,   185,    53,    51,   144,   144,   103,    29,   179,    80,
      81,   151,   152,    51,    51,    53,    53,   188,    49,    90,
      91,    92,    93,    94,    95,    47,    51,    49,    53,    51,
      53,    51,    55,    53,    52,   219,   190,    53,   178,   179,
      53,    50,    55,   197,   228,    53,   186,   187,   188,    53,
     190,   190,    74,    75,   238,    38,    39,   197,   197,    56,
      82,   245,   194,   194,   103,   249,   178,    47,   103,   201,
     201,    34,    47,   205,   205,   187,   260,   103,   262,   101,
     102,   103,    11,   215,   215,   239,    53,    57,    58,    59,
      60,    61,    48,    47,    50,   235,   236,    13,    48,   239,
     239,    90,   234,   234,    53,    51,   246,   103,    52,     3,
      80,    81,     6,     7,     8,    85,    53,    53,   258,   259,
      14,    15,    16,    48,    18,   257,   257,   103,    22,    23,
      24,    25,    26,    27,    86,    53,    30,    48,    32,   151,
      34,    35,    36,    46,    38,   119,   209,    49,    42,    43,
      44,    45,    46,   145,     3,    49,    50,     6,     7,     8,
      -1,    -1,    -1,    -1,    21,    14,    15,    16,    -1,    18,
      -1,    -1,    29,    22,    23,    24,    25,    26,    27,    -1,
      21,    30,    -1,    32,    -1,    34,    35,    36,    29,    38,
      47,    48,    49,    42,    43,    44,    45,    46,    -1,    -1,
      49,    -1,    -1,    -1,    47,    -1,    47,    -1,    49,   103,
      -1,    -1,    -1,    56,    -1,    -1,    -1,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    75,    -1,    -1,    80,    81,    -1,
      -1,    82,    -1,    -1,   101,   102,   103,    90,    91,    92,
      93,    94,    95,    48,   103,    -1,    -1,    -1,    -1,    -1,
     101,   102,   103,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,     8,    14,    15,    16,    18,    22,
      23,    24,    25,    26,    27,    30,    32,    34,    35,    36,
      38,    42,    43,    44,    45,    46,    49,   103,   106,   107,
     108,   109,   110,   111,   112,   115,   117,   119,   124,   125,
     127,   129,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   141,   144,   145,   149,   152,   153,   156,   157,   158,
      21,    29,    47,    49,    53,    74,    75,    82,   101,   102,
     115,   122,   123,   127,   130,   131,   143,   146,   103,    53,
     122,    37,    47,    38,    39,   126,   115,   143,   115,   115,
      51,   122,   127,    47,   122,   109,   143,    47,    50,   107,
     113,   114,   115,    79,     0,   107,    47,    80,    81,    90,
      91,    92,    93,    94,    95,   140,   113,   115,     6,    15,
     117,   136,   137,   136,   115,   103,    51,    53,    89,    12,
     111,    53,    47,    34,   103,   109,    53,   111,    52,    53,
      53,   122,    53,     5,    13,   154,   155,   111,   143,    50,
      50,    55,    56,   116,   115,    48,   121,   122,    53,    53,
     122,    53,   103,   126,   113,    48,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,   148,    47,
      52,   102,   115,   147,   122,   103,    34,   103,    47,   128,
      11,   142,    53,    48,    47,   109,   155,    48,   116,   114,
     115,    90,   118,    53,    48,    55,    53,    12,   111,   103,
      53,   143,    48,   113,    52,    56,   111,   115,   143,    48,
     113,   109,    53,   122,   109,   122,    53,   122,   103,   128,
      48,   116,    48,   122,    86,    53,    56,   111,    48,    48,
     111,   116,   122,   115,   150,   115,    56,   111,   109,    48,
      57,    58,    59,    60,    61,    80,    81,    85,   120,   151,
      48,   111,   115,   111,   122,   115,   115,   111,   111
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
      

/* Line 1455 of yacc.c  */
#line 1761 "yyparse.tab.c"
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



