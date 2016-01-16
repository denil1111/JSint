#ifndef OBJECT_H_
#define OBJECT_H_

#include <string>
#include <vector>
#include <map>
#include "varlist.hpp"

class Object {
private:
	std::map<std::string, TValue> prop;
	bool isArr;
public:
	Object() {}
    Object(std::vector<TValue> arr): isArr(true) {
		prop = std::map<std::string, TValue>();
		for (int i=0; i<arr.size(); i++) {
			prop[std::to_string(i)] = arr[i];
		}
	}
	Object(std::map<std::string, TValue> prop): prop(prop), isArr(false) { }
	// void changeProp(std::string name, TValue val)
	// {
	// 	prop[name] = val;
	// }
	virtual TValue toDouble();
	virtual bool toBoolean();
	virtual std::string toString();

	TValue get(std::string name);
	TValue get(int index);
	void set(std::string name, TValue value);
	
};


#endif
