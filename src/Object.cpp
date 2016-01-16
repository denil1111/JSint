#include "Object.h"

TValue Object::get(std::string name) {
	if (!prop.hasVar(name)) {
		return TValue::undefined();
	} else {
        debugOut<<"finded: "<<name<<std::endl;
        return prop.getVar(name);
    }
}

TValue Object::get(int index) {
	return get(std::to_string(index));
}

void Object::set(std::string name, TValue val) {
	prop.assignAndNew(name, val);
}

TValue Object::toDouble() {
    if (isArr && prop.getSize() == 1 && prop.getVar("0").toDouble().type != TValue::TType::TNaN) {
        return prop.getVar("0").toDouble();
    } else return this->toString();
}

bool Object::toBoolean() {
    return true;
}

std::string Object::toString() {
    if (isArr) {
		return prop.joinValue(",");
	} else {
		return "[object Object]";
	}
}

std::string Object::toOutput() {
	if (isArr) {
		std::string str;		
		str = "[ ";
		str += prop.joinValue(", ");
		str += " ]";
		return str;
	} else {
		std::string str;
		str = "{ ";
		str += prop.joinKeyValue(", ");
		str += " }";
		return str;
	}
}
