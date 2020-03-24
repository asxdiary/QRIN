// Name:     R_NetInterestExpense_OperatingProfitAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_R_NetInterestExpense_OperatingProfitAccount_cpp
#define ASX_R_NetInterestExpense_OperatingProfitAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "R_DoubleDbAccount.hpp"
#include "NetInterestExpenseAccount.hpp"
#include "OperatingProfitAccount.hpp"
#include "R_NetInterestExpense_OperatingProfitAccount.hpp"
#include "OperatingRevenueAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctFields;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

R_NetInterestExpense_OperatingProfitAccount::R_NetInterestExpense_OperatingProfitAccount() { init_NULL(); }
R_NetInterestExpense_OperatingProfitAccount::R_NetInterestExpense_OperatingProfitAccount(const R_NetInterestExpense_OperatingProfitAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
R_NetInterestExpense_OperatingProfitAccount::R_NetInterestExpense_OperatingProfitAccount(const R_NetInterestExpense_OperatingProfitAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void R_NetInterestExpense_OperatingProfitAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void R_NetInterestExpense_OperatingProfitAccount::init() {
   R_DoubleDbAccount::init(NetInterestExpenseAccount::instance(),
                           OperatingProfitAccount::instance(),
                           false, false);
   init_R_NetInterestExpense_OperatingProfitAccount();
}

void R_NetInterestExpense_OperatingProfitAccount::init_R_NetInterestExpense_OperatingProfitAccount() {
   set_id("R_NetInterestExpense_OperatingProfitAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

R_NetInterestExpense_OperatingProfitAccount::~R_NetInterestExpense_OperatingProfitAccount()	{ cleanMem(); }

void R_NetInterestExpense_OperatingProfitAccount::cleanMem()	{
	cleanMem_R_NetInterestExpense_OperatingProfitAccount();
   R_DoubleDbAccount::cleanMem();
}

void R_NetInterestExpense_OperatingProfitAccount::cleanMem_R_NetInterestExpense_OperatingProfitAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string R_NetInterestExpense_OperatingProfitAccount::className() const {return "R_NetInterestExpense_OperatingProfitAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void R_NetInterestExpense_OperatingProfitAccount::myerr_msg(string msg, string func) {
	err_msg("R_NetInterestExpense_OperatingProfitAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void R_NetInterestExpense_OperatingProfitAccount::fprint(string fname) {
   R_DoubleDbAccount::fprint(fname);
	fprint_R_NetInterestExpense_OperatingProfitAccount(fname);
}

void R_NetInterestExpense_OperatingProfitAccount::fprint_R_NetInterestExpense_OperatingProfitAccount(string fname) {
}

void R_NetInterestExpense_OperatingProfitAccount::fscan(string fname) {
   R_DoubleDbAccount::fscan(fname);
	fscan_R_NetInterestExpense_OperatingProfitAccount(fname);
}

void R_NetInterestExpense_OperatingProfitAccount::fscan_R_NetInterestExpense_OperatingProfitAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void R_NetInterestExpense_OperatingProfitAccount::reset() {
	reset_R_NetInterestExpense_OperatingProfitAccount();
   R_DoubleDbAccount::reset();
}

void R_NetInterestExpense_OperatingProfitAccount::reset_R_NetInterestExpense_OperatingProfitAccount() {
}

/** ----------  static instance function -----------*/


R_NetInterestExpense_OperatingProfitAccount* R_NetInterestExpense_OperatingProfitAccount::instance()	{
	R_NetInterestExpense_OperatingProfitAccount* ptr = NULL;
   string id = "R_NetInterestExpense_OperatingProfitAccount";

   ptr = (R_NetInterestExpense_OperatingProfitAccount*) util_singleton("R_NetInterestExpense_OperatingProfitAccount",id);
   if(ptr==NULL) {
      ptr = new R_NetInterestExpense_OperatingProfitAccount();
      ptr->init();
      util_singleton("R_NetInterestExpense_OperatingProfitAccount",id,ptr);
   }
	return ptr;
}

R_NetInterestExpense_OperatingProfitAccount* R_NetInterestExpense_OperatingProfitAccount::instance_fscan(string fname)	{
   return R_NetInterestExpense_OperatingProfitAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

R_NetInterestExpense_OperatingProfitAccount* R_NetInterestExpense_OperatingProfitAccount::__ptr_R_NetInterestExpense_OperatingProfitAccount = R_NetInterestExpense_OperatingProfitAccount::instance();

#endif

