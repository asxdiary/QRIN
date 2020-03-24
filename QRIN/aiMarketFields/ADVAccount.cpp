// Name:     ADVAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ADVAccount_cpp
#define ASX_ADVAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "StatisticAccount.hpp"
#include "ADVAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiMarketFields;

/** --------------Constructors and init_NULL-----------*/

ADVAccount::ADVAccount() { init_NULL(); }
ADVAccount::ADVAccount(const ADVAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
ADVAccount::ADVAccount(const ADVAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void ADVAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void ADVAccount::init() {
   StatisticAccount::init();
	init_ADVAccount();
}

void ADVAccount::init_ADVAccount() {
   set_id("ADVAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

ADVAccount::~ADVAccount()	{ cleanMem(); }

void ADVAccount::cleanMem()	{
	cleanMem_ADVAccount();
   StatisticAccount::cleanMem();
}

void ADVAccount::cleanMem_ADVAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string ADVAccount::className() const {return "ADVAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void ADVAccount::myerr_msg(string msg, string func) {
	err_msg("ADVAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void ADVAccount::fprint(string fname) {
   StatisticAccount::fprint(fname);
	fprint_ADVAccount(fname);
}

void ADVAccount::fprint_ADVAccount(string fname) {
}

void ADVAccount::fscan(string fname) {
   StatisticAccount::fscan(fname);
	fscan_ADVAccount(fname);
}

void ADVAccount::fscan_ADVAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void ADVAccount::reset() {
	reset_ADVAccount();
   StatisticAccount::reset();
}

void ADVAccount::reset_ADVAccount() {
}

/** ----------  static instance function -----------*/


ADVAccount* ADVAccount::instance()	{
	ADVAccount* ptr = NULL;
   string id = "ADVAccount";

   ptr = (ADVAccount*) util_singleton("ADVAccount",id);
   if(ptr==NULL) {
      ptr = new ADVAccount();
      ptr->init();
      util_singleton("ADVAccount",id,ptr);
   }
	return ptr;
}

ADVAccount* ADVAccount::instance_fscan(string fname)	{
   return ADVAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

ADVAccount* ADVAccount::__ptr_ADVAccount = ADVAccount::instance();

#endif

