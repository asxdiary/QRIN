// Name:     NonOperatingIncomeExpenseAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_NonOperatingIncomeExpenseAccount_cpp
#define ASX_NonOperatingIncomeExpenseAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "NonOperatingIncomeExpenseAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

NonOperatingIncomeExpenseAccount::NonOperatingIncomeExpenseAccount() { init_NULL(); }
NonOperatingIncomeExpenseAccount::NonOperatingIncomeExpenseAccount(const NonOperatingIncomeExpenseAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
NonOperatingIncomeExpenseAccount::NonOperatingIncomeExpenseAccount(const NonOperatingIncomeExpenseAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void NonOperatingIncomeExpenseAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void NonOperatingIncomeExpenseAccount::init() {
   FlowAccount::init();
	init_NonOperatingIncomeExpenseAccount();
}

void NonOperatingIncomeExpenseAccount::init_NonOperatingIncomeExpenseAccount() {
   set_id("NonOperatingIncomeExpenseAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

NonOperatingIncomeExpenseAccount::~NonOperatingIncomeExpenseAccount()	{ cleanMem(); }

void NonOperatingIncomeExpenseAccount::cleanMem()	{
	cleanMem_NonOperatingIncomeExpenseAccount();
   FlowAccount::cleanMem();
}

void NonOperatingIncomeExpenseAccount::cleanMem_NonOperatingIncomeExpenseAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string NonOperatingIncomeExpenseAccount::className() const {return "NonOperatingIncomeExpenseAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void NonOperatingIncomeExpenseAccount::myerr_msg(string msg, string func) {
	err_msg("NonOperatingIncomeExpenseAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void NonOperatingIncomeExpenseAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_NonOperatingIncomeExpenseAccount(fname);
}

void NonOperatingIncomeExpenseAccount::fprint_NonOperatingIncomeExpenseAccount(string fname) {
}

void NonOperatingIncomeExpenseAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_NonOperatingIncomeExpenseAccount(fname);
}

void NonOperatingIncomeExpenseAccount::fscan_NonOperatingIncomeExpenseAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void NonOperatingIncomeExpenseAccount::reset() {
	reset_NonOperatingIncomeExpenseAccount();
   FlowAccount::reset();
}

void NonOperatingIncomeExpenseAccount::reset_NonOperatingIncomeExpenseAccount() {
}

/** ----------  static instance function -----------*/


NonOperatingIncomeExpenseAccount* NonOperatingIncomeExpenseAccount::instance()	{
	NonOperatingIncomeExpenseAccount* ptr = NULL;
   string id = "NonOperatingIncomeExpenseAccount";

   ptr = (NonOperatingIncomeExpenseAccount*) util_singleton("NonOperatingIncomeExpenseAccount",id);
   if(ptr==NULL) {
      ptr = new NonOperatingIncomeExpenseAccount();
      ptr->init();
      util_singleton("NonOperatingIncomeExpenseAccount",id,ptr);
   }
	return ptr;
}

NonOperatingIncomeExpenseAccount* NonOperatingIncomeExpenseAccount::instance_fscan(string fname)	{
   return NonOperatingIncomeExpenseAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

NonOperatingIncomeExpenseAccount* NonOperatingIncomeExpenseAccount::__ptr_NonOperatingIncomeExpenseAccount = NonOperatingIncomeExpenseAccount::instance();

#endif

