// Name:     FS.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_FS_cpp
#define ASX_FS_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "ObjectDb.hpp"
#include "Company.hpp"
#include "FS.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctDb;
using namespace aiFin;
using namespace aiDb;

/** --------------Constructors and init_NULL-----------*/

FS::FS() { init_NULL(); }
FS::FS(const FS* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
FS::FS(const FS& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void FS::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void FS::init(Company* dbobj, UtilDate* end_d, UtilDate* dh, UtilDate* start_d) {
   ObjectDb::init(dbobj, end_d, dh, start_d);
	init_FS();
}

void FS::init_FS() {
}

/** -----Destructors and Memory Cleanup functions -----*/

FS::~FS()	{ cleanMem(); }

void FS::cleanMem()	{
	cleanMem_FS();
   ObjectDb::cleanMem();
}

void FS::cleanMem_FS() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string FS::className() const {return "FS";}

/** ------------- Error Message Handling Functions ------------------*/

void FS::myerr_msg(string msg, string func) {
	err_msg("FS::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void FS::fprint(string fname) {
   ObjectDb::fprint(fname);
	fprint_FS(fname);
}

void FS::fprint_FS(string fname) {
}

void FS::fscan(string fname) {
   ObjectDb::fscan(fname);
	fscan_FS(fname);
}

void FS::fscan_FS(string fname) {
}

/** ------------- Reset Functions --------------------*/

void FS::reset() {
	reset_FS();
   ObjectDb::reset();
}

void FS::reset_FS() {
}

/** ----------  static instance function -----------*/

FS* FS::instantiate(Object* dbobj, UtilDate* end_d, UtilDate* dh, UtilDate* start_d) {
   return FS::instance((Company*)dbobj, end_d, dh, start_d);
}

FS* FS::instance(Company* dbobj, UtilDate* end_d, UtilDate* dh, UtilDate* start_d) {
   FS* ptr=new FS();
   ptr->init(dbobj, end_d, dh, start_d);
	return ptr;
}


FS* FS::instance_fscan(string fname)	{
	FS* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new FS();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

#endif

