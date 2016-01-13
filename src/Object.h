#ifndef OBJECT_H_
#define OBJECT_H_

#include <string>
#include <vector>
#include <map>
#include "varlist.hpp"

class Object : public TValue {
private:
	std::map<std::string, TValue> prop;
	bool isArr;
public:
	Object() { type = TType::Tobject; }
Object(std::vector<TValue> arr): isArr(true) {
		type = TType::Tobject;
		prop = std::map<std::string, TValue>();
		for (int i=0; i<arr.size(); i++) {
			prop[std::to_string(i)] = arr[i];
		}
	}
Object(std::map<std::string, TValue> prop): prop(prop), isArr(false) {
		type = TType::Tobject;
	}

	TValue get(std::string name) {
		if (prop.find(name) == prop.end()) {
			return TValue::undefined;
		} else return prop[name];
	}

	TValue get(int index) {
		return get(std::to_string(index));
	}
	
	virtual TValue toDouble() {
		if (isArr && prop.size() == 1 && prop["0"].toDouble().type != TType::TNaN) {
			return prop["0"].toDouble();
		} else return this->toString();
	}
	virtual bool toBoolean() {
		return true;
	}
	virtual std::string toString() {
		std::string str = "";
		if (isArr) {
			for (int i=0; i<prop.size(); i++) {
				str = str + prop[std::to_string(i)].toString();
				if (i!=prop.size()-1) str = str + ",";
			}
		} else str = "[object Object]";
		return str;
	}

};


#endif
