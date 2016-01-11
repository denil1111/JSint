#include "varlist.hpp"
#include <cmath>
using namespace std;
TValue TValue::NaN()
{
	TValue ret;
	ret.type = TType::TNaN;
	return ret;
}
TValue TValue::ToDouble()
{
	if (type == TType::Tstring)
	{
		double x;
		stringstream ss(sValue.str);
		if (!(ss>>x))
		{
			return TValue::NaN();
		}
		else
		{
			return TValue(x);	
		}
	}
	else
	{
		return *this;
	}
}
TValue TValue::ToBoolean()
{
	if (type == TType::Tstring)
	{
		if (sValue.str == "")
		{
			return TValue(false);
		}
		else
		{
			return TValue(true);
		}
	}
	if (type == TType::Tdouble)
	{
		if (sValue.dou == 0)
		{
			return TValue(false);
		}
		else
		{
			return TValue(true);
		}
	}
	if (type == TType::TNaN)
	{
		return TValue(false);
	}
}
TValue TValue::operator   +( TValue &rx){
	TValue ret;
	if (this->type == TType::TNaN || rx.type == TType::TNaN)
	{
		return TValue::NaN();
	}
	if (this->type == TType::Tdouble)
	{
		switch (rx.type)
		{
			case TType::Tdouble: {
				ret.type = TType::Tdouble;
				ret.sValue.dou = this->sValue.dou + rx.sValue.dou;
				break;
			}
			case TType::Tstring: {
				ret.type = TType::Tstring;
				stringstream ss;
				string s1;
				ss<<this->sValue.dou;
				ss>>s1;
				ret.sValue.str = s1 + rx.sValue.str;
				break;
			}
		}
	}
	if (this->type == TType::Tstring)
	{
		switch (rx.type)
		{

			case TType::Tdouble: {
				ret.type = TType::Tstring;
				stringstream ss;
				string s1;
				ss<<rx.sValue.dou;
				ss>>s1;
				ret.sValue.str = this->sValue.str + s1;
				break;

			}
			case TType::Tstring: {
				ret.type = TType::Tstring;
				ret.sValue.str = this->sValue.str + rx.sValue.str;
				break;
			}
		}
	}
	return ret;
}
TValue TValue::operator   -( TValue &rx){
	TValue x = this->ToDouble();
	TValue y = rx.ToDouble();
	if (x.type == TType::TNaN || y.type == TType::TNaN)
	{
		return TValue::NaN();
	}
	return TValue(x.sValue.dou - y.sValue.dou);
}
TValue TValue::operator  *( TValue &rx){
	TValue x = this->ToDouble();
	TValue y = rx.ToDouble();
	if (x.type == TType::TNaN || y.type == TType::TNaN)
	{
		return TValue::NaN();
	}
	return TValue(x.sValue.dou * y.sValue.dou);
}
TValue TValue::operator  /( TValue &rx){
	TValue x = this->ToDouble();
	TValue y = rx.ToDouble();
	if (x.type == TType::TNaN || y.type == TType::TNaN)
	{
		return TValue::NaN();
	}
	return TValue(x.sValue.dou / y.sValue.dou);
}
TValue TValue::operator  %( TValue &rx){
	double t;
	TValue x = this->ToDouble();
	TValue y = rx.ToDouble();
	if (x.type == TType::TNaN || y.type == TType::TNaN)
	{
		return TValue::NaN();
	}
	t = fabs(x.sValue.dou) / fabs(y.sValue.dou);
	t = fabs(x.sValue.dou) - (int)t*fabs(y.sValue.dou);
	return TValue(t * (x.sValue.dou >0?1:-1)*(y.sValue.dou >0?1:-1));
}

