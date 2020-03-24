// Name:     TotalEquityCapitalAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_TotalEquityCapitalAccount_cpp
#define ASX_TotalEquityCapitalAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "TotalEquityCapitalAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

TotalEquityCapitalAccount::TotalEquityCapitalAccount() { init_NULL(); }
TotalEquityCapitalAccount::TotalEquityCapitalAccount(const TotalEquityCapitalAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
TotalEquityCapitalAccount::TotalEquityCapitalAccount(const TotalEquityCapitalAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void TotalEquityCapitalAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void TotalEquityCapitalAccount::init() {
   PositionAccount::init();
	init_TotalEquityCapitalAccount();
}

void TotalEquityCapitalAccount::init_TotalEquityCapitalAccount() {
   set_id("TotalEquityCapitalAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

TotalEquityCapitalAccount::~TotalEquityCapitalAccount()	{ cleanMem(); }

void TotalEquityCapitalAccount::cleanMem()	{
	cleanMem_TotalEquityCapitalAccount();
   PositionAccount::cleanMem();
}

void TotalEquityCapitalAccount::cleanMem_TotalEquityCapitalAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string TotalEquityCapitalAccount::className() const {return "TotalEquityCapitalAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void TotalEquityCapitalAccount::myerr_msg(string msg, string func) {
	err_msg("TotalEquityCapitalAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void TotalEquityCapitalAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_TotalEquityCapitalAccount(fname);
}

void TotalEquityCapitalAccount::fprint_TotalEquityCapitalAccount(string fname) {
}

void TotalEquityCapitalAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_TotalEquityCapitalAccount(fname);
}

void TotalEquityCapitalAccount::fscan_TotalEquityCapitalAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void TotalEquityCapitalAccount::reset() {
	reset_TotalEquityCapitalAccount();
   PositionAccount::reset();
}

void TotalEquityCapitalAccount::reset_TotalEquityCapitalAccount() {
}

/** ----------  static instance function -----------*/


TotalEquityCapitalAccount* TotalEquityCapitalAccount::instance()	{
	TotalEquityCapitalAccount* ptr = NULL;
   string id = "TotalEquityCapitalAccount";

   ptr = (TotalEquityCapitalAccount*) util_singleton("TotalEquityCapitalAccount",id);
   if(ptr==NULL) {
      ptr = new TotalEquityCapitalAccount();
      ptr->init();
      util_singleton("TotalEquityCapitalAccount",id,ptr);
   }
	return ptr;
}

TotalEquityCapitalAccount* TotalEquityCapitalAccount::instance_fscan(string fname)	{
   return TotalEquityCapitalAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

TotalEquityCapitalAccount* TotalEquityCapitalAccount::__ptr_TotalEquityCapitalAccount = TotalEquityCapitalAccount::instance();

#endif

