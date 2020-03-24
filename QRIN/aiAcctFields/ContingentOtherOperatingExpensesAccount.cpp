// Name:     ContingentOtherOperatingExpensesAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ContingentOtherOperatingExpensesAccount_cpp
#define ASX_ContingentOtherOperatingExpensesAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "ContingentOtherOperatingExpensesAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

ContingentOtherOperatingExpensesAccount::ContingentOtherOperatingExpensesAccount() { init_NULL(); }
ContingentOtherOperatingExpensesAccount::ContingentOtherOperatingExpensesAccount(const ContingentOtherOperatingExpensesAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
ContingentOtherOperatingExpensesAccount::ContingentOtherOperatingExpensesAccount(const ContingentOtherOperatingExpensesAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void ContingentOtherOperatingExpensesAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void ContingentOtherOperatingExpensesAccount::init() {
   FlowAccount::init();
	init_ContingentOtherOperatingExpensesAccount();
}

void ContingentOtherOperatingExpensesAccount::init_ContingentOtherOperatingExpensesAccount() {
   set_id("ContingentOtherOperatingExpensesAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

ContingentOtherOperatingExpensesAccount::~ContingentOtherOperatingExpensesAccount()	{ cleanMem(); }

void ContingentOtherOperatingExpensesAccount::cleanMem()	{
	cleanMem_ContingentOtherOperatingExpensesAccount();
   FlowAccount::cleanMem();
}

void ContingentOtherOperatingExpensesAccount::cleanMem_ContingentOtherOperatingExpensesAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string ContingentOtherOperatingExpensesAccount::className() const {return "ContingentOtherOperatingExpensesAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void ContingentOtherOperatingExpensesAccount::myerr_msg(string msg, string func) {
	err_msg("ContingentOtherOperatingExpensesAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void ContingentOtherOperatingExpensesAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_ContingentOtherOperatingExpensesAccount(fname);
}

void ContingentOtherOperatingExpensesAccount::fprint_ContingentOtherOperatingExpensesAccount(string fname) {
}

void ContingentOtherOperatingExpensesAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_ContingentOtherOperatingExpensesAccount(fname);
}

void ContingentOtherOperatingExpensesAccount::fscan_ContingentOtherOperatingExpensesAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void ContingentOtherOperatingExpensesAccount::reset() {
	reset_ContingentOtherOperatingExpensesAccount();
   FlowAccount::reset();
}

void ContingentOtherOperatingExpensesAccount::reset_ContingentOtherOperatingExpensesAccount() {
}

/** ----------  static instance function -----------*/


ContingentOtherOperatingExpensesAccount* ContingentOtherOperatingExpensesAccount::instance()	{
	ContingentOtherOperatingExpensesAccount* ptr = NULL;
   string id = "ContingentOtherOperatingExpensesAccount";

   ptr = (ContingentOtherOperatingExpensesAccount*) util_singleton("ContingentOtherOperatingExpensesAccount",id);
   if(ptr==NULL) {
      ptr = new ContingentOtherOperatingExpensesAccount();
      ptr->init();
      util_singleton("ContingentOtherOperatingExpensesAccount",id,ptr);
   }
	return ptr;
}

ContingentOtherOperatingExpensesAccount* ContingentOtherOperatingExpensesAccount::instance_fscan(string fname)	{
   return ContingentOtherOperatingExpensesAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

ContingentOtherOperatingExpensesAccount* ContingentOtherOperatingExpensesAccount::__ptr_ContingentOtherOperatingExpensesAccount = ContingentOtherOperatingExpensesAccount::instance();

#endif

