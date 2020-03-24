// Name:     D_EBITDAMarginAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_EBITDAMarginAccount_cpp
#define ASX_D_EBITDAMarginAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "D_DoubleDbAccount.hpp"
#include "EBITDAMarginAccount.hpp"
#include "D_EBITDAMarginAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

D_EBITDAMarginAccount::D_EBITDAMarginAccount() { init_NULL(); }
D_EBITDAMarginAccount::D_EBITDAMarginAccount(const D_EBITDAMarginAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
D_EBITDAMarginAccount::D_EBITDAMarginAccount(const D_EBITDAMarginAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void D_EBITDAMarginAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void D_EBITDAMarginAccount::init() {
   D_DoubleDbAccount::init(EBITDAMarginAccount::instance());
	init_D_EBITDAMarginAccount();
}

void D_EBITDAMarginAccount::init_D_EBITDAMarginAccount() {
   set_id("D_EBITDAMarginAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

D_EBITDAMarginAccount::~D_EBITDAMarginAccount()	{ cleanMem(); }

void D_EBITDAMarginAccount::cleanMem()	{
	cleanMem_D_EBITDAMarginAccount();
   D_DoubleDbAccount::cleanMem();
}

void D_EBITDAMarginAccount::cleanMem_D_EBITDAMarginAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string D_EBITDAMarginAccount::className() const {return "D_EBITDAMarginAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void D_EBITDAMarginAccount::myerr_msg(string msg, string func) {
	err_msg("D_EBITDAMarginAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void D_EBITDAMarginAccount::fprint(string fname) {
   D_DoubleDbAccount::fprint(fname);
	fprint_D_EBITDAMarginAccount(fname);
}

void D_EBITDAMarginAccount::fprint_D_EBITDAMarginAccount(string fname) {
}

void D_EBITDAMarginAccount::fscan(string fname) {
   D_DoubleDbAccount::fscan(fname);
	fscan_D_EBITDAMarginAccount(fname);
}

void D_EBITDAMarginAccount::fscan_D_EBITDAMarginAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void D_EBITDAMarginAccount::reset() {
	reset_D_EBITDAMarginAccount();
   D_DoubleDbAccount::reset();
}

void D_EBITDAMarginAccount::reset_D_EBITDAMarginAccount() {
}

/** ----------  static instance function -----------*/


D_EBITDAMarginAccount* D_EBITDAMarginAccount::instance()	{
	D_EBITDAMarginAccount* ptr = NULL;
   string id = "D_EBITDAMarginAccount";

   ptr = (D_EBITDAMarginAccount*) util_singleton("D_EBITDAMarginAccount",id);
   if(ptr==NULL) {
      ptr = new D_EBITDAMarginAccount();
      ptr->init();
      util_singleton("D_EBITDAMarginAccount",id,ptr);
   }
	return ptr;
}

D_EBITDAMarginAccount* D_EBITDAMarginAccount::instance_fscan(string fname)	{
   return D_EBITDAMarginAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

D_EBITDAMarginAccount* D_EBITDAMarginAccount::__ptr_D_EBITDAMarginAccount = D_EBITDAMarginAccount::instance();

#endif

