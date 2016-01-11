/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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
     BIT_XOR = 326,
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
/* Tokens.  */
#define DECIMAL_LITERAL 258
#define HEX_INTEGER_LITERAL 259
#define STRING_LITERAL 260
#define BOOLEAN_LITERAL 261
#define NULL_LITERAL 262
#define SLASHASSIGN 263
#define SLASH 264
#define JEOF 265
#define IDENTIFIER_NAME 266
#define THIS 267
#define NEW 268
#define DELETE 269
#define VOID 270
#define TYPEOF 271
#define INSTANCEOF 272
#define IN 273
#define VAR 274
#define IF 275
#define ELSE 276
#define DO 277
#define WHILE 278
#define FOR 279
#define CONTINUE 280
#define BREAK 281
#define RETURN 282
#define WITH 283
#define SWITCH 284
#define CASE 285
#define DEFAULT 286
#define THROW 287
#define TRY 288
#define CATCH 289
#define FINALLY 290
#define FUNCTION 291
#define IMPORT 292
#define LEFT_BRACKET 293
#define RIGHT_BRACKET 294
#define LEFT_PARE 295
#define RIGHT_PARE 296
#define LEFT_BRACE 297
#define RIGHT_BRACE 298
#define COMMA 299
#define DOT 300
#define COLON 301
#define SEMICOLON 302
#define PLUS 303
#define MINUS 304
#define MULTI 305
#define ASSIGN 306
#define PLUS_PLUS 307
#define MINUS_MINUS 308
#define TILDE 309
#define QUES 310
#define EXCLAM 311
#define PERCENT 312
#define LESS 313
#define GREATER 314
#define EQUAL 315
#define LSHIFT 316
#define RSHIFT 317
#define RRSHIFT 318
#define LESS_EQ 319
#define GREATER_EQ 320
#define NOT_EQUAL 321
#define ALWAYS_EQ 322
#define ALWAYS_NEQ 323
#define BIT_AND 324
#define BIT_OR 325
#define BIT_XOR 326
#define AND 327
#define OR 328
#define MULTI_ASG 329
#define MOD_ASG 330
#define PLUS_ASG 331
#define MINUS_ASG 332
#define LSHIFT_ASG 333
#define RSHIFT_ASG 334
#define LLSHIFT_ASG 335
#define BIT_AND_ASG 336
#define BIT_NOT_ASG 337
#define BIT_OR_ASG 338




