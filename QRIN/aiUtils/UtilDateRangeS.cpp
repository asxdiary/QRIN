// Name:     UtilDateRangeS.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_UtilDateRangeS_cpp
#define ASX_UtilDateRangeS_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "UtilDateRange.hpp"
#include "UtilDate.hpp"
#include "UtilDateRangeS.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiUtils;

/** --------------Constructors and init_NULL-----------*/

UtilDateRangeS::UtilDateRangeS() { init_NULL(); }
UtilDateRangeS::UtilDateRangeS(const UtilDateRangeS* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
UtilDateRangeS::UtilDateRangeS(const UtilDateRangeS& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void UtilDateRangeS::init_NULL()	{
	_drS=NULL;
}

/** ---Public Data Setting Functions-----------------*/

void UtilDateRangeS::add(UtilDateRange* _obj) {
   if(_obj==NULL) myerr_msg("_obj==NULL",__FUNCTION__);
   _drS->insert(_obj);
}

void UtilDateRangeS::add(UtilDate* d1, UtilDate* d2) {
   add(UtilDateRange::instance(d1,d2));
}

/** --------   Init Functions -------------------------*/

void UtilDateRangeS::init() {
   Object::init();
	init_UtilDateRangeS();
}

void UtilDateRangeS::init_UtilDateRangeS() {
	init_drS();
}

void UtilDateRangeS::init_drS() {
   _drS = new set<UtilDateRange*>();
}

/** -----Destructors and Memory Cleanup functions -----*/

UtilDateRangeS::~UtilDateRangeS()	{ cleanMem(); }

void UtilDateRangeS::cleanMem()	{
	cleanMem_UtilDateRangeS();
	Object::cleanMem();
}

void UtilDateRangeS::cleanMem_UtilDateRangeS() {
	cleanMem_drS();
}

void UtilDateRangeS::cleanMem_drS() {
   if(_drS!=NULL) {
      set<UtilDateRange*>::iterator it;
      for(it=_drS->begin();it!=_drS->end();it++) delete *it;
      delete _drS;
   }
	_drS=NULL;
}

/** ------------- Data Access Functions --------------------*/

set<UtilDateRange*>* UtilDateRangeS::drS() {return _drS;}

/** ------------- Access classname dynamically --------------------*/

string UtilDateRangeS::className() const {return "UtilDateRangeS";}

/** ------------- Error Message Handling Functions ------------------*/

void UtilDateRangeS::myerr_msg(string msg, string func) {
	err_msg("UtilDateRangeS::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void UtilDateRangeS::fprint(string fname) {
	Object::fprint(fname);
	fprint_UtilDateRangeS(fname);
}

void UtilDateRangeS::fprint_UtilDateRangeS(string fname) {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
}

void UtilDateRangeS::fscan(string fname) {
	Object::fscan(fname);
	fscan_UtilDateRangeS(fname);
}

void UtilDateRangeS::fscan_UtilDateRangeS(string fname) {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
}

/** ------------- Reset Functions --------------------*/

void UtilDateRangeS::reset() {
	reset_UtilDateRangeS();
	Object::reset();
}

void UtilDateRangeS::reset_UtilDateRangeS() {
}

/** ----------  static instance function -----------*/


UtilDateRangeS* UtilDateRangeS::instance()	{
	UtilDateRangeS* ptr=new UtilDateRangeS();
	ptr->init();
	return ptr;
}


UtilDateRangeS* UtilDateRangeS::instance_fscan(string fname)	{
	UtilDateRangeS* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new UtilDateRangeS();
		ptr->init_NULL();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

bool UtilDateRangeS::overlap(UtilDate* ptr) {
   set<UtilDateRange*>::iterator it;
   bool flag = false;
   for(it=_drS->begin();it!=_drS->end() && !flag;it++) flag = (*it)->overlap(ptr);
   return flag;
}

bool UtilDateRangeS::overlap(UtilDateRange* ptr) {
   set<UtilDateRange*>::iterator it;
   bool flag = false;
   for(it=_drS->begin();it!=_drS->end() && !flag;it++) flag = (*it)->overlap(ptr);
   return flag;
}

#endif

