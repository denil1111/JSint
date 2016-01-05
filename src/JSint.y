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

%token DECIMAL_LITERAL HEX_INTEGER_LITERAL STRING_LITERAL BOOLEAN_LITERAL NULL_LITERAL
%token SLASHASSIGN SLASH JEOF IDENTIFIER_NAME
%token THIS NEW DELETE VOID TYPEOF INSTANCEOF IN VAR IF ELSE DO WHILE FOR CONTINUE BREAK RETURN WITH SWITCH CASE DEFAULT THROW TRY CATCH FINALLY FUNCTION IMPORT
％token LEFT_BRACKET RIGHT_BRACKET LEFT_PARE RIGHT_PARE LEFT_BRACE RIGHT_BRACE COMMA DOT COLON SEMICOLON 
%token PLUS MINUS MULTI DIV ASSIGN PLUS_PLUS MINUS_MINUS TILDE QUES EXCLAM PERCENT LESS GREATER EQUAL LSHIFT RSHIFT RRSHIFT LESS_EQ GREATER_EQ ALWAYS_EQ ALWAYS_NEQ BIT_AND BIT_OR BIT_NOT AND OR MULTI_ASG MOD_ASG PLUS_ASG MINUS_ASG LSHIFT_ASG RSHIFT_ASG
 LLSHIFT_ASG BIT_AND_ASG BIT_NOT_ASG BIT_OR_ASG
%start Program

%type <debug> DECIMAL_LITERAL HEX_INTEGER_LITERAL STRING_LITERAL BOOLEAN_LITERAL NULL_LITERAL
%type <debug> SLASHASSIGN SLASH JEOF IDENTIFIER_NAME


// default type is ast node
%type <ast_Node> PrimaryExpression Literal Identifier ArrayLiteral
%type <ast_Node> ElementList ElementListPart Elision ObjectLiteral
%type <ast_Node> PropertyNameAndValueList PropertyNameAndValueListPart
%type <ast_Node> PropertyNameAndValue PropertyName 
%type <ast_Node> MemberExpression MemberExpressionForIn
%type <ast_Node> AllocationExpression AllocationExpressionBody
%type <ast_Node> MemberExpressionParts MemberExpressionPart
%type <ast_Node> CallExpression CallExpressionForIn CallExpressionParts CallExpressionPart
%type <ast_Node> Arguments ArgumentList
%type <ast_Node> ElAssignmentExpressions 
%type <ast_Node> LeftHandSideExpression LeftHandSideExpressionForIn
%type <ast_Node> PostfixExpression PostfixOperator
%type <ast_Node> UnaryExpression UnaryExpressionPart UnaryOperator
%type <ast_Node> MultiplicativeExpression MultiplicativeExpressionPart MultiplicativeOperator
%type <ast_Node> AdditiveExpression AdditiveExpressionPart AdditiveOperator
%type <ast_Node> ShiftExpression ShiftExpressionPart ShiftOperator
%type <ast_Node> RelationalExpression RelationalExpressionPart RelationalOperator
%type <ast_Node> RelationalExpressionNoIn RelationalExpressionNoInPart RelationalNoInOperator
%type <ast_Node> EqualityExpression EqualityExpressionPart EqualityExpressionNoIn EqualityExpressionNoInPart EqualityOperator
%type <ast_Node> BitwiseANDExpression BitwiseANDExpressionPart BitwiseANDExpressionNoIn BitwiseANDExpressionNoInPart BitwiseANDOperator BitwiseXORExpression
%type <ast_Node> BitwiseXORExpressionPart BitwiseXORExpressionNoIn BitwiseXORExpressionNoInPart BitwiseXOROperator BitwiseORExpression BitwiseORExpressionPart
%type <ast_Node> BitwiseORExpressionNoIn BitwiseORExpressionNoInPart BitwiseOROperator
%type <ast_Node> LogicalANDExpression LogicalANDExpressionPart LogicalANDExpressionNoIn LogicalANDExpressionNoInPart LogicalANDOperator
%type <ast_Node> LogicalORExpression LogicalORExpressionPart LogicalORExpressionNoIn LogicalORExpressionNoInPart LogicalOROperator
%type <ast_Node> ConditionalExpression ConditionalExpressionNoIn AssignmentExpression AssignmentExpressionNoIn AssignmentOperator
%type <ast_Node> Expression ExpressionPart ExpressionNoIn ExpressionNoInPart
%type <ast_Node> ExpressionOrNull Statement 
%type <ast_Node> Block StatementList 
%type <ast_Node> VariableStatement VariableDeclarationList  VariableDeclarationListNoIn
%type <ast_Node> VariableDeclaration VariableDeclarationNoIn
%type <ast_Node> Initialiser InitialiserNoIn
%type <ast_Node> EmptyStatement ExpressionStatement
%type <ast_Node> IfStatement IterationStatement
%type <ast_Node> IdentifierComma 
%type <ast_Node> ContinueStatement BreakStatement ReturnStatement
%type <ast_Node> WithStatement SwitchStatement
%type <ast_Node> CaseBlock CaseBlockPart CaseClauses CaseClause DefaultClause
%type <ast_Node> LabelledStatement ThrowStatement
%type <ast_Node> TryStatement TryStatementPart Catch Finally
%type <ast_Node> FormalParameterListInPare
%type <ast_Node> FunctionDeclaration FunctionExpression
%type <ast_Node> FormalParameterList FunctionBody
%type <ast_Node> Program 
%type <ast_Node> SourceElements SourceElement
%type <ast_Node> ImportStatement Name
%type <ast_Node> JScriptVarStatement JScriptVarDeclarationList JScriptVarDeclaration


