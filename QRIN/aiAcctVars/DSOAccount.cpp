// Name:     DSOAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DSOAccount_cpp
#define ASX_DSOAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "ObjectDb.hpp"
#include "DoubleDbAccount.hpp"
#include "ReceivablesTOAccount.hpp"
#include "DSOAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctVars;
using namespace aiDb;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

DSOAccount::DSOAccount() { init_NULL(); }
DSOAccount::DSOAccount(const DSOAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
DSOAccount::DSOAccount(const DSOAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void DSOAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void DSOAccount::init() {
   DoubleDbAccount::init("days");
	init_DSOAccount();
}

void DSOAccount::init_DSOAccount() {
   set_id("DSOAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

DSOAccount::~DSOAccount()	{ cleanMem(); }

void DSOAccount::cleanMem()	{
	cleanMem_DSOAccount();
	DoubleDbAccount::cleanMem();
}

void DSOAccount::cleanMem_DSOAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string DSOAccount::className() const {return "DSOAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void DSOAccount::myerr_msg(string msg, string func) {
	err_msg("DSOAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void DSOAccount::fprint(string fname) {
	DoubleDbAccount::fprint(fname);
	fprint_DSOAccount(fname);
}

void DSOAccount::fprint_DSOAccount(string fname) {
}

void DSOAccount::fscan(string fname) {
	DoubleDbAccount::fscan(fname);
	fscan_DSOAccount(fname);
}

void DSOAccount::fscan_DSOAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void DSOAccount::reset() {
	reset_DSOAccount();
	DoubleDbAccount::reset();
}

void DSOAccount::reset_DSOAccount() {
}

/** ----------  static instance function -----------*/

DSOAccount* DSOAccount::instance()	{
	DSOAccount* ptr = NULL;
   string id = "DSOAccount";

   ptr = (DSOAccount*) util_singleton("DSOAccount",id);
   if(ptr==NULL) {
      ptr = new DSOAccount();
      ptr->init();
      util_singleton("DSOAccount",id,ptr);
   }
	return ptr;
}

DSOAccount* DSOAccount::instance_fscan(string fname)	{
   return DSOAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

void DSOAccount::compute(vector<ObjectDb*>* odbv, int& xval) {
   DbAccount::compute(odbv, xval);
   if(xval>0) return;

   DoubleDbAccount* tover_dba = ReceivablesTOAccount::instance();

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

