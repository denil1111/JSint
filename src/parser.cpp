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
#include <vector>
#include "ast.h"
#include "utils.h"
#include "parser.hpp"
#include "ccalc.h"
using namespace std;

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
#line 19 "JSint.y"
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

	ast::ParameterList*     ast_ParameterList;
	ast::FunctionDeclaration* ast_FunctionDeclaration;
	ast::ArgumentList*      ast_ArgumentList;
	ast::CallExpression*    ast_CallExpression;
}
/* Line 193 of yacc.c.  */
#line 317 "parser.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 330 "parser.cpp"

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
#define YYLAST   1169

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  130
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
     136,   138,   142,   145,   149,   152,   154,   158,   160,   162,
     164,   166,   168,   171,   173,   175,   177,   179,   182,   186,
     188,   190,   192,   194,   196,   198,   200,   202,   204,   207,
     211,   212,   214,   216,   218,   221,   225,   226,   228,   230,
     233,   237,   238,   240,   242,   244,   247,   251,   252,   254,
     256,   258,   260,   262,   264,   267,   271,   272,   274,   276,
     278,   280,   282,   285,   289,   290,   293,   297,   298,   300,
     302,   304,   306,   309,   313,   314,   317,   321,   322,   324,
     327,   331,   332,   335,   339,   340,   342,   345,   349,   350,
     353,   357,   358,   360,   363,   367,   368,   371,   375,   376,
     378,   381,   385,   386,   389,   393,   394,   396,   398,   404,
     406,   412,   416,   418,   422,   424,   426,   428,   430,   432,
     434,   436,   438,   440,   442,   444,   446,   448,   451,   455,
     456,   459,   463,   464,   465,   467,   469,   471,   473,   475,
     477,   479,   481,   483,   485,   487,   489,   491,   493,   495,
     497,   499,   502,   506,   508,   511,   514,   518,   520,   524,
     526,   529,   531,   534,   537,   540,   542,   544,   547,   553,
     561,   568,   576,   582,   591,   601,   612,   621,   629,   630,
     632,   634,   637,   640,   643,   646,   650,   656,   662,   665,
     669,   671,   674,   678,   680,   683,   687,   692,   695,   699,
     703,   706,   710,   714,   716,   718,   721,   727,   730,   733,
     737,   742,   746,   751,   753,   757,   760,   764,   766,   769,
     771,   774,   776,   778,   780,   784,   790,   792,   796,   799,
     803,   805,   809,   813
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     206,     0,    -1,    12,    -1,    92,    -1,    40,   166,    41,
      -1,    87,    -1,    88,    -1,    86,    -1,     3,    -1,     4,
      -1,     5,    -1,     6,    -1,     7,    -1,    11,    -1,    38,
      91,    39,    -1,    38,    89,    91,    39,    -1,    38,    89,
      39,    -1,    38,    39,    -1,    91,   163,    90,    -1,   163,
      90,    -1,    90,    91,   163,    -1,    -1,    44,    -1,    91,
      44,    -1,    42,    93,    43,    -1,    42,    43,    -1,    95,
      94,    -1,    94,    44,    -1,    94,    44,    95,    -1,    -1,
      96,    46,   163,    -1,    87,    -1,     5,    -1,     3,    -1,
     203,   101,    -1,    85,   101,    -1,    99,    -1,   203,   101,
      -1,    85,   101,    -1,    13,    97,   100,    -1,   100,   107,
     101,    -1,    -1,   101,   102,    -1,    -1,    38,   166,    39,
      -1,    45,    87,    -1,    97,   107,   105,    -1,    98,   107,
     105,    -1,   105,   106,    -1,    -1,   107,    -1,    38,   166,
      39,    -1,    45,    87,    -1,    40,   108,    41,    -1,    40,
      41,    -1,   163,    -1,   108,    44,   163,    -1,   103,    -1,
      97,    -1,   104,    -1,    98,    -1,   109,    -1,   109,   112,
      -1,    52,    -1,    53,    -1,   111,    -1,   114,    -1,   115,
     113,    -1,   114,   115,   113,    -1,    14,    -1,    15,    -1,
      16,    -1,    52,    -1,    53,    -1,    48,    -1,    49,    -1,
      54,    -1,    56,    -1,   113,   117,    -1,   117,   118,   113,
      -1,    -1,    50,    -1,     9,    -1,    57,    -1,   116,   120,
      -1,   120,   121,   116,    -1,    -1,    48,    -1,    49,    -1,
     119,   123,    -1,   123,   124,   119,    -1,    -1,    61,    -1,
      62,    -1,    63,    -1,   122,   126,    -1,   126,   127,   122,
      -1,    -1,    58,    -1,    59,    -1,    64,    -1,    65,    -1,
      17,    -1,    18,    -1,   122,   129,    -1,   129,   130,   122,
      -1,    -1,    58,    -1,    59,    -1,    64,    -1,    65,    -1,
      17,    -1,   125,   132,    -1,   132,   135,   125,    -1,    -1,
     128,   134,    -1,   134,   135,   128,    -1,    -1,    60,    -1,
      66,    -1,    67,    -1,    68,    -1,   131,   137,    -1,   137,
     140,   131,    -1,    -1,   133,   139,    -1,   139,   140,   133,
      -1,    -1,    69,    -1,   136,   142,    -1,   142,   145,   136,
      -1,    -1,   138,   144,    -1,   144,   145,   138,    -1,    -1,
      71,    -1,   141,   147,    -1,   147,   150,   141,    -1,    -1,
     143,   149,    -1,   149,   150,   143,    -1,    -1,    70,    -1,
     146,   152,    -1,   152,   155,   146,    -1,    -1,   148,   154,
      -1,   154,   155,   148,    -1,    -1,    72,    -1,   151,   157,
      -1,   157,   160,   151,    -1,    -1,   153,   159,    -1,   159,
     160,   153,    -1,    -1,    73,    -1,   156,    -1,   156,    55,
     163,    46,   163,    -1,   158,    -1,   158,    55,   163,    46,
     164,    -1,   109,   165,   163,    -1,   161,    -1,   109,   165,
     164,    -1,   162,    -1,    51,    -1,    74,    -1,     8,    -1,
      75,    -1,    76,    -1,    77,    -1,    78,    -1,    79,    -1,
      80,    -1,    81,    -1,    82,    -1,    83,    -1,   163,   167,
      -1,    44,   163,   167,    -1,    -1,   164,   169,    -1,   169,
      44,   164,    -1,    -1,    -1,   166,    -1,   172,    -1,   211,
      -1,   174,    -1,   180,    -1,   195,    -1,   181,    -1,   182,
      -1,   183,    -1,   185,    -1,   186,    -1,   209,    -1,   187,
      -1,   188,    -1,   189,    -1,   196,    -1,   197,    -1,    42,
      43,    -1,    42,   173,    43,    -1,   171,    -1,   171,   173,
      -1,    19,   175,    -1,    19,   175,    47,    -1,   176,    -1,
     175,    44,   176,    -1,    87,    -1,    87,   178,    -1,    87,
      -1,    87,   179,    -1,    51,   163,    -1,    51,   164,    -1,
      47,    -1,   166,    -1,   166,    47,    -1,    20,    40,   166,
      41,   171,    -1,    20,    40,   166,    41,   171,    21,   171,
      -1,    22,   171,    23,    40,   166,    41,    -1,    22,   171,
      23,    40,   166,    41,    47,    -1,    23,    40,   166,    41,
     171,    -1,    24,    40,    47,   170,    47,   170,    41,   171,
      -1,    24,    40,   168,    47,   170,    47,   170,    41,   171,
      -1,    24,    40,    19,   175,    47,   170,    47,   170,    41,
     171,    -1,    24,    40,    19,   177,    18,   166,    41,   171,
      -1,    24,    40,   110,    18,   166,    41,   171,    -1,    -1,
      87,    -1,    47,    -1,    87,    47,    -1,    25,   184,    -1,
      26,   184,    -1,    27,   170,    -1,    27,   170,    47,    -1,
      28,    40,   166,    41,   171,    -1,    29,    40,   166,    41,
     190,    -1,    42,   191,    -1,    42,   192,   191,    -1,    43,
      -1,   194,    43,    -1,   194,   192,    43,    -1,   193,    -1,
     192,   193,    -1,    30,   166,    46,    -1,    30,   166,    46,
     173,    -1,    31,    46,    -1,    31,    46,   173,    -1,    87,
      46,   171,    -1,    32,   166,    -1,    32,   166,    47,    -1,
      33,   172,   198,    -1,   200,    -1,   199,    -1,   199,   200,
      -1,    34,    40,    87,    41,   172,    -1,    35,   172,    -1,
      40,    41,    -1,    40,   204,    41,    -1,    36,    87,   201,
     205,    -1,    36,   201,   205,    -1,    36,    87,   201,   205,
      -1,    87,    -1,   204,    44,    87,    -1,    42,    43,    -1,
      42,   207,    43,    -1,    10,    -1,   207,    10,    -1,   208,
      -1,   207,   208,    -1,     1,    -1,   202,    -1,   171,    -1,
      37,   210,    47,    -1,    37,   210,    45,    50,    47,    -1,
      11,    -1,   210,    45,    11,    -1,    19,   212,    -1,    19,
     212,    47,    -1,   213,    -1,   212,    44,   213,    -1,    87,
      46,    11,    -1,    87,    46,    11,   178,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   123,   123,   124,   125,   126,   130,   131,   135,   139,
     140,   147,   147,   148,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     168,   169,   170,   171,   172,   173,   181,   182,   183,   187,
     188,   189,   190,   191,   194,   195,   197,   201,   203,   204,
     207,   208,   209,   211,   214,   218,   222,   227,   230,   234,
     235,   240,   244,   245,   246,   247,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   273,
     280,   283,   286,   289,   292,   303,   310,   313,   316,   319,
     329,   336,   339,   342,   345,   348,   358,   365,   368,   371,
     374,   377,   380,   383,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   404,   411,   414,   415,   416,   417,   420,
     423,   426,   429,   439,   446,   449,   450,   451,   452,   455,
     465,   472,   475,   476,   477,   478,   481,   491,   498,   501,
     502,   503,   504,   507,   517,   524,   527,   528,   529,   530,
     533,   543,   550,   553,   554,   555,   556,   559,   562,   564,
     565,   566,   571,   575,   576,   577,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   603,   611,
     614,   615,   616,   619,   620,   621,   622,   623,   624,   625,
     626,   630,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,   641,   642,   643,   644,   645,   646,   647,   650,
     651,   652,   653,   654,   655,   656,   657,   660,   663,   664,
     665,   666,   667,   668,   669,   670,   671,   672,   673,   674,
     675,   676,   677,   678,   679,   680,   681,   682,   683,   684,
     685,   686,   687,   688,   689,   690,   691,   692,   693,   694,
     695,   696,   697,   698,   699,   700,   701,   702,   704,   707,
     711,   715,   716,   718,   722,   727,   730,   734,   735,   739,
     761,   783,   784,   785,   788,   789,   790,   791,   792,   793,
     794,   795,   796,   797
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
  "LeftHandSideExpression", "LeftHandSideExpressionForIn",
  "PostfixExpression", "PostfixOperator", "UnaryExpression",
  "UnaryExpressionPart", "UnaryOperator", "MultiplicativeExpression",
  "MultiplicativeExpressionPart", "MultiplicativeOperator",
  "AdditiveExpression", "AdditiveExpressionPart", "AdditiveOperator",
  "ShiftExpression", "ShiftExpressionPart", "ShiftOperator",
  "RelationalExpression", "RelationalExpressionPart", "RelationalOperator",
  "RelationalExpressionNoIn", "RelationalExpressionNoInPart",
  "RelationalNoInOperator", "EqualityExpression", "EqualityExpressionPart",
  "EqualityExpressionNoIn", "EqualityExpressionNoInPart",
  "EqualityOperator", "BitwiseANDExpression", "BitwiseANDExpressionPart",
  "BitwiseANDExpressionNoIn", "BitwiseANDExpressionNoInPart",
  "BitwiseANDOperator", "BitwiseXORExpression", "BitwiseXORExpressionPart",
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
     106,   106,   106,   107,   107,   108,   108,   109,   109,   110,
     110,   111,   111,   112,   112,   113,   113,   114,   114,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   116,   117,
     117,   118,   118,   118,   119,   120,   120,   121,   121,   122,
     123,   123,   124,   124,   124,   125,   126,   126,   127,   127,
     127,   127,   127,   127,   128,   129,   129,   130,   130,   130,
     130,   130,   131,   132,   132,   133,   134,   134,   135,   135,
     135,   135,   136,   137,   137,   138,   139,   139,   140,   141,
     142,   142,   143,   144,   144,   145,   146,   147,   147,   148,
     149,   149,   150,   151,   152,   152,   153,   154,   154,   155,
     156,   157,   157,   158,   159,   159,   160,   161,   161,   162,
     162,   163,   163,   164,   164,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   166,   167,   167,
     168,   169,   169,   170,   170,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   171,   171,   171,
     171,   172,   172,   173,   173,   174,   174,   175,   175,   176,
     176,   177,   177,   178,   179,   180,   181,   181,   182,   182,
     183,   183,   183,   183,   183,   183,   183,   183,   184,   184,
     184,   184,   185,   186,   187,   187,   188,   189,   190,   190,
     191,   191,   191,   192,   192,   193,   193,   194,   194,   195,
     196,   196,   197,   198,   198,   198,   199,   200,   201,   201,
     202,   203,   203,   204,   204,   205,   205,   206,   206,   207,
     207,   207,   208,   208,   209,   209,   210,   210,   211,   211,
     212,   212,   213,   213
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     3,     2,     3,     2,
       3,     0,     1,     2,     3,     2,     2,     2,     3,     0,
       3,     1,     1,     1,     2,     2,     1,     2,     2,     3,
       3,     0,     2,     0,     3,     2,     3,     3,     2,     0,
       1,     3,     2,     3,     2,     1,     3,     1,     1,     1,
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
       1,     2,     3,     1,     2,     2,     3,     1,     3,     1,
       2,     1,     2,     2,     2,     1,     1,     2,     5,     7,
       6,     7,     5,     8,     9,    10,     8,     7,     0,     1,
       1,     2,     2,     2,     2,     3,     5,     5,     2,     3,
       1,     2,     3,     1,     2,     3,     4,     2,     3,     3,
       2,     3,     3,     1,     1,     2,     5,     2,     2,     3,
       4,     3,     4,     1,     3,     2,     3,     1,     2,     1,
       2,     1,     1,     1,     3,     5,     1,     3,     2,     3,
       1,     3,     3,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,   271,     8,     9,    10,    11,    12,   267,    13,     2,
       0,    69,    70,    71,     0,     0,     0,     0,     0,   228,
     228,   183,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   215,    74,    75,    72,    73,    76,    77,    43,     7,
       5,     6,     3,    58,    36,    57,    61,    65,    80,    66,
       0,    86,    91,    97,   114,   124,   131,   138,   145,   152,
     157,   162,   179,   216,   273,   185,   187,   188,   190,   191,
     192,   193,   194,   196,   197,   198,   189,   199,   200,   272,
      43,     0,     0,   269,   195,   186,     0,     0,     5,    41,
     209,   205,   207,   278,   280,     0,     0,     0,     0,   230,
     229,   232,   233,   184,   234,     0,     0,   250,     0,     0,
       0,     0,     0,   276,     0,    17,    22,     0,     0,    21,
       0,     8,    10,    25,     5,     0,    29,     0,   203,     0,
      35,     0,     0,    49,   167,   165,    63,    64,   166,   168,
     169,   170,   171,   172,   173,   174,   175,   176,    62,     0,
      78,     0,    61,    67,    84,    89,    95,   112,   122,   129,
     136,   143,   150,     0,     0,   177,   217,    34,     1,   268,
     270,     0,    33,    32,    25,    31,    39,     0,     0,   210,
       0,   206,     0,   279,     0,     0,     0,     0,   183,    43,
      60,    59,    61,     0,   106,   117,   127,   134,   141,   148,
     155,   159,   164,   182,     0,    43,   231,   235,     0,     0,
     251,   201,     0,     0,   252,   254,   253,   258,   263,     0,
       0,     0,   261,     0,   274,    16,     0,    14,    23,    21,
      19,     4,    24,    26,     0,   204,   202,     0,     0,    42,
     249,    54,     0,    55,    46,   161,    82,    81,    83,     0,
      68,    87,    88,     0,    92,    93,    94,     0,   102,   103,
      98,    99,   100,   101,     0,   118,   119,   120,   121,     0,
     128,     0,   135,     0,   142,     0,   149,     0,   156,     0,
       0,   179,     0,    43,   282,   213,   209,   208,     0,   281,
       0,     0,     0,   209,     0,     0,     0,    35,    49,     0,
       0,   104,   115,   125,   132,   139,   146,   153,     0,   180,
     183,    34,     0,     0,     0,   257,   255,   259,     0,   260,
     265,     0,   277,     0,    15,    18,     0,    27,    30,     0,
      45,    53,     0,     0,     0,    48,    50,    79,    85,    90,
      96,   113,   123,   130,   137,   144,   151,     0,   178,   262,
      40,   283,   218,     0,   222,     0,   212,   183,     0,   183,
      47,   163,     0,   111,   107,   108,   109,   110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,     0,
     237,     0,   264,   266,   275,    20,    28,    44,    56,     0,
      52,   158,     0,   220,    61,    97,   214,     0,     0,     0,
       0,   105,   116,   126,   133,   140,   147,   154,     0,   181,
     183,     0,     0,   240,   238,     0,   243,     0,     0,    51,
     219,   221,     0,   183,     0,     0,   227,   160,     0,     0,
     247,   239,   244,   241,     0,   256,     0,   226,   223,     0,
     245,   248,   242,     0,   224,   246,   225
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    38,    39,    88,    41,   117,   230,   326,    42,   125,
     233,   126,   127,    43,   190,    44,   176,   130,   239,    45,
     191,   244,   335,   336,   242,    46,   193,    47,   148,    48,
      49,    50,    51,   150,   249,    52,   154,   253,    53,   155,
     257,    54,   156,   264,   195,   301,   368,    55,   157,   196,
     302,   269,    56,   158,   197,   303,   271,    57,   159,   198,
     304,   273,    58,   160,   199,   305,   275,    59,   161,   200,
     306,   277,    60,   162,   201,   307,   279,    61,   202,    62,
     361,   149,    63,   165,   204,   309,   104,   128,    65,   129,
      66,    91,    92,   295,   179,   356,    67,    68,    69,    70,
     101,    71,    72,    73,    74,    75,   380,   414,   415,   416,
     417,    76,    77,    78,   214,   215,   216,   112,    79,    80,
     219,   222,    81,    82,    83,    84,   114,    85,    93,    94
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -384
static const yytype_int16 yypact[] =
{
     535,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,
     212,  -384,  -384,  -384,    18,    -5,   859,    31,    41,    17,
      17,  1113,    90,   121,  1113,     1,    30,    38,   913,  1113,
     643,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,
      13,  -384,  -384,   125,  -384,  -384,    16,  -384,  -384,   110,
    1113,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,
     112,  -384,   100,   126,  -384,  -384,  -384,  -384,  -384,  -384,
    -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,
    -384,   175,   697,  -384,  -384,  -384,    30,    37,  -384,  -384,
      58,   -26,  -384,     3,  -384,  1113,   154,  1113,   967,  -384,
     131,  -384,  -384,  -384,   132,  1113,  1113,   137,   751,    85,
      14,   145,    43,  -384,    89,  -384,  -384,    78,   986,  -384,
     147,   140,   144,  -384,    13,   148,  -384,   146,   859,   150,
     102,   859,  1040,  -384,  -384,  -384,  -384,  -384,  -384,  -384,
    -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  1113,
       8,  1113,    96,  -384,   104,   109,    19,   -22,   127,   123,
     129,   128,   122,  1113,  1113,  -384,  -384,   102,  -384,  -384,
    -384,   145,  -384,  -384,  -384,  -384,   125,   186,  1113,  -384,
      18,  -384,    18,  -384,   160,   162,   163,    18,  1113,  -384,
     125,  -384,    16,   185,  -384,  -384,  -384,  -384,  -384,  -384,
    -384,   151,  -384,  -384,   158,  -384,  -384,  -384,   167,   170,
    -384,  -384,   172,     1,  -384,   178,  -384,  -384,  -384,    62,
      43,   589,  -384,    11,  -384,  -384,   107,  -384,  -384,  -384,
     176,  -384,  -384,   182,  1113,  -384,  -384,  1113,    18,  -384,
    -384,  -384,    77,  -384,   105,  -384,  -384,  -384,  -384,  1113,
    -384,  -384,  -384,  1113,  -384,  -384,  -384,  1113,  -384,  -384,
    -384,  -384,  -384,  -384,  1113,  -384,  -384,  -384,  -384,  1113,
    -384,  1113,  -384,  1113,  -384,  1113,  -384,  1113,  -384,  1113,
     168,   100,    43,  -384,   171,  -384,   171,  -384,   183,  -384,
     859,  1113,   859,     9,   113,   213,   187,    34,  -384,  1113,
    1113,    -2,   -22,   127,   123,   129,   128,   122,  1113,   188,
    1113,    94,   859,   191,    18,  -384,  -384,  -384,    18,   452,
    -384,   805,  -384,   189,  -384,   176,  1059,   130,  -384,   196,
    -384,  -384,  1113,  1113,    18,  -384,  -384,  -384,  -384,  -384,
    -384,  -384,  -384,  -384,  -384,  -384,  -384,  1113,  -384,  -384,
     102,  -384,   209,   201,  -384,  1113,  -384,  1113,  1113,  1113,
     105,  -384,   202,  -384,  -384,  -384,  -384,  -384,  1113,  1113,
    1113,  1113,  1113,  1113,  1113,   198,  1113,   190,  -384,    45,
    -384,   204,  -384,  -384,  -384,  -384,  -384,  -384,  -384,   207,
    -384,  -384,   859,   208,    16,  -384,  -384,   211,   210,   215,
     859,  -384,  -384,  -384,  -384,  -384,  -384,  -384,  1113,  -384,
    1113,  1113,   203,  -384,  -384,    45,  -384,    23,     1,  -384,
    -384,  -384,  1113,  1113,   859,   859,  -384,  -384,   218,   214,
     859,  -384,  -384,  -384,    71,  -384,   221,  -384,  -384,   859,
     859,  -384,  -384,   859,  -384,  -384,  -384
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -384,   166,  -384,     0,  -384,  -384,    36,   -17,  -384,  -384,
    -384,   -61,  -384,   257,  -384,  -384,  -384,   -76,  -384,  -384,
    -384,   -29,  -384,   -34,  -384,     4,  -384,  -384,  -384,   -40,
    -384,   222,    21,  -384,  -384,    15,  -384,  -384,    83,  -384,
    -384,    20,  -384,  -384,   -99,  -384,  -384,    22,  -384,   -94,
    -384,   -20,    12,  -384,   -93,  -384,   -23,    25,  -384,   -86,
    -384,   -16,    27,  -384,   -82,  -384,   -18,    28,  -384,   -79,
    -384,   -12,  -384,  -384,  -384,  -384,   -11,  -384,  -384,     5,
     -92,  -184,    10,    42,  -384,  -384,  -183,     7,   -24,  -125,
    -384,   111,   142,  -384,    24,  -384,  -384,  -384,  -384,  -384,
     282,  -384,  -384,  -384,  -384,  -384,  -384,  -109,  -108,  -383,
    -384,  -384,  -384,  -384,  -384,  -384,   114,   -98,  -384,   219,
    -384,  -208,  -384,   103,   -80,  -384,  -384,  -384,  -384,   143
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -263
static const yytype_int16 yytable[] =
{
      40,   109,   170,   235,   167,   296,   203,    64,   299,   133,
     153,   118,   319,   220,    90,   363,    40,   246,   180,   100,
     100,   181,   322,    96,   134,     8,   111,  -211,     8,     8,
     124,   103,   432,   119,   107,    95,   258,   259,   265,   120,
     172,     8,   173,   108,   266,   267,   268,   182,     8,   113,
     183,   432,   -38,   411,   152,   217,   364,   365,   247,   131,
     355,   323,   366,   367,    99,   248,   433,   135,   136,   137,
     110,    97,   237,   282,   349,   411,   412,   260,   261,   238,
     174,    98,    40,   262,   263,   221,   171,   175,   413,    64,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     226,   411,   192,   317,   177,   184,   318,   186,    40,   178,
     218,   250,   -37,   297,   442,   208,   209,   225,   331,   212,
     213,   332,   116,   229,    11,    12,    13,   377,    40,   311,
     105,    40,   237,   172,   223,   173,   224,   243,   240,   238,
     237,     8,   283,   333,   164,   132,   324,   238,   136,   137,
     334,   228,   251,   252,   245,   152,   298,   180,    32,    33,
     357,   106,    34,    35,    36,   132,    37,   163,   280,   281,
     254,   255,   256,   166,   397,   168,   399,   185,   206,   207,
     286,   194,   288,   285,   210,   110,   -33,   293,   231,   315,
     -32,   232,   234,   236,   272,   278,   270,   284,   103,   274,
     276,   290,   291,   300,   292,   310,   308,   350,   312,   337,
     422,   313,   314,   213,   347,     2,     3,     4,     5,     6,
     116,    40,   178,     8,     9,    10,   327,   428,    64,   177,
     392,   358,   376,   379,   359,   387,   384,   410,   330,   328,
     436,   170,   393,   400,   408,   418,   419,   329,    86,   430,
      28,   424,    29,   152,    87,   421,   425,   152,   423,   439,
     440,   152,   443,   396,   189,   325,   386,    89,   152,   360,
     402,   151,   339,   152,   338,   152,   403,   152,   404,   152,
     370,   152,   369,   152,   409,   343,   405,   372,   371,   341,
      40,   406,    40,   342,   373,   407,   374,   352,   294,   354,
     344,   353,   102,   192,   345,   441,   431,   346,   351,   434,
     362,     0,    40,   375,   381,   445,   427,   205,   382,   378,
     103,    40,   287,   348,   321,   289,     0,   175,    64,   316,
       0,   385,     0,     0,   390,     0,     0,   388,     0,     0,
       0,     0,     0,   389,     0,     0,     0,   340,     0,     0,
       0,     0,   391,     0,     0,     0,     0,     0,     0,   394,
     285,     0,     0,     0,     0,     0,     0,   103,   398,   103,
       0,     0,   152,   152,   152,   152,   152,   152,   152,     0,
     192,     0,   194,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    40,     0,   435,     0,     0,     0,     0,   420,
      40,     0,     0,     0,     0,     0,     0,   426,     0,     0,
       0,     0,   192,     0,     0,     0,     0,     0,     0,     0,
     103,   429,     0,     0,    40,    40,   394,   245,     0,     0,
      40,   437,   438,   103,     0,     0,     0,     0,   395,    40,
      40,     0,     0,    40,     0,     0,   444,     0,     0,     0,
     446,   401,   194,   194,   194,   194,   194,   194,     0,   194,
    -262,  -262,     0,     0,     0,     0,     0,     0,     0,  -262,
    -262,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   194,     0,     0,     0,     0,  -262,  -262,     0,     0,
       0,     0,  -262,  -262,     0,   395,     0,  -262,     0,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,     1,     0,     2,     3,
       4,     5,     6,     0,     0,     7,     8,     9,    10,    11,
      12,    13,     0,     0,    14,    15,     0,    16,    17,    18,
      19,    20,    21,    22,    23,     0,     0,    24,    25,     0,
       0,    26,    27,    28,     0,    29,     0,    30,     0,     0,
       0,     0,    31,    32,    33,     0,     0,    34,    35,    36,
       1,    37,     2,     3,     4,     5,     6,     0,     0,     0,
       8,     9,    10,    11,    12,    13,     0,     0,    14,    15,
       0,    16,    17,    18,    19,    20,    21,    22,    23,     0,
       0,    24,    25,     0,     0,    26,    27,    28,     0,    29,
       0,    30,   320,     0,     0,     0,    31,    32,    33,     0,
       0,    34,    35,    36,     0,    37,   121,     3,   122,     5,
       6,     0,     0,     0,     8,     9,    10,    11,    12,    13,
       0,     0,    14,    15,     0,    16,    17,    18,    19,    20,
      21,    22,    23,     0,     0,    24,    25,     0,     0,    86,
      27,    28,     0,    29,     0,    30,   123,     0,     0,     0,
      31,    32,    33,     0,     0,    34,    35,    36,     0,    37,
       2,     3,     4,     5,     6,     0,     0,   169,     8,     9,
      10,    11,    12,    13,     0,     0,    14,    15,     0,    16,
      17,    18,    19,    20,    21,    22,    23,     0,     0,    24,
      25,     0,     0,    26,    27,    28,     0,    29,     0,    30,
       0,     0,     0,     0,    31,    32,    33,     0,     0,    34,
      35,    36,     0,    37,     2,     3,     4,     5,     6,     0,
       0,     0,     8,     9,    10,    11,    12,    13,     0,     0,
      14,    15,     0,    16,    17,    18,    19,    20,    21,    22,
      23,     0,     0,    24,    25,     0,     0,    86,    27,    28,
       0,    29,     0,    30,   211,     0,     0,     0,    31,    32,
      33,     0,     0,    34,    35,    36,     0,    37,     2,     3,
       4,     5,     6,     0,     0,     0,     8,     9,    10,    11,
      12,    13,     0,     0,    14,    15,     0,    16,    17,    18,
      19,    20,    21,    22,    23,     0,     0,    24,    25,     0,
       0,    26,    27,    28,     0,    29,     0,    30,   383,     0,
       0,     0,    31,    32,    33,     0,     0,    34,    35,    36,
       0,    37,     2,     3,     4,     5,     6,     0,     0,     0,
       8,     9,    10,    11,    12,    13,     0,     0,    14,    15,
       0,    16,    17,    18,    19,    20,    21,    22,    23,     0,
       0,    24,    25,     0,     0,    86,    27,    28,     0,    29,
       0,    30,     0,     0,     0,     0,    31,    32,    33,     0,
       0,    34,    35,    36,     0,    37,     2,     3,     4,     5,
       6,     0,     0,     0,     8,     9,    10,    11,    12,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
       0,    28,   115,    29,     0,    87,     0,   116,     0,     0,
       0,    32,    33,     0,     0,    34,    35,    36,     0,    37,
       2,     3,     4,     5,     6,     0,     0,     0,     8,     9,
      10,    11,    12,    13,     0,     0,   187,     0,     0,     2,
       3,     4,     5,     6,     0,     0,     0,     8,     9,    10,
      11,    12,    13,    86,     0,    28,     0,    29,     0,    87,
       0,     0,     0,     0,   188,    32,    33,     0,     0,    34,
      35,    36,    86,    37,    28,   227,    29,     0,    87,     0,
     228,     0,     0,     0,    32,    33,     0,     0,    34,    35,
      36,     0,    37,     2,     3,     4,     5,     6,     0,     0,
       0,     8,     9,    10,    11,    12,    13,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     0,     0,     0,
       8,     9,    10,    11,    12,    13,    86,     0,    28,     0,
      29,   241,    87,     0,     0,     0,     0,     0,    32,    33,
       0,     0,    34,    35,    36,    86,    37,    28,     0,    29,
       0,    87,     0,   228,     0,     0,     0,    32,    33,     0,
       0,    34,    35,    36,     0,    37,     2,     3,     4,     5,
       6,     0,     0,     0,     8,     9,    10,    11,    12,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
       0,    28,     0,    29,     0,    87,     0,     0,     0,     0,
       0,    32,    33,     0,     0,    34,    35,    36,     0,    37
};

static const yytype_int16 yycheck[] =
{
       0,    25,    82,   128,    80,   188,    98,     0,   192,    43,
      50,    28,   220,   111,    14,    17,    16,     9,    44,    19,
      20,    47,    11,    16,     8,    11,    26,    18,    11,    11,
      30,    21,   415,    28,    24,    40,    17,    18,    60,    29,
       3,    11,     5,    42,    66,    67,    68,    44,    11,    11,
      47,   434,    18,    30,    50,    41,    58,    59,    50,    46,
      51,    50,    64,    65,    47,    57,    43,    51,    52,    53,
      40,    40,    38,   171,   282,    30,    31,    58,    59,    45,
      43,    40,    82,    64,    65,    42,    86,    87,    43,    82,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
     117,    30,    98,    41,    46,    95,    44,    97,   108,    51,
     110,   151,    18,   189,    43,   105,   106,    39,    41,    34,
      35,    44,    44,   118,    14,    15,    16,   310,   128,   205,
      40,   131,    38,     3,    45,     5,    47,   132,   131,    45,
      38,    11,   176,    38,    44,    40,    39,    45,    52,    53,
      45,    44,    48,    49,   149,   151,   190,    44,    48,    49,
      47,    40,    52,    53,    54,    40,    56,    55,   163,   164,
      61,    62,    63,    47,   357,     0,   359,    23,    47,    47,
     180,    98,   182,   178,    47,    40,    46,   187,    41,   213,
      46,    43,    46,    43,    71,    73,    69,    11,   188,    70,
      72,    41,    40,    18,    41,    47,    55,   283,    41,   249,
     394,    41,    40,    35,    46,     3,     4,     5,     6,     7,
      44,   221,    51,    11,    12,    13,    44,   410,   221,    46,
      21,    18,    44,    42,    47,    39,    47,    47,   238,   234,
     423,   321,    41,    41,    46,    41,    39,   237,    36,    46,
      38,    41,    40,   249,    42,    47,    41,   253,    47,    41,
      46,   257,    41,   355,    98,   229,   327,    10,   264,   298,
     369,    49,   257,   269,   253,   271,   370,   273,   371,   275,
     303,   277,   302,   279,   376,   273,   372,   305,   304,   269,
     290,   373,   292,   271,   306,   374,   307,   290,   187,   292,
     275,   291,    20,   299,   277,   430,   415,   279,   284,   417,
     300,    -1,   312,   308,   314,   440,   408,    98,   318,   312,
     310,   321,   180,   281,   221,   182,    -1,   327,   321,   215,
      -1,   326,    -1,    -1,   334,    -1,    -1,   332,    -1,    -1,
      -1,    -1,    -1,   333,    -1,    -1,    -1,   264,    -1,    -1,
      -1,    -1,   347,    -1,    -1,    -1,    -1,    -1,    -1,   355,
     355,    -1,    -1,    -1,    -1,    -1,    -1,   357,   358,   359,
      -1,    -1,   368,   369,   370,   371,   372,   373,   374,    -1,
     376,    -1,   299,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   392,    -1,   418,    -1,    -1,    -1,    -1,   392,
     400,    -1,    -1,    -1,    -1,    -1,    -1,   400,    -1,    -1,
      -1,    -1,   408,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     410,   411,    -1,    -1,   424,   425,   422,   422,    -1,    -1,
     430,   424,   425,   423,    -1,    -1,    -1,    -1,   355,   439,
     440,    -1,    -1,   443,    -1,    -1,   439,    -1,    -1,    -1,
     443,   368,   369,   370,   371,   372,   373,   374,    -1,   376,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   408,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,
      -1,    -1,    50,    51,    -1,   422,    -1,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,     1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    32,    33,    -1,
      -1,    36,    37,    38,    -1,    40,    -1,    42,    -1,    -1,
      -1,    -1,    47,    48,    49,    -1,    -1,    52,    53,    54,
       1,    56,     3,     4,     5,     6,     7,    -1,    -1,    -1,
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
       3,     4,     5,     6,     7,    -1,    -1,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    19,    20,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    32,
      33,    -1,    -1,    36,    37,    38,    -1,    40,    -1,    42,
      -1,    -1,    -1,    -1,    47,    48,    49,    -1,    -1,    52,
      53,    54,    -1,    56,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    11,    12,    13,    14,    15,    16,    -1,    -1,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    32,    33,    -1,    -1,    36,    37,    38,
      -1,    40,    -1,    42,    43,    -1,    -1,    -1,    47,    48,
      49,    -1,    -1,    52,    53,    54,    -1,    56,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    11,    12,    13,    14,
      15,    16,    -1,    -1,    19,    20,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    32,    33,    -1,
      -1,    36,    37,    38,    -1,    40,    -1,    42,    43,    -1,
      -1,    -1,    47,    48,    49,    -1,    -1,    52,    53,    54,
      -1,    56,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      11,    12,    13,    14,    15,    16,    -1,    -1,    19,    20,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    32,    33,    -1,    -1,    36,    37,    38,    -1,    40,
      -1,    42,    -1,    -1,    -1,    -1,    47,    48,    49,    -1,
      -1,    52,    53,    54,    -1,    56,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    38,    39,    40,    -1,    42,    -1,    44,    -1,    -1,
      -1,    48,    49,    -1,    -1,    52,    53,    54,    -1,    56,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    11,    12,
      13,    14,    15,    16,    -1,    -1,    19,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    11,    12,    13,
      14,    15,    16,    36,    -1,    38,    -1,    40,    -1,    42,
      -1,    -1,    -1,    -1,    47,    48,    49,    -1,    -1,    52,
      53,    54,    36,    56,    38,    39,    40,    -1,    42,    -1,
      44,    -1,    -1,    -1,    48,    49,    -1,    -1,    52,    53,
      54,    -1,    56,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      11,    12,    13,    14,    15,    16,    36,    -1,    38,    -1,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,
      -1,    -1,    52,    53,    54,    36,    56,    38,    -1,    40,
      -1,    42,    -1,    44,    -1,    -1,    -1,    48,    49,    -1,
      -1,    52,    53,    54,    -1,    56,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    38,    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    48,    49,    -1,    -1,    52,    53,    54,    -1,    56
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,    10,    11,    12,
      13,    14,    15,    16,    19,    20,    22,    23,    24,    25,
      26,    27,    28,    29,    32,    33,    36,    37,    38,    40,
      42,    47,    48,    49,    52,    53,    54,    56,    85,    86,
      87,    88,    92,    97,    99,   103,   109,   111,   113,   114,
     115,   116,   119,   122,   125,   131,   136,   141,   146,   151,
     156,   161,   163,   166,   171,   172,   174,   180,   181,   182,
     183,   185,   186,   187,   188,   189,   195,   196,   197,   202,
     203,   206,   207,   208,   209,   211,    36,    42,    87,    97,
      87,   175,   176,   212,   213,    40,   171,    40,    40,    47,
      87,   184,   184,   166,   170,    40,    40,   166,    42,   172,
      40,    87,   201,    11,   210,    39,    44,    89,    91,   163,
     166,     3,     5,    43,    87,    93,    95,    96,   171,   173,
     101,    46,    40,   107,     8,    51,    52,    53,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,   112,   165,
     117,   115,   109,   113,   120,   123,   126,   132,   137,   142,
     147,   152,   157,    55,    44,   167,    47,   101,     0,    10,
     208,    87,     3,     5,    43,    87,   100,    46,    51,   178,
      44,    47,    44,    47,   166,    23,   166,    19,    47,    85,
      98,   104,   109,   110,   122,   128,   133,   138,   143,   148,
     153,   158,   162,   164,   168,   203,    47,    47,   166,   166,
      47,    43,    34,    35,   198,   199,   200,    41,    87,   204,
     201,    42,   205,    45,    47,    39,    91,    39,    44,   163,
      90,    41,    43,    94,    46,   173,    43,    38,    45,   102,
     171,    41,   108,   163,   105,   163,     9,    50,    57,   118,
     113,    48,    49,   121,    61,    62,    63,   124,    17,    18,
      58,    59,    64,    65,   127,    60,    66,    67,    68,   135,
      69,   140,    71,   145,    70,   150,    72,   155,    73,   160,
     163,   163,   201,   107,    11,   163,    87,   176,    87,   213,
      41,    40,    41,    87,   175,   177,   170,   101,   107,   165,
      18,   129,   134,   139,   144,   149,   154,   159,    55,   169,
      47,   101,    41,    41,    40,   172,   200,    41,    44,   205,
      43,   207,    11,    50,    39,    90,    91,    44,   163,   166,
      87,    41,    44,    38,    45,   106,   107,   113,   116,   119,
     122,   125,   131,   136,   141,   146,   151,    46,   167,   205,
     101,   178,   171,   166,   171,    51,   179,    47,    18,    47,
     105,   164,   166,    17,    58,    59,    64,    65,   130,   135,
     140,   145,   150,   155,   160,   163,    44,   170,   171,    42,
     190,    87,    87,    43,    47,   163,    95,    39,   163,   166,
      87,   163,    21,    41,   109,   122,   164,   170,   166,   170,
      41,   122,   128,   133,   138,   143,   148,   153,    46,   164,
      47,    30,    31,    43,   191,   192,   193,   194,    41,    39,
     171,    47,   165,    47,    41,    41,   171,   164,   170,   166,
      46,   191,   193,    43,   192,   172,   170,   171,   171,    41,
      46,   173,    43,    41,   171,   173,   171
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
#line 126 "JSint.y"
    {
/*	//printf("identifier\n");*/
	(yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Identifier);
;}
    break;

  case 7:
#line 131 "JSint.y"
    {
/*	//printf("Literal\n");*/
	(yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression);
;}
    break;

  case 8:
#line 135 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::IntegerType(atoi((yyvsp[(1) - (1)].debug))); (yyval.ast_Expression)->debug = (yyvsp[(1) - (1)].debug);
	//printf("number\n");
;}
    break;

  case 10:
#line 140 "JSint.y"
    {
	char a[200];
	strcpy(a,(yyvsp[(1) - (1)].debug)+1);
	a[strlen(a)-1] = 0;
/*	std::cout<<a<<std::endl;*/
	(yyval.ast_Expression) = new ast::StringType(a); (yyval.ast_Expression)->debug = a;
;}
    break;

  case 13:
#line 148 "JSint.y"
    {
	(yyval.ast_Identifier) = new ast::Identifier((yyvsp[(1) - (1)].debug));
;}
    break;

  case 35:
#line 173 "JSint.y"
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
#line 183 "JSint.y"
    {
/*	//printf("MemberExpForIn\n");*/
;}
    break;

  case 43:
#line 191 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
;}
    break;

  case 46:
