// Name:     D_DoubleDbAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_DoubleDbAccount_cpp
#define ASX_D_DoubleDbAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DoubleDbAccount.hpp"
#include "ObjectDb.hpp"
#include "D_DoubleDbAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;

/** --------------Constructors and init_NULL-----------*/

D_DoubleDbAccount::D_DoubleDbAccount() { init_NULL(); }
D_DoubleDbAccount::D_DoubleDbAccount(const D_DoubleDbAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
D_DoubleDbAccount::D_DoubleDbAccount(const D_DoubleDbAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void D_DoubleDbAccount::init_NULL()	{
	_bdba=NULL;
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void D_DoubleDbAccount::init(DoubleDbAccount* bdba) {
   DoubleDbAccount::init("growth");
	init_D_DoubleDbAccount(bdba);
}

void D_DoubleDbAccount::init_D_DoubleDbAccount(DoubleDbAccount* bdba) {
	init_bdba(bdba);
   set_nhistory(2);
}

void D_DoubleDbAccount::init_bdba(DoubleDbAccount* bdba) {
   _bdba = bdba;
}

/** -----Destructors and Memory Cleanup functions -----*/

D_DoubleDbAccount::~D_DoubleDbAccount()	{ cleanMem(); }

void D_DoubleDbAccount::cleanMem()	{
	cleanMem_D_DoubleDbAccount();
	DoubleDbAccount::cleanMem();
}

void D_DoubleDbAccount::cleanMem_D_DoubleDbAccount() {
	cleanMem_bdba();
}

void D_DoubleDbAccount::cleanMem_bdba() {
	_bdba=NULL;
}

/** ------------- Data Access Functions --------------------*/

DoubleDbAccount* D_DoubleDbAccount::bdba() {return _bdba;}

/** ------------- Access classname dynamically --------------------*/

string D_DoubleDbAccount::className() const {return "D_DoubleDbAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void D_DoubleDbAccount::myerr_msg(string msg, string func) {
	err_msg("D_DoubleDbAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void D_DoubleDbAccount::fprint(string fname) {
	DoubleDbAccount::fprint(fname);
	fprint_D_DoubleDbAccount(fname);
}

void D_DoubleDbAccount::fprint_D_DoubleDbAccount(string fname) {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
}

void D_DoubleDbAccount::fscan(string fname) {
	DoubleDbAccount::fscan(fname);
	fscan_D_DoubleDbAccount(fname);
}

void D_DoubleDbAccount::fscan_D_DoubleDbAccount(string fname) {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
}

/** ------------- Reset Functions --------------------*/

void D_DoubleDbAccount::reset() {
	reset_D_DoubleDbAccount();
	DoubleDbAccount::reset();
}

void D_DoubleDbAccount::reset_D_DoubleDbAccount() {
}

/** ----------  static instance function -----------*/


D_DoubleDbAccount* D_DoubleDbAccount::instance(DoubleDbAccount* bdba)	{
	D_DoubleDbAccount* ptr=new D_DoubleDbAccount();
	ptr->init(bdba);
	return ptr;
}


D_DoubleDbAccount* D_DoubleDbAccount::instance_fscan(string fname)	{
	D_DoubleDbAccount* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new D_DoubleDbAccount();
		ptr->init_NULL();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

void D_DoubleDbAccount::compute(vector<ObjectDb*>* odbv, int& xval) {
   DbAccount::compute(odbv, xval);
   if(xval>0) return;

   DoubleDbAccount* bdba = NULL;
   ObjectDb* odb0 = NULL;
   ObjectDb* odb1 = NULL;
   UtilDate* dh0 = NULL;
   UtilDate* dh1 = NULL;
   double x0, x1, x;
   int num;

   bdba = this->bdba();
   num = odbv->size();
   odb0 = odbv->at(num-1);
   odb1 = odbv->at(num-2);
   dh0 = odb0->dh();
   dh1 = odb1->dh();

   x0 = odb0->ddba(NULL,NULL,dh0,bdba,xval);
   if(xval>0) return;
   x1 = odb1->ddba(NULL,NULL,dh1,bdba,xval);
   if(xval>0) return;

   x = x0 - x1;
   odb0->add_ddba(this, x, xval);

   return;
}

/** If any of the values are missing, xval is set to 1 */
double D_DoubleDbAccount::agg_guts(vector<ObjectDb*>* odbv, UtilDate* dh, int& xval) {
   double x;
   int n;

   xval = 0;
   x = 0; n = odbv->size();
   for(int i=0;i<n && (xval==0);i++) x += odbv->at(i)->ddba(NULL, NULL, dh, this, xval);

   return x;
}

#endif

