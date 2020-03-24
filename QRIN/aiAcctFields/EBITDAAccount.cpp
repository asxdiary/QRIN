// Name:     EBITDAAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_EBITDAAccount_cpp
#define ASX_EBITDAAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "EBITDAAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

EBITDAAccount::EBITDAAccount() { init_NULL(); }
EBITDAAccount::EBITDAAccount(const EBITDAAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
EBITDAAccount::EBITDAAccount(const EBITDAAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void EBITDAAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void EBITDAAccount::init() {
   FlowAccount::init();
	init_EBITDAAccount();
}

void EBITDAAccount::init_EBITDAAccount() {
   set_id("EBITDAAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

EBITDAAccount::~EBITDAAccount()	{ cleanMem(); }

void EBITDAAccount::cleanMem()	{
	cleanMem_EBITDAAccount();
   FlowAccount::cleanMem();
}

void EBITDAAccount::cleanMem_EBITDAAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string EBITDAAccount::className() const {return "EBITDAAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void EBITDAAccount::myerr_msg(string msg, string func) {
	err_msg("EBITDAAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void EBITDAAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_EBITDAAccount(fname);
}

void EBITDAAccount::fprint_EBITDAAccount(string fname) {
}

void EBITDAAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_EBITDAAccount(fname);
}

void EBITDAAccount::fscan_EBITDAAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void EBITDAAccount::reset() {
	reset_EBITDAAccount();
   FlowAccount::reset();
}

void EBITDAAccount::reset_EBITDAAccount() {
}

/** ----------  static instance function -----------*/


EBITDAAccount* EBITDAAccount::instance()	{
	EBITDAAccount* ptr = NULL;
   string id = "EBITDAAccount";

   ptr = (EBITDAAccount*) util_singleton("EBITDAAccount",id);
   if(ptr==NULL) {
      ptr = new EBITDAAccount();
      ptr->init();
      util_singleton("EBITDAAccount",id,ptr);
   }
	return ptr;
}

EBITDAAccount* EBITDAAccount::instance_fscan(string fname)	{
   return EBITDAAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

EBITDAAccount* EBITDAAccount::__ptr_EBITDAAccount = EBITDAAccount::instance();

#endif

