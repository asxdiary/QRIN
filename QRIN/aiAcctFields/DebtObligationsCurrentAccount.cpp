// Name:     DebtObligationsCurrentAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DebtObligationsCurrentAccount_cpp
#define ASX_DebtObligationsCurrentAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "DebtObligationsCurrentAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

DebtObligationsCurrentAccount::DebtObligationsCurrentAccount() { init_NULL(); }
DebtObligationsCurrentAccount::DebtObligationsCurrentAccount(const DebtObligationsCurrentAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
DebtObligationsCurrentAccount::DebtObligationsCurrentAccount(const DebtObligationsCurrentAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void DebtObligationsCurrentAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void DebtObligationsCurrentAccount::init() {
   PositionAccount::init();
	init_DebtObligationsCurrentAccount();
}

void DebtObligationsCurrentAccount::init_DebtObligationsCurrentAccount() {
   set_id("DebtObligationsCurrentAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

DebtObligationsCurrentAccount::~DebtObligationsCurrentAccount()	{ cleanMem(); }

void DebtObligationsCurrentAccount::cleanMem()	{
	cleanMem_DebtObligationsCurrentAccount();
   PositionAccount::cleanMem();
}

void DebtObligationsCurrentAccount::cleanMem_DebtObligationsCurrentAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string DebtObligationsCurrentAccount::className() const {return "DebtObligationsCurrentAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void DebtObligationsCurrentAccount::myerr_msg(string msg, string func) {
	err_msg("DebtObligationsCurrentAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void DebtObligationsCurrentAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_DebtObligationsCurrentAccount(fname);
}

void DebtObligationsCurrentAccount::fprint_DebtObligationsCurrentAccount(string fname) {
}

void DebtObligationsCurrentAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_DebtObligationsCurrentAccount(fname);
}

void DebtObligationsCurrentAccount::fscan_DebtObligationsCurrentAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void DebtObligationsCurrentAccount::reset() {
	reset_DebtObligationsCurrentAccount();
   PositionAccount::reset();
}

void DebtObligationsCurrentAccount::reset_DebtObligationsCurrentAccount() {
}

/** ----------  static instance function -----------*/


DebtObligationsCurrentAccount* DebtObligationsCurrentAccount::instance()	{
	DebtObligationsCurrentAccount* ptr = NULL;
   string id = "DebtObligationsCurrentAccount";

   ptr = (DebtObligationsCurrentAccount*) util_singleton("DebtObligationsCurrentAccount",id);
   if(ptr==NULL) {
      ptr = new DebtObligationsCurrentAccount();
      ptr->init();
      util_singleton("DebtObligationsCurrentAccount",id,ptr);
   }
	return ptr;
}

DebtObligationsCurrentAccount* DebtObligationsCurrentAccount::instance_fscan(string fname)	{
   return DebtObligationsCurrentAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

DebtObligationsCurrentAccount* DebtObligationsCurrentAccount::__ptr_DebtObligationsCurrentAccount = DebtObligationsCurrentAccount::instance();

#endif

