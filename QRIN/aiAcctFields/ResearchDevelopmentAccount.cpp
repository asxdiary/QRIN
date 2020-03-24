// Name:     ResearchDevelopmentAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ResearchDevelopmentAccount_cpp
#define ASX_ResearchDevelopmentAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "ResearchDevelopmentAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

ResearchDevelopmentAccount::ResearchDevelopmentAccount() { init_NULL(); }
ResearchDevelopmentAccount::ResearchDevelopmentAccount(const ResearchDevelopmentAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
ResearchDevelopmentAccount::ResearchDevelopmentAccount(const ResearchDevelopmentAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void ResearchDevelopmentAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void ResearchDevelopmentAccount::init() {
   FlowAccount::init();
	init_ResearchDevelopmentAccount();
}

void ResearchDevelopmentAccount::init_ResearchDevelopmentAccount() {
   set_id("ResearchDevelopmentAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

ResearchDevelopmentAccount::~ResearchDevelopmentAccount()	{ cleanMem(); }

void ResearchDevelopmentAccount::cleanMem()	{
	cleanMem_ResearchDevelopmentAccount();
   FlowAccount::cleanMem();
}

void ResearchDevelopmentAccount::cleanMem_ResearchDevelopmentAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string ResearchDevelopmentAccount::className() const {return "ResearchDevelopmentAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void ResearchDevelopmentAccount::myerr_msg(string msg, string func) {
	err_msg("ResearchDevelopmentAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void ResearchDevelopmentAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_ResearchDevelopmentAccount(fname);
}

void ResearchDevelopmentAccount::fprint_ResearchDevelopmentAccount(string fname) {
}

void ResearchDevelopmentAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_ResearchDevelopmentAccount(fname);
}

void ResearchDevelopmentAccount::fscan_ResearchDevelopmentAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void ResearchDevelopmentAccount::reset() {
	reset_ResearchDevelopmentAccount();
   FlowAccount::reset();
}

void ResearchDevelopmentAccount::reset_ResearchDevelopmentAccount() {
}

/** ----------  static instance function -----------*/


ResearchDevelopmentAccount* ResearchDevelopmentAccount::instance()	{
	ResearchDevelopmentAccount* ptr = NULL;
   string id = "ResearchDevelopmentAccount";

   ptr = (ResearchDevelopmentAccount*) util_singleton("ResearchDevelopmentAccount",id);
   if(ptr==NULL) {
      ptr = new ResearchDevelopmentAccount();
      ptr->init();
      util_singleton("ResearchDevelopmentAccount",id,ptr);
   }
	return ptr;
}

ResearchDevelopmentAccount* ResearchDevelopmentAccount::instance_fscan(string fname)	{
   return ResearchDevelopmentAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

ResearchDevelopmentAccount* ResearchDevelopmentAccount::__ptr_ResearchDevelopmentAccount = ResearchDevelopmentAccount::instance();

#endif

