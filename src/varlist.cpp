#include "varlist.hpp"
using namespace std;
TValue TValue::operator   +(const TValue &rx){
	TValue ret;
	if (this->type == TType::Tint)
	{
		switch (rx.type)
		{
			case TType::Tint: {
				ret.type = TType::Tint;
				ret.sValue.integer = this->sValue.integer + rx.sValue.integer;
				break;
			}
			case TType::Tdouble: {
				ret.type = TType::Tdouble;
				ret.sValue.dou = this->sValue.integer + rx.sValue.dou;
				break;
			}
			case TType::Tstring: {
				ret.type = TType::Tstring;
				stringstream ss;
				string s1;
				ss<<this->sValue.integer;
				ss>>s1;
				ret.sValue.str = s1 + rx.sValue.str;
			}
		}
	}
	return ret;
}