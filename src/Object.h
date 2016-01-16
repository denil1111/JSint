#ifndef OBJECT_H_
#define OBJECT_H_

#include <string>
#include <vector>
#include <map>
#include "varlist.hpp"

class Object {
private:
	VarList prop;
	bool isArr;
public:
Object(): prop(VarList()), isArr(false) {}
    Object(std::vector<TValue> arr): isArr(true) {
		prop = VarList();
		for (int i=0; i<arr.size(); i++) {
			prop.assignAndNew(std::to_string(i), arr[i]);
		}
	}
    Object(std::map<std::string, TValue> propMap): prop(VarList(propMap)), isArr(false) {}
    Object(VarList prop): prop(prop) {}
	virtual TValue toDouble();
	virtual bool toBoolean();
	virtual std::string toString();
	virtual std::string toOutput();
	
	TValue get(std::string name);
	TValue get(int index);
	void set(std::string name, TValue value);
	
};


#endif