/* Copy the first part of user declarations.  */
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
extern VarStack nowStack;
int yydebug = 1;
ast::Node* ast_root;
ast::BinaryOperator* noOp1Exp;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 18 "JSint.y"
{
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

	ast::Block*             ast_Block;
}
/* Line 193 of yacc.c.  */
#line 313 "parser.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 326 "parser.cpp"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  168
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1127

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  131
/* YYNRULES -- Number of rules.  */
#define YYNRULES  284
/* YYNRULES -- Number of states.  */
#define YYNSTATES  448

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
     771,   773,   776,   778,   780,   782,   786,   792,   794,   798,
     801,   805,   807,   811,   815
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
      -1,   209,    -1,   208,   209,    -1,     1,    -1,   203,    -1,
     172,    -1,    37,   211,    47,    -1,    37,   211,    45,    50,
      47,    -1,    11,    -1,   211,    45,    11,    -1,    19,   213,
      -1,    19,   213,    47,    -1,   214,    -1,   213,    44,   214,
      -1,    87,    46,    11,    -1,    87,    46,    11,   179,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   119,   119,   120,   121,   122,   126,   127,   131,   135,
     136,   143,   143,   144,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     164,   165,   166,   167,   168,   169,   177,   178,   179,   183,
     184,   185,   186,   187,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     209,   210,   215,   219,   220,   221,   222,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     248,   255,   258,   261,   264,   267,   278,   285,   288,   291,
     294,   304,   311,   314,   317,   320,   323,   333,   340,   343,
     346,   349,   352,   355,   358,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   379,   386,   389,   390,   391,   392,
     395,   398,   401,   404,   414,   421,   424,   425,   426,   427,
     430,   440,   447,   450,   451,   452,   453,   456,   466,   473,
     476,   477,   478,   479,   482,   492,   499,   502,   503,   504,
     505,   508,   518,   525,   528,   529,   530,   531,   534,   537,
     539,   540,   541,   546,   550,   551,   552,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   578,
     586,   589,   590,   591,   594,   595,   596,   600,   601,   602,
     603,   604,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   620,   624,   628,   632,   633,   634,   635,
     638,   639,   640,   641,   642,   643,   644,   645,   648,   651,
     652,   653,   654,   655,   656,   657,   658,   659,   660,   661,
     662,   663,   664,   665,   666,   667,   668,   669,   670,   671,
     672,   673,   674,   675,   676,   677,   678,   679,   680,   681,
     682,   683,   684,   685,   686,   687,   688,   689,   690,   691,
     692,   693,   694,   695,   696,   697,   698,   699,   700,   701,
     705,   727,   749,   750,   751,   754,   755,   756,   757,   758,
     759,   760,   761,   762,   763
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
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
  "BIT_OR", "BIT_XOR", "AND", "OR", "MULTI_ASG", "MOD_ASG", "PLUS_ASG",
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
  "JScriptVarDeclarationList", "JScriptVarDeclaration", 0
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
     208,   208,   208,   209,   209,   210,   210,   211,   211,   212,
     212,   213,   213,   214,   214
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
       1,     2,     1,     1,     1,     3,     5,     1,     3,     2,
       3,     1,     3,     3,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   272,     8,     9,    10,    11,    12,   268,    13,     2,
       0,    70,    71,    72,     0,     0,     0,     0,     0,   229,
     229,   184,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   216,    75,    76,    73,    74,    77,    78,    43,     7,
       5,     6,     3,    59,    36,    58,    62,    66,    81,    67,
       0,    87,    92,    98,   115,   125,   132,   139,   146,   153,
     158,   163,   180,   217,   274,   186,   188,   189,   191,   192,
     193,   194,   195,   197,   198,   199,   190,   200,   201,   273,
      43,     0,     0,   270,   196,   187,     0,     0,     5,    41,
     210,   206,   208,   279,   281,     0,     0,     0,     0,   231,
     230,   233,   234,   185,   235,     0,     0,   251,     0,     0,
       0,     0,     0,   277,     0,    17,    22,     0,     0,    21,
       0,     8,    10,    25,     5,     0,    29,     0,   204,     0,
      35,     0,     0,    49,   168,   166,    64,    65,   167,   169,
     170,   171,   172,   173,   174,   175,   176,   177,    63,     0,
      79,     0,    62,    68,    85,    90,    96,   113,   123,   130,
     137,   144,   151,     0,     0,   178,   218,    34,     1,   269,
     271,     0,    33,    32,    25,    31,    39,     0,     0,   211,
       0,   207,     0,   280,     0,     0,     0,     0,   184,    43,
      61,    60,    62,     0,   107,   118,   128,   135,   142,   149,
     156,   160,   165,   183,     0,    43,   232,   236,     0,     0,
     252,   202,     0,     0,   253,   255,   254,   259,   264,     0,
       0,     0,   262,     0,   275,    16,     0,    14,    23,    21,
      19,     4,    24,    26,     0,   205,   203,     0,     0,    42,
     250,    54,     0,    57,    46,   162,    83,    82,    84,     0,
      69,    88,    89,     0,    93,    94,    95,     0,   103,   104,
      99,   100,   101,   102,     0,   119,   120,   121,   122,     0,
     129,     0,   136,     0,   143,     0,   150,     0,   157,     0,
       0,   180,     0,    43,   283,   214,   210,   209,     0,   282,
       0,     0,     0,   210,     0,     0,     0,    35,    49,     0,
       0,   105,   116,   126,   133,   140,   147,   154,     0,   181,
     184,    34,     0,     0,     0,   258,   256,   260,     0,   261,
     266,     0,   278,     0,    15,    18,     0,    27,    30,     0,
      45,    53,    55,     0,     0,    48,    50,    80,    86,    91,
      97,   114,   124,   131,   138,   145,   152,     0,   179,   263,
      40,   284,   219,     0,   223,     0,   213,   184,     0,   184,
      47,   164,     0,   112,   108,   109,   110,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   237,     0,
     238,     0,   265,   267,   276,    20,    28,    44,     0,     0,
      52,   159,     0,   221,    62,    98,   215,     0,     0,     0,
       0,   106,   117,   127,   134,   141,   148,   155,     0,   182,
     184,     0,     0,   241,   239,     0,   244,     0,     0,    56,
      51,   220,   222,     0,   184,     0,     0,   228,   161,     0,
       0,   248,   240,   245,   242,     0,   257,     0,   227,   224,
       0,   246,   249,   243,     0,   225,   247,   226
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    38,    39,    88,    41,   117,   230,   326,    42,   125,
     233,   126,   127,    43,   190,    44,   176,   130,   239,    45,
     191,   244,   335,   336,   242,   332,    46,   193,    47,   148,
      48,    49,    50,    51,   150,   249,    52,   154,   253,    53,
     155,   257,    54,   156,   264,   195,   301,   368,    55,   157,
     196,   302,   269,    56,   158,   197,   303,   271,    57,   159,
     198,   304,   273,    58,   160,   199,   305,   275,    59,   161,
     200,   306,   277,    60,   162,   201,   307,   279,    61,   202,
      62,   361,   149,    63,   165,   204,   309,   104,   128,    65,
     129,    66,    91,    92,   295,   179,   356,    67,    68,    69,
      70,   101,    71,    72,    73,    74,    75,   380,   414,   415,
     416,   417,    76,    77,    78,   214,   215,   216,   112,    79,
      80,   219,   222,    81,    82,    83,    84,   114,    85,    93,
      94
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -364
static const yytype_int16 yypact[] =
{
     493,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,
     154,  -364,  -364,  -364,    42,   -19,   817,    15,    22,    29,
      29,  1071,    39,    45,  1071,    60,    31,    46,   871,  1071,
     601,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,
      65,  -364,  -364,    81,  -364,  -364,    16,  -364,  -364,    98,
    1071,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,
      75,  -364,   128,   134,  -364,  -364,  -364,  -364,  -364,  -364,
    -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,
    -364,   185,   655,  -364,  -364,  -364,    31,    30,  -364,  -364,
      55,    85,  -364,   124,  -364,  1071,   163,  1071,   925,  -364,
     141,  -364,  -364,  -364,   144,  1071,  1071,   146,   709,   143,
      17,   155,   157,  -364,   108,  -364,  -364,    83,   944,  -364,
     156,   158,   160,  -364,    65,   162,  -364,   164,   817,   166,
      43,   817,   998,  -364,  -364,  -364,  -364,  -364,  -364,  -364,
    -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  1071,
      13,  1071,    -8,  -364,   135,    78,    19,    77,   131,   140,
     133,   129,   139,  1071,  1071,  -364,  -364,    43,  -364,  -364,
    -364,   155,  -364,  -364,  -364,  -364,    81,   191,  1071,  -364,
      42,  -364,    42,  -364,   173,   175,   176,    42,  1071,  -364,
      81,  -364,    16,   198,  -364,  -364,  -364,  -364,  -364,  -364,
    -364,   165,  -364,  -364,   171,  -364,  -364,  -364,   181,   182,
    -364,  -364,   184,    60,  -364,   190,  -364,  -364,  -364,     2,
     157,   547,  -364,    14,  -364,  -364,   130,  -364,  -364,  -364,
     183,  -364,  -364,   186,  1071,  -364,  -364,  1071,    42,  -364,
    -364,  -364,   188,  -364,    80,  -364,  -364,  -364,  -364,  1071,
    -364,  -364,  -364,  1071,  -364,  -364,  -364,  1071,  -364,  -364,
    -364,  -364,  -364,  -364,  1071,  -364,  -364,  -364,  -364,  1071,
    -364,  1071,  -364,  1071,  -364,  1071,  -364,  1071,  -364,  1071,
     187,   128,   157,  -364,   192,  -364,   192,  -364,   196,  -364,
     817,  1071,   817,    -1,   132,   214,   189,     9,  -364,  1071,
    1071,     1,    77,   131,   140,   133,   129,   139,  1071,   193,
    1071,    11,   817,   202,    42,  -364,  -364,  -364,    42,   410,
    -364,   763,  -364,   201,  -364,   183,  1017,   159,  -364,   195,
    -364,  -364,   205,  1071,    42,  -364,  -364,  -364,  -364,  -364,
    -364,  -364,  -364,  -364,  -364,  -364,  -364,  1071,  -364,  -364,
      43,  -364,   224,   209,  -364,  1071,  -364,  1071,  1071,  1071,
      80,  -364,   211,  -364,  -364,  -364,  -364,  -364,  1071,  1071,
    1071,  1071,  1071,  1071,  1071,   208,  1071,   213,  -364,    93,
    -364,   215,  -364,  -364,  -364,  -364,  -364,  -364,  1071,   219,
    -364,  -364,   817,   216,    16,  -364,  -364,   217,   225,   226,
     817,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  1071,  -364,
    1071,  1071,   222,  -364,  -364,    93,  -364,     8,    60,  -364,
    -364,  -364,  -364,  1071,  1071,   817,   817,  -364,  -364,   228,
     227,   817,  -364,  -364,  -364,    18,  -364,   230,  -364,  -364,
     817,   817,  -364,  -364,   817,  -364,  -364,  -364
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -364,   167,  -364,     0,  -364,  -364,    47,   -17,  -364,  -364,
    -364,   -55,  -364,   264,  -364,  -364,  -364,   -70,  -364,  -364,
    -364,   -23,  -364,   -34,  -364,  -364,   -18,  -364,  -364,  -364,
     -42,  -364,   229,    24,  -364,  -364,    23,  -364,  -364,     6,
    -364,  -364,    20,  -364,  -364,   -90,  -364,  -364,    25,  -364,
     -88,  -364,   -16,    12,  -364,   -87,  -364,   -12,    27,  -364,
     -85,  -364,   -10,    21,  -364,   -78,  -364,    -5,    28,  -364,
     -86,  -364,    -3,  -364,  -364,  -364,  -364,    26,  -364,  -364,
     -15,   -93,  -186,    10,    32,  -364,  -364,  -184,     7,   -24,
    -125,  -364,   117,   137,  -364,    38,  -364,  -364,  -364,  -364,
    -364,   288,  -364,  -364,  -364,  -364,  -364,  -364,  -106,   -94,
    -363,  -364,  -364,  -364,  -364,  -364,  -364,   109,   -96,  -364,
     231,  -364,  -208,  -364,   104,   -80,  -364,  -364,  -364,  -364,
     148
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -264
static const yytype_int16 yytable[] =
{
      40,   109,   170,   235,   296,   203,   299,    64,   153,   133,
     167,   118,   319,   119,    90,   220,    40,  -212,   363,   100,
     100,    95,   246,    96,   134,   322,   111,   -38,     8,   -37,
     124,   103,   152,   172,   107,   173,   258,   259,   411,   120,
       8,     8,     8,   317,   136,   137,   318,   237,   411,   237,
     355,   434,   433,     8,   238,    97,   238,   113,   217,   364,
     365,   443,    98,   247,   323,   366,   367,   135,   136,   137,
     248,   110,   433,   174,   349,   282,    99,   260,   261,   105,
     192,   237,    40,   262,   263,   106,   171,   175,   238,    64,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     226,   177,   108,   229,   194,   184,   178,   186,    40,   250,
     218,   131,    11,    12,    13,   208,   209,   243,   333,   297,
     132,   132,   225,   411,   412,   334,   377,   116,    40,   180,
     163,    40,   181,   152,   245,   311,   413,   265,   240,   254,
     255,   256,   283,   266,   267,   268,    32,    33,   280,   281,
      34,    35,    36,   223,    37,   224,   298,     2,     3,     4,
       5,     6,   172,   285,   173,     8,     9,    10,   182,   324,
       8,   183,   164,   397,   228,   399,   180,   212,   213,   357,
     286,   166,   288,   251,   252,   168,   185,   293,   206,   315,
      86,   207,    28,   210,    29,   110,    87,   231,   103,   221,
     270,   276,   284,   274,   -33,   232,   -32,   337,   423,   236,
     234,   272,   278,   350,   290,   291,   300,   292,   310,   328,
     308,    40,   312,   313,   314,   213,   429,   116,    64,   331,
     327,   152,   358,   347,   387,   152,   359,   376,   330,   152,
     437,   170,   177,   178,   379,   392,   152,   329,   384,   388,
     393,   152,   400,   152,   408,   152,   418,   152,   420,   152,
     410,   152,   396,   422,   424,   189,   425,   426,   431,   440,
     340,   444,   386,   441,    89,   360,   325,   338,   151,   402,
     339,   192,   403,   409,   404,   343,   369,   405,   407,   341,
      40,   370,    40,   375,   371,   406,   342,   352,   345,   354,
     372,   353,   344,   373,   294,   194,   442,   346,   102,   432,
     362,   385,    40,   348,   381,   428,   446,   287,   382,   378,
     103,    40,   351,   435,   316,   321,     0,   175,    64,   205,
     289,     0,   391,   374,   390,     0,     0,   394,     0,     0,
     285,     0,     0,   389,     0,     0,     0,     0,     0,     0,
     152,   152,   152,   152,   152,   152,   152,     0,   192,     0,
       0,   395,     0,     0,     0,     0,     0,   103,   398,   103,
       0,     0,     0,   419,   401,   194,   194,   194,   194,   194,
     194,     0,   194,     0,     0,     0,     0,     0,     0,     0,
     192,     0,    40,     0,   436,     0,     0,     0,     0,   421,
      40,     0,     0,     0,     0,   394,     0,   427,   245,     0,
       0,     0,     0,     0,   194,     0,     0,     0,  -263,  -263,
     103,   430,     0,     0,     0,    40,    40,  -263,  -263,   395,
       0,    40,   438,   439,   103,     0,     0,     0,     0,     0,
      40,    40,     0,     0,    40,     0,     0,   445,     0,     0,
       0,   447,     0,     0,  -263,  -263,     0,     0,     0,     0,
    -263,  -263,     0,     0,     0,  -263,     0,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,     1,     0,     2,     3,     4,     5,
       6,     0,     0,     7,     8,     9,    10,    11,    12,    13,
       0,     0,    14,    15,     0,    16,    17,    18,    19,    20,
      21,    22,    23,     0,     0,    24,    25,     0,     0,    26,
      27,    28,     0,    29,     0,    30,     0,     0,     0,     0,
      31,    32,    33,     0,     0,    34,    35,    36,     1,    37,
       2,     3,     4,     5,     6,     0,     0,     0,     8,     9,
      10,    11,    12,    13,     0,     0,    14,    15,     0,    16,
      17,    18,    19,    20,    21,    22,    23,     0,     0,    24,
      25,     0,     0,    26,    27,    28,     0,    29,     0,    30,
     320,     0,     0,     0,    31,    32,    33,     0,     0,    34,
      35,    36,     0,    37,   121,     3,   122,     5,     6,     0,
       0,     0,     8,     9,    10,    11,    12,    13,     0,     0,
      14,    15,     0,    16,    17,    18,    19,    20,    21,    22,
      23,     0,     0,    24,    25,     0,     0,    86,    27,    28,
       0,    29,     0,    30,   123,     0,     0,     0,    31,    32,
      33,     0,     0,    34,    35,    36,     0,    37,     2,     3,
       4,     5,     6,     0,     0,   169,     8,     9,    10,    11,
      12,    13,     0,     0,    14,    15,     0,    16,    17,    18,
      19,    20,    21,    22,    23,     0,     0,    24,    25,     0,
       0,    26,    27,    28,     0,    29,     0,    30,     0,     0,
       0,     0,    31,    32,    33,     0,     0,    34,    35,    36,
       0,    37,     2,     3,     4,     5,     6,     0,     0,     0,
       8,     9,    10,    11,    12,    13,     0,     0,    14,    15,
       0,    16,    17,    18,    19,    20,    21,    22,    23,     0,
       0,    24,    25,     0,     0,    86,    27,    28,     0,    29,
       0,    30,   211,     0,     0,     0,    31,    32,    33,     0,
       0,    34,    35,    36,     0,    37,     2,     3,     4,     5,
       6,     0,     0,     0,     8,     9,    10,    11,    12,    13,
       0,     0,    14,    15,     0,    16,    17,    18,    19,    20,
      21,    22,    23,     0,     0,    24,    25,     0,     0,    26,
      27,    28,     0,    29,     0,    30,   383,     0,     0,     0,
      31,    32,    33,     0,     0,    34,    35,    36,     0,    37,
       2,     3,     4,     5,     6,     0,     0,     0,     8,     9,
      10,    11,    12,    13,     0,     0,    14,    15,     0,    16,
      17,    18,    19,    20,    21,    22,    23,     0,     0,    24,
      25,     0,     0,    86,    27,    28,     0,    29,     0,    30,
       0,     0,     0,     0,    31,    32,    33,     0,     0,    34,
      35,    36,     0,    37,     2,     3,     4,     5,     6,     0,
       0,     0,     8,     9,    10,    11,    12,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,     0,    28,
     115,    29,     0,    87,     0,   116,     0,     0,     0,    32,
      33,     0,     0,    34,    35,    36,     0,    37,     2,     3,
       4,     5,     6,     0,     0,     0,     8,     9,    10,    11,
      12,    13,     0,     0,   187,     0,     0,     2,     3,     4,
       5,     6,     0,     0,     0,     8,     9,    10,    11,    12,
      13,    86,     0,    28,     0,    29,     0,    87,     0,     0,
       0,     0,   188,    32,    33,     0,     0,    34,    35,    36,
      86,    37,    28,   227,    29,     0,    87,     0,   228,     0,
       0,     0,    32,    33,     0,     0,    34,    35,    36,     0,
      37,     2,     3,     4,     5,     6,     0,     0,     0,     8,
       9,    10,    11,    12,    13,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    86,     0,    28,     0,    29,   241,
      87,     0,     0,     0,     0,     0,    32,    33,     0,     0,
      34,    35,    36,    86,    37,    28,     0,    29,     0,    87,
       0,   228,     0,     0,     0,    32,    33,     0,     0,    34,
      35,    36,     0,    37,     2,     3,     4,     5,     6,     0,
       0,     0,     8,     9,    10,    11,    12,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,     0,    28,
       0,    29,     0,    87,     0,     0,     0,     0,     0,    32,
      33,     0,     0,    34,    35,    36,     0,    37
};

static const yytype_int16 yycheck[] =
{
       0,    25,    82,   128,   188,    98,   192,     0,    50,    43,
      80,    28,   220,    28,    14,   111,    16,    18,    17,    19,
      20,    40,     9,    16,     8,    11,    26,    18,    11,    18,
      30,    21,    50,     3,    24,     5,    17,    18,    30,    29,
      11,    11,    11,    41,    52,    53,    44,    38,    30,    38,
      51,    43,   415,    11,    45,    40,    45,    11,    41,    58,
      59,    43,    40,    50,    50,    64,    65,    51,    52,    53,
      57,    40,   435,    43,   282,   171,    47,    58,    59,    40,
      98,    38,    82,    64,    65,    40,    86,    87,    45,    82,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
     117,    46,    42,   118,    98,    95,    51,    97,   108,   151,
     110,    46,    14,    15,    16,   105,   106,   132,    38,   189,
      40,    40,    39,    30,    31,    45,   310,    44,   128,    44,
      55,   131,    47,   151,   149,   205,    43,    60,   131,    61,
      62,    63,   176,    66,    67,    68,    48,    49,   163,   164,
      52,    53,    54,    45,    56,    47,   190,     3,     4,     5,
       6,     7,     3,   178,     5,    11,    12,    13,    44,    39,
      11,    47,    44,   357,    44,   359,    44,    34,    35,    47,
     180,    47,   182,    48,    49,     0,    23,   187,    47,   213,
      36,    47,    38,    47,    40,    40,    42,    41,   188,    42,
      69,    72,    11,    70,    46,    43,    46,   249,   394,    43,
      46,    71,    73,   283,    41,    40,    18,    41,    47,   234,
      55,   221,    41,    41,    40,    35,   410,    44,   221,    41,
      44,   249,    18,    46,    39,   253,    47,    44,   238,   257,
     424,   321,    46,    51,    42,    21,   264,   237,    47,    44,
      41,   269,    41,   271,    46,   273,    41,   275,    39,   277,
      47,   279,   355,    47,    47,    98,    41,    41,    46,    41,
     264,    41,   327,    46,    10,   298,   229,   253,    49,   369,
     257,   299,   370,   376,   371,   273,   302,   372,   374,   269,
     290,   303,   292,   308,   304,   373,   271,   290,   277,   292,
     305,   291,   275,   306,   187,   299,   431,   279,    20,   415,
     300,   326,   312,   281,   314,   408,   441,   180,   318,   312,
     310,   321,   284,   417,   215,   221,    -1,   327,   321,    98,
     182,    -1,   347,   307,   334,    -1,    -1,   355,    -1,    -1,
     355,    -1,    -1,   333,    -1,    -1,    -1,    -1,    -1,    -1,
     368,   369,   370,   371,   372,   373,   374,    -1,   376,    -1,
      -1,   355,    -1,    -1,    -1,    -1,    -1,   357,   358,   359,
      -1,    -1,    -1,   388,   368,   369,   370,   371,   372,   373,
     374,    -1,   376,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     408,    -1,   392,    -1,   418,    -1,    -1,    -1,    -1,   392,
     400,    -1,    -1,    -1,    -1,   423,    -1,   400,   423,    -1,
      -1,    -1,    -1,    -1,   408,    -1,    -1,    -1,     8,     9,
     410,   411,    -1,    -1,    -1,   425,   426,    17,    18,   423,
      -1,   431,   425,   426,   424,    -1,    -1,    -1,    -1,    -1,
     440,   441,    -1,    -1,   444,    -1,    -1,   440,    -1,    -1,
      -1,   444,    -1,    -1,    44,    45,    -1,    -1,    -1,    -1,
      50,    51,    -1,    -1,    -1,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,     1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    32,    33,    -1,    -1,    36,
      37,    38,    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,
      47,    48,    49,    -1,    -1,    52,    53,    54,     1,    56,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    11,    12,
      13,    14,    15,    16,    -1,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    32,
      33,    -1,    -1,    36,    37,    38,    -1,    40,    -1,    42,
      43,    -1,    -1,    -1,    47,    48,    49,    -1,    -1,    52,
      53,    54,    -1,    56,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    11,    12,    13,    14,    15,    16,    -1,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    32,    33,    -1,    -1,    36,    37,    38,
      -1,    40,    -1,    42,    43,    -1,    -1,    -1,    47,    48,
      49,    -1,    -1,    52,    53,    54,    -1,    56,     3,     4,
       5,     6,     7,    -1,    -1,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    32,    33,    -1,
      -1,    36,    37,    38,    -1,    40,    -1,    42,    -1,    -1,
      -1,    -1,    47,    48,    49,    -1,    -1,    52,    53,    54,
      -1,    56,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      11,    12,    13,    14,    15,    16,    -1,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    32,    33,    -1,    -1,    36,    37,    38,    -1,    40,
      -1,    42,    43,    -1,    -1,    -1,    47,    48,    49,    -1,
      -1,    52,    53,    54,    -1,    56,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    11,    12,    13,    14,    15,    16,
      -1,    -1,    19,    20,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    32,    33,    -1,    -1,    36,
      37,    38,    -1,    40,    -1,    42,    43,    -1,    -1,    -1,
      47,    48,    49,    -1,    -1,    52,    53,    54,    -1,    56,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    11,    12,
      13,    14,    15,    16,    -1,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    32,
      33,    -1,    -1,    36,    37,    38,    -1,    40,    -1,    42,
      -1,    -1,    -1,    -1,    47,    48,    49,    -1,    -1,    52,
      53,    54,    -1,    56,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    38,
      39,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,    48,
      49,    -1,    -1,    52,    53,    54,    -1,    56,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    11,    12,    13,    14,
      15,    16,    -1,    -1,    19,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    11,    12,    13,    14,    15,
      16,    36,    -1,    38,    -1,    40,    -1,    42,    -1,    -1,
      -1,    -1,    47,    48,    49,    -1,    -1,    52,    53,    54,
      36,    56,    38,    39,    40,    -1,    42,    -1,    44,    -1,
      -1,    -1,    48,    49,    -1,    -1,    52,    53,    54,    -1,
      56,     3,     4,     5,     6,     7,    -1,    -1,    -1,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    11,    12,
      13,    14,    15,    16,    36,    -1,    38,    -1,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,
      52,    53,    54,    36,    56,    38,    -1,    40,    -1,    42,
      -1,    44,    -1,    -1,    -1,    48,    49,    -1,    -1,    52,
      53,    54,    -1,    56,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    38,
      -1,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,
      49,    -1,    -1,    52,    53,    54,    -1,    56
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,    10,    11,    12,
      13,    14,    15,    16,    19,    20,    22,    23,    24,    25,
      26,    27,    28,    29,    32,    33,    36,    37,    38,    40,
      42,    47,    48,    49,    52,    53,    54,    56,    85,    86,
      87,    88,    92,    97,    99,   103,   110,   112,   114,   115,
     116,   117,   120,   123,   126,   132,   137,   142,   147,   152,
     157,   162,   164,   167,   172,   173,   175,   181,   182,   183,
     184,   186,   187,   188,   189,   190,   196,   197,   198,   203,
     204,   207,   208,   209,   210,   212,    36,    42,    87,    97,
      87,   176,   177,   213,   214,    40,   172,    40,    40,    47,
      87,   185,   185,   167,   171,    40,    40,   167,    42,   173,
      40,    87,   202,    11,   211,    39,    44,    89,    91,   164,
     167,     3,     5,    43,    87,    93,    95,    96,   172,   174,
     101,    46,    40,   107,     8,    51,    52,    53,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,   113,   166,
     118,   116,   110,   114,   121,   124,   127,   133,   138,   143,
     148,   153,   158,    55,    44,   168,    47,   101,     0,    10,
     209,    87,     3,     5,    43,    87,   100,    46,    51,   179,
      44,    47,    44,    47,   167,    23,   167,    19,    47,    85,
      98,   104,   110,   111,   123,   129,   134,   139,   144,   149,
     154,   159,   163,   165,   169,   204,    47,    47,   167,   167,
      47,    43,    34,    35,   199,   200,   201,    41,    87,   205,
     202,    42,   206,    45,    47,    39,    91,    39,    44,   164,
      90,    41,    43,    94,    46,   174,    43,    38,    45,   102,
     172,    41,   108,   164,   105,   164,     9,    50,    57,   119,
     114,    48,    49,   122,    61,    62,    63,   125,    17,    18,
      58,    59,    64,    65,   128,    60,    66,    67,    68,   136,
      69,   141,    71,   146,    70,   151,    72,   156,    73,   161,
     164,   164,   202,   107,    11,   164,    87,   177,    87,   214,
      41,    40,    41,    87,   176,   178,   171,   101,   107,   166,
      18,   130,   135,   140,   145,   150,   155,   160,    55,   170,
      47,   101,    41,    41,    40,   173,   201,    41,    44,   206,
      43,   208,    11,    50,    39,    90,    91,    44,   164,   167,
      87,    41,   109,    38,    45,   106,   107,   114,   117,   120,
     123,   126,   132,   137,   142,   147,   152,    46,   168,   206,
     101,   179,   172,   167,   172,    51,   180,    47,    18,    47,
     105,   165,   167,    17,    58,    59,    64,    65,   131,   136,
     141,   146,   151,   156,   161,   164,    44,   171,   172,    42,
     191,    87,    87,    43,    47,   164,    95,    39,    44,   167,
      87,   164,    21,    41,   110,   123,   165,   171,   167,   171,
      41,   123,   129,   134,   139,   144,   149,   154,    46,   165,
      47,    30,    31,    43,   192,   193,   194,   195,    41,   164,
      39,   172,    47,   166,    47,    41,    41,   172,   165,   171,
     167,    46,   192,   194,    43,   193,   173,   171,   172,   172,
      41,    46,   174,    43,    41,   172,   174,   172
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
        case 5:
#line 122 "JSint.y"
    {
/*	//printf("identifier\n");*/
	(yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression);
;}
    break;

  case 7:
#line 127 "JSint.y"
    {
/*	//printf("Literal\n");*/
	(yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression);
;}
    break;

  case 8:
#line 131 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::IntegerType(atoi((yyvsp[(1) - (1)].debug))); (yyval.ast_Expression)->debug = (yyvsp[(1) - (1)].debug);
	//printf("number\n");
;}
    break;

  case 10:
#line 136 "JSint.y"
    {
	char a[200];
	strcpy(a,(yyvsp[(1) - (1)].debug)+1);
	a[strlen(a)-1] = 0;
/*	std::cout<<a<<std::endl;*/
	(yyval.ast_Expression) = new ast::StringType(a); (yyval.ast_Expression)->debug = a;
;}
    break;

  case 13:
#line 144 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::Identifier((yyvsp[(1) - (1)].debug));
;}
    break;

  case 35:
