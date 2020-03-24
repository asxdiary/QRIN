// Name:     D_G_OperatingRevenueAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_G_OperatingRevenueAccount_cpp
#define ASX_D_G_OperatingRevenueAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "D_DoubleDbAccount.hpp"
#include "G_OperatingRevenueAccount.hpp"
#include "D_G_OperatingRevenueAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

D_G_OperatingRevenueAccount::D_G_OperatingRevenueAccount() { init_NULL(); }
D_G_OperatingRevenueAccount::D_G_OperatingRevenueAccount(const D_G_OperatingRevenueAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
D_G_OperatingRevenueAccount::D_G_OperatingRevenueAccount(const D_G_OperatingRevenueAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void D_G_OperatingRevenueAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void D_G_OperatingRevenueAccount::init() {
   D_DoubleDbAccount::init(G_OperatingRevenueAccount::instance());
	init_D_G_OperatingRevenueAccount();
}

void D_G_OperatingRevenueAccount::init_D_G_OperatingRevenueAccount() {
   set_id("D_G_OperatingRevenueAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

D_G_OperatingRevenueAccount::~D_G_OperatingRevenueAccount()	{ cleanMem(); }

void D_G_OperatingRevenueAccount::cleanMem()	{
	cleanMem_D_G_OperatingRevenueAccount();
   D_DoubleDbAccount::cleanMem();
}

void D_G_OperatingRevenueAccount::cleanMem_D_G_OperatingRevenueAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string D_G_OperatingRevenueAccount::className() const {return "D_G_OperatingRevenueAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void D_G_OperatingRevenueAccount::myerr_msg(string msg, string func) {
	err_msg("D_G_OperatingRevenueAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void D_G_OperatingRevenueAccount::fprint(string fname) {
   D_DoubleDbAccount::fprint(fname);
	fprint_D_G_OperatingRevenueAccount(fname);
}

void D_G_OperatingRevenueAccount::fprint_D_G_OperatingRevenueAccount(string fname) {
}

void D_G_OperatingRevenueAccount::fscan(string fname) {
   D_DoubleDbAccount::fscan(fname);
	fscan_D_G_OperatingRevenueAccount(fname);
}

void D_G_OperatingRevenueAccount::fscan_D_G_OperatingRevenueAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void D_G_OperatingRevenueAccount::reset() {
	reset_D_G_OperatingRevenueAccount();
   D_DoubleDbAccount::reset();
}

void D_G_OperatingRevenueAccount::reset_D_G_OperatingRevenueAccount() {
}

/** ----------  static instance function -----------*/


D_G_OperatingRevenueAccount* D_G_OperatingRevenueAccount::instance()	{
	D_G_OperatingRevenueAccount* ptr = NULL;
   string id = "D_G_OperatingRevenueAccount";

   ptr = (D_G_OperatingRevenueAccount*) util_singleton("D_G_OperatingRevenueAccount",id);
   if(ptr==NULL) {
      ptr = new D_G_OperatingRevenueAccount();
      ptr->init();
      util_singleton("D_G_OperatingRevenueAccount",id,ptr);
   }
	return ptr;
}

D_G_OperatingRevenueAccount* D_G_OperatingRevenueAccount::instance_fscan(string fname)	{
   return D_G_OperatingRevenueAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

D_G_OperatingRevenueAccount* D_G_OperatingRevenueAccount::__ptr_D_G_OperatingRevenueAccount = D_G_OperatingRevenueAccount::instance();

#endif

