// Name:     IntangibleAssetsAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_IntangibleAssetsAccount_cpp
#define ASX_IntangibleAssetsAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "IntangibleAssetsAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

IntangibleAssetsAccount::IntangibleAssetsAccount() { init_NULL(); }
IntangibleAssetsAccount::IntangibleAssetsAccount(const IntangibleAssetsAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
IntangibleAssetsAccount::IntangibleAssetsAccount(const IntangibleAssetsAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void IntangibleAssetsAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void IntangibleAssetsAccount::init() {
   PositionAccount::init();
	init_IntangibleAssetsAccount();
}

void IntangibleAssetsAccount::init_IntangibleAssetsAccount() {
   set_id("IntangibleAssetsAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

IntangibleAssetsAccount::~IntangibleAssetsAccount()	{ cleanMem(); }

void IntangibleAssetsAccount::cleanMem()	{
	cleanMem_IntangibleAssetsAccount();
   PositionAccount::cleanMem();
}

void IntangibleAssetsAccount::cleanMem_IntangibleAssetsAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string IntangibleAssetsAccount::className() const {return "IntangibleAssetsAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void IntangibleAssetsAccount::myerr_msg(string msg, string func) {
	err_msg("IntangibleAssetsAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void IntangibleAssetsAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_IntangibleAssetsAccount(fname);
}

void IntangibleAssetsAccount::fprint_IntangibleAssetsAccount(string fname) {
}

void IntangibleAssetsAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_IntangibleAssetsAccount(fname);
}

void IntangibleAssetsAccount::fscan_IntangibleAssetsAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void IntangibleAssetsAccount::reset() {
	reset_IntangibleAssetsAccount();
   PositionAccount::reset();
}

void IntangibleAssetsAccount::reset_IntangibleAssetsAccount() {
}

/** ----------  static instance function -----------*/


IntangibleAssetsAccount* IntangibleAssetsAccount::instance()	{
	IntangibleAssetsAccount* ptr = NULL;
   string id = "IntangibleAssetsAccount";

   ptr = (IntangibleAssetsAccount*) util_singleton("IntangibleAssetsAccount",id);
   if(ptr==NULL) {
      ptr = new IntangibleAssetsAccount();
      ptr->init();
      util_singleton("IntangibleAssetsAccount",id,ptr);
   }
	return ptr;
}

IntangibleAssetsAccount* IntangibleAssetsAccount::instance_fscan(string fname)	{
   return IntangibleAssetsAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

IntangibleAssetsAccount* IntangibleAssetsAccount::__ptr_IntangibleAssetsAccount = IntangibleAssetsAccount::instance();

#endif

