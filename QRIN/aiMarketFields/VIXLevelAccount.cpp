// Name:     VIXLevelAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_VIXLevelAccount_cpp
#define ASX_VIXLevelAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "VIXLevelAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiMarketFields;

/** --------------Constructors and init_NULL-----------*/

VIXLevelAccount::VIXLevelAccount() { init_NULL(); }
VIXLevelAccount::VIXLevelAccount(const VIXLevelAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
VIXLevelAccount::VIXLevelAccount(const VIXLevelAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void VIXLevelAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void VIXLevelAccount::init() {
   PositionAccount::init();
	init_VIXLevelAccount();
}

void VIXLevelAccount::init_VIXLevelAccount() {
   set_id("VIXLevelAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

VIXLevelAccount::~VIXLevelAccount()	{ cleanMem(); }

void VIXLevelAccount::cleanMem()	{
	cleanMem_VIXLevelAccount();
   PositionAccount::cleanMem();
}

void VIXLevelAccount::cleanMem_VIXLevelAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string VIXLevelAccount::className() const {return "VIXLevelAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void VIXLevelAccount::myerr_msg(string msg, string func) {
	err_msg("VIXLevelAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void VIXLevelAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_VIXLevelAccount(fname);
}

void VIXLevelAccount::fprint_VIXLevelAccount(string fname) {
}

void VIXLevelAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_VIXLevelAccount(fname);
}

void VIXLevelAccount::fscan_VIXLevelAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void VIXLevelAccount::reset() {
	reset_VIXLevelAccount();
   PositionAccount::reset();
}

void VIXLevelAccount::reset_VIXLevelAccount() {
}

/** ----------  static instance function -----------*/


VIXLevelAccount* VIXLevelAccount::instance()	{
	VIXLevelAccount* ptr = NULL;
   string id = "VIXLevelAccount";

   ptr = (VIXLevelAccount*) util_singleton("VIXLevelAccount",id);
   if(ptr==NULL) {
      ptr = new VIXLevelAccount();
      ptr->init();
      util_singleton("VIXLevelAccount",id,ptr);
   }
	return ptr;
}

VIXLevelAccount* VIXLevelAccount::instance_fscan(string fname)	{
   return VIXLevelAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

VIXLevelAccount* VIXLevelAccount::__ptr_VIXLevelAccount = VIXLevelAccount::instance();

#endif

