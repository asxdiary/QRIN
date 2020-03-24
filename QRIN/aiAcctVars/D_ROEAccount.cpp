// Name:     D_ROEAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_ROEAccount_cpp
#define ASX_D_ROEAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "D_DoubleDbAccount.hpp"
#include "ROEAccount.hpp"
#include "D_ROEAccount.hpp"
#include "TemplatePositionAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctVars;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

D_ROEAccount::D_ROEAccount() { init_NULL(); }
D_ROEAccount::D_ROEAccount(const D_ROEAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
D_ROEAccount::D_ROEAccount(const D_ROEAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void D_ROEAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void D_ROEAccount::init() {
   D_DoubleDbAccount::init(ROEAccount::instance());
	init_D_ROEAccount();
}

void D_ROEAccount::init_D_ROEAccount() {
   set_id("D_ROEAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

D_ROEAccount::~D_ROEAccount()	{ cleanMem(); }

void D_ROEAccount::cleanMem()	{
	cleanMem_D_ROEAccount();
   D_DoubleDbAccount::cleanMem();
}

void D_ROEAccount::cleanMem_D_ROEAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string D_ROEAccount::className() const {return "D_ROEAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void D_ROEAccount::myerr_msg(string msg, string func) {
	err_msg("D_ROEAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void D_ROEAccount::fprint(string fname) {
   D_DoubleDbAccount::fprint(fname);
	fprint_D_ROEAccount(fname);
}

void D_ROEAccount::fprint_D_ROEAccount(string fname) {
}

void D_ROEAccount::fscan(string fname) {
   D_DoubleDbAccount::fscan(fname);
	fscan_D_ROEAccount(fname);
}

void D_ROEAccount::fscan_D_ROEAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void D_ROEAccount::reset() {
	reset_D_ROEAccount();
   D_DoubleDbAccount::reset();
}

void D_ROEAccount::reset_D_ROEAccount() {
}

/** ----------  static instance function -----------*/


D_ROEAccount* D_ROEAccount::instance()	{
	D_ROEAccount* ptr = NULL;
   string id = "D_ROEAccount";

   ptr = (D_ROEAccount*) util_singleton("D_ROEAccount",id);
   if(ptr==NULL) {
      ptr = new D_ROEAccount();
      ptr->init();
      util_singleton("D_ROEAccount",id,ptr);
   }
	return ptr;
}

D_ROEAccount* D_ROEAccount::instance_fscan(string fname)	{
   return D_ROEAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

D_ROEAccount* D_ROEAccount::__ptr_D_ROEAccount = D_ROEAccount::instance();

#endif

