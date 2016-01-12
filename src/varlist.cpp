#include "varlist.hpp"
#include <cmath>
using namespace std;
string TValue::toString() 
{
	std::stringstream  ss;
	std::string st;
	if (type == TType::Tdouble) {
		if (boolFlag)
		{
			if (sValue.dou)
			{
				ss<<"true";
			}
			else
			{
				ss<<"false";
			}
		}
		else
		{
			ss << sValue.dou;
		}
	}
	if (type == TType::Tstring) {
		ss << "\""<<sValue.str<<"\"";
	}
	if (type == TType::TNaN) {
		ss<<"NaN";
	}
	if (type == TType::Tundefined) {
		ss<<"undefined";
	}
	if (type == TType::Tnull) {
		ss<<"null";
	}
	ss >> st;
	return st;
}
TValue TValue::NaN()
{
	TValue ret;
	ret.type = TType::TNaN;
	return ret;
}
TValue TValue::null()
{
	TValue ret;
	ret.type = TType::Tnull;
	return ret;
}
TValue TValue::undefined()
{
	TValue ret;
	ret.type = TType::Tundefined;
	return ret;
}
TValue TValue::toDouble()
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
	if (type == TType::Tdouble)
	{
		return *this;
	}
	return TType::TNaN;
}
bool TValue::toBoolean()
{
	if (type == TType::Tstring)
	{
		if (sValue.str == "")
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	if (type == TType::Tdouble)
	{
		if (sValue.dou == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	if (type == TType::TNaN)
	{
		return false;
	}
	if (type == TType::Tnull)
	{
		return false;
	}
	if (type == TType::Tundefined)
	{
		return false;
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
	TValue x = this->toDouble();
	TValue y = rx.toDouble();
	if (x.type == TType::TNaN || y.type == TType::TNaN)
	{
		return TValue::NaN();
	}
	return TValue(x.sValue.dou - y.sValue.dou);
}
TValue TValue::operator  *( TValue &rx){
	TValue x = this->toDouble();
	TValue y = rx.toDouble();
	if (x.type == TType::TNaN || y.type == TType::TNaN)
	{
		return TValue::NaN();
	}
	return TValue(x.sValue.dou * y.sValue.dou);
}
TValue TValue::operator  /( TValue &rx){
	TValue x = this->toDouble();
	TValue y = rx.toDouble();
	if (x.type == TType::TNaN || y.type == TType::TNaN)
	{
		return TValue::NaN();
	}
	return TValue(x.sValue.dou / y.sValue.dou);
}
TValue TValue::operator  %( TValue &rx){
	double t;
	TValue x = this->toDouble();
	TValue y = rx.toDouble();
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
	TValue x = this->toDouble();
	TValue y = rx.toDouble();
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
	TValue x = this->toDouble();
	TValue y = rx.toDouble();
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
	if (this->toBoolean())
	{
		return *this;
	}
	else
	{
		return rx;
	}
}
TValue TValue::operator  &&( TValue &rx){
	if (this->toBoolean())
	{
		return *this;
	}
	else
	{
		return rx;
	}
}
TValue TValue::operator  |( TValue &rx){
	TValue x = this->toDouble();
	TValue y = rx.toDouble();
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
	TValue x = this->toDouble();
	TValue y = rx.toDouble();
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
	TValue x = this->toDouble();
	TValue y = rx.toDouble();
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
	return TValue(!toBoolean());
}
TValue TValue::operator  -(){
	TValue x = this->toDouble();
	if (x.type == TType::TNaN)
	{
		return TValue::NaN();
	}
	return TValue(-x.sValue.dou);
}
TValue TValue::operator  >>( TValue &rx){
	TValue x = this->toDouble();
	TValue y = rx.toDouble();
	if (x.type == TType::TNaN || y.type == TType::TNaN)
	{
		return TValue::NaN();
	}
	return TValue((int)x.sValue.dou >> (int)y.sValue.dou);
}
TValue TValue::operator  <<( TValue &rx){
	TValue x = this->toDouble();
	TValue y = rx.toDouble();
	if (x.type == TType::TNaN || y.type == TType::TNaN)
	{
		return TValue::NaN();
	}
	return TValue((int)x.sValue.dou << (int)y.sValue.dou);
}
TValue TValue::logicRShift( TValue &rx){
	TValue x = this->toDouble();
	TValue y = rx.toDouble();
	if (x.type == TType::TNaN || y.type == TType::TNaN)
	{
		return TValue::NaN();
	}
	return TValue((unsigned int)x.sValue.dou >> (int)y.sValue.dou);
}
TValue TValue::operator  ~(){
	TValue x = this->toDouble();
	if (x.type == TType::TNaN)
	{
		x = TValue(0);
	}
	return TValue(~(int)x.sValue.dou);
}

