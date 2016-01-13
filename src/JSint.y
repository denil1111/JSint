%{
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
#include "helper.h"

using namespace std;
extern VarStack nowStack;
extern vector<ast::Expression*> concat(vector<ast::Expression*>, vector<ast::Expression*>);
extern vector<ast::Expression*> concat(ast::Expression*, vector<ast::Expression*>);
int yydebug = 1;
ast::Node* ast_root;
ast::Operator* noOp1Exp;
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
	ast::Operator::OpType ast_OpType;
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
    ast::IfStmt*          	ast_IfStmt;
    ast::ForStmt*          	ast_ForStmt;
    ast::WhileStmt*         ast_WhileStmt;
    ast::CaseList*          ast_CaseList;
    ast::CaseStmt*          ast_CaseStmt;
    ast::SwitchStmt*        ast_SwitchStmt;
	ast::ContinueStmt*      ast_ContinueStmt;
	ast::BreakStmt*         ast_BreakStmt;
	ast::Block*         	ast_Block;
	ast::LabeledStmt*       ast_LabeledStmt;
	ast::TryStmt*         	ast_TryStmt;
	ast::ThrowStmt*        	ast_ThrowStmt;
	ast::CatchStmt*        	ast_CatchStmt;
	ast::FinallyStmt*       ast_FinallyStmt;
	ast::ParameterList*     ast_ParameterList;
	ast::FunctionDeclaration* ast_FunctionDeclaration;
	ast::ArgumentList*      ast_ArgumentList;
	ast::CallExpression*    ast_CallExpression;
	ast::ElementList*       ast_ElementList;
	ast::PropertyName*       ast_PropertyName;
	ast::PropertyNameAndValue* ast_PropertyNameAndValue;
	ast::PropertyNameAndValueList* ast_PropertyNameAndValueList;
	ast::ObjectType*         ast_ObjectType;
	ast::MemberPropertyExpression*   ast_MemberPropertyExpression;
	ast::MemberName*        ast_MemberName;
	ast::MemberNameList*    ast_MemberNameList;
}

%token DECIMAL_LITERAL HEX_INTEGER_LITERAL STRING_LITERAL BOOLEAN_LITERAL NULL_LITERAL
%token SLASHASSIGN SLASH JEOF IDENTIFIER_NAME
%token THIS NEW DELETE VOID TYPEOF INSTANCEOF IN VAR IF ELSE DO WHILE FOR CONTINUE BREAK RETURN WITH SWITCH CASE DEFAULT THROW TRY CATCH FINALLY FUNCTION IMPORT
%token LEFT_BRACKET RIGHT_BRACKET LEFT_PARE RIGHT_PARE LEFT_BRACE RIGHT_BRACE COMMA DOT COLON SEMICOLON
%token PLUS MINUS MULTI ASSIGN PLUS_PLUS MINUS_MINUS TILDE QUES EXCLAM PERCENT LESS GREATER EQUAL LSHIFT RSHIFT RRSHIFT LESS_EQ GREATER_EQ NOT_EQUAL ALWAYS_EQ ALWAYS_NEQ BIT_AND BIT_OR BIT_XOR AND OR MULTI_ASG MOD_ASG PLUS_ASG MINUS_ASG LRSHIFT_ASG LSHIFT_ASG RSHIFT_ASG
%token BIT_AND_ASG BIT_XOR_ASG BIT_OR_ASG NL
%start Program

%type <debug> DECIMAL_LITERAL HEX_INTEGER_LITERAL STRING_LITERAL BOOLEAN_LITERAL NULL_LITERAL
%type <debug> SLASHASSIGN SLASH JEOF IDENTIFIER_NAME NL


