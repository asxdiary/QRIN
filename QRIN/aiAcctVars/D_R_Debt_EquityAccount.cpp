// Name:     D_R_Debt_EquityAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_R_Debt_EquityAccount_cpp
#define ASX_D_R_Debt_EquityAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "D_DoubleDbAccount.hpp"
#include "R_Debt_EquityAccount.hpp"
#include "D_R_Debt_EquityAccount.hpp"
#include "TemplatePositionAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctVars;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

D_R_Debt_EquityAccount::D_R_Debt_EquityAccount() { init_NULL(); }
D_R_Debt_EquityAccount::D_R_Debt_EquityAccount(const D_R_Debt_EquityAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
D_R_Debt_EquityAccount::D_R_Debt_EquityAccount(const D_R_Debt_EquityAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void D_R_Debt_EquityAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void D_R_Debt_EquityAccount::init() {
   D_DoubleDbAccount::init(R_Debt_EquityAccount::instance());
	init_D_R_Debt_EquityAccount();
}

void D_R_Debt_EquityAccount::init_D_R_Debt_EquityAccount() {
   set_id("D_R_Debt_EquityAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

D_R_Debt_EquityAccount::~D_R_Debt_EquityAccount()	{ cleanMem(); }

void D_R_Debt_EquityAccount::cleanMem()	{
	cleanMem_D_R_Debt_EquityAccount();
   D_DoubleDbAccount::cleanMem();
}

void D_R_Debt_EquityAccount::cleanMem_D_R_Debt_EquityAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string D_R_Debt_EquityAccount::className() const {return "D_R_Debt_EquityAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void D_R_Debt_EquityAccount::myerr_msg(string msg, string func) {
	err_msg("D_R_Debt_EquityAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void D_R_Debt_EquityAccount::fprint(string fname) {
   D_DoubleDbAccount::fprint(fname);
	fprint_D_R_Debt_EquityAccount(fname);
}

void D_R_Debt_EquityAccount::fprint_D_R_Debt_EquityAccount(string fname) {
}

void D_R_Debt_EquityAccount::fscan(string fname) {
   D_DoubleDbAccount::fscan(fname);
	fscan_D_R_Debt_EquityAccount(fname);
}

void D_R_Debt_EquityAccount::fscan_D_R_Debt_EquityAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void D_R_Debt_EquityAccount::reset() {
	reset_D_R_Debt_EquityAccount();
   D_DoubleDbAccount::reset();
}

void D_R_Debt_EquityAccount::reset_D_R_Debt_EquityAccount() {
}

/** ----------  static instance function -----------*/


D_R_Debt_EquityAccount* D_R_Debt_EquityAccount::instance()	{
	D_R_Debt_EquityAccount* ptr = NULL;
   string id = "D_R_Debt_EquityAccount";

   ptr = (D_R_Debt_EquityAccount*) util_singleton("D_R_Debt_EquityAccount",id);
   if(ptr==NULL) {
      ptr = new D_R_Debt_EquityAccount();
      ptr->init();
      util_singleton("D_R_Debt_EquityAccount",id,ptr);
   }
	return ptr;
}

D_R_Debt_EquityAccount* D_R_Debt_EquityAccount::instance_fscan(string fname)	{
   return D_R_Debt_EquityAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

D_R_Debt_EquityAccount* D_R_Debt_EquityAccount::__ptr_D_R_Debt_EquityAccount = D_R_Debt_EquityAccount::instance();

#endif