#line 197 "JSint.y"
    {
	(yyval.ast_CallExpression) = new ast::CallExpression(dynamic_cast<ast::Identifier*>((yyvsp[(1) - (3)].ast_Expression)), (yyvsp[(2) - (3)].ast_ArgumentList));
;}
    break;

  case 49:
#line 204 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
;}
    break;

  case 53:
#line 211 "JSint.y"
    {
	(yyval.ast_ArgumentList) = (yyvsp[(2) - (3)].ast_ArgumentList);
;}
    break;

  case 54:
#line 214 "JSint.y"
    {
	(yyval.ast_ArgumentList) = nullptr;
;}
    break;

  case 55:
#line 218 "JSint.y"
    {
	(yyval.ast_ArgumentList) = new ast::ArgumentList();
	(yyval.ast_ArgumentList)->push_back((yyvsp[(1) - (1)].ast_Expression));
;}
    break;

  case 56:
#line 222 "JSint.y"
    {
	(yyvsp[(1) - (3)].ast_ArgumentList)->push_back((yyvsp[(3) - (3)].ast_Expression));
	(yyval.ast_ArgumentList) = (yyvsp[(1) - (3)].ast_ArgumentList);
;}
    break;

  case 57:
#line 227 "JSint.y"
    {
	(yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_CallExpression);
;}
    break;

  case 58:
