// Name:     PayablesTOAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_PayablesTOAccount_cpp
#define ASX_PayablesTOAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "R_DoubleDbAccount.hpp"
#include "CostRevenueAccount.hpp"
#include "AccountsPayableAccount.hpp"
#include "PayablesTOAccount.hpp"
#include "CostRevenueAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctFields;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

PayablesTOAccount::PayablesTOAccount() { init_NULL(); }
PayablesTOAccount::PayablesTOAccount(const PayablesTOAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
PayablesTOAccount::PayablesTOAccount(const PayablesTOAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void PayablesTOAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void PayablesTOAccount::init() {
   R_DoubleDbAccount::init(CostRevenueAccount::instance(),
                           AccountsPayableAccount::instance(),
                           true, false);
   init_PayablesTOAccount();
}

void PayablesTOAccount::init_PayablesTOAccount() {
   set_id("PayablesTOAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

PayablesTOAccount::~PayablesTOAccount()	{ cleanMem(); }

void PayablesTOAccount::cleanMem()	{
	cleanMem_PayablesTOAccount();
   R_DoubleDbAccount::cleanMem();
}

void PayablesTOAccount::cleanMem_PayablesTOAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string PayablesTOAccount::className() const {return "PayablesTOAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void PayablesTOAccount::myerr_msg(string msg, string func) {
	err_msg("PayablesTOAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void PayablesTOAccount::fprint(string fname) {
   R_DoubleDbAccount::fprint(fname);
	fprint_PayablesTOAccount(fname);
}

void PayablesTOAccount::fprint_PayablesTOAccount(string fname) {
}

void PayablesTOAccount::fscan(string fname) {
   R_DoubleDbAccount::fscan(fname);
	fscan_PayablesTOAccount(fname);
}

void PayablesTOAccount::fscan_PayablesTOAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void PayablesTOAccount::reset() {
	reset_PayablesTOAccount();
   R_DoubleDbAccount::reset();
}

void PayablesTOAccount::reset_PayablesTOAccount() {
}

/** ----------  static instance function -----------*/


PayablesTOAccount* PayablesTOAccount::instance()	{
	PayablesTOAccount* ptr = NULL;
   string id = "PayablesTOAccount";

   ptr = (PayablesTOAccount*) util_singleton("PayablesTOAccount",id);
   if(ptr==NULL) {
      ptr = new PayablesTOAccount();
      ptr->init();
      util_singleton("PayablesTOAccount",id,ptr);
   }
	return ptr;
}

PayablesTOAccount* PayablesTOAccount::instance_fscan(string fname)	{
   return PayablesTOAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

PayablesTOAccount* PayablesTOAccount::__ptr_PayablesTOAccount = PayablesTOAccount::instance();

#endif

