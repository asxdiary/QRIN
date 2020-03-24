// Name:     StartDateAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_StartDateAccount_cpp
#define ASX_StartDateAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DateAccount.hpp"
#include "StartDateAccount.hpp"
#include "ObjectDb.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiDbAccounts;

/** --------------Constructors and init_NULL-----------*/

StartDateAccount::StartDateAccount() { init_NULL(); }
StartDateAccount::StartDateAccount(const StartDateAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
StartDateAccount::StartDateAccount(const StartDateAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void StartDateAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void StartDateAccount::init() {
   DateAccount::init();
	init_StartDateAccount();
}

void StartDateAccount::init_StartDateAccount() {
   set_id("StartDateAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

StartDateAccount::~StartDateAccount()	{ cleanMem(); }

void StartDateAccount::cleanMem()	{
	cleanMem_StartDateAccount();
   DateAccount::cleanMem();
}

void StartDateAccount::cleanMem_StartDateAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string StartDateAccount::className() const {return "StartDateAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void StartDateAccount::myerr_msg(string msg, string func) {
	err_msg("StartDateAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void StartDateAccount::fprint(string fname) {
   DateAccount::fprint(fname);
	fprint_StartDateAccount(fname);
}

void StartDateAccount::fprint_StartDateAccount(string fname) {
}

void StartDateAccount::fscan(string fname) {
   DateAccount::fscan(fname);
	fscan_StartDateAccount(fname);
}

void StartDateAccount::fscan_StartDateAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void StartDateAccount::reset() {
	reset_StartDateAccount();
   DateAccount::reset();
}

void StartDateAccount::reset_StartDateAccount() {
}

/** ----------  static instance function -----------*/


StartDateAccount* StartDateAccount::instance()	{
	StartDateAccount* ptr = NULL;
   string id = "StartDateAccount";

   ptr = (StartDateAccount*) util_singleton("StartDateAccount",id);
   if(ptr==NULL) {
      ptr = new StartDateAccount();
      ptr->init();
      util_singleton("StartDateAccount",id,ptr);
   }
	return ptr;
}

StartDateAccount* StartDateAccount::instance_fscan(string fname)	{
   return StartDateAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

StartDateAccount* StartDateAccount::__ptr_StartDateAccount = StartDateAccount::instance();

/** Algorithm:
 * 1. Use the dba account for the first odb */
double StartDateAccount::agg_guts(vector<ObjectDb*>* odbv, UtilDate* dh, int& xval) {
   ObjectDb* lodb = NULL;
   double x;

   xval = 0;
   lodb = odbv->front();
   x = lodb->ddba(NULL, NULL, dh, this, xval);

   return x;
}

void StartDateAccount::agg(ObjectDb* odb, vector<ObjectDb*>* odbv, UtilDate* dh, int& xval) {
   UtilDate* d = odb->start_d();
   DateAccount::agg(odb, odbv, dh, xval);
   if(xval==0 && odb->start_d()!=d) myerr_msg("agg function failed",__FUNCTION__);
   return;
}

#endif

