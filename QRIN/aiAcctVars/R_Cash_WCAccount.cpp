// Name:     R_Cash_WCAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_R_Cash_WCAccount_cpp
#define ASX_R_Cash_WCAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "R_DoubleDbAccount.hpp"
#include "CashShortTermInvestmentsAccount.hpp"
#include "WorkingCapitalAccount.hpp"
#include "R_Cash_WCAccount.hpp"
#include "OperatingRevenueAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctFields;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

R_Cash_WCAccount::R_Cash_WCAccount() { init_NULL(); }
R_Cash_WCAccount::R_Cash_WCAccount(const R_Cash_WCAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
R_Cash_WCAccount::R_Cash_WCAccount(const R_Cash_WCAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void R_Cash_WCAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void R_Cash_WCAccount::init() {
   R_DoubleDbAccount::init(CashShortTermInvestmentsAccount::instance(),
                           WorkingCapitalAccount::instance(),
                           false, false);
   init_R_Cash_WCAccount();
}

void R_Cash_WCAccount::init_R_Cash_WCAccount() {
   set_id("R_Cash_WCAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

R_Cash_WCAccount::~R_Cash_WCAccount()	{ cleanMem(); }

void R_Cash_WCAccount::cleanMem()	{
	cleanMem_R_Cash_WCAccount();
   R_DoubleDbAccount::cleanMem();
}

void R_Cash_WCAccount::cleanMem_R_Cash_WCAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string R_Cash_WCAccount::className() const {return "R_Cash_WCAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void R_Cash_WCAccount::myerr_msg(string msg, string func) {
	err_msg("R_Cash_WCAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void R_Cash_WCAccount::fprint(string fname) {
   R_DoubleDbAccount::fprint(fname);
	fprint_R_Cash_WCAccount(fname);
}

void R_Cash_WCAccount::fprint_R_Cash_WCAccount(string fname) {
}

void R_Cash_WCAccount::fscan(string fname) {
   R_DoubleDbAccount::fscan(fname);
	fscan_R_Cash_WCAccount(fname);
}

void R_Cash_WCAccount::fscan_R_Cash_WCAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void R_Cash_WCAccount::reset() {
	reset_R_Cash_WCAccount();
   R_DoubleDbAccount::reset();
}

void R_Cash_WCAccount::reset_R_Cash_WCAccount() {
}

/** ----------  static instance function -----------*/


R_Cash_WCAccount* R_Cash_WCAccount::instance()	{
	R_Cash_WCAccount* ptr = NULL;
   string id = "R_Cash_WCAccount";

   ptr = (R_Cash_WCAccount*) util_singleton("R_Cash_WCAccount",id);
   if(ptr==NULL) {
      ptr = new R_Cash_WCAccount();
      ptr->init();
      util_singleton("R_Cash_WCAccount",id,ptr);
   }
	return ptr;
}

R_Cash_WCAccount* R_Cash_WCAccount::instance_fscan(string fname)	{
   return R_Cash_WCAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

R_Cash_WCAccount* R_Cash_WCAccount::__ptr_R_Cash_WCAccount = R_Cash_WCAccount::instance();

#endif

