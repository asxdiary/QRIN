// Name:     DividendsPerShareAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DividendsPerShareAccount_cpp
#define ASX_DividendsPerShareAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "DividendsPerShareAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

DividendsPerShareAccount::DividendsPerShareAccount() { init_NULL(); }
DividendsPerShareAccount::DividendsPerShareAccount(const DividendsPerShareAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
DividendsPerShareAccount::DividendsPerShareAccount(const DividendsPerShareAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void DividendsPerShareAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void DividendsPerShareAccount::init() {
   FlowAccount::init();
	init_DividendsPerShareAccount();
}

void DividendsPerShareAccount::init_DividendsPerShareAccount() {
   set_id("DividendsPerShareAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

DividendsPerShareAccount::~DividendsPerShareAccount()	{ cleanMem(); }

void DividendsPerShareAccount::cleanMem()	{
	cleanMem_DividendsPerShareAccount();
   FlowAccount::cleanMem();
}

void DividendsPerShareAccount::cleanMem_DividendsPerShareAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string DividendsPerShareAccount::className() const {return "DividendsPerShareAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void DividendsPerShareAccount::myerr_msg(string msg, string func) {
	err_msg("DividendsPerShareAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void DividendsPerShareAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_DividendsPerShareAccount(fname);
}

void DividendsPerShareAccount::fprint_DividendsPerShareAccount(string fname) {
}

void DividendsPerShareAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_DividendsPerShareAccount(fname);
}

void DividendsPerShareAccount::fscan_DividendsPerShareAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void DividendsPerShareAccount::reset() {
	reset_DividendsPerShareAccount();
   FlowAccount::reset();
}

void DividendsPerShareAccount::reset_DividendsPerShareAccount() {
}

/** ----------  static instance function -----------*/


DividendsPerShareAccount* DividendsPerShareAccount::instance()	{
	DividendsPerShareAccount* ptr = NULL;
   string id = "DividendsPerShareAccount";

   ptr = (DividendsPerShareAccount*) util_singleton("DividendsPerShareAccount",id);
   if(ptr==NULL) {
      ptr = new DividendsPerShareAccount();
      ptr->init();
      util_singleton("DividendsPerShareAccount",id,ptr);
   }
	return ptr;
}

DividendsPerShareAccount* DividendsPerShareAccount::instance_fscan(string fname)	{
   return DividendsPerShareAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

DividendsPerShareAccount* DividendsPerShareAccount::__ptr_DividendsPerShareAccount = DividendsPerShareAccount::instance();

#endif

