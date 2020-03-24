// Name:     EarningsLossesEquityInvestmentsAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_EarningsLossesEquityInvestmentsAccount_cpp
#define ASX_EarningsLossesEquityInvestmentsAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "EarningsLossesEquityInvestmentsAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

EarningsLossesEquityInvestmentsAccount::EarningsLossesEquityInvestmentsAccount() { init_NULL(); }
EarningsLossesEquityInvestmentsAccount::EarningsLossesEquityInvestmentsAccount(const EarningsLossesEquityInvestmentsAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
EarningsLossesEquityInvestmentsAccount::EarningsLossesEquityInvestmentsAccount(const EarningsLossesEquityInvestmentsAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void EarningsLossesEquityInvestmentsAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void EarningsLossesEquityInvestmentsAccount::init() {
   FlowAccount::init();
	init_EarningsLossesEquityInvestmentsAccount();
}

void EarningsLossesEquityInvestmentsAccount::init_EarningsLossesEquityInvestmentsAccount() {
   set_id("EarningsLossesEquityInvestmentsAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

EarningsLossesEquityInvestmentsAccount::~EarningsLossesEquityInvestmentsAccount()	{ cleanMem(); }

void EarningsLossesEquityInvestmentsAccount::cleanMem()	{
	cleanMem_EarningsLossesEquityInvestmentsAccount();
   FlowAccount::cleanMem();
}

void EarningsLossesEquityInvestmentsAccount::cleanMem_EarningsLossesEquityInvestmentsAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string EarningsLossesEquityInvestmentsAccount::className() const {return "EarningsLossesEquityInvestmentsAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void EarningsLossesEquityInvestmentsAccount::myerr_msg(string msg, string func) {
	err_msg("EarningsLossesEquityInvestmentsAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void EarningsLossesEquityInvestmentsAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_EarningsLossesEquityInvestmentsAccount(fname);
}

void EarningsLossesEquityInvestmentsAccount::fprint_EarningsLossesEquityInvestmentsAccount(string fname) {
}

void EarningsLossesEquityInvestmentsAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_EarningsLossesEquityInvestmentsAccount(fname);
}

void EarningsLossesEquityInvestmentsAccount::fscan_EarningsLossesEquityInvestmentsAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void EarningsLossesEquityInvestmentsAccount::reset() {
	reset_EarningsLossesEquityInvestmentsAccount();
   FlowAccount::reset();
}

void EarningsLossesEquityInvestmentsAccount::reset_EarningsLossesEquityInvestmentsAccount() {
}

/** ----------  static instance function -----------*/


EarningsLossesEquityInvestmentsAccount* EarningsLossesEquityInvestmentsAccount::instance()	{
	EarningsLossesEquityInvestmentsAccount* ptr = NULL;
   string id = "EarningsLossesEquityInvestmentsAccount";

   ptr = (EarningsLossesEquityInvestmentsAccount*) util_singleton("EarningsLossesEquityInvestmentsAccount",id);
   if(ptr==NULL) {
      ptr = new EarningsLossesEquityInvestmentsAccount();
      ptr->init();
      util_singleton("EarningsLossesEquityInvestmentsAccount",id,ptr);
   }
	return ptr;
}

EarningsLossesEquityInvestmentsAccount* EarningsLossesEquityInvestmentsAccount::instance_fscan(string fname)	{
   return EarningsLossesEquityInvestmentsAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

EarningsLossesEquityInvestmentsAccount* EarningsLossesEquityInvestmentsAccount::__ptr_EarningsLossesEquityInvestmentsAccount = EarningsLossesEquityInvestmentsAccount::instance();

#endif

