// Name:     D_ROAAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_ROAAccount_cpp
#define ASX_D_ROAAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "D_DoubleDbAccount.hpp"
#include "ROAAccount.hpp"
#include "D_ROAAccount.hpp"
#include "TemplatePositionAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctVars;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

D_ROAAccount::D_ROAAccount() { init_NULL(); }
D_ROAAccount::D_ROAAccount(const D_ROAAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
D_ROAAccount::D_ROAAccount(const D_ROAAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void D_ROAAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void D_ROAAccount::init() {
   D_DoubleDbAccount::init(ROAAccount::instance());
	init_D_ROAAccount();
}

void D_ROAAccount::init_D_ROAAccount() {
   set_id("D_ROAAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

D_ROAAccount::~D_ROAAccount()	{ cleanMem(); }

void D_ROAAccount::cleanMem()	{
	cleanMem_D_ROAAccount();
   D_DoubleDbAccount::cleanMem();
}

void D_ROAAccount::cleanMem_D_ROAAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string D_ROAAccount::className() const {return "D_ROAAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void D_ROAAccount::myerr_msg(string msg, string func) {
	err_msg("D_ROAAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void D_ROAAccount::fprint(string fname) {
   D_DoubleDbAccount::fprint(fname);
	fprint_D_ROAAccount(fname);
}

void D_ROAAccount::fprint_D_ROAAccount(string fname) {
}

void D_ROAAccount::fscan(string fname) {
   D_DoubleDbAccount::fscan(fname);
	fscan_D_ROAAccount(fname);
}

void D_ROAAccount::fscan_D_ROAAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void D_ROAAccount::reset() {
	reset_D_ROAAccount();
   D_DoubleDbAccount::reset();
}

void D_ROAAccount::reset_D_ROAAccount() {
}

/** ----------  static instance function -----------*/


D_ROAAccount* D_ROAAccount::instance()	{
	D_ROAAccount* ptr = NULL;
   string id = "D_ROAAccount";

   ptr = (D_ROAAccount*) util_singleton("D_ROAAccount",id);
   if(ptr==NULL) {
      ptr = new D_ROAAccount();
      ptr->init();
      util_singleton("D_ROAAccount",id,ptr);
   }
	return ptr;
}

D_ROAAccount* D_ROAAccount::instance_fscan(string fname)	{
   return D_ROAAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

D_ROAAccount* D_ROAAccount::__ptr_D_ROAAccount = D_ROAAccount::instance();

#endif

