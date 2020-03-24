// Name:     WorkingCapitalAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_WorkingCapitalAccount_cpp
#define ASX_WorkingCapitalAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "ObjectDb.hpp"
#include "DoubleDbAccount.hpp"
#include "CurrentAssetsAccount.hpp"
#include "CurrentLiabilitiesAccount.hpp"
#include "WorkingCapitalAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctVars;
using namespace aiDb;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

WorkingCapitalAccount::WorkingCapitalAccount() { init_NULL(); }
WorkingCapitalAccount::WorkingCapitalAccount(const WorkingCapitalAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
WorkingCapitalAccount::WorkingCapitalAccount(const WorkingCapitalAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void WorkingCapitalAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void WorkingCapitalAccount::init() {
   DoubleDbAccount::init("position");
	init_WorkingCapitalAccount();
}

void WorkingCapitalAccount::init_WorkingCapitalAccount() {
   set_id("WorkingCapitalAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

WorkingCapitalAccount::~WorkingCapitalAccount()	{ cleanMem(); }

void WorkingCapitalAccount::cleanMem()	{
	cleanMem_WorkingCapitalAccount();
	DoubleDbAccount::cleanMem();
}

void WorkingCapitalAccount::cleanMem_WorkingCapitalAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string WorkingCapitalAccount::className() const {return "WorkingCapitalAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void WorkingCapitalAccount::myerr_msg(string msg, string func) {
	err_msg("WorkingCapitalAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void WorkingCapitalAccount::fprint(string fname) {
	DoubleDbAccount::fprint(fname);
	fprint_WorkingCapitalAccount(fname);
}

void WorkingCapitalAccount::fprint_WorkingCapitalAccount(string fname) {
}

void WorkingCapitalAccount::fscan(string fname) {
	DoubleDbAccount::fscan(fname);
	fscan_WorkingCapitalAccount(fname);
}

void WorkingCapitalAccount::fscan_WorkingCapitalAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void WorkingCapitalAccount::reset() {
	reset_WorkingCapitalAccount();
	DoubleDbAccount::reset();
}

void WorkingCapitalAccount::reset_WorkingCapitalAccount() {
}

/** ----------  static instance function -----------*/

WorkingCapitalAccount* WorkingCapitalAccount::instance()	{
	WorkingCapitalAccount* ptr = NULL;
   string id = "WorkingCapitalAccount";

   ptr = (WorkingCapitalAccount*) util_singleton("WorkingCapitalAccount",id);
   if(ptr==NULL) {
      ptr = new WorkingCapitalAccount();
      ptr->init();
      util_singleton("WorkingCapitalAccount",id,ptr);
   }
	return ptr;
}

WorkingCapitalAccount* WorkingCapitalAccount::instance_fscan(string fname)	{
   return WorkingCapitalAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

void WorkingCapitalAccount::compute(vector<ObjectDb*>* odbv, int& xval) {
   DbAccount::compute(odbv, xval);
   if(xval>0) return;

   DoubleDbAccount* ca_dba = CurrentAssetsAccount::instance();
   DoubleDbAccount* cl_dba = CurrentLiabilitiesAccount::instance();

   ObjectDb* odb0 = NULL;
   UtilDate* dh0 = NULL;
   double ca, cl, x;
   int num;

   num = odbv->size();
   odb0 = odbv->at(num-1);
   dh0 = odb0->dh();

   ca = odb0->ddba(NULL,NULL,dh0,ca_dba,xval); if(xval>0) return;
   cl = odb0->ddba(NULL,NULL,dh0,cl_dba,xval); if(xval>0) return;

   x = ca - cl;
   odb0->add_ddba(this, x, xval);

   return;
}

#endif

