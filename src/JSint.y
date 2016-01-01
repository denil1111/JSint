%{
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
%}
%union{
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
}

%token PROGRAM IDD DOT EQUAL LTHAN LEQU GT GE PLUS MINUS MUL DIV RIGHTP LEFTP 
%token ASSIGN COLON COMMA SEMI UNTIL OR AND MOD OF READ REPEAT TO UNEQUAL 
%token IF THEN ELSE WHILE DO BEGINN END CASE DOWNTO FOR GOTO INTEGER LB RB NOT 
%token NUMBER SYS_CON SYS_BOOL SYS_FUNCT SYS_PROC SYS_TYPE CHAR CONST STRING REAL ARRAY 
%token VAR PROCEDURE RECORD FUNCTION TYPE

%start program

%type <debug> PROGRAM IDD DOT NAME EQUAL LTHAN LEQU GT GE PLUS MINUS MUL DIV 
%type <debug> ASSIGN COLON COMMA SEMI IF THEN ELSE WHILE DO BEGINN FUNCTION LB
%type <debug> NOT OR AND MOD OF READ REPEAT TO UNEQUAL UNTIL NUMBER SYS_CON RB
%type <debug> SYS_FUNCT SYS_PROC SYS_TYPE CHAR CONST STRING REAL ARRAY VAR TYPE 
%type <debug> RIGHTP LEFTP DOWNTO FOR GOTO INTEGER PROCEDURE RECORD END CASE SYS_BOOL

// default type is ast node
%type <ast_Node> label_part  

%type <ast_Program> 		program program_head routine routine_head sub_routine
%type <ast_TypeDecl> 		type_decl   array_type_decl record_type_decl simple_type_decl
%type <ast_Statement> 		proc_stmt stmt non_label_stmt else_clause for_stmt repeat_stmt while_stmt if_stmt
%type <ast_Statement>		goto_stmt case_stmt 
%type <ast_AssignmentStmt> 	assign_stmt 
%type <ast_Expression> 		expression expr term factor
%type <ast_Routine> 		function_decl function_head procedure_head procedure_decl
%type <ast_ConstValue>      const_value
%type <ast_TypeConst>       type_definition

%type <ast_TypeDeclList>    type_part type_decl_list
%type <ast_VarDeclList> 	parameters para_decl_list para_type_list
%type <ast_RoutineList> 	routine_part 
%type <ast_StatementList> 	routine_body compound_stmt stmt_list 
%type <ast_VarDeclList> 	var_part var_decl_list var_decl
%type <ast_NameList> 		name_list
%type <ast_ExpressionList>  expression_list
%type <ast_ConstDeclList>   const_expr_list const_part
%type <ast_FieldDeclList>   field_decl_list field_decl
%type <ast_CaseStmt>		case_expr 
%type <ast_CaseList>		case_expr_list

%%
//张宇昊
PrimaryExpression	:	"this"
|	ObjectLiteral
|	"(" Expression ")" 
|	Identifier
|	ArrayLiteral
|	Literal
Literal	:	<DECIMAL_LITERAL> | <HEX_INTEGER_LITERAL> | <STRING_LITERAL> | <BOOLEAN_LITERAL> | <NULL_LITERAL> | <REGULAR_EXPRESSION_LITERAL> 
Identifier	:	<IDENTIFIER_NAME>
ArrayLiteral    :  "[" Elision "]"
|   "[" ElementList Elision "]"
|   "[" ElementList "]"
|   "[" "]"
ElementList	:	( Elision )? AssignmentExpression ( Elision AssignmentExpression )*
ElementList	:	Elision AssignmentExpression 
|   AssignmentExpression
|   ElementList Elision AssignmentExpression
Elision	:   ","
|   Elision "," 
ObjectLiteral	:	"{" PropertyNameAndValueList "}"
|   "{" PropertyNameAndValueList "}"
//here is an example
//old one-->PropertyNameAndValueList	:	PropertyNameAndValue ( "," PropertyNameAndValue | "," )*
//new one 
PropertyNameAndValueList	:	PropertyNameAndValue 
|   PropertyNameAndValueList "," PropertyNameAndValue 
|   propertyNameAndValueList ","

