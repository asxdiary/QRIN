// Name:     NetChangeDebtAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_NetChangeDebtAccount_cpp
#define ASX_NetChangeDebtAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "NetChangeDebtAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

NetChangeDebtAccount::NetChangeDebtAccount() { init_NULL(); }
NetChangeDebtAccount::NetChangeDebtAccount(const NetChangeDebtAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
NetChangeDebtAccount::NetChangeDebtAccount(const NetChangeDebtAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void NetChangeDebtAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void NetChangeDebtAccount::init() {
   FlowAccount::init();
	init_NetChangeDebtAccount();
}

void NetChangeDebtAccount::init_NetChangeDebtAccount() {
   set_id("NetChangeDebtAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

NetChangeDebtAccount::~NetChangeDebtAccount()	{ cleanMem(); }

void NetChangeDebtAccount::cleanMem()	{
	cleanMem_NetChangeDebtAccount();
   FlowAccount::cleanMem();
}

void NetChangeDebtAccount::cleanMem_NetChangeDebtAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string NetChangeDebtAccount::className() const {return "NetChangeDebtAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void NetChangeDebtAccount::myerr_msg(string msg, string func) {
	err_msg("NetChangeDebtAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void NetChangeDebtAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_NetChangeDebtAccount(fname);
}

void NetChangeDebtAccount::fprint_NetChangeDebtAccount(string fname) {
}

void NetChangeDebtAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_NetChangeDebtAccount(fname);
}

void NetChangeDebtAccount::fscan_NetChangeDebtAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void NetChangeDebtAccount::reset() {
	reset_NetChangeDebtAccount();
   FlowAccount::reset();
}

void NetChangeDebtAccount::reset_NetChangeDebtAccount() {
}

/** ----------  static instance function -----------*/


NetChangeDebtAccount* NetChangeDebtAccount::instance()	{
	NetChangeDebtAccount* ptr = NULL;
   string id = "NetChangeDebtAccount";

   ptr = (NetChangeDebtAccount*) util_singleton("NetChangeDebtAccount",id);
   if(ptr==NULL) {
      ptr = new NetChangeDebtAccount();
      ptr->init();
      util_singleton("NetChangeDebtAccount",id,ptr);
   }
	return ptr;
}

NetChangeDebtAccount* NetChangeDebtAccount::instance_fscan(string fname)	{
   return NetChangeDebtAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

NetChangeDebtAccount* NetChangeDebtAccount::__ptr_NetChangeDebtAccount = NetChangeDebtAccount::instance();

#endif

