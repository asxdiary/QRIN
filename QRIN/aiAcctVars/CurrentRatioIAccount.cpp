// Name:     CurrentRatioIAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CurrentRatioIAccount_cpp
#define ASX_CurrentRatioIAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "R_DoubleDbAccount.hpp"
#include "CurrentAssetsAccount.hpp"
#include "CurrentLiabilitiesAccount.hpp"
#include "CurrentRatioIAccount.hpp"
#include "OperatingRevenueAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctFields;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

CurrentRatioIAccount::CurrentRatioIAccount() { init_NULL(); }
CurrentRatioIAccount::CurrentRatioIAccount(const CurrentRatioIAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
CurrentRatioIAccount::CurrentRatioIAccount(const CurrentRatioIAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void CurrentRatioIAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void CurrentRatioIAccount::init() {
   R_DoubleDbAccount::init(CurrentLiabilitiesAccount::instance(),
                           CurrentAssetsAccount::instance(),
                           false, false);
   init_CurrentRatioIAccount();
}

void CurrentRatioIAccount::init_CurrentRatioIAccount() {
   set_id("CurrentRatioIAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

CurrentRatioIAccount::~CurrentRatioIAccount()	{ cleanMem(); }

void CurrentRatioIAccount::cleanMem()	{
	cleanMem_CurrentRatioIAccount();
   R_DoubleDbAccount::cleanMem();
}

void CurrentRatioIAccount::cleanMem_CurrentRatioIAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string CurrentRatioIAccount::className() const {return "CurrentRatioIAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void CurrentRatioIAccount::myerr_msg(string msg, string func) {
	err_msg("CurrentRatioIAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void CurrentRatioIAccount::fprint(string fname) {
   R_DoubleDbAccount::fprint(fname);
	fprint_CurrentRatioIAccount(fname);
}

void CurrentRatioIAccount::fprint_CurrentRatioIAccount(string fname) {
}

void CurrentRatioIAccount::fscan(string fname) {
   R_DoubleDbAccount::fscan(fname);
	fscan_CurrentRatioIAccount(fname);
}

void CurrentRatioIAccount::fscan_CurrentRatioIAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void CurrentRatioIAccount::reset() {
	reset_CurrentRatioIAccount();
   R_DoubleDbAccount::reset();
}

void CurrentRatioIAccount::reset_CurrentRatioIAccount() {
}

/** ----------  static instance function -----------*/


CurrentRatioIAccount* CurrentRatioIAccount::instance()	{
	CurrentRatioIAccount* ptr = NULL;
   string id = "CurrentRatioIAccount";

   ptr = (CurrentRatioIAccount*) util_singleton("CurrentRatioIAccount",id);
   if(ptr==NULL) {
      ptr = new CurrentRatioIAccount();
      ptr->init();
      util_singleton("CurrentRatioIAccount",id,ptr);
   }
	return ptr;
}

CurrentRatioIAccount* CurrentRatioIAccount::instance_fscan(string fname)	{
   return CurrentRatioIAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

CurrentRatioIAccount* CurrentRatioIAccount::__ptr_CurrentRatioIAccount = CurrentRatioIAccount::instance();

#endif

