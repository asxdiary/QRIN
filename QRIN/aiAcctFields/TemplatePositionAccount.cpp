// Name:     TemplatePositionAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_TemplatePositionAccount_cpp
#define ASX_TemplatePositionAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "TemplatePositionAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

TemplatePositionAccount::TemplatePositionAccount() { init_NULL(); }
TemplatePositionAccount::TemplatePositionAccount(const TemplatePositionAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
TemplatePositionAccount::TemplatePositionAccount(const TemplatePositionAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void TemplatePositionAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void TemplatePositionAccount::init() {
   PositionAccount::init();
	init_TemplatePositionAccount();
}

void TemplatePositionAccount::init_TemplatePositionAccount() {
   set_id("TemplatePositionAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

TemplatePositionAccount::~TemplatePositionAccount()	{ cleanMem(); }

void TemplatePositionAccount::cleanMem()	{
	cleanMem_TemplatePositionAccount();
   PositionAccount::cleanMem();
}

void TemplatePositionAccount::cleanMem_TemplatePositionAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string TemplatePositionAccount::className() const {return "TemplatePositionAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void TemplatePositionAccount::myerr_msg(string msg, string func) {
	err_msg("TemplatePositionAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void TemplatePositionAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_TemplatePositionAccount(fname);
}

void TemplatePositionAccount::fprint_TemplatePositionAccount(string fname) {
}

void TemplatePositionAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_TemplatePositionAccount(fname);
}

void TemplatePositionAccount::fscan_TemplatePositionAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void TemplatePositionAccount::reset() {
	reset_TemplatePositionAccount();
   PositionAccount::reset();
}

void TemplatePositionAccount::reset_TemplatePositionAccount() {
}

/** ----------  static instance function -----------*/


TemplatePositionAccount* TemplatePositionAccount::instance()	{
	TemplatePositionAccount* ptr = NULL;
   string id = "TemplatePositionAccount";

   ptr = (TemplatePositionAccount*) util_singleton("TemplatePositionAccount",id);
   if(ptr==NULL) {
      ptr = new TemplatePositionAccount();
      ptr->init();
      util_singleton("TemplatePositionAccount",id,ptr);
   }
	return ptr;
}

TemplatePositionAccount* TemplatePositionAccount::instance_fscan(string fname)	{
   return TemplatePositionAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

TemplatePositionAccount* TemplatePositionAccount::__ptr_TemplatePositionAccount = TemplatePositionAccount::instance();

#endif

