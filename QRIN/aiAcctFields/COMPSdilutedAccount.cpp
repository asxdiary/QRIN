// Name:     COMPSdilutedAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_COMPSdilutedAccount_cpp
#define ASX_COMPSdilutedAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "COMPSdilutedAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

COMPSdilutedAccount::COMPSdilutedAccount() { init_NULL(); }
COMPSdilutedAccount::COMPSdilutedAccount(const COMPSdilutedAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
COMPSdilutedAccount::COMPSdilutedAccount(const COMPSdilutedAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void COMPSdilutedAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void COMPSdilutedAccount::init() {
   FlowAccount::init();
	init_COMPSdilutedAccount();
}

void COMPSdilutedAccount::init_COMPSdilutedAccount() {
   set_id("COMPSdilutedAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

COMPSdilutedAccount::~COMPSdilutedAccount()	{ cleanMem(); }

void COMPSdilutedAccount::cleanMem()	{
	cleanMem_COMPSdilutedAccount();
   FlowAccount::cleanMem();
}

void COMPSdilutedAccount::cleanMem_COMPSdilutedAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string COMPSdilutedAccount::className() const {return "COMPSdilutedAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void COMPSdilutedAccount::myerr_msg(string msg, string func) {
	err_msg("COMPSdilutedAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void COMPSdilutedAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_COMPSdilutedAccount(fname);
}

void COMPSdilutedAccount::fprint_COMPSdilutedAccount(string fname) {
}

void COMPSdilutedAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_COMPSdilutedAccount(fname);
}

void COMPSdilutedAccount::fscan_COMPSdilutedAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void COMPSdilutedAccount::reset() {
	reset_COMPSdilutedAccount();
   FlowAccount::reset();
}

void COMPSdilutedAccount::reset_COMPSdilutedAccount() {
}

/** ----------  static instance function -----------*/


COMPSdilutedAccount* COMPSdilutedAccount::instance()	{
	COMPSdilutedAccount* ptr = NULL;
   string id = "COMPSdilutedAccount";

   ptr = (COMPSdilutedAccount*) util_singleton("COMPSdilutedAccount",id);
   if(ptr==NULL) {
      ptr = new COMPSdilutedAccount();
      ptr->init();
      util_singleton("COMPSdilutedAccount",id,ptr);
   }
	return ptr;
}

COMPSdilutedAccount* COMPSdilutedAccount::instance_fscan(string fname)	{
   return COMPSdilutedAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

COMPSdilutedAccount* COMPSdilutedAccount::__ptr_COMPSdilutedAccount = COMPSdilutedAccount::instance();

#endif

