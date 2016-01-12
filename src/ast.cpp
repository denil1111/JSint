#include "ast.h"

#include <iostream>
#include <sstream>
#include <map>
#include <functional>
#include <stdexcept>
#include <cassert>

#include "utils.h"
using namespace std;
extern VarStack nowStack;
TValue ast::Identifier::run() {
    debugOut << "Creating identifier: " << name << std::endl;

	value = nowStack.getVar(name);

	return value;
}

TValue ast::IntegerType::run() {
    debugOut << "Creating integer: " << val << std::endl;
    return value;
}

TValue ast::RealType::run() {
    debugOut << "Creating real: " << val << std::endl;
    value.type = TValue::TType::Tdouble;
	value.sValue.dou = val;
	return value;
}

TValue ast::CharType::run() {
    debugOut << "Creating char: " << val << std::endl;
    return value;
}

TValue ast::StringType::run() {
    debugOut << "Creating String: " << val << std::endl;
	value.type = TValue::TType::Tstring;
	value.sValue.str = val;
	return value;
}

TValue ast::BooleanType::run() {
    debugOut << "Creating boolean: " << val << std::endl;
    value = TValue(val);
    return value;

}
TValue ast::RangeType::run() {
    debugOut << "Creating subscript range from " << this->low << " to " << this->high << std::endl;
    return value;

}
TValue ast::Operator::run() {
	if (op!= OpType::assign)
	{
		op1->run();
	}
	bool asgFlag = false;
	switch (op)
	{
		case OpType::land :{
			if (op1->value.toBoolean())
			{
				op2->run();
				value = op2->value;
			}
			else
			{
				value = op1->value;
			}
			break;
		}
		case OpType::lor :{
			if (!op1->value.toBoolean())
			{
				op2->run();
				value = op2->value;
			}
			else
			{
				value = op1->value;
			}
			break;
		}
		case OpType::lnot :{
			value = !op1->value;
			break;
		}
		case OpType::bit_not :{
			value = ~op1->value;
			break;
		}
		case OpType::positive :{
			value = - -op1->value;
			break;
		}
        case OpType::negtive :{
        	value = -op1->value;
        	break;
        }
        case OpType::pplus :{
        	RealType tempE(1);
        	Operator tempO(op1,OpType::plus_assign,&tempE);
        	tempO.run();
        	value = tempO.value;
        	break;
        }
        case OpType::mminus :{
        	RealType tempE(1);
        	Operator tempO(op1,OpType::minus_assign,&tempE);
        	tempO.run();
        	value = tempO.value;
        	break;
        }
        case OpType::rpplus :{
        	value = op1->value;
        	RealType tempE(1);
        	Operator tempO(op1,OpType::plus_assign,&tempE);
        	tempO.run();
        	break;
        }
        case OpType::rmminus :{
        	value = op1->value;
        	RealType tempE(1);
        	Operator tempO(op1,OpType::minus_assign,&tempE);
        	tempO.run();
        	break;
        }
        case OpType::type :{
        	value = TValue(op1->value.getTypeString());
        	break;
        }
        case OpType::voido :{
        	value = TValue::undefined();
        	break;
        }
        default:
        {
        	op2->run();
		    switch(op)
		    {
				case OpType::assign :{
					asgFlag = true;
					value = op2->value;
					break;
				}
				case OpType::plus_assign :{
					asgFlag = true;
				}
				case OpType::plus :{
					value = op1->value + op2->value;
					break;
				}
				case OpType::minus_assign :{
					asgFlag = true;
				}
				case OpType::minus :{
					value = op1->value - op2->value;
					break;
				}
				case OpType::mul_assign :{
					asgFlag = true;
				}
				case OpType::mul :{
					value = op1->value * op2->value;
					break;
				}
				case OpType::div_assign :{
					asgFlag = true;
				}
				case OpType::div :{
					value = op1->value / op2->value;
					break;
				}
				case OpType::mod_assign :{
					asgFlag = true;
				}
				case OpType::mod :{
					value = op1->value % op2->value;
					break;
				}
				case OpType::bit_and_assign :{
					asgFlag = true;
				}
				case OpType::bit_and :{
					value = op1->value & op2->value;
					break;
				}
				case OpType::bit_or_assign :{
					asgFlag = true;
				}
				case OpType::bit_or :{
					value = op1->value | op2->value;
					break;
				}
				case OpType::bit_xor_assign :{
					asgFlag = true;
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
					if (op1->value.getType() != op2->value.getType()) {
						value = TValue(false);
					}
					break;
				}
				case OpType::ane :{
					value = op1->value == op2->value;
					if (op1->value.getType() != op2->value.getType()) {
						value = TValue(true);
					}
					break;
				}
				case OpType::lsh_assign :{
					asgFlag = true;
				}
				case OpType::lsh :{
					value = op1->value << op2->value;
					break;
				}
				case OpType::rsh_assign :{
					asgFlag = true;
				}
				case OpType::rsh :{
					value = op1->value >> op2->value;
					break;
				}
				case OpType::lrsh_assign :{
					asgFlag = true;
				}
				case OpType::lrsh :{
					value = op1->value.logicRShift(op2->value);
					break;
				}
				case OpType::comma :{
					value = op2->value;
					break;
				}
			}
        }
    }
    if (asgFlag) {
		auto id = dynamic_cast<Identifier*>(op1);
		if (id == nullptr)
		{
			yyerror("leftside exp error");
		}
		else
		{
			nowStack.assignAndNew(id->name,value);
		}
	}

	return value;
}

