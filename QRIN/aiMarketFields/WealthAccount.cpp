// Name:     WealthAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_WealthAccount_cpp
#define ASX_WealthAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "WealthAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiMarketFields;

/** --------------Constructors and init_NULL-----------*/

WealthAccount::WealthAccount() { init_NULL(); }
WealthAccount::WealthAccount(const WealthAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
WealthAccount::WealthAccount(const WealthAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void WealthAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void WealthAccount::init() {
   PositionAccount::init();
	init_WealthAccount();
}

void WealthAccount::init_WealthAccount() {
   set_id("WealthAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

WealthAccount::~WealthAccount()	{ cleanMem(); }

void WealthAccount::cleanMem()	{
	cleanMem_WealthAccount();
   PositionAccount::cleanMem();
}

void WealthAccount::cleanMem_WealthAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string WealthAccount::className() const {return "WealthAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void WealthAccount::myerr_msg(string msg, string func) {
	err_msg("WealthAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void WealthAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_WealthAccount(fname);
}

void WealthAccount::fprint_WealthAccount(string fname) {
}

void WealthAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_WealthAccount(fname);
}

void WealthAccount::fscan_WealthAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void WealthAccount::reset() {
	reset_WealthAccount();
   PositionAccount::reset();
}

void WealthAccount::reset_WealthAccount() {
}

/** ----------  static instance function -----------*/


WealthAccount* WealthAccount::instance()	{
	WealthAccount* ptr = NULL;
   string id = "WealthAccount";

   ptr = (WealthAccount*) util_singleton("WealthAccount",id);
   if(ptr==NULL) {
      ptr = new WealthAccount();
      ptr->init();
      util_singleton("WealthAccount",id,ptr);
   }
	return ptr;
}

WealthAccount* WealthAccount::instance_fscan(string fname)	{
   return WealthAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

WealthAccount* WealthAccount::__ptr_WealthAccount = WealthAccount::instance();

/** Algorithm:
 *
 * 1. Find the closest date (d1a) to d1 in [d1-K,d1] for which Wealth attribute is available;
 * 2. Find the closest day to (d2a) d2 in [d2-K,d2] for which Wealth attribute is available
 * 3. Check suitability:
 *    - if d1a == NULL then xval = 1
 *    - if d2a == NULL then xval = 1
 *    - if d2a->isBefore(d1a) then xval = 1
 * 4. Compute cumret = w2a/w1a - 1
 * */
double WealthAccount::cumret(Object* dbobj, Db* db, UtilDate* d1, UtilDate* d2,
                             int& xval)
{
   const int K = WealthAccount_cumret_window;
   UtilDate* d1a = NULL;
   UtilDate* d2a = NULL;
   double w1a, w2a, val;

   val = 0;

   xval = 1; d1a = d1;
   for(int i=0;i<K && (xval>0);i++) {
      w1a = db->ddba(dbobj, d1a, d1a, this, xval);
      d1a = UtilDate::prev_d(d1a);
   }
   if(xval>0) return val;

   xval = 2; d2a = d2;
   for(int i=0;i<K && (xval>0);i++) {
      w2a = db->ddba(dbobj, d2a, d2a, this, xval);
      d2a = UtilDate::prev_d(d2a);
   }
   if(xval>0) return val;

   if(d2a->isBefore(d1a)) {xval=3; return val;}

   val = w2a/w1a - 1;

   return val;
}

#endif