PropertyNameAndValue	:	PropertyName ":" AssignmentExpression
PropertyName	:	Identifier
|	<STRING_LITERAL>
|	<DECIMAL_LITERAL>
MemberExpression	:  MemberExpressionForIn
|	AllocationExpression
MemberExpressionForIn	:	FunctionExpression 
|   PrimaryExpression
|   MemberExpressionForIn MemberExpressionPart
//example 2
//old one -->AllocationExpression	:	( "new" MemberExpression ( ( Arguments ( MemberExpressionPart )* )* ) )
//new one
AllocationExpression    :   "new" MemberExpression 
|   AllocationExpression    AllocationExpressionPart
AllocationExpressionPart    :   Arguments
|   AllocationExpressionPart    MemberExpressionPart

MemberExpressionPart    :   "[" Expression "]"
|	"." Identifier
CallExpression	:	MemberExpression Arguments 
|   CallExpression  CallExpressionPart 

CallExpressionForIn	:	MemberExpressionForIn Arguments 
|   MemberExpressionForIn CallExpressionPart 
CallExpressionPart	:	Arguments
|   "[" Expression "]"
|	"." Identifier
Arguments	:	"(" ArgumentList ")"
|   "(" ")"
ArgumentList	:	AssignmentExpression 
|   AssignmentExpression "," AssignmentExpression
LeftHandSideExpression	:	CallExpression
|	MemberExpression
LeftHandSideExpressionForIn	:	CallExpressionForIn
//李逸婷
|	MemberExpressionForIn
PostfixExpression	:	LeftHandSideExpression ( PostfixOperator )?
PostfixOperator	:	( "++" | "--" )
UnaryExpression	:	( PostfixExpression | ( UnaryOperator UnaryExpression )+ )
UnaryOperator	:	( "delete" | "void" | "typeof" | "++" | "--" | "+" | "-" | "~" | "!" )
MultiplicativeExpression	:	UnaryExpression ( MultiplicativeOperator UnaryExpression )*
MultiplicativeOperator	:	( "*" | <SLASH> | "%" )
AdditiveExpression	:	MultiplicativeExpression ( AdditiveOperator MultiplicativeExpression )*
AdditiveOperator	:	( "+" | "-" )
ShiftExpression	:	AdditiveExpression ( ShiftOperator AdditiveExpression )*
ShiftOperator	:	( "<<" | ">>" | ">>>" )
RelationalExpression	:	ShiftExpression ( RelationalOperator ShiftExpression )*
RelationalOperator	:	( "<" | ">" | "<=" | ">=" | "instanceof" | "in" )
RelationalExpressionNoIn	:	ShiftExpression ( RelationalNoInOperator ShiftExpression )*
RelationalNoInOperator	:	( "<" | ">" | "<=" | ">=" | "instanceof" )
EqualityExpression	:	RelationalExpression ( EqualityOperator RelationalExpression )*
EqualityExpressionNoIn	:	RelationalExpressionNoIn ( EqualityOperator RelationalExpressionNoIn )*
EqualityOperator	:	( "==" | "!=" | "===" | "!==" )
BitwiseANDExpression	:	EqualityExpression ( BitwiseANDOperator EqualityExpression )*
BitwiseANDExpressionNoIn	:	EqualityExpressionNoIn ( BitwiseANDOperator EqualityExpressionNoIn )*
BitwiseANDOperator	:	"&"
BitwiseXORExpression	:	BitwiseANDExpression ( BitwiseXOROperator BitwiseANDExpression )*
BitwiseXORExpressionNoIn	:	BitwiseANDExpressionNoIn ( BitwiseXOROperator BitwiseANDExpressionNoIn )*
BitwiseXOROperator	:	"^"
BitwiseORExpression	:	BitwiseXORExpression ( BitwiseOROperator BitwiseXORExpression )*
BitwiseORExpressionNoIn	:	BitwiseXORExpressionNoIn ( BitwiseOROperator BitwiseXORExpressionNoIn )*
BitwiseOROperator	:	"|"
LogicalANDExpression	:	BitwiseORExpression ( LogicalANDOperator BitwiseORExpression )*
LogicalANDExpressionNoIn	:	BitwiseORExpressionNoIn ( LogicalANDOperator BitwiseORExpressionNoIn )*
LogicalANDOperator	:	"&&"
LogicalORExpression	:	LogicalANDExpression ( LogicalOROperator LogicalANDExpression )*
LogicalORExpressionNoIn	:	LogicalANDExpressionNoIn ( LogicalOROperator LogicalANDExpressionNoIn )*
LogicalOROperator	:	"||"
ConditionalExpression	:	LogicalORExpression ( "?" AssignmentExpression ":" AssignmentExpression )?
ConditionalExpressionNoIn	:	LogicalORExpressionNoIn ( "?" AssignmentExpression ":" AssignmentExpressionNoIn )?
AssignmentExpression	:	( LeftHandSideExpression AssignmentOperator AssignmentExpression | ConditionalExpression )
AssignmentExpressionNoIn	:	( LeftHandSideExpression AssignmentOperator AssignmentExpressionNoIn | ConditionalExpressionNoIn )
AssignmentOperator	:	( "=" | "*=" | <SLASHASSIGN> | "%=" | "+=" | "-=" | "<<=" | ">>=" | ">>>=" | "&=" | "^=" | "|=" )
Expression	:	AssignmentExpression ( "," AssignmentExpression )*
ExpressionNoIn	:	AssignmentExpressionNoIn ( "," AssignmentExpressionNoIn )*

