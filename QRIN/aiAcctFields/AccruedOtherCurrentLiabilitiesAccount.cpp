// Name:     AccruedOtherCurrentLiabilitiesAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_AccruedOtherCurrentLiabilitiesAccount_cpp
#define ASX_AccruedOtherCurrentLiabilitiesAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "AccruedOtherCurrentLiabilitiesAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

AccruedOtherCurrentLiabilitiesAccount::AccruedOtherCurrentLiabilitiesAccount() { init_NULL(); }
AccruedOtherCurrentLiabilitiesAccount::AccruedOtherCurrentLiabilitiesAccount(const AccruedOtherCurrentLiabilitiesAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
AccruedOtherCurrentLiabilitiesAccount::AccruedOtherCurrentLiabilitiesAccount(const AccruedOtherCurrentLiabilitiesAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void AccruedOtherCurrentLiabilitiesAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void AccruedOtherCurrentLiabilitiesAccount::init() {
   PositionAccount::init();
	init_AccruedOtherCurrentLiabilitiesAccount();
}

void AccruedOtherCurrentLiabilitiesAccount::init_AccruedOtherCurrentLiabilitiesAccount() {
   set_id("AccruedOtherCurrentLiabilitiesAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

AccruedOtherCurrentLiabilitiesAccount::~AccruedOtherCurrentLiabilitiesAccount()	{ cleanMem(); }

void AccruedOtherCurrentLiabilitiesAccount::cleanMem()	{
	cleanMem_AccruedOtherCurrentLiabilitiesAccount();
   PositionAccount::cleanMem();
}

void AccruedOtherCurrentLiabilitiesAccount::cleanMem_AccruedOtherCurrentLiabilitiesAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string AccruedOtherCurrentLiabilitiesAccount::className() const {return "AccruedOtherCurrentLiabilitiesAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void AccruedOtherCurrentLiabilitiesAccount::myerr_msg(string msg, string func) {
	err_msg("AccruedOtherCurrentLiabilitiesAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void AccruedOtherCurrentLiabilitiesAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_AccruedOtherCurrentLiabilitiesAccount(fname);
}

void AccruedOtherCurrentLiabilitiesAccount::fprint_AccruedOtherCurrentLiabilitiesAccount(string fname) {
}

void AccruedOtherCurrentLiabilitiesAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_AccruedOtherCurrentLiabilitiesAccount(fname);
}

void AccruedOtherCurrentLiabilitiesAccount::fscan_AccruedOtherCurrentLiabilitiesAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void AccruedOtherCurrentLiabilitiesAccount::reset() {
	reset_AccruedOtherCurrentLiabilitiesAccount();
   PositionAccount::reset();
}

void AccruedOtherCurrentLiabilitiesAccount::reset_AccruedOtherCurrentLiabilitiesAccount() {
}

/** ----------  static instance function -----------*/


AccruedOtherCurrentLiabilitiesAccount* AccruedOtherCurrentLiabilitiesAccount::instance()	{
	AccruedOtherCurrentLiabilitiesAccount* ptr = NULL;
   string id = "AccruedOtherCurrentLiabilitiesAccount";

   ptr = (AccruedOtherCurrentLiabilitiesAccount*) util_singleton("AccruedOtherCurrentLiabilitiesAccount",id);
   if(ptr==NULL) {
      ptr = new AccruedOtherCurrentLiabilitiesAccount();
      ptr->init();
      util_singleton("AccruedOtherCurrentLiabilitiesAccount",id,ptr);
   }
	return ptr;
}

AccruedOtherCurrentLiabilitiesAccount* AccruedOtherCurrentLiabilitiesAccount::instance_fscan(string fname)	{
   return AccruedOtherCurrentLiabilitiesAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

AccruedOtherCurrentLiabilitiesAccount* AccruedOtherCurrentLiabilitiesAccount::__ptr_AccruedOtherCurrentLiabilitiesAccount = AccruedOtherCurrentLiabilitiesAccount::instance();

#endif

