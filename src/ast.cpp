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
	else
	{
		op1->run();
		switch (op)
		{
			case OpType::plus :{
				value = op1->value + op2->value;
				break;
			}
			case OpType::minus :{
				value = op1->value - op2->value;
				break;
			}
			case OpType::mul :{
				value = op1->value * op2->value;
				break;
			}
			case OpType::div :{
				value = op1->value / op2->value;
				break;
			}
			case OpType::mod :{
				value = op1->value % op2->value;
				break;
			}
			case OpType::bit_and :{
				value = op1->value & op2->value;
				break;
			}
			case OpType::bit_or :{
				value = op1->value | op2->value;
				break;
			}
			case OpType::land :{
				value = op1->value && op2->value;
				break;
			}
			case OpType::lor :{
				value = op1->value || op2->value;
				break;
			}
			case OpType::bit_xor :{
				value = op1->value ^ op2->value;
				break;
			}
			case OpType::eq :{
				value = op1->value == op2->value;
				break;
			}
			case OpType::ne :{
				value = op1->value != op2->value;
				break;
			}
			case OpType::lt :{
				value = op1->value < op2->value;
				break;
			}
			case OpType::gt :{
				value = op1->value > op2->value;
				break;
			}
			case OpType::le :{
				value = op1->value <= op2->value;
				break;
			}
			case OpType::ge :{
				value = op1->value >= op2->value;
				break;
			}
			case OpType::aeq :{
				value = op1->value == op2->value;
				if (op1->value.type != op2->value.type) {
					value.sValue.integer = 0;
				}
				break;
			}
			case OpType::ane :{
				value = op1->value == op2->value;
				if (op1->value.type != op2->value.type) {
					value.sValue.integer = 1;
				}
				break;
			}
		}
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

void ast::FunctionDeclaration::run() {
    std::cout << "declaring function: " << function_name->name << std::endl;
    std::cout << "with parameters: ";
    for (auto parameter : *parameter_list) {
        std::cout << parameter->name << " ";
    }
    DeclaredFunction* func = new DeclaredFunction();
    value = TValue(func);
    nowList.assignAndNew(function_name->name, value);
}

void ast::CallExpression::run() {
    std::cout << "calling function: " << function_name->name << std::endl;
    for (auto arg : *argument_list) {
        arg->run();
    }
    std::cout << "with arguments: ";
    for (auto arg : *argument_list) {
        switch (arg->value.type) {
            case TValue::TType::Tint: {
                std::cout << arg->value.sValue.integer << " ";
                break;
            }
            case TValue::TType::Tstring: {
                std::cout << arg->value.sValue.str << " ";
                break;
            }
            case TValue::TType::Tdouble: {
                std::cout << arg->value.sValue.dou << " ";
                break;
            }
        }
    }
    value = nowList.getVar(function_name->name);
    (value.func)->callWithArguments();
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
