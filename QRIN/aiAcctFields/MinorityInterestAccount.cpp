// Name:     MinorityInterestAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_MinorityInterestAccount_cpp
#define ASX_MinorityInterestAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "MinorityInterestAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

MinorityInterestAccount::MinorityInterestAccount() { init_NULL(); }
MinorityInterestAccount::MinorityInterestAccount(const MinorityInterestAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
MinorityInterestAccount::MinorityInterestAccount(const MinorityInterestAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void MinorityInterestAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void MinorityInterestAccount::init() {
   PositionAccount::init();
	init_MinorityInterestAccount();
}

void MinorityInterestAccount::init_MinorityInterestAccount() {
   set_id("MinorityInterestAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

MinorityInterestAccount::~MinorityInterestAccount()	{ cleanMem(); }

void MinorityInterestAccount::cleanMem()	{
	cleanMem_MinorityInterestAccount();
   PositionAccount::cleanMem();
}

void MinorityInterestAccount::cleanMem_MinorityInterestAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string MinorityInterestAccount::className() const {return "MinorityInterestAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void MinorityInterestAccount::myerr_msg(string msg, string func) {
	err_msg("MinorityInterestAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void MinorityInterestAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_MinorityInterestAccount(fname);
}

void MinorityInterestAccount::fprint_MinorityInterestAccount(string fname) {
}

void MinorityInterestAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_MinorityInterestAccount(fname);
}

void MinorityInterestAccount::fscan_MinorityInterestAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void MinorityInterestAccount::reset() {
	reset_MinorityInterestAccount();
   PositionAccount::reset();
}

void MinorityInterestAccount::reset_MinorityInterestAccount() {
}

/** ----------  static instance function -----------*/


MinorityInterestAccount* MinorityInterestAccount::instance()	{
	MinorityInterestAccount* ptr = NULL;
   string id = "MinorityInterestAccount";

   ptr = (MinorityInterestAccount*) util_singleton("MinorityInterestAccount",id);
   if(ptr==NULL) {
      ptr = new MinorityInterestAccount();
      ptr->init();
      util_singleton("MinorityInterestAccount",id,ptr);
   }
	return ptr;
}

MinorityInterestAccount* MinorityInterestAccount::instance_fscan(string fname)	{
   return MinorityInterestAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

MinorityInterestAccount* MinorityInterestAccount::__ptr_MinorityInterestAccount = MinorityInterestAccount::instance();

#endif

