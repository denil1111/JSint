#include "ast.h"

#include <iostream>
#include <sstream>
#include <map>
#include <functional>
#include <stdexcept>
#include <cassert>

#include "utils.h"
#include "DeclaredFunction.h"

using namespace std;
extern VarStack nowStack;
extern ast::LabelMap labelMap;

/*
void debugSet() {
	debugOut << "Check In!" << std::endl;
}

void debugUnset() {
	debugOut << "Check Out!" << std::endl;
}

void myerror(std::string str) {
	yyerror(str.c_str());
}
*/

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
    value = TValue(new DeclaredFunction(function_name, parameter_list, function_body));
    nowStack.assignAndNew(function_name->name, value);
    return value;
}

TValue ast::CallExpression::run() {
    debugOut<< "calling function: "<< std::endl;
    TValue val = funcExp->run();
    DeclaredFunction *function = val.function;
    if (function) {
        value = function->execute(argument_list);
    }
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
	if(ifDo){
		loopStmt->run();
	}

	condition->run();
	while(condition->value.toBoolean()){
		loopStmt->run();
		condition->run();
	}

	return value;
}
TValue ast::ForStmt::run() {


	return value;
}
TValue ast::CaseStmt::run() {
	std::cout<<"CaseStmt::run"<<std::endl;
	// try{
		thenStmt->run();
	// }catch(BreakException &exception){
	// 	std::cout<<"case stmt exception"<<std::endl;
	// }
	return value;
}

TValue ast::IfStmt::run() {
	condition->run();
	std::cout <<"IfStmt::run::"<<condition->value.toBoolean()<<std::endl;
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
	
	CaseStmt* stmt;
	bool firstFlag=true;
	int defaultIndex=-1;
	for(int i=0;i<list->size();i++){
		try{
			std::cout<<"for try::i="<<i<<std::endl;
			stmt=(*list)[i];
			if(stmt->isDefault){
				//如果已经匹配过了case，那么就要执行default语句
				if(!firstFlag){
					stmt->run();
				}else{
					//如果还没有匹配，那么就要先跳过default语句；
					// 如果最后没有任何匹配，就进入default那句往后执行，所以记下编号；
					defaultIndex=i;	
				}
			}else{
				if(!firstFlag){
					stmt->run();
				}

				stmt->condition->run();

				exp->run();
				auto res=exp->value;

				if((stmt->condition->value==res).toBoolean()){

					stmt->run();
					firstFlag=false;
				}	
			}
			
		}catch(BreakException &exception){
			std::cout<<"switch stmt exception"<<std::endl;
			return value;
		}
	}

	// 如果最后没有任何匹配，就进入default那句往后执行
	if(firstFlag && defaultIndex!=-1){
		for(int i=defaultIndex;i<list->size();i++){
			try{
				std::cout<<"switch default try::i="<<i<<std::endl;
				stmt=(*list)[i];
				stmt->run();			
			}catch(BreakException &exception){
				std::cout<<"switch stmt exception"<<std::endl;
				return value;
			}
		}
	}else{
		//如果没有任何匹配，并且也没有default
		return value;
	}	
}
// TValue ast::ArrayType::run() {

// 	return value;
// }

TValue ast::ArrayRef::run() {


	return value;
}

TValue ast::ContinueStmt::run() {
	if(label!=nullptr){
		throw ContinueException(label->name);
	}else{
		throw ContinueException("");
	}
   
	return value;
}

TValue ast::BreakStmt::run() {
    if(label!=nullptr){
		throw BreakException(label->name);
	}else{
		throw BreakException("");
	}

	return value;
}

TValue ast::LabeledStmt::run() {
    labelMap[label->name]=stmt;
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

	elList->run();

	std::vector<Statement*> stmtList = elList->list;
	
	std::vector<TValue> values = std::vector<TValue>(stmtList.size());
	for (int i=0; i<stmtList.size(); i++) {
		Expression* exp = dynamic_cast<Expression*>(stmtList[i]);
		values[i] = exp->value;
	}
	Object* arrayValue = new Object(values);

	debugOut << "Creating array: " <<  arrayValue->toString() << std::endl;

	value = TValue(arrayValue); 
	return value;

}

TValue ast::ObjectType::run() {
	propList->run();

	std::map<std::string, TValue> props = std::map<std::string, TValue>();
	for (auto stmt : propList->list) {
		PropertyNameAndValue* property = dynamic_cast<PropertyNameAndValue*>(stmt);
		props[property->name] = property->valueExp->value;
	}

	Object* objectValue = new Object(props);

	debugOut <<  "Creating object: " << objectValue->toString() << std::endl;

	value = TValue(objectValue); 	
	return value;
}

TValue ast::StatementList::run() {
	for (auto stmt: list){
		value = stmt->run();
	}
	return value;
}

TValue ast::PropertyNameAndValue::run() {
	value = valueExp->run();
	return value;
}

TValue ast::PropertyNameAndValueList::run() {
	for (auto stmt: list) {
		PropertyNameAndValue* property = dynamic_cast<PropertyNameAndValue*>(stmt);
		value = property->run();
	}
	return value;
}

TValue ast::ElementList::run() {
	for (auto stmt: list) {
		Expression* exp = dynamic_cast<Expression*>(stmt);
		value = exp->run();
	}
	return value;
}


TValue ast::MemberPropertyExpression::run() {
	leftExp->run();
	value = leftExp->value;
	
	if (rightExpList != nullptr) {
		
		Object* o;
		
		for (ExpressionList::iterator iter=rightExpList->begin();
			 iter!=rightExpList->end(); iter++) {			 
			 (*iter)->run();
		}

		for (ExpressionList::iterator iter=rightExpList->begin();
			 iter!=rightExpList->end(); iter++) {
			
			if (value.object == nullptr) {
				yyerror("Not an object!");
			} else {
				o = value.object;
			}
			 
			value = o->get((*iter)->value.toString());
		}
		//debugOut << "check in" << std::endl;			
		//debugOut << "check out!" << std::endl;				
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