%%
//张宇昊
PrimaryExpression	:	THIS
|	ObjectLiteral
|	LEFT_PARE Expression RIGHT_PARE
|	Identifier
|	ArrayLiteral
|	Literal
Literal	:	DECIMAL_LITERAL | HEX_INTEGER_LITERAL | STRING_LITERAL | BOOLEAN_LITERAL | NULL_LITERAL
Identifier	:	IDENTIFIER_NAME
ArrayLiteral    :  LEFT_BRACKET Elision RIGHT_BRACKET
|   LEFT_BRACKET ElementList Elision RIGHT_BRACKET
|   LEFT_BRACKET ElementList RIGHT_BRACKET
|   LEFT_BRACKET RIGHT_BRACKET
// example
// old one->ElementList	:	( Elision )? AssignmentExpression ( Elision AssignmentExpression )*
//new one
ElementList	:	Elision AssignmentExpression ElementListPart
|   AssignmentExpression ElementListPart
ElementListPart :   ElementListPart Elision AssignmentExpression
|
Elision	:   COMMA
|   Elision COMMA
ObjectLiteral	:	LEFT_BRACE PropertyNameAndValueList RIGHT_BRACE
|   LEFT_BRACE  RIGHT_BRACE
//here is an example
//old one-->PropertyNameAndValueList	:	PropertyNameAndValue ( COMMA PropertyNameAndValue | COMMA )*
//new one
PropertyNameAndValueList	:	PropertyNameAndValue PropertyNameAndValueListPart
PropertyNameAndValueListPart    :   PropertyNameAndValueListPart COMMA
|   PropertyNameAndValueListPart COMMA PropertyNameAndValue
|

PropertyNameAndValue	:	PropertyName COLON AssignmentExpression
PropertyName	:	Identifier
|	STRING_LITERAL
|	DECIMAL_LITERAL
MemberExpression	:  MemberExpressionForIn
|	AllocationExpression
MemberExpressionForIn	:	FunctionExpression MemberExpressionParts
|   PrimaryExpression MemberExpressionParts

