// Name:     SellingGeneralAdministrativeAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_SellingGeneralAdministrativeAccount_cpp
#define ASX_SellingGeneralAdministrativeAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "SellingGeneralAdministrativeAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

SellingGeneralAdministrativeAccount::SellingGeneralAdministrativeAccount() { init_NULL(); }
SellingGeneralAdministrativeAccount::SellingGeneralAdministrativeAccount(const SellingGeneralAdministrativeAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
SellingGeneralAdministrativeAccount::SellingGeneralAdministrativeAccount(const SellingGeneralAdministrativeAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void SellingGeneralAdministrativeAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void SellingGeneralAdministrativeAccount::init() {
   FlowAccount::init();
	init_SellingGeneralAdministrativeAccount();
}

void SellingGeneralAdministrativeAccount::init_SellingGeneralAdministrativeAccount() {
   set_id("SellingGeneralAdministrativeAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

SellingGeneralAdministrativeAccount::~SellingGeneralAdministrativeAccount()	{ cleanMem(); }

void SellingGeneralAdministrativeAccount::cleanMem()	{
	cleanMem_SellingGeneralAdministrativeAccount();
   FlowAccount::cleanMem();
}

void SellingGeneralAdministrativeAccount::cleanMem_SellingGeneralAdministrativeAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string SellingGeneralAdministrativeAccount::className() const {return "SellingGeneralAdministrativeAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void SellingGeneralAdministrativeAccount::myerr_msg(string msg, string func) {
	err_msg("SellingGeneralAdministrativeAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void SellingGeneralAdministrativeAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_SellingGeneralAdministrativeAccount(fname);
}

void SellingGeneralAdministrativeAccount::fprint_SellingGeneralAdministrativeAccount(string fname) {
}

void SellingGeneralAdministrativeAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_SellingGeneralAdministrativeAccount(fname);
}

void SellingGeneralAdministrativeAccount::fscan_SellingGeneralAdministrativeAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void SellingGeneralAdministrativeAccount::reset() {
	reset_SellingGeneralAdministrativeAccount();
   FlowAccount::reset();
}

void SellingGeneralAdministrativeAccount::reset_SellingGeneralAdministrativeAccount() {
}

/** ----------  static instance function -----------*/


SellingGeneralAdministrativeAccount* SellingGeneralAdministrativeAccount::instance()	{
	SellingGeneralAdministrativeAccount* ptr = NULL;
   string id = "SellingGeneralAdministrativeAccount";

   ptr = (SellingGeneralAdministrativeAccount*) util_singleton("SellingGeneralAdministrativeAccount",id);
   if(ptr==NULL) {
      ptr = new SellingGeneralAdministrativeAccount();
      ptr->init();
      util_singleton("SellingGeneralAdministrativeAccount",id,ptr);
   }
	return ptr;
}

SellingGeneralAdministrativeAccount* SellingGeneralAdministrativeAccount::instance_fscan(string fname)	{
   return SellingGeneralAdministrativeAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

SellingGeneralAdministrativeAccount* SellingGeneralAdministrativeAccount::__ptr_SellingGeneralAdministrativeAccount = SellingGeneralAdministrativeAccount::instance();

#endif

