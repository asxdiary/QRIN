// Name:     D_CCCAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_CCCAccount_cpp
#define ASX_D_CCCAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "D_DoubleDbAccount.hpp"
#include "CCCAccount.hpp"
#include "D_CCCAccount.hpp"
#include "TemplatePositionAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctVars;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

D_CCCAccount::D_CCCAccount() { init_NULL(); }
D_CCCAccount::D_CCCAccount(const D_CCCAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
D_CCCAccount::D_CCCAccount(const D_CCCAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void D_CCCAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void D_CCCAccount::init() {
   D_DoubleDbAccount::init(CCCAccount::instance());
	init_D_CCCAccount();
}

void D_CCCAccount::init_D_CCCAccount() {
   set_id("D_CCCAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

D_CCCAccount::~D_CCCAccount()	{ cleanMem(); }

void D_CCCAccount::cleanMem()	{
	cleanMem_D_CCCAccount();
   D_DoubleDbAccount::cleanMem();
}

void D_CCCAccount::cleanMem_D_CCCAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string D_CCCAccount::className() const {return "D_CCCAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void D_CCCAccount::myerr_msg(string msg, string func) {
	err_msg("D_CCCAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void D_CCCAccount::fprint(string fname) {
   D_DoubleDbAccount::fprint(fname);
	fprint_D_CCCAccount(fname);
}

void D_CCCAccount::fprint_D_CCCAccount(string fname) {
}

void D_CCCAccount::fscan(string fname) {
   D_DoubleDbAccount::fscan(fname);
	fscan_D_CCCAccount(fname);
}

void D_CCCAccount::fscan_D_CCCAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void D_CCCAccount::reset() {
	reset_D_CCCAccount();
   D_DoubleDbAccount::reset();
}

void D_CCCAccount::reset_D_CCCAccount() {
}

/** ----------  static instance function -----------*/


D_CCCAccount* D_CCCAccount::instance()	{
	D_CCCAccount* ptr = NULL;
   string id = "D_CCCAccount";

   ptr = (D_CCCAccount*) util_singleton("D_CCCAccount",id);
   if(ptr==NULL) {
      ptr = new D_CCCAccount();
      ptr->init();
      util_singleton("D_CCCAccount",id,ptr);
   }
	return ptr;
}

D_CCCAccount* D_CCCAccount::instance_fscan(string fname)	{
   return D_CCCAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

D_CCCAccount* D_CCCAccount::__ptr_D_CCCAccount = D_CCCAccount::instance();

#endif