#line 169 "JSint.y"
    {
	if ((yyvsp[(2) - (2)].ast_Expression) == nullptr)
	{
		(yyval.ast_Expression) = (yyvsp[(1) - (2)].ast_Expression);
/*		//printf("MemberExp\n");*/
	}
/*	//printf("MemberExp\n");*/
;}
    break;

  case 38:
#line 179 "JSint.y"
    {
/*	//printf("MemberExpForIn\n");*/
;}
    break;

  case 43:
#line 187 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
;}
    break;

  case 59:
#line 205 "JSint.y"
    {
	(yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression);
/*	//printf("LeftHandExp\n");*/
;}
    break;

  case 61:
#line 210 "JSint.y"
    {
	
;}
    break;

  case 62:
#line 215 "JSint.y"
    {
	(yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression);
/*	//printf("postfixExp\n");*/
;}
    break;

  case 66:
#line 222 "JSint.y"
    {
	(yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression);
;}
    break;

  case 79:
#line 237 "JSint.y"
    {
	auto exp = dynamic_cast<ast::BinaryOperator*>((yyvsp[(2) - (2)].ast_Expression));
	if (exp == nullptr) {
		(yyval.ast_Expression) = (yyvsp[(1) - (2)].ast_Expression);
	}
	else {
		(yyval.ast_Expression) = exp;
		noOp1Exp ->op1 = (yyvsp[(1) - (2)].ast_Expression);
	}
;}
    break;

  case 80:
