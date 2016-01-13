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
	Object(std::vector<TValue> arr);
	Object(std::map<std::string, TValue> prop): prop(prop), isArr(false) { }
	void changeProp(std::string name, TValue val)
	{
		prop[name] = val;
	}
	virtual TValue toDouble();
	virtual bool toBoolean();
	virtual std::string toString();

};


#endif
