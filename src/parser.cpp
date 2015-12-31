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
     PROGRAM = 258,
     IDD = 259,
     DOT = 260,
     EQUAL = 261,
     LTHAN = 262,
     LEQU = 263,
     GT = 264,
     GE = 265,
     PLUS = 266,
     MINUS = 267,
     MUL = 268,
     DIV = 269,
     RIGHTP = 270,
     LEFTP = 271,
     ASSIGN = 272,
     COLON = 273,
     COMMA = 274,
     SEMI = 275,
     UNTIL = 276,
     OR = 277,
     AND = 278,
     MOD = 279,
     OF = 280,
     READ = 281,
     REPEAT = 282,
     TO = 283,
     UNEQUAL = 284,
     IF = 285,
     THEN = 286,
     ELSE = 287,
     WHILE = 288,
     DO = 289,
     BEGINN = 290,
     END = 291,
     CASE = 292,
     DOWNTO = 293,
     FOR = 294,
     GOTO = 295,
     INTEGER = 296,
     LB = 297,
     RB = 298,
     NOT = 299,
     NUMBER = 300,
     SYS_CON = 301,
     SYS_BOOL = 302,
     SYS_FUNCT = 303,
     SYS_PROC = 304,
     SYS_TYPE = 305,
     CHAR = 306,
     CONST = 307,
     STRING = 308,
     REAL = 309,
     ARRAY = 310,
     VAR = 311,
     PROCEDURE = 312,
     RECORD = 313,
     FUNCTION = 314,
     TYPE = 315
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
#line 218 "parser.cpp"
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
#line 246 "parser.cpp"

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   391

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNRULES -- Number of states.  */
#define YYNSTATES  265

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    13,    14,    17,    20,    25,
      28,    29,    35,    40,    42,    44,    46,    48,    50,    53,
      54,    57,    59,    64,    66,    68,    70,    72,    74,    79,
      84,    89,    95,   102,   107,   114,   118,   121,   123,   128,
     132,   134,   137,   138,   141,   143,   148,   151,   154,   155,
     160,   166,   171,   175,   179,   182,   183,   187,   189,   194,
     198,   200,   204,   207,   211,   212,   214,   218,   220,   222,
     224,   226,   228,   230,   232,   234,   236,   238,   242,   249,
     255,   257,   262,   264,   269,   275,   278,   279,   284,   289,
     298,   307,   313,   316,   318,   323,   328,   331,   335,   337,
     339,   341,   345,   349,   353,   357,   361,   365,   369,   373,
     377,   379,   381,   383,   387,   391,   395,   399,   401,   406,
     408,   413,   415,   419,   422,   425,   430
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      63,     0,    -1,     4,    -1,    64,    65,     5,    -1,     3,
       4,    20,    -1,    -1,    67,    92,    -1,    67,    92,    -1,
      68,    71,    81,    84,    -1,    52,    69,    -1,    -1,    69,
      62,     6,    70,    20,    -1,    62,     6,    70,    20,    -1,
      41,    -1,    54,    -1,    51,    -1,    47,    -1,    46,    -1,
      60,    72,    -1,    -1,    72,    73,    -1,    73,    -1,     4,
       6,    74,    20,    -1,    76,    -1,    75,    -1,    77,    -1,
      50,    -1,    62,    -1,    41,     5,     5,    41,    -1,    51,
       5,     5,    51,    -1,    47,     5,     5,    47,    -1,    12,
      41,     5,     5,    41,    -1,    12,    41,     5,     5,    12,
      41,    -1,    62,     5,     5,    62,    -1,    55,    42,    75,
      43,    25,    74,    -1,    58,    78,    36,    -1,    78,    79,
      -1,    79,    -1,    80,    18,    74,    20,    -1,    80,    19,
       4,    -1,     4,    -1,    56,    82,    -1,    -1,    82,    83,
      -1,    83,    -1,    80,    18,    74,    20,    -1,    84,    85,
      -1,    84,    87,    -1,    -1,    86,    20,    66,    20,    -1,
      59,     4,    89,    18,    75,    -1,    88,    20,    66,    20,
      -1,    57,     4,    89,    -1,    16,    90,    15,    -1,    16,
      15,    -1,    -1,    90,    20,    91,    -1,    91,    -1,    56,
      80,    18,    75,    -1,    80,    18,    75,    -1,    93,    -1,
      35,    94,    36,    -1,    94,    95,    -1,    94,    95,    20,
      -1,    -1,    96,    -1,    41,    18,    96,    -1,     1,    -1,
      97,    -1,    98,    -1,    93,    -1,    99,    -1,   101,    -1,
     102,    -1,   103,    -1,   104,    -1,   107,    -1,     4,    17,
     109,    -1,     4,    42,   109,    43,    17,   109,    -1,     4,
       5,     4,    17,   109,    -1,     4,    -1,     4,    16,   108,
      15,    -1,    49,    -1,    49,    16,   108,    15,    -1,    30,
     109,    31,    95,   100,    -1,    32,    95,    -1,    -1,    27,
      94,    21,   109,    -1,    33,   109,    34,    95,    -1,    39,
       4,    17,   109,    28,   109,    34,    95,    -1,    39,     4,
      17,   109,    38,   109,    34,    95,    -1,    37,   109,    25,
     105,    36,    -1,   105,   106,    -1,   106,    -1,    70,    18,
      95,    20,    -1,     4,    18,    95,    20,    -1,    40,    41,
      -1,   108,    19,   109,    -1,   109,    -1,     1,    -1,   110,
      -1,   109,    10,   110,    -1,   109,     9,   110,    -1,   109,
       8,   110,    -1,   109,     7,   110,    -1,   109,     6,   110,
      -1,   109,    29,   110,    -1,   110,    11,   111,    -1,   110,
      12,   111,    -1,   110,    22,   111,    -1,   111,    -1,     1,
      -1,   112,    -1,   111,    13,   112,    -1,   111,    14,   112,
      -1,   111,    24,   112,    -1,   111,    23,   112,    -1,    62,
      -1,    62,    16,   108,    15,    -1,    48,    -1,    48,    16,
     108,    15,    -1,    70,    -1,    16,   109,    15,    -1,    44,
     112,    -1,    12,   112,    -1,     4,    42,   109,    43,    -1,
       4,     5,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    87,    87,    89,    90,    90,    93,    97,   102,   111,
     112,   116,   117,   121,   122,   123,   125,   126,   131,   132,
     136,   137,   141,   145,   146,   147,   151,   152,   154,   155,
     156,   157,   158,   159,   163,   167,   171,   172,   176,   180,
     181,   185,   186,   190,   191,   195,   199,   200,   201,   205,
     209,   213,   217,   221,   222,   223,   227,   228,   232,   233,
     237,   241,   245,   246,   247,   251,   252,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   271,   272,   273,
     277,   278,   279,   280,   285,   289,   290,   294,   297,   300,
     303,   308,   311,   312,   315,   316,   319,   323,   324,   327,
     328,   329,   330,   331,   332,   333,   334,   338,   339,   340,
     341,   345,   346,   347,   348,   349,   350,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "IDD", "DOT", "EQUAL",
  "LTHAN", "LEQU", "GT", "GE", "PLUS", "MINUS", "MUL", "DIV", "RIGHTP",
  "LEFTP", "ASSIGN", "COLON", "COMMA", "SEMI", "UNTIL", "OR", "AND", "MOD",
  "OF", "READ", "REPEAT", "TO", "UNEQUAL", "IF", "THEN", "ELSE", "WHILE",
  "DO", "BEGINN", "END", "CASE", "DOWNTO", "FOR", "GOTO", "INTEGER", "LB",
  "RB", "NOT", "NUMBER", "SYS_CON", "SYS_BOOL", "SYS_FUNCT", "SYS_PROC",
  "SYS_TYPE", "CHAR", "CONST", "STRING", "REAL", "ARRAY", "VAR",
  "PROCEDURE", "RECORD", "FUNCTION", "TYPE", "$accept", "NAME", "program",
  "program_head", "routine", "sub_routine", "routine_head", "const_part",
  "const_expr_list", "const_value", "type_part", "type_decl_list",
  "type_definition", "type_decl", "simple_type_decl", "array_type_decl",
  "record_type_decl", "field_decl_list", "field_decl", "name_list",
  "var_part", "var_decl_list", "var_decl", "routine_part", "function_decl",
  "function_head", "procedure_decl", "procedure_head", "parameters",
  "para_decl_list", "para_type_list", "routine_body", "compound_stmt",
  "stmt_list", "stmt", "non_label_stmt", "assign_stmt", "proc_stmt",
  "if_stmt", "else_clause", "repeat_stmt", "while_stmt", "for_stmt",
  "case_stmt", "case_expr_list", "case_expr", "goto_stmt",
  "expression_list", "expression", "expr", "term", "factor", YY_NULL
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
     315
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    64,    64,    65,    66,    67,    68,
      68,    69,    69,    70,    70,    70,    70,    70,    71,    71,
      72,    72,    73,    74,    74,    74,    75,    75,    75,    75,
      75,    75,    75,    75,    76,    77,    78,    78,    79,    80,
      80,    81,    81,    82,    82,    83,    84,    84,    84,    85,
      86,    87,    88,    89,    89,    89,    90,    90,    91,    91,
      92,    93,    94,    94,    94,    95,    95,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    97,    97,    97,
      98,    98,    98,    98,    99,   100,   100,   101,   102,   103,
     103,   104,   105,   105,   106,   106,   107,   108,   108,   109,
     109,   109,   109,   109,   109,   109,   109,   110,   110,   110,
     110,   111,   111,   111,   111,   111,   111,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     3,     0,     2,     2,     4,     2,
       0,     5,     4,     1,     1,     1,     1,     1,     2,     0,
       2,     1,     4,     1,     1,     1,     1,     1,     4,     4,
       4,     5,     6,     4,     6,     3,     2,     1,     4,     3,
       1,     2,     0,     2,     1,     4,     2,     2,     0,     4,
       5,     4,     3,     3,     2,     0,     3,     1,     4,     3,
       1,     3,     2,     3,     0,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     6,     5,
       1,     4,     1,     4,     5,     2,     0,     4,     4,     8,
       8,     5,     2,     1,     4,     4,     2,     3,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     3,     3,     3,     3,     1,     4,     1,
       4,     1,     3,     2,     2,     4,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,    10,     0,     1,     0,     0,     0,    19,
       4,     2,     0,     9,     3,    64,     6,    60,     0,    42,
       0,     0,     0,     0,    18,    21,     0,    48,    13,    17,
      16,    15,    14,     0,     0,    67,    80,    64,     0,     0,
      61,     0,     0,     0,     0,    82,    70,    62,    65,    68,
      69,    71,    72,    73,    74,    75,    76,     0,    20,    40,
       0,    41,    44,     8,    12,     0,     0,     0,     0,     0,
       0,    99,     2,     0,     0,     0,   119,   117,   121,     0,
     100,   110,   112,     0,     0,     0,    96,     0,     0,    63,
       0,     0,     0,    26,     0,     0,     0,    27,     0,    24,
      23,    25,     0,     0,    43,     0,     0,    46,     0,    47,
       0,    11,     0,     0,    98,    77,     0,     0,     0,     0,
     124,     0,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    66,     0,     0,     0,     0,     0,     0,     0,
      37,     0,     0,    22,     0,    39,    55,    55,    10,    10,
       0,    81,     0,     0,    87,   126,     0,   122,     0,     0,
     111,   105,   104,   103,   102,   101,   106,    86,   107,   108,
     109,   113,   114,   116,   115,    88,     0,     0,     0,    93,
       0,    83,     0,     0,     0,     0,     0,    35,    36,     0,
       0,    45,     0,    52,     0,     0,     0,     0,    79,    97,
       0,   125,   120,   118,     0,    84,     0,     0,    91,    92,
       0,     0,     0,    28,    30,    29,     0,     0,    33,    54,
       0,     0,     0,    57,     0,    49,     7,    51,    78,    85,
       0,     0,     0,     0,     0,    31,     0,    38,     0,     0,
      53,     0,    50,    95,    94,     0,     0,    32,    34,     0,
      59,    56,    89,    90,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    77,     2,     3,     7,   205,   206,     9,    13,    78,
      19,    24,    25,    98,    99,   100,   101,   149,   150,    60,
      27,    61,    62,    63,   107,   108,   109,   110,   203,   232,
     233,    16,    46,    22,    47,    48,    49,    50,    51,   215,
      52,    53,    54,    55,   188,   189,    56,   113,   114,    80,
      81,    82
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -138
static const yytype_int16 yypact[] =
{
      50,    74,    54,    39,    78,  -138,    97,   104,    72,    69,
    -138,  -138,   126,    97,  -138,  -138,  -138,  -138,   137,   100,
     141,   164,   197,   167,   137,  -138,   158,  -138,  -138,  -138,
    -138,  -138,  -138,   151,   141,  -138,    71,  -138,   107,   107,
    -138,   107,   171,   142,   172,   173,  -138,   176,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,     9,  -138,  -138,
      22,   158,  -138,    47,  -138,   185,   204,   107,   107,   107,
     221,   367,    13,   165,   107,   165,   198,   199,  -138,   322,
      25,    76,  -138,   157,   348,   200,  -138,   263,   107,  -138,
     177,   215,   216,  -138,   218,   184,   158,   224,   211,  -138,
    -138,  -138,     9,   231,  -138,   235,   237,  -138,   225,  -138,
     229,  -138,   227,     5,   108,   108,    20,   107,   248,   107,
    -138,   353,  -138,   107,   107,   156,   156,   156,   156,   156,
     156,   246,   156,   156,   156,   165,   165,   165,   165,   246,
      98,   107,  -138,    16,   250,   252,   254,   260,    11,    35,
    -138,    67,   261,  -138,   243,  -138,   253,   253,    39,    39,
     107,  -138,   107,   251,   108,  -138,    36,  -138,    65,   112,
    -138,    25,    25,    25,    25,    25,    25,   239,    76,    76,
      76,  -138,  -138,  -138,  -138,  -138,   256,   257,    89,  -138,
     298,  -138,   267,   236,   233,   238,   241,  -138,  -138,     9,
      97,  -138,    10,  -138,   264,   268,    72,   271,   108,   108,
     107,  -138,  -138,  -138,   246,  -138,   246,   246,  -138,  -138,
     107,   107,     7,  -138,  -138,  -138,   269,   272,  -138,  -138,
     158,   102,    62,  -138,    11,  -138,  -138,  -138,   108,  -138,
     277,   279,   308,   314,   270,  -138,     9,  -138,   128,    11,
    -138,    12,  -138,  -138,  -138,   246,   246,  -138,  -138,    11,
    -138,  -138,  -138,  -138,  -138
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -138,    -6,  -138,  -138,  -138,   119,   306,  -138,  -138,   -12,
    -138,  -138,   286,   -96,  -137,  -138,  -138,  -138,   152,   -92,
    -138,  -138,   273,  -138,  -138,  -138,  -138,  -138,   162,  -138,
      82,   129,    -7,   276,  -122,   259,  -138,  -138,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,   150,  -138,   -54,   -36,   258,
      46,   -63
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -112
static const yytype_int16 yytable[] =
{
      12,    17,    79,    83,   151,    84,   154,    21,    33,   177,
     120,   196,   122,    11,    59,    11,    59,   185,   118,   244,
     161,    90,    65,    90,   162,   229,   125,   126,   127,   128,
     129,   191,   115,   116,   143,   162,   132,   133,   121,    59,
     102,   103,   125,   126,   127,   128,   129,   134,   245,   130,
      91,    97,    91,     1,     5,   119,    92,   151,    92,    93,
      94,    93,    94,   163,    95,   130,   230,    96,   230,   168,
     169,   197,   181,   182,   183,   184,    66,   250,     4,   211,
     212,   164,   251,   166,   162,   199,   103,    67,    68,   135,
     136,     6,   239,   186,   240,   241,    97,   252,    10,   137,
     138,    11,   186,   227,   105,   190,   106,    15,    71,    14,
     231,    72,   260,    69,   125,   126,   127,   128,   129,    73,
     249,   103,   264,    74,   208,   218,   209,   213,   187,    18,
      28,   162,    20,   262,   263,    29,    30,   130,   248,    28,
      31,    23,    97,    32,    29,    30,   259,   103,    28,    31,
     258,    75,    32,    29,    30,    76,    26,   170,    31,   231,
      72,    32,    59,   125,   126,   127,   128,   129,    73,    72,
      34,    64,    74,    57,   238,    85,   187,    73,   178,   179,
     180,    74,    28,    86,   242,   243,   130,    29,    30,    88,
      87,   139,    31,    97,   228,    32,    89,    28,    35,    17,
      75,    36,    29,    30,    76,   111,    28,    31,   112,    75,
      32,    29,    30,    76,   123,   124,    31,   141,   144,    32,
     145,   146,    35,   147,    37,    36,   148,    38,    97,   152,
      39,   153,    15,    40,    41,   155,    42,    43,    44,   156,
      97,   157,   117,    97,   160,   158,    45,    35,    37,   159,
      36,    38,   165,    97,    39,   192,    15,   193,    41,   194,
      42,    43,    44,   201,    35,   195,   200,    36,   210,   202,
      45,   214,   222,    37,   216,   217,    38,   223,   207,    39,
     224,    15,   234,    41,   226,    42,    43,    44,   235,   225,
      37,   237,   247,    38,   246,    45,    39,   253,    15,   254,
      41,   198,    42,    43,   125,   126,   127,   128,   129,     8,
      58,   257,    45,    70,   125,   126,   127,   128,   129,   204,
     125,   126,   127,   128,   129,     0,   220,   130,   125,   126,
     127,   128,   129,   261,   104,   236,   221,   130,   219,     0,
       0,     0,   255,   130,     0,     0,   142,     0,   256,     0,
       0,   130,     0,   131,   125,   126,   127,   128,   129,   125,
     126,   127,   128,   129,     0,     0,     0,     0,   167,     0,
       0,     0,     0,   140,     0,     0,     0,   130,  -111,  -111,
    -111,  -111,   130,   171,   172,   173,   174,   175,   176,  -111,
    -111,  -111
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-138)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       6,     8,    38,    39,    96,    41,   102,    13,    20,   131,
      73,   148,    75,     4,     4,     4,     4,   139,     5,    12,
      15,    12,    34,    12,    19,    15,     6,     7,     8,     9,
      10,    15,    68,    69,    88,    19,    11,    12,    74,     4,
      18,    19,     6,     7,     8,     9,    10,    22,    41,    29,
      41,    57,    41,     3,     0,    42,    47,   149,    47,    50,
      51,    50,    51,    43,    55,    29,    56,    58,    56,   123,
     124,    36,   135,   136,   137,   138,     5,    15,     4,    43,
      15,   117,    20,   119,    19,    18,    19,    16,    17,    13,
      14,    52,   214,     4,   216,   217,   102,   234,    20,    23,
      24,     4,     4,   199,    57,   141,    59,    35,     1,     5,
     202,     4,   249,    42,     6,     7,     8,     9,    10,    12,
      18,    19,   259,    16,   160,    36,   162,    15,   140,    60,
      41,    19,     6,   255,   256,    46,    47,    29,   230,    41,
      51,     4,   148,    54,    46,    47,    18,    19,    41,    51,
     246,    44,    54,    46,    47,    48,    56,     1,    51,   251,
       4,    54,     4,     6,     7,     8,     9,    10,    12,     4,
       6,    20,    16,     6,   210,     4,   188,    12,   132,   133,
     134,    16,    41,    41,   220,   221,    29,    46,    47,    16,
      18,    34,    51,   199,   200,    54,    20,    41,     1,   206,
      44,     4,    46,    47,    48,    20,    41,    51,     4,    44,
      54,    46,    47,    48,    16,    16,    51,    17,    41,    54,
       5,     5,     1,     5,    27,     4,    42,    30,   234,     5,
      33,    20,    35,    36,    37,     4,    39,    40,    41,     4,
     246,     4,    21,   249,    17,    20,    49,     1,    27,    20,
       4,    30,     4,   259,    33,     5,    35,     5,    37,     5,
      39,    40,    41,    20,     1,     5,     5,     4,    17,    16,
      49,    32,     5,    27,    18,    18,    30,    41,   159,    33,
      47,    35,    18,    37,    43,    39,    40,    41,    20,    51,
      27,    20,    20,    30,    25,    49,    33,    20,    35,    20,
      37,   149,    39,    40,     6,     7,     8,     9,    10,     3,
      24,    41,    49,    37,     6,     7,     8,     9,    10,   157,
       6,     7,     8,     9,    10,    -1,    28,    29,     6,     7,
       8,     9,    10,   251,    61,   206,    38,    29,   188,    -1,
      -1,    -1,    34,    29,    -1,    -1,    87,    -1,    34,    -1,
      -1,    29,    -1,    31,     6,     7,     8,     9,    10,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    11,    12,
      13,    14,    29,   125,   126,   127,   128,   129,   130,    22,
      23,    24
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    63,    64,     4,     0,    52,    65,    67,    68,
      20,     4,    62,    69,     5,    35,    92,    93,    60,    71,
       6,    62,    94,     4,    72,    73,    56,    81,    41,    46,
      47,    51,    54,    70,     6,     1,     4,    27,    30,    33,
      36,    37,    39,    40,    41,    49,    93,    95,    96,    97,
      98,    99,   101,   102,   103,   104,   107,     6,    73,     4,
      80,    82,    83,    84,    20,    70,     5,    16,    17,    42,
      94,     1,     4,    12,    16,    44,    48,    62,    70,   109,
     110,   111,   112,   109,   109,     4,    41,    18,    16,    20,
      12,    41,    47,    50,    51,    55,    58,    62,    74,    75,
      76,    77,    18,    19,    83,    57,    59,    85,    86,    87,
      88,    20,     4,   108,   109,   109,   109,    21,     5,    42,
     112,   109,   112,    16,    16,     6,     7,     8,     9,    10,
      29,    31,    11,    12,    22,    13,    14,    23,    24,    34,
      25,    17,    96,   108,    41,     5,     5,     5,    42,    78,
      79,    80,     5,    20,    74,     4,     4,     4,    20,    20,
      17,    15,    19,    43,   109,     4,   109,    15,   108,   108,
       1,   110,   110,   110,   110,   110,   110,    95,   111,   111,
     111,   112,   112,   112,   112,    95,     4,    70,   105,   106,
     109,    15,     5,     5,     5,     5,    75,    36,    79,    18,
       5,    20,    16,    89,    89,    66,    67,    66,   109,   109,
      17,    43,    15,    15,    32,   100,    18,    18,    36,   106,
      28,    38,     5,    41,    47,    51,    43,    74,    62,    15,
      56,    80,    90,    91,    18,    20,    92,    20,   109,    95,
      95,    95,   109,   109,    12,    41,    25,    20,    80,    18,
      15,    20,    75,    20,    20,    34,    34,    41,    74,    18,
      75,    91,    95,    95,    75
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
        case 2:
/* Line 1787 of yacc.c  */
#line 87 "JSint.y"
    { (yyval.debug) = (yyvsp[(1) - (1)].debug); }
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 89 "JSint.y"
    { ast_root = (yyvsp[(2) - (3)].ast_Program); }
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 90 "JSint.y"
    {}
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 90 "JSint.y"
    {}
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 93 "JSint.y"
    { (yyval.ast_Program) = (yyvsp[(1) - (2)].ast_Program); (yyval.ast_Program)->routine_body = (yyvsp[(2) - (2)].ast_StatementList); /*$$->print_node("", true, true);*/ }
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 97 "JSint.y"
    { (yyval.ast_Program) = (yyvsp[(1) - (2)].ast_Program); (yyval.ast_Program)->routine_body = (yyvsp[(2) - (2)].ast_StatementList); }
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 102 "JSint.y"
    { 
		(yyval.ast_Program) = new ast::Program(nullptr, (yyvsp[(1) - (4)].ast_ConstDeclList), (yyvsp[(2) - (4)].ast_TypeDeclList), (yyvsp[(3) - (4)].ast_VarDeclList), (yyvsp[(4) - (4)].ast_RoutineList), nullptr); 
	}
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 111 "JSint.y"
    { (yyval.ast_ConstDeclList) = (yyvsp[(2) - (2)].ast_ConstDeclList); }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 112 "JSint.y"
    { (yyval.ast_ConstDeclList) = new ast::ConstDeclList(); }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 116 "JSint.y"
    { (yyval.ast_ConstDeclList) = (yyvsp[(1) - (5)].ast_ConstDeclList); (yyvsp[(1) - (5)].ast_ConstDeclList)->push_back(new ast::ConstDecl(new ast::Identifier((yyvsp[(2) - (5)].debug)), (yyvsp[(4) - (5)].ast_ConstValue))); }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 117 "JSint.y"
    { (yyval.ast_ConstDeclList) = new ast::ConstDeclList(); (yyval.ast_ConstDeclList)->push_back(new ast::ConstDecl(new ast::Identifier((yyvsp[(1) - (4)].debug)), (yyvsp[(3) - (4)].ast_ConstValue))); }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 121 "JSint.y"
    { (yyval.ast_ConstValue) = new ast::IntegerType(atoi((yyvsp[(1) - (1)].debug))); (yyval.ast_ConstValue)->debug = (yyvsp[(1) - (1)].debug); }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 122 "JSint.y"
    { (yyval.ast_ConstValue) = new ast::RealType(atof((yyvsp[(1) - (1)].debug))); (yyval.ast_ConstValue)->debug = (yyvsp[(1) - (1)].debug); }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 123 "JSint.y"
    { (yyval.ast_ConstValue) = new ast::CharType((yyvsp[(1) - (1)].debug)); (yyval.ast_ConstValue)->debug = (yyvsp[(1) - (1)].debug); }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 125 "JSint.y"
    { (yyval.ast_ConstValue) = new ast::BooleanType((yyvsp[(1) - (1)].debug)); }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 126 "JSint.y"
    { (yyval.ast_ConstValue) = new ast::IntegerType(32767); }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 131 "JSint.y"
    { (yyval.ast_TypeDeclList) = (yyvsp[(2) - (2)].ast_TypeDeclList); }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 132 "JSint.y"
    { (yyval.ast_TypeDeclList) = new ast::TypeDeclList(); }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 136 "JSint.y"
    { (yyval.ast_TypeDeclList) = (yyvsp[(1) - (2)].ast_TypeDeclList); (yyvsp[(1) - (2)].ast_TypeDeclList)->push_back((yyvsp[(2) - (2)].ast_TypeConst)); }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 137 "JSint.y"
    { (yyval.ast_TypeDeclList) = new ast::TypeDeclList(); (yyval.ast_TypeDeclList)->push_back((yyvsp[(1) - (1)].ast_TypeConst)); }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 141 "JSint.y"
    { (yyval.ast_TypeConst) = new ast::TypeConst(new ast::Identifier((yyvsp[(1) - (4)].debug)), (yyvsp[(3) - (4)].ast_TypeDecl));  }
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 145 "JSint.y"
    { (yyval.ast_TypeDecl) = (yyvsp[(1) - (1)].ast_TypeDecl); DBMSG("array here"); }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 146 "JSint.y"
    { (yyval.ast_TypeDecl) = (yyvsp[(1) - (1)].ast_TypeDecl); DBMSG("arary 1");}
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 147 "JSint.y"
    { (yyval.ast_TypeDecl) = (yyvsp[(1) - (1)].ast_TypeDecl); }
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 151 "JSint.y"
    { (yyval.ast_TypeDecl) = new ast::TypeDecl((yyvsp[(1) - (1)].debug)); }
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 152 "JSint.y"
    { (yyval.ast_TypeDecl) = new ast::TypeDecl(std::string((yyvsp[(1) - (1)].debug))); DBMSG("parse name " << (yyvsp[(1) - (1)].debug));}
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 154 "JSint.y"
    { (yyval.ast_TypeDecl) = new ast::TypeDecl(new ast::RangeType(atoi((yyvsp[(1) - (4)].debug)), atoi((yyvsp[(4) - (4)].debug)))); DBMSG("reach here, + to +");}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 155 "JSint.y"
    { (yyval.ast_TypeDecl) = new ast::TypeDecl(new ast::RangeType(*(yyvsp[(1) - (4)].debug),*(yyvsp[(4) - (4)].debug))); }
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 156 "JSint.y"
    { (yyval.ast_TypeDecl) = new ast::TypeDecl(new ast::RangeType(std::string((yyvsp[(1) - (4)].debug)) == "true" ? 1 : 0, std::string((yyvsp[(4) - (4)].debug)) == "true" ? 1 : 0)); }
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 157 "JSint.y"
    { (yyval.ast_TypeDecl) = new ast::TypeDecl(new ast::RangeType(-atoi((yyvsp[(1) - (5)].debug)), atoi((yyvsp[(5) - (5)].debug)))); }
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 158 "JSint.y"
    { (yyval.ast_TypeDecl) = new ast::TypeDecl(new ast::RangeType(-atoi((yyvsp[(1) - (6)].debug)), -atoi((yyvsp[(2) - (6)].debug)))); }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 159 "JSint.y"
    { (yyval.ast_TypeDecl) = new ast::TypeDecl(new ast::RangeType(std::string((yyvsp[(1) - (4)].debug)), std::string((yyvsp[(4) - (4)].debug)))); }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 163 "JSint.y"
    { (yyval.ast_TypeDecl) = new ast::TypeDecl(new ast::ArrayType((yyvsp[(3) - (6)].ast_TypeDecl), (yyvsp[(6) - (6)].ast_TypeDecl))); std::cout << "finished here" << std::endl;}
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 167 "JSint.y"
    { (yyval.ast_TypeDecl) = new ast::TypeDecl(new ast::RecordType((yyvsp[(2) - (3)].ast_FieldDeclList))); }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 171 "JSint.y"
    { (yyval.ast_FieldDeclList) = (yyvsp[(1) - (2)].ast_FieldDeclList); (yyvsp[(1) - (2)].ast_FieldDeclList)->insert((yyvsp[(1) - (2)].ast_FieldDeclList)->end(), (yyvsp[(2) - (2)].ast_FieldDeclList)->begin(), (yyvsp[(2) - (2)].ast_FieldDeclList)->end()); }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 172 "JSint.y"
    { (yyval.ast_FieldDeclList) = (yyvsp[(1) - (1)].ast_FieldDeclList); }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 176 "JSint.y"
    { (yyval.ast_FieldDeclList) = new ast::FieldDeclList(); for(auto name : *((yyvsp[(1) - (4)].ast_NameList))) (yyval.ast_FieldDeclList)->push_back(new ast::FieldDecl(new ast::Identifier(name),(yyvsp[(3) - (4)].ast_TypeDecl))); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 180 "JSint.y"
    { (yyval.ast_NameList) = (yyvsp[(1) - (3)].ast_NameList); (yyval.ast_NameList)->push_back((yyvsp[(3) - (3)].debug)); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 181 "JSint.y"
    { (yyval.ast_NameList) = new ast::NameList(); (yyval.ast_NameList)->push_back((yyvsp[(1) - (1)].debug)); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 185 "JSint.y"
    { (yyval.ast_VarDeclList) = (yyvsp[(2) - (2)].ast_VarDeclList); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 186 "JSint.y"
    { (yyval.ast_VarDeclList) = new ast::VarDeclList(); }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 190 "JSint.y"
    { (yyval.ast_VarDeclList) = (yyvsp[(1) - (2)].ast_VarDeclList); (yyvsp[(1) - (2)].ast_VarDeclList)->insert((yyvsp[(1) - (2)].ast_VarDeclList)->end(), (yyvsp[(2) - (2)].ast_VarDeclList)->begin(), (yyvsp[(2) - (2)].ast_VarDeclList)->end()); }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 191 "JSint.y"
    { (yyval.ast_VarDeclList) = (yyvsp[(1) - (1)].ast_VarDeclList); }
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 195 "JSint.y"
    { (yyval.ast_VarDeclList) = new ast::VarDeclList(); for(auto name : *((yyvsp[(1) - (4)].ast_NameList))) (yyval.ast_VarDeclList)->push_back(new ast::VarDecl(new ast::Identifier(name), (yyvsp[(3) - (4)].ast_TypeDecl))); }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 199 "JSint.y"
    { (yyval.ast_RoutineList) = (yyvsp[(1) - (2)].ast_RoutineList); (yyvsp[(1) - (2)].ast_RoutineList)->push_back((yyvsp[(2) - (2)].ast_Routine)); }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 200 "JSint.y"
    { (yyval.ast_RoutineList) = (yyvsp[(1) - (2)].ast_RoutineList); (yyvsp[(1) - (2)].ast_RoutineList)->push_back((yyvsp[(2) - (2)].ast_Routine)); }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 201 "JSint.y"
    { (yyval.ast_RoutineList) = new ast::RoutineList(); }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 205 "JSint.y"
    { (yyval.ast_Routine) = new ast::Routine((yyvsp[(1) - (4)].ast_Routine), (yyvsp[(3) - (4)].ast_Program)); }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 209 "JSint.y"
    { (yyval.ast_Routine) = new ast::Routine(ast::Routine::RoutineType::function, new ast::Identifier((yyvsp[(2) - (5)].debug)), (yyvsp[(3) - (5)].ast_VarDeclList), (yyvsp[(5) - (5)].ast_TypeDecl)); }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 213 "JSint.y"
    { (yyval.ast_Routine) = new ast::Routine((yyvsp[(1) - (4)].ast_Routine), (yyvsp[(3) - (4)].ast_Program)); }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 217 "JSint.y"
    { (yyval.ast_Routine) = new ast::Routine(ast::Routine::RoutineType::procedure, new ast::Identifier((yyvsp[(2) - (3)].debug)), (yyvsp[(3) - (3)].ast_VarDeclList), nullptr); }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 221 "JSint.y"
    { (yyval.ast_VarDeclList) = (yyvsp[(2) - (3)].ast_VarDeclList); }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 222 "JSint.y"
    { (yyval.ast_VarDeclList) = new ast::VarDeclList(); }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 223 "JSint.y"
    { (yyval.ast_VarDeclList) = new ast::VarDeclList(); }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 227 "JSint.y"
    { (yyval.ast_VarDeclList) = (yyvsp[(1) - (3)].ast_VarDeclList); (yyvsp[(1) - (3)].ast_VarDeclList)->insert((yyvsp[(1) - (3)].ast_VarDeclList)->end(), (yyvsp[(3) - (3)].ast_VarDeclList)->begin(), (yyvsp[(3) - (3)].ast_VarDeclList)->end()); }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 228 "JSint.y"
    { (yyval.ast_VarDeclList) = (yyvsp[(1) - (1)].ast_VarDeclList); }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 232 "JSint.y"
    { (yyval.ast_VarDeclList) = new ast::VarDeclList(); for(auto name: *((yyvsp[(2) - (4)].ast_NameList))) (yyval.ast_VarDeclList)->push_back(new ast::VarDecl(new ast::Identifier(name), (yyvsp[(4) - (4)].ast_TypeDecl))); }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 233 "JSint.y"
    { (yyval.ast_VarDeclList) = new ast::VarDeclList(); for(auto name: *((yyvsp[(1) - (3)].ast_NameList))) (yyval.ast_VarDeclList)->push_back(new ast::VarDecl(new ast::Identifier(name), (yyvsp[(3) - (3)].ast_TypeDecl))); }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 237 "JSint.y"
    { (yyval.ast_StatementList) = (yyvsp[(1) - (1)].ast_StatementList); }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 241 "JSint.y"
    { (yyval.ast_StatementList) = (yyvsp[(2) - (3)].ast_StatementList); }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 245 "JSint.y"
    {yyerror("expected ';' at the end of the last line"); }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 246 "JSint.y"
    { (yyval.ast_StatementList) = (yyvsp[(1) - (3)].ast_StatementList);(yyval.ast_StatementList)->getlist()->push_back((yyvsp[(2) - (3)].ast_Statement));}
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 247 "JSint.y"
    { (yyval.ast_StatementList) = new ast::StatementList(); }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 251 "JSint.y"
    { (yyval.ast_Statement) = (yyvsp[(1) - (1)].ast_Statement); }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 252 "JSint.y"
    { 
		(yyval.ast_Statement) = new ast::LabelStmt(atoi((yyvsp[(1) - (3)].debug)),(yyvsp[(3) - (3)].ast_Statement));
	}
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 258 "JSint.y"
    { (yyval.ast_Statement) = (ast::Statement *)(yyvsp[(1) - (1)].ast_AssignmentStmt); }
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 259 "JSint.y"
    { (yyval.ast_Statement) = (ast::Statement *) (yyvsp[(1) - (1)].ast_Statement); }
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 260 "JSint.y"
    { (yyval.ast_Statement) = (yyvsp[(1) - (1)].ast_StatementList);}
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 261 "JSint.y"
    { (yyval.ast_Statement) = (ast::Statement *)(yyvsp[(1) - (1)].ast_Statement);}
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 262 "JSint.y"
    { (yyval.ast_Statement) = (ast::Statement *)(yyvsp[(1) - (1)].ast_Statement);}
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 263 "JSint.y"
    { (yyval.ast_Statement) = (ast::Statement *)(yyvsp[(1) - (1)].ast_Statement);}
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 264 "JSint.y"
    { (yyval.ast_Statement) = (ast::Statement *)(yyvsp[(1) - (1)].ast_Statement);}
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 265 "JSint.y"
    { (yyval.ast_Statement) = (ast::Statement *)(yyvsp[(1) - (1)].ast_Statement);}
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 266 "JSint.y"
    { (yyval.ast_Statement) = (ast::Statement *)(yyvsp[(1) - (1)].ast_Statement);}
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 271 "JSint.y"
    { (yyval.ast_AssignmentStmt) = new ast::AssignmentStmt(new ast::Identifier((yyvsp[(1) - (3)].debug)), (yyvsp[(3) - (3)].ast_Expression)); }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 272 "JSint.y"
    { (yyval.ast_AssignmentStmt) = new ast::AssignmentStmt(new ast::ArrayRef(new ast::Identifier((yyvsp[(1) - (6)].debug)), (yyvsp[(3) - (6)].ast_Expression)), (yyvsp[(6) - (6)].ast_Expression)); }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 273 "JSint.y"
    { (yyval.ast_AssignmentStmt) = new ast::AssignmentStmt(new ast::RecordRef(new ast::Identifier((yyvsp[(1) - (5)].debug)), new ast::Identifier((yyvsp[(3) - (5)].debug))), (yyvsp[(5) - (5)].ast_Expression)); }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 277 "JSint.y"
    { (yyval.ast_Statement) = new ast::ProcCall(new ast::Identifier((yyvsp[(1) - (1)].debug))); }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 278 "JSint.y"
    { (yyval.ast_Statement) = new ast::ProcCall(new ast::Identifier((yyvsp[(1) - (4)].debug)), (yyvsp[(3) - (4)].ast_ExpressionList)); }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 279 "JSint.y"
    { (yyval.ast_Statement) = new ast::SysProcCall(new ast::Identifier((yyvsp[(1) - (1)].debug))); }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 280 "JSint.y"
    { (yyval.ast_Statement) = new ast::SysProcCall(new ast::Identifier((yyvsp[(1) - (4)].debug)), (yyvsp[(3) - (4)].ast_ExpressionList)); }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 285 "JSint.y"
    { (yyval.ast_Statement) = (ast::Statement*)new ast::IfStmt((yyvsp[(2) - (5)].ast_Expression),(yyvsp[(4) - (5)].ast_Statement),(yyvsp[(5) - (5)].ast_Statement));}
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 289 "JSint.y"
    { (yyval.ast_Statement) = (yyvsp[(2) - (2)].ast_Statement);}
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 290 "JSint.y"
    { (yyval.ast_Statement) = nullptr;}
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 294 "JSint.y"
    { (yyval.ast_Statement) = (ast::Statement*)new ast::RepeatStmt((yyvsp[(4) - (4)].ast_Expression),(yyvsp[(2) - (4)].ast_StatementList));}
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 297 "JSint.y"
    { (yyval.ast_Statement) = (ast::Statement*)new ast::WhileStmt((yyvsp[(2) - (4)].ast_Expression),(yyvsp[(4) - (4)].ast_Statement));}
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 300 "JSint.y"
    {
		(yyval.ast_Statement) = new ast::ForStmt(new ast::Identifier((yyvsp[(2) - (8)].debug)), (yyvsp[(4) - (8)].ast_Expression),(yyvsp[(6) - (8)].ast_Expression),1,(yyvsp[(8) - (8)].ast_Statement)); 
	}
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 303 "JSint.y"
    { 
		(yyval.ast_Statement) = new ast::ForStmt(new ast::Identifier((yyvsp[(2) - (8)].debug)), (yyvsp[(4) - (8)].ast_Expression),(yyvsp[(6) - (8)].ast_Expression),0,(yyvsp[(8) - (8)].ast_Statement)); 
	}
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 308 "JSint.y"
    { (yyval.ast_Statement) = new ast::SwitchStmt((yyvsp[(2) - (5)].ast_Expression),(yyvsp[(4) - (5)].ast_CaseList));}
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 311 "JSint.y"
    { (yyval.ast_CaseList)->push_back((yyvsp[(2) - (2)].ast_CaseStmt));}
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 312 "JSint.y"
    { (yyval.ast_CaseList)= new ast::CaseList;(yyval.ast_CaseList)->push_back((yyvsp[(1) - (1)].ast_CaseStmt));}
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 315 "JSint.y"
    { (yyval.ast_CaseStmt) = new ast::CaseStmt((yyvsp[(1) - (4)].ast_ConstValue),(yyvsp[(3) - (4)].ast_Statement));}
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 316 "JSint.y"
    { (yyval.ast_CaseStmt) = new ast::CaseStmt(new ast::Identifier((yyvsp[(1) - (4)].debug)),(yyvsp[(3) - (4)].ast_Statement));}
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 319 "JSint.y"
    { (yyval.ast_Statement) = new ast::GotoStmt(atoi((yyvsp[(2) - (2)].debug)));}
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 323 "JSint.y"
    { (yyval.ast_ExpressionList) = (yyvsp[(1) - (3)].ast_ExpressionList); (yyvsp[(1) - (3)].ast_ExpressionList)->push_back((yyvsp[(3) - (3)].ast_Expression)); }
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 324 "JSint.y"
    { (yyval.ast_ExpressionList) = new ast::ExpressionList(); (yyval.ast_ExpressionList)->push_back((yyvsp[(1) - (1)].ast_Expression)); }
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 328 "JSint.y"
    { (yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression); }
    break;

  case 101:
/* Line 1787 of yacc.c  */
#line 329 "JSint.y"
    {(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression), ast::BinaryOperator::OpType::ge, (yyvsp[(3) - (3)].ast_Expression));}
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 330 "JSint.y"
    {(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression), ast::BinaryOperator::OpType::gt, (yyvsp[(3) - (3)].ast_Expression));}
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 331 "JSint.y"
    {(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression), ast::BinaryOperator::OpType::le, (yyvsp[(3) - (3)].ast_Expression));}
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 332 "JSint.y"
    {(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression), ast::BinaryOperator::OpType::lt, (yyvsp[(3) - (3)].ast_Expression));}
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 333 "JSint.y"
    {(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression), ast::BinaryOperator::OpType::eq, (yyvsp[(3) - (3)].ast_Expression));}
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 334 "JSint.y"
    {(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression), ast::BinaryOperator::OpType::ne, (yyvsp[(3) - (3)].ast_Expression));}
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 338 "JSint.y"
    {(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression), ast::BinaryOperator::OpType::plus, (yyvsp[(3) - (3)].ast_Expression)); }
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 339 "JSint.y"
    {(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression), ast::BinaryOperator::OpType::minus, (yyvsp[(3) - (3)].ast_Expression));}
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 340 "JSint.y"
    {(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression), ast::BinaryOperator::OpType::bit_or, (yyvsp[(3) - (3)].ast_Expression));}
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 341 "JSint.y"
    { (yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression); }
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 346 "JSint.y"
    { (yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression); }
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 347 "JSint.y"
    {(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression), ast::BinaryOperator::OpType::mul, (yyvsp[(3) - (3)].ast_Expression));}
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 348 "JSint.y"
    {(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression), ast::BinaryOperator::OpType::div, (yyvsp[(3) - (3)].ast_Expression));}
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 349 "JSint.y"
    {(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression), ast::BinaryOperator::OpType::mod, (yyvsp[(3) - (3)].ast_Expression));}
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 350 "JSint.y"
    {(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression), ast::BinaryOperator::OpType::bit_and, (yyvsp[(3) - (3)].ast_Expression));}
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 354 "JSint.y"
    { (yyval.ast_Expression) = new ast::Identifier((yyvsp[(1) - (1)].debug)); }
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 355 "JSint.y"
    { (yyval.ast_Expression) = new ast::FuncCall(new ast::Identifier((yyvsp[(1) - (4)].debug)), (yyvsp[(3) - (4)].ast_ExpressionList)); }
    break;

  case 119:
