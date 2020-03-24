// Name:     ADRIndicatorAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ADRIndicatorAccount_cpp
#define ASX_ADRIndicatorAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "StringDbAccount.hpp"
#include "ObjectDb.hpp"
#include "ADRIndicatorAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiDbAccounts;
using namespace aiMarketFields;

/** --------------Constructors and init_NULL-----------*/

ADRIndicatorAccount::ADRIndicatorAccount() { init_NULL(); }
ADRIndicatorAccount::ADRIndicatorAccount(const ADRIndicatorAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
ADRIndicatorAccount::ADRIndicatorAccount(const ADRIndicatorAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void ADRIndicatorAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void ADRIndicatorAccount::init() {
   StringDbAccount::init("position");
	init_ADRIndicatorAccount();
}

void ADRIndicatorAccount::init_ADRIndicatorAccount() {
   set_id("ADRIndicatorAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

ADRIndicatorAccount::~ADRIndicatorAccount()	{ cleanMem(); }

void ADRIndicatorAccount::cleanMem()	{
	cleanMem_ADRIndicatorAccount();
   StringDbAccount::cleanMem();
}

void ADRIndicatorAccount::cleanMem_ADRIndicatorAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string ADRIndicatorAccount::className() const {return "ADRIndicatorAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void ADRIndicatorAccount::myerr_msg(string msg, string func) {
	err_msg("ADRIndicatorAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void ADRIndicatorAccount::fprint(string fname) {
   StringDbAccount::fprint(fname);
	fprint_ADRIndicatorAccount(fname);
}

void ADRIndicatorAccount::fprint_ADRIndicatorAccount(string fname) {
}

void ADRIndicatorAccount::fscan(string fname) {
   StringDbAccount::fscan(fname);
	fscan_ADRIndicatorAccount(fname);
}

void ADRIndicatorAccount::fscan_ADRIndicatorAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void ADRIndicatorAccount::reset() {
	reset_ADRIndicatorAccount();
   StringDbAccount::reset();
}

void ADRIndicatorAccount::reset_ADRIndicatorAccount() {
}

/** ----------  static instance function -----------*/


ADRIndicatorAccount* ADRIndicatorAccount::instance()	{
	ADRIndicatorAccount* ptr = NULL;
   string id = "ADRIndicatorAccount";

   ptr = (ADRIndicatorAccount*) util_singleton("ADRIndicatorAccount",id);
   if(ptr==NULL) {
      ptr = new ADRIndicatorAccount();
      ptr->init();
      util_singleton("ADRIndicatorAccount",id,ptr);
   }
	return ptr;
}

ADRIndicatorAccount* ADRIndicatorAccount::instance_fscan(string fname)	{
   return ADRIndicatorAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

ADRIndicatorAccount* ADRIndicatorAccount::__ptr_ADRIndicatorAccount = ADRIndicatorAccount::instance();

bool ADRIndicatorAccount::isADR(string adr_str) {
   return adr_str.compare("1")==0;
}

#endif

