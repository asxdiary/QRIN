// Name:     AcctDb.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_AcctDb_cpp
#define ASX_AcctDb_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Db.hpp"
#include "AcctDb.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctDb;
using namespace aiDb;

/** --------------Constructors and init_NULL-----------*/

AcctDb::AcctDb() { init_NULL(); }
AcctDb::AcctDb(const AcctDb* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
AcctDb::AcctDb(const AcctDb& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void AcctDb::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void AcctDb::init() {
   Db::init();
	init_AcctDb();
}

void AcctDb::init_AcctDb() {
}

/** -----Destructors and Memory Cleanup functions -----*/

AcctDb::~AcctDb()	{ cleanMem(); }

void AcctDb::cleanMem()	{
	cleanMem_AcctDb();
   Db::cleanMem();
}

void AcctDb::cleanMem_AcctDb() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string AcctDb::className() const {return "AcctDb";}

/** ------------- Error Message Handling Functions ------------------*/

void AcctDb::myerr_msg(string msg, string func) {
	err_msg("AcctDb::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void AcctDb::fprint(string fname) {
   Db::fprint(fname);
	fprint_AcctDb(fname);
}

void AcctDb::fprint_AcctDb(string fname) {
}

void AcctDb::fscan(string fname) {
   Db::fscan(fname);
	fscan_AcctDb(fname);
}

void AcctDb::fscan_AcctDb(string fname) {
}

/** ------------- Reset Functions --------------------*/

void AcctDb::reset() {
	reset_AcctDb();
   Db::reset();
}

void AcctDb::reset_AcctDb() {
}

/** ----------  static instance function -----------*/

AcctDb* AcctDb::instantiate()	{
   return AcctDb::instance();
}

AcctDb* AcctDb::instance()	{
	AcctDb* ptr=new AcctDb();
	ptr->init();
	return ptr;
}


AcctDb* AcctDb::instance_fscan(string fname)	{
	AcctDb* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new AcctDb();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

FS* AcctDb::fs(Company* cmp, UtilDate* end_d, UtilDate* dh, 
           int& xval)
{
   return (FS*) Db::odb(cmp, end_d, dh, xval);
}

FSDb* AcctDb::create_eaodb(Object* dbobj) {
   return FSDb::instance((Company*) dbobj);
}

AcctDb* AcctDb::agg(vector<UtilDate*>* end_dv, UtilDate* dh, int& xval, AcctDb* db) {
   return (AcctDb*) Db::agg(end_dv, dh, xval, db);
}

AcctDb* AcctDb::aggQ(list<UtilDate*>* end_dL, UtilDate* dh, int& xval, AcctDb* db) {
   list<UtilDate*>::iterator it;
   for(it=end_dL->begin();it!=end_dL->end();it++) {
      vector<UtilDate*> dV;
      UtilDate::eoq(*it,&dV);
      db = this->agg(&dV, dh, xval, db);
   }
   return db;
}

AcctDb* AcctDb::aggA2(list<UtilDate*>* end_dL, UtilDate* dh, int& xval, AcctDb* db) {
   list<UtilDate*>::iterator it;
   for(it=end_dL->begin();it!=end_dL->end();it++) {
      vector<UtilDate*> dV(2);
      dV[1] = *it;
      dV[0] = dV[1]->prev_eom(12);
      db = this->agg(&dV, dh, xval, db);
   }
   return db;
}

AcctDb* AcctDb::interpolateA(list<UtilDate*>* dL, int& xval, AcctDb* db) {
   list<UtilDate*>::iterator it;
   UtilDate* start_d = NULL;
   UtilDate* end_d = NULL;
   UtilDate* dh = NULL;

   for(it=dL->begin();it!=dL->end();it++) {
      end_d = *it;
      start_d = end_d->prev_eom(12);
      dh = start_d;
      db = (AcctDb*) this->interpolate(end_d, dh, start_d, xval, db);
   }

   return (AcctDb*) db;
}

AcctDb* AcctDb::interpolateA2(UtilDate* dh, list<UtilDate*>* dL, int& xval, AcctDb* db) {
   list<UtilDate*>::iterator it;
   UtilDate* start_d = NULL;
   UtilDate* end_d = NULL;

   for(it=dL->begin();it!=dL->end();it++) {
      end_d = *it;
      start_d = end_d->prev_eom(12);
      db = (AcctDb*) this->interpolate(end_d, dh, start_d, xval, db);
   }

   return (AcctDb*) db;
}



#endif

