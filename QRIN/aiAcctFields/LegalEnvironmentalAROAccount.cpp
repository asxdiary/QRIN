// Name:     LegalEnvironmentalAROAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_LegalEnvironmentalAROAccount_cpp
#define ASX_LegalEnvironmentalAROAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "LegalEnvironmentalAROAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

LegalEnvironmentalAROAccount::LegalEnvironmentalAROAccount() { init_NULL(); }
LegalEnvironmentalAROAccount::LegalEnvironmentalAROAccount(const LegalEnvironmentalAROAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
LegalEnvironmentalAROAccount::LegalEnvironmentalAROAccount(const LegalEnvironmentalAROAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void LegalEnvironmentalAROAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void LegalEnvironmentalAROAccount::init() {
   PositionAccount::init();
	init_LegalEnvironmentalAROAccount();
}

void LegalEnvironmentalAROAccount::init_LegalEnvironmentalAROAccount() {
   set_id("LegalEnvironmentalAROAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

LegalEnvironmentalAROAccount::~LegalEnvironmentalAROAccount()	{ cleanMem(); }

void LegalEnvironmentalAROAccount::cleanMem()	{
	cleanMem_LegalEnvironmentalAROAccount();
   PositionAccount::cleanMem();
}

void LegalEnvironmentalAROAccount::cleanMem_LegalEnvironmentalAROAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string LegalEnvironmentalAROAccount::className() const {return "LegalEnvironmentalAROAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void LegalEnvironmentalAROAccount::myerr_msg(string msg, string func) {
	err_msg("LegalEnvironmentalAROAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void LegalEnvironmentalAROAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_LegalEnvironmentalAROAccount(fname);
}

void LegalEnvironmentalAROAccount::fprint_LegalEnvironmentalAROAccount(string fname) {
}

void LegalEnvironmentalAROAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_LegalEnvironmentalAROAccount(fname);
}

void LegalEnvironmentalAROAccount::fscan_LegalEnvironmentalAROAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void LegalEnvironmentalAROAccount::reset() {
	reset_LegalEnvironmentalAROAccount();
   PositionAccount::reset();
}

void LegalEnvironmentalAROAccount::reset_LegalEnvironmentalAROAccount() {
}

/** ----------  static instance function -----------*/


LegalEnvironmentalAROAccount* LegalEnvironmentalAROAccount::instance()	{
	LegalEnvironmentalAROAccount* ptr = NULL;
   string id = "LegalEnvironmentalAROAccount";

   ptr = (LegalEnvironmentalAROAccount*) util_singleton("LegalEnvironmentalAROAccount",id);
   if(ptr==NULL) {
      ptr = new LegalEnvironmentalAROAccount();
      ptr->init();
      util_singleton("LegalEnvironmentalAROAccount",id,ptr);
   }
	return ptr;
}

LegalEnvironmentalAROAccount* LegalEnvironmentalAROAccount::instance_fscan(string fname)	{
   return LegalEnvironmentalAROAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

LegalEnvironmentalAROAccount* LegalEnvironmentalAROAccount::__ptr_LegalEnvironmentalAROAccount = LegalEnvironmentalAROAccount::instance();

#endif