// default type is ast node
%type <ast_Identifier> Identifier
%type <ast_Expression> PrimaryExpression Literal ArrayLiteral
%type <ast_ElementList> ElementList ElementListPart
%type <ast_Node> Elision
%type <ast_ObjectType> ObjectLiteral
%type <ast_PropertyName> PropertyName
%type <ast_PropertyNameAndValue> PropertyNameAndValue
%type <ast_PropertyNameAndValueList> PropertyNameAndValueList
%type <ast_Expression> MemberExpression MemberExpressionForIn
%type <ast_MemberPropertyExpression> MemberPropertyExpression
%type <ast_Expression> AllocationExpression AllocationExpressionBody
%type <ast_MemberNameList> MemberExpressionParts
%type <ast_MemberName> MemberExpressionPart
%type <ast_Expression> CallExpressionForIn CallExpressionParts CallExpressionPart
%type <ast_CallExpression> CallExpression
%type <ast_ArgumentList> Arguments ArgumentList
%type <ast_Expression> LeftHandSideExpression LeftHandSideExpressionForIn
%type <ast_Expression> PostfixExpression
%type <ast_Expression> UnaryExpression
%type <ast_Expression> MultiplicativeExpression MultiplicativeExpressionPart
%type <ast_Expression> AdditiveExpression AdditiveExpressionPart
%type <ast_Expression> ShiftExpression ShiftExpressionPart
%type <ast_Expression> RelationalExpression RelationalExpressionPart
%type <ast_Expression> RelationalExpressionNoIn RelationalExpressionNoInPart
%type <ast_Expression> EqualityExpression EqualityExpressionPart EqualityExpressionNoIn EqualityExpressionNoInPart
%type <ast_Expression> BitwiseANDExpression BitwiseANDExpressionPart BitwiseANDExpressionNoIn BitwiseANDExpressionNoInPart
%type <ast_Expression> BitwiseXORExpressionPart BitwiseXORExpressionNoIn BitwiseXORExpressionNoInPart  BitwiseORExpression
%type <ast_Expression> BitwiseORExpressionNoIn BitwiseORExpressionNoInPart BitwiseORExpressionPart BitwiseXORExpression
%type <ast_Expression> LogicalANDExpression LogicalANDExpressionPart LogicalANDExpressionNoIn LogicalANDExpressionNoInPart
%type <ast_Expression> LogicalORExpression LogicalORExpressionPart LogicalORExpressionNoIn LogicalORExpressionNoInPart
%type <ast_Expression> ConditionalExpression ConditionalExpressionNoIn AssignmentExpression AssignmentExpressionNoIn
%type <ast_OpType> PostfixOperator UnaryOperator AssignmentOperator LogicalOROperator LogicalANDOperator BitwiseOROperator  EqualityOperator BitwiseXOROperator BitwiseANDOperator
%type <ast_OpType> RelationalNoInOperator RelationalOperator ShiftOperator AdditiveOperator MultiplicativeOperator
%type <ast_Expression> Expression ExpressionPart ExpressionNoIn ExpressionNoInPart
%type <ast_Expression> ExpressionOrNull
%type <ast_Statement> Statement
%type <ast_Block> Block
%type <ast_StatementList> StatementList
%type <ast_Node> VariableStatement VariableDeclarationList  VariableDeclarationListNoIn
%type <ast_Node> VariableDeclaration VariableDeclarationNoIn
%type <ast_Node> Initialiser InitialiserNoIn
%type <ast_Statement> EmptyStatement ExpressionStatement
%type <ast_IfStmt> IfStatement 
%type <ast_Statement> IterationStatement
%type <ast_Identifier> IdentifierComma
%type <ast_ContinueStmt> ContinueStatement
%type <ast_BreakStmt> BreakStatement
%type <ast_Node> ReturnStatement
%type <ast_Node> WithStatement 
%type <ast_SwitchStmt> SwitchStatement
%type <ast_CaseList> CaseBlock CaseBlockPart CaseClauses 
%type <ast_CaseStmt> CaseClause DefaultClause
%type <ast_LabeledStmt> LabelledStatement 
%type <ast_ThrowStmt> ThrowStatement
%type <ast_TryStmt> TryStatement TryStatementPart
%type <ast_CatchStmt> Catch
%type <ast_FinallyStmt> Finally
%type <ast_ParameterList> FormalParameterListInPare FormalParameterList
%type <ast_FunctionDeclaration> FunctionDeclaration FunctionExpression
%type <ast_StatementList> FunctionBody
%type <ast_StatementList> Program
%type <ast_StatementList> SourceElements InFuncSourceElements SourceElementsNL
%type <ast_Statement> SourceElement InFuncSourceElement
%type <ast_Node> ImportStatement Name
%type <ast_Node> JScriptVarStatement JScriptVarDeclarationList JScriptVarDeclaration


