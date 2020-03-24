// Name:     DepreciationAmortizationUnclassifiedOperatingAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DepreciationAmortizationUnclassifiedOperatingAccount_cpp
#define ASX_DepreciationAmortizationUnclassifiedOperatingAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "DepreciationAmortizationUnclassifiedOperatingAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

DepreciationAmortizationUnclassifiedOperatingAccount::DepreciationAmortizationUnclassifiedOperatingAccount() { init_NULL(); }
DepreciationAmortizationUnclassifiedOperatingAccount::DepreciationAmortizationUnclassifiedOperatingAccount(const DepreciationAmortizationUnclassifiedOperatingAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
DepreciationAmortizationUnclassifiedOperatingAccount::DepreciationAmortizationUnclassifiedOperatingAccount(const DepreciationAmortizationUnclassifiedOperatingAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void DepreciationAmortizationUnclassifiedOperatingAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void DepreciationAmortizationUnclassifiedOperatingAccount::init() {
   FlowAccount::init();
	init_DepreciationAmortizationUnclassifiedOperatingAccount();
}

void DepreciationAmortizationUnclassifiedOperatingAccount::init_DepreciationAmortizationUnclassifiedOperatingAccount() {
   set_id("DepreciationAmortizationUnclassifiedOperatingAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

DepreciationAmortizationUnclassifiedOperatingAccount::~DepreciationAmortizationUnclassifiedOperatingAccount()	{ cleanMem(); }

void DepreciationAmortizationUnclassifiedOperatingAccount::cleanMem()	{
	cleanMem_DepreciationAmortizationUnclassifiedOperatingAccount();
   FlowAccount::cleanMem();
}

void DepreciationAmortizationUnclassifiedOperatingAccount::cleanMem_DepreciationAmortizationUnclassifiedOperatingAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string DepreciationAmortizationUnclassifiedOperatingAccount::className() const {return "DepreciationAmortizationUnclassifiedOperatingAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void DepreciationAmortizationUnclassifiedOperatingAccount::myerr_msg(string msg, string func) {
	err_msg("DepreciationAmortizationUnclassifiedOperatingAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void DepreciationAmortizationUnclassifiedOperatingAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_DepreciationAmortizationUnclassifiedOperatingAccount(fname);
}

void DepreciationAmortizationUnclassifiedOperatingAccount::fprint_DepreciationAmortizationUnclassifiedOperatingAccount(string fname) {
}

void DepreciationAmortizationUnclassifiedOperatingAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_DepreciationAmortizationUnclassifiedOperatingAccount(fname);
}

void DepreciationAmortizationUnclassifiedOperatingAccount::fscan_DepreciationAmortizationUnclassifiedOperatingAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void DepreciationAmortizationUnclassifiedOperatingAccount::reset() {
	reset_DepreciationAmortizationUnclassifiedOperatingAccount();
   FlowAccount::reset();
}

void DepreciationAmortizationUnclassifiedOperatingAccount::reset_DepreciationAmortizationUnclassifiedOperatingAccount() {
}

/** ----------  static instance function -----------*/


DepreciationAmortizationUnclassifiedOperatingAccount* DepreciationAmortizationUnclassifiedOperatingAccount::instance()	{
	DepreciationAmortizationUnclassifiedOperatingAccount* ptr = NULL;
   string id = "DepreciationAmortizationUnclassifiedOperatingAccount";

   ptr = (DepreciationAmortizationUnclassifiedOperatingAccount*) util_singleton("DepreciationAmortizationUnclassifiedOperatingAccount",id);
   if(ptr==NULL) {
      ptr = new DepreciationAmortizationUnclassifiedOperatingAccount();
      ptr->init();
      util_singleton("DepreciationAmortizationUnclassifiedOperatingAccount",id,ptr);
   }
	return ptr;
}

DepreciationAmortizationUnclassifiedOperatingAccount* DepreciationAmortizationUnclassifiedOperatingAccount::instance_fscan(string fname)	{
   return DepreciationAmortizationUnclassifiedOperatingAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

DepreciationAmortizationUnclassifiedOperatingAccount* DepreciationAmortizationUnclassifiedOperatingAccount::__ptr_DepreciationAmortizationUnclassifiedOperatingAccount = DepreciationAmortizationUnclassifiedOperatingAccount::instance();

#endif

