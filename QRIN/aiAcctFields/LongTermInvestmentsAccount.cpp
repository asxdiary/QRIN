// Name:     LongTermInvestmentsAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_LongTermInvestmentsAccount_cpp
#define ASX_LongTermInvestmentsAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "LongTermInvestmentsAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

LongTermInvestmentsAccount::LongTermInvestmentsAccount() { init_NULL(); }
LongTermInvestmentsAccount::LongTermInvestmentsAccount(const LongTermInvestmentsAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
LongTermInvestmentsAccount::LongTermInvestmentsAccount(const LongTermInvestmentsAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void LongTermInvestmentsAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void LongTermInvestmentsAccount::init() {
   PositionAccount::init();
	init_LongTermInvestmentsAccount();
}

void LongTermInvestmentsAccount::init_LongTermInvestmentsAccount() {
   set_id("LongTermInvestmentsAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

LongTermInvestmentsAccount::~LongTermInvestmentsAccount()	{ cleanMem(); }

void LongTermInvestmentsAccount::cleanMem()	{
	cleanMem_LongTermInvestmentsAccount();
   PositionAccount::cleanMem();
}

void LongTermInvestmentsAccount::cleanMem_LongTermInvestmentsAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string LongTermInvestmentsAccount::className() const {return "LongTermInvestmentsAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void LongTermInvestmentsAccount::myerr_msg(string msg, string func) {
	err_msg("LongTermInvestmentsAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void LongTermInvestmentsAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_LongTermInvestmentsAccount(fname);
}

void LongTermInvestmentsAccount::fprint_LongTermInvestmentsAccount(string fname) {
}

void LongTermInvestmentsAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_LongTermInvestmentsAccount(fname);
}

void LongTermInvestmentsAccount::fscan_LongTermInvestmentsAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void LongTermInvestmentsAccount::reset() {
	reset_LongTermInvestmentsAccount();
   PositionAccount::reset();
}

void LongTermInvestmentsAccount::reset_LongTermInvestmentsAccount() {
}

/** ----------  static instance function -----------*/


LongTermInvestmentsAccount* LongTermInvestmentsAccount::instance()	{
	LongTermInvestmentsAccount* ptr = NULL;
   string id = "LongTermInvestmentsAccount";

   ptr = (LongTermInvestmentsAccount*) util_singleton("LongTermInvestmentsAccount",id);
   if(ptr==NULL) {
      ptr = new LongTermInvestmentsAccount();
      ptr->init();
      util_singleton("LongTermInvestmentsAccount",id,ptr);
   }
	return ptr;
}

LongTermInvestmentsAccount* LongTermInvestmentsAccount::instance_fscan(string fname)	{
   return LongTermInvestmentsAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

LongTermInvestmentsAccount* LongTermInvestmentsAccount::__ptr_LongTermInvestmentsAccount = LongTermInvestmentsAccount::instance();

#endif

