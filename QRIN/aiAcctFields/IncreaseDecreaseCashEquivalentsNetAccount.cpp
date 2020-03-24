// Name:     IncreaseDecreaseCashEquivalentsNetAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_IncreaseDecreaseCashEquivalentsNetAccount_cpp
#define ASX_IncreaseDecreaseCashEquivalentsNetAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "IncreaseDecreaseCashEquivalentsNetAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

IncreaseDecreaseCashEquivalentsNetAccount::IncreaseDecreaseCashEquivalentsNetAccount() { init_NULL(); }
IncreaseDecreaseCashEquivalentsNetAccount::IncreaseDecreaseCashEquivalentsNetAccount(const IncreaseDecreaseCashEquivalentsNetAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
IncreaseDecreaseCashEquivalentsNetAccount::IncreaseDecreaseCashEquivalentsNetAccount(const IncreaseDecreaseCashEquivalentsNetAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void IncreaseDecreaseCashEquivalentsNetAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void IncreaseDecreaseCashEquivalentsNetAccount::init() {
   FlowAccount::init();
	init_IncreaseDecreaseCashEquivalentsNetAccount();
}

void IncreaseDecreaseCashEquivalentsNetAccount::init_IncreaseDecreaseCashEquivalentsNetAccount() {
   set_id("IncreaseDecreaseCashEquivalentsNetAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

IncreaseDecreaseCashEquivalentsNetAccount::~IncreaseDecreaseCashEquivalentsNetAccount()	{ cleanMem(); }

void IncreaseDecreaseCashEquivalentsNetAccount::cleanMem()	{
	cleanMem_IncreaseDecreaseCashEquivalentsNetAccount();
   FlowAccount::cleanMem();
}

void IncreaseDecreaseCashEquivalentsNetAccount::cleanMem_IncreaseDecreaseCashEquivalentsNetAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string IncreaseDecreaseCashEquivalentsNetAccount::className() const {return "IncreaseDecreaseCashEquivalentsNetAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void IncreaseDecreaseCashEquivalentsNetAccount::myerr_msg(string msg, string func) {
	err_msg("IncreaseDecreaseCashEquivalentsNetAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void IncreaseDecreaseCashEquivalentsNetAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_IncreaseDecreaseCashEquivalentsNetAccount(fname);
}

void IncreaseDecreaseCashEquivalentsNetAccount::fprint_IncreaseDecreaseCashEquivalentsNetAccount(string fname) {
}

void IncreaseDecreaseCashEquivalentsNetAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_IncreaseDecreaseCashEquivalentsNetAccount(fname);
}

void IncreaseDecreaseCashEquivalentsNetAccount::fscan_IncreaseDecreaseCashEquivalentsNetAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void IncreaseDecreaseCashEquivalentsNetAccount::reset() {
	reset_IncreaseDecreaseCashEquivalentsNetAccount();
   FlowAccount::reset();
}

void IncreaseDecreaseCashEquivalentsNetAccount::reset_IncreaseDecreaseCashEquivalentsNetAccount() {
}

/** ----------  static instance function -----------*/


IncreaseDecreaseCashEquivalentsNetAccount* IncreaseDecreaseCashEquivalentsNetAccount::instance()	{
	IncreaseDecreaseCashEquivalentsNetAccount* ptr = NULL;
   string id = "IncreaseDecreaseCashEquivalentsNetAccount";

   ptr = (IncreaseDecreaseCashEquivalentsNetAccount*) util_singleton("IncreaseDecreaseCashEquivalentsNetAccount",id);
   if(ptr==NULL) {
      ptr = new IncreaseDecreaseCashEquivalentsNetAccount();
      ptr->init();
      util_singleton("IncreaseDecreaseCashEquivalentsNetAccount",id,ptr);
   }
	return ptr;
}

IncreaseDecreaseCashEquivalentsNetAccount* IncreaseDecreaseCashEquivalentsNetAccount::instance_fscan(string fname)	{
   return IncreaseDecreaseCashEquivalentsNetAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

IncreaseDecreaseCashEquivalentsNetAccount* IncreaseDecreaseCashEquivalentsNetAccount::__ptr_IncreaseDecreaseCashEquivalentsNetAccount = IncreaseDecreaseCashEquivalentsNetAccount::instance();

#endif

