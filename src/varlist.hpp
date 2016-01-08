#ifndef VARLIST_H_
#define VARLIST_H_
#include <string>
#include <map>
#include <sstream>
#include <iostream>
extern std::string green(const std::string& str);
struct TValue {
	struct TSValue{
		std::string str;
		int integer;
		double dou;
	};
	enum TType {
		Tstring,
		Tint,
		Tdouble,
		Tarray,
	};
	TSValue sValue;
	TType type;
	void print() {
		std::stringstream  ss;
		std::string st;
		if (type == TType::Tint) {
			ss << sValue.integer;	
		}
		if (type == TType::Tstring) {
			ss << "\""<<sValue.str<<"\"";
		}
		ss >> st;
		std::cout<<green(std::string(st))<<std::endl;
	}
	TValue operator   +(const TValue &rx);
	// TValue operator   -(const X &rx);
};
class VarList {
	std::map<std::string,TValue> list;
public:
	void assignAndNew(std::string idname, TValue val){
		list[idname] = val;
	};
	TValue getVar(std::string idname) {
		return list[idname];
	}
};
#endif