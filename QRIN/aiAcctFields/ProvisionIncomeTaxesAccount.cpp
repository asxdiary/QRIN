// Name:     ProvisionIncomeTaxesAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ProvisionIncomeTaxesAccount_cpp
#define ASX_ProvisionIncomeTaxesAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "ProvisionIncomeTaxesAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

ProvisionIncomeTaxesAccount::ProvisionIncomeTaxesAccount() { init_NULL(); }
ProvisionIncomeTaxesAccount::ProvisionIncomeTaxesAccount(const ProvisionIncomeTaxesAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
ProvisionIncomeTaxesAccount::ProvisionIncomeTaxesAccount(const ProvisionIncomeTaxesAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void ProvisionIncomeTaxesAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void ProvisionIncomeTaxesAccount::init() {
   FlowAccount::init();
	init_ProvisionIncomeTaxesAccount();
}

void ProvisionIncomeTaxesAccount::init_ProvisionIncomeTaxesAccount() {
   set_id("ProvisionIncomeTaxesAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

ProvisionIncomeTaxesAccount::~ProvisionIncomeTaxesAccount()	{ cleanMem(); }

void ProvisionIncomeTaxesAccount::cleanMem()	{
	cleanMem_ProvisionIncomeTaxesAccount();
   FlowAccount::cleanMem();
}

void ProvisionIncomeTaxesAccount::cleanMem_ProvisionIncomeTaxesAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string ProvisionIncomeTaxesAccount::className() const {return "ProvisionIncomeTaxesAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void ProvisionIncomeTaxesAccount::myerr_msg(string msg, string func) {
	err_msg("ProvisionIncomeTaxesAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void ProvisionIncomeTaxesAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_ProvisionIncomeTaxesAccount(fname);
}

void ProvisionIncomeTaxesAccount::fprint_ProvisionIncomeTaxesAccount(string fname) {
}

void ProvisionIncomeTaxesAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_ProvisionIncomeTaxesAccount(fname);
}

void ProvisionIncomeTaxesAccount::fscan_ProvisionIncomeTaxesAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void ProvisionIncomeTaxesAccount::reset() {
	reset_ProvisionIncomeTaxesAccount();
   FlowAccount::reset();
}

void ProvisionIncomeTaxesAccount::reset_ProvisionIncomeTaxesAccount() {
}

/** ----------  static instance function -----------*/


ProvisionIncomeTaxesAccount* ProvisionIncomeTaxesAccount::instance()	{
	ProvisionIncomeTaxesAccount* ptr = NULL;
   string id = "ProvisionIncomeTaxesAccount";

   ptr = (ProvisionIncomeTaxesAccount*) util_singleton("ProvisionIncomeTaxesAccount",id);
   if(ptr==NULL) {
      ptr = new ProvisionIncomeTaxesAccount();
      ptr->init();
      util_singleton("ProvisionIncomeTaxesAccount",id,ptr);
   }
	return ptr;
}

ProvisionIncomeTaxesAccount* ProvisionIncomeTaxesAccount::instance_fscan(string fname)	{
   return ProvisionIncomeTaxesAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

ProvisionIncomeTaxesAccount* ProvisionIncomeTaxesAccount::__ptr_ProvisionIncomeTaxesAccount = ProvisionIncomeTaxesAccount::instance();

#endif

