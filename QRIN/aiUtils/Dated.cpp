// Name:     Dated.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_Dated_cpp
#define ASX_Dated_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "UtilDate.hpp"
#include "Object.hpp"
#include "Dated.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiUtils;

/** --------------Constructors and init_NULL-----------*/

Dated::Dated() { init_NULL(); }
Dated::Dated(const Dated* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
Dated::Dated(const Dated& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void Dated::init_NULL()	{
	_d=NULL;
}

/** ---Public Data Setting Functions-----------------*/

void Dated::set_d(UtilDate* _obj) {
   myerr_msg("Invalid attempt to set the date",__FUNCTION__);
}

/** --------   Init Functions -------------------------*/

void Dated::init(UtilDate* d) {
   Object::init();
	init_Dated(d);
}

void Dated::init_Dated(UtilDate* d) {
	init_d(d);
}

void Dated::init_d(UtilDate* d) {_d=d;}

/** -----Destructors and Memory Cleanup functions -----*/

Dated::~Dated()	{ cleanMem(); }

void Dated::cleanMem()	{
	cleanMem_Dated();
   Object::cleanMem();
}

void Dated::cleanMem_Dated() {
	cleanMem_d();
}

void Dated::cleanMem_d() {
	_d=NULL;
}

/** ------------- Data Access Functions --------------------*/

UtilDate* Dated::d() {return _d;}

/** ------------- Access classname dynamically --------------------*/

string Dated::className() const {return "Dated";}

/** ------------- Error Message Handling Functions ------------------*/

void Dated::myerr_msg(string msg, string func) {
	err_msg("Dated::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void Dated::fprint(string fname) {
   Object::fprint(fname);
	fprint_Dated(fname);
}

void Dated::fprint_Dated(string fname) {
	util_ofprint_obj(fname,"d",_d);
}

void Dated::fscan(string fname) {
   Object::fscan(fname);
	fscan_Dated(fname);
}

void Dated::fscan_Dated(string fname) {
   Object::fscan(fname);
   _d = UtilDate::instance_fscan( util_ofname(fname,"d") );
}

/** ------------- Reset Functions --------------------*/

void Dated::reset() {
	reset_Dated();
   Object::reset();
}

void Dated::reset_Dated() {
}

/** ----------  static instance function -----------*/


Dated* Dated::instance(UtilDate* d)	{
	Dated* ptr=new Dated();
	ptr->init(d);
	return ptr;
}


Dated* Dated::instance_fscan(string fname)	{
	Dated* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new Dated();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

bool Dated::validate(UtilDate* d) {
   if(d->isBefore(this->d())) myerr_msg(this->className() + ": Invalid attempt to access data", __FUNCTION__);
   return true;
}

#endif

