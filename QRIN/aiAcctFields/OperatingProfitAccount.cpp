// Name:     OperatingProfitAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_OperatingProfitAccount_cpp
#define ASX_OperatingProfitAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "OperatingProfitAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

OperatingProfitAccount::OperatingProfitAccount() { init_NULL(); }
OperatingProfitAccount::OperatingProfitAccount(const OperatingProfitAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
OperatingProfitAccount::OperatingProfitAccount(const OperatingProfitAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void OperatingProfitAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void OperatingProfitAccount::init() {
   FlowAccount::init();
	init_OperatingProfitAccount();
}

void OperatingProfitAccount::init_OperatingProfitAccount() {
   set_id("OperatingProfitAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

OperatingProfitAccount::~OperatingProfitAccount()	{ cleanMem(); }

void OperatingProfitAccount::cleanMem()	{
	cleanMem_OperatingProfitAccount();
   FlowAccount::cleanMem();
}

void OperatingProfitAccount::cleanMem_OperatingProfitAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string OperatingProfitAccount::className() const {return "OperatingProfitAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void OperatingProfitAccount::myerr_msg(string msg, string func) {
	err_msg("OperatingProfitAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void OperatingProfitAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_OperatingProfitAccount(fname);
}

void OperatingProfitAccount::fprint_OperatingProfitAccount(string fname) {
}

void OperatingProfitAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_OperatingProfitAccount(fname);
}

void OperatingProfitAccount::fscan_OperatingProfitAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void OperatingProfitAccount::reset() {
	reset_OperatingProfitAccount();
   FlowAccount::reset();
}

void OperatingProfitAccount::reset_OperatingProfitAccount() {
}

/** ----------  static instance function -----------*/


OperatingProfitAccount* OperatingProfitAccount::instance()	{
	OperatingProfitAccount* ptr = NULL;
   string id = "OperatingProfitAccount";

   ptr = (OperatingProfitAccount*) util_singleton("OperatingProfitAccount",id);
   if(ptr==NULL) {
      ptr = new OperatingProfitAccount();
      ptr->init();
      util_singleton("OperatingProfitAccount",id,ptr);
   }
	return ptr;
}

OperatingProfitAccount* OperatingProfitAccount::instance_fscan(string fname)	{
   return OperatingProfitAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

OperatingProfitAccount* OperatingProfitAccount::__ptr_OperatingProfitAccount = OperatingProfitAccount::instance();

#endif

