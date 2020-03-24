// Name:     UtilDateRange.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_UtilDateRange_cpp
#define ASX_UtilDateRange_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "UtilDate.hpp"
#include "UtilDateRange.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiUtils;

/** --------------Constructors and init_NULL-----------*/

UtilDateRange::UtilDateRange() { init_NULL(); }
UtilDateRange::UtilDateRange(const UtilDateRange* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
UtilDateRange::UtilDateRange(const UtilDateRange& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void UtilDateRange::init_NULL()	{
	_sd=NULL;
	_ed=NULL;
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void UtilDateRange::init(UtilDate* sd, UtilDate* ed) {
   Object::init();
	init_UtilDateRange(sd, ed);
}

void UtilDateRange::init_UtilDateRange(UtilDate* sd, UtilDate* ed) {
	init_sd(sd);
	init_ed(ed);

   if(sd==NULL && ed==NULL) myerr_msg("sd==NULL && ed==NULL",__FUNCTION__);
   if(sd!=NULL && ed!=NULL && ed->isBefore(sd)) myerr_msg("ed->isBefore(sd)",__FUNCTION__);
}

void UtilDateRange::init_sd(UtilDate* obj) {_sd = obj;}
void UtilDateRange::init_ed(UtilDate* obj) {_ed = obj;}


/** -----Destructors and Memory Cleanup functions -----*/

UtilDateRange::~UtilDateRange()	{ cleanMem(); }

void UtilDateRange::cleanMem()	{
	cleanMem_UtilDateRange();
	Object::cleanMem();
}

void UtilDateRange::cleanMem_UtilDateRange() {
	cleanMem_sd();
	cleanMem_ed();
}

void UtilDateRange::cleanMem_sd() {
	_sd=NULL;
}

void UtilDateRange::cleanMem_ed() {
	_ed=NULL;
}

/** ------------- Data Access Functions --------------------*/

UtilDate* UtilDateRange::sd() {return _sd;}
UtilDate* UtilDateRange::ed() {return _ed;}

/** ------------- Access classname dynamically --------------------*/

string UtilDateRange::className() const {return "UtilDateRange";}

/** ------------- Error Message Handling Functions ------------------*/

void UtilDateRange::myerr_msg(string msg, string func) {
	err_msg("UtilDateRange::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void UtilDateRange::fprint(string fname) {
	Object::fprint(fname);
	fprint_UtilDateRange(fname);
}

void UtilDateRange::fprint_UtilDateRange(string fname) {
	util_ofprint_obj(fname,"sd",_sd);
	util_ofprint_obj(fname,"ed",_ed);
}

void UtilDateRange::fscan(string fname) {
	Object::fscan(fname);
	fscan_UtilDateRange(fname);
}

void UtilDateRange::fscan_UtilDateRange(string fname) {
   _sd = UtilDate::instance_fscan( util_ofname(fname, "sd") );
   _ed = UtilDate::instance_fscan( util_ofname(fname, "ed") );
}

/** ------------- Reset Functions --------------------*/

void UtilDateRange::reset() {
	reset_UtilDateRange();
	Object::reset();
}

void UtilDateRange::reset_UtilDateRange() {
}

/** ----------  static instance function -----------*/


UtilDateRange* UtilDateRange::instance(UtilDate* sd, UtilDate* ed)	{
	UtilDateRange* ptr=new UtilDateRange();
	ptr->init(sd, ed);
	return ptr;
}


UtilDateRange* UtilDateRange::instance_fscan(string fname)	{
	UtilDateRange* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new UtilDateRange();
		ptr->init_NULL();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

bool UtilDateRange::overlap(UtilDate* d) {
   if(d==NULL) return false;
   bool sflag = (sd()==NULL);
   bool eflag = (ed()==NULL);

   if(!sflag) sflag = d->isAfter(sd(),true);
   if(!eflag) eflag = d->isBefore(ed(),true);

   return sflag && eflag;
}

bool UtilDateRange::overlap(UtilDateRange* ptr) {
   if(ptr==NULL) return false;
   bool sflag = this->overlap(ptr->sd());
   bool eflag = this->overlap(ptr->ed());
   bool sflag2 = ptr->overlap(this->sd());
   bool eflag2 = ptr->overlap(this->ed());
   return sflag || eflag || sflag2 || eflag2;
}

#endif

