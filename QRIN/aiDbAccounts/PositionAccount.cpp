// Name:     PositionAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_PositionAccount_cpp
#define ASX_PositionAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DoubleDbAccount.hpp"
#include "PositionAccount.hpp"
#include "ObjectDb.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;

/** --------------Constructors and init_NULL-----------*/

PositionAccount::PositionAccount() { init_NULL(); }
PositionAccount::PositionAccount(const PositionAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
PositionAccount::PositionAccount(const PositionAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void PositionAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void PositionAccount::init() {
   DoubleDbAccount::init("position");
	init_PositionAccount();
}

void PositionAccount::init_PositionAccount() {
}

/** -----Destructors and Memory Cleanup functions -----*/

PositionAccount::~PositionAccount()	{ cleanMem(); }

void PositionAccount::cleanMem()	{
	cleanMem_PositionAccount();
   DoubleDbAccount::cleanMem();
}

void PositionAccount::cleanMem_PositionAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string PositionAccount::className() const {return "PositionAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void PositionAccount::myerr_msg(string msg, string func) {
	err_msg("PositionAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void PositionAccount::fprint(string fname) {
   DoubleDbAccount::fprint(fname);
	fprint_PositionAccount(fname);
}

void PositionAccount::fprint_PositionAccount(string fname) {
}

void PositionAccount::fscan(string fname) {
   DoubleDbAccount::fscan(fname);
	fscan_PositionAccount(fname);
}

void PositionAccount::fscan_PositionAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void PositionAccount::reset() {
	reset_PositionAccount();
   DoubleDbAccount::reset();
}

void PositionAccount::reset_PositionAccount() {
}

/** ----------  static instance function -----------*/


PositionAccount* PositionAccount::instance()	{
	PositionAccount* ptr=new PositionAccount();
	ptr->init();
	return ptr;
}


PositionAccount* PositionAccount::instance_fscan(string fname)	{
	PositionAccount* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new PositionAccount();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

/** Algorithm:
 * 1. Use the dba account for the last odb */
double PositionAccount::agg_guts(vector<ObjectDb*>* odbv, UtilDate* dh, int& xval) {
   ObjectDb* lodb = NULL;
   double x;

   xval = 0;
   lodb = odbv->back();
   x = lodb->ddba(NULL, NULL, dh, this, xval);

   return x;
}

#endif

