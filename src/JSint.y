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
%token SLASHASSIGN SLASH EOF IDENTIFIER_NAME
%start Program

%type <debug> DECIMAL_LITERAL HEX_INTEGER_LITERAL STRING_LITERAL BOOLEAN_LITERAL NULL_LITERAL
%type <debug> SLASHASSIGN SLASH EOF IDENTIFIER_NAME


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
PrimaryExpression	:	"this"
|	ObjectLiteral
|	"(" Expression ")"
|	Identifier
|	ArrayLiteral
|	Literal
Literal	:	DECIMAL_LITERAL | HEX_INTEGER_LITERAL | STRING_LITERAL | BOOLEAN_LITERAL | NULL_LITERAL
Identifier	:	IDENTIFIER_NAME
ArrayLiteral    :  "[" Elision "]"
|   "[" ElementList Elision "]"
|   "[" ElementList "]"
|   "[" "]"
// example
// old one->ElementList	:	( Elision )? AssignmentExpression ( Elision AssignmentExpression )*
//new one
ElementList	:	Elision AssignmentExpression ElementListPart
|   AssignmentExpression ElementListPart
ElementListPart :   ElementListPart Elision AssignmentExpression
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
|	STRING_LITERAL
|	DECIMAL_LITERAL
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
| SLASH
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
| SLASHASSIGN
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
VariableDeclarationList	:	VariableDeclaration
| VariableDeclarationList  "," VariableDeclaration
VariableDeclarationListNoIn	:	VariableDeclarationNoIn
| VariableDeclarationListNoIn "," VariableDeclarationNoIn
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
CaseBlock	    :	"{" CaseBlockPart
| "{" CaseClauses CaseBlockPart
CaseBlockPart   :   "}"
| DefaultClause "}"
| DefaultClause CaseClauses "}"
CaseClauses	    :	CaseClause
| CaseClauses CaseClause
CaseClause	    :	"case" Expression ":"
| "case" Expression ":" StatementList
DefaultClause	:	"default" ":"
| "default" ":" StatementList
LabelledStatement	:	Identifier ":" Statement
ThrowStatement	:	"throw" Expression
| "throw" Expression ";"
TryStatement	:	"try" Block TryStatementPart
TryStatementPart:   Finally
| Catch
| Catch Finally
Catch	:	"catch" "(" Identifier ")" Block
Finally	:	"finally" Block
FormalParameterListInPare: "()"
| "(" FormalParameterList ")"
FunctionDeclaration	:	"function" Identifier FormalParameterListInPare FunctionBody
FunctionExpression	:	"function" FormalParameterListInPare FunctionBody
| "function" Identifier FormalParameterListInPare FunctionBody
FormalParameterList	:	Identifier
| FormalParameterList "," Identifier
FunctionBody	:	"{}"
| "{" SourceElements "}"
Program	:	EOF
| SourceElements EOF
SourceElements	:	SourceElement
| SourceElements SourceElement
SourceElement	:	FunctionDeclaration
|	Statement
ImportStatement	:	"import" Name ";"
| "import" Name "." "*"  ";"
Name	:	IDENTIFIER_NAME
| Name "." IDENTIFIER_NAME
JScriptVarStatement	:	"var" JScriptVarDeclarationList
| "var" JScriptVarDeclarationList ";"
JScriptVarDeclarationList	:	JScriptVarDeclaration
| JScriptVarDeclarationList "," JScriptVarDeclaration
JScriptVarDeclaration	:	Identifier ":" IDENTIFIER_NAME
| Identifier ":" IDENTIFIER_NAME Initialiser
