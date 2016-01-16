#include "system.hpp"
void initSystem()
{
	debugOut<<"initit!"<<std::endl;
	Console* console = new Console();
	debugOut << "type: " << TValue(console).toString() << std::endl;
	nowStack.assignAndNew("console",TValue(console));	
}
