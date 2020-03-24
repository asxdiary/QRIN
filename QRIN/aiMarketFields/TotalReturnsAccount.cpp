// Name:     TotalReturnsAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_TotalReturnsAccount_cpp
#define ASX_TotalReturnsAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "ObjectDb.hpp"
#include "TotalReturnsAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiDbAccounts;
using namespace aiMarketFields;

/** --------------Constructors and init_NULL-----------*/

TotalReturnsAccount::TotalReturnsAccount() { init_NULL(); }
TotalReturnsAccount::TotalReturnsAccount(const TotalReturnsAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
TotalReturnsAccount::TotalReturnsAccount(const TotalReturnsAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void TotalReturnsAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void TotalReturnsAccount::init() {
   FlowAccount::init();
	init_TotalReturnsAccount();
}

void TotalReturnsAccount::init_TotalReturnsAccount() {
   set_id("TotalReturnsAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

TotalReturnsAccount::~TotalReturnsAccount()	{ cleanMem(); }

void TotalReturnsAccount::cleanMem()	{
	cleanMem_TotalReturnsAccount();
   FlowAccount::cleanMem();
}

void TotalReturnsAccount::cleanMem_TotalReturnsAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string TotalReturnsAccount::className() const {return "TotalReturnsAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void TotalReturnsAccount::myerr_msg(string msg, string func) {
	err_msg("TotalReturnsAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void TotalReturnsAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_TotalReturnsAccount(fname);
}

void TotalReturnsAccount::fprint_TotalReturnsAccount(string fname) {
}

void TotalReturnsAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_TotalReturnsAccount(fname);
}

void TotalReturnsAccount::fscan_TotalReturnsAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void TotalReturnsAccount::reset() {
	reset_TotalReturnsAccount();
   FlowAccount::reset();
}

void TotalReturnsAccount::reset_TotalReturnsAccount() {
}

/** ----------  static instance function -----------*/


TotalReturnsAccount* TotalReturnsAccount::instance()	{
	TotalReturnsAccount* ptr = NULL;
   string id = "TotalReturnsAccount";

   ptr = (TotalReturnsAccount*) util_singleton("TotalReturnsAccount",id);
   if(ptr==NULL) {
      ptr = new TotalReturnsAccount();
      ptr->init();
      util_singleton("TotalReturnsAccount",id,ptr);
   }
	return ptr;
}

TotalReturnsAccount* TotalReturnsAccount::instance_fscan(string fname)	{
   return TotalReturnsAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

TotalReturnsAccount* TotalReturnsAccount::__ptr_TotalReturnsAccount = TotalReturnsAccount::instance();

/** Currently, missing values are assumed to be equal to 0, and are admissible */
double TotalReturnsAccount::agg_guts(vector<ObjectDb*>* odbv, UtilDate* dh, int& xval) {
   double x;
   int n;

   xval = 0;
   x = 1; n = odbv->size();
   for(int i=0;i<n;i++) x *= (1 + odbv->at(i)->ddba(NULL, NULL, dh, this, xval));
   x -= 1; xval=0;
   return x;
}


#endif

