// Name:     D_CurrentRatioIAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_CurrentRatioIAccount_cpp
#define ASX_D_CurrentRatioIAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "D_DoubleDbAccount.hpp"
#include "CurrentRatioIAccount.hpp"
#include "D_CurrentRatioIAccount.hpp"
#include "TemplatePositionAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctVars;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

D_CurrentRatioIAccount::D_CurrentRatioIAccount() { init_NULL(); }
D_CurrentRatioIAccount::D_CurrentRatioIAccount(const D_CurrentRatioIAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
D_CurrentRatioIAccount::D_CurrentRatioIAccount(const D_CurrentRatioIAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void D_CurrentRatioIAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void D_CurrentRatioIAccount::init() {
   D_DoubleDbAccount::init(CurrentRatioIAccount::instance());
	init_D_CurrentRatioIAccount();
}

void D_CurrentRatioIAccount::init_D_CurrentRatioIAccount() {
   set_id("D_CurrentRatioIAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

D_CurrentRatioIAccount::~D_CurrentRatioIAccount()	{ cleanMem(); }

void D_CurrentRatioIAccount::cleanMem()	{
	cleanMem_D_CurrentRatioIAccount();
   D_DoubleDbAccount::cleanMem();
}

void D_CurrentRatioIAccount::cleanMem_D_CurrentRatioIAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string D_CurrentRatioIAccount::className() const {return "D_CurrentRatioIAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void D_CurrentRatioIAccount::myerr_msg(string msg, string func) {
	err_msg("D_CurrentRatioIAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void D_CurrentRatioIAccount::fprint(string fname) {
   D_DoubleDbAccount::fprint(fname);
	fprint_D_CurrentRatioIAccount(fname);
}

void D_CurrentRatioIAccount::fprint_D_CurrentRatioIAccount(string fname) {
}

void D_CurrentRatioIAccount::fscan(string fname) {
   D_DoubleDbAccount::fscan(fname);
	fscan_D_CurrentRatioIAccount(fname);
}

void D_CurrentRatioIAccount::fscan_D_CurrentRatioIAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void D_CurrentRatioIAccount::reset() {
	reset_D_CurrentRatioIAccount();
   D_DoubleDbAccount::reset();
}

void D_CurrentRatioIAccount::reset_D_CurrentRatioIAccount() {
}

/** ----------  static instance function -----------*/


D_CurrentRatioIAccount* D_CurrentRatioIAccount::instance()	{
	D_CurrentRatioIAccount* ptr = NULL;
   string id = "D_CurrentRatioIAccount";

   ptr = (D_CurrentRatioIAccount*) util_singleton("D_CurrentRatioIAccount",id);
   if(ptr==NULL) {
      ptr = new D_CurrentRatioIAccount();
      ptr->init();
      util_singleton("D_CurrentRatioIAccount",id,ptr);
   }
	return ptr;
}

D_CurrentRatioIAccount* D_CurrentRatioIAccount::instance_fscan(string fname)	{
   return D_CurrentRatioIAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

D_CurrentRatioIAccount* D_CurrentRatioIAccount::__ptr_D_CurrentRatioIAccount = D_CurrentRatioIAccount::instance();

#endif

