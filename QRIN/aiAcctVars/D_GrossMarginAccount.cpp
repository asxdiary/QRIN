// Name:     D_GrossMarginAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_GrossMarginAccount_cpp
#define ASX_D_GrossMarginAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "D_DoubleDbAccount.hpp"
#include "GrossMarginAccount.hpp"
#include "D_GrossMarginAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

D_GrossMarginAccount::D_GrossMarginAccount() { init_NULL(); }
D_GrossMarginAccount::D_GrossMarginAccount(const D_GrossMarginAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
D_GrossMarginAccount::D_GrossMarginAccount(const D_GrossMarginAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void D_GrossMarginAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void D_GrossMarginAccount::init() {
   D_DoubleDbAccount::init(GrossMarginAccount::instance());
	init_D_GrossMarginAccount();
}

void D_GrossMarginAccount::init_D_GrossMarginAccount() {
   set_id("D_GrossMarginAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

D_GrossMarginAccount::~D_GrossMarginAccount()	{ cleanMem(); }

void D_GrossMarginAccount::cleanMem()	{
	cleanMem_D_GrossMarginAccount();
   D_DoubleDbAccount::cleanMem();
}

void D_GrossMarginAccount::cleanMem_D_GrossMarginAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string D_GrossMarginAccount::className() const {return "D_GrossMarginAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void D_GrossMarginAccount::myerr_msg(string msg, string func) {
	err_msg("D_GrossMarginAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void D_GrossMarginAccount::fprint(string fname) {
   D_DoubleDbAccount::fprint(fname);
	fprint_D_GrossMarginAccount(fname);
}

void D_GrossMarginAccount::fprint_D_GrossMarginAccount(string fname) {
}

void D_GrossMarginAccount::fscan(string fname) {
   D_DoubleDbAccount::fscan(fname);
	fscan_D_GrossMarginAccount(fname);
}

void D_GrossMarginAccount::fscan_D_GrossMarginAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void D_GrossMarginAccount::reset() {
	reset_D_GrossMarginAccount();
   D_DoubleDbAccount::reset();
}

void D_GrossMarginAccount::reset_D_GrossMarginAccount() {
}

/** ----------  static instance function -----------*/


D_GrossMarginAccount* D_GrossMarginAccount::instance()	{
	D_GrossMarginAccount* ptr = NULL;
   string id = "D_GrossMarginAccount";

   ptr = (D_GrossMarginAccount*) util_singleton("D_GrossMarginAccount",id);
   if(ptr==NULL) {
      ptr = new D_GrossMarginAccount();
      ptr->init();
      util_singleton("D_GrossMarginAccount",id,ptr);
   }
	return ptr;
}

D_GrossMarginAccount* D_GrossMarginAccount::instance_fscan(string fname)	{
   return D_GrossMarginAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

D_GrossMarginAccount* D_GrossMarginAccount::__ptr_D_GrossMarginAccount = D_GrossMarginAccount::instance();

#endif

