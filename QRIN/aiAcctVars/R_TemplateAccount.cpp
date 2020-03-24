// Name:     R_TemplateAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_R_TemplateAccount_cpp
#define ASX_R_TemplateAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "R_DoubleDbAccount.hpp"
#include "TemplateFlowAccount.hpp"
#include "TemplatePositionAccount.hpp"
#include "R_TemplateAccount.hpp"
#include "OperatingRevenueAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctFields;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

R_TemplateAccount::R_TemplateAccount() { init_NULL(); }
R_TemplateAccount::R_TemplateAccount(const R_TemplateAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
R_TemplateAccount::R_TemplateAccount(const R_TemplateAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void R_TemplateAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void R_TemplateAccount::init() {
   R_DoubleDbAccount::init(TemplateFlowAccount::instance(),
                           TemplatePositionAccount::instance(),
                           false, false);
   init_R_TemplateAccount();
}

void R_TemplateAccount::init_R_TemplateAccount() {
   set_id("R_TemplateAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

R_TemplateAccount::~R_TemplateAccount()	{ cleanMem(); }

void R_TemplateAccount::cleanMem()	{
	cleanMem_R_TemplateAccount();
   R_DoubleDbAccount::cleanMem();
}

void R_TemplateAccount::cleanMem_R_TemplateAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string R_TemplateAccount::className() const {return "R_TemplateAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void R_TemplateAccount::myerr_msg(string msg, string func) {
	err_msg("R_TemplateAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void R_TemplateAccount::fprint(string fname) {
   R_DoubleDbAccount::fprint(fname);
	fprint_R_TemplateAccount(fname);
}

void R_TemplateAccount::fprint_R_TemplateAccount(string fname) {
}

void R_TemplateAccount::fscan(string fname) {
   R_DoubleDbAccount::fscan(fname);
	fscan_R_TemplateAccount(fname);
}

void R_TemplateAccount::fscan_R_TemplateAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void R_TemplateAccount::reset() {
	reset_R_TemplateAccount();
   R_DoubleDbAccount::reset();
}

void R_TemplateAccount::reset_R_TemplateAccount() {
}

/** ----------  static instance function -----------*/


R_TemplateAccount* R_TemplateAccount::instance()	{
	R_TemplateAccount* ptr = NULL;
   string id = "R_TemplateAccount";

   ptr = (R_TemplateAccount*) util_singleton("R_TemplateAccount",id);
   if(ptr==NULL) {
      ptr = new R_TemplateAccount();
      ptr->init();
      util_singleton("R_TemplateAccount",id,ptr);
   }
	return ptr;
}

R_TemplateAccount* R_TemplateAccount::instance_fscan(string fname)	{
   return R_TemplateAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

R_TemplateAccount* R_TemplateAccount::__ptr_R_TemplateAccount = R_TemplateAccount::instance();

#endif

