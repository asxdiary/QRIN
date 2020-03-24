// Name:     NetCashFlowsProvidedUsedInvestingActivitiesAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_NetCashFlowsProvidedUsedInvestingActivitiesAccount_cpp
#define ASX_NetCashFlowsProvidedUsedInvestingActivitiesAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "NetCashFlowsProvidedUsedInvestingActivitiesAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

NetCashFlowsProvidedUsedInvestingActivitiesAccount::NetCashFlowsProvidedUsedInvestingActivitiesAccount() { init_NULL(); }
NetCashFlowsProvidedUsedInvestingActivitiesAccount::NetCashFlowsProvidedUsedInvestingActivitiesAccount(const NetCashFlowsProvidedUsedInvestingActivitiesAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
NetCashFlowsProvidedUsedInvestingActivitiesAccount::NetCashFlowsProvidedUsedInvestingActivitiesAccount(const NetCashFlowsProvidedUsedInvestingActivitiesAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void NetCashFlowsProvidedUsedInvestingActivitiesAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void NetCashFlowsProvidedUsedInvestingActivitiesAccount::init() {
   FlowAccount::init();
	init_NetCashFlowsProvidedUsedInvestingActivitiesAccount();
}

void NetCashFlowsProvidedUsedInvestingActivitiesAccount::init_NetCashFlowsProvidedUsedInvestingActivitiesAccount() {
   set_id("NetCashFlowsProvidedUsedInvestingActivitiesAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

NetCashFlowsProvidedUsedInvestingActivitiesAccount::~NetCashFlowsProvidedUsedInvestingActivitiesAccount()	{ cleanMem(); }

void NetCashFlowsProvidedUsedInvestingActivitiesAccount::cleanMem()	{
	cleanMem_NetCashFlowsProvidedUsedInvestingActivitiesAccount();
   FlowAccount::cleanMem();
}

void NetCashFlowsProvidedUsedInvestingActivitiesAccount::cleanMem_NetCashFlowsProvidedUsedInvestingActivitiesAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string NetCashFlowsProvidedUsedInvestingActivitiesAccount::className() const {return "NetCashFlowsProvidedUsedInvestingActivitiesAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void NetCashFlowsProvidedUsedInvestingActivitiesAccount::myerr_msg(string msg, string func) {
	err_msg("NetCashFlowsProvidedUsedInvestingActivitiesAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void NetCashFlowsProvidedUsedInvestingActivitiesAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_NetCashFlowsProvidedUsedInvestingActivitiesAccount(fname);
}

void NetCashFlowsProvidedUsedInvestingActivitiesAccount::fprint_NetCashFlowsProvidedUsedInvestingActivitiesAccount(string fname) {
}

void NetCashFlowsProvidedUsedInvestingActivitiesAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_NetCashFlowsProvidedUsedInvestingActivitiesAccount(fname);
}

void NetCashFlowsProvidedUsedInvestingActivitiesAccount::fscan_NetCashFlowsProvidedUsedInvestingActivitiesAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void NetCashFlowsProvidedUsedInvestingActivitiesAccount::reset() {
	reset_NetCashFlowsProvidedUsedInvestingActivitiesAccount();
   FlowAccount::reset();
}

void NetCashFlowsProvidedUsedInvestingActivitiesAccount::reset_NetCashFlowsProvidedUsedInvestingActivitiesAccount() {
}

/** ----------  static instance function -----------*/


NetCashFlowsProvidedUsedInvestingActivitiesAccount* NetCashFlowsProvidedUsedInvestingActivitiesAccount::instance()	{
	NetCashFlowsProvidedUsedInvestingActivitiesAccount* ptr = NULL;
   string id = "NetCashFlowsProvidedUsedInvestingActivitiesAccount";

   ptr = (NetCashFlowsProvidedUsedInvestingActivitiesAccount*) util_singleton("NetCashFlowsProvidedUsedInvestingActivitiesAccount",id);
   if(ptr==NULL) {
      ptr = new NetCashFlowsProvidedUsedInvestingActivitiesAccount();
      ptr->init();
      util_singleton("NetCashFlowsProvidedUsedInvestingActivitiesAccount",id,ptr);
   }
	return ptr;
}

NetCashFlowsProvidedUsedInvestingActivitiesAccount* NetCashFlowsProvidedUsedInvestingActivitiesAccount::instance_fscan(string fname)	{
   return NetCashFlowsProvidedUsedInvestingActivitiesAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

NetCashFlowsProvidedUsedInvestingActivitiesAccount* NetCashFlowsProvidedUsedInvestingActivitiesAccount::__ptr_NetCashFlowsProvidedUsedInvestingActivitiesAccount = NetCashFlowsProvidedUsedInvestingActivitiesAccount::instance();

#endif

