// Name:     GrossProfitAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_GrossProfitAccount_cpp
#define ASX_GrossProfitAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "GrossProfitAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

GrossProfitAccount::GrossProfitAccount() { init_NULL(); }
GrossProfitAccount::GrossProfitAccount(const GrossProfitAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
GrossProfitAccount::GrossProfitAccount(const GrossProfitAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void GrossProfitAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void GrossProfitAccount::init() {
   FlowAccount::init();
	init_GrossProfitAccount();
}

void GrossProfitAccount::init_GrossProfitAccount() {
   set_id("GrossProfitAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

GrossProfitAccount::~GrossProfitAccount()	{ cleanMem(); }

void GrossProfitAccount::cleanMem()	{
	cleanMem_GrossProfitAccount();
   FlowAccount::cleanMem();
}

void GrossProfitAccount::cleanMem_GrossProfitAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string GrossProfitAccount::className() const {return "GrossProfitAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void GrossProfitAccount::myerr_msg(string msg, string func) {
	err_msg("GrossProfitAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void GrossProfitAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_GrossProfitAccount(fname);
}

void GrossProfitAccount::fprint_GrossProfitAccount(string fname) {
}

void GrossProfitAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_GrossProfitAccount(fname);
}

void GrossProfitAccount::fscan_GrossProfitAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void GrossProfitAccount::reset() {
	reset_GrossProfitAccount();
   FlowAccount::reset();
}

void GrossProfitAccount::reset_GrossProfitAccount() {
}

/** ----------  static instance function -----------*/


GrossProfitAccount* GrossProfitAccount::instance()	{
	GrossProfitAccount* ptr = NULL;
   string id = "GrossProfitAccount";

   ptr = (GrossProfitAccount*) util_singleton("GrossProfitAccount",id);
   if(ptr==NULL) {
      ptr = new GrossProfitAccount();
      ptr->init();
      util_singleton("GrossProfitAccount",id,ptr);
   }
	return ptr;
}

GrossProfitAccount* GrossProfitAccount::instance_fscan(string fname)	{
   return GrossProfitAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

GrossProfitAccount* GrossProfitAccount::__ptr_GrossProfitAccount = GrossProfitAccount::instance();

#endif

