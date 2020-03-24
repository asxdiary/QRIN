// Name:     ResearchDevelopmentIntensityAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ResearchDevelopmentIntensityAccount_cpp
#define ASX_ResearchDevelopmentIntensityAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "R_DoubleDbAccount.hpp"
#include "ResearchDevelopmentAccount.hpp"
#include "OperatingRevenueAccount.hpp"
#include "ResearchDevelopmentIntensityAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctFields;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

ResearchDevelopmentIntensityAccount::ResearchDevelopmentIntensityAccount() { init_NULL(); }
ResearchDevelopmentIntensityAccount::ResearchDevelopmentIntensityAccount(const ResearchDevelopmentIntensityAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
ResearchDevelopmentIntensityAccount::ResearchDevelopmentIntensityAccount(const ResearchDevelopmentIntensityAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void ResearchDevelopmentIntensityAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void ResearchDevelopmentIntensityAccount::init() {
   R_DoubleDbAccount::init(ResearchDevelopmentAccount::instance(),
                      OperatingRevenueAccount::instance(),
                      false, false);
	init_ResearchDevelopmentIntensityAccount();
}

void ResearchDevelopmentIntensityAccount::init_ResearchDevelopmentIntensityAccount() {
   set_id("ResearchDevelopmentIntensityAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

ResearchDevelopmentIntensityAccount::~ResearchDevelopmentIntensityAccount()	{ cleanMem(); }

void ResearchDevelopmentIntensityAccount::cleanMem()	{
	cleanMem_ResearchDevelopmentIntensityAccount();
   R_DoubleDbAccount::cleanMem();
}

void ResearchDevelopmentIntensityAccount::cleanMem_ResearchDevelopmentIntensityAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string ResearchDevelopmentIntensityAccount::className() const {return "ResearchDevelopmentIntensityAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void ResearchDevelopmentIntensityAccount::myerr_msg(string msg, string func) {
	err_msg("ResearchDevelopmentIntensityAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void ResearchDevelopmentIntensityAccount::fprint(string fname) {
   R_DoubleDbAccount::fprint(fname);
	fprint_ResearchDevelopmentIntensityAccount(fname);
}

void ResearchDevelopmentIntensityAccount::fprint_ResearchDevelopmentIntensityAccount(string fname) {
}

void ResearchDevelopmentIntensityAccount::fscan(string fname) {
   R_DoubleDbAccount::fscan(fname);
	fscan_ResearchDevelopmentIntensityAccount(fname);
}

void ResearchDevelopmentIntensityAccount::fscan_ResearchDevelopmentIntensityAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void ResearchDevelopmentIntensityAccount::reset() {
	reset_ResearchDevelopmentIntensityAccount();
   R_DoubleDbAccount::reset();
}

void ResearchDevelopmentIntensityAccount::reset_ResearchDevelopmentIntensityAccount() {
}

/** ----------  static instance function -----------*/


ResearchDevelopmentIntensityAccount* ResearchDevelopmentIntensityAccount::instance()	{
	ResearchDevelopmentIntensityAccount* ptr = NULL;
   string id = "ResearchDevelopmentIntensityAccount";

   ptr = (ResearchDevelopmentIntensityAccount*) util_singleton("ResearchDevelopmentIntensityAccount",id);
   if(ptr==NULL) {
      ptr = new ResearchDevelopmentIntensityAccount();
      ptr->init();
      util_singleton("ResearchDevelopmentIntensityAccount",id,ptr);
   }
	return ptr;
}

ResearchDevelopmentIntensityAccount* ResearchDevelopmentIntensityAccount::instance_fscan(string fname)	{
   return ResearchDevelopmentIntensityAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

ResearchDevelopmentIntensityAccount* ResearchDevelopmentIntensityAccount::__ptr_ResearchDevelopmentIntensityAccount = ResearchDevelopmentIntensityAccount::instance();

#endif

