#include <iostream>
#include <stdexcept>

#include "ast.h"
#include "parser.hpp"
#include "ccalc.h"
#include "varlist.hpp"

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
extern int yyparse();
extern ast::StatementList* ast_root;
VarList nowList;
VarStack nowStack = VarStack();
int main(int argc, char** argv) {
	cout << green("start!") << endl;
	if (argc>1 && argv[1][0] == 'd')
	{
		debugFlag = 1;
	}
	init_buffer();
	yyparse();
	extern int parseError;
	// if (parseError) return 0;
	// cout<<"!!"<<endl;
	cout << green("syntax check success!") << endl;
	return 0;
}
