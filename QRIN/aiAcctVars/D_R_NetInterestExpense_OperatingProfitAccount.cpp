// Name:     D_R_NetInterestExpense_OperatingProfitAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_R_NetInterestExpense_OperatingProfitAccount_cpp
#define ASX_D_R_NetInterestExpense_OperatingProfitAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "D_DoubleDbAccount.hpp"
#include "R_NetInterestExpense_OperatingProfitAccount.hpp"
#include "D_R_NetInterestExpense_OperatingProfitAccount.hpp"
#include "TemplatePositionAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctVars;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

D_R_NetInterestExpense_OperatingProfitAccount::D_R_NetInterestExpense_OperatingProfitAccount() { init_NULL(); }
D_R_NetInterestExpense_OperatingProfitAccount::D_R_NetInterestExpense_OperatingProfitAccount(const D_R_NetInterestExpense_OperatingProfitAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
D_R_NetInterestExpense_OperatingProfitAccount::D_R_NetInterestExpense_OperatingProfitAccount(const D_R_NetInterestExpense_OperatingProfitAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void D_R_NetInterestExpense_OperatingProfitAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void D_R_NetInterestExpense_OperatingProfitAccount::init() {
   D_DoubleDbAccount::init(R_NetInterestExpense_OperatingProfitAccount::instance());
	init_D_R_NetInterestExpense_OperatingProfitAccount();
}

void D_R_NetInterestExpense_OperatingProfitAccount::init_D_R_NetInterestExpense_OperatingProfitAccount() {
   set_id("D_R_NetInterestExpense_OperatingProfitAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

D_R_NetInterestExpense_OperatingProfitAccount::~D_R_NetInterestExpense_OperatingProfitAccount()	{ cleanMem(); }

void D_R_NetInterestExpense_OperatingProfitAccount::cleanMem()	{
	cleanMem_D_R_NetInterestExpense_OperatingProfitAccount();
   D_DoubleDbAccount::cleanMem();
}

void D_R_NetInterestExpense_OperatingProfitAccount::cleanMem_D_R_NetInterestExpense_OperatingProfitAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string D_R_NetInterestExpense_OperatingProfitAccount::className() const {return "D_R_NetInterestExpense_OperatingProfitAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void D_R_NetInterestExpense_OperatingProfitAccount::myerr_msg(string msg, string func) {
	err_msg("D_R_NetInterestExpense_OperatingProfitAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void D_R_NetInterestExpense_OperatingProfitAccount::fprint(string fname) {
   D_DoubleDbAccount::fprint(fname);
	fprint_D_R_NetInterestExpense_OperatingProfitAccount(fname);
}

void D_R_NetInterestExpense_OperatingProfitAccount::fprint_D_R_NetInterestExpense_OperatingProfitAccount(string fname) {
}

void D_R_NetInterestExpense_OperatingProfitAccount::fscan(string fname) {
   D_DoubleDbAccount::fscan(fname);
	fscan_D_R_NetInterestExpense_OperatingProfitAccount(fname);
}

void D_R_NetInterestExpense_OperatingProfitAccount::fscan_D_R_NetInterestExpense_OperatingProfitAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void D_R_NetInterestExpense_OperatingProfitAccount::reset() {
	reset_D_R_NetInterestExpense_OperatingProfitAccount();
   D_DoubleDbAccount::reset();
}

void D_R_NetInterestExpense_OperatingProfitAccount::reset_D_R_NetInterestExpense_OperatingProfitAccount() {
}

/** ----------  static instance function -----------*/


D_R_NetInterestExpense_OperatingProfitAccount* D_R_NetInterestExpense_OperatingProfitAccount::instance()	{
	D_R_NetInterestExpense_OperatingProfitAccount* ptr = NULL;
   string id = "D_R_NetInterestExpense_OperatingProfitAccount";

   ptr = (D_R_NetInterestExpense_OperatingProfitAccount*) util_singleton("D_R_NetInterestExpense_OperatingProfitAccount",id);
   if(ptr==NULL) {
      ptr = new D_R_NetInterestExpense_OperatingProfitAccount();
      ptr->init();
      util_singleton("D_R_NetInterestExpense_OperatingProfitAccount",id,ptr);
   }
	return ptr;
}

D_R_NetInterestExpense_OperatingProfitAccount* D_R_NetInterestExpense_OperatingProfitAccount::instance_fscan(string fname)	{
   return D_R_NetInterestExpense_OperatingProfitAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

D_R_NetInterestExpense_OperatingProfitAccount* D_R_NetInterestExpense_OperatingProfitAccount::__ptr_D_R_NetInterestExpense_OperatingProfitAccount = D_R_NetInterestExpense_OperatingProfitAccount::instance();

#endif

