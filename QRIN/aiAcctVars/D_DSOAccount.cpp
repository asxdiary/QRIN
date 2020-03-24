// Name:     D_DSOAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_DSOAccount_cpp
#define ASX_D_DSOAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "D_DoubleDbAccount.hpp"
#include "DSOAccount.hpp"
#include "D_DSOAccount.hpp"
#include "TemplatePositionAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctVars;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

D_DSOAccount::D_DSOAccount() { init_NULL(); }
D_DSOAccount::D_DSOAccount(const D_DSOAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
D_DSOAccount::D_DSOAccount(const D_DSOAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void D_DSOAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void D_DSOAccount::init() {
   D_DoubleDbAccount::init(DSOAccount::instance());
	init_D_DSOAccount();
}

void D_DSOAccount::init_D_DSOAccount() {
   set_id("D_DSOAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

D_DSOAccount::~D_DSOAccount()	{ cleanMem(); }

void D_DSOAccount::cleanMem()	{
	cleanMem_D_DSOAccount();
   D_DoubleDbAccount::cleanMem();
}

void D_DSOAccount::cleanMem_D_DSOAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string D_DSOAccount::className() const {return "D_DSOAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void D_DSOAccount::myerr_msg(string msg, string func) {
	err_msg("D_DSOAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void D_DSOAccount::fprint(string fname) {
   D_DoubleDbAccount::fprint(fname);
	fprint_D_DSOAccount(fname);
}

void D_DSOAccount::fprint_D_DSOAccount(string fname) {
}

void D_DSOAccount::fscan(string fname) {
   D_DoubleDbAccount::fscan(fname);
	fscan_D_DSOAccount(fname);
}

void D_DSOAccount::fscan_D_DSOAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void D_DSOAccount::reset() {
	reset_D_DSOAccount();
   D_DoubleDbAccount::reset();
}

void D_DSOAccount::reset_D_DSOAccount() {
}

/** ----------  static instance function -----------*/


D_DSOAccount* D_DSOAccount::instance()	{
	D_DSOAccount* ptr = NULL;
   string id = "D_DSOAccount";

   ptr = (D_DSOAccount*) util_singleton("D_DSOAccount",id);
   if(ptr==NULL) {
      ptr = new D_DSOAccount();
      ptr->init();
      util_singleton("D_DSOAccount",id,ptr);
   }
	return ptr;
}

D_DSOAccount* D_DSOAccount::instance_fscan(string fname)	{
   return D_DSOAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

D_DSOAccount* D_DSOAccount::__ptr_D_DSOAccount = D_DSOAccount::instance();

#endif

