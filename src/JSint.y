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
using namespace std;

int yydebug = 1;
ast::Node* ast_root;
ast::BinaryOperator* noOp1Exp;
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

%token DECIMAL_LITERAL HEX_INTEGER_LITERAL STRING_LITERAL BOOLEAN_LITERAL NULL_LITERAL
%token SLASHASSIGN SLASH JEOF IDENTIFIER_NAME
%token THIS NEW DELETE VOID TYPEOF INSTANCEOF IN VAR IF ELSE DO WHILE FOR CONTINUE BREAK RETURN WITH SWITCH CASE DEFAULT THROW TRY CATCH FINALLY FUNCTION IMPORT
%token LEFT_BRACKET RIGHT_BRACKET LEFT_PARE RIGHT_PARE LEFT_BRACE RIGHT_BRACE COMMA DOT COLON SEMICOLON
%token PLUS MINUS MULTI ASSIGN PLUS_PLUS MINUS_MINUS TILDE QUES EXCLAM PERCENT LESS GREATER EQUAL LSHIFT RSHIFT RRSHIFT LESS_EQ GREATER_EQ NOT_EQUAL ALWAYS_EQ ALWAYS_NEQ BIT_AND BIT_OR BIT_XOR AND OR MULTI_ASG MOD_ASG PLUS_ASG MINUS_ASG LRSHIFT_ASG LSHIFT_ASG RSHIFT_ASG
%token BIT_AND_ASG BIT_XOR_ASG BIT_OR_ASG
%start Program

%type <debug> DECIMAL_LITERAL HEX_INTEGER_LITERAL STRING_LITERAL BOOLEAN_LITERAL NULL_LITERAL
%type <debug> SLASHASSIGN SLASH JEOF IDENTIFIER_NAME


// default type is ast node
%type <ast_Identifier> Identifier
%type <ast_Expression> PrimaryExpression Literal ArrayLiteral
%type <ast_Node> ElementList ElementListPart Elision ObjectLiteral
%type <ast_Node> PropertyNameAndValueList PropertyNameAndValueListPart
%type <ast_Node> PropertyNameAndValue PropertyName
%type <ast_Expression> MemberExpression MemberExpressionForIn
%type <ast_Expression> AllocationExpression AllocationExpressionBody
%type <ast_Expression> MemberExpressionParts MemberExpressionPart
%type <ast_Expression> CallExpressionForIn CallExpressionParts CallExpressionPart
%type <ast_CallExpression> CallExpression
%type <ast_ArgumentList> Arguments ArgumentList
%type <ast_Expression> LeftHandSideExpression LeftHandSideExpressionForIn
%type <ast_Expression> PostfixExpression PostfixOperator
%type <ast_Expression> UnaryExpression UnaryExpressionPart UnaryOperator
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
%type <ast_OpType> AssignmentOperator LogicalOROperator LogicalANDOperator BitwiseOROperator  EqualityOperator BitwiseXOROperator BitwiseANDOperator
%type <ast_OpType> RelationalNoInOperator RelationalOperator ShiftOperator AdditiveOperator MultiplicativeOperator
%type <ast_Expression> Expression ExpressionPart ExpressionNoIn ExpressionNoInPart
%type <ast_Node> ExpressionOrNull
%type <ast_Statement> Statement
%type <ast_Node> Block StatementList
%type <ast_Node> VariableStatement VariableDeclarationList  VariableDeclarationListNoIn
%type <ast_Node> VariableDeclaration VariableDeclarationNoIn
%type <ast_Node> Initialiser InitialiserNoIn
%type <ast_Statement> EmptyStatement ExpressionStatement
%type <ast_Node> IfStatement IterationStatement
%type <ast_Node> IdentifierComma
%type <ast_Node> ContinueStatement BreakStatement ReturnStatement
%type <ast_Node> WithStatement SwitchStatement
%type <ast_Node> CaseBlock CaseBlockPart CaseClauses CaseClause DefaultClause
%type <ast_Node> LabelledStatement ThrowStatement
%type <ast_Node> TryStatement TryStatementPart Catch Finally
%type <ast_ParameterList> FormalParameterListInPare FormalParameterList
%type <ast_FunctionDeclaration> FunctionDeclaration FunctionExpression
%type <ast_StatementList> FunctionBody
%type <ast_StatementList> Program
%type <ast_StatementList> SourceElements
%type <ast_Statement> SourceElement
%type <ast_Node> ImportStatement Name
%type <ast_Node> JScriptVarStatement JScriptVarDeclarationList JScriptVarDeclaration


