// Name:     DomicileAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DomicileAccount_cpp
#define ASX_DomicileAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "StringDbAccount.hpp"
#include "ObjectDb.hpp"
#include "DomicileAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiDbAccounts;
using namespace aiMarketFields;

/** --------------Constructors and init_NULL-----------*/

DomicileAccount::DomicileAccount() { init_NULL(); }
DomicileAccount::DomicileAccount(const DomicileAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
DomicileAccount::DomicileAccount(const DomicileAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void DomicileAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void DomicileAccount::init() {
   StringDbAccount::init("position");
	init_DomicileAccount();
}

void DomicileAccount::init_DomicileAccount() {
   set_id("DomicileAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

DomicileAccount::~DomicileAccount()	{ cleanMem(); }

void DomicileAccount::cleanMem()	{
	cleanMem_DomicileAccount();
   StringDbAccount::cleanMem();
}

void DomicileAccount::cleanMem_DomicileAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string DomicileAccount::className() const {return "DomicileAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void DomicileAccount::myerr_msg(string msg, string func) {
	err_msg("DomicileAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void DomicileAccount::fprint(string fname) {
   StringDbAccount::fprint(fname);
	fprint_DomicileAccount(fname);
}

void DomicileAccount::fprint_DomicileAccount(string fname) {
}

void DomicileAccount::fscan(string fname) {
   StringDbAccount::fscan(fname);
	fscan_DomicileAccount(fname);
}

void DomicileAccount::fscan_DomicileAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void DomicileAccount::reset() {
	reset_DomicileAccount();
   StringDbAccount::reset();
}

void DomicileAccount::reset_DomicileAccount() {
}

/** ----------  static instance function -----------*/


DomicileAccount* DomicileAccount::instance()	{
	DomicileAccount* ptr = NULL;
   string id = "DomicileAccount";

   ptr = (DomicileAccount*) util_singleton("DomicileAccount",id);
   if(ptr==NULL) {
      ptr = new DomicileAccount();
      ptr->init();
      util_singleton("DomicileAccount",id,ptr);
   }
	return ptr;
}

DomicileAccount* DomicileAccount::instance_fscan(string fname)	{
   return DomicileAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

DomicileAccount* DomicileAccount::__ptr_DomicileAccount = DomicileAccount::instance();

#endif