//陈睿
Statement	:	Block
|	JScriptVarStatement
|	VariableStatement
|	EmptyStatement
|	LabelledStatement
|	ExpressionStatement
|	IfStatement
|	IterationStatement
|	ContinueStatement
|	BreakStatement
|	ImportStatement
|	ReturnStatement
|	WithStatement
|	SwitchStatement
|	ThrowStatement
|	TryStatement
Block	:	"{" ( StatementList )? "}"
StatementList	:	( Statement )+
VariableStatement	:	"var" VariableDeclarationList ( ";" )?
VariableDeclarationList	:	VariableDeclaration ( "," VariableDeclaration )*
VariableDeclarationListNoIn	:	VariableDeclarationNoIn ( "," VariableDeclarationNoIn )*
VariableDeclaration	:	Identifier ( Initialiser )?
VariableDeclarationNoIn	:	Identifier ( InitialiserNoIn )?
Initialiser	:	"=" AssignmentExpression
InitialiserNoIn	:	"=" AssignmentExpressionNoIn
EmptyStatement	:	";"
ExpressionStatement	:	Expression ( ";" )?
IfStatement	:	"if" "(" Expression ")" Statement ( "else" Statement )?
IterationStatement	:	( "do" Statement "while" "(" Expression ")" ( ";" )? )
|	( "while" "(" Expression ")" Statement )
|	( "for" "(" ( ExpressionNoIn )? ";" ( Expression )? ";" ( Expression )? ")" Statement )
|	( "for" "(" "var" VariableDeclarationList ";" ( Expression )? ";" ( Expression )? ")" Statement )
|	( "for" "(" "var" VariableDeclarationNoIn "in" Expression ")" Statement )
|	( "for" "(" LeftHandSideExpressionForIn "in" Expression ")" Statement )
ContinueStatement	:	"continue" ( Identifier )? ( ";" )?
BreakStatement	:	"break" ( Identifier )? ( ";" )?
ReturnStatement	:	"return" ( Expression )? ( ";" )?
WithStatement	:	"with" "(" Expression ")" Statement
SwitchStatement	:	"switch" "(" Expression ")" CaseBlock
CaseBlock	:	"{" ( CaseClauses )? ( "}" | DefaultClause ( CaseClauses )? "}" )
CaseClauses	:	( CaseClause )+
CaseClause	:	( ( "case" Expression ":" ) ) ( StatementList )?
DefaultClause	:	( ( "default" ":" ) ) ( StatementList )?
LabelledStatement	:	Identifier ":" Statement
ThrowStatement	:	"throw" Expression ( ";" )?
TryStatement	:	"try" Block ( ( Finally | Catch ( Finally )? ) )
Catch	:	"catch" "(" Identifier ")" Block
Finally	:	"finally" Block
FunctionDeclaration	:	"function" Identifier ( "(" ( FormalParameterList )? ")" ) FunctionBody
FunctionExpression	:	"function" ( Identifier )? ( "(" ( FormalParameterList )? ")" ) FunctionBody
FormalParameterList	:	Identifier ( "," Identifier )*
FunctionBody	:	"{" ( SourceElements )? "}"
Program	:	( SourceElements )? <EOF>
SourceElements	:	( SourceElement )+
SourceElement	:	FunctionDeclaration
|	Statement
ImportStatement	:	"import" Name ( "." "*" )? ";"
Name	:	<IDENTIFIER_NAME> ( "." <IDENTIFIER_NAME> )*
JScriptVarStatement	:	"var" JScriptVarDeclarationList ( ";" )?
JScriptVarDeclarationList	:	JScriptVarDeclaration ( "," JScriptVarDeclaration )*
JScriptVarDeclaration	:	Identifier ":" <IDENTIFIER_NAME> ( Initialiser )?