// Name:     SGAOtherOperatingAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_SGAOtherOperatingAccount_cpp
#define ASX_SGAOtherOperatingAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "SGAOtherOperatingAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

SGAOtherOperatingAccount::SGAOtherOperatingAccount() { init_NULL(); }
SGAOtherOperatingAccount::SGAOtherOperatingAccount(const SGAOtherOperatingAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
SGAOtherOperatingAccount::SGAOtherOperatingAccount(const SGAOtherOperatingAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void SGAOtherOperatingAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void SGAOtherOperatingAccount::init() {
   FlowAccount::init();
	init_SGAOtherOperatingAccount();
}

void SGAOtherOperatingAccount::init_SGAOtherOperatingAccount() {
   set_id("SGAOtherOperatingAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

SGAOtherOperatingAccount::~SGAOtherOperatingAccount()	{ cleanMem(); }

void SGAOtherOperatingAccount::cleanMem()	{
	cleanMem_SGAOtherOperatingAccount();
   FlowAccount::cleanMem();
}

void SGAOtherOperatingAccount::cleanMem_SGAOtherOperatingAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string SGAOtherOperatingAccount::className() const {return "SGAOtherOperatingAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void SGAOtherOperatingAccount::myerr_msg(string msg, string func) {
	err_msg("SGAOtherOperatingAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void SGAOtherOperatingAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_SGAOtherOperatingAccount(fname);
}

void SGAOtherOperatingAccount::fprint_SGAOtherOperatingAccount(string fname) {
}

void SGAOtherOperatingAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_SGAOtherOperatingAccount(fname);
}

void SGAOtherOperatingAccount::fscan_SGAOtherOperatingAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void SGAOtherOperatingAccount::reset() {
	reset_SGAOtherOperatingAccount();
   FlowAccount::reset();
}

void SGAOtherOperatingAccount::reset_SGAOtherOperatingAccount() {
}

/** ----------  static instance function -----------*/


SGAOtherOperatingAccount* SGAOtherOperatingAccount::instance()	{
	SGAOtherOperatingAccount* ptr = NULL;
   string id = "SGAOtherOperatingAccount";

   ptr = (SGAOtherOperatingAccount*) util_singleton("SGAOtherOperatingAccount",id);
   if(ptr==NULL) {
      ptr = new SGAOtherOperatingAccount();
      ptr->init();
      util_singleton("SGAOtherOperatingAccount",id,ptr);
   }
	return ptr;
}

SGAOtherOperatingAccount* SGAOtherOperatingAccount::instance_fscan(string fname)	{
   return SGAOtherOperatingAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

SGAOtherOperatingAccount* SGAOtherOperatingAccount::__ptr_SGAOtherOperatingAccount = SGAOtherOperatingAccount::instance();

#endif

