#ifndef VARLIST_H_
#define VARLIST_H_
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iostream>
<<<<<<< HEAD

=======
#include "declared_function.h"
>>>>>>> 63dfd311f3e2bbccc911f076e2dac11b5a85a62a
extern std::string green(const std::string& str);
extern std::string red(const std::string& str);
struct TValue {
	struct TSValue{
		std::string str;
		int integer;
		double dou;
	};
	enum TType {
		Tfunction,
		Tstring,
		Tint,
		Tdouble,
		Tarray,
		TNaN
	};
	DeclaredFunction *func;
	TSValue sValue;
	TType type;
	TValue(){}
	TValue(int x) {
		type = TType::Tint;
		sValue.integer = x;
	}
	TValue(double x) {
		type = TType::Tdouble;
		sValue.dou = x;
	}
	TValue(std::string x) {
		type = TType::Tint;
		sValue.str = x;
	}
	TValue(DeclaredFunction* function) {
		type = TType::Tfunction;
		func = function;
	}
	void print() const{
		std::cout<<green(this->toString())<<std::endl;
	}
    std::string toString() const {
		std::stringstream  ss;
		std::string st;
		if (type == TType::Tint) {
			ss << sValue.integer;
		}
		if (type == TType::Tstring) {
			ss << "\""<<sValue.str<<"\"";
		}
		ss >> st;
		return st;
	}
	TValue operator   +(const TValue &rx);
	TValue operator   -(const TValue &rx);
	TValue operator   *(const TValue &rx);
	TValue operator   /(const TValue &rx);
	TValue operator   %(const TValue &rx);
	TValue operator   >(const TValue &rx);
	TValue operator   <(const TValue &rx);
	TValue operator   >=(const TValue &rx);
	TValue operator   <=(const TValue &rx);
	TValue operator   !=(const TValue &rx);
	TValue operator   ==(const TValue &rx);
	TValue operator   ||(const TValue &rx);
	TValue operator   &&(const TValue &rx);
	TValue operator   |(const TValue &rx);
	TValue operator   &(const TValue &rx);
	TValue operator   ^(const TValue &rx);
	TValue operator   !();
	TValue operator   -();
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
		std::cout << red("Not exist in variable stack!") << std::endl;
		exit(0);
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
