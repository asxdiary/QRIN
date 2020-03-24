// Name:     D_TemplateAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_TemplateAccount_cpp
#define ASX_D_TemplateAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "D_DoubleDbAccount.hpp"
#include "TemplateFlowAccount.hpp"
#include "D_TemplateAccount.hpp"
#include "TemplatePositionAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctVars;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

D_TemplateAccount::D_TemplateAccount() { init_NULL(); }
D_TemplateAccount::D_TemplateAccount(const D_TemplateAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
D_TemplateAccount::D_TemplateAccount(const D_TemplateAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void D_TemplateAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void D_TemplateAccount::init() {
   D_DoubleDbAccount::init(TemplateFlowAccount::instance());
	init_D_TemplateAccount();
}

void D_TemplateAccount::init_D_TemplateAccount() {
   set_id("D_TemplateAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

D_TemplateAccount::~D_TemplateAccount()	{ cleanMem(); }

void D_TemplateAccount::cleanMem()	{
	cleanMem_D_TemplateAccount();
   D_DoubleDbAccount::cleanMem();
}

void D_TemplateAccount::cleanMem_D_TemplateAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string D_TemplateAccount::className() const {return "D_TemplateAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void D_TemplateAccount::myerr_msg(string msg, string func) {
	err_msg("D_TemplateAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void D_TemplateAccount::fprint(string fname) {
   D_DoubleDbAccount::fprint(fname);
	fprint_D_TemplateAccount(fname);
}

void D_TemplateAccount::fprint_D_TemplateAccount(string fname) {
}

void D_TemplateAccount::fscan(string fname) {
   D_DoubleDbAccount::fscan(fname);
	fscan_D_TemplateAccount(fname);
}

void D_TemplateAccount::fscan_D_TemplateAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void D_TemplateAccount::reset() {
	reset_D_TemplateAccount();
   D_DoubleDbAccount::reset();
}

void D_TemplateAccount::reset_D_TemplateAccount() {
}

/** ----------  static instance function -----------*/


D_TemplateAccount* D_TemplateAccount::instance()	{
	D_TemplateAccount* ptr = NULL;
   string id = "D_TemplateAccount";

   ptr = (D_TemplateAccount*) util_singleton("D_TemplateAccount",id);
   if(ptr==NULL) {
      ptr = new D_TemplateAccount();
      ptr->init();
      util_singleton("D_TemplateAccount",id,ptr);
   }
	return ptr;
}

D_TemplateAccount* D_TemplateAccount::instance_fscan(string fname)	{
   return D_TemplateAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

D_TemplateAccount* D_TemplateAccount::__ptr_D_TemplateAccount = D_TemplateAccount::instance();

#endif

