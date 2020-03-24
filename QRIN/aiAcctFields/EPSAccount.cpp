// Name:     EPSAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_EPSAccount_cpp
#define ASX_EPSAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "EPSAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

EPSAccount::EPSAccount() { init_NULL(); }
EPSAccount::EPSAccount(const EPSAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
EPSAccount::EPSAccount(const EPSAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void EPSAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void EPSAccount::init() {
   FlowAccount::init();
	init_EPSAccount();
}

void EPSAccount::init_EPSAccount() {
   set_id("EPSAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

EPSAccount::~EPSAccount()	{ cleanMem(); }

void EPSAccount::cleanMem()	{
	cleanMem_EPSAccount();
   FlowAccount::cleanMem();
}

void EPSAccount::cleanMem_EPSAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string EPSAccount::className() const {return "EPSAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void EPSAccount::myerr_msg(string msg, string func) {
	err_msg("EPSAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void EPSAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_EPSAccount(fname);
}

void EPSAccount::fprint_EPSAccount(string fname) {
}

void EPSAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_EPSAccount(fname);
}

void EPSAccount::fscan_EPSAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void EPSAccount::reset() {
	reset_EPSAccount();
   FlowAccount::reset();
}

void EPSAccount::reset_EPSAccount() {
}

/** ----------  static instance function -----------*/


EPSAccount* EPSAccount::instance()	{
	EPSAccount* ptr = NULL;
   string id = "EPSAccount";

   ptr = (EPSAccount*) util_singleton("EPSAccount",id);
   if(ptr==NULL) {
      ptr = new EPSAccount();
      ptr->init();
      util_singleton("EPSAccount",id,ptr);
   }
	return ptr;
}

EPSAccount* EPSAccount::instance_fscan(string fname)	{
   return EPSAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

EPSAccount* EPSAccount::__ptr_EPSAccount = EPSAccount::instance();

#endif

