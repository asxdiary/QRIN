// Name:     OperatingMarginAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_OperatingMarginAccount_cpp
#define ASX_OperatingMarginAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "R_DoubleDbAccount.hpp"
#include "OperatingProfitAccount.hpp"
#include "OperatingRevenueAccount.hpp"
#include "OperatingMarginAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctFields;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

OperatingMarginAccount::OperatingMarginAccount() { init_NULL(); }
OperatingMarginAccount::OperatingMarginAccount(const OperatingMarginAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
OperatingMarginAccount::OperatingMarginAccount(const OperatingMarginAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void OperatingMarginAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void OperatingMarginAccount::init() {
   R_DoubleDbAccount::init(OperatingProfitAccount::instance(),
                      OperatingRevenueAccount::instance(),
                      false, false);
	init_OperatingMarginAccount();
}

void OperatingMarginAccount::init_OperatingMarginAccount() {
   set_id("OperatingMarginAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

OperatingMarginAccount::~OperatingMarginAccount()	{ cleanMem(); }

void OperatingMarginAccount::cleanMem()	{
	cleanMem_OperatingMarginAccount();
   R_DoubleDbAccount::cleanMem();
}

void OperatingMarginAccount::cleanMem_OperatingMarginAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string OperatingMarginAccount::className() const {return "OperatingMarginAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void OperatingMarginAccount::myerr_msg(string msg, string func) {
	err_msg("OperatingMarginAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void OperatingMarginAccount::fprint(string fname) {
   R_DoubleDbAccount::fprint(fname);
	fprint_OperatingMarginAccount(fname);
}

void OperatingMarginAccount::fprint_OperatingMarginAccount(string fname) {
}

void OperatingMarginAccount::fscan(string fname) {
   R_DoubleDbAccount::fscan(fname);
	fscan_OperatingMarginAccount(fname);
}

void OperatingMarginAccount::fscan_OperatingMarginAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void OperatingMarginAccount::reset() {
	reset_OperatingMarginAccount();
   R_DoubleDbAccount::reset();
}

void OperatingMarginAccount::reset_OperatingMarginAccount() {
}

/** ----------  static instance function -----------*/


OperatingMarginAccount* OperatingMarginAccount::instance()	{
	OperatingMarginAccount* ptr = NULL;
   string id = "OperatingMarginAccount";

   ptr = (OperatingMarginAccount*) util_singleton("OperatingMarginAccount",id);
   if(ptr==NULL) {
      ptr = new OperatingMarginAccount();
      ptr->init();
      util_singleton("OperatingMarginAccount",id,ptr);
   }
	return ptr;
}

OperatingMarginAccount* OperatingMarginAccount::instance_fscan(string fname)	{
   return OperatingMarginAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

OperatingMarginAccount* OperatingMarginAccount::__ptr_OperatingMarginAccount = OperatingMarginAccount::instance();

#endif

