// Name:     R_Debt_EquityAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_R_Debt_EquityAccount_cpp
#define ASX_R_Debt_EquityAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "R_DoubleDbAccount.hpp"
#include "TotalLiabilitiesAccount.hpp"
#include "TotalEquityCapitalAccount.hpp"
#include "R_Debt_EquityAccount.hpp"
#include "OperatingRevenueAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctFields;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

R_Debt_EquityAccount::R_Debt_EquityAccount() { init_NULL(); }
R_Debt_EquityAccount::R_Debt_EquityAccount(const R_Debt_EquityAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
R_Debt_EquityAccount::R_Debt_EquityAccount(const R_Debt_EquityAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void R_Debt_EquityAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void R_Debt_EquityAccount::init() {
   R_DoubleDbAccount::init(TotalLiabilitiesAccount::instance(),
                           TotalEquityCapitalAccount::instance(),
                           false, false);
   init_R_Debt_EquityAccount();
}

void R_Debt_EquityAccount::init_R_Debt_EquityAccount() {
   set_id("R_Debt_EquityAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

R_Debt_EquityAccount::~R_Debt_EquityAccount()	{ cleanMem(); }

void R_Debt_EquityAccount::cleanMem()	{
	cleanMem_R_Debt_EquityAccount();
   R_DoubleDbAccount::cleanMem();
}

void R_Debt_EquityAccount::cleanMem_R_Debt_EquityAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string R_Debt_EquityAccount::className() const {return "R_Debt_EquityAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void R_Debt_EquityAccount::myerr_msg(string msg, string func) {
	err_msg("R_Debt_EquityAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void R_Debt_EquityAccount::fprint(string fname) {
   R_DoubleDbAccount::fprint(fname);
	fprint_R_Debt_EquityAccount(fname);
}

void R_Debt_EquityAccount::fprint_R_Debt_EquityAccount(string fname) {
}

void R_Debt_EquityAccount::fscan(string fname) {
   R_DoubleDbAccount::fscan(fname);
	fscan_R_Debt_EquityAccount(fname);
}

void R_Debt_EquityAccount::fscan_R_Debt_EquityAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void R_Debt_EquityAccount::reset() {
	reset_R_Debt_EquityAccount();
   R_DoubleDbAccount::reset();
}

void R_Debt_EquityAccount::reset_R_Debt_EquityAccount() {
}

/** ----------  static instance function -----------*/


R_Debt_EquityAccount* R_Debt_EquityAccount::instance()	{
	R_Debt_EquityAccount* ptr = NULL;
   string id = "R_Debt_EquityAccount";

   ptr = (R_Debt_EquityAccount*) util_singleton("R_Debt_EquityAccount",id);
   if(ptr==NULL) {
      ptr = new R_Debt_EquityAccount();
      ptr->init();
      util_singleton("R_Debt_EquityAccount",id,ptr);
   }
	return ptr;
}

R_Debt_EquityAccount* R_Debt_EquityAccount::instance_fscan(string fname)	{
   return R_Debt_EquityAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

R_Debt_EquityAccount* R_Debt_EquityAccount::__ptr_R_Debt_EquityAccount = R_Debt_EquityAccount::instance();

#endif

