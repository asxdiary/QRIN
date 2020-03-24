// Name:     InventoriesNetAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_InventoriesNetAccount_cpp
#define ASX_InventoriesNetAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "InventoriesNetAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

InventoriesNetAccount::InventoriesNetAccount() { init_NULL(); }
InventoriesNetAccount::InventoriesNetAccount(const InventoriesNetAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
InventoriesNetAccount::InventoriesNetAccount(const InventoriesNetAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void InventoriesNetAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void InventoriesNetAccount::init() {
   PositionAccount::init();
	init_InventoriesNetAccount();
}

void InventoriesNetAccount::init_InventoriesNetAccount() {
   set_id("InventoriesNetAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

InventoriesNetAccount::~InventoriesNetAccount()	{ cleanMem(); }

void InventoriesNetAccount::cleanMem()	{
	cleanMem_InventoriesNetAccount();
   PositionAccount::cleanMem();
}

void InventoriesNetAccount::cleanMem_InventoriesNetAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string InventoriesNetAccount::className() const {return "InventoriesNetAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void InventoriesNetAccount::myerr_msg(string msg, string func) {
	err_msg("InventoriesNetAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void InventoriesNetAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_InventoriesNetAccount(fname);
}

void InventoriesNetAccount::fprint_InventoriesNetAccount(string fname) {
}

void InventoriesNetAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_InventoriesNetAccount(fname);
}

void InventoriesNetAccount::fscan_InventoriesNetAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void InventoriesNetAccount::reset() {
	reset_InventoriesNetAccount();
   PositionAccount::reset();
}

void InventoriesNetAccount::reset_InventoriesNetAccount() {
}

/** ----------  static instance function -----------*/


InventoriesNetAccount* InventoriesNetAccount::instance()	{
	InventoriesNetAccount* ptr = NULL;
   string id = "InventoriesNetAccount";

   ptr = (InventoriesNetAccount*) util_singleton("InventoriesNetAccount",id);
   if(ptr==NULL) {
      ptr = new InventoriesNetAccount();
      ptr->init();
      util_singleton("InventoriesNetAccount",id,ptr);
   }
	return ptr;
}

InventoriesNetAccount* InventoriesNetAccount::instance_fscan(string fname)	{
   return InventoriesNetAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

InventoriesNetAccount* InventoriesNetAccount::__ptr_InventoriesNetAccount = InventoriesNetAccount::instance();

#endif

