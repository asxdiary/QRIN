// Name:     StringDbAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_StringDbAccount_cpp
#define ASX_StringDbAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DbAccount.hpp"
#include "StringDbAccount.hpp"
#include "ObjectDb.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;

/** --------------Constructors and init_NULL-----------*/

StringDbAccount::StringDbAccount() { init_NULL(); }
StringDbAccount::StringDbAccount(const StringDbAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
StringDbAccount::StringDbAccount(const StringDbAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void StringDbAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void StringDbAccount::init(string type) {
   DbAccount::init(type,"string");
	init_StringDbAccount();
}

void StringDbAccount::init_StringDbAccount() {
}

/** -----Destructors and Memory Cleanup functions -----*/

StringDbAccount::~StringDbAccount()	{ cleanMem(); }

void StringDbAccount::cleanMem()	{
	cleanMem_StringDbAccount();
   DbAccount::cleanMem();
}

void StringDbAccount::cleanMem_StringDbAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string StringDbAccount::className() const {return "StringDbAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void StringDbAccount::myerr_msg(string msg, string func) {
	err_msg("StringDbAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void StringDbAccount::fprint(string fname) {
   DbAccount::fprint(fname);
	fprint_StringDbAccount(fname);
}

void StringDbAccount::fprint_StringDbAccount(string fname) {
}

void StringDbAccount::fscan(string fname) {
   DbAccount::fscan(fname);
	fscan_StringDbAccount(fname);
}

void StringDbAccount::fscan_StringDbAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void StringDbAccount::reset() {
	reset_StringDbAccount();
   DbAccount::reset();
}

void StringDbAccount::reset_StringDbAccount() {
}

/** ----------  static instance function -----------*/


StringDbAccount* StringDbAccount::instance(string type)	{
	StringDbAccount* ptr=new StringDbAccount();
	ptr->init(type);
	return ptr;
}


StringDbAccount* StringDbAccount::instance_fscan(string fname)	{
	StringDbAccount* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new StringDbAccount();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

void StringDbAccount::populate(ObjectDb* odb, string val, int& xval) {
   xval = 0;
   odb->add_sdba(this, val, xval);
}

void StringDbAccount::compute(vector<ObjectDb*>* odbv, int& xval) {
   DbAccount::compute(odbv, xval);
   if(xval>0) return;
   ObjectDb* odb = odbv->back();
   odb->sdba(NULL,NULL,odb->dh(),this,xval);
   return;
}

/** Algorithm:
 * 1. Use the dba account for the last odb */
string StringDbAccount::agg_guts(vector<ObjectDb*>* odbv, UtilDate* dh, int& xval) {
   ObjectDb* lodb = NULL;
   string x;

   xval = 0;
   lodb = odbv->back();
   x = lodb->sdba(NULL, NULL, dh, this, xval);

   return x;
}

void StringDbAccount::agg(ObjectDb* odb, vector<ObjectDb*>* odbv, UtilDate* dh, int& xval) {
   string x = this->agg_guts(odbv, dh, xval);
   if(xval==0) odb->add_sdba(this, x, xval);
   return;
}

void StringDbAccount::copy(UtilDate* dh, ObjectDb* odb1, ObjectDb* odb2, int& xval) {
   string x = odb1->sdba(NULL, NULL, dh, this, xval);
   odb2->add_sdba(this, x, xval);
   return;
}

void StringDbAccount::interpolate(ObjectDb* odb1, ObjectDb* odb2, ObjectDb* odb,
                                  int& xval) 
{
   UtilDate* dh = odb->dh();
   string x1, x2, x;
   int n1, n2;

   //check if odb1 and odb2 are contigous
   if(odb1->end_d()!=odb2->start_d()) {xval=1; return;}

   xval = 0;
   x1 = odb1->sdba(NULL, NULL, dh, this, xval); if(xval>0) return;
   x2 = odb2->sdba(NULL, NULL, dh, this, xval); if(xval>0) return;

   n1 = UtilDate::nmonths(odb->end_d(), odb1->end_d());
   n2 = UtilDate::nmonths(odb->end_d(), odb2->end_d());

   if(n1==0) x = x1;
   else if(n2==0) x = x2;
   else x = x2;

   odb->add_sdba(this, x, xval);

   return;
}



#endif

