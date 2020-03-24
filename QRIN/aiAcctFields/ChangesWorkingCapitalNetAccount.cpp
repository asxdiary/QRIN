// Name:     ChangesWorkingCapitalNetAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ChangesWorkingCapitalNetAccount_cpp
#define ASX_ChangesWorkingCapitalNetAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "ChangesWorkingCapitalNetAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

ChangesWorkingCapitalNetAccount::ChangesWorkingCapitalNetAccount() { init_NULL(); }
ChangesWorkingCapitalNetAccount::ChangesWorkingCapitalNetAccount(const ChangesWorkingCapitalNetAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
ChangesWorkingCapitalNetAccount::ChangesWorkingCapitalNetAccount(const ChangesWorkingCapitalNetAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void ChangesWorkingCapitalNetAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void ChangesWorkingCapitalNetAccount::init() {
   FlowAccount::init();
	init_ChangesWorkingCapitalNetAccount();
}

void ChangesWorkingCapitalNetAccount::init_ChangesWorkingCapitalNetAccount() {
   set_id("ChangesWorkingCapitalNetAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

ChangesWorkingCapitalNetAccount::~ChangesWorkingCapitalNetAccount()	{ cleanMem(); }

void ChangesWorkingCapitalNetAccount::cleanMem()	{
	cleanMem_ChangesWorkingCapitalNetAccount();
   FlowAccount::cleanMem();
}

void ChangesWorkingCapitalNetAccount::cleanMem_ChangesWorkingCapitalNetAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string ChangesWorkingCapitalNetAccount::className() const {return "ChangesWorkingCapitalNetAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void ChangesWorkingCapitalNetAccount::myerr_msg(string msg, string func) {
	err_msg("ChangesWorkingCapitalNetAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void ChangesWorkingCapitalNetAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_ChangesWorkingCapitalNetAccount(fname);
}

void ChangesWorkingCapitalNetAccount::fprint_ChangesWorkingCapitalNetAccount(string fname) {
}

void ChangesWorkingCapitalNetAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_ChangesWorkingCapitalNetAccount(fname);
}

void ChangesWorkingCapitalNetAccount::fscan_ChangesWorkingCapitalNetAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void ChangesWorkingCapitalNetAccount::reset() {
	reset_ChangesWorkingCapitalNetAccount();
   FlowAccount::reset();
}

void ChangesWorkingCapitalNetAccount::reset_ChangesWorkingCapitalNetAccount() {
}

/** ----------  static instance function -----------*/


ChangesWorkingCapitalNetAccount* ChangesWorkingCapitalNetAccount::instance()	{
	ChangesWorkingCapitalNetAccount* ptr = NULL;
   string id = "ChangesWorkingCapitalNetAccount";

   ptr = (ChangesWorkingCapitalNetAccount*) util_singleton("ChangesWorkingCapitalNetAccount",id);
   if(ptr==NULL) {
      ptr = new ChangesWorkingCapitalNetAccount();
      ptr->init();
      util_singleton("ChangesWorkingCapitalNetAccount",id,ptr);
   }
	return ptr;
}

ChangesWorkingCapitalNetAccount* ChangesWorkingCapitalNetAccount::instance_fscan(string fname)	{
   return ChangesWorkingCapitalNetAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

ChangesWorkingCapitalNetAccount* ChangesWorkingCapitalNetAccount::__ptr_ChangesWorkingCapitalNetAccount = ChangesWorkingCapitalNetAccount::instance();

#endif

