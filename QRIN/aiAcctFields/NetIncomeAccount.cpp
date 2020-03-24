// Name:     NetIncomeAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_NetIncomeAccount_cpp
#define ASX_NetIncomeAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "NetIncomeAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

NetIncomeAccount::NetIncomeAccount() { init_NULL(); }
NetIncomeAccount::NetIncomeAccount(const NetIncomeAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
NetIncomeAccount::NetIncomeAccount(const NetIncomeAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void NetIncomeAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void NetIncomeAccount::init() {
   FlowAccount::init();
	init_NetIncomeAccount();
}

void NetIncomeAccount::init_NetIncomeAccount() {
   set_id("NetIncomeAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

NetIncomeAccount::~NetIncomeAccount()	{ cleanMem(); }

void NetIncomeAccount::cleanMem()	{
	cleanMem_NetIncomeAccount();
   FlowAccount::cleanMem();
}

void NetIncomeAccount::cleanMem_NetIncomeAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string NetIncomeAccount::className() const {return "NetIncomeAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void NetIncomeAccount::myerr_msg(string msg, string func) {
	err_msg("NetIncomeAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void NetIncomeAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_NetIncomeAccount(fname);
}

void NetIncomeAccount::fprint_NetIncomeAccount(string fname) {
}

void NetIncomeAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_NetIncomeAccount(fname);
}

void NetIncomeAccount::fscan_NetIncomeAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void NetIncomeAccount::reset() {
	reset_NetIncomeAccount();
   FlowAccount::reset();
}

void NetIncomeAccount::reset_NetIncomeAccount() {
}

/** ----------  static instance function -----------*/


NetIncomeAccount* NetIncomeAccount::instance()	{
	NetIncomeAccount* ptr = NULL;
   string id = "NetIncomeAccount";

   ptr = (NetIncomeAccount*) util_singleton("NetIncomeAccount",id);
   if(ptr==NULL) {
      ptr = new NetIncomeAccount();
      ptr->init();
      util_singleton("NetIncomeAccount",id,ptr);
   }
	return ptr;
}

NetIncomeAccount* NetIncomeAccount::instance_fscan(string fname)	{
   return NetIncomeAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

NetIncomeAccount* NetIncomeAccount::__ptr_NetIncomeAccount = NetIncomeAccount::instance();

#endif

