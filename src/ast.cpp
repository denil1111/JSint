#include "ast.h"

#include <iostream>
#include <sstream>
#include <map>
#include <functional>
#include <stdexcept>
#include <cassert>

#include "utils.h"
using namespace std;
extern VarList nowList;
void ast::Identifier::run() {
    std::cout << "Creating identifier: " << name << std::endl;
	value = nowList.getVar(name);
    
}

void ast::IntegerType::run() {
    std::cout << "Creating integer: " << val << std::endl;
	value.type = TValue::TType::Tint;
	value.sValue.integer = val;
}
void ast::RealType::run() {
    std::cout << "Creating real: " << val << std::endl;
}
void ast::CharType::run() {
    std::cout << "Creating char: " << val << std::endl;
}
void ast::StringType::run() {
    std::cout << "Creating String: " << val << std::endl;
	value.type = TValue::TType::Tstring;
	value.sValue.str = val;
}
void ast::BooleanType::run() {
    std::cout << "Creating boolean: " << val << std::endl;
}
void ast::RangeType::run() {
    std::cout << "Creating subscript range from " << this->low << " to " << this->high << std::endl;
}
void ast::BinaryOperator::run() {
	op2->run();
	if (op == OpType::assign) {
		auto id = dynamic_cast<Identifier*>(op1);
		if (id == nullptr)
		{
			yyerror("leftside exp error");
		}
		else
		{
			value = op2->value;
			nowList.assignAndNew(id->name,value);
		}
	}
	if (op == OpType::plus) {
		op1->run();
		value = op1->value + op2->value;
	}
	
}

void ast::AssignmentStmt::run() {
    
}

void ast::ConstDecl::run() {
    
}


void ast::VarDecl::run() {
    
}

void ast::Program::run() {
    
}

void ast::Routine::run() {
   
}
void ast::FuncCall::run() {
   
}

void ast::ProcCall::run() {
   
}

void ast::SysFuncCall::run() {}



void ast::SysProcCall::run() {
    
}

void ast::TypeDecl::run() {}

void ast::Expression::run() {}

void ast::IfStmt::run() {
    
}
void ast::WhileStmt::run() {
   
}
void ast::RepeatStmt::run() {
    
}
void ast::ForStmt::run() {
    
}
void ast::CaseStmt::run() {
    
}
void ast::SwitchStmt::run() {
   
}
void ast::GotoStmt::run(){
   
}
void ast::LabelStmt::run(){
    
}

void ast::ArrayType::run() {
}

void ast::ArrayRef::run() {
    
}


