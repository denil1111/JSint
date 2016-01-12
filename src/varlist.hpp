#ifndef VARLIST_H_
#define VARLIST_H_

#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iostream>
#include "utils.h"

namespace ast {
	class FunctionDeclaration;
}

extern void yyerror(char *s, ...);
extern std::string green(const std::string& str);
extern std::string red(const std::string& str);

struct TSValue{
	std::string str;
	int dou;
};

class TValue {
public:
	enum TType {
		Tfunction,
		Tstring,
		Tdouble,
		Tobject,
		TNaN,
		Tbool,
		Tundefined,
		Tnull
	};
	//std::vector<TValue> arr;
	ast::FunctionDeclaration *func;
	TSValue sValue;
	bool boolFlag = false;
	TType type;

	static TValue NaN();
	static TValue undefined();
	static TValue null();
	
	TValue(){
		type = TType::Tundefined;
	}
	TValue(TType type) : type(type) {}
	TValue(unsigned int x) {
		type = TType::Tdouble;
		sValue.dou = x;
	}
	TValue(int x) {
		type = TType::Tdouble;
		sValue.dou = x;
	}
	TValue(double x) {
		type = TType::Tdouble;
		sValue.dou = x;
	}
	TValue(bool x) {
		type = TType::Tdouble;
		sValue.dou = x;
		boolFlag = true;
	}
	TValue(std::string x) {
		type = TType::Tstring;
		sValue.str = x;
	}
	TValue(ast::FunctionDeclaration* function) {
		type = TType::Tfunction;
		func = function;
	}

	virtual TValue toDouble() ;
	virtual bool toBoolean() ;
	virtual std::string toString();
		
	TType getType()
	{
		if (boolFlag) return TType::Tbool;
		else return type;

	}
	std::string getTypeString()
	{
		switch (getType())
		{
			case TType::Tfunction: return "function";
			case TType::Tstring: return "string";
			case TType::Tdouble: return "number";
			case TType::Tobject: return "object";
			case TType::TNaN: return "NaN";
			case TType::Tbool: return "bool";
			case TType::Tundefined: return "undefined";
			case TType::Tnull: return "nul";
		}

	}

	void print() {
		std::cout<<green(this->toString())<<std::endl;
	}
	
	TValue operator   +( TValue &rx);
	TValue operator   -( TValue &rx);
	TValue operator   *( TValue &rx);
	TValue operator   /( TValue &rx);
	TValue operator   %( TValue &rx);
	TValue operator   >( TValue &rx);
	TValue operator   <( TValue &rx);
	TValue operator   >=( TValue &rx);
	TValue operator   <=( TValue &rx);
	TValue operator   !=( TValue &rx);
	TValue operator   ==( TValue &rx);
	TValue operator   ||( TValue &rx);
	TValue operator   &&( TValue &rx);
	TValue operator   |( TValue &rx);
	TValue operator   &( TValue &rx);
	TValue operator   ^( TValue &rx);
	TValue operator   <<( TValue &rx);
	TValue operator   >>( TValue &rx);
	TValue logicRShift( TValue &rx);
	TValue operator   !();
	TValue operator   -();
	TValue operator   ~();

};
class VarList {
	std::map<std::string,TValue> list;
public:
	VarList() : list(std::map<std::string, TValue>()) {}
	void assignAndNew(std::string idname, TValue val){
		list[idname] = val;
	};
	bool hasVar(std::string idname) {
		if (list.find(idname) == list.end())
			return false;
		else return true;
	}
	TValue getVar(std::string idname) {
		if (hasVar(idname)) return list[idname];
		else {
			std::cout << red("Not exist in variable list!") << std::endl;
			exit(0);
		}
	}
	void print() {
		std::cout << "VarList(";
		for (auto& kv : list) {
			std::cout << kv.first << ": " << kv.second.toString() << ", ";
		}
		std::cout << ")" << std::endl;
	}
};

class VarStack {
	std::vector<VarList> vstack;
public:
	VarStack() : vstack(std::vector<VarList>()){
		this->push_new();
	}
	void assignAndNew(std::string idname, TValue val) {
		vstack.back().assignAndNew(idname, val);
	}
	TValue getVar(std::string idname) {
		for (auto it = vstack.rbegin(); it != vstack.rend(); ++it) {
			if (it->hasVar(idname)) return it->getVar(idname);
		}
		yyerror("Not exist in variable stack!");
	}
	void push(VarList varList) {
		vstack.push_back(varList);
	}
	void push_new() {
		this->push(VarList());
	}
	void pop() {
		vstack.pop_back();
	}
	void print() {
		for (int lv = vstack.size()-1; lv>=0; lv--) {
			std::cout << "level " << lv << " : ";
			vstack[lv].print();
		}
	}
};
#endif