/* Line 1787 of yacc.c  */
#line 356 "JSint.y"
    { (yyval.ast_Expression) = new ast::SysFuncCall(new ast::Identifier((yyvsp[(1) - (1)].debug))); }
    break;

  case 120:
/* Line 1787 of yacc.c  */
#line 357 "JSint.y"
    { (yyval.ast_Expression) = new ast::SysFuncCall(new ast::Identifier((yyvsp[(1) - (4)].debug)), (yyvsp[(3) - (4)].ast_ExpressionList)); }
    break;

  case 121:
/* Line 1787 of yacc.c  */
#line 358 "JSint.y"
    { (yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_ConstValue); }
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 359 "JSint.y"
    { (yyval.ast_Expression) = (yyvsp[(2) - (3)].ast_Expression); }
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 360 "JSint.y"
    { (yyval.ast_Expression) = new ast::BinaryOperator(new ast::BooleanType("true"), ast::BinaryOperator::OpType::bit_xor, (yyvsp[(2) - (2)].ast_Expression));}
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 361 "JSint.y"
    { (yyval.ast_Expression) = new ast::BinaryOperator(new ast::IntegerType(0), ast::BinaryOperator::OpType::minus, (yyvsp[(2) - (2)].ast_Expression));}
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 362 "JSint.y"
    { (yyval.ast_Expression) = new ast::ArrayRef(new ast::Identifier((yyvsp[(1) - (4)].debug)), (yyvsp[(3) - (4)].ast_Expression)); }
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 363 "JSint.y"
    { (yyval.ast_Expression) = new ast::RecordRef(new ast::Identifier((yyvsp[(1) - (3)].debug)), new ast::Identifier((yyvsp[(3) - (3)].debug))); }
    break;


/* Line 1787 of yacc.c  */
#line 2447 "parser.cpp"
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


/* Line 2050 of yacc.c  */
#line 365 "JSint.y"