%%
//张宇昊
PrimaryExpression	:	THIS
|	ObjectLiteral
{
	$$ = $1;
}
|	LEFT_PARE Expression RIGHT_PARE
{
	$$ = $2;
}
|	Identifier {
/*	//printf("identifier\n");*/
	$$ = $1;
}
|	ArrayLiteral
{
	$$ = $1;
}
|	Literal {
/*	//printf("Literal\n");*/
	$$ = $1;
}
Literal	:	DECIMAL_LITERAL {
	$$ = new ast::RealType(atof($1));
	//printf("number\n");
}
| HEX_INTEGER_LITERAL
| STRING_LITERAL {
	char a[200];
	strcpy(a,$1+1);
	a[strlen(a)-1] = 0;
/*	std::cout<<a<<std::endl;*/
	$$ = new ast::StringType(a);
}
| BOOLEAN_LITERAL {
	$$ = new ast::BooleanType($1);

}| NULL_LITERAL
Identifier	:	IDENTIFIER_NAME {
	$$ = new ast::Identifier($1);
}
ArrayLiteral    :  LEFT_BRACKET Elision RIGHT_BRACKET
|   LEFT_BRACKET ElementList Elision RIGHT_BRACKET
|   LEFT_BRACKET ElementList RIGHT_BRACKET
{
	$$ = new ast::ArrayType($2);
}
|   LEFT_BRACKET RIGHT_BRACKET
{
	$$ = new ast::ArrayType();
}
ElementList	:	Elision AssignmentExpression ElementListPart
|   AssignmentExpression ElementListPart
{
	$$ = new ast::ElementList($1, $2);
}
ElementListPart :   Elision AssignmentExpression ElementListPart
{
	$$ = new ast::ElementList($2, $3);
}
|
{
	$$ = new ast::ElementList();
}
Elision	:   COMMA
|   Elision COMMA
ObjectLiteral	:	LEFT_BRACE PropertyNameAndValueList RIGHT_BRACE
{
	$$ = new ast::ObjectType($2);
}
|   LEFT_BRACE  RIGHT_BRACE
{
	$$ = new ast::ObjectType();
}
PropertyNameAndValueList	:	PropertyNameAndValue COMMA PropertyNameAndValueList
{
	$$ = new ast::PropertyNameAndValueList($1, $3);
}
| PropertyNameAndValue
{
	$$ = new ast::PropertyNameAndValueList($1);
}
/*PropertyNameAndValueListPart    :   PropertyNameAndValueListPart COMMA
|   PropertyNameAndValueListPart COMMA PropertyNameAndValue
{
	$$ = new ast::PropertyNameAndValueList()
}
|*/

PropertyNameAndValue	:	PropertyName COLON AssignmentExpression
{
	$$ = new ast::PropertyNameAndValue($1, $3);
}
PropertyName	:	Identifier
{
	$$ = &($1->name);
}
|	STRING_LITERAL
{
	$$ = new std::string($1);
}
|	DECIMAL_LITERAL
{
	$$ = new std::string($1);
}

MemberExpression	:  MemberPropertyExpression
{
	$$ =$1;
}
|	AllocationExpression
|   FunctionExpression
|   PrimaryExpression
{
	$$ = $1;
}

MemberPropertyExpression    :   FunctionExpression MemberExpressionParts
|   PrimaryExpression MemberExpressionParts
{
	$$ = new ast::MemberPropertyExpression($1, $2);
}

MemberExpressionForIn	:	FunctionExpression MemberExpressionParts
|   PrimaryExpression MemberExpressionParts {
/*	//printf("MemberExpForIn\n");*/
}

AllocationExpression    :   NEW MemberExpression AllocationExpressionBody
AllocationExpressionBody    :   AllocationExpressionBody Arguments MemberExpressionParts
|
MemberExpressionParts   :   MemberExpressionParts MemberExpressionPart
{
	$1->push_back($2);
	$$ = $1;
}
| MemberExpressionPart
{
	$$ = new ast::MemberNameList{$1};
}

MemberExpressionPart    :   LEFT_BRACKET Expression RIGHT_BRACKET
{
	$$ = new ast::MemberName($2, false);
}
|	DOT Identifier
{
	$$ = new ast::MemberName($2, true);
}

CallExpression	:	MemberExpression Arguments CallExpressionParts {
	$$ = new ast::CallExpression($1, $2);
}

CallExpressionForIn	:	MemberExpressionForIn Arguments CallExpressionParts

CallExpressionParts :   CallExpressionParts CallExpressionPart
| {
	$$ = nullptr;
}
CallExpressionPart	:	Arguments
|   LEFT_BRACKET Expression RIGHT_BRACKET
|	DOT Identifier

Arguments	:	LEFT_PARE ArgumentList RIGHT_PARE {
	$$ = $2;
}
|   LEFT_PARE RIGHT_PARE {
	$$ = nullptr;
}

ArgumentList	:	AssignmentExpression {
	if ($1) {
		$$ = new ast::ArgumentList();
		$$->push_back($1);
	} else {
		$$ = nullptr;
	}
}
| ArgumentList COMMA AssignmentExpression {
	$1->push_back($3);
	$$ = $1;
}

