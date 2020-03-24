// Name:     StockExchangeAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_StockExchangeAccount_cpp
#define ASX_StockExchangeAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "StringDbAccount.hpp"
#include "ObjectDb.hpp"
#include "StockExchangeAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiDbAccounts;
using namespace aiMarketFields;

/** --------------Constructors and init_NULL-----------*/

StockExchangeAccount::StockExchangeAccount() { init_NULL(); }
StockExchangeAccount::StockExchangeAccount(const StockExchangeAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
StockExchangeAccount::StockExchangeAccount(const StockExchangeAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void StockExchangeAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void StockExchangeAccount::init() {
   StringDbAccount::init("position");
	init_StockExchangeAccount();
}

void StockExchangeAccount::init_StockExchangeAccount() {
   set_id("StockExchangeAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

StockExchangeAccount::~StockExchangeAccount()	{ cleanMem(); }

void StockExchangeAccount::cleanMem()	{
	cleanMem_StockExchangeAccount();
   StringDbAccount::cleanMem();
}

void StockExchangeAccount::cleanMem_StockExchangeAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string StockExchangeAccount::className() const {return "StockExchangeAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void StockExchangeAccount::myerr_msg(string msg, string func) {
	err_msg("StockExchangeAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void StockExchangeAccount::fprint(string fname) {
   StringDbAccount::fprint(fname);
	fprint_StockExchangeAccount(fname);
}

void StockExchangeAccount::fprint_StockExchangeAccount(string fname) {
}

void StockExchangeAccount::fscan(string fname) {
   StringDbAccount::fscan(fname);
	fscan_StockExchangeAccount(fname);
}

void StockExchangeAccount::fscan_StockExchangeAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void StockExchangeAccount::reset() {
	reset_StockExchangeAccount();
   StringDbAccount::reset();
}

void StockExchangeAccount::reset_StockExchangeAccount() {
}

/** ----------  static instance function -----------*/


StockExchangeAccount* StockExchangeAccount::instance()	{
	StockExchangeAccount* ptr = NULL;
   string id = "StockExchangeAccount";

   ptr = (StockExchangeAccount*) util_singleton("StockExchangeAccount",id);
   if(ptr==NULL) {
      ptr = new StockExchangeAccount();
      ptr->init();
      util_singleton("StockExchangeAccount",id,ptr);
   }
	return ptr;
}

StockExchangeAccount* StockExchangeAccount::instance_fscan(string fname)	{
   return StockExchangeAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

StockExchangeAccount* StockExchangeAccount::__ptr_StockExchangeAccount = StockExchangeAccount::instance();

#endif

