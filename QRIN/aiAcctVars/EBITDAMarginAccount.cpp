// Name:     EBITDAMarginAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_EBITDAMarginAccount_cpp
#define ASX_EBITDAMarginAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "R_DoubleDbAccount.hpp"
#include "EBITDAAccount.hpp"
#include "OperatingRevenueAccount.hpp"
#include "EBITDAMarginAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctFields;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

EBITDAMarginAccount::EBITDAMarginAccount() { init_NULL(); }
EBITDAMarginAccount::EBITDAMarginAccount(const EBITDAMarginAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
EBITDAMarginAccount::EBITDAMarginAccount(const EBITDAMarginAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void EBITDAMarginAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void EBITDAMarginAccount::init() {
   R_DoubleDbAccount::init(EBITDAAccount::instance(),
                      OperatingRevenueAccount::instance(),
                      false, false);
	init_EBITDAMarginAccount();
}

void EBITDAMarginAccount::init_EBITDAMarginAccount() {
   set_id("EBITDAMarginAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

EBITDAMarginAccount::~EBITDAMarginAccount()	{ cleanMem(); }

void EBITDAMarginAccount::cleanMem()	{
	cleanMem_EBITDAMarginAccount();
   R_DoubleDbAccount::cleanMem();
}

void EBITDAMarginAccount::cleanMem_EBITDAMarginAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string EBITDAMarginAccount::className() const {return "EBITDAMarginAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void EBITDAMarginAccount::myerr_msg(string msg, string func) {
	err_msg("EBITDAMarginAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void EBITDAMarginAccount::fprint(string fname) {
   R_DoubleDbAccount::fprint(fname);
	fprint_EBITDAMarginAccount(fname);
}

void EBITDAMarginAccount::fprint_EBITDAMarginAccount(string fname) {
}

void EBITDAMarginAccount::fscan(string fname) {
   R_DoubleDbAccount::fscan(fname);
	fscan_EBITDAMarginAccount(fname);
}

void EBITDAMarginAccount::fscan_EBITDAMarginAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void EBITDAMarginAccount::reset() {
	reset_EBITDAMarginAccount();
   R_DoubleDbAccount::reset();
}

void EBITDAMarginAccount::reset_EBITDAMarginAccount() {
}

/** ----------  static instance function -----------*/


EBITDAMarginAccount* EBITDAMarginAccount::instance()	{
	EBITDAMarginAccount* ptr = NULL;
   string id = "EBITDAMarginAccount";

   ptr = (EBITDAMarginAccount*) util_singleton("EBITDAMarginAccount",id);
   if(ptr==NULL) {
      ptr = new EBITDAMarginAccount();
      ptr->init();
      util_singleton("EBITDAMarginAccount",id,ptr);
   }
	return ptr;
}

EBITDAMarginAccount* EBITDAMarginAccount::instance_fscan(string fname)	{
   return EBITDAMarginAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

EBITDAMarginAccount* EBITDAMarginAccount::__ptr_EBITDAMarginAccount = EBITDAMarginAccount::instance();

#endif

