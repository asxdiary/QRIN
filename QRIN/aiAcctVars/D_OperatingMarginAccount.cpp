// Name:     D_OperatingMarginAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_OperatingMarginAccount_cpp
#define ASX_D_OperatingMarginAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "D_DoubleDbAccount.hpp"
#include "OperatingMarginAccount.hpp"
#include "D_OperatingMarginAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

D_OperatingMarginAccount::D_OperatingMarginAccount() { init_NULL(); }
D_OperatingMarginAccount::D_OperatingMarginAccount(const D_OperatingMarginAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
D_OperatingMarginAccount::D_OperatingMarginAccount(const D_OperatingMarginAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void D_OperatingMarginAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void D_OperatingMarginAccount::init() {
   D_DoubleDbAccount::init(OperatingMarginAccount::instance());
	init_D_OperatingMarginAccount();
}

void D_OperatingMarginAccount::init_D_OperatingMarginAccount() {
   set_id("D_OperatingMarginAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

D_OperatingMarginAccount::~D_OperatingMarginAccount()	{ cleanMem(); }

void D_OperatingMarginAccount::cleanMem()	{
	cleanMem_D_OperatingMarginAccount();
   D_DoubleDbAccount::cleanMem();
}

void D_OperatingMarginAccount::cleanMem_D_OperatingMarginAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string D_OperatingMarginAccount::className() const {return "D_OperatingMarginAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void D_OperatingMarginAccount::myerr_msg(string msg, string func) {
	err_msg("D_OperatingMarginAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void D_OperatingMarginAccount::fprint(string fname) {
   D_DoubleDbAccount::fprint(fname);
	fprint_D_OperatingMarginAccount(fname);
}

void D_OperatingMarginAccount::fprint_D_OperatingMarginAccount(string fname) {
}

void D_OperatingMarginAccount::fscan(string fname) {
   D_DoubleDbAccount::fscan(fname);
	fscan_D_OperatingMarginAccount(fname);
}

void D_OperatingMarginAccount::fscan_D_OperatingMarginAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void D_OperatingMarginAccount::reset() {
	reset_D_OperatingMarginAccount();
   D_DoubleDbAccount::reset();
}

void D_OperatingMarginAccount::reset_D_OperatingMarginAccount() {
}

/** ----------  static instance function -----------*/


D_OperatingMarginAccount* D_OperatingMarginAccount::instance()	{
	D_OperatingMarginAccount* ptr = NULL;
   string id = "D_OperatingMarginAccount";

   ptr = (D_OperatingMarginAccount*) util_singleton("D_OperatingMarginAccount",id);
   if(ptr==NULL) {
      ptr = new D_OperatingMarginAccount();
      ptr->init();
      util_singleton("D_OperatingMarginAccount",id,ptr);
   }
	return ptr;
}

D_OperatingMarginAccount* D_OperatingMarginAccount::instance_fscan(string fname)	{
   return D_OperatingMarginAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

D_OperatingMarginAccount* D_OperatingMarginAccount::__ptr_D_OperatingMarginAccount = D_OperatingMarginAccount::instance();

#endif

