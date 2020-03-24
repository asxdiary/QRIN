// Name:     PrepaidOtherCurrentAssetsAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_PrepaidOtherCurrentAssetsAccount_cpp
#define ASX_PrepaidOtherCurrentAssetsAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "PrepaidOtherCurrentAssetsAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

PrepaidOtherCurrentAssetsAccount::PrepaidOtherCurrentAssetsAccount() { init_NULL(); }
PrepaidOtherCurrentAssetsAccount::PrepaidOtherCurrentAssetsAccount(const PrepaidOtherCurrentAssetsAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
PrepaidOtherCurrentAssetsAccount::PrepaidOtherCurrentAssetsAccount(const PrepaidOtherCurrentAssetsAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void PrepaidOtherCurrentAssetsAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void PrepaidOtherCurrentAssetsAccount::init() {
   PositionAccount::init();
	init_PrepaidOtherCurrentAssetsAccount();
}

void PrepaidOtherCurrentAssetsAccount::init_PrepaidOtherCurrentAssetsAccount() {
   set_id("PrepaidOtherCurrentAssetsAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

PrepaidOtherCurrentAssetsAccount::~PrepaidOtherCurrentAssetsAccount()	{ cleanMem(); }

void PrepaidOtherCurrentAssetsAccount::cleanMem()	{
	cleanMem_PrepaidOtherCurrentAssetsAccount();
   PositionAccount::cleanMem();
}

void PrepaidOtherCurrentAssetsAccount::cleanMem_PrepaidOtherCurrentAssetsAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string PrepaidOtherCurrentAssetsAccount::className() const {return "PrepaidOtherCurrentAssetsAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void PrepaidOtherCurrentAssetsAccount::myerr_msg(string msg, string func) {
	err_msg("PrepaidOtherCurrentAssetsAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void PrepaidOtherCurrentAssetsAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_PrepaidOtherCurrentAssetsAccount(fname);
}

void PrepaidOtherCurrentAssetsAccount::fprint_PrepaidOtherCurrentAssetsAccount(string fname) {
}

void PrepaidOtherCurrentAssetsAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_PrepaidOtherCurrentAssetsAccount(fname);
}

void PrepaidOtherCurrentAssetsAccount::fscan_PrepaidOtherCurrentAssetsAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void PrepaidOtherCurrentAssetsAccount::reset() {
	reset_PrepaidOtherCurrentAssetsAccount();
   PositionAccount::reset();
}

void PrepaidOtherCurrentAssetsAccount::reset_PrepaidOtherCurrentAssetsAccount() {
}

/** ----------  static instance function -----------*/


PrepaidOtherCurrentAssetsAccount* PrepaidOtherCurrentAssetsAccount::instance()	{
	PrepaidOtherCurrentAssetsAccount* ptr = NULL;
   string id = "PrepaidOtherCurrentAssetsAccount";

   ptr = (PrepaidOtherCurrentAssetsAccount*) util_singleton("PrepaidOtherCurrentAssetsAccount",id);
   if(ptr==NULL) {
      ptr = new PrepaidOtherCurrentAssetsAccount();
      ptr->init();
      util_singleton("PrepaidOtherCurrentAssetsAccount",id,ptr);
   }
	return ptr;
}

PrepaidOtherCurrentAssetsAccount* PrepaidOtherCurrentAssetsAccount::instance_fscan(string fname)	{
   return PrepaidOtherCurrentAssetsAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

PrepaidOtherCurrentAssetsAccount* PrepaidOtherCurrentAssetsAccount::__ptr_PrepaidOtherCurrentAssetsAccount = PrepaidOtherCurrentAssetsAccount::instance();

#endif

