// Name:     NonoperatingGainsAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_NonoperatingGainsAccount_cpp
#define ASX_NonoperatingGainsAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "NonoperatingGainsAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

NonoperatingGainsAccount::NonoperatingGainsAccount() { init_NULL(); }
NonoperatingGainsAccount::NonoperatingGainsAccount(const NonoperatingGainsAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
NonoperatingGainsAccount::NonoperatingGainsAccount(const NonoperatingGainsAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void NonoperatingGainsAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void NonoperatingGainsAccount::init() {
   FlowAccount::init();
	init_NonoperatingGainsAccount();
}

void NonoperatingGainsAccount::init_NonoperatingGainsAccount() {
   set_id("NonoperatingGainsAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

NonoperatingGainsAccount::~NonoperatingGainsAccount()	{ cleanMem(); }

void NonoperatingGainsAccount::cleanMem()	{
	cleanMem_NonoperatingGainsAccount();
   FlowAccount::cleanMem();
}

void NonoperatingGainsAccount::cleanMem_NonoperatingGainsAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string NonoperatingGainsAccount::className() const {return "NonoperatingGainsAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void NonoperatingGainsAccount::myerr_msg(string msg, string func) {
	err_msg("NonoperatingGainsAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void NonoperatingGainsAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_NonoperatingGainsAccount(fname);
}

void NonoperatingGainsAccount::fprint_NonoperatingGainsAccount(string fname) {
}

void NonoperatingGainsAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_NonoperatingGainsAccount(fname);
}

void NonoperatingGainsAccount::fscan_NonoperatingGainsAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void NonoperatingGainsAccount::reset() {
	reset_NonoperatingGainsAccount();
   FlowAccount::reset();
}

void NonoperatingGainsAccount::reset_NonoperatingGainsAccount() {
}

/** ----------  static instance function -----------*/


NonoperatingGainsAccount* NonoperatingGainsAccount::instance()	{
	NonoperatingGainsAccount* ptr = NULL;
   string id = "NonoperatingGainsAccount";

   ptr = (NonoperatingGainsAccount*) util_singleton("NonoperatingGainsAccount",id);
   if(ptr==NULL) {
      ptr = new NonoperatingGainsAccount();
      ptr->init();
      util_singleton("NonoperatingGainsAccount",id,ptr);
   }
	return ptr;
}

NonoperatingGainsAccount* NonoperatingGainsAccount::instance_fscan(string fname)	{
   return NonoperatingGainsAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

NonoperatingGainsAccount* NonoperatingGainsAccount::__ptr_NonoperatingGainsAccount = NonoperatingGainsAccount::instance();

#endif