TValue TValue::operator  >( TValue &rx){
	if (this->type == TType::Tstring && rx.type == TType::Tstring)
	{
		return TValue(this->sValue.str > rx.sValue.str);
	}
	TValue x = this->ToDouble();
	TValue y = rx.ToDouble();
	if (x.type == TType::TNaN || y.type == TType::TNaN)
	{
		return TValue(false);
	}
	return TValue(x.sValue.dou > y.sValue.dou);
}
TValue TValue::operator  <( TValue &rx){
	return rx > *this;
}
TValue TValue::operator  >=( TValue &rx){
	TValue ret,ret2;
	ret = *this > rx;
	ret2 = *this == rx;
	ret = ret || ret2;
	return ret;
}
TValue TValue::operator  <=( TValue &rx){
	return rx >= *this;
}
TValue TValue::operator  ==( TValue &rx){
	if (this->type == TType::Tstring && rx.type == TType::Tstring)
	{
		return TValue(this->sValue.str == rx.sValue.str);
	}
	TValue x = this->ToDouble();
	TValue y = rx.ToDouble();
	if (x.type == TType::TNaN || y.type == TType::TNaN)
	{
		return TValue(false);
	}
	return TValue(x.sValue.dou == y.sValue.dou);
}
TValue TValue::operator  !=( TValue &rx){
	TValue ret;
	ret = *this == rx;
	ret = !ret;
	return ret;
}
TValue TValue::operator  ||( TValue &rx){
	TValue x = this->ToBoolean();
	if (x.sValue.dou)
	{
		return *this;
	}
	else
	{
		return rx;
	}
}
TValue TValue::operator  &&( TValue &rx){
	TValue x = this->ToBoolean();
	if (!x.sValue.dou)
	{
		return *this;
	}
	else
	{
		return rx;TValue x = this->ToBoolean();
	if (x.sValue.dou)
	{
		return *this;
	}
	else
	{
		return rx;
	}
	}
}
TValue TValue::operator  |( TValue &rx){
	TValue x = this->ToDouble();
	TValue y = rx.ToDouble();
	if (x.type == TType::TNaN)
	{
		x = TValue(0);
	}
	if (y.type == TType::TNaN)
	{
		y = TValue(0);
	}
	return TValue((int)x.sValue.dou | (int)y.sValue.dou);
}
TValue TValue::operator  ^( TValue &rx){
	TValue x = this->ToDouble();
	TValue y = rx.ToDouble();
	if (x.type == TType::TNaN)
	{
		x = TValue(0);
	}
	if (y.type == TType::TNaN)
	{
		y = TValue(0);
	}
	return TValue((int)x.sValue.dou ^ (int)y.sValue.dou);
}
TValue TValue::operator  &( TValue &rx){
	TValue x = this->ToDouble();
	TValue y = rx.ToDouble();
	if (x.type == TType::TNaN)
	{
		x = TValue(0);
	}
	if (y.type == TType::TNaN)
	{
		y = TValue(0);
	}
	return TValue((int)x.sValue.dou & (int)y.sValue.dou);
}
TValue TValue::operator !(){
	if (ToBoolean().sValue.dou)
	{
		return TValue(false);
	}	
	else
	{
		return TValue(true);
	}
}
TValue TValue::operator  -(){
	TValue x = this->ToDouble();
	if (x.type == TType::TNaN)
	{
		return TValue::NaN();
	}
	return TValue(-x.sValue.dou);
}
TValue TValue::operator  >>( TValue &rx){
	TValue x = this->ToDouble();
	TValue y = rx.ToDouble();
	if (x.type == TType::TNaN || y.type == TType::TNaN)
	{
		return TValue::NaN();
	}
	return TValue((int)x.sValue.dou >> (int)y.sValue.dou);
}
TValue TValue::operator  <<( TValue &rx){
	TValue x = this->ToDouble();
	TValue y = rx.ToDouble();
	if (x.type == TType::TNaN || y.type == TType::TNaN)
	{
		return TValue::NaN();
	}
	return TValue((int)x.sValue.dou << (int)y.sValue.dou);
}
TValue TValue::logicRShift( TValue &rx){
	TValue x = this->ToDouble();
	TValue y = rx.ToDouble();
	if (x.type == TType::TNaN || y.type == TType::TNaN)
	{
		return TValue::NaN();
	}
	return TValue((unsigned int)x.sValue.dou >> (int)y.sValue.dou);
}

