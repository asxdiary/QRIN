// Name:     NetMarginAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_NetMarginAccount_cpp
#define ASX_NetMarginAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "R_DoubleDbAccount.hpp"
#include "NetIncomeAccount.hpp"
#include "OperatingRevenueAccount.hpp"
#include "NetMarginAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctFields;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

NetMarginAccount::NetMarginAccount() { init_NULL(); }
NetMarginAccount::NetMarginAccount(const NetMarginAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
NetMarginAccount::NetMarginAccount(const NetMarginAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void NetMarginAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void NetMarginAccount::init() {
   R_DoubleDbAccount::init(NetIncomeAccount::instance(),
                      OperatingRevenueAccount::instance(),
                      false, false);
	init_NetMarginAccount();
}

void NetMarginAccount::init_NetMarginAccount() {
   set_id("NetMarginAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

NetMarginAccount::~NetMarginAccount()	{ cleanMem(); }

void NetMarginAccount::cleanMem()	{
	cleanMem_NetMarginAccount();
   R_DoubleDbAccount::cleanMem();
}

void NetMarginAccount::cleanMem_NetMarginAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string NetMarginAccount::className() const {return "NetMarginAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void NetMarginAccount::myerr_msg(string msg, string func) {
	err_msg("NetMarginAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void NetMarginAccount::fprint(string fname) {
   R_DoubleDbAccount::fprint(fname);
	fprint_NetMarginAccount(fname);
}

void NetMarginAccount::fprint_NetMarginAccount(string fname) {
}

void NetMarginAccount::fscan(string fname) {
   R_DoubleDbAccount::fscan(fname);
	fscan_NetMarginAccount(fname);
}

void NetMarginAccount::fscan_NetMarginAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void NetMarginAccount::reset() {
	reset_NetMarginAccount();
   R_DoubleDbAccount::reset();
}

void NetMarginAccount::reset_NetMarginAccount() {
}

/** ----------  static instance function -----------*/


NetMarginAccount* NetMarginAccount::instance()	{
	NetMarginAccount* ptr = NULL;
   string id = "NetMarginAccount";

   ptr = (NetMarginAccount*) util_singleton("NetMarginAccount",id);
   if(ptr==NULL) {
      ptr = new NetMarginAccount();
      ptr->init();
      util_singleton("NetMarginAccount",id,ptr);
   }
	return ptr;
}

NetMarginAccount* NetMarginAccount::instance_fscan(string fname)	{
   return NetMarginAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

NetMarginAccount* NetMarginAccount::__ptr_NetMarginAccount = NetMarginAccount::instance();

#endif