#line 248 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression),(yyvsp[(2) - (3)].ast_OpType),(yyvsp[(3) - (3)].ast_Expression));
	if ((yyvsp[(1) - (3)].ast_Expression) == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>((yyval.ast_Expression));
	}
;}
    break;

  case 81:
#line 255 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
;}
    break;

  case 82:
#line 258 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::mul;
;}
    break;

  case 83:
#line 261 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::div;
;}
    break;

  case 84:
#line 264 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::mod;
;}
    break;

  case 85:
#line 267 "JSint.y"
    {
	auto exp = dynamic_cast<ast::BinaryOperator*>((yyvsp[(2) - (2)].ast_Expression));
	if (exp == nullptr) {
		(yyval.ast_Expression) = (yyvsp[(1) - (2)].ast_Expression);
	}
	else {
		(yyval.ast_Expression) = exp;
		noOp1Exp ->op1 = (yyvsp[(1) - (2)].ast_Expression);
	}
;}
    break;

  case 86:
#line 278 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression),(yyvsp[(2) - (3)].ast_OpType),(yyvsp[(3) - (3)].ast_Expression));
	if ((yyvsp[(1) - (3)].ast_Expression) == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>((yyval.ast_Expression));
	}
;}
    break;

  case 87:
#line 285 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
;}
    break;

  case 88:
