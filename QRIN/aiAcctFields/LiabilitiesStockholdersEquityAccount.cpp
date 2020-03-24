// Name:     LiabilitiesStockholdersEquityAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_LiabilitiesStockholdersEquityAccount_cpp
#define ASX_LiabilitiesStockholdersEquityAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "LiabilitiesStockholdersEquityAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

LiabilitiesStockholdersEquityAccount::LiabilitiesStockholdersEquityAccount() { init_NULL(); }
LiabilitiesStockholdersEquityAccount::LiabilitiesStockholdersEquityAccount(const LiabilitiesStockholdersEquityAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
LiabilitiesStockholdersEquityAccount::LiabilitiesStockholdersEquityAccount(const LiabilitiesStockholdersEquityAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void LiabilitiesStockholdersEquityAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void LiabilitiesStockholdersEquityAccount::init() {
   PositionAccount::init();
	init_LiabilitiesStockholdersEquityAccount();
}

void LiabilitiesStockholdersEquityAccount::init_LiabilitiesStockholdersEquityAccount() {
   set_id("LiabilitiesStockholdersEquityAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

LiabilitiesStockholdersEquityAccount::~LiabilitiesStockholdersEquityAccount()	{ cleanMem(); }

void LiabilitiesStockholdersEquityAccount::cleanMem()	{
	cleanMem_LiabilitiesStockholdersEquityAccount();
   PositionAccount::cleanMem();
}

void LiabilitiesStockholdersEquityAccount::cleanMem_LiabilitiesStockholdersEquityAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string LiabilitiesStockholdersEquityAccount::className() const {return "LiabilitiesStockholdersEquityAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void LiabilitiesStockholdersEquityAccount::myerr_msg(string msg, string func) {
	err_msg("LiabilitiesStockholdersEquityAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void LiabilitiesStockholdersEquityAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_LiabilitiesStockholdersEquityAccount(fname);
}

void LiabilitiesStockholdersEquityAccount::fprint_LiabilitiesStockholdersEquityAccount(string fname) {
}

void LiabilitiesStockholdersEquityAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_LiabilitiesStockholdersEquityAccount(fname);
}

void LiabilitiesStockholdersEquityAccount::fscan_LiabilitiesStockholdersEquityAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void LiabilitiesStockholdersEquityAccount::reset() {
	reset_LiabilitiesStockholdersEquityAccount();
   PositionAccount::reset();
}

void LiabilitiesStockholdersEquityAccount::reset_LiabilitiesStockholdersEquityAccount() {
}

/** ----------  static instance function -----------*/


LiabilitiesStockholdersEquityAccount* LiabilitiesStockholdersEquityAccount::instance()	{
	LiabilitiesStockholdersEquityAccount* ptr = NULL;
   string id = "LiabilitiesStockholdersEquityAccount";

   ptr = (LiabilitiesStockholdersEquityAccount*) util_singleton("LiabilitiesStockholdersEquityAccount",id);
   if(ptr==NULL) {
      ptr = new LiabilitiesStockholdersEquityAccount();
      ptr->init();
      util_singleton("LiabilitiesStockholdersEquityAccount",id,ptr);
   }
	return ptr;
}

LiabilitiesStockholdersEquityAccount* LiabilitiesStockholdersEquityAccount::instance_fscan(string fname)	{
   return LiabilitiesStockholdersEquityAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

LiabilitiesStockholdersEquityAccount* LiabilitiesStockholdersEquityAccount::__ptr_LiabilitiesStockholdersEquityAccount = LiabilitiesStockholdersEquityAccount::instance();

#endif

