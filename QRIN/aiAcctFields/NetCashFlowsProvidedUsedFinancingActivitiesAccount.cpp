// Name:     NetCashFlowsProvidedUsedFinancingActivitiesAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_NetCashFlowsProvidedUsedFinancingActivitiesAccount_cpp
#define ASX_NetCashFlowsProvidedUsedFinancingActivitiesAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "NetCashFlowsProvidedUsedFinancingActivitiesAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

NetCashFlowsProvidedUsedFinancingActivitiesAccount::NetCashFlowsProvidedUsedFinancingActivitiesAccount() { init_NULL(); }
NetCashFlowsProvidedUsedFinancingActivitiesAccount::NetCashFlowsProvidedUsedFinancingActivitiesAccount(const NetCashFlowsProvidedUsedFinancingActivitiesAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
NetCashFlowsProvidedUsedFinancingActivitiesAccount::NetCashFlowsProvidedUsedFinancingActivitiesAccount(const NetCashFlowsProvidedUsedFinancingActivitiesAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void NetCashFlowsProvidedUsedFinancingActivitiesAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void NetCashFlowsProvidedUsedFinancingActivitiesAccount::init() {
   FlowAccount::init();
	init_NetCashFlowsProvidedUsedFinancingActivitiesAccount();
}

void NetCashFlowsProvidedUsedFinancingActivitiesAccount::init_NetCashFlowsProvidedUsedFinancingActivitiesAccount() {
   set_id("NetCashFlowsProvidedUsedFinancingActivitiesAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

NetCashFlowsProvidedUsedFinancingActivitiesAccount::~NetCashFlowsProvidedUsedFinancingActivitiesAccount()	{ cleanMem(); }

void NetCashFlowsProvidedUsedFinancingActivitiesAccount::cleanMem()	{
	cleanMem_NetCashFlowsProvidedUsedFinancingActivitiesAccount();
   FlowAccount::cleanMem();
}

void NetCashFlowsProvidedUsedFinancingActivitiesAccount::cleanMem_NetCashFlowsProvidedUsedFinancingActivitiesAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string NetCashFlowsProvidedUsedFinancingActivitiesAccount::className() const {return "NetCashFlowsProvidedUsedFinancingActivitiesAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void NetCashFlowsProvidedUsedFinancingActivitiesAccount::myerr_msg(string msg, string func) {
	err_msg("NetCashFlowsProvidedUsedFinancingActivitiesAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void NetCashFlowsProvidedUsedFinancingActivitiesAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_NetCashFlowsProvidedUsedFinancingActivitiesAccount(fname);
}

void NetCashFlowsProvidedUsedFinancingActivitiesAccount::fprint_NetCashFlowsProvidedUsedFinancingActivitiesAccount(string fname) {
}

void NetCashFlowsProvidedUsedFinancingActivitiesAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_NetCashFlowsProvidedUsedFinancingActivitiesAccount(fname);
}

void NetCashFlowsProvidedUsedFinancingActivitiesAccount::fscan_NetCashFlowsProvidedUsedFinancingActivitiesAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void NetCashFlowsProvidedUsedFinancingActivitiesAccount::reset() {
	reset_NetCashFlowsProvidedUsedFinancingActivitiesAccount();
   FlowAccount::reset();
}

void NetCashFlowsProvidedUsedFinancingActivitiesAccount::reset_NetCashFlowsProvidedUsedFinancingActivitiesAccount() {
}

/** ----------  static instance function -----------*/


NetCashFlowsProvidedUsedFinancingActivitiesAccount* NetCashFlowsProvidedUsedFinancingActivitiesAccount::instance()	{
	NetCashFlowsProvidedUsedFinancingActivitiesAccount* ptr = NULL;
   string id = "NetCashFlowsProvidedUsedFinancingActivitiesAccount";

   ptr = (NetCashFlowsProvidedUsedFinancingActivitiesAccount*) util_singleton("NetCashFlowsProvidedUsedFinancingActivitiesAccount",id);
   if(ptr==NULL) {
      ptr = new NetCashFlowsProvidedUsedFinancingActivitiesAccount();
      ptr->init();
      util_singleton("NetCashFlowsProvidedUsedFinancingActivitiesAccount",id,ptr);
   }
	return ptr;
}

NetCashFlowsProvidedUsedFinancingActivitiesAccount* NetCashFlowsProvidedUsedFinancingActivitiesAccount::instance_fscan(string fname)	{
   return NetCashFlowsProvidedUsedFinancingActivitiesAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

NetCashFlowsProvidedUsedFinancingActivitiesAccount* NetCashFlowsProvidedUsedFinancingActivitiesAccount::__ptr_NetCashFlowsProvidedUsedFinancingActivitiesAccount = NetCashFlowsProvidedUsedFinancingActivitiesAccount::instance();

#endif

