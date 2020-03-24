// Name:     G_DoubleDbAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_G_DoubleDbAccount_cpp
#define ASX_G_DoubleDbAccount_cpp


#include <stdio.h>
#include <math.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DoubleDbAccount.hpp"
#include "ObjectDb.hpp"
#include "G_DoubleDbAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;

/** --------------Constructors and init_NULL-----------*/

G_DoubleDbAccount::G_DoubleDbAccount() { init_NULL(); }
G_DoubleDbAccount::G_DoubleDbAccount(const G_DoubleDbAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
G_DoubleDbAccount::G_DoubleDbAccount(const G_DoubleDbAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void G_DoubleDbAccount::init_NULL()	{
	_bdba=NULL;
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void G_DoubleDbAccount::init(DoubleDbAccount* bdba, bool geom_flag) {
   DoubleDbAccount::init("growth");
	init_G_DoubleDbAccount(bdba);
   init_geom_flag(geom_flag);
}

void G_DoubleDbAccount::init_G_DoubleDbAccount(DoubleDbAccount* bdba) {
	init_bdba(bdba);
   set_nhistory(2);
}

void G_DoubleDbAccount::init_bdba(DoubleDbAccount* bdba) {
   _bdba = bdba;
}

void G_DoubleDbAccount::init_geom_flag(bool geom_flag) {
   _geom_flag = geom_flag;
}

/** -----Destructors and Memory Cleanup functions -----*/

G_DoubleDbAccount::~G_DoubleDbAccount()	{ cleanMem(); }

void G_DoubleDbAccount::cleanMem()	{
	cleanMem_G_DoubleDbAccount();
	DoubleDbAccount::cleanMem();
}

void G_DoubleDbAccount::cleanMem_G_DoubleDbAccount() {
	cleanMem_bdba();
}

void G_DoubleDbAccount::cleanMem_bdba() {
	_bdba=NULL;
}

/** ------------- Data Access Functions --------------------*/

DoubleDbAccount* G_DoubleDbAccount::bdba() {return _bdba;}
bool G_DoubleDbAccount::geom_flag() {return _geom_flag;}

/** ------------- Access classname dynamically --------------------*/

string G_DoubleDbAccount::className() const {return "G_DoubleDbAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void G_DoubleDbAccount::myerr_msg(string msg, string func) {
	err_msg("G_DoubleDbAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void G_DoubleDbAccount::fprint(string fname) {
	DoubleDbAccount::fprint(fname);
	fprint_G_DoubleDbAccount(fname);
}

void G_DoubleDbAccount::fprint_G_DoubleDbAccount(string fname) {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
}

void G_DoubleDbAccount::fscan(string fname) {
	DoubleDbAccount::fscan(fname);
	fscan_G_DoubleDbAccount(fname);
}

void G_DoubleDbAccount::fscan_G_DoubleDbAccount(string fname) {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
}

/** ------------- Reset Functions --------------------*/

void G_DoubleDbAccount::reset() {
	reset_G_DoubleDbAccount();
	DoubleDbAccount::reset();
}

void G_DoubleDbAccount::reset_G_DoubleDbAccount() {
}

/** ----------  static instance function -----------*/


G_DoubleDbAccount* G_DoubleDbAccount::instance(DoubleDbAccount* bdba, bool geom_flag)	{
	G_DoubleDbAccount* ptr=new G_DoubleDbAccount();
	ptr->init(bdba, geom_flag);
	return ptr;
}


G_DoubleDbAccount* G_DoubleDbAccount::instance_fscan(string fname)	{
	G_DoubleDbAccount* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new G_DoubleDbAccount();
		ptr->init_NULL();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

void G_DoubleDbAccount::compute(vector<ObjectDb*>* odbv, int& xval) {
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

   if(util_isZero(x1) || x1 < 0 || x0 < 0) {xval=1; return;}
   if(geom_flag() && util_isZero(x0)) {xval=1; return;}
   
   if(geom_flag()) x = log(x0/x1);
   else x = x0/x1 - 1;
   odb0->add_ddba(this, x, xval);

   return;
}

/** If any of the values are missing, xval is set to 1 */
double G_DoubleDbAccount::agg_guts(vector<ObjectDb*>* odbv, UtilDate* dh, int& xval) {
   double x;
   int n;

   xval = 0;
   n = odbv->size();

   if(geom_flag()) {
      x = 0;
      for(int i=0;i<n && (xval==0);i++) x += odbv->at(i)->ddba(NULL, NULL, dh, this, xval);
   }
   else {
      x = 1;
      for(int i=0;i<n && (xval==0);i++) x *= 1 + odbv->at(i)->ddba(NULL, NULL, dh, this, xval);
      x -= 1;
   }

   return x;
}



#endif

