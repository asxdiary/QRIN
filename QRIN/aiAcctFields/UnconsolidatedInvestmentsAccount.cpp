// Name:     UnconsolidatedInvestmentsAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_UnconsolidatedInvestmentsAccount_cpp
#define ASX_UnconsolidatedInvestmentsAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "UnconsolidatedInvestmentsAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

UnconsolidatedInvestmentsAccount::UnconsolidatedInvestmentsAccount() { init_NULL(); }
UnconsolidatedInvestmentsAccount::UnconsolidatedInvestmentsAccount(const UnconsolidatedInvestmentsAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
UnconsolidatedInvestmentsAccount::UnconsolidatedInvestmentsAccount(const UnconsolidatedInvestmentsAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void UnconsolidatedInvestmentsAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void UnconsolidatedInvestmentsAccount::init() {
   PositionAccount::init();
	init_UnconsolidatedInvestmentsAccount();
}

void UnconsolidatedInvestmentsAccount::init_UnconsolidatedInvestmentsAccount() {
   set_id("UnconsolidatedInvestmentsAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

UnconsolidatedInvestmentsAccount::~UnconsolidatedInvestmentsAccount()	{ cleanMem(); }

void UnconsolidatedInvestmentsAccount::cleanMem()	{
	cleanMem_UnconsolidatedInvestmentsAccount();
   PositionAccount::cleanMem();
}

void UnconsolidatedInvestmentsAccount::cleanMem_UnconsolidatedInvestmentsAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string UnconsolidatedInvestmentsAccount::className() const {return "UnconsolidatedInvestmentsAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void UnconsolidatedInvestmentsAccount::myerr_msg(string msg, string func) {
	err_msg("UnconsolidatedInvestmentsAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void UnconsolidatedInvestmentsAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_UnconsolidatedInvestmentsAccount(fname);
}

void UnconsolidatedInvestmentsAccount::fprint_UnconsolidatedInvestmentsAccount(string fname) {
}

void UnconsolidatedInvestmentsAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_UnconsolidatedInvestmentsAccount(fname);
}

void UnconsolidatedInvestmentsAccount::fscan_UnconsolidatedInvestmentsAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void UnconsolidatedInvestmentsAccount::reset() {
	reset_UnconsolidatedInvestmentsAccount();
   PositionAccount::reset();
}

void UnconsolidatedInvestmentsAccount::reset_UnconsolidatedInvestmentsAccount() {
}

/** ----------  static instance function -----------*/


UnconsolidatedInvestmentsAccount* UnconsolidatedInvestmentsAccount::instance()	{
	UnconsolidatedInvestmentsAccount* ptr = NULL;
   string id = "UnconsolidatedInvestmentsAccount";

   ptr = (UnconsolidatedInvestmentsAccount*) util_singleton("UnconsolidatedInvestmentsAccount",id);
   if(ptr==NULL) {
      ptr = new UnconsolidatedInvestmentsAccount();
      ptr->init();
      util_singleton("UnconsolidatedInvestmentsAccount",id,ptr);
   }
	return ptr;
}

UnconsolidatedInvestmentsAccount* UnconsolidatedInvestmentsAccount::instance_fscan(string fname)	{
   return UnconsolidatedInvestmentsAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

UnconsolidatedInvestmentsAccount* UnconsolidatedInvestmentsAccount::__ptr_UnconsolidatedInvestmentsAccount = UnconsolidatedInvestmentsAccount::instance();

#endif

