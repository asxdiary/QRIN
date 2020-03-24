// Name:     ReceivablesNetAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ReceivablesNetAccount_cpp
#define ASX_ReceivablesNetAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "ReceivablesNetAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

ReceivablesNetAccount::ReceivablesNetAccount() { init_NULL(); }
ReceivablesNetAccount::ReceivablesNetAccount(const ReceivablesNetAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
ReceivablesNetAccount::ReceivablesNetAccount(const ReceivablesNetAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void ReceivablesNetAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void ReceivablesNetAccount::init() {
   PositionAccount::init();
	init_ReceivablesNetAccount();
}

void ReceivablesNetAccount::init_ReceivablesNetAccount() {
   set_id("ReceivablesNetAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

ReceivablesNetAccount::~ReceivablesNetAccount()	{ cleanMem(); }

void ReceivablesNetAccount::cleanMem()	{
	cleanMem_ReceivablesNetAccount();
   PositionAccount::cleanMem();
}

void ReceivablesNetAccount::cleanMem_ReceivablesNetAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string ReceivablesNetAccount::className() const {return "ReceivablesNetAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void ReceivablesNetAccount::myerr_msg(string msg, string func) {
	err_msg("ReceivablesNetAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void ReceivablesNetAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_ReceivablesNetAccount(fname);
}

void ReceivablesNetAccount::fprint_ReceivablesNetAccount(string fname) {
}

void ReceivablesNetAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_ReceivablesNetAccount(fname);
}

void ReceivablesNetAccount::fscan_ReceivablesNetAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void ReceivablesNetAccount::reset() {
	reset_ReceivablesNetAccount();
   PositionAccount::reset();
}

void ReceivablesNetAccount::reset_ReceivablesNetAccount() {
}

/** ----------  static instance function -----------*/


ReceivablesNetAccount* ReceivablesNetAccount::instance()	{
	ReceivablesNetAccount* ptr = NULL;
   string id = "ReceivablesNetAccount";

   ptr = (ReceivablesNetAccount*) util_singleton("ReceivablesNetAccount",id);
   if(ptr==NULL) {
      ptr = new ReceivablesNetAccount();
      ptr->init();
      util_singleton("ReceivablesNetAccount",id,ptr);
   }
	return ptr;
}

ReceivablesNetAccount* ReceivablesNetAccount::instance_fscan(string fname)	{
   return ReceivablesNetAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

ReceivablesNetAccount* ReceivablesNetAccount::__ptr_ReceivablesNetAccount = ReceivablesNetAccount::instance();

#endif

