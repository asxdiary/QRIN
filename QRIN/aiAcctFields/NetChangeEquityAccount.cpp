// Name:     NetChangeEquityAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_NetChangeEquityAccount_cpp
#define ASX_NetChangeEquityAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "NetChangeEquityAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

NetChangeEquityAccount::NetChangeEquityAccount() { init_NULL(); }
NetChangeEquityAccount::NetChangeEquityAccount(const NetChangeEquityAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
NetChangeEquityAccount::NetChangeEquityAccount(const NetChangeEquityAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void NetChangeEquityAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void NetChangeEquityAccount::init() {
   FlowAccount::init();
	init_NetChangeEquityAccount();
}

void NetChangeEquityAccount::init_NetChangeEquityAccount() {
   set_id("NetChangeEquityAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

NetChangeEquityAccount::~NetChangeEquityAccount()	{ cleanMem(); }

void NetChangeEquityAccount::cleanMem()	{
	cleanMem_NetChangeEquityAccount();
   FlowAccount::cleanMem();
}

void NetChangeEquityAccount::cleanMem_NetChangeEquityAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string NetChangeEquityAccount::className() const {return "NetChangeEquityAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void NetChangeEquityAccount::myerr_msg(string msg, string func) {
	err_msg("NetChangeEquityAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void NetChangeEquityAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_NetChangeEquityAccount(fname);
}

void NetChangeEquityAccount::fprint_NetChangeEquityAccount(string fname) {
}

void NetChangeEquityAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_NetChangeEquityAccount(fname);
}

void NetChangeEquityAccount::fscan_NetChangeEquityAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void NetChangeEquityAccount::reset() {
	reset_NetChangeEquityAccount();
   FlowAccount::reset();
}

void NetChangeEquityAccount::reset_NetChangeEquityAccount() {
}

/** ----------  static instance function -----------*/


NetChangeEquityAccount* NetChangeEquityAccount::instance()	{
	NetChangeEquityAccount* ptr = NULL;
   string id = "NetChangeEquityAccount";

   ptr = (NetChangeEquityAccount*) util_singleton("NetChangeEquityAccount",id);
   if(ptr==NULL) {
      ptr = new NetChangeEquityAccount();
      ptr->init();
      util_singleton("NetChangeEquityAccount",id,ptr);
   }
	return ptr;
}

NetChangeEquityAccount* NetChangeEquityAccount::instance_fscan(string fname)	{
   return NetChangeEquityAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

NetChangeEquityAccount* NetChangeEquityAccount::__ptr_NetChangeEquityAccount = NetChangeEquityAccount::instance();

#endif

