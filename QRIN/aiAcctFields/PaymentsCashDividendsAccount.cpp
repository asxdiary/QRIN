// Name:     PaymentsCashDividendsAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_PaymentsCashDividendsAccount_cpp
#define ASX_PaymentsCashDividendsAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "PaymentsCashDividendsAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

PaymentsCashDividendsAccount::PaymentsCashDividendsAccount() { init_NULL(); }
PaymentsCashDividendsAccount::PaymentsCashDividendsAccount(const PaymentsCashDividendsAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
PaymentsCashDividendsAccount::PaymentsCashDividendsAccount(const PaymentsCashDividendsAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void PaymentsCashDividendsAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void PaymentsCashDividendsAccount::init() {
   FlowAccount::init();
	init_PaymentsCashDividendsAccount();
}

void PaymentsCashDividendsAccount::init_PaymentsCashDividendsAccount() {
   set_id("PaymentsCashDividendsAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

PaymentsCashDividendsAccount::~PaymentsCashDividendsAccount()	{ cleanMem(); }

void PaymentsCashDividendsAccount::cleanMem()	{
	cleanMem_PaymentsCashDividendsAccount();
   FlowAccount::cleanMem();
}

void PaymentsCashDividendsAccount::cleanMem_PaymentsCashDividendsAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string PaymentsCashDividendsAccount::className() const {return "PaymentsCashDividendsAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void PaymentsCashDividendsAccount::myerr_msg(string msg, string func) {
	err_msg("PaymentsCashDividendsAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void PaymentsCashDividendsAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_PaymentsCashDividendsAccount(fname);
}

void PaymentsCashDividendsAccount::fprint_PaymentsCashDividendsAccount(string fname) {
}

void PaymentsCashDividendsAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_PaymentsCashDividendsAccount(fname);
}

void PaymentsCashDividendsAccount::fscan_PaymentsCashDividendsAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void PaymentsCashDividendsAccount::reset() {
	reset_PaymentsCashDividendsAccount();
   FlowAccount::reset();
}

void PaymentsCashDividendsAccount::reset_PaymentsCashDividendsAccount() {
}

/** ----------  static instance function -----------*/


PaymentsCashDividendsAccount* PaymentsCashDividendsAccount::instance()	{
	PaymentsCashDividendsAccount* ptr = NULL;
   string id = "PaymentsCashDividendsAccount";

   ptr = (PaymentsCashDividendsAccount*) util_singleton("PaymentsCashDividendsAccount",id);
   if(ptr==NULL) {
      ptr = new PaymentsCashDividendsAccount();
      ptr->init();
      util_singleton("PaymentsCashDividendsAccount",id,ptr);
   }
	return ptr;
}

PaymentsCashDividendsAccount* PaymentsCashDividendsAccount::instance_fscan(string fname)	{
   return PaymentsCashDividendsAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

PaymentsCashDividendsAccount* PaymentsCashDividendsAccount::__ptr_PaymentsCashDividendsAccount = PaymentsCashDividendsAccount::instance();

#endif