#line 230 "JSint.y"
    {
	(yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression);
/*	//printf("LeftHandExp\n");*/
;}
    break;

  case 60:
#line 235 "JSint.y"
    {

;}
    break;

  case 61:
#line 240 "JSint.y"
    {
	(yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression);
/*	//printf("postfixExp\n");*/
;}
    break;

  case 65:
#line 247 "JSint.y"
    {
	(yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression);
;}
    break;

  case 78:
#line 262 "JSint.y"
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

  case 79:
#line 273 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression),(yyvsp[(2) - (3)].ast_OpType),(yyvsp[(3) - (3)].ast_Expression));
	if ((yyvsp[(1) - (3)].ast_Expression) == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>((yyval.ast_Expression));
	}
;}
    break;

  case 80:
#line 280 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
;}
    break;

  case 81:
#line 283 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::mul;
;}
    break;

  case 82:
#line 286 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::div;
;}
    break;

  case 83:
#line 289 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::mod;
;}
    break;

  case 84:
#line 292 "JSint.y"
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

  case 85:
#line 303 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression),(yyvsp[(2) - (3)].ast_OpType),(yyvsp[(3) - (3)].ast_Expression));
	if ((yyvsp[(1) - (3)].ast_Expression) == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>((yyval.ast_Expression));
	}
