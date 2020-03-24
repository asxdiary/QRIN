// Name:     CashShortTermInvestmentsAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CashShortTermInvestmentsAccount_cpp
#define ASX_CashShortTermInvestmentsAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "CashShortTermInvestmentsAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

CashShortTermInvestmentsAccount::CashShortTermInvestmentsAccount() { init_NULL(); }
CashShortTermInvestmentsAccount::CashShortTermInvestmentsAccount(const CashShortTermInvestmentsAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
CashShortTermInvestmentsAccount::CashShortTermInvestmentsAccount(const CashShortTermInvestmentsAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void CashShortTermInvestmentsAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void CashShortTermInvestmentsAccount::init() {
   PositionAccount::init();
	init_CashShortTermInvestmentsAccount();
}

void CashShortTermInvestmentsAccount::init_CashShortTermInvestmentsAccount() {
   set_id("CashShortTermInvestmentsAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

CashShortTermInvestmentsAccount::~CashShortTermInvestmentsAccount()	{ cleanMem(); }

void CashShortTermInvestmentsAccount::cleanMem()	{
	cleanMem_CashShortTermInvestmentsAccount();
   PositionAccount::cleanMem();
}

void CashShortTermInvestmentsAccount::cleanMem_CashShortTermInvestmentsAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string CashShortTermInvestmentsAccount::className() const {return "CashShortTermInvestmentsAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void CashShortTermInvestmentsAccount::myerr_msg(string msg, string func) {
	err_msg("CashShortTermInvestmentsAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void CashShortTermInvestmentsAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_CashShortTermInvestmentsAccount(fname);
}

void CashShortTermInvestmentsAccount::fprint_CashShortTermInvestmentsAccount(string fname) {
}

void CashShortTermInvestmentsAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_CashShortTermInvestmentsAccount(fname);
}

void CashShortTermInvestmentsAccount::fscan_CashShortTermInvestmentsAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void CashShortTermInvestmentsAccount::reset() {
	reset_CashShortTermInvestmentsAccount();
   PositionAccount::reset();
}

void CashShortTermInvestmentsAccount::reset_CashShortTermInvestmentsAccount() {
}

/** ----------  static instance function -----------*/


CashShortTermInvestmentsAccount* CashShortTermInvestmentsAccount::instance()	{
	CashShortTermInvestmentsAccount* ptr = NULL;
   string id = "CashShortTermInvestmentsAccount";

   ptr = (CashShortTermInvestmentsAccount*) util_singleton("CashShortTermInvestmentsAccount",id);
   if(ptr==NULL) {
      ptr = new CashShortTermInvestmentsAccount();
      ptr->init();
      util_singleton("CashShortTermInvestmentsAccount",id,ptr);
   }
	return ptr;
}

CashShortTermInvestmentsAccount* CashShortTermInvestmentsAccount::instance_fscan(string fname)	{
   return CashShortTermInvestmentsAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

CashShortTermInvestmentsAccount* CashShortTermInvestmentsAccount::__ptr_CashShortTermInvestmentsAccount = CashShortTermInvestmentsAccount::instance();

#endif

