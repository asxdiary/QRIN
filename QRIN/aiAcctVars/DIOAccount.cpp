// Name:     DIOAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DIOAccount_cpp
#define ASX_DIOAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "ObjectDb.hpp"
#include "DoubleDbAccount.hpp"
#include "InventoryTOAccount.hpp"
#include "DIOAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctVars;
using namespace aiDb;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

DIOAccount::DIOAccount() { init_NULL(); }
DIOAccount::DIOAccount(const DIOAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
DIOAccount::DIOAccount(const DIOAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void DIOAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void DIOAccount::init() {
   DoubleDbAccount::init("days");
	init_DIOAccount();
}

void DIOAccount::init_DIOAccount() {
   set_id("DIOAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

DIOAccount::~DIOAccount()	{ cleanMem(); }

void DIOAccount::cleanMem()	{
	cleanMem_DIOAccount();
	DoubleDbAccount::cleanMem();
}

void DIOAccount::cleanMem_DIOAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string DIOAccount::className() const {return "DIOAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void DIOAccount::myerr_msg(string msg, string func) {
	err_msg("DIOAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void DIOAccount::fprint(string fname) {
	DoubleDbAccount::fprint(fname);
	fprint_DIOAccount(fname);
}

void DIOAccount::fprint_DIOAccount(string fname) {
}

void DIOAccount::fscan(string fname) {
	DoubleDbAccount::fscan(fname);
	fscan_DIOAccount(fname);
}

void DIOAccount::fscan_DIOAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void DIOAccount::reset() {
	reset_DIOAccount();
	DoubleDbAccount::reset();
}

void DIOAccount::reset_DIOAccount() {
}

/** ----------  static instance function -----------*/

DIOAccount* DIOAccount::instance()	{
	DIOAccount* ptr = NULL;
   string id = "DIOAccount";

   ptr = (DIOAccount*) util_singleton("DIOAccount",id);
   if(ptr==NULL) {
      ptr = new DIOAccount();
      ptr->init();
      util_singleton("DIOAccount",id,ptr);
   }
	return ptr;
}

DIOAccount* DIOAccount::instance_fscan(string fname)	{
   return DIOAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

void DIOAccount::compute(vector<ObjectDb*>* odbv, int& xval) {
   DbAccount::compute(odbv, xval);
   if(xval>0) return;

   DoubleDbAccount* invto_dba = InventoryTOAccount::instance();

   ObjectDb* odb0 = NULL;
   UtilDate* dh0 = NULL;
   double invto, x;
   int num;

   num = odbv->size();
   odb0 = odbv->at(num-1);
   dh0 = odb0->dh();

   invto = odb0->ddba(NULL,NULL,dh0,invto_dba,xval); if(xval>0) return;

   if(util_isZero(invto) || invto<0) {x=0; xval=1;}
   else x = 365.0/invto;
   odb0->add_ddba(this, x, xval);

   return;
}

#endif

