#include "Object.h"
#include <regex>

TValue Object::get(std::string name) {
	if (prop.find(name) == prop.end()) {
		return TValue::undefined();
	} else {
        debugOut<<"finded: "<<name<<std::endl;
        return prop[name];
    }
}

TValue Object::get(int index) {
	return get(std::to_string(index));
}

void Object::set(std::string name, TValue val) {
	prop[name] = val;
}

TValue Object::toDouble() {
    if (isArr && prop.size() == 1 && prop["0"].toDouble().type != TValue::TType::TNaN) {
        return prop["0"].toDouble();
    } else return this->toString();
}

bool Object::toBoolean() {
    return true;
}

std::string Object::toString() {
    std::string str;
    if (isArr) {
		str = "[ ";		
        for (int i=0; i<prop.size(); i++) {
            str = str + prop[std::to_string(i)].toString();
            if (i!=prop.size()-1) str = str + ", ";
        }
		str = str + " ]";
	} else {
		str = "{ ";
		for (std::map<std::string, TValue>::iterator iter=prop.begin();
			 iter!=prop.end(); iter++) {
			if (std::regex_match(iter->first, std::regex("[$_a-zA-Z][$_a-zA-Z0-9]*"))) {
				str += iter->first + ": " + iter->second.toString();
			} else {
				str += "'" + iter->first + "': " + iter->second.toString();				
			}
			if (++iter!=prop.end()) str = str + ", ";
			iter--;
		}
		str = str + " }";
	}	
    return str;
}
