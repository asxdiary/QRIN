// Name:     AssetTOAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_AssetTOAccount_cpp
#define ASX_AssetTOAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "R_DoubleDbAccount.hpp"
#include "OperatingRevenueAccount.hpp"
#include "TotalAssetsAccount.hpp"
#include "AssetTOAccount.hpp"
#include "OperatingRevenueAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctFields;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

AssetTOAccount::AssetTOAccount() { init_NULL(); }
AssetTOAccount::AssetTOAccount(const AssetTOAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
AssetTOAccount::AssetTOAccount(const AssetTOAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void AssetTOAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void AssetTOAccount::init() {
   R_DoubleDbAccount::init(OperatingRevenueAccount::instance(),
                           TotalAssetsAccount::instance(),
                           true, false);
   init_AssetTOAccount();
}

void AssetTOAccount::init_AssetTOAccount() {
   set_id("AssetTOAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

AssetTOAccount::~AssetTOAccount()	{ cleanMem(); }

void AssetTOAccount::cleanMem()	{
	cleanMem_AssetTOAccount();
   R_DoubleDbAccount::cleanMem();
}

void AssetTOAccount::cleanMem_AssetTOAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string AssetTOAccount::className() const {return "AssetTOAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void AssetTOAccount::myerr_msg(string msg, string func) {
	err_msg("AssetTOAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void AssetTOAccount::fprint(string fname) {
   R_DoubleDbAccount::fprint(fname);
	fprint_AssetTOAccount(fname);
}

void AssetTOAccount::fprint_AssetTOAccount(string fname) {
}

void AssetTOAccount::fscan(string fname) {
   R_DoubleDbAccount::fscan(fname);
	fscan_AssetTOAccount(fname);
}

void AssetTOAccount::fscan_AssetTOAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void AssetTOAccount::reset() {
	reset_AssetTOAccount();
   R_DoubleDbAccount::reset();
}

void AssetTOAccount::reset_AssetTOAccount() {
}

/** ----------  static instance function -----------*/


AssetTOAccount* AssetTOAccount::instance()	{
	AssetTOAccount* ptr = NULL;
   string id = "AssetTOAccount";

   ptr = (AssetTOAccount*) util_singleton("AssetTOAccount",id);
   if(ptr==NULL) {
      ptr = new AssetTOAccount();
      ptr->init();
      util_singleton("AssetTOAccount",id,ptr);
   }
	return ptr;
}

AssetTOAccount* AssetTOAccount::instance_fscan(string fname)	{
   return AssetTOAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

AssetTOAccount* AssetTOAccount::__ptr_AssetTOAccount = AssetTOAccount::instance();

#endif

