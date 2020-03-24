// Name:     OperatingRevenueAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_OperatingRevenueAccount_cpp
#define ASX_OperatingRevenueAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "OperatingRevenueAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

OperatingRevenueAccount::OperatingRevenueAccount() { init_NULL(); }
OperatingRevenueAccount::OperatingRevenueAccount(const OperatingRevenueAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
OperatingRevenueAccount::OperatingRevenueAccount(const OperatingRevenueAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void OperatingRevenueAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void OperatingRevenueAccount::init() {
   FlowAccount::init();
	init_OperatingRevenueAccount();
}

void OperatingRevenueAccount::init_OperatingRevenueAccount() {
   set_id("OperatingRevenueAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

OperatingRevenueAccount::~OperatingRevenueAccount()	{ cleanMem(); }

void OperatingRevenueAccount::cleanMem()	{
	cleanMem_OperatingRevenueAccount();
   FlowAccount::cleanMem();
}

void OperatingRevenueAccount::cleanMem_OperatingRevenueAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string OperatingRevenueAccount::className() const {return "OperatingRevenueAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void OperatingRevenueAccount::myerr_msg(string msg, string func) {
	err_msg("OperatingRevenueAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void OperatingRevenueAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_OperatingRevenueAccount(fname);
}

void OperatingRevenueAccount::fprint_OperatingRevenueAccount(string fname) {
}

void OperatingRevenueAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_OperatingRevenueAccount(fname);
}

void OperatingRevenueAccount::fscan_OperatingRevenueAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void OperatingRevenueAccount::reset() {
	reset_OperatingRevenueAccount();
   FlowAccount::reset();
}

void OperatingRevenueAccount::reset_OperatingRevenueAccount() {
}

/** ----------  static instance function -----------*/


OperatingRevenueAccount* OperatingRevenueAccount::instance()	{
	OperatingRevenueAccount* ptr = NULL;
   string id = "OperatingRevenueAccount";

   ptr = (OperatingRevenueAccount*) util_singleton("OperatingRevenueAccount",id);
   if(ptr==NULL) {
      ptr = new OperatingRevenueAccount();
      ptr->init();
      util_singleton("OperatingRevenueAccount",id,ptr);
   }
	return ptr;
}

OperatingRevenueAccount* OperatingRevenueAccount::instance_fscan(string fname)	{
   return OperatingRevenueAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

OperatingRevenueAccount* OperatingRevenueAccount::__ptr_OperatingRevenueAccount = OperatingRevenueAccount::instance();

#endif

