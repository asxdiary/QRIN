// Name:     DeferredOtherNoncurrentLiabilitiesAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DeferredOtherNoncurrentLiabilitiesAccount_cpp
#define ASX_DeferredOtherNoncurrentLiabilitiesAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "DeferredOtherNoncurrentLiabilitiesAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

DeferredOtherNoncurrentLiabilitiesAccount::DeferredOtherNoncurrentLiabilitiesAccount() { init_NULL(); }
DeferredOtherNoncurrentLiabilitiesAccount::DeferredOtherNoncurrentLiabilitiesAccount(const DeferredOtherNoncurrentLiabilitiesAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
DeferredOtherNoncurrentLiabilitiesAccount::DeferredOtherNoncurrentLiabilitiesAccount(const DeferredOtherNoncurrentLiabilitiesAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void DeferredOtherNoncurrentLiabilitiesAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void DeferredOtherNoncurrentLiabilitiesAccount::init() {
   PositionAccount::init();
	init_DeferredOtherNoncurrentLiabilitiesAccount();
}

void DeferredOtherNoncurrentLiabilitiesAccount::init_DeferredOtherNoncurrentLiabilitiesAccount() {
   set_id("DeferredOtherNoncurrentLiabilitiesAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

DeferredOtherNoncurrentLiabilitiesAccount::~DeferredOtherNoncurrentLiabilitiesAccount()	{ cleanMem(); }

void DeferredOtherNoncurrentLiabilitiesAccount::cleanMem()	{
	cleanMem_DeferredOtherNoncurrentLiabilitiesAccount();
   PositionAccount::cleanMem();
}

void DeferredOtherNoncurrentLiabilitiesAccount::cleanMem_DeferredOtherNoncurrentLiabilitiesAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string DeferredOtherNoncurrentLiabilitiesAccount::className() const {return "DeferredOtherNoncurrentLiabilitiesAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void DeferredOtherNoncurrentLiabilitiesAccount::myerr_msg(string msg, string func) {
	err_msg("DeferredOtherNoncurrentLiabilitiesAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void DeferredOtherNoncurrentLiabilitiesAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_DeferredOtherNoncurrentLiabilitiesAccount(fname);
}

void DeferredOtherNoncurrentLiabilitiesAccount::fprint_DeferredOtherNoncurrentLiabilitiesAccount(string fname) {
}

void DeferredOtherNoncurrentLiabilitiesAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_DeferredOtherNoncurrentLiabilitiesAccount(fname);
}

void DeferredOtherNoncurrentLiabilitiesAccount::fscan_DeferredOtherNoncurrentLiabilitiesAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void DeferredOtherNoncurrentLiabilitiesAccount::reset() {
	reset_DeferredOtherNoncurrentLiabilitiesAccount();
   PositionAccount::reset();
}

void DeferredOtherNoncurrentLiabilitiesAccount::reset_DeferredOtherNoncurrentLiabilitiesAccount() {
}

/** ----------  static instance function -----------*/


DeferredOtherNoncurrentLiabilitiesAccount* DeferredOtherNoncurrentLiabilitiesAccount::instance()	{
	DeferredOtherNoncurrentLiabilitiesAccount* ptr = NULL;
   string id = "DeferredOtherNoncurrentLiabilitiesAccount";

   ptr = (DeferredOtherNoncurrentLiabilitiesAccount*) util_singleton("DeferredOtherNoncurrentLiabilitiesAccount",id);
   if(ptr==NULL) {
      ptr = new DeferredOtherNoncurrentLiabilitiesAccount();
      ptr->init();
      util_singleton("DeferredOtherNoncurrentLiabilitiesAccount",id,ptr);
   }
	return ptr;
}

DeferredOtherNoncurrentLiabilitiesAccount* DeferredOtherNoncurrentLiabilitiesAccount::instance_fscan(string fname)	{
   return DeferredOtherNoncurrentLiabilitiesAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

DeferredOtherNoncurrentLiabilitiesAccount* DeferredOtherNoncurrentLiabilitiesAccount::__ptr_DeferredOtherNoncurrentLiabilitiesAccount = DeferredOtherNoncurrentLiabilitiesAccount::instance();

#endif

