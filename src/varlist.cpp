#include "varlist.hpp"
#include "Object.h"
#include <iomanip>
#include <cmath>
using namespace std;
string TValue::toString()
{
	std::ostringstream  ss;
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
			ss<<setprecision(14)<<sValue.dou;
		}
	}
	if (type == TType::Tstring) {
		ss << sValue.str;
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
	if (type == TType::Tfunction) {
		ss<<"function";
	}
	if (type == TType::Tobject) {
		ss<<(object->toString());
	}
	st = ss.str();
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
	if (type == TType::Tobject) {
		return object->toDouble();
	}
	if (type == TType::Tfunction) {
		return  TValue::NaN();
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
	if (type == TType::Tfunction)
	{
		return true;
	}
}
TValue TValue::operator   +( TValue &rx){
	TValue ret;
	if (this->type == TType::TNaN || rx.type == TType::TNaN)
	{
		return TValue::NaN();
	}
	if (this->type == TType::Tdouble && rx.type == TType::Tdouble)
	{
		ret.type = TType::Tdouble;
		ret.sValue.dou = this->sValue.dou + rx.sValue.dou;
		return ret;
	}
	return TValue(toString()+rx.toString());
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





//varStack
VarStack::VarStack(){
	vstack.push_back(new VarList);
}

void VarStack::setVar(std::string idname,TValue val) {
	VarList *nowList = (vstack.back());
	do
	{
		if (nowList->hasVar(idname))
		{
			nowList->assignAndNew(idname,val);
			return;
		}
		else
		{
			if (nowList->parent != nullptr)
				nowList = nowList->parent;
			else
				break;
		} 
	}while(1);
}

void VarStack::removeVar(std::string idname) {
	VarList *nowList = (vstack.back());
	do
	{
		if (nowList->hasVar(idname))
		{
			nowList->removeVar(idname);
			return;
		}
		else
		{
			if (nowList->parent != nullptr)
				nowList = nowList->parent;
			else
				break;
		} 
	}while(1);
}

bool VarStack::hasVar(std::string idname) {
	VarList *nowList = (vstack.back());
	do
	{
		if (nowList->hasVar(idname))
		{
			return true;
		}
		else
		{
			if (nowList->parent != nullptr)
				nowList = nowList->parent;
			else
				break;
		} 
	}while(1);
	return false;
}

TValue VarStack::getVar(std::string idname) {
	VarList *nowList = (vstack.back());
	do
	{
		if (nowList->hasVar(idname))
		{
			return nowList->getVar(idname);
		}
		else
		{
			if (nowList->parent != nullptr)
			{
				nowList = nowList->parent;
			}
				
			else
				break;
		} 
	}while(1);
	runerror("Not exist in variable stack!");
}
void VarStack::assignAndNew(std::string idname, TValue val) {
	if (hasVar(idname))
	{
		setVar(idname,val);
	}
	else
	{
		vstack.front()->assignAndNew(idname, val);
	}
}
void VarStack::newVar(std::string idname, TValue val) {
	if (vstack.back()->hasVar(idname))
	{
		runerror("redefined variable %s",idname.c_str());
	}
	else
	{
		vstack.back()->assignAndNew(idname, val);
	}
}

void VarStack::push(VarList *varList) {
	vstack.push_back(varList);
}
void VarStack::push_new(VarList* parent) {
	VarList *newList = new VarList;
	newList->parent =parent;
	this->push(newList);
}
void VarStack::pop() {
	vstack.pop_back();
}
VarList* VarStack::back() {

	return vstack.back();
}
void VarStack::print() {
	for (int lv = vstack.size()-1; lv>=0; lv--) {
		debugOut << "level " << lv << " : ";
		vstack[lv]->print();
	}
}
bool VarStack::isMain() {
	if (vstack.size() == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}