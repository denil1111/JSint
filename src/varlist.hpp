#ifndef VARLIST_H_
#define VARLIST_H_
#include <string>
#include <map>
#include <sstream>
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
		if (type == TType::Tint) {
			std::string st;
			ss << sValue.integer;
			ss >> st;
			std::cout<<green(std::string(st))<<std::endl;
		}
	}
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