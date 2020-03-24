// Name:     ROAAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ROAAccount_cpp
#define ASX_ROAAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "R_DoubleDbAccount.hpp"
#include "NetIncomeAccount.hpp"
#include "TotalAssetsAccount.hpp"
#include "ROAAccount.hpp"
#include "OperatingRevenueAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctFields;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

ROAAccount::ROAAccount() { init_NULL(); }
ROAAccount::ROAAccount(const ROAAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
ROAAccount::ROAAccount(const ROAAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void ROAAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void ROAAccount::init() {
   R_DoubleDbAccount::init(NetIncomeAccount::instance(),
                           TotalAssetsAccount::instance(),
                           true, false);
   init_ROAAccount();
}

void ROAAccount::init_ROAAccount() {
   set_id("ROAAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

ROAAccount::~ROAAccount()	{ cleanMem(); }

void ROAAccount::cleanMem()	{
	cleanMem_ROAAccount();
   R_DoubleDbAccount::cleanMem();
}

void ROAAccount::cleanMem_ROAAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string ROAAccount::className() const {return "ROAAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void ROAAccount::myerr_msg(string msg, string func) {
	err_msg("ROAAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void ROAAccount::fprint(string fname) {
   R_DoubleDbAccount::fprint(fname);
	fprint_ROAAccount(fname);
}

void ROAAccount::fprint_ROAAccount(string fname) {
}

void ROAAccount::fscan(string fname) {
   R_DoubleDbAccount::fscan(fname);
	fscan_ROAAccount(fname);
}

void ROAAccount::fscan_ROAAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void ROAAccount::reset() {
	reset_ROAAccount();
   R_DoubleDbAccount::reset();
}

void ROAAccount::reset_ROAAccount() {
}

/** ----------  static instance function -----------*/


ROAAccount* ROAAccount::instance()	{
	ROAAccount* ptr = NULL;
   string id = "ROAAccount";

   ptr = (ROAAccount*) util_singleton("ROAAccount",id);
   if(ptr==NULL) {
      ptr = new ROAAccount();
      ptr->init();
      util_singleton("ROAAccount",id,ptr);
   }
	return ptr;
}

ROAAccount* ROAAccount::instance_fscan(string fname)	{
   return ROAAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

ROAAccount* ROAAccount::__ptr_ROAAccount = ROAAccount::instance();

#endif