#line 288 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::plus;
;}
    break;

  case 89:
#line 291 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::minus;
;}
    break;

  case 90:
#line 294 "JSint.y"
    {
	auto exp = dynamic_cast<ast::BinaryOperator*>((yyvsp[(2) - (2)].ast_Expression));
	if (exp == nullptr) {
		(yyval.ast_Expression) = (yyvsp[(1) - (2)].ast_Expression);
	}
	else {
		(yyval.ast_Expression) = exp;
		noOp1Exp ->op1 = (yyvsp[(1) - (2)].ast_Expression);
	}
;}
    break;

  case 91:
#line 304 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression),(yyvsp[(2) - (3)].ast_OpType),(yyvsp[(3) - (3)].ast_Expression));
	if ((yyvsp[(1) - (3)].ast_Expression) == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>((yyval.ast_Expression));
	}
;}
    break;

  case 92:
#line 311 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
;}
    break;

  case 93:
#line 314 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::lsh;
;}
    break;

  case 94:
#line 317 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::rsh;
;}
    break;

  case 95:
#line 320 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::ursh;
;}
    break;

  case 96:
#line 323 "JSint.y"
    {
	auto exp = dynamic_cast<ast::BinaryOperator*>((yyvsp[(2) - (2)].ast_Expression));
	if (exp == nullptr) {
		(yyval.ast_Expression) = (yyvsp[(1) - (2)].ast_Expression);
	}
	else {
		(yyval.ast_Expression) = exp;
		noOp1Exp ->op1 = (yyvsp[(1) - (2)].ast_Expression);
	}
;}
    break;

  case 97:
