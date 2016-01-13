#include "system.hpp"
void initSystem()
{
	extern VarStack nowStack;
	Console* console = new Console;
	nowStack.assignAndNew("console",TValue(console));

}