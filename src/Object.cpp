#include "Object.h"

TValue Object::get(std::string name) {
	if (prop.find(name) == prop.end()) {
		return TValue::undefined();
	} else {
        debugOut<<"finded"<<name<<std::endl;
        return prop[name];
    }
}

TValue Object::get(int index) {
	return get(std::to_string(index));
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
    std::string str = "";
    if (isArr) {
        for (int i=0; i<prop.size(); i++) {
            str = str + prop[std::to_string(i)].toString();
            if (i!=prop.size()-1) str = str + ",";
        }
    } else str = "[object Object]";
    return str;
}
