// Name:     EPSdilutedAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_EPSdilutedAccount_cpp
#define ASX_EPSdilutedAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "EPSdilutedAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

EPSdilutedAccount::EPSdilutedAccount() { init_NULL(); }
EPSdilutedAccount::EPSdilutedAccount(const EPSdilutedAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
EPSdilutedAccount::EPSdilutedAccount(const EPSdilutedAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void EPSdilutedAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void EPSdilutedAccount::init() {
   FlowAccount::init();
	init_EPSdilutedAccount();
}

void EPSdilutedAccount::init_EPSdilutedAccount() {
   set_id("EPSdilutedAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

EPSdilutedAccount::~EPSdilutedAccount()	{ cleanMem(); }

void EPSdilutedAccount::cleanMem()	{
	cleanMem_EPSdilutedAccount();
   FlowAccount::cleanMem();
}

void EPSdilutedAccount::cleanMem_EPSdilutedAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string EPSdilutedAccount::className() const {return "EPSdilutedAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void EPSdilutedAccount::myerr_msg(string msg, string func) {
	err_msg("EPSdilutedAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void EPSdilutedAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_EPSdilutedAccount(fname);
}

void EPSdilutedAccount::fprint_EPSdilutedAccount(string fname) {
}

void EPSdilutedAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_EPSdilutedAccount(fname);
}

void EPSdilutedAccount::fscan_EPSdilutedAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void EPSdilutedAccount::reset() {
	reset_EPSdilutedAccount();
   FlowAccount::reset();
}

void EPSdilutedAccount::reset_EPSdilutedAccount() {
}

/** ----------  static instance function -----------*/


EPSdilutedAccount* EPSdilutedAccount::instance()	{
	EPSdilutedAccount* ptr = NULL;
   string id = "EPSdilutedAccount";

   ptr = (EPSdilutedAccount*) util_singleton("EPSdilutedAccount",id);
   if(ptr==NULL) {
      ptr = new EPSdilutedAccount();
      ptr->init();
      util_singleton("EPSdilutedAccount",id,ptr);
   }
	return ptr;
}

EPSdilutedAccount* EPSdilutedAccount::instance_fscan(string fname)	{
   return EPSdilutedAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

EPSdilutedAccount* EPSdilutedAccount::__ptr_EPSdilutedAccount = EPSdilutedAccount::instance();

#endif

