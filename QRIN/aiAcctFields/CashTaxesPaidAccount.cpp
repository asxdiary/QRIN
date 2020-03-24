// Name:     CashTaxesPaidAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CashTaxesPaidAccount_cpp
#define ASX_CashTaxesPaidAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "CashTaxesPaidAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

CashTaxesPaidAccount::CashTaxesPaidAccount() { init_NULL(); }
CashTaxesPaidAccount::CashTaxesPaidAccount(const CashTaxesPaidAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
CashTaxesPaidAccount::CashTaxesPaidAccount(const CashTaxesPaidAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void CashTaxesPaidAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void CashTaxesPaidAccount::init() {
   FlowAccount::init();
	init_CashTaxesPaidAccount();
}

void CashTaxesPaidAccount::init_CashTaxesPaidAccount() {
   set_id("CashTaxesPaidAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

CashTaxesPaidAccount::~CashTaxesPaidAccount()	{ cleanMem(); }

void CashTaxesPaidAccount::cleanMem()	{
	cleanMem_CashTaxesPaidAccount();
   FlowAccount::cleanMem();
}

void CashTaxesPaidAccount::cleanMem_CashTaxesPaidAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string CashTaxesPaidAccount::className() const {return "CashTaxesPaidAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void CashTaxesPaidAccount::myerr_msg(string msg, string func) {
	err_msg("CashTaxesPaidAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void CashTaxesPaidAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_CashTaxesPaidAccount(fname);
}

void CashTaxesPaidAccount::fprint_CashTaxesPaidAccount(string fname) {
}

void CashTaxesPaidAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_CashTaxesPaidAccount(fname);
}

void CashTaxesPaidAccount::fscan_CashTaxesPaidAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void CashTaxesPaidAccount::reset() {
	reset_CashTaxesPaidAccount();
   FlowAccount::reset();
}

void CashTaxesPaidAccount::reset_CashTaxesPaidAccount() {
}

/** ----------  static instance function -----------*/


CashTaxesPaidAccount* CashTaxesPaidAccount::instance()	{
	CashTaxesPaidAccount* ptr = NULL;
   string id = "CashTaxesPaidAccount";

   ptr = (CashTaxesPaidAccount*) util_singleton("CashTaxesPaidAccount",id);
   if(ptr==NULL) {
      ptr = new CashTaxesPaidAccount();
      ptr->init();
      util_singleton("CashTaxesPaidAccount",id,ptr);
   }
	return ptr;
}

CashTaxesPaidAccount* CashTaxesPaidAccount::instance_fscan(string fname)	{
   return CashTaxesPaidAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

CashTaxesPaidAccount* CashTaxesPaidAccount::__ptr_CashTaxesPaidAccount = CashTaxesPaidAccount::instance();

#endif

