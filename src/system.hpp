#ifndef _SYSTEM_HPP_
#define _SYSTEM_HPP_
#include "DeclaredFunction.h"
class LogFunction : public DeclaredFunction
{
public:
	LogFunction()
	{
		parameter_list = new ParameterList;
		parameter_list->push_back(new ast::Identifier("x"));

	}
	virtual TValue execute(ArgumentList *args)
	{
		(*args)[0]->run().output();
		return TValue::undefined();
	}
};
class Console: public Object
{
public:
	Console() {
		LogFunction *logfuc = new LogFunction;
		TValue val(logfuc);
		changeProp("log",val);
	}
};
void initSystem();
#endif