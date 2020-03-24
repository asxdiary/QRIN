// Name:     D_R_Liabilities_AssetsAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_R_Liabilities_AssetsAccount_cpp
#define ASX_D_R_Liabilities_AssetsAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "D_DoubleDbAccount.hpp"
#include "R_Liabilities_AssetsAccount.hpp"
#include "D_R_Liabilities_AssetsAccount.hpp"
#include "TemplatePositionAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctVars;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

D_R_Liabilities_AssetsAccount::D_R_Liabilities_AssetsAccount() { init_NULL(); }
D_R_Liabilities_AssetsAccount::D_R_Liabilities_AssetsAccount(const D_R_Liabilities_AssetsAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
D_R_Liabilities_AssetsAccount::D_R_Liabilities_AssetsAccount(const D_R_Liabilities_AssetsAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void D_R_Liabilities_AssetsAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void D_R_Liabilities_AssetsAccount::init() {
   D_DoubleDbAccount::init(R_Liabilities_AssetsAccount::instance());
	init_D_R_Liabilities_AssetsAccount();
}

void D_R_Liabilities_AssetsAccount::init_D_R_Liabilities_AssetsAccount() {
   set_id("D_R_Liabilities_AssetsAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

D_R_Liabilities_AssetsAccount::~D_R_Liabilities_AssetsAccount()	{ cleanMem(); }

void D_R_Liabilities_AssetsAccount::cleanMem()	{
	cleanMem_D_R_Liabilities_AssetsAccount();
   D_DoubleDbAccount::cleanMem();
}

void D_R_Liabilities_AssetsAccount::cleanMem_D_R_Liabilities_AssetsAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string D_R_Liabilities_AssetsAccount::className() const {return "D_R_Liabilities_AssetsAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void D_R_Liabilities_AssetsAccount::myerr_msg(string msg, string func) {
	err_msg("D_R_Liabilities_AssetsAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void D_R_Liabilities_AssetsAccount::fprint(string fname) {
   D_DoubleDbAccount::fprint(fname);
	fprint_D_R_Liabilities_AssetsAccount(fname);
}

void D_R_Liabilities_AssetsAccount::fprint_D_R_Liabilities_AssetsAccount(string fname) {
}

void D_R_Liabilities_AssetsAccount::fscan(string fname) {
   D_DoubleDbAccount::fscan(fname);
	fscan_D_R_Liabilities_AssetsAccount(fname);
}

void D_R_Liabilities_AssetsAccount::fscan_D_R_Liabilities_AssetsAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void D_R_Liabilities_AssetsAccount::reset() {
	reset_D_R_Liabilities_AssetsAccount();
   D_DoubleDbAccount::reset();
}

void D_R_Liabilities_AssetsAccount::reset_D_R_Liabilities_AssetsAccount() {
}

/** ----------  static instance function -----------*/


D_R_Liabilities_AssetsAccount* D_R_Liabilities_AssetsAccount::instance()	{
	D_R_Liabilities_AssetsAccount* ptr = NULL;
   string id = "D_R_Liabilities_AssetsAccount";

   ptr = (D_R_Liabilities_AssetsAccount*) util_singleton("D_R_Liabilities_AssetsAccount",id);
   if(ptr==NULL) {
      ptr = new D_R_Liabilities_AssetsAccount();
      ptr->init();
      util_singleton("D_R_Liabilities_AssetsAccount",id,ptr);
   }
	return ptr;
}

D_R_Liabilities_AssetsAccount* D_R_Liabilities_AssetsAccount::instance_fscan(string fname)	{
   return D_R_Liabilities_AssetsAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

D_R_Liabilities_AssetsAccount* D_R_Liabilities_AssetsAccount::__ptr_D_R_Liabilities_AssetsAccount = D_R_Liabilities_AssetsAccount::instance();

#endif

