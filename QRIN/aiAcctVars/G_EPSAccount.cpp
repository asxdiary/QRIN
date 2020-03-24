// Name:     G_EPSAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_G_EPSAccount_cpp
#define ASX_G_EPSAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "G_DoubleDbAccount.hpp"
#include "EPSAccount.hpp"
#include "G_EPSAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctFields;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

G_EPSAccount::G_EPSAccount() { init_NULL(); }
G_EPSAccount::G_EPSAccount(const G_EPSAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
G_EPSAccount::G_EPSAccount(const G_EPSAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void G_EPSAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void G_EPSAccount::init(bool geom_flag) {
   G_DoubleDbAccount::init(EPSAccount::instance(), geom_flag);
	init_G_EPSAccount();
}

void G_EPSAccount::init_G_EPSAccount() {
   set_id("G_EPSAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

G_EPSAccount::~G_EPSAccount()	{ cleanMem(); }

void G_EPSAccount::cleanMem()	{
	cleanMem_G_EPSAccount();
   G_DoubleDbAccount::cleanMem();
}

void G_EPSAccount::cleanMem_G_EPSAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string G_EPSAccount::className() const {return "G_EPSAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void G_EPSAccount::myerr_msg(string msg, string func) {
	err_msg("G_EPSAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void G_EPSAccount::fprint(string fname) {
   G_DoubleDbAccount::fprint(fname);
	fprint_G_EPSAccount(fname);
}

void G_EPSAccount::fprint_G_EPSAccount(string fname) {
}

void G_EPSAccount::fscan(string fname) {
   G_DoubleDbAccount::fscan(fname);
	fscan_G_EPSAccount(fname);
}

void G_EPSAccount::fscan_G_EPSAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void G_EPSAccount::reset() {
	reset_G_EPSAccount();
   G_DoubleDbAccount::reset();
}

void G_EPSAccount::reset_G_EPSAccount() {
}

/** ----------  static instance function -----------*/


G_EPSAccount* G_EPSAccount::instance(bool geom_flag)	{
	G_EPSAccount* ptr = NULL;
   string id = "G_EPSAccount";

   if(!geom_flag) id = id + "_geom_false";

   ptr = (G_EPSAccount*) util_singleton("G_EPSAccount",id);
   if(ptr==NULL) {
      ptr = new G_EPSAccount();
      ptr->init(geom_flag);
      util_singleton("G_EPSAccount",id,ptr);
   }
	return ptr;
}

G_EPSAccount* G_EPSAccount::instance_fscan(string fname)	{
   return G_EPSAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

G_EPSAccount* G_EPSAccount::__ptr_G_EPSAccount = G_EPSAccount::instance();

#endif