%%
//张宇昊
PrimaryExpression	:	THIS
|	ObjectLiteral
|	LEFT_PARE Expression RIGHT_PARE
|	Identifier {
/*	//printf("identifier\n");*/
	$$ = $1;
}
|	ArrayLiteral
|	Literal {
/*	//printf("Literal\n");*/
	$$ = $1;
}
Literal	:	DECIMAL_LITERAL {
	$$ = new ast::IntegerType(atoi($1)); $$->debug = $1;
	//printf("number\n");
}
| HEX_INTEGER_LITERAL
| STRING_LITERAL {
	char a[200];
	strcpy(a,$1+1);
	a[strlen(a)-1] = 0;
/*	std::cout<<a<<std::endl;*/
	$$ = new ast::StringType(a); $$->debug = a;
}
| BOOLEAN_LITERAL | NULL_LITERAL
Identifier	:	IDENTIFIER_NAME {
	$$ = new ast::Identifier($1);
}
ArrayLiteral    :  LEFT_BRACKET Elision RIGHT_BRACKET
|   LEFT_BRACKET ElementList Elision RIGHT_BRACKET
|   LEFT_BRACKET ElementList RIGHT_BRACKET
|   LEFT_BRACKET RIGHT_BRACKET
ElementList	:	Elision AssignmentExpression ElementListPart
|   AssignmentExpression ElementListPart
ElementListPart :   ElementListPart Elision AssignmentExpression
|
Elision	:   COMMA
|   Elision COMMA
ObjectLiteral	:	LEFT_BRACE PropertyNameAndValueList RIGHT_BRACE
|   LEFT_BRACE  RIGHT_BRACE
PropertyNameAndValueList	:	PropertyNameAndValue PropertyNameAndValueListPart
PropertyNameAndValueListPart    :   PropertyNameAndValueListPart COMMA
|   PropertyNameAndValueListPart COMMA PropertyNameAndValue
|

PropertyNameAndValue	:	PropertyName COLON AssignmentExpression
PropertyName	:	Identifier
|	STRING_LITERAL
|	DECIMAL_LITERAL
MemberExpression	:  FunctionExpression MemberExpressionParts
|   PrimaryExpression MemberExpressionParts{
	if ($2 == nullptr)
	{
		$$ = $1;
/*		//printf("MemberExp\n");*/
	}
/*	//printf("MemberExp\n");*/
}
|	AllocationExpression
MemberExpressionForIn	:	FunctionExpression MemberExpressionParts
|   PrimaryExpression MemberExpressionParts {
/*	//printf("MemberExpForIn\n");*/
}

AllocationExpression    :   NEW MemberExpression AllocationExpressionBody
AllocationExpressionBody    :   AllocationExpressionBody Arguments MemberExpressionParts
|
MemberExpressionParts   :   MemberExpressionParts MemberExpressionPart
| {
	$$ = nullptr;
}
MemberExpressionPart    :   LEFT_BRACKET Expression RIGHT_BRACKET
|	DOT Identifier

