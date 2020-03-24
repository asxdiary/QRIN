// Name:     WeightedAverageDilutedSharesAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_WeightedAverageDilutedSharesAccount_cpp
#define ASX_WeightedAverageDilutedSharesAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "WeightedAverageDilutedSharesAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

WeightedAverageDilutedSharesAccount::WeightedAverageDilutedSharesAccount() { init_NULL(); }
WeightedAverageDilutedSharesAccount::WeightedAverageDilutedSharesAccount(const WeightedAverageDilutedSharesAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
WeightedAverageDilutedSharesAccount::WeightedAverageDilutedSharesAccount(const WeightedAverageDilutedSharesAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void WeightedAverageDilutedSharesAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void WeightedAverageDilutedSharesAccount::init() {
   FlowAccount::init();
	init_WeightedAverageDilutedSharesAccount();
}

void WeightedAverageDilutedSharesAccount::init_WeightedAverageDilutedSharesAccount() {
   set_id("WeightedAverageDilutedSharesAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

WeightedAverageDilutedSharesAccount::~WeightedAverageDilutedSharesAccount()	{ cleanMem(); }

void WeightedAverageDilutedSharesAccount::cleanMem()	{
	cleanMem_WeightedAverageDilutedSharesAccount();
   FlowAccount::cleanMem();
}

void WeightedAverageDilutedSharesAccount::cleanMem_WeightedAverageDilutedSharesAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string WeightedAverageDilutedSharesAccount::className() const {return "WeightedAverageDilutedSharesAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void WeightedAverageDilutedSharesAccount::myerr_msg(string msg, string func) {
	err_msg("WeightedAverageDilutedSharesAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void WeightedAverageDilutedSharesAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_WeightedAverageDilutedSharesAccount(fname);
}

void WeightedAverageDilutedSharesAccount::fprint_WeightedAverageDilutedSharesAccount(string fname) {
}

void WeightedAverageDilutedSharesAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_WeightedAverageDilutedSharesAccount(fname);
}

void WeightedAverageDilutedSharesAccount::fscan_WeightedAverageDilutedSharesAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void WeightedAverageDilutedSharesAccount::reset() {
	reset_WeightedAverageDilutedSharesAccount();
   FlowAccount::reset();
}

void WeightedAverageDilutedSharesAccount::reset_WeightedAverageDilutedSharesAccount() {
}

/** ----------  static instance function -----------*/


WeightedAverageDilutedSharesAccount* WeightedAverageDilutedSharesAccount::instance()	{
	WeightedAverageDilutedSharesAccount* ptr = NULL;
   string id = "WeightedAverageDilutedSharesAccount";

   ptr = (WeightedAverageDilutedSharesAccount*) util_singleton("WeightedAverageDilutedSharesAccount",id);
   if(ptr==NULL) {
      ptr = new WeightedAverageDilutedSharesAccount();
      ptr->init();
      util_singleton("WeightedAverageDilutedSharesAccount",id,ptr);
   }
	return ptr;
}

WeightedAverageDilutedSharesAccount* WeightedAverageDilutedSharesAccount::instance_fscan(string fname)	{
   return WeightedAverageDilutedSharesAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

WeightedAverageDilutedSharesAccount* WeightedAverageDilutedSharesAccount::__ptr_WeightedAverageDilutedSharesAccount = WeightedAverageDilutedSharesAccount::instance();

#endif

