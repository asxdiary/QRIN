// Name:     PreferredEquityAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_PreferredEquityAccount_cpp
#define ASX_PreferredEquityAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "PreferredEquityAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

PreferredEquityAccount::PreferredEquityAccount() { init_NULL(); }
PreferredEquityAccount::PreferredEquityAccount(const PreferredEquityAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
PreferredEquityAccount::PreferredEquityAccount(const PreferredEquityAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void PreferredEquityAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void PreferredEquityAccount::init() {
   PositionAccount::init();
	init_PreferredEquityAccount();
}

void PreferredEquityAccount::init_PreferredEquityAccount() {
   set_id("PreferredEquityAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

PreferredEquityAccount::~PreferredEquityAccount()	{ cleanMem(); }

void PreferredEquityAccount::cleanMem()	{
	cleanMem_PreferredEquityAccount();
   PositionAccount::cleanMem();
}

void PreferredEquityAccount::cleanMem_PreferredEquityAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string PreferredEquityAccount::className() const {return "PreferredEquityAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void PreferredEquityAccount::myerr_msg(string msg, string func) {
	err_msg("PreferredEquityAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void PreferredEquityAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_PreferredEquityAccount(fname);
}

void PreferredEquityAccount::fprint_PreferredEquityAccount(string fname) {
}

void PreferredEquityAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_PreferredEquityAccount(fname);
}

void PreferredEquityAccount::fscan_PreferredEquityAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void PreferredEquityAccount::reset() {
	reset_PreferredEquityAccount();
   PositionAccount::reset();
}

void PreferredEquityAccount::reset_PreferredEquityAccount() {
}

/** ----------  static instance function -----------*/


PreferredEquityAccount* PreferredEquityAccount::instance()	{
	PreferredEquityAccount* ptr = NULL;
   string id = "PreferredEquityAccount";

   ptr = (PreferredEquityAccount*) util_singleton("PreferredEquityAccount",id);
   if(ptr==NULL) {
      ptr = new PreferredEquityAccount();
      ptr->init();
      util_singleton("PreferredEquityAccount",id,ptr);
   }
	return ptr;
}

PreferredEquityAccount* PreferredEquityAccount::instance_fscan(string fname)	{
   return PreferredEquityAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

PreferredEquityAccount* PreferredEquityAccount::__ptr_PreferredEquityAccount = PreferredEquityAccount::instance();

#endif

