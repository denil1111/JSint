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
// example
// old one->ElementList	:	( Elision )? AssignmentExpression ( Elision AssignmentExpression )*
//new one
ElementList	:	Elision AssignmentExpression ElementListPart
|   AssignmentExpression ElementListPart
ElementListPart :   ElementListPart Elision Assignment
|
Elision	:   ","
|   Elision "," 
ObjectLiteral	:	"{" PropertyNameAndValueList "}"
|   "{"  "}"
//here is an example
//old one-->PropertyNameAndValueList	:	PropertyNameAndValue ( "," PropertyNameAndValue | "," )*
//new one 
PropertyNameAndValueList	:	PropertyNameAndValue PropertyNameAndValueListPart
PropertyNameAndValueListPart    :   PropertyNameAndValueListPart ","
|   PropertyNameAndValueListPart "," PropertyNameAndValue 
|   

PropertyNameAndValue	:	PropertyName ":" AssignmentExpression
PropertyName	:	Identifier
|	<STRING_LITERAL>
|	<DECIMAL_LITERAL>
MemberExpression	:  MemberExpressionForIn
|	AllocationExpression
MemberExpressionForIn	:	FunctionExpression MemberExpressionParts
|   PrimaryExpression MemberExpressionParts

//example 2
//old one -->AllocationExpression	:	( "new" MemberExpression ( ( Arguments ( MemberExpressionPart )* )* ) )
//new one
AllocationExpression    :   "new" MemberExpression AllocationExpressionBody
AllocationExpressionBody    :   AllocationExpressionBody Arguments MemberExpressionParts
|
MemberExpressionParts   :   MemberExpressionParts MemberExpressionPart
|
MemberExpressionPart    :   "[" Expression "]"
|	"." Identifier
CallExpression	:	MemberExpression Arguments CallExpressionParts
CallExpressionForIn	:	MemberExpressionForIn Arguments CallExpressionParts
CallExpressionParts :   CallExpressionParts CallExpressionPart
|
CallExpressionPart	:	Arguments
|   "[" Expression "]"
|	"." Identifier
Arguments	:	"(" ArgumentList ")"
|   "(" ")"
ArgumentList	:	AssignmentExpression ElAssignmentExpressions
ElAssignmentExpressions :  ElAssignmentExpressions "," AssignmentExpression
|
LeftHandSideExpression	:	CallExpression
|	MemberExpression
LeftHandSideExpressionForIn	:	CallExpressionForIn
|	MemberExpressionForIn
//李逸婷
PostfixExpression	:	LeftHandSideExpression
| LeftHandSideExpression PostfixOperator
PostfixOperator	:	 "++" 
| "--" 
UnaryExpression	:	PostfixExpression 
| UnaryExpressionPart
UnaryExpressionPart : UnaryOperator UnaryExpression
| UnaryExpressionPart UnaryOperator UnaryExpression
UnaryOperator	:	"delete" 
| "void" 
| "typeof" 
| "++" 
| "--" 
| "+" 
| "-" 
| "~" 
| "!" 
MultiplicativeExpression	:    UnaryExpression MultiplicativeExpressionPart
MultiplicativeExpressionPart  : MultiplicativeExpressionPart MultiplicativeOperator UnaryExpression
|
MultiplicativeOperator	:	"*" 
| <SLASH> 
| "%" 
AdditiveExpression	:	MultiplicativeExpression AdditiveExpressionPart
AdditiveExpressionPart  :   AdditiveExpressionPart AdditiveOperator MultiplicativeExpression
|
AdditiveOperator	:	"+" 
| "-" 
ShiftExpression	:	AdditiveExpression ShiftExpressionPart
ShiftExpressionPart :   ShiftExpressionPart ShiftOperator AdditiveExpression
|
ShiftOperator	:	"<<" 
| ">>" 
| ">>>" 
RelationalExpression	:	ShiftExpression RelationalExpressionPart
RelationalExpressionPart  :   RelationalExpressionPart RelationalOperator ShiftExpression
|
RelationalOperator	:	"<" 
| ">" 
| "<=" 
| ">=" 
| "instanceof" 
| "in" 
RelationalExpressionNoIn	:	ShiftExpression RelationalExpressionNoInPart
RelationalExpressionNoInPart  :   RelationalExpressionNoInPart RelationalNoInOperator ShiftExpression
|
RelationalNoInOperator	:	"<" 
| ">" 
| "<=" 
| ">=" 
| "instanceof" 
EqualityExpression	:	RelationalExpression EqualityExpressionPart
EqualityExpressionPart  :   EqualityExpressionPart EqualityOperator RelationalExpression
|
EqualityExpressionNoIn	:	RelationalExpressionNoIn EqualityExpressionNoInPart
EqualityExpressionNoInPart  :   EqualityExpressionNoInPart EqualityOperator RelationalExpressionNoIn
|
EqualityOperator	:	"==" 
| "!=" 
| "===" 
| "!==" 
BitwiseANDExpression	:	EqualityExpression BitwiseANDExpressionPart
BitwiseANDExpressionPart  :   BitwiseANDExpressionPart BitwiseANDOperator EqualityExpression
|
BitwiseANDExpressionNoIn	:	EqualityExpressionNoIn BitwiseANDExpressionNoInPart
BitwiseANDExpressionNoInPart  :   BitwiseANDExpressionNoInPart BitwiseANDOperator EqualityExpressionNoIn
|
BitwiseANDOperator	:	"&"
BitwiseXORExpression	:	BitwiseANDExpression BitwiseXORExpressionPart
BitwiseXORExpressionPart   :   BitwiseXORExpressionPart BitwiseXOROperator BitwiseANDExpression
|
BitwiseXORExpressionNoIn	:	BitwiseANDExpressionNoIn BitwiseXORExpressionNoInPart
BitwiseXORExpressionNoInPart   :   BitwiseXORExpressionNoInPart BitwiseXOROperator BitwiseANDExpressionNoIn
|
BitwiseXOROperator	:	"^"
BitwiseORExpression	:	BitwiseXORExpression BitwiseORExpressionPart
BitwiseORExpressionPart   :   BitwiseORExpressionPart BitwiseOROperator BitwiseXORExpression
|
BitwiseORExpressionNoIn	:	BitwiseXORExpressionNoIn BitwiseORExpressionNoInPart
BitwiseORExpressionNoInPart   :   BitwiseORExpressionNoInPart BitwiseOROperator BitwiseXORExpressionNoIn
|
BitwiseOROperator	:	"|"
LogicalANDExpression	:	BitwiseORExpression LogicalANDExpressionPart
LogicalANDExpressionPart   :   LogicalANDExpressionPart LogicalANDOperator BitwiseORExpression
|
LogicalANDExpressionNoIn	:	BitwiseORExpressionNoIn LogicalANDExpressionNoInPart
LogicalANDExpressionNoInPart   :   LogicalANDExpressionNoInPart LogicalANDOperator BitwiseORExpressionNoIn
|
LogicalANDOperator	:	"&&"
LogicalORExpression	:	LogicalANDExpression LogicalORExpressionPart
LogicalORExpressionPart   :   LogicalORExpressionPart LogicalOROperator LogicalANDExpression
|
LogicalORExpressionNoIn	:	LogicalANDExpressionNoIn LogicalORExpressionNoInPart
LogicalORExpressionNoInPart   :   LogicalORExpressionNoInPart LogicalOROperator LogicalANDExpressionNoIn
|
LogicalOROperator	:	"||"
ConditionalExpression	:	LogicalORExpression
|LogicalORExpression "?" AssignmentExpression ":" AssignmentExpression
ConditionalExpressionNoIn	:	LogicalORExpressionNoIn
|LogicalORExpressionNoIn "?" AssignmentExpression ":" AssignmentExpressionNoIn
AssignmentExpression	:	LeftHandSideExpression AssignmentOperator AssignmentExpression 
| ConditionalExpression
AssignmentExpressionNoIn	:	LeftHandSideExpression AssignmentOperator AssignmentExpressionNoIn 
| ConditionalExpressionNoIn
AssignmentOperator	:	"=" 
| "*=" 
| <SLASHASSIGN> 
| "%=" 
| "+=" 
| "-=" 
| "<<=" 
| ">>=" 
| ">>>=" 
| "&=" 
| "^=" 
| "|=" 
Expression	:	AssignmentExpression ExpressionPart
ExpressionPart   :   ExpressionPart "," AssignmentExpression
|
ExpressionNoIn	:	AssignmentExpressionNoIn ExpressionNoInPart
ExpressionNoInPart   :   ExpressionNoInPart "," AssignmentExpressionNoIn
|

