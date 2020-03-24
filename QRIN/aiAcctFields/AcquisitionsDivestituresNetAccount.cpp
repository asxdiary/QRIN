// Name:     AcquisitionsDivestituresNetAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_AcquisitionsDivestituresNetAccount_cpp
#define ASX_AcquisitionsDivestituresNetAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"
#include "AcquisitionsDivestituresNetAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

AcquisitionsDivestituresNetAccount::AcquisitionsDivestituresNetAccount() { init_NULL(); }
AcquisitionsDivestituresNetAccount::AcquisitionsDivestituresNetAccount(const AcquisitionsDivestituresNetAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
AcquisitionsDivestituresNetAccount::AcquisitionsDivestituresNetAccount(const AcquisitionsDivestituresNetAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void AcquisitionsDivestituresNetAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void AcquisitionsDivestituresNetAccount::init() {
   FlowAccount::init();
	init_AcquisitionsDivestituresNetAccount();
}

void AcquisitionsDivestituresNetAccount::init_AcquisitionsDivestituresNetAccount() {
   set_id("AcquisitionsDivestituresNetAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

AcquisitionsDivestituresNetAccount::~AcquisitionsDivestituresNetAccount()	{ cleanMem(); }

void AcquisitionsDivestituresNetAccount::cleanMem()	{
	cleanMem_AcquisitionsDivestituresNetAccount();
   FlowAccount::cleanMem();
}

void AcquisitionsDivestituresNetAccount::cleanMem_AcquisitionsDivestituresNetAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string AcquisitionsDivestituresNetAccount::className() const {return "AcquisitionsDivestituresNetAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void AcquisitionsDivestituresNetAccount::myerr_msg(string msg, string func) {
	err_msg("AcquisitionsDivestituresNetAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void AcquisitionsDivestituresNetAccount::fprint(string fname) {
   FlowAccount::fprint(fname);
	fprint_AcquisitionsDivestituresNetAccount(fname);
}

void AcquisitionsDivestituresNetAccount::fprint_AcquisitionsDivestituresNetAccount(string fname) {
}

void AcquisitionsDivestituresNetAccount::fscan(string fname) {
   FlowAccount::fscan(fname);
	fscan_AcquisitionsDivestituresNetAccount(fname);
}

void AcquisitionsDivestituresNetAccount::fscan_AcquisitionsDivestituresNetAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void AcquisitionsDivestituresNetAccount::reset() {
	reset_AcquisitionsDivestituresNetAccount();
   FlowAccount::reset();
}

void AcquisitionsDivestituresNetAccount::reset_AcquisitionsDivestituresNetAccount() {
}

/** ----------  static instance function -----------*/


AcquisitionsDivestituresNetAccount* AcquisitionsDivestituresNetAccount::instance()	{
	AcquisitionsDivestituresNetAccount* ptr = NULL;
   string id = "AcquisitionsDivestituresNetAccount";

   ptr = (AcquisitionsDivestituresNetAccount*) util_singleton("AcquisitionsDivestituresNetAccount",id);
   if(ptr==NULL) {
      ptr = new AcquisitionsDivestituresNetAccount();
      ptr->init();
      util_singleton("AcquisitionsDivestituresNetAccount",id,ptr);
   }
	return ptr;
}

AcquisitionsDivestituresNetAccount* AcquisitionsDivestituresNetAccount::instance_fscan(string fname)	{
   return AcquisitionsDivestituresNetAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

AcquisitionsDivestituresNetAccount* AcquisitionsDivestituresNetAccount::__ptr_AcquisitionsDivestituresNetAccount = AcquisitionsDivestituresNetAccount::instance();

#endif

