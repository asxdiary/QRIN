// Name:     DeferredPrepaidExpensesAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DeferredPrepaidExpensesAccount_cpp
#define ASX_DeferredPrepaidExpensesAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "DeferredPrepaidExpensesAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

DeferredPrepaidExpensesAccount::DeferredPrepaidExpensesAccount() { init_NULL(); }
DeferredPrepaidExpensesAccount::DeferredPrepaidExpensesAccount(const DeferredPrepaidExpensesAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
DeferredPrepaidExpensesAccount::DeferredPrepaidExpensesAccount(const DeferredPrepaidExpensesAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void DeferredPrepaidExpensesAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void DeferredPrepaidExpensesAccount::init() {
   PositionAccount::init();
	init_DeferredPrepaidExpensesAccount();
}

void DeferredPrepaidExpensesAccount::init_DeferredPrepaidExpensesAccount() {
   set_id("DeferredPrepaidExpensesAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

DeferredPrepaidExpensesAccount::~DeferredPrepaidExpensesAccount()	{ cleanMem(); }

void DeferredPrepaidExpensesAccount::cleanMem()	{
	cleanMem_DeferredPrepaidExpensesAccount();
   PositionAccount::cleanMem();
}

void DeferredPrepaidExpensesAccount::cleanMem_DeferredPrepaidExpensesAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string DeferredPrepaidExpensesAccount::className() const {return "DeferredPrepaidExpensesAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void DeferredPrepaidExpensesAccount::myerr_msg(string msg, string func) {
	err_msg("DeferredPrepaidExpensesAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void DeferredPrepaidExpensesAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_DeferredPrepaidExpensesAccount(fname);
}

void DeferredPrepaidExpensesAccount::fprint_DeferredPrepaidExpensesAccount(string fname) {
}

void DeferredPrepaidExpensesAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_DeferredPrepaidExpensesAccount(fname);
}

void DeferredPrepaidExpensesAccount::fscan_DeferredPrepaidExpensesAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void DeferredPrepaidExpensesAccount::reset() {
	reset_DeferredPrepaidExpensesAccount();
   PositionAccount::reset();
}

void DeferredPrepaidExpensesAccount::reset_DeferredPrepaidExpensesAccount() {
}

/** ----------  static instance function -----------*/


DeferredPrepaidExpensesAccount* DeferredPrepaidExpensesAccount::instance()	{
	DeferredPrepaidExpensesAccount* ptr = NULL;
   string id = "DeferredPrepaidExpensesAccount";

   ptr = (DeferredPrepaidExpensesAccount*) util_singleton("DeferredPrepaidExpensesAccount",id);
   if(ptr==NULL) {
      ptr = new DeferredPrepaidExpensesAccount();
      ptr->init();
      util_singleton("DeferredPrepaidExpensesAccount",id,ptr);
   }
	return ptr;
}

DeferredPrepaidExpensesAccount* DeferredPrepaidExpensesAccount::instance_fscan(string fname)	{
   return DeferredPrepaidExpensesAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

DeferredPrepaidExpensesAccount* DeferredPrepaidExpensesAccount::__ptr_DeferredPrepaidExpensesAccount = DeferredPrepaidExpensesAccount::instance();

#endif

