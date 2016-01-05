/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "JSint.y"

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "ast.h"
#include "utils.h"
#include "parser.hpp"
#include "ccalc.h"
using namespace std;

int yydebug = 1;
ast::Node* ast_root;

/* Line 371 of yacc.c  */
#line 84 "parser.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DECIMAL_LITERAL = 258,
     HEX_INTEGER_LITERAL = 259,
     STRING_LITERAL = 260,
     BOOLEAN_LITERAL = 261,
     NULL_LITERAL = 262,
     SLASHASSIGN = 263,
     SLASH = 264,
     JEOF = 265,
     IDENTIFIER_NAME = 266,
     ASS = 267
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 16 "JSint.y"

	char* 					debug;

    ast::Node* 				ast_Node;
    ast::Statement* 		ast_Statement;
    ast::Expression* 		ast_Expression;
    ast::Program* 			ast_Program;
    ast::Routine* 			ast_Routine;
    ast::TypeDecl* 			ast_TypeDecl;
    ast::VarDecl* 			ast_VarDecl;
    ast::Identifier* 		ast_Identifier;
    ast::AssignmentStmt* 	ast_AssignmentStmt;
    ast::ConstDecl*         ast_ConstDecl;
    ast::ConstValue*        ast_ConstValue;
    ast::RecordType*        ast_RecordType;
    ast::TypeConst*         ast_TypeConst;

    ast::StatementList* 	ast_StatementList;
    ast::VarDeclList* 		ast_VarDeclList;
    ast::IdentifierList* 	ast_IdentifierList;
    ast::RoutineList* 		ast_RoutineList;
    ast::NameList* 			ast_NameList;
    ast::ExpressionList* 	ast_ExpressionList;
    ast::ConstDeclList*     ast_ConstDeclList;
    ast::FieldDeclList*     ast_FieldDeclList;
    ast::TypeDeclList*      ast_TypeDeclList;
    ast::CaseList*          ast_CaseList;
    ast::CaseStmt*          ast_CaseStmt;


