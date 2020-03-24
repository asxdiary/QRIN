// Name:     NetInterestExpenseAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_NetInterestExpenseAccount_cpp
#define ASX_NetInterestExpenseAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "NetInterestExpenseAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

NetInterestExpenseAccount::NetInterestExpenseAccount() { init_NULL(); }
NetInterestExpenseAccount::NetInterestExpenseAccount(const NetInterestExpenseAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
NetInterestExpenseAccount::NetInterestExpenseAccount(const NetInterestExpenseAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void NetInterestExpenseAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void NetInterestExpenseAccount::init() {
   FlowAccount::init();
	init_NetInterestExpenseAccount();
}

void NetInterestExpenseAccount::init_NetInterestExpenseAccount() {
   set_id("NetInterestExpenseAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

NetInterestExpenseAccount::~NetInterestExpenseAccount()	{ cleanMem(); }

void NetInterestExpenseAccount::cleanMem()	{
	cleanMem_NetInterestExpenseAccount();
   FlowAccount::cleanMem();
}

void NetInterestExpenseAccount::cleanMem_NetInterestExpenseAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string NetInterestExpenseAccount::className() const {return "NetInterestExpenseAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void NetInterestExpenseAccount::myerr_msg(string msg, string func) {
	err_msg("NetInterestExpenseAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void NetInterestExpenseAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_NetInterestExpenseAccount(fname);
}

void NetInterestExpenseAccount::fprint_NetInterestExpenseAccount(string fname) {
}

void NetInterestExpenseAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_NetInterestExpenseAccount(fname);
}

void NetInterestExpenseAccount::fscan_NetInterestExpenseAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void NetInterestExpenseAccount::reset() {
	reset_NetInterestExpenseAccount();
   FlowAccount::reset();
}

void NetInterestExpenseAccount::reset_NetInterestExpenseAccount() {
}

/** ----------  static instance function -----------*/


NetInterestExpenseAccount* NetInterestExpenseAccount::instance()	{
	NetInterestExpenseAccount* ptr = NULL;
   string id = "NetInterestExpenseAccount";

   ptr = (NetInterestExpenseAccount*) util_singleton("NetInterestExpenseAccount",id);
   if(ptr==NULL) {
      ptr = new NetInterestExpenseAccount();
      ptr->init();
      util_singleton("NetInterestExpenseAccount",id,ptr);
   }
	return ptr;
}

NetInterestExpenseAccount* NetInterestExpenseAccount::instance_fscan(string fname)	{
   return NetInterestExpenseAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

NetInterestExpenseAccount* NetInterestExpenseAccount::__ptr_NetInterestExpenseAccount = NetInterestExpenseAccount::instance();

#endif

