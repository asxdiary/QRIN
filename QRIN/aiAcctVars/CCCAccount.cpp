// Name:     CCCAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CCCAccount_cpp
#define ASX_CCCAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "ObjectDb.hpp"
#include "DoubleDbAccount.hpp"
#include "DIOAccount.hpp"
#include "DSOAccount.hpp"
#include "DPOAccount.hpp"
#include "CCCAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctVars;
using namespace aiDb;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

CCCAccount::CCCAccount() { init_NULL(); }
CCCAccount::CCCAccount(const CCCAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
CCCAccount::CCCAccount(const CCCAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void CCCAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void CCCAccount::init() {
   DoubleDbAccount::init("days");
	init_CCCAccount();
}

void CCCAccount::init_CCCAccount() {
   set_id("CCCAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

CCCAccount::~CCCAccount()	{ cleanMem(); }

void CCCAccount::cleanMem()	{
	cleanMem_CCCAccount();
	DoubleDbAccount::cleanMem();
}

void CCCAccount::cleanMem_CCCAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string CCCAccount::className() const {return "CCCAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void CCCAccount::myerr_msg(string msg, string func) {
	err_msg("CCCAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void CCCAccount::fprint(string fname) {
	DoubleDbAccount::fprint(fname);
	fprint_CCCAccount(fname);
}

void CCCAccount::fprint_CCCAccount(string fname) {
}

void CCCAccount::fscan(string fname) {
	DoubleDbAccount::fscan(fname);
	fscan_CCCAccount(fname);
}

void CCCAccount::fscan_CCCAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void CCCAccount::reset() {
	reset_CCCAccount();
	DoubleDbAccount::reset();
}

void CCCAccount::reset_CCCAccount() {
}

/** ----------  static instance function -----------*/

CCCAccount* CCCAccount::instance()	{
	CCCAccount* ptr = NULL;
   string id = "CCCAccount";

   ptr = (CCCAccount*) util_singleton("CCCAccount",id);
   if(ptr==NULL) {
      ptr = new CCCAccount();
      ptr->init();
      util_singleton("CCCAccount",id,ptr);
   }
	return ptr;
}

CCCAccount* CCCAccount::instance_fscan(string fname)	{
   return CCCAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

void CCCAccount::compute(vector<ObjectDb*>* odbv, int& xval) {
   DbAccount::compute(odbv, xval);
   if(xval>0) return;

   DoubleDbAccount* dio_dba = DIOAccount::instance();
   DoubleDbAccount* dso_dba = DSOAccount::instance();
   DoubleDbAccount* dpo_dba = DPOAccount::instance();

   ObjectDb* odb0 = NULL;
   UtilDate* dh0 = NULL;
   double dio, dso, dpo, x;
   int num;

   num = odbv->size();
   odb0 = odbv->at(num-1);
   dh0 = odb0->dh();

   dio = odb0->ddba(NULL,NULL,dh0,dio_dba,xval); if(xval>0) return;
   dso = odb0->ddba(NULL,NULL,dh0,dso_dba,xval); if(xval>0) return;
   dpo = odb0->ddba(NULL,NULL,dh0,dpo_dba,xval); if(xval>0) return;

   x = dio + dso - dpo;
   odb0->add_ddba(this, x, xval);

   return;
}

#endif

