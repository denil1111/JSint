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
#include <cstring>
#include <string>
#include "ast.h"
#include "utils.h"
#include "parser.hpp"
#include "ccalc.h"
using namespace std;

int yydebug = 1;
ast::Node* ast_root;

/* Line 371 of yacc.c  */
#line 85 "parser.cpp"

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
     THIS = 267,
     NEW = 268,
     DELETE = 269,
     VOID = 270,
     TYPEOF = 271,
     INSTANCEOF = 272,
     IN = 273,
     VAR = 274,
     IF = 275,
     ELSE = 276,
     DO = 277,
     WHILE = 278,
     FOR = 279,
     CONTINUE = 280,
     BREAK = 281,
     RETURN = 282,
     WITH = 283,
     SWITCH = 284,
     CASE = 285,
     DEFAULT = 286,
     THROW = 287,
     TRY = 288,
     CATCH = 289,
     FINALLY = 290,
     FUNCTION = 291,
     IMPORT = 292,
     LEFT_BRACKET = 293,
     RIGHT_BRACKET = 294,
     LEFT_PARE = 295,
     RIGHT_PARE = 296,
     LEFT_BRACE = 297,
     RIGHT_BRACE = 298,
     COMMA = 299,
     DOT = 300,
     COLON = 301,
     SEMICOLON = 302,
     PLUS = 303,
     MINUS = 304,
     MULTI = 305,
     ASSIGN = 306,
     PLUS_PLUS = 307,
     MINUS_MINUS = 308,
     TILDE = 309,
     QUES = 310,
     EXCLAM = 311,
     PERCENT = 312,
     LESS = 313,
     GREATER = 314,
     EQUAL = 315,
     LSHIFT = 316,
     RSHIFT = 317,
     RRSHIFT = 318,
     LESS_EQ = 319,
     GREATER_EQ = 320,
     NOT_EQUAL = 321,
     ALWAYS_EQ = 322,
     ALWAYS_NEQ = 323,
     BIT_AND = 324,
     BIT_OR = 325,
     BIT_NOT = 326,
     AND = 327,
     OR = 328,
     MULTI_ASG = 329,
     MOD_ASG = 330,
     PLUS_ASG = 331,
     MINUS_ASG = 332,
     LSHIFT_ASG = 333,
     RSHIFT_ASG = 334,
     LLSHIFT_ASG = 335,
     BIT_AND_ASG = 336,
     BIT_NOT_ASG = 337,
     BIT_OR_ASG = 338
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 17 "JSint.y"

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
	ast::BinaryOperator::OpType ast_OpType;
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
#line 243 "parser.cpp"
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
#line 271 "parser.cpp"

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
#define YYFINAL  167
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1070

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  131
/* YYNRULES -- Number of rules.  */
#define YYNRULES  283
/* YYNRULES -- Number of states.  */
#define YYNSTATES  447

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   338

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
      75,    76,    77,    78,    79,    80,    81,    82,    83
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    11,    13,    15,    17,    19,
      21,    23,    25,    27,    29,    33,    38,    42,    45,    49,
      52,    56,    57,    59,    62,    66,    69,    72,    75,    79,
      80,    84,    86,    88,    90,    93,    96,    98,   101,   104,
     108,   112,   113,   116,   117,   121,   124,   128,   132,   135,
     136,   138,   142,   145,   149,   152,   155,   159,   160,   162,
     164,   166,   168,   170,   173,   175,   177,   179,   181,   184,
     188,   190,   192,   194,   196,   198,   200,   202,   204,   206,
     209,   213,   214,   216,   218,   220,   223,   227,   228,   230,
     232,   235,   239,   240,   242,   244,   246,   249,   253,   254,
     256,   258,   260,   262,   264,   266,   269,   273,   274,   276,
     278,   280,   282,   284,   287,   291,   292,   295,   299,   300,
     302,   304,   306,   308,   311,   315,   316,   319,   323,   324,
     326,   329,   333,   334,   337,   341,   342,   344,   347,   351,
     352,   355,   359,   360,   362,   365,   369,   370,   373,   377,
     378,   380,   383,   387,   388,   391,   395,   396,   398,   400,
     406,   408,   414,   418,   420,   424,   426,   428,   430,   432,
     434,   436,   438,   440,   442,   444,   446,   448,   450,   453,
     457,   458,   461,   465,   466,   467,   469,   471,   473,   475,
     477,   479,   481,   483,   485,   487,   489,   491,   493,   495,
     497,   499,   501,   504,   508,   510,   513,   516,   520,   522,
     526,   528,   531,   533,   536,   539,   542,   544,   546,   549,
     555,   563,   570,   578,   584,   593,   603,   614,   623,   631,
     632,   634,   636,   639,   642,   645,   648,   652,   658,   664,
     667,   671,   673,   676,   680,   682,   685,   689,   694,   697,
     701,   705,   708,   712,   716,   718,   720,   723,   729,   732,
     735,   739,   744,   748,   753,   755,   759,   762,   766,   768,
     771,   773,   776,   778,   780,   784,   790,   792,   796,   799,
     803,   805,   809,   813
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     207,     0,    -1,    12,    -1,    92,    -1,    40,   167,    41,
      -1,    87,    -1,    88,    -1,    86,    -1,     3,    -1,     4,
      -1,     5,    -1,     6,    -1,     7,    -1,    11,    -1,    38,
      91,    39,    -1,    38,    89,    91,    39,    -1,    38,    89,
      39,    -1,    38,    39,    -1,    91,   164,    90,    -1,   164,
      90,    -1,    90,    91,   164,    -1,    -1,    44,    -1,    91,
      44,    -1,    42,    93,    43,    -1,    42,    43,    -1,    95,
      94,    -1,    94,    44,    -1,    94,    44,    95,    -1,    -1,
      96,    46,   164,    -1,    87,    -1,     5,    -1,     3,    -1,
     204,   101,    -1,    85,   101,    -1,    99,    -1,   204,   101,
      -1,    85,   101,    -1,    13,    97,   100,    -1,   100,   107,
     101,    -1,    -1,   101,   102,    -1,    -1,    38,   167,    39,
      -1,    45,    87,    -1,    97,   107,   105,    -1,    98,   107,
     105,    -1,   105,   106,    -1,    -1,   107,    -1,    38,   167,
      39,    -1,    45,    87,    -1,    40,   108,    41,    -1,    40,
      41,    -1,   164,   109,    -1,   109,    44,   164,    -1,    -1,
     103,    -1,    97,    -1,   104,    -1,    98,    -1,   110,    -1,
     110,   113,    -1,    52,    -1,    53,    -1,   112,    -1,   115,
      -1,   116,   114,    -1,   115,   116,   114,    -1,    14,    -1,
      15,    -1,    16,    -1,    52,    -1,    53,    -1,    48,    -1,
      49,    -1,    54,    -1,    56,    -1,   114,   118,    -1,   118,
     119,   114,    -1,    -1,    50,    -1,     9,    -1,    57,    -1,
     117,   121,    -1,   121,   122,   117,    -1,    -1,    48,    -1,
      49,    -1,   120,   124,    -1,   124,   125,   120,    -1,    -1,
      61,    -1,    62,    -1,    63,    -1,   123,   127,    -1,   127,
     128,   123,    -1,    -1,    58,    -1,    59,    -1,    64,    -1,
      65,    -1,    17,    -1,    18,    -1,   123,   130,    -1,   130,
     131,   123,    -1,    -1,    58,    -1,    59,    -1,    64,    -1,
      65,    -1,    17,    -1,   126,   133,    -1,   133,   136,   126,
      -1,    -1,   129,   135,    -1,   135,   136,   129,    -1,    -1,
      60,    -1,    66,    -1,    67,    -1,    68,    -1,   132,   138,
      -1,   138,   141,   132,    -1,    -1,   134,   140,    -1,   140,
     141,   134,    -1,    -1,    69,    -1,   137,   143,    -1,   143,
     146,   137,    -1,    -1,   139,   145,    -1,   145,   146,   139,
      -1,    -1,    71,    -1,   142,   148,    -1,   148,   151,   142,
      -1,    -1,   144,   150,    -1,   150,   151,   144,    -1,    -1,
      70,    -1,   147,   153,    -1,   153,   156,   147,    -1,    -1,
     149,   155,    -1,   155,   156,   149,    -1,    -1,    72,    -1,
     152,   158,    -1,   158,   161,   152,    -1,    -1,   154,   160,
      -1,   160,   161,   154,    -1,    -1,    73,    -1,   157,    -1,
     157,    55,   164,    46,   164,    -1,   159,    -1,   159,    55,
     164,    46,   165,    -1,   110,   166,   164,    -1,   162,    -1,
     110,   166,   165,    -1,   163,    -1,    51,    -1,    74,    -1,
       8,    -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,
      79,    -1,    80,    -1,    81,    -1,    82,    -1,    83,    -1,
     164,   168,    -1,    44,   164,   168,    -1,    -1,   165,   170,
      -1,   170,    44,   165,    -1,    -1,    -1,   167,    -1,   173,
      -1,   212,    -1,   175,    -1,   181,    -1,   196,    -1,   182,
      -1,   183,    -1,   184,    -1,   186,    -1,   187,    -1,   210,
      -1,   188,    -1,   189,    -1,   190,    -1,   197,    -1,   198,
      -1,    42,    43,    -1,    42,   174,    43,    -1,   172,    -1,
     172,   174,    -1,    19,   176,    -1,    19,   176,    47,    -1,
     177,    -1,   176,    44,   177,    -1,    87,    -1,    87,   179,
      -1,    87,    -1,    87,   180,    -1,    51,   164,    -1,    51,
     165,    -1,    47,    -1,   167,    -1,   167,    47,    -1,    20,
      40,   167,    41,   172,    -1,    20,    40,   167,    41,   172,
      21,   172,    -1,    22,   172,    23,    40,   167,    41,    -1,
      22,   172,    23,    40,   167,    41,    47,    -1,    23,    40,
     167,    41,   172,    -1,    24,    40,    47,   171,    47,   171,
      41,   172,    -1,    24,    40,   169,    47,   171,    47,   171,
      41,   172,    -1,    24,    40,    19,   176,    47,   171,    47,
     171,    41,   172,    -1,    24,    40,    19,   178,    18,   167,
      41,   172,    -1,    24,    40,   111,    18,   167,    41,   172,
      -1,    -1,    87,    -1,    47,    -1,    87,    47,    -1,    25,
     185,    -1,    26,   185,    -1,    27,   171,    -1,    27,   171,
      47,    -1,    28,    40,   167,    41,   172,    -1,    29,    40,
     167,    41,   191,    -1,    42,   192,    -1,    42,   193,   192,
      -1,    43,    -1,   195,    43,    -1,   195,   193,    43,    -1,
     194,    -1,   193,   194,    -1,    30,   167,    46,    -1,    30,
     167,    46,   174,    -1,    31,    46,    -1,    31,    46,   174,
      -1,    87,    46,   172,    -1,    32,   167,    -1,    32,   167,
      47,    -1,    33,   173,   199,    -1,   201,    -1,   200,    -1,
     200,   201,    -1,    34,    40,    87,    41,   173,    -1,    35,
     173,    -1,    40,    41,    -1,    40,   205,    41,    -1,    36,
      87,   202,   206,    -1,    36,   202,   206,    -1,    36,    87,
     202,   206,    -1,    87,    -1,   205,    44,    87,    -1,    42,
      43,    -1,    42,   208,    43,    -1,    10,    -1,   208,    10,
      -1,   209,    -1,   208,   209,    -1,   203,    -1,   172,    -1,
      37,   211,    47,    -1,    37,   211,    45,    50,    47,    -1,
      11,    -1,   211,    45,    11,    -1,    19,   213,    -1,    19,
     213,    47,    -1,   214,    -1,   213,    44,   214,    -1,    87,
      46,    11,    -1,    87,    46,    11,   179,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   115,   115,   116,   117,   118,   122,   123,   127,   131,
     132,   139,   139,   140,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     160,   161,   162,   163,   164,   165,   173,   174,   175,   179,
     180,   181,   182,   183,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     205,   206,   211,   215,   216,   217,   218,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     244,   248,   251,   254,   257,   260,   271,   275,   278,   281,
     284,   294,   295,   298,   299,   300,   301,   311,   312,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   339,   340,   343,   344,   345,   346,
     347,   348,   349,   350,   360,   361,   364,   365,   366,   367,
     368,   378,   379,   382,   383,   384,   385,   386,   396,   397,
     400,   401,   402,   403,   404,   414,   415,   418,   419,   420,
     421,   422,   432,   433,   436,   437,   438,   439,   440,   443,
     444,   445,   446,   451,   455,   456,   457,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   483,
     491,   494,   495,   496,   499,   500,   501,   502,   503,   504,
     505,   506,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     530,   531,   532,   533,   534,   535,   536,   537,   540,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     597,   619,   641,   642,   645,   646,   647,   648,   649,   650,
     651,   652,   653,   654
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DECIMAL_LITERAL", "HEX_INTEGER_LITERAL",
  "STRING_LITERAL", "BOOLEAN_LITERAL", "NULL_LITERAL", "SLASHASSIGN",
  "SLASH", "JEOF", "IDENTIFIER_NAME", "THIS", "NEW", "DELETE", "VOID",
  "TYPEOF", "INSTANCEOF", "IN", "VAR", "IF", "ELSE", "DO", "WHILE", "FOR",
  "CONTINUE", "BREAK", "RETURN", "WITH", "SWITCH", "CASE", "DEFAULT",
  "THROW", "TRY", "CATCH", "FINALLY", "FUNCTION", "IMPORT", "LEFT_BRACKET",
  "RIGHT_BRACKET", "LEFT_PARE", "RIGHT_PARE", "LEFT_BRACE", "RIGHT_BRACE",
  "COMMA", "DOT", "COLON", "SEMICOLON", "PLUS", "MINUS", "MULTI", "ASSIGN",
  "PLUS_PLUS", "MINUS_MINUS", "TILDE", "QUES", "EXCLAM", "PERCENT", "LESS",
  "GREATER", "EQUAL", "LSHIFT", "RSHIFT", "RRSHIFT", "LESS_EQ",
  "GREATER_EQ", "NOT_EQUAL", "ALWAYS_EQ", "ALWAYS_NEQ", "BIT_AND",
  "BIT_OR", "BIT_NOT", "AND", "OR", "MULTI_ASG", "MOD_ASG", "PLUS_ASG",
  "MINUS_ASG", "LSHIFT_ASG", "RSHIFT_ASG", "LLSHIFT_ASG", "BIT_AND_ASG",
  "BIT_NOT_ASG", "BIT_OR_ASG", "$accept", "PrimaryExpression", "Literal",
  "Identifier", "ArrayLiteral", "ElementList", "ElementListPart",
  "Elision", "ObjectLiteral", "PropertyNameAndValueList",
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
  "CaseBlock", "CaseBlockPart", "CaseClauses", "CaseClause",
  "DefaultClause", "LabelledStatement", "ThrowStatement", "TryStatement",
  "TryStatementPart", "Catch", "Finally", "FormalParameterListInPare",
  "FunctionDeclaration", "FunctionExpression", "FormalParameterList",
  "FunctionBody", "Program", "SourceElements", "SourceElement",
  "ImportStatement", "Name", "JScriptVarStatement",
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
     335,   336,   337,   338
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    84,    85,    85,    85,    85,    85,    85,    86,    86,
      86,    86,    86,    87,    88,    88,    88,    88,    89,    89,
      90,    90,    91,    91,    92,    92,    93,    94,    94,    94,
      95,    96,    96,    96,    97,    97,    97,    98,    98,    99,
     100,   100,   101,   101,   102,   102,   103,   104,   105,   105,
     106,   106,   106,   107,   107,   108,   109,   109,   110,   110,
     111,   111,   112,   112,   113,   113,   114,   114,   115,   115,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   117,
     118,   118,   119,   119,   119,   120,   121,   121,   122,   122,
     123,   124,   124,   125,   125,   125,   126,   127,   127,   128,
     128,   128,   128,   128,   128,   129,   130,   130,   131,   131,
     131,   131,   131,   132,   133,   133,   134,   135,   135,   136,
     136,   136,   136,   137,   138,   138,   139,   140,   140,   141,
     142,   143,   143,   144,   145,   145,   146,   147,   148,   148,
     149,   150,   150,   151,   152,   153,   153,   154,   155,   155,
     156,   157,   158,   158,   159,   160,   160,   161,   162,   162,
     163,   163,   164,   164,   165,   165,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   167,   168,
     168,   169,   170,   170,   171,   171,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   173,   173,   174,   174,   175,   175,   176,   176,
     177,   177,   178,   178,   179,   180,   181,   182,   182,   183,
     183,   184,   184,   184,   184,   184,   184,   184,   184,   185,
     185,   185,   185,   186,   187,   188,   188,   189,   190,   191,
     191,   192,   192,   192,   193,   193,   194,   194,   195,   195,
     196,   197,   197,   198,   199,   199,   199,   200,   201,   202,
     202,   203,   204,   204,   205,   205,   206,   206,   207,   207,
     208,   208,   209,   209,   210,   210,   211,   211,   212,   212,
     213,   213,   214,   214
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     3,     2,     3,     2,
       3,     0,     1,     2,     3,     2,     2,     2,     3,     0,
       3,     1,     1,     1,     2,     2,     1,     2,     2,     3,
       3,     0,     2,     0,     3,     2,     3,     3,     2,     0,
       1,     3,     2,     3,     2,     2,     3,     0,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     0,     1,     1,     1,     2,     3,     0,     1,     1,
       2,     3,     0,     1,     1,     1,     2,     3,     0,     1,
       1,     1,     1,     1,     1,     2,     3,     0,     1,     1,
       1,     1,     1,     2,     3,     0,     2,     3,     0,     1,
       1,     1,     1,     2,     3,     0,     2,     3,     0,     1,
       2,     3,     0,     2,     3,     0,     1,     2,     3,     0,
       2,     3,     0,     1,     2,     3,     0,     2,     3,     0,
       1,     2,     3,     0,     2,     3,     0,     1,     1,     5,
       1,     5,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       0,     2,     3,     0,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     1,     2,     2,     3,     1,     3,
       1,     2,     1,     2,     2,     2,     1,     1,     2,     5,
       7,     6,     7,     5,     8,     9,    10,     8,     7,     0,
       1,     1,     2,     2,     2,     2,     3,     5,     5,     2,
       3,     1,     2,     3,     1,     2,     3,     4,     2,     3,
       3,     2,     3,     3,     1,     1,     2,     5,     2,     2,
       3,     4,     3,     4,     1,     3,     2,     3,     1,     2,
       1,     2,     1,     1,     3,     5,     1,     3,     2,     3,
       1,     3,     3,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     8,     9,    10,    11,    12,   268,    13,     2,     0,
      70,    71,    72,     0,     0,     0,     0,     0,   229,   229,
     184,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     216,    75,    76,    73,    74,    77,    78,    43,     7,     5,
       6,     3,    59,    36,    58,    62,    66,    81,    67,     0,
      87,    92,    98,   115,   125,   132,   139,   146,   153,   158,
     163,   180,   217,   273,   186,   188,   189,   191,   192,   193,
     194,   195,   197,   198,   199,   190,   200,   201,   272,    43,
       0,     0,   270,   196,   187,     0,     0,     5,    41,   210,
     206,   208,   278,   280,     0,     0,     0,     0,   231,   230,
     233,   234,   185,   235,     0,     0,   251,     0,     0,     0,
       0,     0,   276,     0,    17,    22,     0,     0,    21,     0,
       8,    10,    25,     5,     0,    29,     0,   204,     0,    35,
       0,     0,    49,   168,   166,    64,    65,   167,   169,   170,
     171,   172,   173,   174,   175,   176,   177,    63,     0,    79,
       0,    62,    68,    85,    90,    96,   113,   123,   130,   137,
     144,   151,     0,     0,   178,   218,    34,     1,   269,   271,
       0,    33,    32,    25,    31,    39,     0,     0,   211,     0,
     207,     0,   279,     0,     0,     0,     0,   184,    43,    61,
      60,    62,     0,   107,   118,   128,   135,   142,   149,   156,
     160,   165,   183,     0,    43,   232,   236,     0,     0,   252,
     202,     0,     0,   253,   255,   254,   259,   264,     0,     0,
       0,   262,     0,   274,    16,     0,    14,    23,    21,    19,
       4,    24,    26,     0,   205,   203,     0,     0,    42,   250,
      54,     0,    57,    46,   162,    83,    82,    84,     0,    69,
      88,    89,     0,    93,    94,    95,     0,   103,   104,    99,
     100,   101,   102,     0,   119,   120,   121,   122,     0,   129,
       0,   136,     0,   143,     0,   150,     0,   157,     0,     0,
     180,     0,    43,   282,   214,   210,   209,     0,   281,     0,
       0,     0,   210,     0,     0,     0,    35,    49,     0,     0,
     105,   116,   126,   133,   140,   147,   154,     0,   181,   184,
      34,     0,     0,     0,   258,   256,   260,     0,   261,   266,
       0,   277,     0,    15,    18,     0,    27,    30,     0,    45,
      53,    55,     0,     0,    48,    50,    80,    86,    91,    97,
     114,   124,   131,   138,   145,   152,     0,   179,   263,    40,
     283,   219,     0,   223,     0,   213,   184,     0,   184,    47,
     164,     0,   112,   108,   109,   110,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   237,     0,   238,
       0,   265,   267,   275,    20,    28,    44,     0,     0,    52,
     159,     0,   221,    62,    98,   215,     0,     0,     0,     0,
     106,   117,   127,   134,   141,   148,   155,     0,   182,   184,
       0,     0,   241,   239,     0,   244,     0,     0,    56,    51,
     220,   222,     0,   184,     0,     0,   228,   161,     0,     0,
     248,   240,   245,   242,     0,   257,     0,   227,   224,     0,
     246,   249,   243,     0,   225,   247,   226
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    37,    38,    87,    40,   116,   229,   325,    41,   124,
     232,   125,   126,    42,   189,    43,   175,   129,   238,    44,
     190,   243,   334,   335,   241,   331,    45,   192,    46,   147,
      47,    48,    49,    50,   149,   248,    51,   153,   252,    52,
     154,   256,    53,   155,   263,   194,   300,   367,    54,   156,
     195,   301,   268,    55,   157,   196,   302,   270,    56,   158,
     197,   303,   272,    57,   159,   198,   304,   274,    58,   160,
     199,   305,   276,    59,   161,   200,   306,   278,    60,   201,
      61,   360,   148,    62,   164,   203,   308,   103,   127,    64,
     128,    65,    90,    91,   294,   178,   355,    66,    67,    68,
      69,   100,    70,    71,    72,    73,    74,   379,   413,   414,
     415,   416,    75,    76,    77,   213,   214,   215,   111,    78,
      79,   218,   221,    80,    81,    82,    83,   113,    84,    92,
      93
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -391
static const yytype_int16 yypact[] =
{
     490,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,   259,
    -391,  -391,  -391,    40,    37,   814,    43,    59,     5,     5,
    1014,    77,    82,  1014,    94,    26,   140,   868,  1014,   544,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,   113,
    -391,  -391,   142,  -391,  -391,    93,  -391,  -391,   225,  1014,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,   125,
    -391,   139,   138,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
     184,   598,  -391,  -391,  -391,    26,    29,  -391,  -391,    17,
      91,  -391,   105,  -391,  1014,   164,  1014,    42,  -391,   141,
    -391,  -391,  -391,   144,  1014,  1014,   146,   652,   131,    24,
     154,   156,  -391,    81,  -391,  -391,    66,   887,  -391,   158,
     157,   159,  -391,   113,   161,  -391,   160,   814,   165,    -2,
     814,   941,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  -391,  1014,    14,
    1014,   -11,  -391,   129,    79,   137,    90,   145,   148,   130,
     143,   149,  1014,  1014,  -391,  -391,    -2,  -391,  -391,  -391,
     154,  -391,  -391,  -391,  -391,   142,   199,  1014,  -391,    40,
    -391,    40,  -391,   170,   173,   175,    40,  1014,  -391,   142,
    -391,    93,   203,  -391,  -391,  -391,  -391,  -391,  -391,  -391,
     162,  -391,  -391,   176,  -391,  -391,  -391,   183,   185,  -391,
    -391,   188,    94,  -391,   190,  -391,  -391,  -391,   119,   156,
     706,  -391,     9,  -391,  -391,    85,  -391,  -391,  -391,   187,
    -391,  -391,   189,  1014,  -391,  -391,  1014,    40,  -391,  -391,
    -391,   191,  -391,    22,  -391,  -391,  -391,  -391,  1014,  -391,
    -391,  -391,  1014,  -391,  -391,  -391,  1014,  -391,  -391,  -391,
    -391,  -391,  -391,  1014,  -391,  -391,  -391,  -391,  1014,  -391,
    1014,  -391,  1014,  -391,  1014,  -391,  1014,  -391,  1014,   198,
     139,   156,  -391,   178,  -391,   178,  -391,   201,  -391,   814,
    1014,   814,    -1,   117,   217,   202,    74,  -391,  1014,  1014,
      11,    90,   145,   148,   130,   143,   149,  1014,   192,  1014,
      75,   814,   206,    40,  -391,  -391,  -391,    40,   409,  -391,
     760,  -391,   204,  -391,   187,   960,   120,  -391,   214,  -391,
    -391,   211,  1014,    40,  -391,  -391,  -391,  -391,  -391,  -391,
    -391,  -391,  -391,  -391,  -391,  -391,  1014,  -391,  -391,    -2,
    -391,   238,   226,  -391,  1014,  -391,  1014,  1014,  1014,    22,
    -391,   227,  -391,  -391,  -391,  -391,  -391,  1014,  1014,  1014,
    1014,  1014,  1014,  1014,   229,  1014,   236,  -391,    -4,  -391,
     235,  -391,  -391,  -391,  -391,  -391,  -391,  1014,   245,  -391,
    -391,   814,   239,    93,  -391,  -391,   240,   244,   247,   814,
    -391,  -391,  -391,  -391,  -391,  -391,  -391,  1014,  -391,  1014,
    1014,   248,  -391,  -391,    -4,  -391,    57,    94,  -391,  -391,
    -391,  -391,  1014,  1014,   814,   814,  -391,  -391,   249,   256,
     814,  -391,  -391,  -391,    78,  -391,   252,  -391,  -391,   814,
     814,  -391,  -391,   814,  -391,  -391,  -391
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -391,   209,  -391,     0,  -391,  -391,    80,   -19,  -391,  -391,
    -391,   -14,  -391,   294,  -391,  -391,  -391,   -70,  -391,  -391,
    -391,    19,  -391,   -36,  -391,  -391,   -18,  -391,  -391,  -391,
     -39,  -391,   273,    55,  -391,  -391,    67,  -391,  -391,     6,
    -391,  -391,    54,  -391,  -391,   -44,  -391,  -391,    58,  -391,
     -40,  -391,    31,    53,  -391,   -35,  -391,    28,    60,  -391,
     -34,  -391,    35,    64,  -391,   -31,  -391,    39,    68,  -391,
     -29,  -391,    51,  -391,  -391,  -391,  -391,    41,  -391,  -391,
     -15,   -93,  -186,    10,    65,  -391,  -391,  -166,     7,   -23,
    -125,  -391,   172,   169,  -391,    76,  -391,  -391,  -391,  -391,
    -391,   342,  -391,  -391,  -391,  -391,  -391,  -391,   -52,   -53,
    -390,  -391,  -391,  -391,  -391,  -391,  -391,   150,   -96,  -391,
     268,  -391,  -208,  -391,   151,   -78,  -391,  -391,  -391,  -391,
     205
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -264
static const yytype_int16 yytable[] =
{
      39,   108,   234,   169,   202,   298,   132,    63,   117,   166,
     152,   318,   118,    89,   219,    39,     7,  -212,    99,    99,
     321,   295,    95,   245,   432,   110,   410,   411,   362,   123,
     102,   151,   171,   106,   172,     7,   236,     7,   119,   412,
       7,   135,   136,   237,   432,     1,     2,     3,     4,     5,
     354,     7,    98,     7,     8,     9,    10,    11,    12,   322,
     332,   186,   131,   176,   246,   216,   109,   333,   177,   363,
     364,   247,   173,   348,   281,   365,   366,    94,    85,   191,
      27,    39,    28,    96,    86,   170,   174,   410,    63,   187,
      31,    32,   -38,   -37,    33,    34,    35,   225,    36,    97,
     433,   133,   228,   193,   183,   224,   185,    39,   410,   217,
     115,   249,   236,   236,   207,   208,   242,   104,   296,   237,
     237,   442,   105,   171,   323,   172,   222,    39,   223,   227,
      39,     7,   151,   244,   310,   179,   107,   239,   180,   282,
     253,   254,   255,   376,   134,   135,   136,   279,   280,   181,
     264,   112,   182,   297,   257,   258,   265,   266,   267,   130,
     316,   179,   284,   317,   356,   211,   212,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   250,   251,   285,
     162,   287,   131,   163,   167,   165,   292,   184,   205,   314,
     396,   206,   398,   209,   109,   259,   260,   102,   220,   230,
     273,   261,   262,   -33,   231,   -32,   233,   422,   235,   336,
     283,   289,   349,   290,   269,   275,   291,   307,   327,   271,
      39,   299,   277,   309,   311,   212,   312,    63,   313,   177,
     151,   115,   330,   326,   151,   357,   375,   329,   151,    10,
      11,    12,   169,   428,   346,   151,   328,   176,   378,   358,
     151,   383,   151,   386,   151,   387,   151,   436,   151,   391,
     151,   395,     1,     2,     3,     4,     5,   392,   399,   339,
       7,     8,     9,    31,    32,   407,   417,    33,    34,    35,
     191,    36,   408,   409,   419,   424,   421,   423,   425,    39,
     439,    39,   374,   443,   430,    85,   351,    27,   353,    28,
     352,    86,   440,    88,   193,   441,   188,   337,   324,   361,
     384,    39,   385,   380,   427,   445,   359,   381,   377,   102,
      39,   150,   340,   338,   401,   342,   174,    63,   341,   402,
     369,   390,   368,   389,   343,   403,   393,   404,   370,   284,
     344,   405,   388,   371,   406,   347,   345,   373,   286,   151,
     151,   151,   151,   151,   151,   151,   372,   191,   293,   350,
     394,   101,   431,   434,   315,   204,   102,   397,   102,     0,
       0,   320,   418,   400,   193,   193,   193,   193,   193,   193,
       0,   193,     0,     0,     0,     0,   288,     0,     0,   191,
       0,    39,     0,     0,   435,     0,     0,     0,   420,    39,
       0,     0,     0,     0,   393,     0,   426,   244,     0,     0,
       0,     0,     0,   193,     0,     0,     0,  -263,  -263,   102,
     429,     0,     0,     0,    39,    39,  -263,  -263,   394,     0,
      39,   437,   438,   102,     0,     0,     0,     0,     0,    39,
      39,     0,     0,    39,     0,     0,   444,     0,     0,     0,
     446,     0,     0,  -263,  -263,     0,     0,     0,     0,  -263,
    -263,     0,     0,     0,  -263,     0,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,     1,     2,     3,     4,     5,     0,     0,
       6,     7,     8,     9,    10,    11,    12,     0,     0,    13,
      14,     0,    15,    16,    17,    18,    19,    20,    21,    22,
       0,     0,    23,    24,     0,     0,    25,    26,    27,     0,
      28,     0,    29,     0,     0,     0,     0,    30,    31,    32,
       0,     0,    33,    34,    35,     0,    36,   120,     2,   121,
       4,     5,     0,     0,     0,     7,     8,     9,    10,    11,
      12,     0,     0,    13,    14,     0,    15,    16,    17,    18,
      19,    20,    21,    22,     0,     0,    23,    24,     0,     0,
      85,    26,    27,     0,    28,     0,    29,   122,     0,     0,
       0,    30,    31,    32,     0,     0,    33,    34,    35,     0,
      36,     1,     2,     3,     4,     5,     0,     0,   168,     7,
       8,     9,    10,    11,    12,     0,     0,    13,    14,     0,
      15,    16,    17,    18,    19,    20,    21,    22,     0,     0,
      23,    24,     0,     0,    25,    26,    27,     0,    28,     0,
      29,     0,     0,     0,     0,    30,    31,    32,     0,     0,
      33,    34,    35,     0,    36,     1,     2,     3,     4,     5,
       0,     0,     0,     7,     8,     9,    10,    11,    12,     0,
       0,    13,    14,     0,    15,    16,    17,    18,    19,    20,
      21,    22,     0,     0,    23,    24,     0,     0,    85,    26,
      27,     0,    28,     0,    29,   210,     0,     0,     0,    30,
      31,    32,     0,     0,    33,    34,    35,     0,    36,     1,
       2,     3,     4,     5,     0,     0,     0,     7,     8,     9,
      10,    11,    12,     0,     0,    13,    14,     0,    15,    16,
      17,    18,    19,    20,    21,    22,     0,     0,    23,    24,
       0,     0,    25,    26,    27,     0,    28,     0,    29,   319,
       0,     0,     0,    30,    31,    32,     0,     0,    33,    34,
      35,     0,    36,     1,     2,     3,     4,     5,     0,     0,
       0,     7,     8,     9,    10,    11,    12,     0,     0,    13,
      14,     0,    15,    16,    17,    18,    19,    20,    21,    22,
       0,     0,    23,    24,     0,     0,    25,    26,    27,     0,
      28,     0,    29,   382,     0,     0,     0,    30,    31,    32,
       0,     0,    33,    34,    35,     0,    36,     1,     2,     3,
       4,     5,     0,     0,     0,     7,     8,     9,    10,    11,
      12,     0,     0,    13,    14,     0,    15,    16,    17,    18,
      19,    20,    21,    22,     0,     0,    23,    24,     0,     0,
      85,    26,    27,     0,    28,     0,    29,     0,     0,     0,
       0,    30,    31,    32,     0,     0,    33,    34,    35,     0,
      36,     1,     2,     3,     4,     5,     0,     0,     0,     7,
       8,     9,    10,    11,    12,     0,     0,     0,     0,     0,
       1,     2,     3,     4,     5,     0,     0,     0,     7,     8,
       9,    10,    11,    12,    85,     0,    27,   114,    28,     0,
      86,     0,   115,     0,     0,     0,    31,    32,     0,     0,
      33,    34,    35,    85,    36,    27,   226,    28,     0,    86,
       0,   227,     0,     0,     0,    31,    32,     0,     0,    33,
      34,    35,     0,    36,     1,     2,     3,     4,     5,     0,
       0,     0,     7,     8,     9,    10,    11,    12,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     0,     0,
       0,     7,     8,     9,    10,    11,    12,    85,     0,    27,
       0,    28,   240,    86,     0,     0,     0,     0,     0,    31,
      32,     0,     0,    33,    34,    35,    85,    36,    27,     0,
      28,     0,    86,     0,   227,     0,     0,     0,    31,    32,
       0,     0,    33,    34,    35,     0,    36,     1,     2,     3,
       4,     5,     0,     0,     0,     7,     8,     9,    10,    11,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,     0,    27,     0,    28,     0,    86,     0,     0,     0,
       0,     0,    31,    32,     0,     0,    33,    34,    35,     0,
      36
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-391)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    24,   127,    81,    97,   191,    42,     0,    27,    79,
      49,   219,    27,    13,   110,    15,    11,    18,    18,    19,
      11,   187,    15,     9,   414,    25,    30,    31,    17,    29,
      20,    49,     3,    23,     5,    11,    38,    11,    28,    43,
      11,    52,    53,    45,   434,     3,     4,     5,     6,     7,
      51,    11,    47,    11,    12,    13,    14,    15,    16,    50,
      38,    19,    40,    46,    50,    41,    40,    45,    51,    58,
      59,    57,    43,   281,   170,    64,    65,    40,    36,    97,
      38,    81,    40,    40,    42,    85,    86,    30,    81,    47,
      48,    49,    18,    18,    52,    53,    54,   116,    56,    40,
      43,     8,   117,    97,    94,    39,    96,   107,    30,   109,
      44,   150,    38,    38,   104,   105,   131,    40,   188,    45,
      45,    43,    40,     3,    39,     5,    45,   127,    47,    44,
     130,    11,   150,   148,   204,    44,    42,   130,    47,   175,
      61,    62,    63,   309,    51,    52,    53,   162,   163,    44,
      60,    11,    47,   189,    17,    18,    66,    67,    68,    46,
      41,    44,   177,    44,    47,    34,    35,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    48,    49,   179,
      55,   181,    40,    44,     0,    47,   186,    23,    47,   212,
     356,    47,   358,    47,    40,    58,    59,   187,    42,    41,
      70,    64,    65,    46,    43,    46,    46,   393,    43,   248,
      11,    41,   282,    40,    69,    72,    41,    55,   233,    71,
     220,    18,    73,    47,    41,    35,    41,   220,    40,    51,
     248,    44,    41,    44,   252,    18,    44,   237,   256,    14,
      15,    16,   320,   409,    46,   263,   236,    46,    42,    47,
     268,    47,   270,    39,   272,    44,   274,   423,   276,    21,
     278,   354,     3,     4,     5,     6,     7,    41,    41,   263,
      11,    12,    13,    48,    49,    46,    41,    52,    53,    54,
     298,    56,   375,    47,    39,    41,    47,    47,    41,   289,
      41,   291,   307,    41,    46,    36,   289,    38,   291,    40,
     290,    42,    46,     9,   298,   430,    97,   252,   228,   299,
     325,   311,   326,   313,   407,   440,   297,   317,   311,   309,
     320,    48,   268,   256,   368,   272,   326,   320,   270,   369,
     302,   346,   301,   333,   274,   370,   354,   371,   303,   354,
     276,   372,   332,   304,   373,   280,   278,   306,   179,   367,
     368,   369,   370,   371,   372,   373,   305,   375,   186,   283,
     354,    19,   414,   416,   214,    97,   356,   357,   358,    -1,
      -1,   220,   387,   367,   368,   369,   370,   371,   372,   373,
      -1,   375,    -1,    -1,    -1,    -1,   181,    -1,    -1,   407,
      -1,   391,    -1,    -1,   417,    -1,    -1,    -1,   391,   399,
      -1,    -1,    -1,    -1,   422,    -1,   399,   422,    -1,    -1,
      -1,    -1,    -1,   407,    -1,    -1,    -1,     8,     9,   409,
     410,    -1,    -1,    -1,   424,   425,    17,    18,   422,    -1,
     430,   424,   425,   423,    -1,    -1,    -1,    -1,    -1,   439,
     440,    -1,    -1,   443,    -1,    -1,   439,    -1,    -1,    -1,
     443,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,
      51,    -1,    -1,    -1,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,     3,     4,     5,     6,     7,    -1,    -1,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    32,    33,    -1,    -1,    36,    37,    38,    -1,
      40,    -1,    42,    -1,    -1,    -1,    -1,    47,    48,    49,
      -1,    -1,    52,    53,    54,    -1,    56,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    11,    12,    13,    14,    15,
      16,    -1,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    32,    33,    -1,    -1,
      36,    37,    38,    -1,    40,    -1,    42,    43,    -1,    -1,
      -1,    47,    48,    49,    -1,    -1,    52,    53,    54,    -1,
      56,     3,     4,     5,     6,     7,    -1,    -1,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      32,    33,    -1,    -1,    36,    37,    38,    -1,    40,    -1,
      42,    -1,    -1,    -1,    -1,    47,    48,    49,    -1,    -1,
      52,    53,    54,    -1,    56,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    11,    12,    13,    14,    15,    16,    -1,
      -1,    19,    20,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    32,    33,    -1,    -1,    36,    37,
      38,    -1,    40,    -1,    42,    43,    -1,    -1,    -1,    47,
      48,    49,    -1,    -1,    52,    53,    54,    -1,    56,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    11,    12,    13,
      14,    15,    16,    -1,    -1,    19,    20,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    32,    33,
      -1,    -1,    36,    37,    38,    -1,    40,    -1,    42,    43,
      -1,    -1,    -1,    47,    48,    49,    -1,    -1,    52,    53,
      54,    -1,    56,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    11,    12,    13,    14,    15,    16,    -1,    -1,    19,
      20,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    32,    33,    -1,    -1,    36,    37,    38,    -1,
      40,    -1,    42,    43,    -1,    -1,    -1,    47,    48,    49,
      -1,    -1,    52,    53,    54,    -1,    56,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    11,    12,    13,    14,    15,
      16,    -1,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    32,    33,    -1,    -1,
      36,    37,    38,    -1,    40,    -1,    42,    -1,    -1,    -1,
      -1,    47,    48,    49,    -1,    -1,    52,    53,    54,    -1,
      56,     3,     4,     5,     6,     7,    -1,    -1,    -1,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    11,    12,
      13,    14,    15,    16,    36,    -1,    38,    39,    40,    -1,
      42,    -1,    44,    -1,    -1,    -1,    48,    49,    -1,    -1,
      52,    53,    54,    36,    56,    38,    39,    40,    -1,    42,
      -1,    44,    -1,    -1,    -1,    48,    49,    -1,    -1,    52,
      53,    54,    -1,    56,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    11,    12,    13,    14,    15,    16,    36,    -1,    38,
      -1,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    48,
      49,    -1,    -1,    52,    53,    54,    36,    56,    38,    -1,
      40,    -1,    42,    -1,    44,    -1,    -1,    -1,    48,    49,
      -1,    -1,    52,    53,    54,    -1,    56,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    38,    -1,    40,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    -1,    -1,    52,    53,    54,    -1,
      56
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    10,    11,    12,    13,
      14,    15,    16,    19,    20,    22,    23,    24,    25,    26,
      27,    28,    29,    32,    33,    36,    37,    38,    40,    42,
      47,    48,    49,    52,    53,    54,    56,    85,    86,    87,
      88,    92,    97,    99,   103,   110,   112,   114,   115,   116,
     117,   120,   123,   126,   132,   137,   142,   147,   152,   157,
     162,   164,   167,   172,   173,   175,   181,   182,   183,   184,
     186,   187,   188,   189,   190,   196,   197,   198,   203,   204,
     207,   208,   209,   210,   212,    36,    42,    87,    97,    87,
     176,   177,   213,   214,    40,   172,    40,    40,    47,    87,
     185,   185,   167,   171,    40,    40,   167,    42,   173,    40,
      87,   202,    11,   211,    39,    44,    89,    91,   164,   167,
       3,     5,    43,    87,    93,    95,    96,   172,   174,   101,
      46,    40,   107,     8,    51,    52,    53,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,   113,   166,   118,
     116,   110,   114,   121,   124,   127,   133,   138,   143,   148,
     153,   158,    55,    44,   168,    47,   101,     0,    10,   209,
      87,     3,     5,    43,    87,   100,    46,    51,   179,    44,
      47,    44,    47,   167,    23,   167,    19,    47,    85,    98,
     104,   110,   111,   123,   129,   134,   139,   144,   149,   154,
     159,   163,   165,   169,   204,    47,    47,   167,   167,    47,
      43,    34,    35,   199,   200,   201,    41,    87,   205,   202,
      42,   206,    45,    47,    39,    91,    39,    44,   164,    90,
      41,    43,    94,    46,   174,    43,    38,    45,   102,   172,
      41,   108,   164,   105,   164,     9,    50,    57,   119,   114,
      48,    49,   122,    61,    62,    63,   125,    17,    18,    58,
      59,    64,    65,   128,    60,    66,    67,    68,   136,    69,
     141,    71,   146,    70,   151,    72,   156,    73,   161,   164,
     164,   202,   107,    11,   164,    87,   177,    87,   214,    41,
      40,    41,    87,   176,   178,   171,   101,   107,   166,    18,
     130,   135,   140,   145,   150,   155,   160,    55,   170,    47,
     101,    41,    41,    40,   173,   201,    41,    44,   206,    43,
     208,    11,    50,    39,    90,    91,    44,   164,   167,    87,
      41,   109,    38,    45,   106,   107,   114,   117,   120,   123,
     126,   132,   137,   142,   147,   152,    46,   168,   206,   101,
     179,   172,   167,   172,    51,   180,    47,    18,    47,   105,
     165,   167,    17,    58,    59,    64,    65,   131,   136,   141,
     146,   151,   156,   161,   164,    44,   171,   172,    42,   191,
      87,    87,    43,    47,   164,    95,    39,    44,   167,    87,
     164,    21,    41,   110,   123,   165,   171,   167,   171,    41,
     123,   129,   134,   139,   144,   149,   154,    46,   165,    47,
      30,    31,    43,   192,   193,   194,   195,    41,   164,    39,
     172,    47,   166,    47,    41,    41,   172,   165,   171,   167,
      46,   192,   194,    43,   193,   173,   171,   172,   172,    41,
      46,   174,    43,    41,   172,   174,   172
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
        case 5:
/* Line 1787 of yacc.c  */
#line 118 "JSint.y"
    {
/*	//printf("identifier\n");*/
	(yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression);
}
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 123 "JSint.y"
    {
/*	//printf("Literal\n");*/
	(yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression);
}
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 127 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::IntegerType(atoi((yyvsp[(1) - (1)].debug))); (yyval.ast_Expression)->debug = (yyvsp[(1) - (1)].debug);
	//printf("number\n");
}
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 132 "JSint.y"
    {
	char a[200];
	strcpy(a,(yyvsp[(1) - (1)].debug)+1);
	a[strlen(a)-1] = 0;
/*	std::cout<<a<<std::endl;*/
	(yyval.ast_Expression) = new ast::StringType(a); (yyval.ast_Expression)->debug = a;
}
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 140 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::Identifier((yyvsp[(1) - (1)].debug));
}
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 165 "JSint.y"
    {
	if ((yyvsp[(2) - (2)].ast_Expression) == nullptr)
	{
		(yyval.ast_Expression) = (yyvsp[(1) - (2)].ast_Expression);
/*		//printf("MemberExp\n");*/
	}
/*	//printf("MemberExp\n");*/
}
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 175 "JSint.y"
    {
/*	//printf("MemberExpForIn\n");*/
}
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 183 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
}
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 201 "JSint.y"
    {
	(yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression);
/*	//printf("LeftHandExp\n");*/
}
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 206 "JSint.y"
    {
	
}
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 211 "JSint.y"
    {
	(yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression);
/*	//printf("postfixExp\n");*/
}
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 218 "JSint.y"
    {
	(yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression);
}
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 233 "JSint.y"
    {
	auto exp = dynamic_cast<ast::BinaryOperator*>((yyvsp[(2) - (2)].ast_Expression));
	if (exp == nullptr) {
		(yyval.ast_Expression) = (yyvsp[(1) - (2)].ast_Expression);
	}
	else {
		(yyval.ast_Expression) = exp;
		exp ->op1 = (yyvsp[(1) - (2)].ast_Expression);
	}
}
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 244 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression),(yyvsp[(2) - (3)].ast_OpType),(yyvsp[(3) - (3)].ast_Expression));

}
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 248 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
}
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 251 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::mul;
}
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 254 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::div;
}
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 257 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::mod;
}
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 260 "JSint.y"
    {
	auto exp = dynamic_cast<ast::BinaryOperator*>((yyvsp[(2) - (2)].ast_Expression));
	if (exp == nullptr) {
		(yyval.ast_Expression) = (yyvsp[(1) - (2)].ast_Expression);
	}
	else {
		(yyval.ast_Expression) = exp;
		exp ->op1 = (yyvsp[(1) - (2)].ast_Expression);
	}
}
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 271 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression),(yyvsp[(2) - (3)].ast_OpType),(yyvsp[(3) - (3)].ast_Expression));

}
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 275 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
}
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 278 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::plus;
}
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 281 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::minus;
}
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 284 "JSint.y"
    {
	auto exp = dynamic_cast<ast::BinaryOperator*>((yyvsp[(2) - (2)].ast_Expression));
	if (exp == nullptr) {
		(yyval.ast_Expression) = (yyvsp[(1) - (2)].ast_Expression);
	}
	else {
		(yyval.ast_Expression) = exp;
		exp ->op1 = (yyvsp[(1) - (2)].ast_Expression);
	}
}
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 295 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
}
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 301 "JSint.y"
    {
	auto exp = dynamic_cast<ast::BinaryOperator*>((yyvsp[(2) - (2)].ast_Expression));
	if (exp == nullptr) {
		(yyval.ast_Expression) = (yyvsp[(1) - (2)].ast_Expression);
	}
	else {
		(yyval.ast_Expression) = exp;
		exp ->op1 = (yyvsp[(1) - (2)].ast_Expression);
	}
}
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 312 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
}
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 329 "JSint.y"
    {
	auto exp = dynamic_cast<ast::BinaryOperator*>((yyvsp[(2) - (2)].ast_Expression));
	if (exp == nullptr) {
		(yyval.ast_Expression) = (yyvsp[(1) - (2)].ast_Expression);
	}
	else {
		(yyval.ast_Expression) = exp;
		exp ->op1 = (yyvsp[(1) - (2)].ast_Expression);
	}
}
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 340 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
}
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 350 "JSint.y"
    {
	auto exp = dynamic_cast<ast::BinaryOperator*>((yyvsp[(2) - (2)].ast_Expression));
	if (exp == nullptr) {
		(yyval.ast_Expression) = (yyvsp[(1) - (2)].ast_Expression);
	}
	else {
		(yyval.ast_Expression) = exp;
		exp ->op1 = (yyvsp[(1) - (2)].ast_Expression);
	}
}
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 361 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
}
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 368 "JSint.y"
    {
	auto exp = dynamic_cast<ast::BinaryOperator*>((yyvsp[(2) - (2)].ast_Expression));
	if (exp == nullptr) {
		(yyval.ast_Expression) = (yyvsp[(1) - (2)].ast_Expression);
	}
	else {
		(yyval.ast_Expression) = exp;
		exp ->op1 = (yyvsp[(1) - (2)].ast_Expression);
	}
}
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 379 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
}
    break;

  case 137:
/* Line 1787 of yacc.c  */
#line 386 "JSint.y"
    {
	auto exp = dynamic_cast<ast::BinaryOperator*>((yyvsp[(2) - (2)].ast_Expression));
	if (exp == nullptr) {
		(yyval.ast_Expression) = (yyvsp[(1) - (2)].ast_Expression);
	}
	else {
		(yyval.ast_Expression) = exp;
		exp ->op1 = (yyvsp[(1) - (2)].ast_Expression);
	}
}
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 397 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
}
    break;

  case 144:
/* Line 1787 of yacc.c  */
#line 404 "JSint.y"
    {
	auto exp = dynamic_cast<ast::BinaryOperator*>((yyvsp[(2) - (2)].ast_Expression));
	if (exp == nullptr) {
		(yyval.ast_Expression) = (yyvsp[(1) - (2)].ast_Expression);
	}
	else {
		(yyval.ast_Expression) = exp;
		exp ->op1 = (yyvsp[(1) - (2)].ast_Expression);
	}
}
    break;

  case 146:
/* Line 1787 of yacc.c  */
#line 415 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
}
    break;

  case 151:
/* Line 1787 of yacc.c  */
#line 422 "JSint.y"
    {
	auto exp = dynamic_cast<ast::BinaryOperator*>((yyvsp[(2) - (2)].ast_Expression));
	if (exp == nullptr) {
		(yyval.ast_Expression) = (yyvsp[(1) - (2)].ast_Expression);
	}
	else {
		(yyval.ast_Expression) = exp;
		exp ->op1 = (yyvsp[(1) - (2)].ast_Expression);
	}
}
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 433 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
}
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 440 "JSint.y"
    {
	(yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression);
}
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 447 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression),(yyvsp[(2) - (3)].ast_OpType),(yyvsp[(3) - (3)].ast_Expression));
/*	//printf("an assign exp\n");*/
}
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 451 "JSint.y"
    {
	(yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression);
	//printf("an assign exp from condition\n");
}
    break;

  case 164:
