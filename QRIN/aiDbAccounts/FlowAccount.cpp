// Name:     FlowAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_FlowAccount_cpp
#define ASX_FlowAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DoubleDbAccount.hpp"
#include "FlowAccount.hpp"
#include "ObjectDb.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;

/** --------------Constructors and init_NULL-----------*/

FlowAccount::FlowAccount() { init_NULL(); }
FlowAccount::FlowAccount(const FlowAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
FlowAccount::FlowAccount(const FlowAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void FlowAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void FlowAccount::init() {
   DoubleDbAccount::init("flow");
	init_FlowAccount();
}

void FlowAccount::init_FlowAccount() {
}

/** -----Destructors and Memory Cleanup functions -----*/

FlowAccount::~FlowAccount()	{ cleanMem(); }

void FlowAccount::cleanMem()	{
	cleanMem_FlowAccount();
   DoubleDbAccount::cleanMem();
}

void FlowAccount::cleanMem_FlowAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string FlowAccount::className() const {return "FlowAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void FlowAccount::myerr_msg(string msg, string func) {
	err_msg("FlowAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void FlowAccount::fprint(string fname) {
   DoubleDbAccount::fprint(fname);
	fprint_FlowAccount(fname);
}

void FlowAccount::fprint_FlowAccount(string fname) {
}

void FlowAccount::fscan(string fname) {
   DoubleDbAccount::fscan(fname);
	fscan_FlowAccount(fname);
}

void FlowAccount::fscan_FlowAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void FlowAccount::reset() {
	reset_FlowAccount();
   DoubleDbAccount::reset();
}

void FlowAccount::reset_FlowAccount() {
}

/** ----------  static instance function -----------*/


FlowAccount* FlowAccount::instance()	{
	FlowAccount* ptr=new FlowAccount();
	ptr->init();
	return ptr;
}


FlowAccount* FlowAccount::instance_fscan(string fname)	{
	FlowAccount* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new FlowAccount();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

/** Currently, missing values are assumed to be equal to 0, and are admissible */
double FlowAccount::agg_guts(vector<ObjectDb*>* odbv, UtilDate* dh, int& xval) {
   double x;
   int n;

   xval = 0;
   x = 0; n = odbv->size();
   for(int i=0;i<n;i++) x += odbv->at(i)->ddba(NULL, NULL, dh, this, xval);

   xval=0;
   return x;
}

#endif

