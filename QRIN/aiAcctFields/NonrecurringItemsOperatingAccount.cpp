// Name:     NonrecurringItemsOperatingAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_NonrecurringItemsOperatingAccount_cpp
#define ASX_NonrecurringItemsOperatingAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "NonrecurringItemsOperatingAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

NonrecurringItemsOperatingAccount::NonrecurringItemsOperatingAccount() { init_NULL(); }
NonrecurringItemsOperatingAccount::NonrecurringItemsOperatingAccount(const NonrecurringItemsOperatingAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
NonrecurringItemsOperatingAccount::NonrecurringItemsOperatingAccount(const NonrecurringItemsOperatingAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void NonrecurringItemsOperatingAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void NonrecurringItemsOperatingAccount::init() {
   FlowAccount::init();
	init_NonrecurringItemsOperatingAccount();
}

void NonrecurringItemsOperatingAccount::init_NonrecurringItemsOperatingAccount() {
   set_id("NonrecurringItemsOperatingAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

NonrecurringItemsOperatingAccount::~NonrecurringItemsOperatingAccount()	{ cleanMem(); }

void NonrecurringItemsOperatingAccount::cleanMem()	{
	cleanMem_NonrecurringItemsOperatingAccount();
   FlowAccount::cleanMem();
}

void NonrecurringItemsOperatingAccount::cleanMem_NonrecurringItemsOperatingAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string NonrecurringItemsOperatingAccount::className() const {return "NonrecurringItemsOperatingAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void NonrecurringItemsOperatingAccount::myerr_msg(string msg, string func) {
	err_msg("NonrecurringItemsOperatingAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void NonrecurringItemsOperatingAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_NonrecurringItemsOperatingAccount(fname);
}

void NonrecurringItemsOperatingAccount::fprint_NonrecurringItemsOperatingAccount(string fname) {
}

void NonrecurringItemsOperatingAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_NonrecurringItemsOperatingAccount(fname);
}

void NonrecurringItemsOperatingAccount::fscan_NonrecurringItemsOperatingAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void NonrecurringItemsOperatingAccount::reset() {
	reset_NonrecurringItemsOperatingAccount();
   FlowAccount::reset();
}

void NonrecurringItemsOperatingAccount::reset_NonrecurringItemsOperatingAccount() {
}

/** ----------  static instance function -----------*/


NonrecurringItemsOperatingAccount* NonrecurringItemsOperatingAccount::instance()	{
	NonrecurringItemsOperatingAccount* ptr = NULL;
   string id = "NonrecurringItemsOperatingAccount";

   ptr = (NonrecurringItemsOperatingAccount*) util_singleton("NonrecurringItemsOperatingAccount",id);
   if(ptr==NULL) {
      ptr = new NonrecurringItemsOperatingAccount();
      ptr->init();
      util_singleton("NonrecurringItemsOperatingAccount",id,ptr);
   }
	return ptr;
}

NonrecurringItemsOperatingAccount* NonrecurringItemsOperatingAccount::instance_fscan(string fname)	{
   return NonrecurringItemsOperatingAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

NonrecurringItemsOperatingAccount* NonrecurringItemsOperatingAccount::__ptr_NonrecurringItemsOperatingAccount = NonrecurringItemsOperatingAccount::instance();

#endif

