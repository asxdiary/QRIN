// Name:     EffectExchangeRateCashCashEquivalentsAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_EffectExchangeRateCashCashEquivalentsAccount_cpp
#define ASX_EffectExchangeRateCashCashEquivalentsAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "EffectExchangeRateCashCashEquivalentsAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

EffectExchangeRateCashCashEquivalentsAccount::EffectExchangeRateCashCashEquivalentsAccount() { init_NULL(); }
EffectExchangeRateCashCashEquivalentsAccount::EffectExchangeRateCashCashEquivalentsAccount(const EffectExchangeRateCashCashEquivalentsAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
EffectExchangeRateCashCashEquivalentsAccount::EffectExchangeRateCashCashEquivalentsAccount(const EffectExchangeRateCashCashEquivalentsAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void EffectExchangeRateCashCashEquivalentsAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void EffectExchangeRateCashCashEquivalentsAccount::init() {
   FlowAccount::init();
	init_EffectExchangeRateCashCashEquivalentsAccount();
}

void EffectExchangeRateCashCashEquivalentsAccount::init_EffectExchangeRateCashCashEquivalentsAccount() {
   set_id("EffectExchangeRateCashCashEquivalentsAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

EffectExchangeRateCashCashEquivalentsAccount::~EffectExchangeRateCashCashEquivalentsAccount()	{ cleanMem(); }

void EffectExchangeRateCashCashEquivalentsAccount::cleanMem()	{
	cleanMem_EffectExchangeRateCashCashEquivalentsAccount();
   FlowAccount::cleanMem();
}

void EffectExchangeRateCashCashEquivalentsAccount::cleanMem_EffectExchangeRateCashCashEquivalentsAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string EffectExchangeRateCashCashEquivalentsAccount::className() const {return "EffectExchangeRateCashCashEquivalentsAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void EffectExchangeRateCashCashEquivalentsAccount::myerr_msg(string msg, string func) {
	err_msg("EffectExchangeRateCashCashEquivalentsAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void EffectExchangeRateCashCashEquivalentsAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_EffectExchangeRateCashCashEquivalentsAccount(fname);
}

void EffectExchangeRateCashCashEquivalentsAccount::fprint_EffectExchangeRateCashCashEquivalentsAccount(string fname) {
}

void EffectExchangeRateCashCashEquivalentsAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_EffectExchangeRateCashCashEquivalentsAccount(fname);
}

void EffectExchangeRateCashCashEquivalentsAccount::fscan_EffectExchangeRateCashCashEquivalentsAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void EffectExchangeRateCashCashEquivalentsAccount::reset() {
	reset_EffectExchangeRateCashCashEquivalentsAccount();
   FlowAccount::reset();
}

void EffectExchangeRateCashCashEquivalentsAccount::reset_EffectExchangeRateCashCashEquivalentsAccount() {
}

/** ----------  static instance function -----------*/


EffectExchangeRateCashCashEquivalentsAccount* EffectExchangeRateCashCashEquivalentsAccount::instance()	{
	EffectExchangeRateCashCashEquivalentsAccount* ptr = NULL;
   string id = "EffectExchangeRateCashCashEquivalentsAccount";

   ptr = (EffectExchangeRateCashCashEquivalentsAccount*) util_singleton("EffectExchangeRateCashCashEquivalentsAccount",id);
   if(ptr==NULL) {
      ptr = new EffectExchangeRateCashCashEquivalentsAccount();
      ptr->init();
      util_singleton("EffectExchangeRateCashCashEquivalentsAccount",id,ptr);
   }
	return ptr;
}

EffectExchangeRateCashCashEquivalentsAccount* EffectExchangeRateCashCashEquivalentsAccount::instance_fscan(string fname)	{
   return EffectExchangeRateCashCashEquivalentsAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

EffectExchangeRateCashCashEquivalentsAccount* EffectExchangeRateCashCashEquivalentsAccount::__ptr_EffectExchangeRateCashCashEquivalentsAccount = EffectExchangeRateCashCashEquivalentsAccount::instance();

#endif

