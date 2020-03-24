// Name:     DPOAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DPOAccount_cpp
#define ASX_DPOAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "ObjectDb.hpp"
#include "DoubleDbAccount.hpp"
#include "PayablesTOAccount.hpp"
#include "DPOAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctVars;
using namespace aiDb;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

DPOAccount::DPOAccount() { init_NULL(); }
DPOAccount::DPOAccount(const DPOAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
DPOAccount::DPOAccount(const DPOAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void DPOAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void DPOAccount::init() {
   DoubleDbAccount::init("days");
	init_DPOAccount();
}

void DPOAccount::init_DPOAccount() {
   set_id("DPOAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

DPOAccount::~DPOAccount()	{ cleanMem(); }

void DPOAccount::cleanMem()	{
	cleanMem_DPOAccount();
	DoubleDbAccount::cleanMem();
}

void DPOAccount::cleanMem_DPOAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string DPOAccount::className() const {return "DPOAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void DPOAccount::myerr_msg(string msg, string func) {
	err_msg("DPOAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void DPOAccount::fprint(string fname) {
	DoubleDbAccount::fprint(fname);
	fprint_DPOAccount(fname);
}

void DPOAccount::fprint_DPOAccount(string fname) {
}

void DPOAccount::fscan(string fname) {
	DoubleDbAccount::fscan(fname);
	fscan_DPOAccount(fname);
}

void DPOAccount::fscan_DPOAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void DPOAccount::reset() {
	reset_DPOAccount();
	DoubleDbAccount::reset();
}

void DPOAccount::reset_DPOAccount() {
}

/** ----------  static instance function -----------*/

DPOAccount* DPOAccount::instance()	{
	DPOAccount* ptr = NULL;
   string id = "DPOAccount";

   ptr = (DPOAccount*) util_singleton("DPOAccount",id);
   if(ptr==NULL) {
      ptr = new DPOAccount();
      ptr->init();
      util_singleton("DPOAccount",id,ptr);
   }
	return ptr;
}

DPOAccount* DPOAccount::instance_fscan(string fname)	{
   return DPOAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

void DPOAccount::compute(vector<ObjectDb*>* odbv, int& xval) {
   DbAccount::compute(odbv, xval);
   if(xval>0) return;

   DoubleDbAccount* tover_dba = PayablesTOAccount::instance();

   ObjectDb* odb0 = NULL;
   UtilDate* dh0 = NULL;
   double tover, x;
   int num;

   num = odbv->size();
   odb0 = odbv->at(num-1);
   dh0 = odb0->dh();

   tover = odb0->ddba(NULL,NULL,dh0,tover_dba,xval); if(xval>0) return;

   if(util_isZero(tover) || tover<0) {x=0; xval=1;}
   else x = 365.0/tover;
   odb0->add_ddba(this, x, xval);

   return;
}

#endif