#line 333 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression),(yyvsp[(2) - (3)].ast_OpType),(yyvsp[(3) - (3)].ast_Expression));
	if ((yyvsp[(1) - (3)].ast_Expression) == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>((yyval.ast_Expression));
	}
;}
    break;

  case 98:
#line 340 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
;}
    break;

  case 99:
#line 343 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::lt;
;}
    break;

  case 100:
#line 346 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::gt;
;}
    break;

  case 101:
#line 349 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::le;
;}
    break;

  case 102:
#line 352 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::ge;
;}
    break;

  case 103:
#line 355 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::iof;
;}
    break;

  case 104:
#line 358 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::iin;
;}
    break;

  case 113:
#line 369 "JSint.y"
    {
	auto exp = dynamic_cast<ast::BinaryOperator*>((yyvsp[(2) - (2)].ast_Expression));
	if (exp == nullptr) {
		(yyval.ast_Expression) = (yyvsp[(1) - (2)].ast_Expression);
	}
	else {
		(yyval.ast_Expression) = exp;
		noOp1Exp ->op1 = (yyvsp[(1) - (2)].ast_Expression);
	}
;}
    break;

  case 114:
#line 379 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression),(yyvsp[(2) - (3)].ast_OpType),(yyvsp[(3) - (3)].ast_Expression));
	if ((yyvsp[(1) - (3)].ast_Expression) == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>((yyval.ast_Expression));
	}