//example 2
//old one -->AllocationExpression	:	( NEW MemberExpression ( ( Arguments ( MemberExpressionPart )* )* ) )
//new one
AllocationExpression    :   NEW MemberExpression AllocationExpressionBody
AllocationExpressionBody    :   AllocationExpressionBody Arguments MemberExpressionParts
|
MemberExpressionParts   :   MemberExpressionParts MemberExpressionPart
|
MemberExpressionPart    :   LEFT_BRACKET Expression RIGHT_BRACKET
|	DOT Identifier
CallExpression	:	MemberExpression Arguments CallExpressionParts
CallExpressionForIn	:	MemberExpressionForIn Arguments CallExpressionParts
CallExpressionParts :   CallExpressionParts CallExpressionPart
|
CallExpressionPart	:	Arguments
|   LEFT_BRACKET Expression RIGHT_BRACKET
|	DOT Identifier
Arguments	:	LEFT_PARE ArgumentList RIGHT_PARE
|   LEFT_PARE RIGHT_PARE
ArgumentList	:	AssignmentExpression ElAssignmentExpressions
ElAssignmentExpressions :  ElAssignmentExpressions COMMA AssignmentExpression
|
LeftHandSideExpression	:	CallExpression
|	MemberExpression
LeftHandSideExpressionForIn	:	CallExpressionForIn
|	MemberExpressionForIn

//李逸婷
PostfixExpression	:	LeftHandSideExpression
| LeftHandSideExpression PostfixOperator
PostfixOperator	:	 PLUS_PLUS
| MINUS_MINUS
UnaryExpression	:	PostfixExpression
| UnaryExpressionPart
UnaryExpressionPart : UnaryOperator UnaryExpression
| UnaryExpressionPart UnaryOperator UnaryExpression
UnaryOperator	:	DELETE
| VOID
| TYPEOF
| PLUS_PLUS
| MINUS_MINUS
| PLUS
| MINUS
| TILDE
| EXCLA
MultiplicativeExpression	:    UnaryExpression MultiplicativeExpressionPart
MultiplicativeExpressionPart  : MultiplicativeExpressionPart MultiplicativeOperator UnaryExpression
|
MultiplicativeOperator	:	MULTI
| SLASH
| PERCENT
AdditiveExpression	:	MultiplicativeExpression AdditiveExpressionPart
AdditiveExpressionPart  :   AdditiveExpressionPart AdditiveOperator MultiplicativeExpression
|
AdditiveOperator	:	PLUS
| MINUS
ShiftExpression	:	AdditiveExpression ShiftExpressionPart
ShiftExpressionPart :   ShiftExpressionPart ShiftOperator AdditiveExpression
|
ShiftOperator	:	LSHIFT
| RSHIFT
| RRSHIFT
RelationalExpression	:	ShiftExpression RelationalExpressionPart
RelationalExpressionPart  :   RelationalExpressionPart RelationalOperator ShiftExpression
|
RelationalOperator	:	LESS
| GREATER
| LESS_EQ
| GREATER_EQ
| INSTANCEOF
| IN
RelationalExpressionNoIn	:	ShiftExpression RelationalExpressionNoInPart
RelationalExpressionNoInPart  :   RelationalExpressionNoInPart RelationalNoInOperator ShiftExpression
|
RelationalNoInOperator	:	LESS
| GREATER
| LESS_EQ
| GREATER_EQ
| INSTANCEOF
EqualityExpression	:	RelationalExpression EqualityExpressionPart
EqualityExpressionPart  :   EqualityExpressionPart EqualityOperator RelationalExpression
|
EqualityExpressionNoIn	:	RelationalExpressionNoIn EqualityExpressionNoInPart
EqualityExpressionNoInPart  :   EqualityExpressionNoInPart EqualityOperator RelationalExpressionNoIn
|
EqualityOperator	:	EQUAL
| NOT_EQUAL
| ALWAYS_EQ
| ALWAYS_NEQ
BitwiseANDExpression	:	EqualityExpression BitwiseANDExpressionPart
BitwiseANDExpressionPart  :   BitwiseANDExpressionPart BitwiseANDOperator EqualityExpression
|
BitwiseANDExpressionNoIn	:	EqualityExpressionNoIn BitwiseANDExpressionNoInPart
BitwiseANDExpressionNoInPart  :   BitwiseANDExpressionNoInPart BitwiseANDOperator EqualityExpressionNoIn
|
BitwiseANDOperator	:	BIT_AND
BitwiseXORExpression	:	BitwiseANDExpression BitwiseXORExpressionPart
BitwiseXORExpressionPart   :   BitwiseXORExpressionPart BitwiseXOROperator BitwiseANDExpression
|
BitwiseXORExpressionNoIn	:	BitwiseANDExpressionNoIn BitwiseXORExpressionNoInPart
BitwiseXORExpressionNoInPart   :   BitwiseXORExpressionNoInPart BitwiseXOROperator BitwiseANDExpressionNoIn
|
BitwiseXOROperator	:	BIT_NOT
BitwiseORExpression	:	BitwiseXORExpression BitwiseORExpressionPart
BitwiseORExpressionPart   :   BitwiseORExpressionPart BitwiseOROperator BitwiseXORExpression
|
BitwiseORExpressionNoIn	:	BitwiseXORExpressionNoIn BitwiseORExpressionNoInPart
BitwiseORExpressionNoInPart   :   BitwiseORExpressionNoInPart BitwiseOROperator BitwiseXORExpressionNoIn
|
BitwiseOROperator	:	BIT_OR
LogicalANDExpression	:	BitwiseORExpression LogicalANDExpressionPart
LogicalANDExpressionPart   :   LogicalANDExpressionPart LogicalANDOperator BitwiseORExpression
|
LogicalANDExpressionNoIn	:	BitwiseORExpressionNoIn LogicalANDExpressionNoInPart
LogicalANDExpressionNoInPart   :   LogicalANDExpressionNoInPart LogicalANDOperator BitwiseORExpressionNoIn
|
LogicalANDOperator	:	AND
LogicalORExpression	:	LogicalANDExpression LogicalORExpressionPart
LogicalORExpressionPart   :   LogicalORExpressionPart LogicalOROperator LogicalANDExpression
|
LogicalORExpressionNoIn	:	LogicalANDExpressionNoIn LogicalORExpressionNoInPart
LogicalORExpressionNoInPart   :   LogicalORExpressionNoInPart LogicalOROperator LogicalANDExpressionNoIn
|
LogicalOROperator	:	OR
ConditionalExpression	:	LogicalORExpression
|LogicalORExpression QUES AssignmentExpression COLON AssignmentExpression
ConditionalExpressionNoIn	:	LogicalORExpressionNoIn
|LogicalORExpressionNoIn QUES AssignmentExpression COLON AssignmentExpressionNoIn
AssignmentExpression	:	LeftHandSideExpression AssignmentOperator AssignmentExpression
| ConditionalExpression
AssignmentExpressionNoIn	:	LeftHandSideExpression AssignmentOperator AssignmentExpressionNoIn
| ConditionalExpressionNoIn
AssignmentOperator	:	ASSIGN { printf("haha!=\n");}
| MULTI_ASG
| SLASHASSIGN
| MOD_ASG
| PLUS_ASG
| MINUS_ASG
| LSHIFT_ASG
| RSHIFT_ASG
| LLSHIFT_ASG
| BIT_AND_ASG
| BIT_NOT_ASG
| BIT_OR_ASG
Expression	:	AssignmentExpression ExpressionPart
ExpressionPart   :   ExpressionPart COMMA AssignmentExpression
|
ExpressionNoIn	:	AssignmentExpressionNoIn ExpressionNoInPart
ExpressionNoInPart   :   ExpressionNoInPart COMMA AssignmentExpressionNoIn
|