LeftHandSideExpression	:	CallExpression {
	$$ = $1;
}
|	MemberExpression {
	$$ = $1;
/*	//printf("LeftHandExp\n");*/
}
LeftHandSideExpressionForIn	:	CallExpressionForIn
|	MemberExpressionForIn {

}

//李逸婷
PostfixExpression	:	LeftHandSideExpression {
	$$ = $1;
/*	//printf("postfixExp\n");*/
}
| LeftHandSideExpression PostfixOperator {
	$$ = new ast::Operator($1,$2,nullptr);
}
PostfixOperator	:	 PLUS_PLUS {$$ = ast::Operator::OpType::rpplus;}
| MINUS_MINUS	{$$ = ast::Operator::OpType::rmminus;}
UnaryExpression	:	PostfixExpression {
	$$ = $1;
}
|UnaryOperator UnaryExpression {
	$$ = new ast::Operator($2,$1,nullptr);
}
/*UnaryExpressionPart {

}
UnaryExpressionPart : UnaryOperator UnaryExpression
{

}
| UnaryExpressionPart UnaryOperator UnaryExpression*/
UnaryOperator	:	DELETE {$$ = ast::Operator::OpType::del;}
| VOID		{$$ = ast::Operator::OpType::voido;}
| TYPEOF	{$$ = ast::Operator::OpType::type;}
| PLUS_PLUS {$$ = ast::Operator::OpType::pplus;}
| MINUS_MINUS {$$ = ast::Operator::OpType::mminus;}
| PLUS   {$$ = ast::Operator::OpType::positive;}
| MINUS  {$$ = ast::Operator::OpType::negtive;}
| TILDE	 {$$ = ast::Operator::OpType::bit_not;}
| EXCLAM {$$ = ast::Operator::OpType::lnot;}
MultiplicativeExpression	:    UnaryExpression MultiplicativeExpressionPart {
	auto exp = dynamic_cast<ast::Operator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}

MultiplicativeExpressionPart  : MultiplicativeExpressionPart MultiplicativeOperator UnaryExpression {
	$$ = new ast::Operator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::Operator*>($$);
	}
}
| {
	$$ = nullptr;
}
MultiplicativeOperator	:	MULTI {
	$$ = ast::Operator::OpType::mul;
}
| SLASH {
	$$ = ast::Operator::OpType::div;
}
| PERCENT {
	$$ = ast::Operator::OpType::mod;
}
AdditiveExpression	:	MultiplicativeExpression AdditiveExpressionPart {
	auto exp = dynamic_cast<ast::Operator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}

AdditiveExpressionPart  :   AdditiveExpressionPart AdditiveOperator MultiplicativeExpression {
	$$ = new ast::Operator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::Operator*>($$);
	}
}
| {
	$$ = nullptr;
}
AdditiveOperator	:	PLUS {
	$$ = ast::Operator::OpType::plus;
}
| MINUS {
	$$ = ast::Operator::OpType::minus;
}
ShiftExpression	:	AdditiveExpression ShiftExpressionPart {
	auto exp = dynamic_cast<ast::Operator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}
ShiftExpressionPart :   ShiftExpressionPart ShiftOperator AdditiveExpression {
	$$ = new ast::Operator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::Operator*>($$);
	}
}
| {
	$$ = nullptr;
}
ShiftOperator	:	LSHIFT {
	$$ = ast::Operator::OpType::lsh;
}
| RSHIFT {
	$$ = ast::Operator::OpType::rsh;
}
| RRSHIFT  {
	$$ = ast::Operator::OpType::lrsh;
}
RelationalExpression	:	ShiftExpression RelationalExpressionPart {
	auto exp = dynamic_cast<ast::Operator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}
RelationalExpressionPart  :   RelationalExpressionPart RelationalOperator ShiftExpression {
	$$ = new ast::Operator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::Operator*>($$);
	}
}
| {
	$$ = nullptr;
}
RelationalOperator	:	LESS {
	$$ = ast::Operator::OpType::lt;
}
| GREATER {
	$$ = ast::Operator::OpType::gt;
}
| LESS_EQ {
	$$ = ast::Operator::OpType::le;
}
| GREATER_EQ {
	$$ = ast::Operator::OpType::ge;
}
| INSTANCEOF {
	$$ = ast::Operator::OpType::iof;
}
| IN {
	$$ = ast::Operator::OpType::iin;
}
RelationalExpressionNoIn	:	ShiftExpression RelationalExpressionNoInPart {
	auto exp = dynamic_cast<ast::Operator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}
