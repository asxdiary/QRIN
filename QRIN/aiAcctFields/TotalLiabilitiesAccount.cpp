// Name:     TotalLiabilitiesAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_TotalLiabilitiesAccount_cpp
#define ASX_TotalLiabilitiesAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "TotalLiabilitiesAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

TotalLiabilitiesAccount::TotalLiabilitiesAccount() { init_NULL(); }
TotalLiabilitiesAccount::TotalLiabilitiesAccount(const TotalLiabilitiesAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
TotalLiabilitiesAccount::TotalLiabilitiesAccount(const TotalLiabilitiesAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void TotalLiabilitiesAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void TotalLiabilitiesAccount::init() {
   PositionAccount::init();
	init_TotalLiabilitiesAccount();
}

void TotalLiabilitiesAccount::init_TotalLiabilitiesAccount() {
   set_id("TotalLiabilitiesAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

TotalLiabilitiesAccount::~TotalLiabilitiesAccount()	{ cleanMem(); }

void TotalLiabilitiesAccount::cleanMem()	{
	cleanMem_TotalLiabilitiesAccount();
   PositionAccount::cleanMem();
}

void TotalLiabilitiesAccount::cleanMem_TotalLiabilitiesAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string TotalLiabilitiesAccount::className() const {return "TotalLiabilitiesAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void TotalLiabilitiesAccount::myerr_msg(string msg, string func) {
	err_msg("TotalLiabilitiesAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void TotalLiabilitiesAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_TotalLiabilitiesAccount(fname);
}

void TotalLiabilitiesAccount::fprint_TotalLiabilitiesAccount(string fname) {
}

void TotalLiabilitiesAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_TotalLiabilitiesAccount(fname);
}

void TotalLiabilitiesAccount::fscan_TotalLiabilitiesAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void TotalLiabilitiesAccount::reset() {
	reset_TotalLiabilitiesAccount();
   PositionAccount::reset();
}

void TotalLiabilitiesAccount::reset_TotalLiabilitiesAccount() {
}

/** ----------  static instance function -----------*/


TotalLiabilitiesAccount* TotalLiabilitiesAccount::instance()	{
	TotalLiabilitiesAccount* ptr = NULL;
   string id = "TotalLiabilitiesAccount";

   ptr = (TotalLiabilitiesAccount*) util_singleton("TotalLiabilitiesAccount",id);
   if(ptr==NULL) {
      ptr = new TotalLiabilitiesAccount();
      ptr->init();
      util_singleton("TotalLiabilitiesAccount",id,ptr);
   }
	return ptr;
}

TotalLiabilitiesAccount* TotalLiabilitiesAccount::instance_fscan(string fname)	{
   return TotalLiabilitiesAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

TotalLiabilitiesAccount* TotalLiabilitiesAccount::__ptr_TotalLiabilitiesAccount = TotalLiabilitiesAccount::instance();

#endif

