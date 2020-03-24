// Name:     RecurringEBITAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_RecurringEBITAccount_cpp
#define ASX_RecurringEBITAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "RecurringEBITAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

RecurringEBITAccount::RecurringEBITAccount() { init_NULL(); }
RecurringEBITAccount::RecurringEBITAccount(const RecurringEBITAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
RecurringEBITAccount::RecurringEBITAccount(const RecurringEBITAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void RecurringEBITAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void RecurringEBITAccount::init() {
   FlowAccount::init();
	init_RecurringEBITAccount();
}

void RecurringEBITAccount::init_RecurringEBITAccount() {
   set_id("RecurringEBITAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

RecurringEBITAccount::~RecurringEBITAccount()	{ cleanMem(); }

void RecurringEBITAccount::cleanMem()	{
	cleanMem_RecurringEBITAccount();
   FlowAccount::cleanMem();
}

void RecurringEBITAccount::cleanMem_RecurringEBITAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string RecurringEBITAccount::className() const {return "RecurringEBITAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void RecurringEBITAccount::myerr_msg(string msg, string func) {
	err_msg("RecurringEBITAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void RecurringEBITAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_RecurringEBITAccount(fname);
}

void RecurringEBITAccount::fprint_RecurringEBITAccount(string fname) {
}

void RecurringEBITAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_RecurringEBITAccount(fname);
}

void RecurringEBITAccount::fscan_RecurringEBITAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void RecurringEBITAccount::reset() {
	reset_RecurringEBITAccount();
   FlowAccount::reset();
}

void RecurringEBITAccount::reset_RecurringEBITAccount() {
}

/** ----------  static instance function -----------*/


RecurringEBITAccount* RecurringEBITAccount::instance()	{
	RecurringEBITAccount* ptr = NULL;
   string id = "RecurringEBITAccount";

   ptr = (RecurringEBITAccount*) util_singleton("RecurringEBITAccount",id);
   if(ptr==NULL) {
      ptr = new RecurringEBITAccount();
      ptr->init();
      util_singleton("RecurringEBITAccount",id,ptr);
   }
	return ptr;
}

RecurringEBITAccount* RecurringEBITAccount::instance_fscan(string fname)	{
   return RecurringEBITAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

RecurringEBITAccount* RecurringEBITAccount::__ptr_RecurringEBITAccount = RecurringEBITAccount::instance();

#endif

