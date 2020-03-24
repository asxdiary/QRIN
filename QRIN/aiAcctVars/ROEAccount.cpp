// Name:     ROEAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ROEAccount_cpp
#define ASX_ROEAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "R_DoubleDbAccount.hpp"
#include "NetIncomeAccount.hpp"
#include "TotalEquityCapitalAccount.hpp"
#include "ROEAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctFields;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

ROEAccount::ROEAccount() { init_NULL(); }
ROEAccount::ROEAccount(const ROEAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
ROEAccount::ROEAccount(const ROEAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void ROEAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void ROEAccount::init() {
   R_DoubleDbAccount::init(NetIncomeAccount::instance(),
                      TotalEquityCapitalAccount::instance(),
                      true, false);
	init_ROEAccount();
}

void ROEAccount::init_ROEAccount() {
   set_id("ROEAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

ROEAccount::~ROEAccount()	{ cleanMem(); }

void ROEAccount::cleanMem()	{
	cleanMem_ROEAccount();
   R_DoubleDbAccount::cleanMem();
}

void ROEAccount::cleanMem_ROEAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string ROEAccount::className() const {return "ROEAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void ROEAccount::myerr_msg(string msg, string func) {
	err_msg("ROEAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void ROEAccount::fprint(string fname) {
   R_DoubleDbAccount::fprint(fname);
	fprint_ROEAccount(fname);
}

void ROEAccount::fprint_ROEAccount(string fname) {
}

void ROEAccount::fscan(string fname) {
   R_DoubleDbAccount::fscan(fname);
	fscan_ROEAccount(fname);
}

void ROEAccount::fscan_ROEAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void ROEAccount::reset() {
	reset_ROEAccount();
   R_DoubleDbAccount::reset();
}

void ROEAccount::reset_ROEAccount() {
}

/** ----------  static instance function -----------*/


ROEAccount* ROEAccount::instance()	{
	ROEAccount* ptr = NULL;
   string id = "ROEAccount";

   ptr = (ROEAccount*) util_singleton("ROEAccount",id);
   if(ptr==NULL) {
      ptr = new ROEAccount();
      ptr->init();
      util_singleton("ROEAccount",id,ptr);
   }
	return ptr;
}

ROEAccount* ROEAccount::instance_fscan(string fname)	{
   return ROEAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

ROEAccount* ROEAccount::__ptr_ROEAccount = ROEAccount::instance();

#endif