RelationalExpressionNoInPart  :   RelationalExpressionNoInPart RelationalNoInOperator ShiftExpression {
	$$ = new ast::Operator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::Operator*>($$);
	}
}
| {
	$$ = nullptr;
}
RelationalNoInOperator	:	LESS {
	$$ = ast::Operator::OpType::lt;
}
| GREATER {
	$$ = ast::Operator::OpType::gt;
}
| LESS_EQ {
	$$ = ast::Operator::OpType::le;
}
| GREATER_EQ {
	$$ = ast::Operator::OpType::ge;
}
| INSTANCEOF {
	$$ = ast::Operator::OpType::iof;
}
EqualityExpression	:	RelationalExpression EqualityExpressionPart {
	auto exp = dynamic_cast<ast::Operator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}
EqualityExpressionPart  :   EqualityExpressionPart EqualityOperator RelationalExpression {
	$$ = new ast::Operator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::Operator*>($$);
	}
}
| {
	$$ = nullptr;
}
EqualityExpressionNoIn	:	RelationalExpressionNoIn EqualityExpressionNoInPart {
	auto exp = dynamic_cast<ast::Operator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}
EqualityExpressionNoInPart  :   EqualityExpressionNoInPart EqualityOperator RelationalExpressionNoIn{
	$$ = new ast::Operator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::Operator*>($$);
	}
}
| {
	$$ = nullptr;
}
EqualityOperator	:	EQUAL {
	$$ = ast::Operator::OpType::eq;
}
| NOT_EQUAL {
	$$ = ast::Operator::OpType::ne;
}
| ALWAYS_EQ {
	$$ = ast::Operator::OpType::aeq;
}
| ALWAYS_NEQ {
	$$ = ast::Operator::OpType::ane;
}
BitwiseANDExpression	:	EqualityExpression BitwiseANDExpressionPart {
	auto exp = dynamic_cast<ast::Operator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}
BitwiseANDExpressionPart  :   BitwiseANDExpressionPart BitwiseANDOperator EqualityExpression {
	$$ = new ast::Operator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::Operator*>($$);
	}
}
| {
	$$ = nullptr;
}
BitwiseANDExpressionNoIn	:	EqualityExpressionNoIn BitwiseANDExpressionNoInPart {
	auto exp = dynamic_cast<ast::Operator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}
BitwiseANDExpressionNoInPart  :   BitwiseANDExpressionNoInPart BitwiseANDOperator EqualityExpressionNoIn{
	$$ = new ast::Operator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::Operator*>($$);
	}
}
| {
	$$ = nullptr;
}
BitwiseANDOperator	:	BIT_AND {
	$$ = ast::Operator::OpType::bit_and;
}
BitwiseXORExpression	:	BitwiseANDExpression BitwiseXORExpressionPart {
	auto exp = dynamic_cast<ast::Operator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}
BitwiseXORExpressionPart   :   BitwiseXORExpressionPart BitwiseXOROperator BitwiseANDExpression {
	$$ = new ast::Operator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::Operator*>($$);
	}
}
| {
	$$ = nullptr;
}
BitwiseXORExpressionNoIn	:	BitwiseANDExpressionNoIn BitwiseXORExpressionNoInPart {
	auto exp = dynamic_cast<ast::Operator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}
BitwiseXORExpressionNoInPart   :   BitwiseXORExpressionNoInPart BitwiseXOROperator BitwiseANDExpressionNoIn{
	$$ = new ast::Operator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::Operator*>($$);
	}
}
| {
	$$ = nullptr;
}
BitwiseXOROperator	:	BIT_XOR {
	$$ = ast::Operator::OpType::bit_xor;
}
BitwiseORExpression	:	BitwiseXORExpression BitwiseORExpressionPart {
	auto exp = dynamic_cast<ast::Operator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}
BitwiseORExpressionPart   :   BitwiseORExpressionPart BitwiseOROperator BitwiseXORExpression {
	$$ = new ast::Operator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::Operator*>($$);
	}
}
| {
	$$ = nullptr;
}
BitwiseORExpressionNoIn	:	BitwiseXORExpressionNoIn BitwiseORExpressionNoInPart {
	auto exp = dynamic_cast<ast::Operator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}
BitwiseORExpressionNoInPart   :   BitwiseORExpressionNoInPart BitwiseOROperator BitwiseXORExpressionNoIn{
	$$ = new ast::Operator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::Operator*>($$);
	}
}
| {
	$$ = nullptr;
}
BitwiseOROperator	:	BIT_OR {
	$$ = ast::Operator::OpType::bit_or;
}
LogicalANDExpression	:	BitwiseORExpression LogicalANDExpressionPart {
	auto exp = dynamic_cast<ast::Operator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}