;}
    break;

  case 115:
#line 386 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
;}
    break;

  case 119:
#line 392 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::eq;
;}
    break;

  case 120:
#line 395 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::ne;
;}
    break;

  case 121:
#line 398 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::aeq;
;}
    break;

  case 122:
#line 401 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::ane;
;}
    break;

  case 123:
#line 404 "JSint.y"
    {
	auto exp = dynamic_cast<ast::BinaryOperator*>((yyvsp[(2) - (2)].ast_Expression));
	if (exp == nullptr) {
		(yyval.ast_Expression) = (yyvsp[(1) - (2)].ast_Expression);
	}
	else {
		(yyval.ast_Expression) = exp;
		noOp1Exp ->op1 = (yyvsp[(1) - (2)].ast_Expression);
	}
;}
    break;

  case 124:
#line 414 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression),(yyvsp[(2) - (3)].ast_OpType),(yyvsp[(3) - (3)].ast_Expression));
	if ((yyvsp[(1) - (3)].ast_Expression) == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>((yyval.ast_Expression));
	}
;}
    break;

  case 125:
#line 421 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
;}
    break;

  case 129:
#line 427 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::bit_and;
;}
    break;

  case 130:
#line 430 "JSint.y"
    {
	auto exp = dynamic_cast<ast::BinaryOperator*>((yyvsp[(2) - (2)].ast_Expression));
	if (exp == nullptr) {
		(yyval.ast_Expression) = (yyvsp[(1) - (2)].ast_Expression);
	}
	else {
		(yyval.ast_Expression) = exp;
		noOp1Exp ->op1 = (yyvsp[(1) - (2)].ast_Expression);
	}
;}
    break;

  case 131:
#line 440 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression),(yyvsp[(2) - (3)].ast_OpType),(yyvsp[(3) - (3)].ast_Expression));
	if ((yyvsp[(1) - (3)].ast_Expression) == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>((yyval.ast_Expression));
	}
;}
    break;

  case 132:
#line 447 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
;}
    break;

  case 136:
#line 453 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::bit_xor;
;}
    break;

  case 137:
#line 456 "JSint.y"
    {
	auto exp = dynamic_cast<ast::BinaryOperator*>((yyvsp[(2) - (2)].ast_Expression));
	if (exp == nullptr) {
		(yyval.ast_Expression) = (yyvsp[(1) - (2)].ast_Expression);
	}
	else {
		(yyval.ast_Expression) = exp;
		noOp1Exp ->op1 = (yyvsp[(1) - (2)].ast_Expression);
	}
;}
    break;

  case 138:
#line 466 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression),(yyvsp[(2) - (3)].ast_OpType),(yyvsp[(3) - (3)].ast_Expression));
	if ((yyvsp[(1) - (3)].ast_Expression) == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>((yyval.ast_Expression));
	}
;}
    break;

  case 139:
#line 473 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
;}
    break;

  case 143:
#line 479 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::bit_or;
;}
    break;

  case 144:
#line 482 "JSint.y"
    {
	auto exp = dynamic_cast<ast::BinaryOperator*>((yyvsp[(2) - (2)].ast_Expression));
	if (exp == nullptr) {
		(yyval.ast_Expression) = (yyvsp[(1) - (2)].ast_Expression);
	}
	else {
		(yyval.ast_Expression) = exp;
		noOp1Exp ->op1 = (yyvsp[(1) - (2)].ast_Expression);
	}
;}
    break;

  case 145:
#line 492 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression),(yyvsp[(2) - (3)].ast_OpType),(yyvsp[(3) - (3)].ast_Expression));
	if ((yyvsp[(1) - (3)].ast_Expression) == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>((yyval.ast_Expression));
	}
;}
    break;

  case 146:
#line 499 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
;}
    break;

  case 150:
#line 505 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::land;
;}
    break;

  case 151:
#line 508 "JSint.y"
    {
	auto exp = dynamic_cast<ast::BinaryOperator*>((yyvsp[(2) - (2)].ast_Expression));
	if (exp == nullptr) {
		(yyval.ast_Expression) = (yyvsp[(1) - (2)].ast_Expression);
	}
	else {
		(yyval.ast_Expression) = exp;
		noOp1Exp ->op1 = (yyvsp[(1) - (2)].ast_Expression);
	}
;}
    break;

  case 152:
#line 518 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression),(yyvsp[(2) - (3)].ast_OpType),(yyvsp[(3) - (3)].ast_Expression));
	if ((yyvsp[(1) - (3)].ast_Expression) == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>((yyval.ast_Expression));
	}
;}
    break;

  case 153:
#line 525 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
;}
    break;

  case 157:
#line 531 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::lor;
;}
    break;

  case 158:
#line 534 "JSint.y"
    {
	(yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression);
;}
    break;

  case 159:
#line 537 "JSint.y"
    {
;}
    break;

  case 162:
#line 542 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression),(yyvsp[(2) - (3)].ast_OpType),(yyvsp[(3) - (3)].ast_Expression));
/*	//printf("an assign exp\n");*/
;}
    break;

  case 163:
#line 546 "JSint.y"
    {
	(yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression);
	//printf("an assign exp from condition\n");
;}
    break;

  case 164:
#line 550 "JSint.y"
    {;}
    break;

  case 166:
#line 552 "JSint.y"
    { 
	(yyval.ast_OpType) =ast::BinaryOperator::OpType::assign; 
	//printf("an assign\n");
;}
    break;

  case 178:
#line 568 "JSint.y"
    {
	if ((yyvsp[(2) - (2)].ast_Expression) == nullptr){
		(yyval.ast_Expression) = (yyvsp[(1) - (2)].ast_Expression);
	}
	else {
		(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (2)].ast_Expression),ast::BinaryOperator::OpType::comma,(yyvsp[(2) - (2)].ast_Expression));
	}
	
	
;}
    break;

  case 179:
#line 578 "JSint.y"
    {
	if ((yyvsp[(3) - (3)].ast_Expression) == nullptr) {
		(yyval.ast_Expression) = (yyvsp[(2) - (3)].ast_Expression);
	} else {
		(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(2) - (3)].ast_Expression),ast::BinaryOperator::OpType::comma,(yyvsp[(3) - (3)].ast_Expression));
	}
	
;}
    break;

  case 180:
#line 586 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
;}
    break;

  case 186:
#line 597 "JSint.y"
    {
	(yyval.ast_Statement) = (yyvsp[(1) - (1)].ast_Block);
;}
    break;

  case 191:
#line 605 "JSint.y"
    {
	(yyval.ast_Statement) = (yyvsp[(1) - (1)].ast_Statement);
;}
    break;

  case 202:
#line 619 "JSint.y"
    {;}
    break;

  case 203:
#line 621 "JSint.y"
    {
	(yyval.ast_Block) = new ast::Block((yyvsp[(2) - (3)].ast_StatementList));
;}
    break;

  case 204:
#line 625 "JSint.y"
    {
	(yyval.ast_StatementList) = new ast::StatementList((yyvsp[(1) - (1)].ast_Statement));
;}
    break;

  case 205:
#line 629 "JSint.y"
    {
	(yyval.ast_StatementList) = new ast::StatementList((yyvsp[(1) - (2)].ast_Statement), (yyvsp[(2) - (2)].ast_StatementList));
;}
    break;

  case 217:
#line 645 "JSint.y"
    {
	(yyval.ast_Statement) = (yyvsp[(1) - (1)].ast_Expression);
;}
    break;

  case 218:
#line 648 "JSint.y"
    {
	(yyval.ast_Statement) = (yyvsp[(1) - (2)].ast_Expression);
;}
    break;

  case 269:
#line 702 "JSint.y"
    {
	(yyval.ast_StatementList) = (yyvsp[(1) - (2)].ast_StatementList);
;}
    break;

  case 270:
#line 705 "JSint.y"
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
;}
    break;

  case 271:
#line 727 "JSint.y"
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
;}
    break;

  case 274:
#line 751 "JSint.y"
    {
	(yyval.ast_Statement) = (yyvsp[(1) - (1)].ast_Statement);
;}
    break;


/* Line 1267 of yacc.c.  */
#line 2927 "parser.cpp"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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



