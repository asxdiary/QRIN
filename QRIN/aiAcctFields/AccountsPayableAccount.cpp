// Name:     AccountsPayableAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_AccountsPayableAccount_cpp
#define ASX_AccountsPayableAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "AccountsPayableAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

AccountsPayableAccount::AccountsPayableAccount() { init_NULL(); }
AccountsPayableAccount::AccountsPayableAccount(const AccountsPayableAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
AccountsPayableAccount::AccountsPayableAccount(const AccountsPayableAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void AccountsPayableAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void AccountsPayableAccount::init() {
   PositionAccount::init();
	init_AccountsPayableAccount();
}

void AccountsPayableAccount::init_AccountsPayableAccount() {
   set_id("AccountsPayableAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

AccountsPayableAccount::~AccountsPayableAccount()	{ cleanMem(); }

void AccountsPayableAccount::cleanMem()	{
	cleanMem_AccountsPayableAccount();
   PositionAccount::cleanMem();
}

void AccountsPayableAccount::cleanMem_AccountsPayableAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string AccountsPayableAccount::className() const {return "AccountsPayableAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void AccountsPayableAccount::myerr_msg(string msg, string func) {
	err_msg("AccountsPayableAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void AccountsPayableAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_AccountsPayableAccount(fname);
}

void AccountsPayableAccount::fprint_AccountsPayableAccount(string fname) {
}

void AccountsPayableAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_AccountsPayableAccount(fname);
}

void AccountsPayableAccount::fscan_AccountsPayableAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void AccountsPayableAccount::reset() {
	reset_AccountsPayableAccount();
   PositionAccount::reset();
}

void AccountsPayableAccount::reset_AccountsPayableAccount() {
}

/** ----------  static instance function -----------*/


AccountsPayableAccount* AccountsPayableAccount::instance()	{
	AccountsPayableAccount* ptr = NULL;
   string id = "AccountsPayableAccount";

   ptr = (AccountsPayableAccount*) util_singleton("AccountsPayableAccount",id);
   if(ptr==NULL) {
      ptr = new AccountsPayableAccount();
      ptr->init();
      util_singleton("AccountsPayableAccount",id,ptr);
   }
	return ptr;
}

AccountsPayableAccount* AccountsPayableAccount::instance_fscan(string fname)	{
   return AccountsPayableAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

AccountsPayableAccount* AccountsPayableAccount::__ptr_AccountsPayableAccount = AccountsPayableAccount::instance();

#endif

