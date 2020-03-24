// Name:     CurrentAssetsAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CurrentAssetsAccount_cpp
#define ASX_CurrentAssetsAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "CurrentAssetsAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

CurrentAssetsAccount::CurrentAssetsAccount() { init_NULL(); }
CurrentAssetsAccount::CurrentAssetsAccount(const CurrentAssetsAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
CurrentAssetsAccount::CurrentAssetsAccount(const CurrentAssetsAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void CurrentAssetsAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void CurrentAssetsAccount::init() {
   PositionAccount::init();
	init_CurrentAssetsAccount();
}

void CurrentAssetsAccount::init_CurrentAssetsAccount() {
   set_id("CurrentAssetsAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

CurrentAssetsAccount::~CurrentAssetsAccount()	{ cleanMem(); }

void CurrentAssetsAccount::cleanMem()	{
	cleanMem_CurrentAssetsAccount();
   PositionAccount::cleanMem();
}

void CurrentAssetsAccount::cleanMem_CurrentAssetsAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string CurrentAssetsAccount::className() const {return "CurrentAssetsAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void CurrentAssetsAccount::myerr_msg(string msg, string func) {
	err_msg("CurrentAssetsAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void CurrentAssetsAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_CurrentAssetsAccount(fname);
}

void CurrentAssetsAccount::fprint_CurrentAssetsAccount(string fname) {
}

void CurrentAssetsAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_CurrentAssetsAccount(fname);
}

void CurrentAssetsAccount::fscan_CurrentAssetsAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void CurrentAssetsAccount::reset() {
	reset_CurrentAssetsAccount();
   PositionAccount::reset();
}

void CurrentAssetsAccount::reset_CurrentAssetsAccount() {
}

/** ----------  static instance function -----------*/


CurrentAssetsAccount* CurrentAssetsAccount::instance()	{
	CurrentAssetsAccount* ptr = NULL;
   string id = "CurrentAssetsAccount";

   ptr = (CurrentAssetsAccount*) util_singleton("CurrentAssetsAccount",id);
   if(ptr==NULL) {
      ptr = new CurrentAssetsAccount();
      ptr->init();
      util_singleton("CurrentAssetsAccount",id,ptr);
   }
	return ptr;
}

CurrentAssetsAccount* CurrentAssetsAccount::instance_fscan(string fname)	{
   return CurrentAssetsAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

CurrentAssetsAccount* CurrentAssetsAccount::__ptr_CurrentAssetsAccount = CurrentAssetsAccount::instance();

#endif

