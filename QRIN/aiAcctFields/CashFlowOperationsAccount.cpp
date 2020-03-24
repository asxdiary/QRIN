// Name:     CashFlowOperationsAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CashFlowOperationsAccount_cpp
#define ASX_CashFlowOperationsAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "CashFlowOperationsAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

CashFlowOperationsAccount::CashFlowOperationsAccount() { init_NULL(); }
CashFlowOperationsAccount::CashFlowOperationsAccount(const CashFlowOperationsAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
CashFlowOperationsAccount::CashFlowOperationsAccount(const CashFlowOperationsAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void CashFlowOperationsAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void CashFlowOperationsAccount::init() {
   FlowAccount::init();
	init_CashFlowOperationsAccount();
}

void CashFlowOperationsAccount::init_CashFlowOperationsAccount() {
   set_id("CashFlowOperationsAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

CashFlowOperationsAccount::~CashFlowOperationsAccount()	{ cleanMem(); }

void CashFlowOperationsAccount::cleanMem()	{
	cleanMem_CashFlowOperationsAccount();
   FlowAccount::cleanMem();
}

void CashFlowOperationsAccount::cleanMem_CashFlowOperationsAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string CashFlowOperationsAccount::className() const {return "CashFlowOperationsAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void CashFlowOperationsAccount::myerr_msg(string msg, string func) {
	err_msg("CashFlowOperationsAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void CashFlowOperationsAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_CashFlowOperationsAccount(fname);
}

void CashFlowOperationsAccount::fprint_CashFlowOperationsAccount(string fname) {
}

void CashFlowOperationsAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_CashFlowOperationsAccount(fname);
}

void CashFlowOperationsAccount::fscan_CashFlowOperationsAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void CashFlowOperationsAccount::reset() {
	reset_CashFlowOperationsAccount();
   FlowAccount::reset();
}

void CashFlowOperationsAccount::reset_CashFlowOperationsAccount() {
}

/** ----------  static instance function -----------*/


CashFlowOperationsAccount* CashFlowOperationsAccount::instance()	{
	CashFlowOperationsAccount* ptr = NULL;
   string id = "CashFlowOperationsAccount";

   ptr = (CashFlowOperationsAccount*) util_singleton("CashFlowOperationsAccount",id);
   if(ptr==NULL) {
      ptr = new CashFlowOperationsAccount();
      ptr->init();
      util_singleton("CashFlowOperationsAccount",id,ptr);
   }
	return ptr;
}

CashFlowOperationsAccount* CashFlowOperationsAccount::instance_fscan(string fname)	{
   return CashFlowOperationsAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

CashFlowOperationsAccount* CashFlowOperationsAccount::__ptr_CashFlowOperationsAccount = CashFlowOperationsAccount::instance();

#endif