LogicalANDExpressionPart   :   LogicalANDExpressionPart LogicalANDOperator BitwiseORExpression {
	$$ = new ast::Operator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::Operator*>($$);
	}
}
| {
	$$ = nullptr;
}
LogicalANDExpressionNoIn	:	BitwiseORExpressionNoIn LogicalANDExpressionNoInPart {
	auto exp = dynamic_cast<ast::Operator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}
LogicalANDExpressionNoInPart   :   LogicalANDExpressionNoInPart LogicalANDOperator BitwiseORExpressionNoIn{
	$$ = new ast::Operator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::Operator*>($$);
	}
}
| {
	$$ = nullptr;
}
LogicalANDOperator	:	AND {
	$$ = ast::Operator::OpType::land;
}
LogicalORExpression	:	LogicalANDExpression LogicalORExpressionPart {
	auto exp = dynamic_cast<ast::Operator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}
LogicalORExpressionPart   :   LogicalORExpressionPart LogicalOROperator LogicalANDExpression {
	$$ = new ast::Operator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::Operator*>($$);
	}
}
| {
	$$ = nullptr;
}
LogicalORExpressionNoIn	:	LogicalANDExpressionNoIn LogicalORExpressionNoInPart {
	auto exp = dynamic_cast<ast::Operator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}
LogicalORExpressionNoInPart   :   LogicalORExpressionNoInPart LogicalOROperator LogicalANDExpressionNoIn{
	$$ = new ast::Operator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::Operator*>($$);
	}
}
| {
	$$ = nullptr;
}
LogicalOROperator	:	OR {
	$$ = ast::Operator::OpType::lor;
}
ConditionalExpression	:	LogicalORExpression{
	$$ = $1;
}
|LogicalORExpression QUES AssignmentExpression COLON AssignmentExpression {
}
ConditionalExpressionNoIn	:	LogicalORExpressionNoIn {
	$$ = $1;
}
|LogicalORExpressionNoIn QUES AssignmentExpression COLON AssignmentExpressionNoIn {
}
AssignmentExpression	:	LeftHandSideExpression AssignmentOperator AssignmentExpression
{
	$$ = new ast::Operator($1,$2,$3);
/*	//printf("an assign exp\n");*/
}
| ConditionalExpression{
	$$ = $1;
	//printf("an assign exp from condition\n");
}
AssignmentExpressionNoIn	:	LeftHandSideExpression AssignmentOperator AssignmentExpressionNoIn {
	$$ = new ast::Operator($1,$2,$3);
/*	//printf("an assign exp\n");*/
}
| ConditionalExpressionNoIn {
	$$ = $1;
	//printf("an assign exp from condition\n");
}
AssignmentOperator	:	ASSIGN {
	$$ =ast::Operator::OpType::assign;
	//printf("an assign\n");
}
| MULTI_ASG {
	$$ =ast::Operator::OpType::mul_assign;
}
| SLASHASSIGN {
	$$ =ast::Operator::OpType::div_assign;
}
| MOD_ASG {
	$$ =ast::Operator::OpType::mod_assign;
}
| PLUS_ASG {
	$$ =ast::Operator::OpType::plus_assign;
}
| MINUS_ASG {
	$$ =ast::Operator::OpType::minus_assign;
}
| LSHIFT_ASG {
	$$ =ast::Operator::OpType::lsh_assign;
}
| RSHIFT_ASG {
	$$ =ast::Operator::OpType::rsh_assign;
}
| LRSHIFT_ASG {
	$$ =ast::Operator::OpType::lrsh_assign;
}
| BIT_AND_ASG {
	$$ =ast::Operator::OpType::bit_and_assign;
}
| BIT_XOR_ASG {
	$$ =ast::Operator::OpType::bit_xor_assign;
}
| BIT_OR_ASG {
	$$ =ast::Operator::OpType::bit_or_assign;
}
Expression	:	AssignmentExpression ExpressionPart
{
	if ($2 == nullptr){
		$$ = $1;
	}
	else {
		$$ = new ast::Operator($1,ast::Operator::OpType::comma,$2);
	}


}
ExpressionPart   :    COMMA AssignmentExpression ExpressionPart {
	if ($3 == nullptr) {
		$$ = $2;
	} else {
		$$ = new ast::Operator($2,ast::Operator::OpType::comma,$3);
	}

}
| {
	$$ = nullptr;
}
ExpressionNoIn	:	AssignmentExpressionNoIn ExpressionNoInPart {
	if ($2 == nullptr){
		$$ = $1;
	}
	else {
		$$ = new ast::Operator($1,ast::Operator::OpType::comma,$2);
	}


}
ExpressionNoInPart   :   COMMA ExpressionNoInPart AssignmentExpressionNoIn {
	if ($3 == nullptr) {
		$$ = $2;
	} else {
		$$ = new ast::Operator($2,ast::Operator::OpType::comma,$3);
	}

}
| {
	$$ = nullptr;
}
//陈睿
ExpressionOrNull:
| Expression
Statement	:	Block
{
	$$ = $1;
}
|	JScriptVarStatement
|	VariableStatement
|	EmptyStatement
{
	$$ = new ast::Statement();
}
|	LabelledStatement{
	$$=$1;
}
|	ExpressionStatement
{
	$$ = $1;
}
|	IfStatement{
	$$=$1;
}
|	IterationStatement{
	$$=$1;
}
|	ContinueStatement{
	$$=$1;
}
|	BreakStatement{
	$$=$1;
}
|	ImportStatement
|	ReturnStatement
|	WithStatement
|	SwitchStatement{
	$$=$1;
}
|	ThrowStatement{
	$$=$1;
}
|	TryStatement{
	$$=$1;
}
Block	:	LEFT_BRACE RIGHT_BRACE{

}
|   LEFT_BRACE StatementList RIGHT_BRACE
{
	$$ = new ast::Block($2);
}
StatementList	:	Statement
{
	$$ = new ast::StatementList($1);
}
|   Statement StatementList
{
	$$ = new ast::StatementList($1, $2);
}
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
|
ExpressionStatement	:	Expression {
	$$ = $1;
}
| Expression SEMICOLON{
	$$ = $1;
}

