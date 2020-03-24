// Name:     OtherCashFlowsFinancingActivitiesNetAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_OtherCashFlowsFinancingActivitiesNetAccount_cpp
#define ASX_OtherCashFlowsFinancingActivitiesNetAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "OtherCashFlowsFinancingActivitiesNetAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

OtherCashFlowsFinancingActivitiesNetAccount::OtherCashFlowsFinancingActivitiesNetAccount() { init_NULL(); }
OtherCashFlowsFinancingActivitiesNetAccount::OtherCashFlowsFinancingActivitiesNetAccount(const OtherCashFlowsFinancingActivitiesNetAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
OtherCashFlowsFinancingActivitiesNetAccount::OtherCashFlowsFinancingActivitiesNetAccount(const OtherCashFlowsFinancingActivitiesNetAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void OtherCashFlowsFinancingActivitiesNetAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void OtherCashFlowsFinancingActivitiesNetAccount::init() {
   FlowAccount::init();
	init_OtherCashFlowsFinancingActivitiesNetAccount();
}

void OtherCashFlowsFinancingActivitiesNetAccount::init_OtherCashFlowsFinancingActivitiesNetAccount() {
   set_id("OtherCashFlowsFinancingActivitiesNetAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

OtherCashFlowsFinancingActivitiesNetAccount::~OtherCashFlowsFinancingActivitiesNetAccount()	{ cleanMem(); }

void OtherCashFlowsFinancingActivitiesNetAccount::cleanMem()	{
	cleanMem_OtherCashFlowsFinancingActivitiesNetAccount();
   FlowAccount::cleanMem();
}

void OtherCashFlowsFinancingActivitiesNetAccount::cleanMem_OtherCashFlowsFinancingActivitiesNetAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string OtherCashFlowsFinancingActivitiesNetAccount::className() const {return "OtherCashFlowsFinancingActivitiesNetAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void OtherCashFlowsFinancingActivitiesNetAccount::myerr_msg(string msg, string func) {
	err_msg("OtherCashFlowsFinancingActivitiesNetAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void OtherCashFlowsFinancingActivitiesNetAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_OtherCashFlowsFinancingActivitiesNetAccount(fname);
}

void OtherCashFlowsFinancingActivitiesNetAccount::fprint_OtherCashFlowsFinancingActivitiesNetAccount(string fname) {
}

void OtherCashFlowsFinancingActivitiesNetAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_OtherCashFlowsFinancingActivitiesNetAccount(fname);
}

void OtherCashFlowsFinancingActivitiesNetAccount::fscan_OtherCashFlowsFinancingActivitiesNetAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void OtherCashFlowsFinancingActivitiesNetAccount::reset() {
	reset_OtherCashFlowsFinancingActivitiesNetAccount();
   FlowAccount::reset();
}

void OtherCashFlowsFinancingActivitiesNetAccount::reset_OtherCashFlowsFinancingActivitiesNetAccount() {
}

/** ----------  static instance function -----------*/


OtherCashFlowsFinancingActivitiesNetAccount* OtherCashFlowsFinancingActivitiesNetAccount::instance()	{
	OtherCashFlowsFinancingActivitiesNetAccount* ptr = NULL;
   string id = "OtherCashFlowsFinancingActivitiesNetAccount";

   ptr = (OtherCashFlowsFinancingActivitiesNetAccount*) util_singleton("OtherCashFlowsFinancingActivitiesNetAccount",id);
   if(ptr==NULL) {
      ptr = new OtherCashFlowsFinancingActivitiesNetAccount();
      ptr->init();
      util_singleton("OtherCashFlowsFinancingActivitiesNetAccount",id,ptr);
   }
	return ptr;
}

OtherCashFlowsFinancingActivitiesNetAccount* OtherCashFlowsFinancingActivitiesNetAccount::instance_fscan(string fname)	{
   return OtherCashFlowsFinancingActivitiesNetAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

OtherCashFlowsFinancingActivitiesNetAccount* OtherCashFlowsFinancingActivitiesNetAccount::__ptr_OtherCashFlowsFinancingActivitiesNetAccount = OtherCashFlowsFinancingActivitiesNetAccount::instance();

#endif

