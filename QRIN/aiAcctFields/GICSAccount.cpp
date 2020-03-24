// Name:     GICSAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_GICSAccount_cpp
#define ASX_GICSAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DoubleDbAccount.hpp"
#include "GICSAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctFields;
using namespace aiDbAccounts;

/** --------------Constructors and init_NULL-----------*/

GICSAccount::GICSAccount() { init_NULL(); }
GICSAccount::GICSAccount(const GICSAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
GICSAccount::GICSAccount(const GICSAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void GICSAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void GICSAccount::init() {
   DoubleDbAccount::init("classification");
	init_GICSAccount();
}

void GICSAccount::init_GICSAccount() {
   set_id("GICSAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

GICSAccount::~GICSAccount()	{ cleanMem(); }

void GICSAccount::cleanMem()	{
	cleanMem_GICSAccount();
	DoubleDbAccount::cleanMem();
}

void GICSAccount::cleanMem_GICSAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string GICSAccount::className() const {return "GICSAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void GICSAccount::myerr_msg(string msg, string func) {
	err_msg("GICSAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void GICSAccount::fprint(string fname) {
	DoubleDbAccount::fprint(fname);
	fprint_GICSAccount(fname);
}

void GICSAccount::fprint_GICSAccount(string fname) {
}

void GICSAccount::fscan(string fname) {
	DoubleDbAccount::fscan(fname);
	fscan_GICSAccount(fname);
}

void GICSAccount::fscan_GICSAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void GICSAccount::reset() {
	reset_GICSAccount();
	DoubleDbAccount::reset();
}

void GICSAccount::reset_GICSAccount() {
}

/** ----------  static instance function -----------*/

GICSAccount* GICSAccount::instance()	{
	GICSAccount* ptr = NULL;
   string id = "GICSAccount";

   ptr = (GICSAccount*) util_singleton("GICSAccount",id);
   if(ptr==NULL) {
      ptr = new GICSAccount();
      ptr->init();
      util_singleton("GICSAccount",id,ptr);
   }
	return ptr;
}

GICSAccount* GICSAccount::instance_fscan(string fname)	{
   return GICSAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

GICSAccount* GICSAccount::__ptr_GICSAccount = GICSAccount::instance();

int GICSAccount::gsec(double gcode) {return int(gcode/1000000);}

#endif

