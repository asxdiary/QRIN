// Name:     R_Liabilities_AssetsAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_R_Liabilities_AssetsAccount_cpp
#define ASX_R_Liabilities_AssetsAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "R_DoubleDbAccount.hpp"
#include "TotalLiabilitiesAccount.hpp"
#include "TotalAssetsAccount.hpp"
#include "R_Liabilities_AssetsAccount.hpp"
#include "OperatingRevenueAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctFields;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

R_Liabilities_AssetsAccount::R_Liabilities_AssetsAccount() { init_NULL(); }
R_Liabilities_AssetsAccount::R_Liabilities_AssetsAccount(const R_Liabilities_AssetsAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
R_Liabilities_AssetsAccount::R_Liabilities_AssetsAccount(const R_Liabilities_AssetsAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void R_Liabilities_AssetsAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void R_Liabilities_AssetsAccount::init() {
   R_DoubleDbAccount::init(TotalLiabilitiesAccount::instance(),
                           TotalAssetsAccount::instance(),
                           false, false);
   init_R_Liabilities_AssetsAccount();
}

void R_Liabilities_AssetsAccount::init_R_Liabilities_AssetsAccount() {
   set_id("R_Liabilities_AssetsAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

R_Liabilities_AssetsAccount::~R_Liabilities_AssetsAccount()	{ cleanMem(); }

void R_Liabilities_AssetsAccount::cleanMem()	{
	cleanMem_R_Liabilities_AssetsAccount();
   R_DoubleDbAccount::cleanMem();
}

void R_Liabilities_AssetsAccount::cleanMem_R_Liabilities_AssetsAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string R_Liabilities_AssetsAccount::className() const {return "R_Liabilities_AssetsAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void R_Liabilities_AssetsAccount::myerr_msg(string msg, string func) {
	err_msg("R_Liabilities_AssetsAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void R_Liabilities_AssetsAccount::fprint(string fname) {
   R_DoubleDbAccount::fprint(fname);
	fprint_R_Liabilities_AssetsAccount(fname);
}

void R_Liabilities_AssetsAccount::fprint_R_Liabilities_AssetsAccount(string fname) {
}

void R_Liabilities_AssetsAccount::fscan(string fname) {
   R_DoubleDbAccount::fscan(fname);
	fscan_R_Liabilities_AssetsAccount(fname);
}

void R_Liabilities_AssetsAccount::fscan_R_Liabilities_AssetsAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void R_Liabilities_AssetsAccount::reset() {
	reset_R_Liabilities_AssetsAccount();
   R_DoubleDbAccount::reset();
}

void R_Liabilities_AssetsAccount::reset_R_Liabilities_AssetsAccount() {
}

/** ----------  static instance function -----------*/


R_Liabilities_AssetsAccount* R_Liabilities_AssetsAccount::instance()	{
	R_Liabilities_AssetsAccount* ptr = NULL;
   string id = "R_Liabilities_AssetsAccount";

   ptr = (R_Liabilities_AssetsAccount*) util_singleton("R_Liabilities_AssetsAccount",id);
   if(ptr==NULL) {
      ptr = new R_Liabilities_AssetsAccount();
      ptr->init();
      util_singleton("R_Liabilities_AssetsAccount",id,ptr);
   }
	return ptr;
}

R_Liabilities_AssetsAccount* R_Liabilities_AssetsAccount::instance_fscan(string fname)	{
   return R_Liabilities_AssetsAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

R_Liabilities_AssetsAccount* R_Liabilities_AssetsAccount::__ptr_R_Liabilities_AssetsAccount = R_Liabilities_AssetsAccount::instance();

#endif

