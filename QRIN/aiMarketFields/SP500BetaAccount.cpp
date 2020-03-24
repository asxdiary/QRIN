// Name:     SP500BetaAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_SP500BetaAccount_cpp
#define ASX_SP500BetaAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "StatisticAccount.hpp"
#include "SP500BetaAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiMarketFields;

/** --------------Constructors and init_NULL-----------*/

SP500BetaAccount::SP500BetaAccount() { init_NULL(); }
SP500BetaAccount::SP500BetaAccount(const SP500BetaAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
SP500BetaAccount::SP500BetaAccount(const SP500BetaAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void SP500BetaAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void SP500BetaAccount::init() {
   StatisticAccount::init();
	init_SP500BetaAccount();
}

void SP500BetaAccount::init_SP500BetaAccount() {
   set_id("SP500BetaAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

SP500BetaAccount::~SP500BetaAccount()	{ cleanMem(); }

void SP500BetaAccount::cleanMem()	{
	cleanMem_SP500BetaAccount();
   StatisticAccount::cleanMem();
}

void SP500BetaAccount::cleanMem_SP500BetaAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string SP500BetaAccount::className() const {return "SP500BetaAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void SP500BetaAccount::myerr_msg(string msg, string func) {
	err_msg("SP500BetaAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void SP500BetaAccount::fprint(string fname) {
   StatisticAccount::fprint(fname);
	fprint_SP500BetaAccount(fname);
}

void SP500BetaAccount::fprint_SP500BetaAccount(string fname) {
}

void SP500BetaAccount::fscan(string fname) {
   StatisticAccount::fscan(fname);
	fscan_SP500BetaAccount(fname);
}

void SP500BetaAccount::fscan_SP500BetaAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void SP500BetaAccount::reset() {
	reset_SP500BetaAccount();
   StatisticAccount::reset();
}

void SP500BetaAccount::reset_SP500BetaAccount() {
}

/** ----------  static instance function -----------*/


SP500BetaAccount* SP500BetaAccount::instance()	{
	SP500BetaAccount* ptr = NULL;
   string id = "SP500BetaAccount";

   ptr = (SP500BetaAccount*) util_singleton("SP500BetaAccount",id);
   if(ptr==NULL) {
      ptr = new SP500BetaAccount();
      ptr->init();
      util_singleton("SP500BetaAccount",id,ptr);
   }
	return ptr;
}

SP500BetaAccount* SP500BetaAccount::instance_fscan(string fname)	{
   return SP500BetaAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

SP500BetaAccount* SP500BetaAccount::__ptr_SP500BetaAccount = SP500BetaAccount::instance();

#endif

