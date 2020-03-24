// Name:     GrossMarginAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_GrossMarginAccount_cpp
#define ASX_GrossMarginAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "R_DoubleDbAccount.hpp"
#include "CostRevenueAccount.hpp"
#include "OperatingRevenueAccount.hpp"
#include "GrossMarginAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctFields;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

GrossMarginAccount::GrossMarginAccount() { init_NULL(); }
GrossMarginAccount::GrossMarginAccount(const GrossMarginAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
GrossMarginAccount::GrossMarginAccount(const GrossMarginAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void GrossMarginAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void GrossMarginAccount::init() {
   R_DoubleDbAccount::init(CostRevenueAccount::instance(),
                      OperatingRevenueAccount::instance(),
                      false, true);
	init_GrossMarginAccount();
}

void GrossMarginAccount::init_GrossMarginAccount() {
   set_id("GrossMarginAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

GrossMarginAccount::~GrossMarginAccount()	{ cleanMem(); }

void GrossMarginAccount::cleanMem()	{
	cleanMem_GrossMarginAccount();
   R_DoubleDbAccount::cleanMem();
}

void GrossMarginAccount::cleanMem_GrossMarginAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string GrossMarginAccount::className() const {return "GrossMarginAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void GrossMarginAccount::myerr_msg(string msg, string func) {
	err_msg("GrossMarginAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void GrossMarginAccount::fprint(string fname) {
   R_DoubleDbAccount::fprint(fname);
	fprint_GrossMarginAccount(fname);
}

void GrossMarginAccount::fprint_GrossMarginAccount(string fname) {
}

void GrossMarginAccount::fscan(string fname) {
   R_DoubleDbAccount::fscan(fname);
	fscan_GrossMarginAccount(fname);
}

void GrossMarginAccount::fscan_GrossMarginAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void GrossMarginAccount::reset() {
	reset_GrossMarginAccount();
   R_DoubleDbAccount::reset();
}

void GrossMarginAccount::reset_GrossMarginAccount() {
}

/** ----------  static instance function -----------*/


GrossMarginAccount* GrossMarginAccount::instance()	{
	GrossMarginAccount* ptr = NULL;
   string id = "GrossMarginAccount";

   ptr = (GrossMarginAccount*) util_singleton("GrossMarginAccount",id);
   if(ptr==NULL) {
      ptr = new GrossMarginAccount();
      ptr->init();
      util_singleton("GrossMarginAccount",id,ptr);
   }
	return ptr;
}

GrossMarginAccount* GrossMarginAccount::instance_fscan(string fname)	{
   return GrossMarginAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

GrossMarginAccount* GrossMarginAccount::__ptr_GrossMarginAccount = GrossMarginAccount::instance();

#endif