//陈睿
ExpressionOrNull: | Expression
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
Block	:	"{}"
|   "{" StatementList "}"
StatementList	:	Statement
|   Statement StatementList						
VariableStatement	:	"var" VariableDeclarationList
|   "var" VariableDeclarationList ";"
VariableDeclarationList	:	VariableDeclaration VariableDeclarationListPart
VariableDeclarationListPart : VariableDeclarationListPart  "," VariableDeclaration
|
VariableDeclarationListNoIn	:	VariableDeclarationNoIn VariableDeclarationNoInPart
VariableDeclarationListNotInPart: VariableDeclarationListNotInPart  "," VariableDeclarationNoIn
|
VariableDeclaration	:	Identifier
| Identifier Initialiser
VariableDeclarationNoIn	:	Identifier
| Identifier  InitialiserNoIn
Initialiser	:	"=" AssignmentExpression
InitialiserNoIn	:	"=" AssignmentExpressionNoIn
EmptyStatement	:	";"
ExpressionStatement	:	Expression
| Expression ";"
IfStatement	:	"if" "(" Expression ")" Statement
| "if" "(" Expression ")" Statement "else" Statement
IterationStatement	:	"do" Statement "while" "(" Expression ")"
|   "do" Statement "while" "(" Expression ")" ";"
|	"while" "(" Expression ")" Statement
|	"for" "(" ";" ExpressionOrNull ";" ExpressionOrNull ")" Statement
|	"for" "(" ExpressionNoIn ";" ExpressionOrNull ";" ExpressionOrNull ")" Statement
|	"for" "(" "var" VariableDeclarationList ";" ExpressionOrNull ";" ExpressionOrNull ")" Statement
|	"for" "(" "var" VariableDeclarationNoIn "in" Expression ")" Statement
|	"for" "(" LeftHandSideExpressionForIn "in" Expression ")" Statement
IdentifierComma  :
| Identifier
| ";"
| Identifier ";"
ContinueStatement	:	"continue" IdentifierComma
BreakStatement	:	"break" IdentifierComma
ReturnStatement	:	"return" ExpressionOrNull
| "return" ExpressionOrNull ";"
WithStatement	:	"with" "(" Expression ")" Statement
SwitchStatement	:	"switch" "(" Expression ")" CaseBlock
CaseBlock	    :	"{"
| "{" CaseClauses
CaseBlockPart   :   "}"
| DefaultClause "}"
| CaseClauses "}"
CaseClauses	    :	CaseClause
| CaseClauses CaseClause
CaseClause	    :	"case" Expression ":"
| "case" Expression ":" StatementList
DefaultClause	:	"default" ":"
| "default" ":" StatementList
LabelledStatement	:	Identifier ":" Statement
ThrowStatement	:	"throw" Expression
| "throw" Expression ";"
TryStatement	:	"try" Block TryStatmentPart
TryStatementPart:   Finally
| Catch
| Catch Finally
Catch	:	"catch" "(" Identifier ")" Block
Finally	:	"finally" Block
FormalParameterListInPare: "()"
| "(" FormalParameterList ")"
FunctionDeclaration	:	"function" Identifier FormalParameterListInPare FunctionBody
FunctionExpression	:	"function" FormalParameterListPare FunctionBody
| "function" Identifier FormalParameterListPare FunctionBody
FormalParameterList	:	Identifier
| FormalParameterList "," Identifier
FunctionBody	:	"{}"
| "{" SourceElements "}"
Program	:	<EOF>
| SourceElements <EOF>
SourceElements	:	SourceElement
| SourceElements SourceElement
SourceElement	:	FunctionDeclaration
|	Statement
ImportStatement	:	"import" Name ";"
| "import" Name "." "*"  ";"
Name	:	<IDENTIFIER_NAME>
| Name "." <IDENTIFIER_NAME>
JScriptVarStatement	:	"var" JScriptVarDeclarationList
| "var" JScriptVarDeclarationList ";"
JScriptVarDeclarationList	:	JScriptVarDeclaration
| JScriptVarDeclarationList "," JScriptVarDeclaration
JScriptVarDeclaration	:	Identifier ":" <IDENTIFIER_NAME>
| Identifier ":" <IDENTIFIER_NAME> Initialiser
