#include "varlist.hpp"
using namespace std;
TValue TValue::operator   +(const TValue &rx){
	TValue ret;
	if (this->type == TType::TNaN || rx.type == TType::TNaN) 
	{
		ret.type = TType::TNaN;
		return ret;
	}
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
				break;
			} 
		}
	}
	if (this->type == TType::Tdouble)
	{
		switch (rx.type)
		{
			case TType::Tint: {
				ret.type = TType::Tdouble;
				ret.sValue.dou = this->sValue.dou + rx.sValue.integer;
				break;
			}
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
			
			case TType::Tint: {
				ret.type = TType::Tstring;
				stringstream ss;
				string s1;
				ss<<rx.sValue.integer;
				ss>>s1;
				ret.sValue.str = this->sValue.str + s1;
				break;
			}
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
TValue TValue::operator   -(const TValue &rx){
	TValue ret;
	if (this->type == TType::TNaN || rx.type == TType::TNaN) 
	{
		ret.type = TType::TNaN;
		return ret;
	}
	if (this->type == TType::Tint)
	{
		switch (rx.type)
		{
			case TType::Tint: {
				ret.type = TType::Tint;
				ret.sValue.integer = this->sValue.integer - rx.sValue.integer;
				break;
			}
			case TType::Tdouble: {
				ret.type = TType::Tdouble;
				ret.sValue.dou = this->sValue.integer - rx.sValue.dou;
				break;
			}
			case TType::Tstring: {
				ret.type = TType::TNaN;
				break;
			}
		}
	}
	if (this->type == TType::Tdouble)
	{
		switch (rx.type)
		{
			case TType::Tint: {
				ret.type = TType::Tdouble;
				ret.sValue.dou = this->sValue.dou - rx.sValue.integer;
				break;
			}
			case TType::Tdouble: {
				ret.type = TType::Tdouble;
				ret.sValue.dou = this->sValue.dou - rx.sValue.dou;
				break;
			}
			case TType::Tstring: {
				ret.type = TType::TNaN;
				break;
			}
		}
	}
	if (this->type == TType::Tstring)
	{
		ret.type = TType::TNaN;	
	}
	return ret;
}
TValue TValue::operator  *(const TValue &rx){
	TValue ret;
	if (this->type == TType::TNaN || rx.type == TType::TNaN) 
	{
		ret.type = TType::TNaN;
		return ret;
	}
	if (this->type == TType::Tint)
	{
		switch (rx.type)
		{
			case TType::Tint: {
				ret.type = TType::Tint;
				ret.sValue.integer = this->sValue.integer * rx.sValue.integer;
				break;
			}
			case TType::Tdouble: {
				ret.type = TType::Tdouble;
				ret.sValue.dou = this->sValue.integer * rx.sValue.dou;
				break;
			}
			case TType::Tstring: {
				ret.type = TType::TNaN;
				break;
			}
		}
	}
	if (this->type == TType::Tdouble)
	{
		switch (rx.type)
		{
			case TType::Tint: {
				ret.type = TType::Tdouble;
				ret.sValue.dou = this->sValue.dou * rx.sValue.integer;
				break;
			}
			case TType::Tdouble: {
				ret.type = TType::Tdouble;
				ret.sValue.dou = this->sValue.dou * rx.sValue.dou;
				break;
			}
			case TType::Tstring: {
				ret.type = TType::TNaN;
				break;
			}
		}
	}
	if (this->type == TType::Tstring)
	{
		ret.type = TType::TNaN;	
	}
	return ret;
}
TValue TValue::operator  /(const TValue &rx){
	TValue ret;
	if (this->type == TType::TNaN || rx.type == TType::TNaN) 
	{
		ret.type = TType::TNaN;
		return ret;
	}
	if (this->type == TType::Tint)
	{
		switch (rx.type)
		{
			case TType::Tint: {
				ret.type = TType::Tint;
				ret.sValue.integer = this->sValue.integer / rx.sValue.integer;
				break;
			}
			case TType::Tdouble: {
				ret.type = TType::Tdouble;
				ret.sValue.dou = this->sValue.integer / rx.sValue.dou;
				break;
			}
			case TType::Tstring: {
				ret.type = TType::TNaN;
				break;
			}
		}
	}
	if (this->type == TType::Tdouble)
	{
		switch (rx.type)
		{
			case TType::Tint: {
				ret.type = TType::Tdouble;
				ret.sValue.dou = this->sValue.dou / rx.sValue.integer;
				break;
			}
			case TType::Tdouble: {
				ret.type = TType::Tdouble;
				ret.sValue.dou = this->sValue.dou / rx.sValue.dou;
				break;
			}
			case TType::Tstring: {
				ret.type = TType::TNaN;
				break;
			}
		}
	}
	if (this->type == TType::Tstring)
	{
		ret.type = TType::TNaN;	
	}
	return ret;
}
TValue TValue::operator  %(const TValue &rx){
	TValue ret;
	if (this->type == TType::TNaN || rx.type == TType::TNaN) 
	{
		ret.type = TType::TNaN;
		return ret;
	}
	if (this->type == TType::Tint)
	{
		switch (rx.type)
		{
			case TType::Tint: {
				ret.type = TType::Tint;
				ret.sValue.integer = this->sValue.integer % rx.sValue.integer;
				break;
			}
			case TType::Tdouble: {
				ret.type = TType::TNaN;
				break;
			}
			case TType::Tstring: {
				ret.type = TType::TNaN;
				break;
			}
		}
	}
	if (this->type == TType::Tdouble)
	{
		ret.type = TType::TNaN;
	}
	if (this->type == TType::Tstring)
	{
		ret.type = TType::TNaN;	
	}
	return ret;
}
TValue TValue::operator  >(const TValue &rx){
	TValue ret;
	if (this->type == TType::TNaN || rx.type == TType::TNaN) 
	{
		ret.type = TType::TNaN;
		return ret;
	}
	if (this->type == TType::Tint)
	{
		switch (rx.type)
		{
			case TType::Tint: {
				ret.type = TType::Tint;
				ret.sValue.integer = this->sValue.integer > rx.sValue.integer;
				break;
			}
			case TType::Tdouble: {
				ret.type = TType::Tint;
				ret.sValue.dou = this->sValue.integer > rx.sValue.dou;
				break;
			}
			case TType::Tstring: {
				ret.type = TType::TNaN;
				break;
			}
		}
	}
	if (this->type == TType::Tdouble)
	{
		switch (rx.type)
		{
			case TType::Tint: {
				ret.type = TType::Tint;
				ret.sValue.dou = this->sValue.dou > rx.sValue.integer;
				break;
			}
			case TType::Tdouble: {
				ret.type = TType::Tint;
				ret.sValue.dou = this->sValue.dou > rx.sValue.dou;
				break;
			}
			case TType::Tstring: {
				ret.type = TType::TNaN;
				break;
			}
		}
	}
	if (this->type == TType::Tstring)
	{	
		switch (rx.type)
		{
			
			case TType::Tint: {
				ret.type = TType::TNaN;
				break;
			}
			case TType::Tdouble: {
				ret.type = TType::TNaN;
				break;
				
			}
			case TType::Tstring: {
				ret.type = TType::Tstring;
				ret.sValue.str = this->sValue.str > rx.sValue.str;
				break;
			}
		}
	}
	return ret;
}
TValue TValue::operator  <(const TValue &rx){
	TValue ret;
	ret = *this >= rx;
	ret = !ret;
	return ret;
}
TValue TValue::operator  >=(const TValue &rx){
	TValue ret,ret2;
	ret = *this > rx;
	ret2 = *this == rx;
	ret = ret | ret2;
	return ret;
}
TValue TValue::operator  <=(const TValue &rx){
	TValue ret;
	ret = *this > rx;
	ret = !ret;
	return ret;
}
TValue TValue::operator  ==(const TValue &rx){
	TValue ret;
	if (this->type == TType::TNaN || rx.type == TType::TNaN) 
	{
		ret.type = TType::TNaN;
		return ret;
	}
	if (this->type == TType::Tint)
	{
		switch (rx.type)
		{
			case TType::Tint: {
				ret.type = TType::Tint;
				ret.sValue.integer = this->sValue.integer == rx.sValue.integer;
				break;
			}
			case TType::Tdouble: {
				ret.type = TType::Tint;
				ret.sValue.dou = this->sValue.integer == rx.sValue.dou;
				break;
			}
			case TType::Tstring: {
				ret.type = TType::TNaN;
				break;
			}
		}
	}
	if (this->type == TType::Tdouble)
	{
		switch (rx.type)
		{
			case TType::Tint: {
				ret.type = TType::Tint;
				ret.sValue.dou = this->sValue.dou == rx.sValue.integer;
				break;
			}
			case TType::Tdouble: {
				ret.type = TType::Tint;
				ret.sValue.dou = this->sValue.dou == rx.sValue.dou;
				break;
			}
			case TType::Tstring: {
				ret.type = TType::TNaN;
				break;
			}
		}
	}
	if (this->type == TType::Tstring)
	{	
		switch (rx.type)
		{
			
			case TType::Tint: {
				ret.type = TType::TNaN;
				break;
			}
			case TType::Tdouble: {
				ret.type = TType::TNaN;
				break;
				
			}
			case TType::Tstring: {
				ret.type = TType::Tstring;
				ret.sValue.str = this->sValue.str == rx.sValue.str;
				break;
			}
		}
	}
	return ret;
}
TValue TValue::operator  !=(const TValue &rx){
	TValue ret;
	ret = *this == rx;
	ret = !ret;
	return ret;
}
TValue TValue::operator  ||(const TValue &rx){
	TValue ret;
	if (this->type == TType::TNaN || rx.type == TType::TNaN) 
	{
		ret.type = TType::TNaN;
		return ret;
	}
	if (this->type == TType::Tint)
	{
		switch (rx.type)
		{
			case TType::Tint: {
				ret.type = TType::Tint;
				ret.sValue.integer = this->sValue.integer || rx.sValue.integer;
				break;
			}
			case TType::Tdouble: {
				ret.type = TType::TNaN;
				break;
			}
			case TType::Tstring: {
				ret.type = TType::TNaN;
				break;
			}
		}
	}
	if (this->type == TType::Tdouble)
	{
		ret.type = TType::TNaN;
	}
	if (this->type == TType::Tstring)
	{	
		ret.type = TType::TNaN;
	}
	return ret;
}
TValue TValue::operator  &&(const TValue &rx){
	TValue ret;
	if (this->type == TType::TNaN || rx.type == TType::TNaN) 
	{
		ret.type = TType::TNaN;
		return ret;
	}
	if (this->type == TType::Tint)
	{
		switch (rx.type)
		{
			case TType::Tint: {
				ret.type = TType::Tint;
				ret.sValue.integer = this->sValue.integer && rx.sValue.integer;
				break;
			}
			case TType::Tdouble: {
				ret.type = TType::TNaN;
				break;
			}
			case TType::Tstring: {
				ret.type = TType::TNaN;
				break;
			}
		}
	}
	if (this->type == TType::Tdouble)
	{
		ret.type = TType::TNaN;
	}
	if (this->type == TType::Tstring)
	{	
		ret.type = TType::TNaN;
	}
	return ret;
}
TValue TValue::operator  |(const TValue &rx){
	TValue ret;
	if (this->type == TType::TNaN || rx.type == TType::TNaN) 
	{
		ret.type = TType::TNaN;
		return ret;
	}
	if (this->type == TType::Tint)
	{
		switch (rx.type)
		{
			case TType::Tint: {
				ret.type = TType::Tint;
				ret.sValue.integer = this->sValue.integer | rx.sValue.integer;
				break;
			}
			case TType::Tdouble: {
				ret.type = TType::TNaN;
				break;
			}
			case TType::Tstring: {
				ret.type = TType::TNaN;
				break;
			}
		}
	}
	if (this->type == TType::Tdouble)
	{
		ret.type = TType::TNaN;
	}
	if (this->type == TType::Tstring)
	{	
		ret.type = TType::TNaN;
	}
	return ret;
}
TValue TValue::operator  ^(const TValue &rx){
	TValue ret;
	if (this->type == TType::TNaN || rx.type == TType::TNaN) 
	{
		ret.type = TType::TNaN;
		return ret;
	}
	if (this->type == TType::Tint)
	{
		switch (rx.type)
		{
			case TType::Tint: {
				ret.type = TType::Tint;
				ret.sValue.integer = this->sValue.integer ^ rx.sValue.integer;
				break;
			}
			case TType::Tdouble: {
				ret.type = TType::TNaN;
				break;
			}
			case TType::Tstring: {
				ret.type = TType::TNaN;
				break;
			}
		}
	}
	if (this->type == TType::Tdouble)
	{
		ret.type = TType::TNaN;
	}
	if (this->type == TType::Tstring)
	{	
		ret.type = TType::TNaN;
	}
	return ret;
}
TValue TValue::operator  &(const TValue &rx){
	TValue ret;
	if (this->type == TType::TNaN || rx.type == TType::TNaN) 
	{
		ret.type = TType::TNaN;
		return ret;
	}
	if (this->type == TType::Tint)
	{
		switch (rx.type)
		{
			case TType::Tint: {
				ret.type = TType::Tint;
				ret.sValue.integer = this->sValue.integer & rx.sValue.integer;
				break;
			}
			case TType::Tdouble: {
				ret.type = TType::TNaN;
				break;
			}
			case TType::Tstring: {
				ret.type = TType::TNaN;
				break;
			}
		}
	}
	if (this->type == TType::Tdouble)
	{
		ret.type = TType::TNaN;
	}
	if (this->type == TType::Tstring)
	{	
		ret.type = TType::TNaN;
	}
	return ret;
}
TValue TValue::operator  !(){
	TValue ret;
	if (this->type == TType::TNaN ) 
	{
		ret.type = TType::TNaN;
		return ret;
	}
	if (this->type == TType::Tint)
	{
		ret.type = TType::Tint;
		ret.sValue.integer = !(this->sValue.integer);
	}
	if (this->type == TType::Tdouble)
	{
		ret.type = TType::TNaN;
	}
	if (this->type == TType::Tstring)
	{	
		ret.type = TType::TNaN;
	}
	return ret;
}
TValue TValue::operator  -(){
	TValue ret;
	if (this->type == TNaN ) 
	{
		ret.type = TType::TNaN;
		return ret;
	}
	if (this->type == TType::Tint)
	{
		ret.type = TType::Tint;
		ret.sValue.integer = -this->sValue.integer;
	}
	if (this->type == TType::Tdouble)
	{
		ret.type = TType::Tdouble;
		ret.sValue.dou = -this->sValue.dou;
	}
	if (this->type == TType::Tstring)
	{	
		ret.type = TType::TNaN;
	}
	return ret;
}
TValue TValue::operator  >>(const TValue &rx){
	TValue ret;
	if (this->type == TType::TNaN || rx.type == TType::TNaN) 
	{
		ret.type = TType::TNaN;
		return ret;
	}
	if (this->type == TType::Tint)
	{
		switch (rx.type)
		{
			case TType::Tint: {
				ret.type = TType::Tint;
				ret.sValue.integer = this->sValue.integer >> rx.sValue.integer;
				break;
			}
			case TType::Tdouble: {
				ret.type = TType::TNaN;
				break;
			}
			case TType::Tstring: {
				ret.type = TType::TNaN;
				break;
			}
		}
	}
	if (this->type == TType::Tdouble)
	{
		ret.type = TType::TNaN;
	}
	if (this->type == TType::Tstring)
	{	
		ret.type = TType::TNaN;
	}
	return ret;
}
TValue TValue::operator  <<(const TValue &rx){
	TValue ret;
	if (this->type == TType::TNaN || rx.type == TType::TNaN) 
	{
		ret.type = TType::TNaN;
		return ret;
	}
	if (this->type == TType::Tint)
	{
		switch (rx.type)
		{
			case TType::Tint: {
				ret.type = TType::Tint;
				ret.sValue.integer = this->sValue.integer << rx.sValue.integer;
				break;
			}
			case TType::Tdouble: {
				ret.type = TType::TNaN;
				break;
			}
			case TType::Tstring: {
				ret.type = TType::TNaN;
				break;
			}
		}
	}
	if (this->type == TType::Tdouble)
	{
		ret.type = TType::TNaN;
	}
	if (this->type == TType::Tstring)
	{	
		ret.type = TType::TNaN;
	}
	return ret;
}
TValue TValue::logicRShift(const TValue &rx){
	TValue ret;
	if (this->type == TType::TNaN || rx.type == TType::TNaN) 
	{
		ret.type = TType::TNaN;
		return ret;
	}
	if (this->type == TType::Tint)
	{
		switch (rx.type)
		{
			case TType::Tint: {
				ret.type = TType::Tint;
				ret.sValue.integer = (unsigned int)this->sValue.integer >> rx.sValue.integer;
				break;
			}
			case TType::Tdouble: {
				ret.type = TType::TNaN;
				break;
			}
			case TType::Tstring: {
				ret.type = TType::TNaN;
				break;
			}
		}
	}
	if (this->type == TType::Tdouble)
	{
		ret.type = TType::TNaN;
	}
	if (this->type == TType::Tstring)
	{	
		ret.type = TType::TNaN;
	}
	return ret;
}

