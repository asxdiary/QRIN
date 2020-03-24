// Name:     MarketCapAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_MarketCapAccount_cpp
#define ASX_MarketCapAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "MarketCapAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiMarketFields;

/** --------------Constructors and init_NULL-----------*/

MarketCapAccount::MarketCapAccount() { init_NULL(); }
MarketCapAccount::MarketCapAccount(const MarketCapAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
MarketCapAccount::MarketCapAccount(const MarketCapAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void MarketCapAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void MarketCapAccount::init() {
   PositionAccount::init();
	init_MarketCapAccount();
}

void MarketCapAccount::init_MarketCapAccount() {
   set_id("MarketCapAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

MarketCapAccount::~MarketCapAccount()	{ cleanMem(); }

void MarketCapAccount::cleanMem()	{
	cleanMem_MarketCapAccount();
   PositionAccount::cleanMem();
}

void MarketCapAccount::cleanMem_MarketCapAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string MarketCapAccount::className() const {return "MarketCapAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void MarketCapAccount::myerr_msg(string msg, string func) {
	err_msg("MarketCapAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void MarketCapAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_MarketCapAccount(fname);
}

void MarketCapAccount::fprint_MarketCapAccount(string fname) {
}

void MarketCapAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_MarketCapAccount(fname);
}

void MarketCapAccount::fscan_MarketCapAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void MarketCapAccount::reset() {
	reset_MarketCapAccount();
   PositionAccount::reset();
}

void MarketCapAccount::reset_MarketCapAccount() {
}

/** ----------  static instance function -----------*/


MarketCapAccount* MarketCapAccount::instance()	{
	MarketCapAccount* ptr = NULL;
   string id = "MarketCapAccount";

   ptr = (MarketCapAccount*) util_singleton("MarketCapAccount",id);
   if(ptr==NULL) {
      ptr = new MarketCapAccount();
      ptr->init();
      util_singleton("MarketCapAccount",id,ptr);
   }
	return ptr;
}

MarketCapAccount* MarketCapAccount::instance_fscan(string fname)	{
   return MarketCapAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

MarketCapAccount* MarketCapAccount::__ptr_MarketCapAccount = MarketCapAccount::instance();

#endif