/* Line 387 of yacc.c  */
#line 170 "parser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 198 "parser.cpp"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  169
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1072

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  129
/* YYNRULES -- Number of rules.  */
#define YYNRULES  278
/* YYNRULES -- Number of states.  */
#define YYNSTATES  432

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   341

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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    11,    13,    15,    17,    19,
      21,    23,    25,    27,    29,    33,    38,    42,    45,    49,
      52,    56,    57,    59,    62,    66,    69,    72,    75,    79,
      80,    84,    86,    88,    90,    92,    94,    97,   100,   104,
     108,   109,   112,   113,   117,   120,   124,   128,   131,   132,
     134,   138,   141,   145,   148,   151,   155,   156,   158,   160,
     162,   164,   166,   169,   171,   173,   175,   177,   180,   184,
     186,   188,   190,   192,   194,   196,   198,   200,   202,   205,
     209,   210,   212,   214,   216,   219,   223,   224,   226,   228,
     231,   235,   236,   238,   240,   242,   245,   249,   250,   252,
     254,   256,   258,   260,   262,   265,   269,   270,   272,   274,
     276,   278,   280,   283,   287,   288,   291,   295,   296,   298,
     300,   302,   304,   307,   311,   312,   315,   319,   320,   322,
     325,   329,   330,   333,   337,   338,   340,   343,   347,   348,
     351,   355,   356,   358,   361,   365,   366,   369,   373,   374,
     376,   379,   383,   384,   387,   391,   392,   394,   396,   402,
     404,   410,   414,   416,   420,   422,   424,   426,   428,   430,
     432,   434,   436,   438,   440,   442,   444,   446,   449,   453,
     454,   457,   461,   462,   463,   465,   467,   469,   471,   473,
     475,   477,   479,   481,   483,   485,   487,   489,   491,   493,
     495,   497,   499,   503,   505,   508,   511,   515,   517,   521,
     523,   526,   528,   531,   534,   537,   539,   541,   544,   550,
     558,   565,   573,   579,   588,   598,   609,   618,   626,   627,
     629,   631,   634,   637,   640,   643,   647,   653,   659,   661,
     664,   666,   669,   673,   678,   682,   685,   689,   693,   695,
     697,   700,   706,   709,   711,   715,   720,   724,   729,   731,
     735,   737,   741,   743,   746,   748,   750,   753,   755,   757,
     761,   767,   769,   773,   776,   780,   782,   786,   790
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     208,     0,    -1,    13,    -1,    95,    -1,    14,   170,    15,
      -1,    90,    -1,    91,    -1,    89,    -1,     3,    -1,     4,
      -1,     5,    -1,     6,    -1,     7,    -1,    11,    -1,    16,
      94,    17,    -1,    16,    92,    94,    17,    -1,    16,    92,
      17,    -1,    16,    17,    -1,    94,   167,    93,    -1,   167,
      93,    -1,    93,    94,   167,    -1,    -1,    18,    -1,    94,
      18,    -1,    19,    96,    20,    -1,    19,    20,    -1,    98,
      97,    -1,    97,    18,    -1,    97,    18,    98,    -1,    -1,
      99,    21,   167,    -1,    90,    -1,     5,    -1,     3,    -1,
     101,    -1,   102,    -1,   205,   104,    -1,    88,   104,    -1,
      22,   100,   103,    -1,   103,   110,   104,    -1,    -1,   104,
     105,    -1,    -1,    16,   170,    17,    -1,    23,    90,    -1,
     100,   110,   108,    -1,   101,   110,   108,    -1,   108,   109,
      -1,    -1,   110,    -1,    16,   170,    17,    -1,    23,    90,
      -1,    14,   111,    15,    -1,    14,    15,    -1,   167,   112,
      -1,   112,    18,   167,    -1,    -1,   106,    -1,   100,    -1,
     107,    -1,   101,    -1,   113,    -1,   113,   116,    -1,    24,
      -1,    25,    -1,   115,    -1,   118,    -1,   119,   117,    -1,
     118,   119,   117,    -1,    26,    -1,    27,    -1,    28,    -1,
      24,    -1,    25,    -1,    29,    -1,    30,    -1,    31,    -1,
      32,    -1,   117,   121,    -1,   121,   122,   117,    -1,    -1,
      33,    -1,     9,    -1,    34,    -1,   120,   124,    -1,   124,
     125,   120,    -1,    -1,    29,    -1,    30,    -1,   123,   127,
      -1,   127,   128,   123,    -1,    -1,    35,    -1,    36,    -1,
      37,    -1,   126,   130,    -1,   130,   131,   126,    -1,    -1,
      38,    -1,    39,    -1,    40,    -1,    41,    -1,    42,    -1,
      43,    -1,   126,   133,    -1,   133,   134,   126,    -1,    -1,
      38,    -1,    39,    -1,    40,    -1,    41,    -1,    42,    -1,
     129,   136,    -1,   136,   139,   129,    -1,    -1,   132,   138,
      -1,   138,   139,   132,    -1,    -1,    44,    -1,    45,    -1,
      46,    -1,    47,    -1,   135,   141,    -1,   141,   144,   135,
      -1,    -1,   137,   143,    -1,   143,   144,   137,    -1,    -1,
      48,    -1,   140,   146,    -1,   146,   149,   140,    -1,    -1,
     142,   148,    -1,   148,   149,   142,    -1,    -1,    49,    -1,
     145,   151,    -1,   151,   154,   145,    -1,    -1,   147,   153,
      -1,   153,   154,   147,    -1,    -1,    50,    -1,   150,   156,
      -1,   156,   159,   150,    -1,    -1,   152,   158,    -1,   158,
     159,   152,    -1,    -1,    51,    -1,   155,   161,    -1,   161,
     164,   155,    -1,    -1,   157,   163,    -1,   163,   164,   157,
      -1,    -1,    52,    -1,   160,    -1,   160,    53,   167,    21,
     167,    -1,   162,    -1,   162,    53,   167,    21,   168,    -1,
     113,   169,   167,    -1,   165,    -1,   113,   169,   168,    -1,
     166,    -1,    12,    -1,    54,    -1,     8,    -1,    55,    -1,
      56,    -1,    57,    -1,    58,    -1,    59,    -1,    60,    -1,
      61,    -1,    62,    -1,    63,    -1,   167,   171,    -1,   171,
      18,   167,    -1,    -1,   168,   173,    -1,   173,    18,   168,
      -1,    -1,    -1,   170,    -1,   176,    -1,   213,    -1,   178,
      -1,   184,    -1,   197,    -1,   185,    -1,   186,    -1,   187,
      -1,   189,    -1,   190,    -1,   211,    -1,   191,    -1,   192,
      -1,   193,    -1,   198,    -1,   199,    -1,    64,    -1,    19,
     177,    20,    -1,   175,    -1,   175,   177,    -1,    65,   179,
      -1,    65,   179,    66,    -1,   180,    -1,   179,    18,   180,
      -1,    90,    -1,    90,   182,    -1,    90,    -1,    90,   183,
      -1,    67,   167,    -1,    67,   168,    -1,    66,    -1,   170,
      -1,   170,    66,    -1,    68,    14,   170,    15,   175,    -1,
      68,    14,   170,    15,   175,    69,   175,    -1,    70,   175,
      71,    14,   170,    15,    -1,    70,   175,    71,    14,   170,
      15,    66,    -1,    71,    14,   170,    15,   175,    -1,    72,
      14,    66,   174,    66,   174,    15,   175,    -1,    72,    14,
     172,    66,   174,    66,   174,    15,   175,    -1,    72,    14,
      65,   179,    66,   174,    66,   174,    15,   175,    -1,    72,
      14,    65,   181,    43,   170,    15,   175,    -1,    72,    14,
     114,    43,   170,    15,   175,    -1,    -1,    90,    -1,    66,
      -1,    90,    66,    -1,    73,   188,    -1,    74,   188,    -1,
      75,   174,    -1,    75,   174,    66,    -1,    76,    14,   170,
      15,   175,    -1,    77,    14,   170,    15,   194,    -1,    19,
      -1,    19,   195,    -1,   196,    -1,   195,   196,    -1,    78,
     170,    21,    -1,    78,   170,    21,   177,    -1,    90,    21,
     175,    -1,    80,   170,    -1,    80,   170,    66,    -1,    81,
     176,   200,    -1,   202,    -1,   201,    -1,   201,   202,    -1,
      82,    14,    90,    15,   176,    -1,    83,   176,    -1,    84,
      -1,    14,   206,    15,    -1,    85,    90,   203,   207,    -1,
      85,   203,   207,    -1,    85,    90,   203,   207,    -1,    90,
      -1,   206,    18,    90,    -1,    64,    -1,    19,   209,    20,
      -1,    10,    -1,   209,    10,    -1,   209,    -1,   210,    -1,
     209,   210,    -1,   204,    -1,   175,    -1,    86,   212,    66,
      -1,    86,   212,    23,    33,    66,    -1,    11,    -1,   212,
      23,    11,    -1,    65,   214,    -1,    65,   214,    66,    -1,
     215,    -1,   214,    18,   215,    -1,    90,    21,    11,    -1,
      90,    21,    11,   182,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   106,   106,   107,   108,   109,   110,   111,   112,   112,
     112,   112,   112,   113,   114,   115,   116,   117,   121,   122,
     123,   124,   125,   126,   127,   128,   132,   133,   134,   135,
     137,   138,   139,   140,   141,   142,   143,   144,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   298,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   321,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     358,   359,   360,   361,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DECIMAL_LITERAL", "HEX_INTEGER_LITERAL",
  "STRING_LITERAL", "BOOLEAN_LITERAL", "NULL_LITERAL", "SLASHASSIGN",
  "SLASH", "JEOF", "IDENTIFIER_NAME", "ASS", "\"this\"", "\"(\"", "\")\"",
  "\"[\"", "\"]\"", "\",\"", "\"{\"", "\"}\"", "\":\"", "\"new\"", "\".\"",
  "\"++\"", "\"--\"", "\"delete\"", "\"void\"", "\"typeof\"", "\"+\"",
  "\"-\"", "\"~\"", "\"!\"", "\"*\"", "\"%\"", "\"<<\"", "\">>\"",
  "\">>>\"", "\"<\"", "\">\"", "\"<=\"", "\">=\"", "\"instanceof\"",
  "\"in\"", "\"==\"", "\"!=\"", "\"===\"", "\"!==\"", "\"&\"", "\"^\"",
  "\"|\"", "\"&&\"", "\"||\"", "\"?\"", "\"*=\"", "\"%=\"", "\"+=\"",
  "\"-=\"", "\"<<=\"", "\">>=\"", "\">>>=\"", "\"&=\"", "\"^=\"", "\"|=\"",
  "\"{}\"", "\"var\"", "\";\"", "\"=\"", "\"if\"", "\"else\"", "\"do\"",
  "\"while\"", "\"for\"", "\"continue\"", "\"break\"", "\"return\"",
  "\"with\"", "\"switch\"", "\"case\"", "\"default\"", "\"throw\"",
  "\"try\"", "\"catch\"", "\"finally\"", "\"()\"", "\"function\"",
  "\"import\"", "$accept", "PrimaryExpression", "Literal", "Identifier",
  "ArrayLiteral", "ElementList", "ElementListPart", "Elision",
  "ObjectLiteral", "PropertyNameAndValueList",
  "PropertyNameAndValueListPart", "PropertyNameAndValue", "PropertyName",
  "MemberExpression", "MemberExpressionForIn", "AllocationExpression",
  "AllocationExpressionBody", "MemberExpressionParts",
  "MemberExpressionPart", "CallExpression", "CallExpressionForIn",
  "CallExpressionParts", "CallExpressionPart", "Arguments", "ArgumentList",
  "ElAssignmentExpressions", "LeftHandSideExpression",
  "LeftHandSideExpressionForIn", "PostfixExpression", "PostfixOperator",
  "UnaryExpression", "UnaryExpressionPart", "UnaryOperator",
  "MultiplicativeExpression", "MultiplicativeExpressionPart",
  "MultiplicativeOperator", "AdditiveExpression", "AdditiveExpressionPart",
  "AdditiveOperator", "ShiftExpression", "ShiftExpressionPart",
  "ShiftOperator", "RelationalExpression", "RelationalExpressionPart",
  "RelationalOperator", "RelationalExpressionNoIn",
  "RelationalExpressionNoInPart", "RelationalNoInOperator",
  "EqualityExpression", "EqualityExpressionPart", "EqualityExpressionNoIn",
  "EqualityExpressionNoInPart", "EqualityOperator", "BitwiseANDExpression",
  "BitwiseANDExpressionPart", "BitwiseANDExpressionNoIn",
  "BitwiseANDExpressionNoInPart", "BitwiseANDOperator",
  "BitwiseXORExpression", "BitwiseXORExpressionPart",
  "BitwiseXORExpressionNoIn", "BitwiseXORExpressionNoInPart",
  "BitwiseXOROperator", "BitwiseORExpression", "BitwiseORExpressionPart",
  "BitwiseORExpressionNoIn", "BitwiseORExpressionNoInPart",
  "BitwiseOROperator", "LogicalANDExpression", "LogicalANDExpressionPart",
  "LogicalANDExpressionNoIn", "LogicalANDExpressionNoInPart",
  "LogicalANDOperator", "LogicalORExpression", "LogicalORExpressionPart",
  "LogicalORExpressionNoIn", "LogicalORExpressionNoInPart",
  "LogicalOROperator", "ConditionalExpression",
  "ConditionalExpressionNoIn", "AssignmentExpression",
  "AssignmentExpressionNoIn", "AssignmentOperator", "Expression",
  "ExpressionPart", "ExpressionNoIn", "ExpressionNoInPart",
  "ExpressionOrNull", "Statement", "Block", "StatementList",
  "VariableStatement", "VariableDeclarationList", "VariableDeclaration",
  "VariableDeclarationNoIn", "Initialiser", "InitialiserNoIn",
  "EmptyStatement", "ExpressionStatement", "IfStatement",
  "IterationStatement", "IdentifierComma", "ContinueStatement",
  "BreakStatement", "ReturnStatement", "WithStatement", "SwitchStatement",
  "CaseBlock", "CaseClauses", "CaseClause", "LabelledStatement",
  "ThrowStatement", "TryStatement", "TryStatementPart", "Catch", "Finally",
  "FormalParameterListInPare", "FunctionDeclaration", "FunctionExpression",
  "FormalParameterList", "FunctionBody", "Program", "SourceElements",
  "SourceElement", "ImportStatement", "Name", "JScriptVarStatement",
  "JScriptVarDeclarationList", "JScriptVarDeclaration", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    88,    88,    88,    88,    88,    89,    89,
      89,    89,    89,    90,    91,    91,    91,    91,    92,    92,
      93,    93,    94,    94,    95,    95,    96,    97,    97,    97,
      98,    99,    99,    99,   100,   100,   101,   101,   102,   103,
     103,   104,   104,   105,   105,   106,   107,   108,   108,   109,
     109,   109,   110,   110,   111,   112,   112,   113,   113,   114,
     114,   115,   115,   116,   116,   117,   117,   118,   118,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   120,   121,
     121,   122,   122,   122,   123,   124,   124,   125,   125,   126,
     127,   127,   128,   128,   128,   129,   130,   130,   131,   131,
     131,   131,   131,   131,   132,   133,   133,   134,   134,   134,
     134,   134,   135,   136,   136,   137,   138,   138,   139,   139,
     139,   139,   140,   141,   141,   142,   143,   143,   144,   145,
     146,   146,   147,   148,   148,   149,   150,   151,   151,   152,
     153,   153,   154,   155,   156,   156,   157,   158,   158,   159,
     160,   161,   161,   162,   163,   163,   164,   165,   165,   166,
     166,   167,   167,   168,   168,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   170,   171,   171,
     172,   173,   173,   174,   174,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   176,   176,   177,   177,   178,   178,   179,   179,   180,
     180,   181,   181,   182,   183,   184,   185,   185,   186,   186,
     187,   187,   187,   187,   187,   187,   187,   187,   188,   188,
     188,   188,   189,   190,   191,   191,   192,   193,   194,   194,
     195,   195,   196,   196,   197,   198,   198,   199,   200,   200,
     200,   201,   202,   203,   203,   204,   205,   205,   206,   206,
     207,   207,   208,   208,   208,   209,   209,   210,   210,   211,
     211,   212,   212,   213,   213,   214,   214,   215,   215
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     3,     2,     3,     2,
       3,     0,     1,     2,     3,     2,     2,     2,     3,     0,
       3,     1,     1,     1,     1,     1,     2,     2,     3,     3,
       0,     2,     0,     3,     2,     3,     3,     2,     0,     1,
       3,     2,     3,     2,     2,     3,     0,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       0,     1,     1,     1,     2,     3,     0,     1,     1,     2,
       3,     0,     1,     1,     1,     2,     3,     0,     1,     1,
       1,     1,     1,     1,     2,     3,     0,     1,     1,     1,
       1,     1,     2,     3,     0,     2,     3,     0,     1,     1,
       1,     1,     2,     3,     0,     2,     3,     0,     1,     2,
       3,     0,     2,     3,     0,     1,     2,     3,     0,     2,
       3,     0,     1,     2,     3,     0,     2,     3,     0,     1,
       2,     3,     0,     2,     3,     0,     1,     1,     5,     1,
       5,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     0,
       2,     3,     0,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     2,     3,     1,     3,     1,
       2,     1,     2,     2,     2,     1,     1,     2,     5,     7,
       6,     7,     5,     8,     9,    10,     8,     7,     0,     1,
       1,     2,     2,     2,     2,     3,     5,     5,     1,     2,
       1,     2,     3,     4,     3,     2,     3,     3,     1,     1,
       2,     5,     2,     1,     3,     4,     3,     4,     1,     3,
       1,     3,     1,     2,     1,     1,     2,     1,     1,     3,
       5,     1,     3,     2,     3,     1,     3,     3,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     8,     9,    10,    11,    12,   262,    13,     2,     0,
       0,     0,     0,    72,    73,    69,    70,    71,    74,    75,
      76,    77,   201,     0,   215,     0,     0,     0,     0,   228,
     228,   183,     0,     0,     0,     0,     0,     0,    42,     7,
       5,     6,     3,    58,    34,    35,    57,    61,    65,    80,
      66,     0,    86,    91,    97,   114,   124,   131,   138,   145,
     152,   157,   162,   179,   216,   268,   185,   187,   188,   190,
     191,   192,   193,   194,   196,   197,   198,   189,   199,   200,
     267,    42,     0,   264,   265,   195,   186,     0,     0,     5,
       0,    17,    22,     0,     0,    21,     8,    10,    25,     5,
       0,    29,     0,   203,     0,    40,   209,   205,   207,   273,
     275,     0,     0,     0,     0,   230,   229,   232,   233,   184,
     234,     0,     0,   245,     0,     0,     0,   253,     0,     0,
     271,     0,    37,     0,     0,    48,   167,   165,    63,    64,
     166,   168,   169,   170,   171,   172,   173,   174,   175,   176,
      62,     0,    78,     0,    61,    67,    84,    89,    95,   112,
     122,   129,   136,   143,   150,     0,   177,   217,    36,     1,
     263,   266,    33,    32,    31,     0,     4,    16,     0,    14,
      23,    21,    19,    24,    26,     0,   204,   202,    38,     0,
       0,   210,     0,   206,     0,   274,     0,     0,     0,     0,
     183,    34,    59,    61,     0,   106,   117,   127,   134,   141,
     148,   155,   159,   164,   182,     0,   231,   235,     0,     0,
     246,     0,     0,   247,   249,   248,   258,     0,     0,     0,
     260,   256,     0,   269,     0,     0,    41,   244,    53,     0,
      56,    45,   161,    82,    81,    83,     0,    68,    87,    88,
       0,    92,    93,    94,     0,    98,    99,   100,   101,   102,
     103,     0,   118,   119,   120,   121,     0,   128,     0,   135,
       0,   142,     0,   149,     0,   156,     0,     0,     0,     0,
      15,    18,     0,    27,    30,    42,   277,   213,   209,   208,
       0,   276,     0,     0,     0,   209,     0,     0,     0,    48,
       0,     0,   104,   115,   125,   132,   139,   146,   153,     0,
     180,   183,     0,     0,     0,   252,   250,   254,     0,   255,
       0,   272,     0,     0,    44,    52,    54,     0,     0,    47,
      49,    79,    85,    90,    96,   113,   123,   130,   137,   144,
     151,     0,   178,   257,    20,    28,    39,   278,   218,     0,
     222,     0,   212,   183,     0,   183,    46,   163,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,   238,   237,     0,   259,   261,
     270,    43,     0,     0,    51,   158,     0,   220,    61,    97,
     214,     0,     0,     0,     0,   105,   116,   126,   133,   140,
     147,   154,     0,   181,   183,     0,   239,   240,     0,    55,
      50,   219,   221,     0,   183,     0,     0,   227,   160,     0,
       0,   241,   251,     0,   226,   223,     0,   242,     0,   224,
     243,   225
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    38,    39,    89,    41,    93,   182,   282,    42,   100,
     184,   101,   102,    43,    44,    45,   188,   132,   236,    46,
     202,   241,   329,   330,   239,   326,    47,   204,    48,   150,
      49,    50,    51,    52,   152,   246,    53,   156,   250,    54,
     157,   254,    55,   158,   261,   206,   302,   364,    56,   159,
     207,   303,   266,    57,   160,   208,   304,   268,    58,   161,
     209,   305,   270,    59,   162,   210,   306,   272,    60,   163,
     211,   307,   274,    61,   164,   212,   308,   276,    62,   213,
      63,   357,   151,    64,   166,   215,   310,   120,    65,    66,
     104,    67,   107,   108,   297,   191,   352,    68,    69,    70,
      71,   117,    72,    73,    74,    75,    76,   376,   406,   407,
      77,    78,    79,   223,   224,   225,   129,    80,    81,   227,
     231,    82,    83,    84,    85,   131,    86,   109,   110
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -212
static const yytype_int16 yypact[] =
{
     458,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,   956,
      47,   542,   202,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,    20,  -212,    30,   686,    33,    41,     4,
       4,   956,    92,   126,   956,    26,     5,    87,  -212,  -212,
      -7,  -212,  -212,   144,  -212,  -212,  -212,   442,  -212,  -212,
     482,   956,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,    42,  -212,  -212,    36,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,   116,   572,  -212,  -212,  -212,    89,     5,  -212,
     145,  -212,  -212,    23,   800,  -212,   141,   142,  -212,    -7,
     146,  -212,   143,   686,   147,  -212,    17,    14,  -212,    15,
    -212,   956,    94,   956,   862,  -212,   103,  -212,  -212,  -212,
     106,   956,   956,   107,   686,    32,    20,  -212,     7,    29,
    -212,     1,    88,   686,   892,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,   956,     9,   956,   113,  -212,   123,    99,   105,    84,
     120,   122,   124,   127,   125,   956,   157,  -212,    88,  -212,
    -212,  -212,  -212,  -212,  -212,     7,  -212,  -212,   137,  -212,
    -212,  -212,   161,  -212,   162,   956,  -212,  -212,   144,   171,
     956,  -212,    20,  -212,    20,  -212,   168,   170,   172,    20,
     956,    13,  -212,   442,   148,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,   132,  -212,  -212,   130,  -212,  -212,   173,   175,
    -212,   183,    26,  -212,   115,  -212,  -212,    10,    29,   770,
    -212,  -212,    24,  -212,   956,    20,  -212,  -212,  -212,   185,
    -212,    85,  -212,  -212,  -212,  -212,   956,  -212,  -212,  -212,
     956,  -212,  -212,  -212,   956,  -212,  -212,  -212,  -212,  -212,
    -212,   956,  -212,  -212,  -212,  -212,   956,  -212,   956,  -212,
     956,  -212,   956,  -212,   956,  -212,   956,   165,   956,    29,
    -212,   161,   926,   102,  -212,  -212,   134,  -212,   134,  -212,
     181,  -212,   686,   956,   686,   -21,    16,   169,   138,  -212,
     956,   956,    81,    84,   120,   122,   124,   127,   125,   956,
     196,   956,   686,   198,    20,  -212,  -212,  -212,    20,  1009,
     656,  -212,   153,   205,  -212,  -212,   207,   956,    20,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,   956,  -212,  -212,  -212,  -212,    88,  -212,   154,   211,
    -212,   956,  -212,   956,   956,   956,    85,  -212,   212,  -212,
    -212,  -212,  -212,  -212,   956,   956,   956,   956,   956,   956,
     956,   209,   956,   166,  -212,   155,  -212,   216,  -212,  -212,
    -212,  -212,   956,   217,  -212,  -212,   686,   174,   442,  -212,
    -212,   176,   221,   222,   686,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,   956,  -212,   956,   956,   155,  -212,    26,  -212,
    -212,  -212,  -212,   956,   956,   686,   686,  -212,  -212,   223,
     218,  -212,  -212,   228,  -212,  -212,   686,   686,   686,  -212,
    -212,  -212
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -212,  -212,  -212,     0,  -212,  -212,    64,     3,  -212,  -212,
    -212,   -36,  -212,   237,   136,  -212,  -212,   -74,  -212,  -212,
    -212,   -48,  -212,   -31,  -212,  -212,    -2,  -212,  -212,  -212,
     -43,  -212,   203,     6,  -212,  -212,    11,  -212,  -212,    79,
    -212,  -212,   -12,  -212,  -212,  -110,  -212,  -212,   -11,  -212,
    -108,  -212,   -42,   -10,  -212,  -104,  -212,   -29,    -1,  -212,
     -92,  -212,   -28,     8,  -212,   -91,  -212,   -27,    19,  -212,
     -90,  -212,   -26,  -212,  -212,  -212,  -212,   -24,  -212,  -212,
      -9,  -105,  -193,    28,  -212,  -212,  -212,  -194,    -6,   -33,
    -100,  -212,    86,    97,  -212,    18,  -212,  -212,  -212,  -212,
    -212,   260,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -115,
    -212,  -212,  -212,  -212,  -212,    69,   -89,  -212,  -212,  -212,
    -211,  -212,    67,   -79,  -212,  -212,  -212,  -212,   108
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -258
static const yytype_int16 yytable[] =
{
      40,    95,   125,   186,   171,   103,   298,   168,   155,   214,
     300,    99,   135,    94,   133,     7,     7,   319,   243,   126,
     112,   126,  -211,   106,   232,   317,    40,   134,   318,   116,
     116,     7,   192,   194,   192,   321,   128,    90,   189,   228,
     177,    92,   244,   245,   111,   124,   351,   113,   229,   154,
       1,     2,     3,     4,     5,   114,   -60,   322,     7,   119,
       8,     9,   123,    10,    91,    92,    87,   233,   343,    12,
     115,    13,    14,    15,    16,    17,    18,    19,    20,    21,
     193,   195,   353,    40,   190,   181,   279,   174,   175,   127,
      22,   127,   172,   230,   173,   165,   178,   103,   130,   134,
       7,   327,   167,    40,   234,   172,   121,   173,   328,    98,
     247,   235,   203,     7,   221,   222,   169,   373,   103,   359,
     360,   361,   362,   363,    40,   240,   226,   237,   262,   263,
     264,   265,    88,    40,   251,   252,   253,   138,   139,   196,
     122,   198,   242,   255,   256,   257,   258,   259,   260,   218,
     219,   154,   248,   249,   280,   180,   277,   285,   134,   391,
     176,   393,   -33,   -32,   185,   197,   183,   187,   267,   216,
     299,   269,   217,   220,   271,   278,   284,   275,   273,    92,
     283,   287,   286,   292,   293,   309,   341,   294,   312,   315,
     313,   301,   288,   205,   290,   413,   311,   314,   222,   295,
     325,   190,   189,   331,   355,     1,     2,     3,     4,     5,
     419,   346,   354,     7,   372,     8,     9,   375,    10,   380,
     423,    87,   381,   386,    12,   382,   387,   394,   119,    40,
     402,   408,   404,   405,   410,   324,   415,   416,   426,   427,
     412,   171,   414,   428,   154,   281,   390,   345,   154,   105,
     201,   356,   154,   153,   335,   396,   332,   336,   397,   154,
     337,   365,   323,   398,   154,   333,   154,   403,   154,   342,
     154,   338,   154,   344,   154,   366,   399,   367,   400,   368,
     401,   369,   339,   174,   370,   296,   348,    88,   350,   289,
     118,   421,    40,   316,    40,   340,   320,   418,   203,     0,
     371,     0,   291,     0,   347,     0,   374,     0,     0,     0,
       0,     0,    40,     0,   377,     0,     0,     0,   378,     0,
      40,   349,     0,     0,     0,     0,     0,   430,   384,   358,
       0,     0,   385,     0,     0,     0,     0,     0,     0,   119,
     334,     0,   287,     0,     0,     0,     0,     0,     0,   388,
       0,     0,     0,     0,     0,   383,     0,     0,     0,     0,
       0,     0,   154,   154,   154,   154,   154,   154,   154,     0,
     203,     0,     0,   409,     0,   422,     0,     0,     0,   205,
     411,   119,   392,   119,     0,     0,    40,     0,   417,     0,
       0,     0,     0,     0,    40,     0,     0,     0,     0,     0,
     203,     0,     0,     0,   242,     0,     0,     0,     0,   424,
     425,   388,     0,     0,     0,    40,    40,     0,     0,     0,
     429,   103,   431,     0,     0,     0,    40,    40,    40,     0,
     389,     0,   119,   420,     0,     0,     0,     0,     0,     0,
       0,     0,   119,   395,   205,   205,   205,   205,   205,   205,
     136,   205,     0,     0,   137,     0,     0,     0,     0,     0,
       0,     1,     2,     3,     4,     5,   138,   139,     6,     7,
       0,     8,     9,     0,    10,     0,     0,    11,     0,     0,
      12,   205,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,   389,     0,     0,     0,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,    22,    23,    24,     0,    25,     0,    26,    27,
      28,    29,    30,    31,    32,    33,     0,     0,    34,    35,
       0,     0,     0,    36,    37,    96,     2,    97,     4,     5,
       0,     0,     0,     7,     0,     8,     9,     0,    10,     0,
       0,    11,    98,     0,    12,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     1,     2,     3,     4,     5,
       0,     0,   170,     7,     0,     8,     9,     0,    10,     0,
       0,    11,     0,     0,    12,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,    22,    23,    24,     0,
      25,     0,    26,    27,    28,    29,    30,    31,    32,    33,
       0,     0,    34,    35,     0,     0,     0,    88,    37,     0,
       0,     0,     0,     0,     0,     0,    22,    23,    24,     0,
      25,     0,    26,    27,    28,    29,    30,    31,    32,    33,
       0,     0,    34,    35,     0,     0,     0,    36,    37,     1,
       2,     3,     4,     5,     0,     0,     0,     7,     0,     8,
       9,     0,    10,     0,     0,    11,   379,     0,    12,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     1,
       2,     3,     4,     5,     0,     0,     0,     7,     0,     8,
       9,     0,    10,     0,     0,    11,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
      22,    23,    24,     0,    25,     0,    26,    27,    28,    29,
      30,    31,    32,    33,     0,     0,    34,    35,     0,     0,
       0,    36,    37,     0,     0,     0,     0,     0,     0,     0,
      22,    23,    24,     0,    25,     0,    26,    27,    28,    29,
      30,    31,    32,    33,     0,     0,    34,    35,     0,     0,
       0,    88,    37,     1,     2,     3,     4,     5,     0,     0,
       0,     7,     0,     8,     9,     0,    10,     0,     0,    11,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     1,     2,     3,     4,     5,     0,     0,
       0,     7,     0,     8,     9,     0,    10,   179,   180,    87,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,    22,    23,    24,     0,    25,     0,
      26,    27,    28,    29,    30,    31,    32,    33,     0,     0,
      34,    35,     0,     0,     0,    36,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     5,
       0,     0,     0,     7,     0,     8,     9,     0,    10,     0,
       0,    87,     0,     0,    12,    88,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     1,     2,     3,     4,     5,
       0,     0,     0,     7,     0,     8,     9,   238,    10,     0,
       0,    87,     0,     0,    12,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,     0,   199,   200,     1,
       2,     3,     4,     5,     0,     0,     0,     7,     0,     8,
       9,     0,    10,     0,   180,    87,     0,    88,    12,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     1,
       2,     3,     4,     5,     0,     0,     0,     7,     0,     8,
       9,     0,    10,     0,     0,    87,     0,    88,    12,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,     0,     0,     0,     0,     0,  -257,  -257,     0,
       0,  -257,     0,     0,     0,     0,     0,  -257,     0,     0,
       0,     0,  -257,     0,     0,     0,     0,     0,     0,     0,
       0,    88,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,
    -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,
    -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,
    -257,  -257,  -257
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-212)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    10,    35,   103,    83,    11,   200,    81,    51,   114,
     203,    11,    43,    10,    21,    11,    11,   228,     9,    14,
      26,    14,    43,    23,    23,    15,    26,    14,    18,    29,
      30,    11,    18,    18,    18,    11,    36,     9,    21,   128,
      17,    18,    33,    34,    14,    19,    67,    14,    19,    51,
       3,     4,     5,     6,     7,    14,    43,    33,    11,    31,
      13,    14,    34,    16,    17,    18,    19,    66,   279,    22,
      66,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      66,    66,    66,    83,    67,    94,   175,    87,    88,    84,
      64,    84,     3,    64,     5,    53,    93,   103,    11,    14,
      11,    16,    66,   103,    16,     3,    14,     5,    23,    20,
     153,    23,   114,    11,    82,    83,     0,   311,   124,    38,
      39,    40,    41,    42,   124,   134,   126,   133,    44,    45,
      46,    47,    85,   133,    35,    36,    37,    24,    25,   111,
      14,   113,   151,    38,    39,    40,    41,    42,    43,   121,
     122,   153,    29,    30,    17,    18,   165,   188,    14,   353,
      15,   355,    21,    21,    21,    71,    20,    20,    48,    66,
     201,    49,    66,    66,    50,    18,   185,    52,    51,    18,
      18,   190,    11,    15,    14,    53,    21,    15,    15,   222,
      15,    43,   192,   114,   194,   388,    66,    14,    83,   199,
      15,    67,    21,   246,    66,     3,     4,     5,     6,     7,
     404,   285,    43,    11,    18,    13,    14,    19,    16,    66,
     414,    19,    17,    69,    22,    18,    15,    15,   200,   229,
      21,    15,    66,    78,    17,   235,    15,    15,    15,    21,
      66,   320,    66,    15,   246,   181,   351,   283,   250,    12,
     114,   299,   254,    50,   266,   365,   250,   268,   366,   261,
     270,   303,   234,   367,   266,   254,   268,   372,   270,   278,
     272,   272,   274,   282,   276,   304,   368,   305,   369,   306,
     370,   307,   274,   283,   308,   199,   292,    85,   294,   192,
      30,   406,   292,   224,   294,   276,   229,   402,   300,    -1,
     309,    -1,   194,    -1,   286,    -1,   312,    -1,    -1,    -1,
      -1,    -1,   312,    -1,   314,    -1,    -1,    -1,   318,    -1,
     320,   293,    -1,    -1,    -1,    -1,    -1,   427,   328,   301,
      -1,    -1,   341,    -1,    -1,    -1,    -1,    -1,    -1,   311,
     261,    -1,   351,    -1,    -1,    -1,    -1,    -1,    -1,   351,
      -1,    -1,    -1,    -1,    -1,   327,    -1,    -1,    -1,    -1,
      -1,    -1,   364,   365,   366,   367,   368,   369,   370,    -1,
     372,    -1,    -1,   382,    -1,   408,    -1,    -1,    -1,   300,
     386,   353,   354,   355,    -1,    -1,   386,    -1,   394,    -1,
      -1,    -1,    -1,    -1,   394,    -1,    -1,    -1,    -1,    -1,
     402,    -1,    -1,    -1,   413,    -1,    -1,    -1,    -1,   415,
     416,   413,    -1,    -1,    -1,   415,   416,    -1,    -1,    -1,
     426,   427,   428,    -1,    -1,    -1,   426,   427,   428,    -1,
     351,    -1,   404,   405,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   414,   364,   365,   366,   367,   368,   369,   370,
       8,   372,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    24,    25,    10,    11,
      -1,    13,    14,    -1,    16,    -1,    -1,    19,    -1,    -1,
      22,   402,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,   413,    -1,    -1,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    68,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    80,    81,
      -1,    -1,    -1,    85,    86,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    11,    -1,    13,    14,    -1,    16,    -1,
      -1,    19,    20,    -1,    22,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,     3,     4,     5,     6,     7,
      -1,    -1,    10,    11,    -1,    13,    14,    -1,    16,    -1,
      -1,    19,    -1,    -1,    22,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    64,    65,    66,    -1,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    80,    81,    -1,    -1,    -1,    85,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,    -1,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    80,    81,    -1,    -1,    -1,    85,    86,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    11,    -1,    13,
      14,    -1,    16,    -1,    -1,    19,    20,    -1,    22,    -1,
      24,    25,    26,    27,    28,    29,    30,    31,    32,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    11,    -1,    13,
      14,    -1,    16,    -1,    -1,    19,    -1,    -1,    22,    -1,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      64,    65,    66,    -1,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    80,    81,    -1,    -1,
      -1,    85,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    65,    66,    -1,    68,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    80,    81,    -1,    -1,
      -1,    85,    86,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    11,    -1,    13,    14,    -1,    16,    -1,    -1,    19,
      -1,    -1,    22,    -1,    24,    25,    26,    27,    28,    29,
      30,    31,    32,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    11,    -1,    13,    14,    -1,    16,    17,    18,    19,
      -1,    -1,    22,    -1,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    64,    65,    66,    -1,    68,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      80,    81,    -1,    -1,    -1,    85,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    11,    -1,    13,    14,    -1,    16,    -1,
      -1,    19,    -1,    -1,    22,    85,    24,    25,    26,    27,
      28,    29,    30,    31,    32,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    11,    -1,    13,    14,    15,    16,    -1,
      -1,    19,    -1,    -1,    22,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    65,    66,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    11,    -1,    13,
      14,    -1,    16,    -1,    18,    19,    -1,    85,    22,    -1,
      24,    25,    26,    27,    28,    29,    30,    31,    32,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    11,    -1,    13,
      14,    -1,    16,    -1,    -1,    19,    -1,    85,    22,    -1,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    -1,    -1,     8,     9,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    10,    11,    13,    14,
      16,    19,    22,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    64,    65,    66,    68,    70,    71,    72,    73,
      74,    75,    76,    77,    80,    81,    85,    86,    88,    89,
      90,    91,    95,   100,   101,   102,   106,   113,   115,   117,
     118,   119,   120,   123,   126,   129,   135,   140,   145,   150,
     155,   160,   165,   167,   170,   175,   176,   178,   184,   185,
     186,   187,   189,   190,   191,   192,   193,   197,   198,   199,
     204,   205,   208,   209,   210,   211,   213,    19,    85,    90,
     170,    17,    18,    92,    94,   167,     3,     5,    20,    90,
      96,    98,    99,   175,   177,   100,    90,   179,   180,   214,
     215,    14,   175,    14,    14,    66,    90,   188,   188,   170,
     174,    14,    14,   170,    19,   176,    14,    84,    90,   203,
      11,   212,   104,    21,    14,   110,     8,    12,    24,    25,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
     116,   169,   121,   119,   113,   117,   124,   127,   130,   136,
     141,   146,   151,   156,   161,    53,   171,    66,   104,     0,
      10,   210,     3,     5,    90,    90,    15,    17,    94,    17,
      18,   167,    93,    20,    97,    21,   177,    20,   103,    21,
      67,   182,    18,    66,    18,    66,   170,    71,   170,    65,
      66,   101,   107,   113,   114,   126,   132,   137,   142,   147,
     152,   157,   162,   166,   168,   172,    66,    66,   170,   170,
      66,    82,    83,   200,   201,   202,    90,   206,   203,    19,
      64,   207,    23,    66,    16,    23,   105,   175,    15,   111,
     167,   108,   167,     9,    33,    34,   122,   117,    29,    30,
     125,    35,    36,    37,   128,    38,    39,    40,    41,    42,
      43,   131,    44,    45,    46,    47,   139,    48,   144,    49,
     149,    50,   154,    51,   159,    52,   164,   167,    18,   203,
      17,    93,    94,    18,   167,   110,    11,   167,    90,   180,
      90,   215,    15,    14,    15,    90,   179,   181,   174,   110,
     169,    43,   133,   138,   143,   148,   153,   158,   163,    53,
     173,    66,    15,    15,    14,   176,   202,    15,    18,   207,
     209,    11,    33,   170,    90,    15,   112,    16,    23,   109,
     110,   117,   120,   123,   126,   129,   135,   140,   145,   150,
     155,    21,   167,   207,   167,    98,   104,   182,   175,   170,
     175,    67,   183,    66,    43,    66,   108,   168,   170,    38,
      39,    40,    41,    42,   134,   139,   144,   149,   154,   159,
     164,   167,    18,   174,   175,    19,   194,    90,    90,    20,
      66,    17,    18,   170,    90,   167,    69,    15,   113,   126,
     168,   174,   170,   174,    15,   126,   132,   137,   142,   147,
     152,   157,    21,   168,    66,    78,   195,   196,    15,   167,
      17,   175,    66,   169,    66,    15,    15,   175,   168,   174,
     170,   196,   176,   174,   175,   175,    15,    21,    15,   175,
     177,   175
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

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

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 165:
/* Line 1787 of yacc.c  */
#line 278 "JSint.y"
    { printf("haha!=\n");}
    break;


/* Line 1787 of yacc.c  */
#line 2007 "parser.cpp"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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