;}
    break;

  case 86:
#line 310 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
;}
    break;

  case 87:
#line 313 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::plus;
;}
    break;

  case 88:
#line 316 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::minus;
;}
    break;

  case 89:
#line 319 "JSint.y"
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

  case 90:
#line 329 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression),(yyvsp[(2) - (3)].ast_OpType),(yyvsp[(3) - (3)].ast_Expression));
	if ((yyvsp[(1) - (3)].ast_Expression) == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>((yyval.ast_Expression));
	}
;}
    break;

  case 91:
#line 336 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
;}
    break;

  case 92:
#line 339 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::lsh;
;}
    break;

  case 93:
#line 342 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::rsh;
;}
    break;

  case 94:
#line 345 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::ursh;
;}
    break;

  case 95:
#line 348 "JSint.y"
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

  case 96:
#line 358 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression),(yyvsp[(2) - (3)].ast_OpType),(yyvsp[(3) - (3)].ast_Expression));
	if ((yyvsp[(1) - (3)].ast_Expression) == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>((yyval.ast_Expression));
	}
;}
    break;

  case 97:
#line 365 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
;}
    break;

  case 98:
#line 368 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::lt;
;}
    break;

  case 99:
#line 371 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::gt;
;}
    break;

  case 100:
#line 374 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::le;
;}
    break;

  case 101:
#line 377 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::ge;
;}
    break;

  case 102:
#line 380 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::iof;
;}
    break;

  case 103:
#line 383 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::iin;
;}
    break;

  case 112:
#line 394 "JSint.y"
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

  case 113:
#line 404 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression),(yyvsp[(2) - (3)].ast_OpType),(yyvsp[(3) - (3)].ast_Expression));
	if ((yyvsp[(1) - (3)].ast_Expression) == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>((yyval.ast_Expression));
	}
;}
    break;

  case 114:
#line 411 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
;}
    break;

  case 118:
#line 417 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::eq;
;}
    break;

  case 119:
#line 420 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::ne;
;}
    break;

  case 120:
#line 423 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::aeq;
;}
    break;

  case 121:
#line 426 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::ane;
;}
    break;

  case 122:
#line 429 "JSint.y"
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

  case 123:
#line 439 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression),(yyvsp[(2) - (3)].ast_OpType),(yyvsp[(3) - (3)].ast_Expression));
	if ((yyvsp[(1) - (3)].ast_Expression) == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>((yyval.ast_Expression));
	}
;}
    break;

  case 124:
#line 446 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
;}
    break;

  case 128:
#line 452 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::bit_and;
;}
    break;

  case 129:
#line 455 "JSint.y"
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

  case 130:
