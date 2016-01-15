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
	runerror(str.c_str());
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
    value = TValue(val);
	return value;
}

TValue ast::CharType::run() {
    debugOut << "Creating char: " << val << std::endl;
    return value;
}

TValue ast::StringType::run() {
    debugOut << "Creating String: " << val << std::endl;
	value = TValue(val);
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
	TValue value,value1,value2;
	if (op!= OpType::assign)
	{
		value1 =  op1->run();
	}
	bool asgFlag = false;
	switch (op)
	{
		case OpType::land :{
			if (value1.toBoolean())
			{
				value2 = op2->run();
				value = value2;
			}
			else
			{
				value = value1;
			}
			break;
		}
		case OpType::lor :{
			if (!value1.toBoolean())
			{
				value2 = op2->run();
				value = value2;
			}
			else
			{
				value = value1;
			}
			break;
		}
		case OpType::lnot :{
			value = !value1;
			break;
		}
		case OpType::bit_not :{
			value = ~value1;
			break;
		}
		case OpType::positive :{
			value = - -value1;
			break;
		}
        case OpType::negtive :{
        	value = -value1;
        	break;
        }
        case OpType::pplus :{
        	RealType tempE(1);
        	Operator tempO(op1,OpType::plus_assign,&tempE);
        	TValue tv = tempO.run();
        	value = tv;
        	break;
        }
        case OpType::mminus :{
        	RealType tempE(1);
        	Operator tempO(op1,OpType::minus_assign,&tempE);
        	TValue tv = tempO.run();
        	value = tv;
        	break;
        }
        case OpType::rpplus :{
        	value = value1;
        	RealType tempE(1);
        	Operator tempO(op1,OpType::plus_assign,&tempE);
        	tempO.run();
        	break;
        }
        case OpType::rmminus :{
        	value = value1;
        	RealType tempE(1);
        	Operator tempO(op1,OpType::minus_assign,&tempE);
        	tempO.run();
        	break;
        }
        case OpType::type :{
        	value = TValue(value1.getTypeString());
        	break;
        }
        case OpType::voido :{
        	value = TValue::undefined();
        	break;
        }
        default:
        {
        	value2 = op2->run();
		    switch(op)
		    {
				case OpType::assign :{
					asgFlag = true;
					value = value2;
					break;
				}
				case OpType::plus_assign :{
					asgFlag = true;
				}
				case OpType::plus :{
					value = value1 + value2;
					break;
				}
				case OpType::minus_assign :{
					asgFlag = true;
				}
				case OpType::minus :{
					value = value1 - value2;
					break;
				}
				case OpType::mul_assign :{
					asgFlag = true;
				}
				case OpType::mul :{
					value = value1 * value2;
					break;
				}
				case OpType::div_assign :{
					asgFlag = true;
				}
				case OpType::div :{
					value = value1 / value2;
					break;
				}
				case OpType::mod_assign :{
					asgFlag = true;
				}
				case OpType::mod :{
					value = value1 % value2;
					break;
				}
				case OpType::bit_and_assign :{
					asgFlag = true;
				}
				case OpType::bit_and :{
					value = value1 & value2;
					break;
				}
				case OpType::bit_or_assign :{
					asgFlag = true;
				}
				case OpType::bit_or :{
					value = value1 | value2;
					break;
				}
				case OpType::bit_xor_assign :{
					asgFlag = true;
				}
				case OpType::bit_xor :{
					value = value1 ^ value2;
					break;
				}
				case OpType::eq :{
					value = value1 == value2;
					break;
				}
				case OpType::ne :{
					value = value1 != value2;
					break;
				}
				case OpType::lt :{
					value = value1 < value2;
					break;
				}
				case OpType::gt :{
					value = value1 > value2;
					break;
				}
				case OpType::le :{
					value = value1 <= value2;
					break;
				}
				case OpType::ge :{
					value = value1 >= value2;
					break;
				}
				case OpType::aeq :{
					value = value1 == value2;
					if (value1.getType() != value2.getType()) {
						value = TValue(false);
					}
					break;
				}
				case OpType::ane :{
					value = value1 == value2;
					if (value1.getType() != value2.getType()) {
						value = TValue(true);
					}
					break;
				}
				case OpType::lsh_assign :{
					asgFlag = true;
				}
				case OpType::lsh :{
					value = value1 << value2;
					break;
				}
				case OpType::rsh_assign :{
					asgFlag = true;
				}
				case OpType::rsh :{
					value = value1 >> value2;
					break;
				}
				case OpType::lrsh_assign :{
					asgFlag = true;
				}
				case OpType::lrsh :{
					value = value1.logicRShift(value2);
					break;
				}
				case OpType::comma :{
					value = value2;
					break;
				}
			}
        }
    }
    if (asgFlag) {
		auto id = dynamic_cast<Identifier*>(op1);
		if (id == nullptr)
		{
			runerror("leftside exp error");
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
	if (initial!=nullptr)
	{
		TValue val = initial->run();
		nowStack.newVar(name->name,val);
	}
	else
	{
		nowStack.newVar(name->name,TValue::undefined());
	}
	return value;
}

TValue ast::Program::run() {
	return value;
}

TValue ast::Routine::run() {
	return value;
}

TValue ast::FunctionDeclaration::run() {
    if (function_name) {
        debugOut << "declaring function: " << function_name->name << std::endl;
        debugOut << "with parameters: ";
    }
    else {
        debugOut << "declaring anonymous function with parameters: ";
    }

    for (auto parameter : *parameter_list) {
        debugOut << parameter->name << " ";
    }
    value = TValue(new DeclaredFunction(function_name, parameter_list, function_body));
    if (function_name) {
        nowStack.assignAndNew(function_name->name, value);
    }
    return value;
}

TValue ast::CallExpression::run() {
    debugOut<< "calling function: "<< std::endl;
    TValue val = funcExp->run();
    DeclaredFunction *function = val.function;
    debugOut<<val.function<<std::endl;
    if (function) {
    	std::vector<TValue> valueList;
    	if (argument_list)
    	{
    		for (auto arg : *argument_list) {
	            valueList.push_back(arg->run());
	        }
	    	val.function->parent->print();
	    	debugOut<<"run func"<<endl;
	        nowStack.push_new(val.function->parent);
	        try{
	        	value = function->execute(&valueList);
		    }catch(ast::ReturnException e){
		        value = e.value;
		    }
	        nowStack.pop();
    	}
    	else
    	{
    		nowStack.push_new(val.function->parent);
	        try{
	        	value = function->execute(nullptr);
		    }catch(ast::ReturnException e){
		        value = e.value;
		    }
	        nowStack.pop();
    	}
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
	bool conditionBool=condition->value.toBoolean();
	while(conditionBool){
		// debugOut<<"in whilestmt::while:"<<condition->value.toString()<<std::endl;
		try{
			loopStmt->run();
			condition->run();
			conditionBool=condition->value.toBoolean();
		}catch(BreakException &brexception){
			debugOut<<"while stmt brexception"<<std::endl;
			if(brexception.label==""){
				return;
			}else{
				//如果有标签
				Statement* stmt=labelMap[brexception.label];
				if(stmt==this){
					//如果就是这个结点
					return value;
				}else{
					//如果不是就再throw给外部
					throw brexception;
				}
			}
			return value;
		}catch(ContinueException &cnexception){
			debugOut<<"while stmt cnexception"<<std::endl;
			condition->run();
			conditionBool=condition->value.toBoolean();
			if(cnexception.label==""){
				continue;
			}else{
				//如果有标签
				Statement* stmt=labelMap[cnexception.label];
				if(stmt==this){
					//如果就是这个结点
					continue;
				}else{
					//如果不是就再throw给外部
					throw cnexception;
				}
			}

			return value;
		}
	}

	return value;
}
TValue ast::ForStmt::run() {

	bool condition=false;

	if(loopVar!=nullptr){
		loopVar->run();
	}
	if(startExp!=nullptr){
		startExp->run();
	}else{
		condition=true;
	}


	while(condition||startExp->value.toBoolean()){
		try{
			loopStmt->run();

			if(endExp!=nullptr){
				endExp->run();
			}

			if(startExp!=nullptr){
				startExp->run();
			}
		}catch(BreakException &brexception){
			debugOut<<"for stmt brexception"<<std::endl;
			if(brexception.label==""){
				return value;
			}else{
				//如果有标签
				Statement* stmt=labelMap[brexception.label];
				if(stmt==this){
					//如果就是这个结点
					return value;
				}else{
					//如果不是就再throw给外部
					throw brexception;
				}
			}
			return value;
		}catch(ContinueException &cnexception){
			debugOut<<"for stmt cnexception"<<std::endl;
			if(endExp!=nullptr){
				endExp->run();
			}
			if(startExp!=nullptr){
				startExp->run();
			}
			if(cnexception.label==""){
				continue;
			}else{
				//如果有标签
				debugOut<<"label justice"<<std::endl;
				Statement* stmt=labelMap[cnexception.label];
				if(stmt==this){
					//如果就是这个结点
					debugOut<<"label finded"<<std::endl;
					continue;
				}else{
					//如果不是就再throw给外部
					debugOut<<"label throw again"<<std::endl;
					throw cnexception;
				}
			}

			return value;
		}

	}

	return value;
}
TValue ast::CaseStmt::run() {
	debugOut<<"CaseStmt::run"<<std::endl;
	// try{
		thenStmt->run();
	// }catch(BreakException &exception){
	// 	debugOut<<"case stmt exception"<<std::endl;
	// }
	return value;
}

TValue ast::IfStmt::run() {
	condition->run();
	debugOut <<"IfStmt::run::"<<condition->value.toBoolean()<<std::endl;
	if(condition->value.toBoolean()){
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
			debugOut<<"for try::i="<<i<<std::endl;
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

				if(stmt->condition->value.toBoolean()){

					stmt->run();
					firstFlag=false;
				}
			}

		}catch(BreakException &exception){
			debugOut<<"switch stmt exception"<<std::endl;
			return value;
		}
	}

	// 如果最后没有任何匹配，就进入default那句往后执行
	if(firstFlag && defaultIndex!=-1){
		for(int i=defaultIndex;i<list->size();i++){
			try{
				debugOut<<"switch default try::i="<<i<<std::endl;
				stmt=(*list)[i];
				stmt->run();
			}catch(BreakException &exception){
				debugOut<<"switch stmt exception"<<std::endl;
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
TValue ast::ReturnStmt::run() {
	if (exp!=nullptr)
	{
		value = exp->run();
		throw ReturnException(value);
	} else
	{
		throw ReturnException(TValue::undefined());
	}

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
    stmt->run();
	return value;
}

TValue ast::TryStmt::run() {

	try{
		debugOut<<"111"<<endl;
		try{
			blockstmt->run();
		}catch(ReturnException & rtex){
			if(finallystmt!=nullptr){
				debugOut<<"need to run finally"<<endl;
			}else{
				debugOut<<"no finally"<<endl;
				throw rtex;
			}
		}
	}catch(MyException & ex){
		//如果抓住什么异常
		debugOut<<"MyException"<<endl;

		TValue exval=ex.myex;
		std::string name=catchstmt->identifier->name;


		debugOut<<"myexTvalue:"<<exval.toString()<<endl;
		debugOut<<"name:"<<name<<endl;

		TValue tmp;
		bool ifDup=false;

		if(nowStack.hasVar(name)){
			tmp=nowStack.getVar(name);
			ifDup=true;
			debugOut<<"nowStack:";
			nowStack.print();
		}else{
			nowStack.assignAndNew(name,exval);
			debugOut<<"nowStack:";
			nowStack.print();
		}

		try{
			catchstmt->run();
		}catch(ReturnException & rtex){
			if(finallystmt!=nullptr){
				debugOut<<"catch:need to run finally"<<endl;
			}else{
				debugOut<<"catch:no finally"<<endl;
				throw rtex;
			}
		}

		if(ifDup){
			debugOut<<"ifDup:true:setVar"<<endl;
			nowStack.setVar(name,tmp);
			debugOut<<"nowStack:";
			nowStack.print();
		}else{
			debugOut<<"ifDup:false:removeVar"<<endl;
			nowStack.removeVar(name);
			debugOut<<"nowStack:";
			nowStack.print();
		}

	}

	if(finallystmt!=nullptr){
		finallystmt->run();
	}

	return value;
}
TValue ast::ThrowStmt::run() {
	exp->run();
	throw MyException(exp->value);
	return value;
}
TValue ast::FinallyStmt::run() {

	stmt->run();
	return value;
}
TValue ast::CatchStmt::run() {
	stmt->run();
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
		debugOut<<property->name<<endl;
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
	debugOut<<"member pro"<<endl;

	if (rightExpList != nullptr) {

		Object* o;

		for (MemberNameList::iterator iter=rightExpList->begin();
			 iter!=rightExpList->end(); iter++) {
			 (*iter)->run();
		}

		for (MemberNameList::iterator iter=rightExpList->begin();
			 iter!=rightExpList->end(); iter++) {

			if (value.object == nullptr) {
				runerror("Not an object!");
			} else {
				o = value.object;
			}
			debugOut<<(*iter)->value.toString()<<endl;
			value = o->get((*iter)->value.toString());
		}
		// debugOut << "check in" << value.function<<std::endl;
		//debugOut << "check out!" << std::endl;
	}

	return value;

}

TValue ast::MemberName::run() {
	if (isIdentifier) {
		Identifier* id = dynamic_cast<Identifier*>(exp);
		value = TValue(id->name);
	} else {
		value = exp->run();
	}
	return value;
}

TValue ast::Block::run() {
	debugOut << "Enter new block!" << std::endl;
	// nowStack.push_new();
	this->stmtList->run();
	// nowStack.print();
	// nowStack.pop();
	debugOut << "Exit from block!" << std::endl;
	// nowStack.print();
	return value;
}
