// Name:     D_R_Cash_WCAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_R_Cash_WCAccount_cpp
#define ASX_D_R_Cash_WCAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "D_DoubleDbAccount.hpp"
#include "R_Cash_WCAccount.hpp"
#include "D_R_Cash_WCAccount.hpp"
#include "TemplatePositionAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctVars;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

D_R_Cash_WCAccount::D_R_Cash_WCAccount() { init_NULL(); }
D_R_Cash_WCAccount::D_R_Cash_WCAccount(const D_R_Cash_WCAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
D_R_Cash_WCAccount::D_R_Cash_WCAccount(const D_R_Cash_WCAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void D_R_Cash_WCAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void D_R_Cash_WCAccount::init() {
   D_DoubleDbAccount::init(R_Cash_WCAccount::instance());
	init_D_R_Cash_WCAccount();
}

void D_R_Cash_WCAccount::init_D_R_Cash_WCAccount() {
   set_id("D_R_Cash_WCAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

D_R_Cash_WCAccount::~D_R_Cash_WCAccount()	{ cleanMem(); }

void D_R_Cash_WCAccount::cleanMem()	{
	cleanMem_D_R_Cash_WCAccount();
   D_DoubleDbAccount::cleanMem();
}

void D_R_Cash_WCAccount::cleanMem_D_R_Cash_WCAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string D_R_Cash_WCAccount::className() const {return "D_R_Cash_WCAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void D_R_Cash_WCAccount::myerr_msg(string msg, string func) {
	err_msg("D_R_Cash_WCAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void D_R_Cash_WCAccount::fprint(string fname) {
   D_DoubleDbAccount::fprint(fname);
	fprint_D_R_Cash_WCAccount(fname);
}

void D_R_Cash_WCAccount::fprint_D_R_Cash_WCAccount(string fname) {
}

void D_R_Cash_WCAccount::fscan(string fname) {
   D_DoubleDbAccount::fscan(fname);
	fscan_D_R_Cash_WCAccount(fname);
}

void D_R_Cash_WCAccount::fscan_D_R_Cash_WCAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void D_R_Cash_WCAccount::reset() {
	reset_D_R_Cash_WCAccount();
   D_DoubleDbAccount::reset();
}

void D_R_Cash_WCAccount::reset_D_R_Cash_WCAccount() {
}

/** ----------  static instance function -----------*/


D_R_Cash_WCAccount* D_R_Cash_WCAccount::instance()	{
	D_R_Cash_WCAccount* ptr = NULL;
   string id = "D_R_Cash_WCAccount";

   ptr = (D_R_Cash_WCAccount*) util_singleton("D_R_Cash_WCAccount",id);
   if(ptr==NULL) {
      ptr = new D_R_Cash_WCAccount();
      ptr->init();
      util_singleton("D_R_Cash_WCAccount",id,ptr);
   }
	return ptr;
}

D_R_Cash_WCAccount* D_R_Cash_WCAccount::instance_fscan(string fname)	{
   return D_R_Cash_WCAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

D_R_Cash_WCAccount* D_R_Cash_WCAccount::__ptr_D_R_Cash_WCAccount = D_R_Cash_WCAccount::instance();

#endif

