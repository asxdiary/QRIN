// Name:     OffBalanceSheetFinancingAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_OffBalanceSheetFinancingAccount_cpp
#define ASX_OffBalanceSheetFinancingAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "OffBalanceSheetFinancingAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

OffBalanceSheetFinancingAccount::OffBalanceSheetFinancingAccount() { init_NULL(); }
OffBalanceSheetFinancingAccount::OffBalanceSheetFinancingAccount(const OffBalanceSheetFinancingAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
OffBalanceSheetFinancingAccount::OffBalanceSheetFinancingAccount(const OffBalanceSheetFinancingAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void OffBalanceSheetFinancingAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void OffBalanceSheetFinancingAccount::init() {
   PositionAccount::init();
	init_OffBalanceSheetFinancingAccount();
}

void OffBalanceSheetFinancingAccount::init_OffBalanceSheetFinancingAccount() {
   set_id("OffBalanceSheetFinancingAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

OffBalanceSheetFinancingAccount::~OffBalanceSheetFinancingAccount()	{ cleanMem(); }

void OffBalanceSheetFinancingAccount::cleanMem()	{
	cleanMem_OffBalanceSheetFinancingAccount();
   PositionAccount::cleanMem();
}

void OffBalanceSheetFinancingAccount::cleanMem_OffBalanceSheetFinancingAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string OffBalanceSheetFinancingAccount::className() const {return "OffBalanceSheetFinancingAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void OffBalanceSheetFinancingAccount::myerr_msg(string msg, string func) {
	err_msg("OffBalanceSheetFinancingAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void OffBalanceSheetFinancingAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_OffBalanceSheetFinancingAccount(fname);
}

void OffBalanceSheetFinancingAccount::fprint_OffBalanceSheetFinancingAccount(string fname) {
}

void OffBalanceSheetFinancingAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_OffBalanceSheetFinancingAccount(fname);
}

void OffBalanceSheetFinancingAccount::fscan_OffBalanceSheetFinancingAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void OffBalanceSheetFinancingAccount::reset() {
	reset_OffBalanceSheetFinancingAccount();
   PositionAccount::reset();
}

void OffBalanceSheetFinancingAccount::reset_OffBalanceSheetFinancingAccount() {
}

/** ----------  static instance function -----------*/


OffBalanceSheetFinancingAccount* OffBalanceSheetFinancingAccount::instance()	{
	OffBalanceSheetFinancingAccount* ptr = NULL;
   string id = "OffBalanceSheetFinancingAccount";

   ptr = (OffBalanceSheetFinancingAccount*) util_singleton("OffBalanceSheetFinancingAccount",id);
   if(ptr==NULL) {
      ptr = new OffBalanceSheetFinancingAccount();
      ptr->init();
      util_singleton("OffBalanceSheetFinancingAccount",id,ptr);
   }
	return ptr;
}

OffBalanceSheetFinancingAccount* OffBalanceSheetFinancingAccount::instance_fscan(string fname)	{
   return OffBalanceSheetFinancingAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

OffBalanceSheetFinancingAccount* OffBalanceSheetFinancingAccount::__ptr_OffBalanceSheetFinancingAccount = OffBalanceSheetFinancingAccount::instance();

#endif