#line 465 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression),(yyvsp[(2) - (3)].ast_OpType),(yyvsp[(3) - (3)].ast_Expression));
	if ((yyvsp[(1) - (3)].ast_Expression) == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>((yyval.ast_Expression));
	}
;}
    break;

  case 131:
#line 472 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
;}
    break;

  case 135:
#line 478 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::bit_xor;
;}
    break;

  case 136:
#line 481 "JSint.y"
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

  case 137:
#line 491 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression),(yyvsp[(2) - (3)].ast_OpType),(yyvsp[(3) - (3)].ast_Expression));
	if ((yyvsp[(1) - (3)].ast_Expression) == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>((yyval.ast_Expression));
	}
;}
    break;

  case 138:
#line 498 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
;}
    break;

  case 142:
#line 504 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::bit_or;
;}
    break;

  case 143:
#line 507 "JSint.y"
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

  case 144:
#line 517 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression),(yyvsp[(2) - (3)].ast_OpType),(yyvsp[(3) - (3)].ast_Expression));
	if ((yyvsp[(1) - (3)].ast_Expression) == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>((yyval.ast_Expression));
	}
;}
    break;

  case 145:
#line 524 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
;}
    break;

  case 149:
#line 530 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::land;
;}
    break;

  case 150:
#line 533 "JSint.y"
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

  case 151:
#line 543 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression),(yyvsp[(2) - (3)].ast_OpType),(yyvsp[(3) - (3)].ast_Expression));
	if ((yyvsp[(1) - (3)].ast_Expression) == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>((yyval.ast_Expression));
	}
;}
    break;

  case 152:
#line 550 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
;}
    break;

  case 156:
#line 556 "JSint.y"
    {
	(yyval.ast_OpType) = ast::BinaryOperator::OpType::lor;
;}
    break;

  case 157:
#line 559 "JSint.y"
    {
	(yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression);
;}
    break;

  case 158:
#line 562 "JSint.y"
    {
;}
    break;

  case 161:
#line 567 "JSint.y"
    {
	(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (3)].ast_Expression),(yyvsp[(2) - (3)].ast_OpType),(yyvsp[(3) - (3)].ast_Expression));
/*	//printf("an assign exp\n");*/
;}
    break;

  case 162:
#line 571 "JSint.y"
    {
	(yyval.ast_Expression) = (yyvsp[(1) - (1)].ast_Expression);
	//printf("an assign exp from condition\n");
;}
    break;

  case 163:
#line 575 "JSint.y"
    {;}
    break;

  case 165:
#line 577 "JSint.y"
    {
	(yyval.ast_OpType) =ast::BinaryOperator::OpType::assign;
	//printf("an assign\n");
;}
    break;

  case 177:
