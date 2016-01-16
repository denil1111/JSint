#ifndef _SYSTEM_HPP_
#define _SYSTEM_HPP_
#include "DeclaredFunction.h"
extern VarStack nowStack;
class LogFunction : public DeclaredFunction
{
public:
	LogFunction()
	{
		parameter_list = new ParameterList;
		parameter_list->push_back(new ast::Identifier("x"));
		parent = nowStack.back();
	}
	virtual TValue execute(ArgumentList *args)
	{
		extern VarStack nowStack;
		(*args)[0].output();
		return TValue::undefined();
	}
};
class Console: public Object
{
public:
	Console() 
	{
		LogFunction *logfuc = new LogFunction;
		TValue val(logfuc);
		set("log",val);
	}
};
void initSystem();

class Prototype: public Object
{

};
#endif