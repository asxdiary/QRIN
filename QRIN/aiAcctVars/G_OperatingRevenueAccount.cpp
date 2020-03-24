// Name:     G_OperatingRevenueAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_G_OperatingRevenueAccount_cpp
#define ASX_G_OperatingRevenueAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "G_DoubleDbAccount.hpp"
#include "OperatingRevenueAccount.hpp"
#include "G_OperatingRevenueAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctFields;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

G_OperatingRevenueAccount::G_OperatingRevenueAccount() { init_NULL(); }
G_OperatingRevenueAccount::G_OperatingRevenueAccount(const G_OperatingRevenueAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
G_OperatingRevenueAccount::G_OperatingRevenueAccount(const G_OperatingRevenueAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void G_OperatingRevenueAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void G_OperatingRevenueAccount::init(bool geom_flag) {
   G_DoubleDbAccount::init(OperatingRevenueAccount::instance(), geom_flag);
	init_G_OperatingRevenueAccount();
}

void G_OperatingRevenueAccount::init_G_OperatingRevenueAccount() {
   set_id("G_OperatingRevenueAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

G_OperatingRevenueAccount::~G_OperatingRevenueAccount()	{ cleanMem(); }

void G_OperatingRevenueAccount::cleanMem()	{
	cleanMem_G_OperatingRevenueAccount();
   G_DoubleDbAccount::cleanMem();
}

void G_OperatingRevenueAccount::cleanMem_G_OperatingRevenueAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string G_OperatingRevenueAccount::className() const {return "G_OperatingRevenueAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void G_OperatingRevenueAccount::myerr_msg(string msg, string func) {
	err_msg("G_OperatingRevenueAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void G_OperatingRevenueAccount::fprint(string fname) {
   G_DoubleDbAccount::fprint(fname);
	fprint_G_OperatingRevenueAccount(fname);
}

void G_OperatingRevenueAccount::fprint_G_OperatingRevenueAccount(string fname) {
}

void G_OperatingRevenueAccount::fscan(string fname) {
   G_DoubleDbAccount::fscan(fname);
	fscan_G_OperatingRevenueAccount(fname);
}

void G_OperatingRevenueAccount::fscan_G_OperatingRevenueAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void G_OperatingRevenueAccount::reset() {
	reset_G_OperatingRevenueAccount();
   G_DoubleDbAccount::reset();
}

void G_OperatingRevenueAccount::reset_G_OperatingRevenueAccount() {
}

/** ----------  static instance function -----------*/


G_OperatingRevenueAccount* G_OperatingRevenueAccount::instance(bool geom_flag)	{
	G_OperatingRevenueAccount* ptr = NULL;
   string id = "G_OperatingRevenueAccount";

   if(!geom_flag) id = id + "_geom_false";

   ptr = (G_OperatingRevenueAccount*) util_singleton("G_OperatingRevenueAccount",id);
   if(ptr==NULL) {
      ptr = new G_OperatingRevenueAccount();
      ptr->init(geom_flag);
      util_singleton("G_OperatingRevenueAccount",id,ptr);
   }
	return ptr;
}

G_OperatingRevenueAccount* G_OperatingRevenueAccount::instance_fscan(string fname)	{
   return G_OperatingRevenueAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

G_OperatingRevenueAccount* G_OperatingRevenueAccount::__ptr_G_OperatingRevenueAccount = G_OperatingRevenueAccount::instance();

#endif

