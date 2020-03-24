// Name:     D_ResearchDevelopmentIntensityAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_ResearchDevelopmentIntensityAccount_cpp
#define ASX_D_ResearchDevelopmentIntensityAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "D_DoubleDbAccount.hpp"
#include "ResearchDevelopmentIntensityAccount.hpp"
#include "D_ResearchDevelopmentIntensityAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

D_ResearchDevelopmentIntensityAccount::D_ResearchDevelopmentIntensityAccount() { init_NULL(); }
D_ResearchDevelopmentIntensityAccount::D_ResearchDevelopmentIntensityAccount(const D_ResearchDevelopmentIntensityAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
D_ResearchDevelopmentIntensityAccount::D_ResearchDevelopmentIntensityAccount(const D_ResearchDevelopmentIntensityAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void D_ResearchDevelopmentIntensityAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void D_ResearchDevelopmentIntensityAccount::init() {
   D_DoubleDbAccount::init(ResearchDevelopmentIntensityAccount::instance());
	init_D_ResearchDevelopmentIntensityAccount();
}

void D_ResearchDevelopmentIntensityAccount::init_D_ResearchDevelopmentIntensityAccount() {
   set_id("D_ResearchDevelopmentIntensityAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

D_ResearchDevelopmentIntensityAccount::~D_ResearchDevelopmentIntensityAccount()	{ cleanMem(); }

void D_ResearchDevelopmentIntensityAccount::cleanMem()	{
	cleanMem_D_ResearchDevelopmentIntensityAccount();
   D_DoubleDbAccount::cleanMem();
}

void D_ResearchDevelopmentIntensityAccount::cleanMem_D_ResearchDevelopmentIntensityAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string D_ResearchDevelopmentIntensityAccount::className() const {return "D_ResearchDevelopmentIntensityAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void D_ResearchDevelopmentIntensityAccount::myerr_msg(string msg, string func) {
	err_msg("D_ResearchDevelopmentIntensityAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void D_ResearchDevelopmentIntensityAccount::fprint(string fname) {
   D_DoubleDbAccount::fprint(fname);
	fprint_D_ResearchDevelopmentIntensityAccount(fname);
}

void D_ResearchDevelopmentIntensityAccount::fprint_D_ResearchDevelopmentIntensityAccount(string fname) {
}

void D_ResearchDevelopmentIntensityAccount::fscan(string fname) {
   D_DoubleDbAccount::fscan(fname);
	fscan_D_ResearchDevelopmentIntensityAccount(fname);
}

void D_ResearchDevelopmentIntensityAccount::fscan_D_ResearchDevelopmentIntensityAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void D_ResearchDevelopmentIntensityAccount::reset() {
	reset_D_ResearchDevelopmentIntensityAccount();
   D_DoubleDbAccount::reset();
}

void D_ResearchDevelopmentIntensityAccount::reset_D_ResearchDevelopmentIntensityAccount() {
}

/** ----------  static instance function -----------*/


D_ResearchDevelopmentIntensityAccount* D_ResearchDevelopmentIntensityAccount::instance()	{
	D_ResearchDevelopmentIntensityAccount* ptr = NULL;
   string id = "D_ResearchDevelopmentIntensityAccount";

   ptr = (D_ResearchDevelopmentIntensityAccount*) util_singleton("D_ResearchDevelopmentIntensityAccount",id);
   if(ptr==NULL) {
      ptr = new D_ResearchDevelopmentIntensityAccount();
      ptr->init();
      util_singleton("D_ResearchDevelopmentIntensityAccount",id,ptr);
   }
	return ptr;
}

D_ResearchDevelopmentIntensityAccount* D_ResearchDevelopmentIntensityAccount::instance_fscan(string fname)	{
   return D_ResearchDevelopmentIntensityAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

D_ResearchDevelopmentIntensityAccount* D_ResearchDevelopmentIntensityAccount::__ptr_D_ResearchDevelopmentIntensityAccount = D_ResearchDevelopmentIntensityAccount::instance();

#endif

