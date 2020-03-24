// Name:     NonContinuingOperationsItemsAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_NonContinuingOperationsItemsAccount_cpp
#define ASX_NonContinuingOperationsItemsAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "NonContinuingOperationsItemsAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

NonContinuingOperationsItemsAccount::NonContinuingOperationsItemsAccount() { init_NULL(); }
NonContinuingOperationsItemsAccount::NonContinuingOperationsItemsAccount(const NonContinuingOperationsItemsAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
NonContinuingOperationsItemsAccount::NonContinuingOperationsItemsAccount(const NonContinuingOperationsItemsAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void NonContinuingOperationsItemsAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void NonContinuingOperationsItemsAccount::init() {
   FlowAccount::init();
	init_NonContinuingOperationsItemsAccount();
}

void NonContinuingOperationsItemsAccount::init_NonContinuingOperationsItemsAccount() {
   set_id("NonContinuingOperationsItemsAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

NonContinuingOperationsItemsAccount::~NonContinuingOperationsItemsAccount()	{ cleanMem(); }

void NonContinuingOperationsItemsAccount::cleanMem()	{
	cleanMem_NonContinuingOperationsItemsAccount();
   FlowAccount::cleanMem();
}

void NonContinuingOperationsItemsAccount::cleanMem_NonContinuingOperationsItemsAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string NonContinuingOperationsItemsAccount::className() const {return "NonContinuingOperationsItemsAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void NonContinuingOperationsItemsAccount::myerr_msg(string msg, string func) {
	err_msg("NonContinuingOperationsItemsAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void NonContinuingOperationsItemsAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_NonContinuingOperationsItemsAccount(fname);
}

void NonContinuingOperationsItemsAccount::fprint_NonContinuingOperationsItemsAccount(string fname) {
}

void NonContinuingOperationsItemsAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_NonContinuingOperationsItemsAccount(fname);
}

void NonContinuingOperationsItemsAccount::fscan_NonContinuingOperationsItemsAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void NonContinuingOperationsItemsAccount::reset() {
	reset_NonContinuingOperationsItemsAccount();
   FlowAccount::reset();
}

void NonContinuingOperationsItemsAccount::reset_NonContinuingOperationsItemsAccount() {
}

/** ----------  static instance function -----------*/


NonContinuingOperationsItemsAccount* NonContinuingOperationsItemsAccount::instance()	{
	NonContinuingOperationsItemsAccount* ptr = NULL;
   string id = "NonContinuingOperationsItemsAccount";

   ptr = (NonContinuingOperationsItemsAccount*) util_singleton("NonContinuingOperationsItemsAccount",id);
   if(ptr==NULL) {
      ptr = new NonContinuingOperationsItemsAccount();
      ptr->init();
      util_singleton("NonContinuingOperationsItemsAccount",id,ptr);
   }
	return ptr;
}

NonContinuingOperationsItemsAccount* NonContinuingOperationsItemsAccount::instance_fscan(string fname)	{
   return NonContinuingOperationsItemsAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

NonContinuingOperationsItemsAccount* NonContinuingOperationsItemsAccount::__ptr_NonContinuingOperationsItemsAccount = NonContinuingOperationsItemsAccount::instance();

#endif

