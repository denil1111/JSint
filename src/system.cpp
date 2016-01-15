#include "system.hpp"
void initSystem()
{
	debugOut<<"intit!"<<std::endl;
	Console* console = new Console;
	nowStack.assignAndNew("console",TValue(console));

}