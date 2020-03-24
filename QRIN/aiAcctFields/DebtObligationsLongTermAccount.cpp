// Name:     DebtObligationsLongTermAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DebtObligationsLongTermAccount_cpp
#define ASX_DebtObligationsLongTermAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "DebtObligationsLongTermAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

DebtObligationsLongTermAccount::DebtObligationsLongTermAccount() { init_NULL(); }
DebtObligationsLongTermAccount::DebtObligationsLongTermAccount(const DebtObligationsLongTermAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
DebtObligationsLongTermAccount::DebtObligationsLongTermAccount(const DebtObligationsLongTermAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void DebtObligationsLongTermAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void DebtObligationsLongTermAccount::init() {
   PositionAccount::init();
	init_DebtObligationsLongTermAccount();
}

void DebtObligationsLongTermAccount::init_DebtObligationsLongTermAccount() {
   set_id("DebtObligationsLongTermAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

DebtObligationsLongTermAccount::~DebtObligationsLongTermAccount()	{ cleanMem(); }

void DebtObligationsLongTermAccount::cleanMem()	{
	cleanMem_DebtObligationsLongTermAccount();
   PositionAccount::cleanMem();
}

void DebtObligationsLongTermAccount::cleanMem_DebtObligationsLongTermAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string DebtObligationsLongTermAccount::className() const {return "DebtObligationsLongTermAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void DebtObligationsLongTermAccount::myerr_msg(string msg, string func) {
	err_msg("DebtObligationsLongTermAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void DebtObligationsLongTermAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_DebtObligationsLongTermAccount(fname);
}

void DebtObligationsLongTermAccount::fprint_DebtObligationsLongTermAccount(string fname) {
}

void DebtObligationsLongTermAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_DebtObligationsLongTermAccount(fname);
}

void DebtObligationsLongTermAccount::fscan_DebtObligationsLongTermAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void DebtObligationsLongTermAccount::reset() {
	reset_DebtObligationsLongTermAccount();
   PositionAccount::reset();
}

void DebtObligationsLongTermAccount::reset_DebtObligationsLongTermAccount() {
}

/** ----------  static instance function -----------*/


DebtObligationsLongTermAccount* DebtObligationsLongTermAccount::instance()	{
	DebtObligationsLongTermAccount* ptr = NULL;
   string id = "DebtObligationsLongTermAccount";

   ptr = (DebtObligationsLongTermAccount*) util_singleton("DebtObligationsLongTermAccount",id);
   if(ptr==NULL) {
      ptr = new DebtObligationsLongTermAccount();
      ptr->init();
      util_singleton("DebtObligationsLongTermAccount",id,ptr);
   }
	return ptr;
}

DebtObligationsLongTermAccount* DebtObligationsLongTermAccount::instance_fscan(string fname)	{
   return DebtObligationsLongTermAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

DebtObligationsLongTermAccount* DebtObligationsLongTermAccount::__ptr_DebtObligationsLongTermAccount = DebtObligationsLongTermAccount::instance();

#endif

