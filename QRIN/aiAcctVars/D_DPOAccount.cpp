// Name:     D_DPOAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_DPOAccount_cpp
#define ASX_D_DPOAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "D_DoubleDbAccount.hpp"
#include "DPOAccount.hpp"
#include "D_DPOAccount.hpp"
#include "TemplatePositionAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctVars;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

D_DPOAccount::D_DPOAccount() { init_NULL(); }
D_DPOAccount::D_DPOAccount(const D_DPOAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
D_DPOAccount::D_DPOAccount(const D_DPOAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void D_DPOAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void D_DPOAccount::init() {
   D_DoubleDbAccount::init(DPOAccount::instance());
	init_D_DPOAccount();
}

void D_DPOAccount::init_D_DPOAccount() {
   set_id("D_DPOAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

D_DPOAccount::~D_DPOAccount()	{ cleanMem(); }

void D_DPOAccount::cleanMem()	{
	cleanMem_D_DPOAccount();
   D_DoubleDbAccount::cleanMem();
}

void D_DPOAccount::cleanMem_D_DPOAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string D_DPOAccount::className() const {return "D_DPOAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void D_DPOAccount::myerr_msg(string msg, string func) {
	err_msg("D_DPOAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void D_DPOAccount::fprint(string fname) {
   D_DoubleDbAccount::fprint(fname);
	fprint_D_DPOAccount(fname);
}

void D_DPOAccount::fprint_D_DPOAccount(string fname) {
}

void D_DPOAccount::fscan(string fname) {
   D_DoubleDbAccount::fscan(fname);
	fscan_D_DPOAccount(fname);
}

void D_DPOAccount::fscan_D_DPOAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void D_DPOAccount::reset() {
	reset_D_DPOAccount();
   D_DoubleDbAccount::reset();
}

void D_DPOAccount::reset_D_DPOAccount() {
}

/** ----------  static instance function -----------*/


D_DPOAccount* D_DPOAccount::instance()	{
	D_DPOAccount* ptr = NULL;
   string id = "D_DPOAccount";

   ptr = (D_DPOAccount*) util_singleton("D_DPOAccount",id);
   if(ptr==NULL) {
      ptr = new D_DPOAccount();
      ptr->init();
      util_singleton("D_DPOAccount",id,ptr);
   }
	return ptr;
}

D_DPOAccount* D_DPOAccount::instance_fscan(string fname)	{
   return D_DPOAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

D_DPOAccount* D_DPOAccount::__ptr_D_DPOAccount = D_DPOAccount::instance();

#endif

