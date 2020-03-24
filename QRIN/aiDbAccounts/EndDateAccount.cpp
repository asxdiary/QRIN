// Name:     EndDateAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_EndDateAccount_cpp
#define ASX_EndDateAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DateAccount.hpp"
#include "EndDateAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiDbAccounts;

/** --------------Constructors and init_NULL-----------*/

EndDateAccount::EndDateAccount() { init_NULL(); }
EndDateAccount::EndDateAccount(const EndDateAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
EndDateAccount::EndDateAccount(const EndDateAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void EndDateAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void EndDateAccount::init() {
   DateAccount::init();
	init_EndDateAccount();
}

void EndDateAccount::init_EndDateAccount() {
   set_id("EndDateAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

EndDateAccount::~EndDateAccount()	{ cleanMem(); }

void EndDateAccount::cleanMem()	{
	cleanMem_EndDateAccount();
   DateAccount::cleanMem();
}

void EndDateAccount::cleanMem_EndDateAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string EndDateAccount::className() const {return "EndDateAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void EndDateAccount::myerr_msg(string msg, string func) {
	err_msg("EndDateAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void EndDateAccount::fprint(string fname) {
   DateAccount::fprint(fname);
	fprint_EndDateAccount(fname);
}

void EndDateAccount::fprint_EndDateAccount(string fname) {
}

void EndDateAccount::fscan(string fname) {
   DateAccount::fscan(fname);
	fscan_EndDateAccount(fname);
}

void EndDateAccount::fscan_EndDateAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void EndDateAccount::reset() {
	reset_EndDateAccount();
   DateAccount::reset();
}

void EndDateAccount::reset_EndDateAccount() {
}

/** ----------  static instance function -----------*/


EndDateAccount* EndDateAccount::instance()	{
	EndDateAccount* ptr = NULL;
   string id = "EndDateAccount";

   ptr = (EndDateAccount*) util_singleton("EndDateAccount",id);
   if(ptr==NULL) {
      ptr = new EndDateAccount();
      ptr->init();
      util_singleton("EndDateAccount",id,ptr);
   }
	return ptr;
}

EndDateAccount* EndDateAccount::instance_fscan(string fname)	{
   return EndDateAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

EndDateAccount* EndDateAccount::__ptr_EndDateAccount = EndDateAccount::instance();

/** Algorithm:
 * 1. Use the dba account for the last odb */
double EndDateAccount::agg_guts(vector<ObjectDb*>* odbv, UtilDate* dh, int& xval) {
   ObjectDb* lodb = NULL;
   double x;

   xval = 0;
   lodb = odbv->back();
   x = lodb->ddba(NULL, NULL, dh, this, xval);

   return x;
}

void EndDateAccount::agg(ObjectDb* odb, vector<ObjectDb*>* odbv, UtilDate* dh, int& xval) {
   UtilDate* d = odb->end_d();
   DateAccount::agg(odb, odbv, dh, xval);
   if(xval==0 && odb->end_d()!=d) myerr_msg("agg function failed",__FUNCTION__);
   return;
}

#endif