CallExpression	:	MemberExpression Arguments CallExpressionParts {
	$$ = new ast::CallExpression(dynamic_cast<ast::Identifier*>($1), $2);
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
	$$ = new ast::ArgumentList();
	$$->push_back($1);
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
| LeftHandSideExpression PostfixOperator
PostfixOperator	:	 PLUS_PLUS
| MINUS_MINUS
UnaryExpression	:	PostfixExpression {
	$$ = $1;
}
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
| EXCLAM
MultiplicativeExpression	:    UnaryExpression MultiplicativeExpressionPart {
	auto exp = dynamic_cast<ast::BinaryOperator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}

MultiplicativeExpressionPart  : MultiplicativeExpressionPart MultiplicativeOperator UnaryExpression {
	$$ = new ast::BinaryOperator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>($$);
	}
}
| {
	$$ = nullptr;
}
MultiplicativeOperator	:	MULTI {
	$$ = ast::BinaryOperator::OpType::mul;
}
| SLASH {
	$$ = ast::BinaryOperator::OpType::div;
}
| PERCENT {
	$$ = ast::BinaryOperator::OpType::mod;
}
AdditiveExpression	:	MultiplicativeExpression AdditiveExpressionPart {
	auto exp = dynamic_cast<ast::BinaryOperator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}

AdditiveExpressionPart  :   AdditiveExpressionPart AdditiveOperator MultiplicativeExpression {
	$$ = new ast::BinaryOperator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>($$);
	}
}
| {
	$$ = nullptr;
}
AdditiveOperator	:	PLUS {
	$$ = ast::BinaryOperator::OpType::plus;
}
| MINUS {
	$$ = ast::BinaryOperator::OpType::minus;
}
ShiftExpression	:	AdditiveExpression ShiftExpressionPart {
	auto exp = dynamic_cast<ast::BinaryOperator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}
ShiftExpressionPart :   ShiftExpressionPart ShiftOperator AdditiveExpression {
	$$ = new ast::BinaryOperator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>($$);
	}
}
| {
	$$ = nullptr;
}
ShiftOperator	:	LSHIFT {
	$$ = ast::BinaryOperator::OpType::lsh;
}
| RSHIFT {
	$$ = ast::BinaryOperator::OpType::rsh;
}
| RRSHIFT  {
	$$ = ast::BinaryOperator::OpType::lrsh;
}
RelationalExpression	:	ShiftExpression RelationalExpressionPart {
	auto exp = dynamic_cast<ast::BinaryOperator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}
RelationalExpressionPart  :   RelationalExpressionPart RelationalOperator ShiftExpression {
	$$ = new ast::BinaryOperator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>($$);
	}
}
| {
	$$ = nullptr;
}
RelationalOperator	:	LESS {
	$$ = ast::BinaryOperator::OpType::lt;
}
| GREATER {
	$$ = ast::BinaryOperator::OpType::gt;
}
| LESS_EQ {
	$$ = ast::BinaryOperator::OpType::le;
}
| GREATER_EQ {
	$$ = ast::BinaryOperator::OpType::ge;
}
| INSTANCEOF {
	$$ = ast::BinaryOperator::OpType::iof;
}
| IN {
	$$ = ast::BinaryOperator::OpType::iin;
}
RelationalExpressionNoIn	:	ShiftExpression RelationalExpressionNoInPart
RelationalExpressionNoInPart  :   RelationalExpressionNoInPart RelationalNoInOperator ShiftExpression
|
RelationalNoInOperator	:	LESS
| GREATER
| LESS_EQ
| GREATER_EQ
| INSTANCEOF
EqualityExpression	:	RelationalExpression EqualityExpressionPart {
	auto exp = dynamic_cast<ast::BinaryOperator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}
EqualityExpressionPart  :   EqualityExpressionPart EqualityOperator RelationalExpression {
	$$ = new ast::BinaryOperator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>($$);
	}
}
| {
	$$ = nullptr;
}
EqualityExpressionNoIn	:	RelationalExpressionNoIn EqualityExpressionNoInPart
EqualityExpressionNoInPart  :   EqualityExpressionNoInPart EqualityOperator RelationalExpressionNoIn
|
EqualityOperator	:	EQUAL {
	$$ = ast::BinaryOperator::OpType::eq;
}
| NOT_EQUAL {
	$$ = ast::BinaryOperator::OpType::ne;
}
| ALWAYS_EQ {
	$$ = ast::BinaryOperator::OpType::aeq;
}
| ALWAYS_NEQ {
	$$ = ast::BinaryOperator::OpType::ane;
}
BitwiseANDExpression	:	EqualityExpression BitwiseANDExpressionPart {
	auto exp = dynamic_cast<ast::BinaryOperator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}