/* Line 1787 of yacc.c  */
#line 455 "JSint.y"
    {}
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 457 "JSint.y"
    { 
	(yyval.ast_OpType) =ast::BinaryOperator::OpType::assign; 
	//printf("an assign\n");
}
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 473 "JSint.y"
    {
	if ((yyvsp[(2) - (2)].ast_Expression) == nullptr){
		(yyval.ast_Expression) = (yyvsp[(1) - (2)].ast_Expression);
	}
	else {
		(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (2)].ast_Expression),ast::BinaryOperator::OpType::comma,(yyvsp[(2) - (2)].ast_Expression));
	}
	
	
}
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 483 "JSint.y"
    {
	if ((yyvsp[(3) - (3)].ast_Expression) == nullptr) {
		(yyval.ast_Expression) = (yyvsp[(2) - (3)].ast_Expression);
	} else {
		(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(2) - (3)].ast_Expression),ast::BinaryOperator::OpType::comma,(yyvsp[(3) - (3)].ast_Expression));
	}
	
}
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 491 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
}
    break;

  case 191:
/* Line 1787 of yacc.c  */
#line 507 "JSint.y"
    {
	(yyval.ast_Statement) = (yyvsp[(1) - (1)].ast_Statement);
}
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 537 "JSint.y"
    {
	(yyval.ast_Statement) = (yyvsp[(1) - (1)].ast_Expression);
}
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 540 "JSint.y"
    {
	(yyval.ast_Statement) = (yyvsp[(1) - (2)].ast_Expression);
}
    break;

  case 269:
