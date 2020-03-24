// Name:     MinorityInterestParticipationNetTaxEffectAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_MinorityInterestParticipationNetTaxEffectAccount_cpp
#define ASX_MinorityInterestParticipationNetTaxEffectAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "MinorityInterestParticipationNetTaxEffectAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

MinorityInterestParticipationNetTaxEffectAccount::MinorityInterestParticipationNetTaxEffectAccount() { init_NULL(); }
MinorityInterestParticipationNetTaxEffectAccount::MinorityInterestParticipationNetTaxEffectAccount(const MinorityInterestParticipationNetTaxEffectAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
MinorityInterestParticipationNetTaxEffectAccount::MinorityInterestParticipationNetTaxEffectAccount(const MinorityInterestParticipationNetTaxEffectAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void MinorityInterestParticipationNetTaxEffectAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void MinorityInterestParticipationNetTaxEffectAccount::init() {
   FlowAccount::init();
	init_MinorityInterestParticipationNetTaxEffectAccount();
}

void MinorityInterestParticipationNetTaxEffectAccount::init_MinorityInterestParticipationNetTaxEffectAccount() {
   set_id("MinorityInterestParticipationNetTaxEffectAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

MinorityInterestParticipationNetTaxEffectAccount::~MinorityInterestParticipationNetTaxEffectAccount()	{ cleanMem(); }

void MinorityInterestParticipationNetTaxEffectAccount::cleanMem()	{
	cleanMem_MinorityInterestParticipationNetTaxEffectAccount();
   FlowAccount::cleanMem();
}

void MinorityInterestParticipationNetTaxEffectAccount::cleanMem_MinorityInterestParticipationNetTaxEffectAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string MinorityInterestParticipationNetTaxEffectAccount::className() const {return "MinorityInterestParticipationNetTaxEffectAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void MinorityInterestParticipationNetTaxEffectAccount::myerr_msg(string msg, string func) {
	err_msg("MinorityInterestParticipationNetTaxEffectAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void MinorityInterestParticipationNetTaxEffectAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_MinorityInterestParticipationNetTaxEffectAccount(fname);
}

void MinorityInterestParticipationNetTaxEffectAccount::fprint_MinorityInterestParticipationNetTaxEffectAccount(string fname) {
}

void MinorityInterestParticipationNetTaxEffectAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_MinorityInterestParticipationNetTaxEffectAccount(fname);
}

void MinorityInterestParticipationNetTaxEffectAccount::fscan_MinorityInterestParticipationNetTaxEffectAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void MinorityInterestParticipationNetTaxEffectAccount::reset() {
	reset_MinorityInterestParticipationNetTaxEffectAccount();
   FlowAccount::reset();
}

void MinorityInterestParticipationNetTaxEffectAccount::reset_MinorityInterestParticipationNetTaxEffectAccount() {
}

/** ----------  static instance function -----------*/


MinorityInterestParticipationNetTaxEffectAccount* MinorityInterestParticipationNetTaxEffectAccount::instance()	{
	MinorityInterestParticipationNetTaxEffectAccount* ptr = NULL;
   string id = "MinorityInterestParticipationNetTaxEffectAccount";

   ptr = (MinorityInterestParticipationNetTaxEffectAccount*) util_singleton("MinorityInterestParticipationNetTaxEffectAccount",id);
   if(ptr==NULL) {
      ptr = new MinorityInterestParticipationNetTaxEffectAccount();
      ptr->init();
      util_singleton("MinorityInterestParticipationNetTaxEffectAccount",id,ptr);
   }
	return ptr;
}

MinorityInterestParticipationNetTaxEffectAccount* MinorityInterestParticipationNetTaxEffectAccount::instance_fscan(string fname)	{
   return MinorityInterestParticipationNetTaxEffectAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

MinorityInterestParticipationNetTaxEffectAccount* MinorityInterestParticipationNetTaxEffectAccount::__ptr_MinorityInterestParticipationNetTaxEffectAccount = MinorityInterestParticipationNetTaxEffectAccount::instance();

#endif

