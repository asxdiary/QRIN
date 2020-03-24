// Name:     FSDb.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_FSDb_cpp
#define ASX_FSDb_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "EADatedObjectDb.hpp"
#include "Company.hpp"
#include "FSDb.hpp"
#include "FS.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctDb;
using namespace aiDb;
using namespace aiFin;

/** --------------Constructors and init_NULL-----------*/

FSDb::FSDb() { init_NULL(); }
FSDb::FSDb(const FSDb* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
FSDb::FSDb(const FSDb& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void FSDb::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void FSDb::init(Company* dbobj) {
   EADatedObjectDb::init(dbobj);
	init_FSDb();
}

void FSDb::init_FSDb() {
}

/** -----Destructors and Memory Cleanup functions -----*/

FSDb::~FSDb()	{ cleanMem(); }

void FSDb::cleanMem()	{
	cleanMem_FSDb();
   EADatedObjectDb::cleanMem();
}

void FSDb::cleanMem_FSDb() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string FSDb::className() const {return "FSDb";}

/** ------------- Error Message Handling Functions ------------------*/

void FSDb::myerr_msg(string msg, string func) {
	err_msg("FSDb::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void FSDb::fprint(string fname) {
   EADatedObjectDb::fprint(fname);
	fprint_FSDb(fname);
}

void FSDb::fprint_FSDb(string fname) {
}

void FSDb::fscan(string fname) {
   EADatedObjectDb::fscan(fname);
	fscan_FSDb(fname);
}

void FSDb::fscan_FSDb(string fname) {
}

/** ------------- Reset Functions --------------------*/

void FSDb::reset() {
	reset_FSDb();
   EADatedObjectDb::reset();
}

void FSDb::reset_FSDb() {
}

/** ----------  static instance function -----------*/

FSDb* FSDb::instantiate(Object* dbobj)	{
   return FSDb::instance((Company*) dbobj);
}

FSDb* FSDb::instance(Company* dbobj)	{
	FSDb* ptr=new FSDb();
	ptr->init(dbobj);
	return ptr;
}


FSDb* FSDb::instance_fscan(string fname)	{
	FSDb* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new FSDb();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

FS* FSDb::fs(Company* cmp, UtilDate* end_d, UtilDate* dh, 
             int& xval)
{
   return (FS*) EADatedObjectDb::odb(cmp, end_d, dh, xval);
}

#endif