/* Line 1787 of yacc.c  */
#line 594 "JSint.y"
    {
	(yyval.ast_StatementList) = (yyvsp[(1) - (2)].ast_StatementList);
}
    break;

  case 270:
/* Line 1787 of yacc.c  */
#line 597 "JSint.y"
    {
	extern int parseError;
	if (!parseError)
	{
		(yyval.ast_StatementList) = new ast::StatementList;
		(yyval.ast_StatementList) -> list.push_back((yyvsp[(1) - (1)].ast_Statement));
		(yyvsp[(1) - (1)].ast_Statement) -> print_node("", true, true);
		ast_root = (yyvsp[(1) - (1)].ast_Statement);
		try {
			ast_root->run();
		} catch (const std::domain_error &de) {
			cout << de.what() << endl;		
		} catch (const std::logic_error &le) {
			cout << le.what() << endl;	
		} catch (...) {
			cout << "other uncaught error" << endl;
		}
		if (!parseError)
			ast_root->value.print();
	}	
	//printf("To SourceElements\n");
}
    break;

  case 271:
/* Line 1787 of yacc.c  */
#line 619 "JSint.y"
    {
	extern int parseError;
	if (!parseError)
	{
		(yyvsp[(2) - (2)].ast_Statement) -> print_node("", true, true);
		ast_root = (yyvsp[(2) - (2)].ast_Statement);
		try {
			ast_root->run();
		} catch (const std::domain_error &de) {
			cout << de.what() << endl;		
		} catch (const std::logic_error &le) {
			cout << le.what() << endl;	
		} catch (...) {
			cout << "other uncaught error" << endl;
		}
		//printf("To SourceElements\n");
		//printf("new source\n");
		if (!parseError)
			ast_root->value.print();
	}
	(yyvsp[(1) - (2)].ast_StatementList)->list.push_back((yyvsp[(2) - (2)].ast_Statement));
}
    break;

  case 273:
/* Line 1787 of yacc.c  */
#line 642 "JSint.y"
    {
	(yyval.ast_Statement) = (yyvsp[(1) - (1)].ast_Statement);
}
    break;


/* Line 1787 of yacc.c  */
#line 2653 "parser.cpp"
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