//陈睿
ExpressionOrNull: 
| Expression
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
Block	:	LEFT_BRACE RIGHT_BRACE
|   LEFT_BRACE StatementList RIGHT_BRACE
StatementList	:	Statement
|   Statement StatementList
VariableStatement	:	VAR VariableDeclarationList
|   VAR VariableDeclarationList SEMICOLON
VariableDeclarationList	:	VariableDeclaration
| VariableDeclarationList  COMMA VariableDeclaration
VariableDeclarationListNoIn	:	VariableDeclarationNoIn
| VariableDeclarationListNoIn COMMA VariableDeclarationNoIn
VariableDeclaration	:	Identifier
| Identifier Initialiser
VariableDeclarationNoIn	:	Identifier
| Identifier  InitialiserNoIn
Initialiser	:	ASSIGN AssignmentExpression
InitialiserNoIn	:	ASSIGN AssignmentExpressionNoIn
EmptyStatement	:	SEMICOLON
ExpressionStatement	:	Expression
| Expression SEMICOLON
IfStatement	:	IF LEFT_PARE Expression RIGHT_PARE Statement
| IF LEFT_PARE Expression RIGHT_PARE Statement ELSE Statement
IterationStatement	:	DO Statement WHILE LEFT_PARE Expression RIGHT_PARE
|   DO Statement WHILE LEFT_PARE Expression RIGHT_PARE SEMICOLON
|	WHILE LEFT_PARE Expression RIGHT_PARE Statement
|	FOR LEFT_PARE SEMICOLON ExpressionOrNull SEMICOLON ExpressionOrNull RIGHT_PARE Statement
|	FOR LEFT_PARE ExpressionNoIn SEMICOLON ExpressionOrNull SEMICOLON ExpressionOrNull RIGHT_PARE Statement
|	FOR LEFT_PARE VAR VariableDeclarationList SEMICOLON ExpressionOrNull SEMICOLON ExpressionOrNull RIGHT_PARE Statement
|	FOR LEFT_PARE VAR VariableDeclarationNoIn IN Expression RIGHT_PARE Statement
|	FOR LEFT_PARE LeftHandSideExpressionForIn IN Expression RIGHT_PARE Statement
IdentifierComma  :
| Identifier
| SEMICOLON
| Identifier SEMICOLON
ContinueStatement	:	CONTINUE IdentifierComma
BreakStatement	:	BREAK IdentifierComma
ReturnStatement	:	RETURN ExpressionOrNull
| RETURN ExpressionOrNull SEMICOLON
WithStatement	:	WITH LEFT_PARE Expression RIGHT_PARE Statement
SwitchStatement	:	SWITCH LEFT_PARE Expression RIGHT_PARE CaseBlock
CaseBlock	    :	LEFT_BRACE CaseBlockPart
| LEFT_BRACE CaseClauses CaseBlockPart
CaseBlockPart   :   RIGHT_BRACE
| DefaultClause RIGHT_BRACE
| DefaultClause CaseClauses RIGHT_BRACE
CaseClauses	    :	CaseClause
| CaseClauses CaseClause
CaseClause	    :	CASE Expression COLON
| CASE Expression COLON StatementList
DefaultClause	:	DEFAULT COLON
| DEFAULT COLON StatementList
LabelledStatement	:	Identifier COLON Statement
ThrowStatement	:	THROW Expression
| THROW Expression SEMICOLON
TryStatement	:	TRY Block TryStatementPart
TryStatementPart:   Finally
| Catch
| Catch Finally
Catch	:	CATCH LEFT_PARE Identifier RIGHT_PARE Block
Finally	:	FINALLY Block
FormalParameterListInPare: LEFT_PARE RIGHT_PARE
| LEFT_PARE FormalParameterList RIGHT_PARE
FunctionDeclaration	:	FUNCTION Identifier FormalParameterListInPare FunctionBody
FunctionExpression	:	FUNCTION FormalParameterListInPare FunctionBody
| FUNCTION Identifier FormalParameterListInPare FunctionBody
FormalParameterList	:	Identifier
| FormalParameterList COMMA Identifier
FunctionBody	:	LEFT_BRACE RIGHT_BRACE
| LEFT_BRACE SourceElements RIGHT_BRACE
Program	:	JEOF 
| SourceElements JEOF 
| SourceElements 
SourceElements	:	SourceElement
| SourceElements SourceElement
SourceElement	:	FunctionDeclaration
|	Statement
ImportStatement	:	IMPORT Name SEMICOLON
| IMPORT Name DOT MULTI  SEMICOLON
Name	:	IDENTIFIER_NAME
| Name DOT IDENTIFIER_NAME
JScriptVarStatement	:	VAR JScriptVarDeclarationList
| VAR JScriptVarDeclarationList SEMICOLON
JScriptVarDeclarationList	:	JScriptVarDeclaration
| JScriptVarDeclarationList COMMA JScriptVarDeclaration
JScriptVarDeclaration	:	Identifier COLON IDENTIFIER_NAME
| Identifier COLON IDENTIFIER_NAME Initialiser