BitwiseANDExpressionPart  :   BitwiseANDExpressionPart BitwiseANDOperator EqualityExpression {
	$$ = new ast::BinaryOperator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>($$);
	}
}
| {
	$$ = nullptr;
}
BitwiseANDExpressionNoIn	:	EqualityExpressionNoIn BitwiseANDExpressionNoInPart
BitwiseANDExpressionNoInPart  :   BitwiseANDExpressionNoInPart BitwiseANDOperator EqualityExpressionNoIn
|
BitwiseANDOperator	:	BIT_AND {
	$$ = ast::BinaryOperator::OpType::bit_and;
}
BitwiseXORExpression	:	BitwiseANDExpression BitwiseXORExpressionPart {
	auto exp = dynamic_cast<ast::BinaryOperator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}
BitwiseXORExpressionPart   :   BitwiseXORExpressionPart BitwiseXOROperator BitwiseANDExpression {
	$$ = new ast::BinaryOperator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>($$);
	}
}
| {
	$$ = nullptr;
}
BitwiseXORExpressionNoIn	:	BitwiseANDExpressionNoIn BitwiseXORExpressionNoInPart
BitwiseXORExpressionNoInPart   :   BitwiseXORExpressionNoInPart BitwiseXOROperator BitwiseANDExpressionNoIn
|
BitwiseXOROperator	:	BIT_XOR {
	$$ = ast::BinaryOperator::OpType::bit_xor;
}
BitwiseORExpression	:	BitwiseXORExpression BitwiseORExpressionPart {
	auto exp = dynamic_cast<ast::BinaryOperator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}
BitwiseORExpressionPart   :   BitwiseORExpressionPart BitwiseOROperator BitwiseXORExpression {
	$$ = new ast::BinaryOperator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>($$);
	}
}
| {
	$$ = nullptr;
}
BitwiseORExpressionNoIn	:	BitwiseXORExpressionNoIn BitwiseORExpressionNoInPart
BitwiseORExpressionNoInPart   :   BitwiseORExpressionNoInPart BitwiseOROperator BitwiseXORExpressionNoIn
|
BitwiseOROperator	:	BIT_OR {
	$$ = ast::BinaryOperator::OpType::bit_or;
}
LogicalANDExpression	:	BitwiseORExpression LogicalANDExpressionPart {
	auto exp = dynamic_cast<ast::BinaryOperator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}
