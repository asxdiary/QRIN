// Name:     TotalAssetsAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_TotalAssetsAccount_cpp
#define ASX_TotalAssetsAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "TotalAssetsAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

TotalAssetsAccount::TotalAssetsAccount() { init_NULL(); }
TotalAssetsAccount::TotalAssetsAccount(const TotalAssetsAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
TotalAssetsAccount::TotalAssetsAccount(const TotalAssetsAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void TotalAssetsAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void TotalAssetsAccount::init() {
   PositionAccount::init();
	init_TotalAssetsAccount();
}

void TotalAssetsAccount::init_TotalAssetsAccount() {
   set_id("TotalAssetsAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

TotalAssetsAccount::~TotalAssetsAccount()	{ cleanMem(); }

void TotalAssetsAccount::cleanMem()	{
	cleanMem_TotalAssetsAccount();
   PositionAccount::cleanMem();
}

void TotalAssetsAccount::cleanMem_TotalAssetsAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string TotalAssetsAccount::className() const {return "TotalAssetsAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void TotalAssetsAccount::myerr_msg(string msg, string func) {
	err_msg("TotalAssetsAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void TotalAssetsAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_TotalAssetsAccount(fname);
}

void TotalAssetsAccount::fprint_TotalAssetsAccount(string fname) {
}

void TotalAssetsAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_TotalAssetsAccount(fname);
}

void TotalAssetsAccount::fscan_TotalAssetsAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void TotalAssetsAccount::reset() {
	reset_TotalAssetsAccount();
   PositionAccount::reset();
}

void TotalAssetsAccount::reset_TotalAssetsAccount() {
}

/** ----------  static instance function -----------*/


TotalAssetsAccount* TotalAssetsAccount::instance()	{
	TotalAssetsAccount* ptr = NULL;
   string id = "TotalAssetsAccount";

   ptr = (TotalAssetsAccount*) util_singleton("TotalAssetsAccount",id);
   if(ptr==NULL) {
      ptr = new TotalAssetsAccount();
      ptr->init();
      util_singleton("TotalAssetsAccount",id,ptr);
   }
	return ptr;
}

TotalAssetsAccount* TotalAssetsAccount::instance_fscan(string fname)	{
   return TotalAssetsAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

TotalAssetsAccount* TotalAssetsAccount::__ptr_TotalAssetsAccount = TotalAssetsAccount::instance();

#endif

