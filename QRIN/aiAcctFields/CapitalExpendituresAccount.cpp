// Name:     CapitalExpendituresAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CapitalExpendituresAccount_cpp
#define ASX_CapitalExpendituresAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "CapitalExpendituresAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

CapitalExpendituresAccount::CapitalExpendituresAccount() { init_NULL(); }
CapitalExpendituresAccount::CapitalExpendituresAccount(const CapitalExpendituresAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
CapitalExpendituresAccount::CapitalExpendituresAccount(const CapitalExpendituresAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void CapitalExpendituresAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void CapitalExpendituresAccount::init() {
   FlowAccount::init();
	init_CapitalExpendituresAccount();
}

void CapitalExpendituresAccount::init_CapitalExpendituresAccount() {
   set_id("CapitalExpendituresAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

CapitalExpendituresAccount::~CapitalExpendituresAccount()	{ cleanMem(); }

void CapitalExpendituresAccount::cleanMem()	{
	cleanMem_CapitalExpendituresAccount();
   FlowAccount::cleanMem();
}

void CapitalExpendituresAccount::cleanMem_CapitalExpendituresAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string CapitalExpendituresAccount::className() const {return "CapitalExpendituresAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void CapitalExpendituresAccount::myerr_msg(string msg, string func) {
	err_msg("CapitalExpendituresAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void CapitalExpendituresAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_CapitalExpendituresAccount(fname);
}

void CapitalExpendituresAccount::fprint_CapitalExpendituresAccount(string fname) {
}

void CapitalExpendituresAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_CapitalExpendituresAccount(fname);
}

void CapitalExpendituresAccount::fscan_CapitalExpendituresAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void CapitalExpendituresAccount::reset() {
	reset_CapitalExpendituresAccount();
   FlowAccount::reset();
}

void CapitalExpendituresAccount::reset_CapitalExpendituresAccount() {
}

/** ----------  static instance function -----------*/


CapitalExpendituresAccount* CapitalExpendituresAccount::instance()	{
	CapitalExpendituresAccount* ptr = NULL;
   string id = "CapitalExpendituresAccount";

   ptr = (CapitalExpendituresAccount*) util_singleton("CapitalExpendituresAccount",id);
   if(ptr==NULL) {
      ptr = new CapitalExpendituresAccount();
      ptr->init();
      util_singleton("CapitalExpendituresAccount",id,ptr);
   }
	return ptr;
}

CapitalExpendituresAccount* CapitalExpendituresAccount::instance_fscan(string fname)	{
   return CapitalExpendituresAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

CapitalExpendituresAccount* CapitalExpendituresAccount::__ptr_CapitalExpendituresAccount = CapitalExpendituresAccount::instance();

#endif

