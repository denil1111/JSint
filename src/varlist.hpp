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
		TNaN
	};
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
	void print() const{
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
	void assignAndNew(std::string idname, TValue val){
		list[idname] = val;
	};
	TValue getVar(std::string idname) {
		return list[idname];
	}
};
#endif