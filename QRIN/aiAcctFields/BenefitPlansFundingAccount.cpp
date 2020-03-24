// Name:     BenefitPlansFundingAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_BenefitPlansFundingAccount_cpp
#define ASX_BenefitPlansFundingAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "BenefitPlansFundingAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

BenefitPlansFundingAccount::BenefitPlansFundingAccount() { init_NULL(); }
BenefitPlansFundingAccount::BenefitPlansFundingAccount(const BenefitPlansFundingAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
BenefitPlansFundingAccount::BenefitPlansFundingAccount(const BenefitPlansFundingAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void BenefitPlansFundingAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void BenefitPlansFundingAccount::init() {
   PositionAccount::init();
	init_BenefitPlansFundingAccount();
}

void BenefitPlansFundingAccount::init_BenefitPlansFundingAccount() {
   set_id("BenefitPlansFundingAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

BenefitPlansFundingAccount::~BenefitPlansFundingAccount()	{ cleanMem(); }

void BenefitPlansFundingAccount::cleanMem()	{
	cleanMem_BenefitPlansFundingAccount();
   PositionAccount::cleanMem();
}

void BenefitPlansFundingAccount::cleanMem_BenefitPlansFundingAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string BenefitPlansFundingAccount::className() const {return "BenefitPlansFundingAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void BenefitPlansFundingAccount::myerr_msg(string msg, string func) {
	err_msg("BenefitPlansFundingAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void BenefitPlansFundingAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_BenefitPlansFundingAccount(fname);
}

void BenefitPlansFundingAccount::fprint_BenefitPlansFundingAccount(string fname) {
}

void BenefitPlansFundingAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_BenefitPlansFundingAccount(fname);
}

void BenefitPlansFundingAccount::fscan_BenefitPlansFundingAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void BenefitPlansFundingAccount::reset() {
	reset_BenefitPlansFundingAccount();
   PositionAccount::reset();
}

void BenefitPlansFundingAccount::reset_BenefitPlansFundingAccount() {
}

/** ----------  static instance function -----------*/


BenefitPlansFundingAccount* BenefitPlansFundingAccount::instance()	{
	BenefitPlansFundingAccount* ptr = NULL;
   string id = "BenefitPlansFundingAccount";

   ptr = (BenefitPlansFundingAccount*) util_singleton("BenefitPlansFundingAccount",id);
   if(ptr==NULL) {
      ptr = new BenefitPlansFundingAccount();
      ptr->init();
      util_singleton("BenefitPlansFundingAccount",id,ptr);
   }
	return ptr;
}

BenefitPlansFundingAccount* BenefitPlansFundingAccount::instance_fscan(string fname)	{
   return BenefitPlansFundingAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

BenefitPlansFundingAccount* BenefitPlansFundingAccount::__ptr_BenefitPlansFundingAccount = BenefitPlansFundingAccount::instance();

#endif

