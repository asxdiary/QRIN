// Name:     ReceivablesTOAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ReceivablesTOAccount_cpp
#define ASX_ReceivablesTOAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "R_DoubleDbAccount.hpp"
#include "OperatingRevenueAccount.hpp"
#include "ReceivablesNetAccount.hpp"
#include "ReceivablesTOAccount.hpp"
#include "OperatingRevenueAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctFields;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

ReceivablesTOAccount::ReceivablesTOAccount() { init_NULL(); }
ReceivablesTOAccount::ReceivablesTOAccount(const ReceivablesTOAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
ReceivablesTOAccount::ReceivablesTOAccount(const ReceivablesTOAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void ReceivablesTOAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void ReceivablesTOAccount::init() {
   R_DoubleDbAccount::init(OperatingRevenueAccount::instance(),
                           ReceivablesNetAccount::instance(),
                           true, false);
   init_ReceivablesTOAccount();
}

void ReceivablesTOAccount::init_ReceivablesTOAccount() {
   set_id("ReceivablesTOAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

ReceivablesTOAccount::~ReceivablesTOAccount()	{ cleanMem(); }

void ReceivablesTOAccount::cleanMem()	{
	cleanMem_ReceivablesTOAccount();
   R_DoubleDbAccount::cleanMem();
}

void ReceivablesTOAccount::cleanMem_ReceivablesTOAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string ReceivablesTOAccount::className() const {return "ReceivablesTOAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void ReceivablesTOAccount::myerr_msg(string msg, string func) {
	err_msg("ReceivablesTOAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void ReceivablesTOAccount::fprint(string fname) {
   R_DoubleDbAccount::fprint(fname);
	fprint_ReceivablesTOAccount(fname);
}

void ReceivablesTOAccount::fprint_ReceivablesTOAccount(string fname) {
}

void ReceivablesTOAccount::fscan(string fname) {
   R_DoubleDbAccount::fscan(fname);
	fscan_ReceivablesTOAccount(fname);
}

void ReceivablesTOAccount::fscan_ReceivablesTOAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void ReceivablesTOAccount::reset() {
	reset_ReceivablesTOAccount();
   R_DoubleDbAccount::reset();
}

void ReceivablesTOAccount::reset_ReceivablesTOAccount() {
}

/** ----------  static instance function -----------*/


ReceivablesTOAccount* ReceivablesTOAccount::instance()	{
	ReceivablesTOAccount* ptr = NULL;
   string id = "ReceivablesTOAccount";

   ptr = (ReceivablesTOAccount*) util_singleton("ReceivablesTOAccount",id);
   if(ptr==NULL) {
      ptr = new ReceivablesTOAccount();
      ptr->init();
      util_singleton("ReceivablesTOAccount",id,ptr);
   }
	return ptr;
}

ReceivablesTOAccount* ReceivablesTOAccount::instance_fscan(string fname)	{
   return ReceivablesTOAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

ReceivablesTOAccount* ReceivablesTOAccount::__ptr_ReceivablesTOAccount = ReceivablesTOAccount::instance();

#endif

