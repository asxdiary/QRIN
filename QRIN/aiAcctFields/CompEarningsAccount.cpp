// Name:     CompEarningsAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CompEarningsAccount_cpp
#define ASX_CompEarningsAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "CompEarningsAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

CompEarningsAccount::CompEarningsAccount() { init_NULL(); }
CompEarningsAccount::CompEarningsAccount(const CompEarningsAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
CompEarningsAccount::CompEarningsAccount(const CompEarningsAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void CompEarningsAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void CompEarningsAccount::init() {
   FlowAccount::init();
	init_CompEarningsAccount();
}

void CompEarningsAccount::init_CompEarningsAccount() {
   set_id("CompEarningsAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

CompEarningsAccount::~CompEarningsAccount()	{ cleanMem(); }

void CompEarningsAccount::cleanMem()	{
	cleanMem_CompEarningsAccount();
   FlowAccount::cleanMem();
}

void CompEarningsAccount::cleanMem_CompEarningsAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string CompEarningsAccount::className() const {return "CompEarningsAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void CompEarningsAccount::myerr_msg(string msg, string func) {
	err_msg("CompEarningsAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void CompEarningsAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_CompEarningsAccount(fname);
}

void CompEarningsAccount::fprint_CompEarningsAccount(string fname) {
}

void CompEarningsAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_CompEarningsAccount(fname);
}

void CompEarningsAccount::fscan_CompEarningsAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void CompEarningsAccount::reset() {
	reset_CompEarningsAccount();
   FlowAccount::reset();
}

void CompEarningsAccount::reset_CompEarningsAccount() {
}

/** ----------  static instance function -----------*/


CompEarningsAccount* CompEarningsAccount::instance()	{
	CompEarningsAccount* ptr = NULL;
   string id = "CompEarningsAccount";

   ptr = (CompEarningsAccount*) util_singleton("CompEarningsAccount",id);
   if(ptr==NULL) {
      ptr = new CompEarningsAccount();
      ptr->init();
      util_singleton("CompEarningsAccount",id,ptr);
   }
	return ptr;
}

CompEarningsAccount* CompEarningsAccount::instance_fscan(string fname)	{
   return CompEarningsAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

CompEarningsAccount* CompEarningsAccount::__ptr_CompEarningsAccount = CompEarningsAccount::instance();

#endif

