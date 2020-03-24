// Name:     CostRevenueAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CostRevenueAccount_cpp
#define ASX_CostRevenueAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "CostRevenueAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

CostRevenueAccount::CostRevenueAccount() { init_NULL(); }
CostRevenueAccount::CostRevenueAccount(const CostRevenueAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
CostRevenueAccount::CostRevenueAccount(const CostRevenueAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void CostRevenueAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void CostRevenueAccount::init() {
   FlowAccount::init();
	init_CostRevenueAccount();
}

void CostRevenueAccount::init_CostRevenueAccount() {
   set_id("CostRevenueAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

CostRevenueAccount::~CostRevenueAccount()	{ cleanMem(); }

void CostRevenueAccount::cleanMem()	{
	cleanMem_CostRevenueAccount();
   FlowAccount::cleanMem();
}

void CostRevenueAccount::cleanMem_CostRevenueAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string CostRevenueAccount::className() const {return "CostRevenueAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void CostRevenueAccount::myerr_msg(string msg, string func) {
	err_msg("CostRevenueAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void CostRevenueAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_CostRevenueAccount(fname);
}

void CostRevenueAccount::fprint_CostRevenueAccount(string fname) {
}

void CostRevenueAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_CostRevenueAccount(fname);
}

void CostRevenueAccount::fscan_CostRevenueAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void CostRevenueAccount::reset() {
	reset_CostRevenueAccount();
   FlowAccount::reset();
}

void CostRevenueAccount::reset_CostRevenueAccount() {
}

/** ----------  static instance function -----------*/


CostRevenueAccount* CostRevenueAccount::instance()	{
	CostRevenueAccount* ptr = NULL;
   string id = "CostRevenueAccount";

   ptr = (CostRevenueAccount*) util_singleton("CostRevenueAccount",id);
   if(ptr==NULL) {
      ptr = new CostRevenueAccount();
      ptr->init();
      util_singleton("CostRevenueAccount",id,ptr);
   }
	return ptr;
}

CostRevenueAccount* CostRevenueAccount::instance_fscan(string fname)	{
   return CostRevenueAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

CostRevenueAccount* CostRevenueAccount::__ptr_CostRevenueAccount = CostRevenueAccount::instance();

#endif