#line 593 "JSint.y"
    {
	if ((yyvsp[(2) - (2)].ast_Expression) == nullptr){
		(yyval.ast_Expression) = (yyvsp[(1) - (2)].ast_Expression);
	}
	else {
		(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(1) - (2)].ast_Expression),ast::BinaryOperator::OpType::comma,(yyvsp[(2) - (2)].ast_Expression));
	}


;}
    break;

  case 178:
#line 603 "JSint.y"
    {
	if ((yyvsp[(3) - (3)].ast_Expression) == nullptr) {
		(yyval.ast_Expression) = (yyvsp[(2) - (3)].ast_Expression);
	} else {
		(yyval.ast_Expression) = new ast::BinaryOperator((yyvsp[(2) - (3)].ast_Expression),ast::BinaryOperator::OpType::comma,(yyvsp[(3) - (3)].ast_Expression));
	}

;}
    break;

  case 179:
#line 611 "JSint.y"
    {
	(yyval.ast_Expression) = nullptr;
;}
    break;

  case 190:
#line 627 "JSint.y"
    {
	(yyval.ast_Statement) = (yyvsp[(1) - (1)].ast_Statement);
;}
    break;

  case 216:
#line 657 "JSint.y"
    {
	(yyval.ast_Statement) = (yyvsp[(1) - (1)].ast_Expression);
;}
    break;

  case 217:
#line 660 "JSint.y"
    {
	(yyval.ast_Statement) = (yyvsp[(1) - (2)].ast_Expression);
;}
    break;

  case 258:
#line 704 "JSint.y"
    {
	(yyval.ast_ParameterList) = new ast::ParameterList();
;}
    break;

  case 259:
#line 707 "JSint.y"
    {
	(yyval.ast_ParameterList) = (yyvsp[(2) - (3)].ast_ParameterList);
;}
    break;

  case 260:
#line 711 "JSint.y"
    {
	(yyval.ast_FunctionDeclaration) = new ast::FunctionDeclaration((ast::Identifier*)(yyvsp[(2) - (4)].ast_Identifier), (yyvsp[(3) - (4)].ast_ParameterList), (yyvsp[(4) - (4)].ast_StatementList));
;}
    break;

  case 263:
#line 718 "JSint.y"
    {
	(yyval.ast_ParameterList) = new ast::ParameterList();
	(yyval.ast_ParameterList)->push_back((yyvsp[(1) - (1)].ast_Identifier));
;}
    break;

  case 264:
#line 722 "JSint.y"
    {
	(yyvsp[(1) - (3)].ast_ParameterList)->push_back((yyvsp[(3) - (3)].ast_Identifier));
	(yyval.ast_ParameterList) = (yyvsp[(1) - (3)].ast_ParameterList);
;}
    break;

  case 265:
#line 727 "JSint.y"
    {
	(yyval.ast_StatementList) = nullptr;
;}
    break;

  case 266:
#line 730 "JSint.y"
    {
	(yyval.ast_StatementList) = (yyvsp[(2) - (3)].ast_StatementList);
;}
    break;

  case 268:
#line 736 "JSint.y"
    {
	(yyval.ast_StatementList) = (yyvsp[(1) - (2)].ast_StatementList);
;}
    break;

  case 269:
#line 739 "JSint.y"
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

  case 270:
#line 761 "JSint.y"
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

  case 273:
#line 785 "JSint.y"
    {
	(yyval.ast_Statement) = (yyvsp[(1) - (1)].ast_Statement);
;}
    break;


/* Line 1267 of yacc.c.  */
#line 3005 "parser.cpp"
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



