// Name:     D_G_EPSAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_G_EPSAccount_cpp
#define ASX_D_G_EPSAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "D_DoubleDbAccount.hpp"
#include "G_EPSAccount.hpp"
#include "D_G_EPSAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

D_G_EPSAccount::D_G_EPSAccount() { init_NULL(); }
D_G_EPSAccount::D_G_EPSAccount(const D_G_EPSAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
D_G_EPSAccount::D_G_EPSAccount(const D_G_EPSAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void D_G_EPSAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void D_G_EPSAccount::init() {
   D_DoubleDbAccount::init(G_EPSAccount::instance());
	init_D_G_EPSAccount();
}

void D_G_EPSAccount::init_D_G_EPSAccount() {
   set_id("D_G_EPSAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

D_G_EPSAccount::~D_G_EPSAccount()	{ cleanMem(); }

void D_G_EPSAccount::cleanMem()	{
	cleanMem_D_G_EPSAccount();
   D_DoubleDbAccount::cleanMem();
}

void D_G_EPSAccount::cleanMem_D_G_EPSAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string D_G_EPSAccount::className() const {return "D_G_EPSAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void D_G_EPSAccount::myerr_msg(string msg, string func) {
	err_msg("D_G_EPSAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void D_G_EPSAccount::fprint(string fname) {
   D_DoubleDbAccount::fprint(fname);
	fprint_D_G_EPSAccount(fname);
}

void D_G_EPSAccount::fprint_D_G_EPSAccount(string fname) {
}

void D_G_EPSAccount::fscan(string fname) {
   D_DoubleDbAccount::fscan(fname);
	fscan_D_G_EPSAccount(fname);
}

void D_G_EPSAccount::fscan_D_G_EPSAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void D_G_EPSAccount::reset() {
	reset_D_G_EPSAccount();
   D_DoubleDbAccount::reset();
}

void D_G_EPSAccount::reset_D_G_EPSAccount() {
}

/** ----------  static instance function -----------*/


D_G_EPSAccount* D_G_EPSAccount::instance()	{
	D_G_EPSAccount* ptr = NULL;
   string id = "D_G_EPSAccount";

   ptr = (D_G_EPSAccount*) util_singleton("D_G_EPSAccount",id);
   if(ptr==NULL) {
      ptr = new D_G_EPSAccount();
      ptr->init();
      util_singleton("D_G_EPSAccount",id,ptr);
   }
	return ptr;
}

D_G_EPSAccount* D_G_EPSAccount::instance_fscan(string fname)	{
   return D_G_EPSAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

D_G_EPSAccount* D_G_EPSAccount::__ptr_D_G_EPSAccount = D_G_EPSAccount::instance();

#endif