IfStatement	:	IF LEFT_PARE Expression RIGHT_PARE Statement{
	$$=new ast::IfStmt($3,$5,nullptr);
}
| IF LEFT_PARE Expression RIGHT_PARE Statement ELSE Statement{
	$$=new ast::IfStmt($3,$5,$7);
}

IterationStatement	:	DO Statement WHILE LEFT_PARE Expression RIGHT_PARE{
	$$=new ast::WhileStmt($5,$2,true);
}
|   DO Statement WHILE LEFT_PARE Expression RIGHT_PARE SEMICOLON{
	$$=new ast::WhileStmt($5,$2,true);
}
|	WHILE LEFT_PARE Expression RIGHT_PARE Statement{
	$$=new ast::WhileStmt($3,$5,false);
}
|	FOR LEFT_PARE SEMICOLON ExpressionOrNull SEMICOLON ExpressionOrNull RIGHT_PARE Statement{
	$$=new ast::ForStmt(nullptr,$4,$6,$8);
	printf("after for stmt\n");
}
|	FOR LEFT_PARE ExpressionNoIn SEMICOLON ExpressionOrNull SEMICOLON ExpressionOrNull RIGHT_PARE Statement{
	$$=new ast::ForStmt($3,$5,$7,$9);
}
|	FOR LEFT_PARE VAR VariableDeclarationList SEMICOLON ExpressionOrNull SEMICOLON ExpressionOrNull RIGHT_PARE Statement{
	//$$=new ast::ForStmt($4,$6,$8,$10);
}
|	FOR LEFT_PARE VAR VariableDeclarationNoIn IN Expression RIGHT_PARE Statement
|	FOR LEFT_PARE LeftHandSideExpressionForIn IN Expression RIGHT_PARE Statement

IdentifierComma  :{
	$$=nullptr;
}
| Identifier{
	$$=$1;
}
| SEMICOLON{
	$$=nullptr;
}
| Identifier SEMICOLON{
	$$=$1;
}

ContinueStatement	:	CONTINUE IdentifierComma{
	$$=new ast::ContinueStmt($2);
}
BreakStatement	:	BREAK IdentifierComma{
	$$=new ast::BreakStmt($2);
}

ReturnStatement	:	RETURN ExpressionOrNull
| RETURN ExpressionOrNull SEMICOLON
WithStatement	:	WITH LEFT_PARE Expression RIGHT_PARE Statement

SwitchStatement	:	SWITCH LEFT_PARE Expression RIGHT_PARE CaseBlock{
	$$=new ast::SwitchStmt($3,$5);
}

CaseBlock	    :	LEFT_BRACE CaseBlockPart{
	$$=$2;
}
| LEFT_BRACE CaseClauses CaseBlockPart{
	
	$$=$2;
	for(int i=0;i<$3->size();i++){
		$$->push_back((*$3)[i]);
	}
}

CaseBlockPart   :   RIGHT_BRACE{
	$$=new ast::CaseList();
}
| DefaultClause RIGHT_BRACE{
	$$=new ast::CaseList();
	$$->push_back($1);
}
| DefaultClause CaseClauses RIGHT_BRACE{
	$$=new ast::CaseList();
	$$->push_back($1);
	for(int i=0;i<$2->size();i++){
		$$->push_back((*$2)[i]);
	}
}