TValue ast::AssignmentStmt::run() {
	return value;
}

TValue ast::ConstDecl::run() {
	return value;
}


TValue ast::VarDecl::run() {
	return value;
}

TValue ast::Program::run() {
	return value;
}

TValue ast::Routine::run() {
	return value;
}

TValue ast::FunctionDeclaration::run() {
    debugOut << "declaring function: " << function_name->name << std::endl;
    debugOut << "with parameters: ";
    for (auto parameter : *parameter_list) {
        debugOut << parameter->name << " ";
    }
    std::cout << std::endl;
    value = TValue(this);
    nowStack.assignAndNew(function_name->name, value);
    return value;
}


TValue ast::CallExpression::run() {
    debugOut<< "calling function: " << function_name->name << std::endl;
    value = nowStack.getVar(function_name->name);
    FunctionDeclaration *function = value.func;
    ParameterList *pl = function->parameter_list;
    FunctionBody *fb = function->function_body;

    if (argument_list) {
        int index = 0;

        if (pl->size() != argument_list->size()) {
            yyerror("wrong number of arguments");
        }
        for (auto arg : *argument_list) {
            arg->run();
        }

        std::cout << "with arguments: ";
        for (auto arg : *argument_list) {
            switch (arg->value.type) {
                case TValue::TType::Tstring: {
                    std::cout << arg->value.sValue.str << " ";
                    break;
                }
                case TValue::TType::Tdouble: {
                    std::cout << arg->value.sValue.dou << " ";
                    break;
                }
            }
            nowStack.assignAndNew(pl->at(index)->name, arg->value);
            index++;
        }
        std::cout << std::endl;
    }
    fb->run();
    return value;
}

TValue ast::FuncCall::run() {


	return value;
}

TValue ast::ProcCall::run() {


	return value;
}

TValue ast::SysFuncCall::run() {
	return value;
}



TValue ast::SysProcCall::run() {


	return value;
}

TValue ast::TypeDecl::run() {
	return value;
}

TValue ast::Expression::run() {
	return value;
}

TValue ast::WhileStmt::run() {


	return value;
}
TValue ast::ForStmt::run() {


	return value;
}
TValue ast::CaseStmt::run() {

	return value;
}

TValue ast::IfStmt::run() {
	condition->run();
	if(condition->value.toBoolean() == TValue(1).toBoolean()){
		thenStmt->run();
	}else{
		if(elseStmt!=nullptr){
			elseStmt->run();
		}
	}
	return value;
}

TValue ast::SwitchStmt::run() {


	return value;
}
// TValue ast::ArrayType::run() {

// 	return value;
// }

TValue ast::ArrayRef::run() {


	return value;
}

TValue ast::ContinueStmt::run() {


	return value;
}

TValue ast::BreakStmt::run() {


	return value;
}

TValue ast::TryStmt::run() {


	return value;
}
TValue ast::ThrowStmt::run() {


	return value;
}
TValue ast::FinallyStmt::run() {


	return value;
}
TValue ast::CatchStmt::run() {


	return value;
}


TValue ast::ArrayType::run() {

	for (auto expPtr : elList) {
		expPtr->run();
	}

	std::vector<TValue> values = std::vector<TValue>(elList.size());
	for (int i=0; i<elList.size(); i++) {
		values[i] = elList[i]->value;
	}
	value.arr = values;
	value.type = TValue::TType::Tarray;

	debugOut << "Creating array: " << "values" << std::endl;
	for (auto val : value.arr) {
		debugOut << val.toString() << ", ";
	}
	debugOut << std::endl;
	return value;
}


TValue ast::StatementList::run() {
	for (auto stmt: list){
		value = stmt->run();
	}
	return value;
}

TValue ast::Block::run() {
	debugOut << "Enter new block!" << std::endl;
	nowStack.push_new();
	this->stmtList->run();
	nowStack.print();
	nowStack.pop();
	debugOut << "Exit from block!" << std::endl;
	nowStack.print();
	return value;
}
