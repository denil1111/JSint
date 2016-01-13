#ifndef VARLIST_H_
#define VARLIST_H_

#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iostream>
#include "utils.h"
class Object;
class DeclaredFunction;

namespace ast {
	class FunctionDeclaration;
}

extern void yyerror(char *s, ...);
extern std::string green(const std::string& str);
extern std::string red(const std::string& str);

class TValue {
public:
	static TValue NaN();
	static TValue undefined();
	static TValue null();

	struct TSValue{
		std::string str;
		double dou;
	};
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
	Object* object;
	DeclaredFunction* function;
	TSValue sValue;
	bool boolFlag = false;
	TType type;

	TValue(){
		type = TType::Tundefined;
	}
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
	TValue(Object *o) {
		type = TType::Tobject;
		object = o;
	}
	TValue(DeclaredFunction *func) {
		type = TType::Tfunction;
		function = func;
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
		if (type != TType::Tstring) {
			std::cout<<green(this->toString())<<std::endl;
		} else {
			std::cout<<"\"" << green(this->toString()) << "\"" << std::endl;
		}
	}
	void output() {
		std::cout<<this->toString()<<std::endl;
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
	void removeVar(std::string idname){
		std::map<std::string,TValue>::iterator it;
		it=list.find(idname);
		if (it == list.end()){
			return;
		}else{
			list.erase(it);
		}
	}
	bool hasVar(std::string idname) {
		if (list.find(idname) == list.end())
			return false;
		else return true;
	}
	TValue getVar(std::string idname) {
		if (hasVar(idname)) return list[idname];
		else {
			debugOut << red("Not exist in variable list!") << std::endl;
			exit(0);
		}
	}
	void print() {
		debugOut << "VarList(";
		for (auto& kv : list) {
			debugOut << kv.first << ": " << kv.second.toString() << ", ";
		}
		debugOut << ")" << std::endl;
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

	void setVar(std::string idname,TValue val) {
		for (auto it = vstack.rbegin(); it != vstack.rend(); ++it) {
			if (it->hasVar(idname)){
				it->assignAndNew(idname,val);
				return;
			}
		}
		return;
	}

	void removeVar(std::string idname) {
		for (auto it = vstack.rbegin(); it != vstack.rend(); ++it) {
			if (it->hasVar(idname)){
				it->removeVar(idname);
				return;
			}
		}
		return;
	}

	bool hasVar(std::string idname) {
		for (auto it = vstack.rbegin(); it != vstack.rend(); ++it) {
			if (it->hasVar(idname)) return true;
		}
		return false;
	}

	TValue getVar(std::string idname) {
		for (auto it = vstack.rbegin(); it != vstack.rend(); ++it) {
			if (it->hasVar(idname)) return it->getVar(idname);
		}
		debugOut<<"get id"<<idname<<std::endl;
		runerror("Not exist in variable stack!");
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
			debugOut << "level " << lv << " : ";
			vstack[lv].print();
		}
	}
};
#endif