CaseClauses	    :	CaseClause{
	$$=new ast::CaseList();
	$$->push_back($1);
}
| CaseClauses CaseClause{
	$$=$1;
	$$->push_back($2);
	//delete $1;
}

CaseClause	    :	CASE Expression COLON{
	$$=new ast::CaseStmt($2,nullptr,false);
}
| CASE Expression COLON StatementList{
	$$=new ast::CaseStmt($2,$4,false);
}

DefaultClause	:	DEFAULT COLON{
	$$=new ast::CaseStmt(nullptr,nullptr,true);
}
| DEFAULT COLON StatementList{
	$$=new ast::CaseStmt(nullptr,$3,true);
}

LabelledStatement	:	Identifier COLON Statement{
	$$=new ast::LabeledStmt($1,$3);
}

ThrowStatement	:	THROW Expression{
	$$=new ast::ThrowStmt($2);
}
| THROW Expression SEMICOLON{
	$$=new ast::ThrowStmt($2);
}

TryStatement	:	TRY Block TryStatementPart{
	$$=$3;
	$$->blockstmt=$2;
	delete $3;
}

TryStatementPart:   Finally{
	$$=new ast::TryStmt(nullptr,$1);
}
| Catch{
	$$=new ast::TryStmt($1,nullptr);
}
| Catch Finally{
	$$=new ast::TryStmt($1,$2);
}

Catch	:	CATCH LEFT_PARE Identifier RIGHT_PARE Block{
	$$ = new ast::CatchStmt($3,$5);
}

Finally	:	FINALLY Block{
	$$ = new ast::FinallyStmt($2);
}

FormalParameterListInPare: LEFT_PARE RIGHT_PARE {
	$$ = new ast::ParameterList();
}
| LEFT_PARE FormalParameterList RIGHT_PARE {
	$$ = $2;
}

FunctionDeclaration	:	FUNCTION Identifier FormalParameterListInPare FunctionBody {
	$$ = new ast::FunctionDeclaration((ast::Identifier*)$2, $3, $4);
}

FunctionExpression	:	FUNCTION FormalParameterListInPare FunctionBody
| FUNCTION Identifier FormalParameterListInPare FunctionBody

FormalParameterList	:	Identifier {
	$$ = new ast::ParameterList();
	$$->push_back($1);
}
| FormalParameterList COMMA Identifier {
	$1->push_back($3);
	$$ = $1;
}

FunctionBody	:	LEFT_BRACE RIGHT_BRACE {
	$$ = nullptr;
}
| LEFT_BRACE InFuncSourceElements RIGHT_BRACE {
	$$ = $2;
}

Program	:	JEOF
| SourceElementsNL JEOF
{
	$$ = $1;
	//cout << "program End"<<endl;
}
SourceElementsNL	:	SourceElements NL
{
	extern int parseError;
	$$ = $1;

	if (!parseError)
	{	
		extern int debugFlag;
		if (debugFlag)
			$1 -> print_node("", true, true);
		ast_root = $1;
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
		{
			extern int valueFlag;
			if (valueFlag)
				ast_root->value.print();
			parseError = 0;
		}
		else
		{
			parseError = 0;
		}

	}
}
| SourceElementsNL  SourceElements NL
{
	extern int parseError;
	$$ = $2;

	if (!parseError)
	{	
		extern int debugFlag;
		if (debugFlag)
			$2 -> print_node("", true, true);
		ast_root = $2;
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
		{
			extern int valueFlag;
			if (valueFlag)
				ast_root->value.print();
			parseError = 0;
		}
		else
		{
			parseError = 0;
		}

	}
}


InFuncSourceElements	:	InFuncSourceElement {
	$$ = new ast::StatementList;
	$$ -> list.push_back($1);
	//printf("To InFuncSourceElements\n");
}
| InFuncSourceElements InFuncSourceElement {
	$1->list.push_back($2);
	$$ = $1;
}
| InFuncSourceElements error {
	$$ = $1;
}
SourceElements	:	SourceElement {
	$$ = new ast::StatementList;
	$$ -> list.push_back($1);
	//printf("To SourceElements\n");
}
| SourceElements SourceElement {
	$1->list.push_back($2);
	$$ = $1;
}

SourceElement	:	FunctionDeclaration {
	$$ = $1;
}
|	Statement {
	$$ = $1;
}
InFuncSourceElement	:	FunctionDeclaration
|	Statement {
	$$ = $1;
}
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
