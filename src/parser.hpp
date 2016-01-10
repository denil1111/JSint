/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 251 "parser.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

