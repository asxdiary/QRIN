// Name:     D_AssetTOAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_AssetTOAccount_cpp
#define ASX_D_AssetTOAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "D_DoubleDbAccount.hpp"
#include "AssetTOAccount.hpp"
#include "D_AssetTOAccount.hpp"
#include "TemplatePositionAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctVars;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

D_AssetTOAccount::D_AssetTOAccount() { init_NULL(); }
D_AssetTOAccount::D_AssetTOAccount(const D_AssetTOAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
D_AssetTOAccount::D_AssetTOAccount(const D_AssetTOAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void D_AssetTOAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void D_AssetTOAccount::init() {
   D_DoubleDbAccount::init(AssetTOAccount::instance());
	init_D_AssetTOAccount();
}

void D_AssetTOAccount::init_D_AssetTOAccount() {
   set_id("D_AssetTOAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

D_AssetTOAccount::~D_AssetTOAccount()	{ cleanMem(); }

void D_AssetTOAccount::cleanMem()	{
	cleanMem_D_AssetTOAccount();
   D_DoubleDbAccount::cleanMem();
}

void D_AssetTOAccount::cleanMem_D_AssetTOAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string D_AssetTOAccount::className() const {return "D_AssetTOAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void D_AssetTOAccount::myerr_msg(string msg, string func) {
	err_msg("D_AssetTOAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void D_AssetTOAccount::fprint(string fname) {
   D_DoubleDbAccount::fprint(fname);
	fprint_D_AssetTOAccount(fname);
}

void D_AssetTOAccount::fprint_D_AssetTOAccount(string fname) {
}

void D_AssetTOAccount::fscan(string fname) {
   D_DoubleDbAccount::fscan(fname);
	fscan_D_AssetTOAccount(fname);
}

void D_AssetTOAccount::fscan_D_AssetTOAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void D_AssetTOAccount::reset() {
	reset_D_AssetTOAccount();
   D_DoubleDbAccount::reset();
}

void D_AssetTOAccount::reset_D_AssetTOAccount() {
}

/** ----------  static instance function -----------*/


D_AssetTOAccount* D_AssetTOAccount::instance()	{
	D_AssetTOAccount* ptr = NULL;
   string id = "D_AssetTOAccount";

   ptr = (D_AssetTOAccount*) util_singleton("D_AssetTOAccount",id);
   if(ptr==NULL) {
      ptr = new D_AssetTOAccount();
      ptr->init();
      util_singleton("D_AssetTOAccount",id,ptr);
   }
	return ptr;
}

D_AssetTOAccount* D_AssetTOAccount::instance_fscan(string fname)	{
   return D_AssetTOAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

D_AssetTOAccount* D_AssetTOAccount::__ptr_D_AssetTOAccount = D_AssetTOAccount::instance();

#endif

