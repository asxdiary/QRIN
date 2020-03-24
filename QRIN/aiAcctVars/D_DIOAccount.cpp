// Name:     D_DIOAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_DIOAccount_cpp
#define ASX_D_DIOAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "D_DoubleDbAccount.hpp"
#include "DIOAccount.hpp"
#include "D_DIOAccount.hpp"
#include "TemplatePositionAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctVars;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

D_DIOAccount::D_DIOAccount() { init_NULL(); }
D_DIOAccount::D_DIOAccount(const D_DIOAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
D_DIOAccount::D_DIOAccount(const D_DIOAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void D_DIOAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void D_DIOAccount::init() {
   D_DoubleDbAccount::init(DIOAccount::instance());
	init_D_DIOAccount();
}

void D_DIOAccount::init_D_DIOAccount() {
   set_id("D_DIOAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

D_DIOAccount::~D_DIOAccount()	{ cleanMem(); }

void D_DIOAccount::cleanMem()	{
	cleanMem_D_DIOAccount();
   D_DoubleDbAccount::cleanMem();
}

void D_DIOAccount::cleanMem_D_DIOAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string D_DIOAccount::className() const {return "D_DIOAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void D_DIOAccount::myerr_msg(string msg, string func) {
	err_msg("D_DIOAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void D_DIOAccount::fprint(string fname) {
   D_DoubleDbAccount::fprint(fname);
	fprint_D_DIOAccount(fname);
}

void D_DIOAccount::fprint_D_DIOAccount(string fname) {
}

void D_DIOAccount::fscan(string fname) {
   D_DoubleDbAccount::fscan(fname);
	fscan_D_DIOAccount(fname);
}

void D_DIOAccount::fscan_D_DIOAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void D_DIOAccount::reset() {
	reset_D_DIOAccount();
   D_DoubleDbAccount::reset();
}

void D_DIOAccount::reset_D_DIOAccount() {
}

/** ----------  static instance function -----------*/


D_DIOAccount* D_DIOAccount::instance()	{
	D_DIOAccount* ptr = NULL;
   string id = "D_DIOAccount";

   ptr = (D_DIOAccount*) util_singleton("D_DIOAccount",id);
   if(ptr==NULL) {
      ptr = new D_DIOAccount();
      ptr->init();
      util_singleton("D_DIOAccount",id,ptr);
   }
	return ptr;
}

D_DIOAccount* D_DIOAccount::instance_fscan(string fname)	{
   return D_DIOAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

D_DIOAccount* D_DIOAccount::__ptr_D_DIOAccount = D_DIOAccount::instance();

#endif

