// Name:     IncomeBeforeIncomeTaxesAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_IncomeBeforeIncomeTaxesAccount_cpp
#define ASX_IncomeBeforeIncomeTaxesAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "IncomeBeforeIncomeTaxesAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

IncomeBeforeIncomeTaxesAccount::IncomeBeforeIncomeTaxesAccount() { init_NULL(); }
IncomeBeforeIncomeTaxesAccount::IncomeBeforeIncomeTaxesAccount(const IncomeBeforeIncomeTaxesAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
IncomeBeforeIncomeTaxesAccount::IncomeBeforeIncomeTaxesAccount(const IncomeBeforeIncomeTaxesAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void IncomeBeforeIncomeTaxesAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void IncomeBeforeIncomeTaxesAccount::init() {
   FlowAccount::init();
	init_IncomeBeforeIncomeTaxesAccount();
}

void IncomeBeforeIncomeTaxesAccount::init_IncomeBeforeIncomeTaxesAccount() {
   set_id("IncomeBeforeIncomeTaxesAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

IncomeBeforeIncomeTaxesAccount::~IncomeBeforeIncomeTaxesAccount()	{ cleanMem(); }

void IncomeBeforeIncomeTaxesAccount::cleanMem()	{
	cleanMem_IncomeBeforeIncomeTaxesAccount();
   FlowAccount::cleanMem();
}

void IncomeBeforeIncomeTaxesAccount::cleanMem_IncomeBeforeIncomeTaxesAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string IncomeBeforeIncomeTaxesAccount::className() const {return "IncomeBeforeIncomeTaxesAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void IncomeBeforeIncomeTaxesAccount::myerr_msg(string msg, string func) {
	err_msg("IncomeBeforeIncomeTaxesAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void IncomeBeforeIncomeTaxesAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_IncomeBeforeIncomeTaxesAccount(fname);
}

void IncomeBeforeIncomeTaxesAccount::fprint_IncomeBeforeIncomeTaxesAccount(string fname) {
}

void IncomeBeforeIncomeTaxesAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_IncomeBeforeIncomeTaxesAccount(fname);
}

void IncomeBeforeIncomeTaxesAccount::fscan_IncomeBeforeIncomeTaxesAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void IncomeBeforeIncomeTaxesAccount::reset() {
	reset_IncomeBeforeIncomeTaxesAccount();
   FlowAccount::reset();
}

void IncomeBeforeIncomeTaxesAccount::reset_IncomeBeforeIncomeTaxesAccount() {
}

/** ----------  static instance function -----------*/


IncomeBeforeIncomeTaxesAccount* IncomeBeforeIncomeTaxesAccount::instance()	{
	IncomeBeforeIncomeTaxesAccount* ptr = NULL;
   string id = "IncomeBeforeIncomeTaxesAccount";

   ptr = (IncomeBeforeIncomeTaxesAccount*) util_singleton("IncomeBeforeIncomeTaxesAccount",id);
   if(ptr==NULL) {
      ptr = new IncomeBeforeIncomeTaxesAccount();
      ptr->init();
      util_singleton("IncomeBeforeIncomeTaxesAccount",id,ptr);
   }
	return ptr;
}

IncomeBeforeIncomeTaxesAccount* IncomeBeforeIncomeTaxesAccount::instance_fscan(string fname)	{
   return IncomeBeforeIncomeTaxesAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

IncomeBeforeIncomeTaxesAccount* IncomeBeforeIncomeTaxesAccount::__ptr_IncomeBeforeIncomeTaxesAccount = IncomeBeforeIncomeTaxesAccount::instance();

#endif

