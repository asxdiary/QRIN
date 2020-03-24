// Name:     InventoryTOAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_InventoryTOAccount_cpp
#define ASX_InventoryTOAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "R_DoubleDbAccount.hpp"
#include "CostRevenueAccount.hpp"
#include "InventoriesNetAccount.hpp"
#include "InventoryTOAccount.hpp"
#include "OperatingRevenueAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctFields;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

InventoryTOAccount::InventoryTOAccount() { init_NULL(); }
InventoryTOAccount::InventoryTOAccount(const InventoryTOAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
InventoryTOAccount::InventoryTOAccount(const InventoryTOAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void InventoryTOAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void InventoryTOAccount::init() {
   R_DoubleDbAccount::init(CostRevenueAccount::instance(),
                           InventoriesNetAccount::instance(),
                           true, false);
   init_InventoryTOAccount();
}

void InventoryTOAccount::init_InventoryTOAccount() {
   set_id("InventoryTOAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

InventoryTOAccount::~InventoryTOAccount()	{ cleanMem(); }

void InventoryTOAccount::cleanMem()	{
	cleanMem_InventoryTOAccount();
   R_DoubleDbAccount::cleanMem();
}

void InventoryTOAccount::cleanMem_InventoryTOAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string InventoryTOAccount::className() const {return "InventoryTOAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void InventoryTOAccount::myerr_msg(string msg, string func) {
	err_msg("InventoryTOAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void InventoryTOAccount::fprint(string fname) {
   R_DoubleDbAccount::fprint(fname);
	fprint_InventoryTOAccount(fname);
}

void InventoryTOAccount::fprint_InventoryTOAccount(string fname) {
}

void InventoryTOAccount::fscan(string fname) {
   R_DoubleDbAccount::fscan(fname);
	fscan_InventoryTOAccount(fname);
}

void InventoryTOAccount::fscan_InventoryTOAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void InventoryTOAccount::reset() {
	reset_InventoryTOAccount();
   R_DoubleDbAccount::reset();
}

void InventoryTOAccount::reset_InventoryTOAccount() {
}

/** ----------  static instance function -----------*/


InventoryTOAccount* InventoryTOAccount::instance()	{
	InventoryTOAccount* ptr = NULL;
   string id = "InventoryTOAccount";

   ptr = (InventoryTOAccount*) util_singleton("InventoryTOAccount",id);
   if(ptr==NULL) {
      ptr = new InventoryTOAccount();
      ptr->init();
      util_singleton("InventoryTOAccount",id,ptr);
   }
	return ptr;
}

InventoryTOAccount* InventoryTOAccount::instance_fscan(string fname)	{
   return InventoryTOAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

InventoryTOAccount* InventoryTOAccount::__ptr_InventoryTOAccount = InventoryTOAccount::instance();

#endif