LogicalANDExpressionPart   :   LogicalANDExpressionPart LogicalANDOperator BitwiseORExpression {
	$$ = new ast::BinaryOperator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>($$);
	}
}
| {
	$$ = nullptr;
}
LogicalANDExpressionNoIn	:	BitwiseORExpressionNoIn LogicalANDExpressionNoInPart
LogicalANDExpressionNoInPart   :   LogicalANDExpressionNoInPart LogicalANDOperator BitwiseORExpressionNoIn
|
LogicalANDOperator	:	AND {
	$$ = ast::BinaryOperator::OpType::land;
}
LogicalORExpression	:	LogicalANDExpression LogicalORExpressionPart {
	auto exp = dynamic_cast<ast::BinaryOperator*>($2);
	if (exp == nullptr) {
		$$ = $1;
	}
	else {
		$$ = exp;
		noOp1Exp ->op1 = $1;
	}
}
LogicalORExpressionPart   :   LogicalORExpressionPart LogicalOROperator LogicalANDExpression {
	$$ = new ast::BinaryOperator($1,$2,$3);
	if ($1 == nullptr)
	{
		noOp1Exp = dynamic_cast<ast::BinaryOperator*>($$);
	}
}
| {
	$$ = nullptr;
}
LogicalORExpressionNoIn	:	LogicalANDExpressionNoIn LogicalORExpressionNoInPart
LogicalORExpressionNoInPart   :   LogicalORExpressionNoInPart LogicalOROperator LogicalANDExpressionNoIn
|
LogicalOROperator	:	OR {
	$$ = ast::BinaryOperator::OpType::lor;
}
ConditionalExpression	:	LogicalORExpression{
	$$ = $1;
}
|LogicalORExpression QUES AssignmentExpression COLON AssignmentExpression {
}
ConditionalExpressionNoIn	:	LogicalORExpressionNoIn
|LogicalORExpressionNoIn QUES AssignmentExpression COLON AssignmentExpressionNoIn
AssignmentExpression	:	LeftHandSideExpression AssignmentOperator AssignmentExpression
{
	$$ = new ast::BinaryOperator($1,$2,$3);
/*	//printf("an assign exp\n");*/
}
| ConditionalExpression{
	$$ = $1;
	//printf("an assign exp from condition\n");
}
AssignmentExpressionNoIn	:	LeftHandSideExpression AssignmentOperator AssignmentExpressionNoIn {}
| ConditionalExpressionNoIn
AssignmentOperator	:	ASSIGN {
	$$ =ast::BinaryOperator::OpType::assign;
	//printf("an assign\n");
}
| MULTI_ASG {
	$$ =ast::BinaryOperator::OpType::mul_assign;
}
| SLASHASSIGN {
	$$ =ast::BinaryOperator::OpType::div_assign;
}
| MOD_ASG {
	$$ =ast::BinaryOperator::OpType::mod_assign;
}
| PLUS_ASG {
	$$ =ast::BinaryOperator::OpType::plus_assign;
}
| MINUS_ASG {
	$$ =ast::BinaryOperator::OpType::minus_assign;
}
| LSHIFT_ASG {
	$$ =ast::BinaryOperator::OpType::lsh_assign;
}
| RSHIFT_ASG {
	$$ =ast::BinaryOperator::OpType::rsh_assign;
}
| LRSHIFT_ASG {
	$$ =ast::BinaryOperator::OpType::lrsh_assign;
}
| BIT_AND_ASG {
	$$ =ast::BinaryOperator::OpType::bit_and_assign;
}
| BIT_XOR_ASG {
	$$ =ast::BinaryOperator::OpType::bit_xor_assign;
}
| BIT_OR_ASG {
	$$ =ast::BinaryOperator::OpType::bit_or_assign;
}
Expression	:	AssignmentExpression ExpressionPart
{
	if ($2 == nullptr){
		$$ = $1;
	}
	else {
		$$ = new ast::BinaryOperator($1,ast::BinaryOperator::OpType::comma,$2);
	}


}
ExpressionPart   :    COMMA AssignmentExpression ExpressionPart{
	if ($3 == nullptr) {
		$$ = $2;
	} else {
		$$ = new ast::BinaryOperator($2,ast::BinaryOperator::OpType::comma,$3);
	}

}
| {
	$$ = nullptr;
}
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
{
	$$ = $1;
}
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
ExpressionStatement	:	Expression {
	$$ = $1;
}
| Expression SEMICOLON{
	$$ = $1;
}
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
| LEFT_BRACE SourceElements RIGHT_BRACE {
	$$ = $2;
}

Program	:	JEOF
| SourceElements JEOF
{
	$$ = $1;
}
SourceElements	:	SourceElement {
	extern int parseError;
	if (!parseError)
	{
		$$ = new ast::StatementList;
		$$ -> list.push_back($1);
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
			ast_root->value.print();
	}
	//printf("To SourceElements\n");
}
| SourceElements SourceElement {
	extern int parseError;
	if (!parseError)
	{
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
		//printf("To SourceElements\n");
		//printf("new source\n");
		if (!parseError)
			ast_root->value.print();
	}
	$1->list.push_back($2);
}
| error
SourceElement	:	FunctionDeclaration
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
