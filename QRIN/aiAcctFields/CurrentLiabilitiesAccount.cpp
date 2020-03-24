// Name:     CurrentLiabilitiesAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CurrentLiabilitiesAccount_cpp
#define ASX_CurrentLiabilitiesAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "CurrentLiabilitiesAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

CurrentLiabilitiesAccount::CurrentLiabilitiesAccount() { init_NULL(); }
CurrentLiabilitiesAccount::CurrentLiabilitiesAccount(const CurrentLiabilitiesAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
CurrentLiabilitiesAccount::CurrentLiabilitiesAccount(const CurrentLiabilitiesAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void CurrentLiabilitiesAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void CurrentLiabilitiesAccount::init() {
   PositionAccount::init();
	init_CurrentLiabilitiesAccount();
}

void CurrentLiabilitiesAccount::init_CurrentLiabilitiesAccount() {
   set_id("CurrentLiabilitiesAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

CurrentLiabilitiesAccount::~CurrentLiabilitiesAccount()	{ cleanMem(); }

void CurrentLiabilitiesAccount::cleanMem()	{
	cleanMem_CurrentLiabilitiesAccount();
   PositionAccount::cleanMem();
}

void CurrentLiabilitiesAccount::cleanMem_CurrentLiabilitiesAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string CurrentLiabilitiesAccount::className() const {return "CurrentLiabilitiesAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void CurrentLiabilitiesAccount::myerr_msg(string msg, string func) {
	err_msg("CurrentLiabilitiesAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void CurrentLiabilitiesAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_CurrentLiabilitiesAccount(fname);
}

void CurrentLiabilitiesAccount::fprint_CurrentLiabilitiesAccount(string fname) {
}

void CurrentLiabilitiesAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_CurrentLiabilitiesAccount(fname);
}

void CurrentLiabilitiesAccount::fscan_CurrentLiabilitiesAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void CurrentLiabilitiesAccount::reset() {
	reset_CurrentLiabilitiesAccount();
   PositionAccount::reset();
}

void CurrentLiabilitiesAccount::reset_CurrentLiabilitiesAccount() {
}

/** ----------  static instance function -----------*/


CurrentLiabilitiesAccount* CurrentLiabilitiesAccount::instance()	{
	CurrentLiabilitiesAccount* ptr = NULL;
   string id = "CurrentLiabilitiesAccount";

   ptr = (CurrentLiabilitiesAccount*) util_singleton("CurrentLiabilitiesAccount",id);
   if(ptr==NULL) {
      ptr = new CurrentLiabilitiesAccount();
      ptr->init();
      util_singleton("CurrentLiabilitiesAccount",id,ptr);
   }
	return ptr;
}

CurrentLiabilitiesAccount* CurrentLiabilitiesAccount::instance_fscan(string fname)	{
   return CurrentLiabilitiesAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

CurrentLiabilitiesAccount* CurrentLiabilitiesAccount::__ptr_CurrentLiabilitiesAccount = CurrentLiabilitiesAccount::instance();

#endif

