// Name:     TemplateFlowAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_TemplateFlowAccount_cpp
#define ASX_TemplateFlowAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "TemplateFlowAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

TemplateFlowAccount::TemplateFlowAccount() { init_NULL(); }
TemplateFlowAccount::TemplateFlowAccount(const TemplateFlowAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
TemplateFlowAccount::TemplateFlowAccount(const TemplateFlowAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void TemplateFlowAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void TemplateFlowAccount::init() {
   FlowAccount::init();
	init_TemplateFlowAccount();
}

void TemplateFlowAccount::init_TemplateFlowAccount() {
   set_id("TemplateFlowAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

TemplateFlowAccount::~TemplateFlowAccount()	{ cleanMem(); }

void TemplateFlowAccount::cleanMem()	{
	cleanMem_TemplateFlowAccount();
   FlowAccount::cleanMem();
}

void TemplateFlowAccount::cleanMem_TemplateFlowAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string TemplateFlowAccount::className() const {return "TemplateFlowAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void TemplateFlowAccount::myerr_msg(string msg, string func) {
	err_msg("TemplateFlowAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void TemplateFlowAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_TemplateFlowAccount(fname);
}

void TemplateFlowAccount::fprint_TemplateFlowAccount(string fname) {
}

void TemplateFlowAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_TemplateFlowAccount(fname);
}

void TemplateFlowAccount::fscan_TemplateFlowAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void TemplateFlowAccount::reset() {
	reset_TemplateFlowAccount();
   FlowAccount::reset();
}

void TemplateFlowAccount::reset_TemplateFlowAccount() {
}

/** ----------  static instance function -----------*/


TemplateFlowAccount* TemplateFlowAccount::instance()	{
	TemplateFlowAccount* ptr = NULL;
   string id = "TemplateFlowAccount";

   ptr = (TemplateFlowAccount*) util_singleton("TemplateFlowAccount",id);
   if(ptr==NULL) {
      ptr = new TemplateFlowAccount();
      ptr->init();
      util_singleton("TemplateFlowAccount",id,ptr);
   }
	return ptr;
}

TemplateFlowAccount* TemplateFlowAccount::instance_fscan(string fname)	{
   return TemplateFlowAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

TemplateFlowAccount* TemplateFlowAccount::__ptr_TemplateFlowAccount = TemplateFlowAccount::instance();

#endif

