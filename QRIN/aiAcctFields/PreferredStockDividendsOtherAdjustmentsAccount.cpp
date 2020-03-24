// Name:     PreferredStockDividendsOtherAdjustmentsAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_PreferredStockDividendsOtherAdjustmentsAccount_cpp
#define ASX_PreferredStockDividendsOtherAdjustmentsAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "PreferredStockDividendsOtherAdjustmentsAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

PreferredStockDividendsOtherAdjustmentsAccount::PreferredStockDividendsOtherAdjustmentsAccount() { init_NULL(); }
PreferredStockDividendsOtherAdjustmentsAccount::PreferredStockDividendsOtherAdjustmentsAccount(const PreferredStockDividendsOtherAdjustmentsAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
PreferredStockDividendsOtherAdjustmentsAccount::PreferredStockDividendsOtherAdjustmentsAccount(const PreferredStockDividendsOtherAdjustmentsAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void PreferredStockDividendsOtherAdjustmentsAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void PreferredStockDividendsOtherAdjustmentsAccount::init() {
   FlowAccount::init();
	init_PreferredStockDividendsOtherAdjustmentsAccount();
}

void PreferredStockDividendsOtherAdjustmentsAccount::init_PreferredStockDividendsOtherAdjustmentsAccount() {
   set_id("PreferredStockDividendsOtherAdjustmentsAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

PreferredStockDividendsOtherAdjustmentsAccount::~PreferredStockDividendsOtherAdjustmentsAccount()	{ cleanMem(); }

void PreferredStockDividendsOtherAdjustmentsAccount::cleanMem()	{
	cleanMem_PreferredStockDividendsOtherAdjustmentsAccount();
   FlowAccount::cleanMem();
}

void PreferredStockDividendsOtherAdjustmentsAccount::cleanMem_PreferredStockDividendsOtherAdjustmentsAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string PreferredStockDividendsOtherAdjustmentsAccount::className() const {return "PreferredStockDividendsOtherAdjustmentsAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void PreferredStockDividendsOtherAdjustmentsAccount::myerr_msg(string msg, string func) {
	err_msg("PreferredStockDividendsOtherAdjustmentsAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void PreferredStockDividendsOtherAdjustmentsAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_PreferredStockDividendsOtherAdjustmentsAccount(fname);
}

void PreferredStockDividendsOtherAdjustmentsAccount::fprint_PreferredStockDividendsOtherAdjustmentsAccount(string fname) {
}

void PreferredStockDividendsOtherAdjustmentsAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_PreferredStockDividendsOtherAdjustmentsAccount(fname);
}

void PreferredStockDividendsOtherAdjustmentsAccount::fscan_PreferredStockDividendsOtherAdjustmentsAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void PreferredStockDividendsOtherAdjustmentsAccount::reset() {
	reset_PreferredStockDividendsOtherAdjustmentsAccount();
   FlowAccount::reset();
}

void PreferredStockDividendsOtherAdjustmentsAccount::reset_PreferredStockDividendsOtherAdjustmentsAccount() {
}

/** ----------  static instance function -----------*/


PreferredStockDividendsOtherAdjustmentsAccount* PreferredStockDividendsOtherAdjustmentsAccount::instance()	{
	PreferredStockDividendsOtherAdjustmentsAccount* ptr = NULL;
   string id = "PreferredStockDividendsOtherAdjustmentsAccount";

   ptr = (PreferredStockDividendsOtherAdjustmentsAccount*) util_singleton("PreferredStockDividendsOtherAdjustmentsAccount",id);
   if(ptr==NULL) {
      ptr = new PreferredStockDividendsOtherAdjustmentsAccount();
      ptr->init();
      util_singleton("PreferredStockDividendsOtherAdjustmentsAccount",id,ptr);
   }
	return ptr;
}

PreferredStockDividendsOtherAdjustmentsAccount* PreferredStockDividendsOtherAdjustmentsAccount::instance_fscan(string fname)	{
   return PreferredStockDividendsOtherAdjustmentsAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

PreferredStockDividendsOtherAdjustmentsAccount* PreferredStockDividendsOtherAdjustmentsAccount::__ptr_PreferredStockDividendsOtherAdjustmentsAccount = PreferredStockDividendsOtherAdjustmentsAccount::instance();

#endif

