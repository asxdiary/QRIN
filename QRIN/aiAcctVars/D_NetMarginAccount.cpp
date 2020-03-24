// Name:     D_NetMarginAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_NetMarginAccount_cpp
#define ASX_D_NetMarginAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "D_DoubleDbAccount.hpp"
#include "NetMarginAccount.hpp"
#include "D_NetMarginAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

D_NetMarginAccount::D_NetMarginAccount() { init_NULL(); }
D_NetMarginAccount::D_NetMarginAccount(const D_NetMarginAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
D_NetMarginAccount::D_NetMarginAccount(const D_NetMarginAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void D_NetMarginAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void D_NetMarginAccount::init() {
   D_DoubleDbAccount::init(NetMarginAccount::instance());
	init_D_NetMarginAccount();
}

void D_NetMarginAccount::init_D_NetMarginAccount() {
   set_id("D_NetMarginAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

D_NetMarginAccount::~D_NetMarginAccount()	{ cleanMem(); }

void D_NetMarginAccount::cleanMem()	{
	cleanMem_D_NetMarginAccount();
   D_DoubleDbAccount::cleanMem();
}

void D_NetMarginAccount::cleanMem_D_NetMarginAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string D_NetMarginAccount::className() const {return "D_NetMarginAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void D_NetMarginAccount::myerr_msg(string msg, string func) {
	err_msg("D_NetMarginAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void D_NetMarginAccount::fprint(string fname) {
   D_DoubleDbAccount::fprint(fname);
	fprint_D_NetMarginAccount(fname);
}

void D_NetMarginAccount::fprint_D_NetMarginAccount(string fname) {
}

void D_NetMarginAccount::fscan(string fname) {
   D_DoubleDbAccount::fscan(fname);
	fscan_D_NetMarginAccount(fname);
}

void D_NetMarginAccount::fscan_D_NetMarginAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void D_NetMarginAccount::reset() {
	reset_D_NetMarginAccount();
   D_DoubleDbAccount::reset();
}

void D_NetMarginAccount::reset_D_NetMarginAccount() {
}

/** ----------  static instance function -----------*/


D_NetMarginAccount* D_NetMarginAccount::instance()	{
	D_NetMarginAccount* ptr = NULL;
   string id = "D_NetMarginAccount";

   ptr = (D_NetMarginAccount*) util_singleton("D_NetMarginAccount",id);
   if(ptr==NULL) {
      ptr = new D_NetMarginAccount();
      ptr->init();
      util_singleton("D_NetMarginAccount",id,ptr);
   }
	return ptr;
}

D_NetMarginAccount* D_NetMarginAccount::instance_fscan(string fname)	{
   return D_NetMarginAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

D_NetMarginAccount* D_NetMarginAccount::__ptr_D_NetMarginAccount = D_NetMarginAccount::instance();

#endif

