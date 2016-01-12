#include <iostream>
#include <stdexcept>

#include "ast.h"
#include "parser.hpp"
#include "ccalc.h"
#include "varlist.hpp"
#include "string.h"

using namespace std;
std::string red(const std::string& str) {
	std::string red_b = "\033[1;31m";
	std::string red_e = "\033[0m";
	return red_b + str + red_e;
}
std::string green(const std::string& str) {
	std::string red_b = "\033[1;32m";
	std::string red_e = "\033[0m";
	return red_b + str + red_e;
}
int debugFlag = 0;
<<<<<<< HEAD
ast::LabelMap labelMap;
=======
int valueFlag = 1;
>>>>>>> 73201c9f9a93639cf8d712af274e0d5e0ff4bfd8
extern int yyparse();
extern ast::StatementList* ast_root;
VarStack nowStack = VarStack();
int main(int argc, char** argv) {
	for (int i=1;i<argc;i++)
	{
		if (strcmp(argv[i],"-d")==0)
		{
			debugFlag = 1;
		}
		if (strcmp(argv[i],"-a")==0)
		{
			valueFlag = 0;
		}
	}
	debugOut <<green("start!") << endl;
	init_buffer();
	yyparse();
	extern int parseError;
	if (parseError) return 0;
	// cout<<"!!"<<endl;
	debugOut << green("-----success run-----") << endl;
	return 0;
}
