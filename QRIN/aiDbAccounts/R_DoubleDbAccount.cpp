// Name:     R_DoubleDbAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_R_DoubleDbAccount_cpp
#define ASX_R_DoubleDbAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DoubleDbAccount.hpp"
#include "ObjectDb.hpp"
#include "R_DoubleDbAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;

/** --------------Constructors and init_NULL-----------*/

R_DoubleDbAccount::R_DoubleDbAccount() { init_NULL(); }
R_DoubleDbAccount::R_DoubleDbAccount(const R_DoubleDbAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
R_DoubleDbAccount::R_DoubleDbAccount(const R_DoubleDbAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void R_DoubleDbAccount::init_NULL()	{
	_numer_dba=NULL;
	_denom_dba=NULL;
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void R_DoubleDbAccount::init(DoubleDbAccount* numer_dba, DoubleDbAccount* denom_dba, bool denom_avg_flag, bool reverse_flag) {
   DoubleDbAccount::init("ratio");
	init_R_DoubleDbAccount(numer_dba, denom_dba, denom_avg_flag, reverse_flag);
}

void R_DoubleDbAccount::init_R_DoubleDbAccount(DoubleDbAccount* numer_dba, DoubleDbAccount* denom_dba, bool denom_avg_flag, bool reverse_flag) {
	init_numer_dba(numer_dba);
	init_denom_dba(denom_dba);
	init_denom_avg_flag(denom_avg_flag);
	init_reverse_flag(reverse_flag);
}

void R_DoubleDbAccount::init_numer_dba(DoubleDbAccount* obj) {_numer_dba = obj;}
void R_DoubleDbAccount::init_denom_dba(DoubleDbAccount* obj) {_denom_dba = obj;}
void R_DoubleDbAccount::init_denom_avg_flag(bool obj) {
   _denom_avg_flag = obj;
   if(denom_avg_flag()) set_nhistory(2);
}
void R_DoubleDbAccount::init_reverse_flag(bool obj) {_reverse_flag = obj;}

/** -----Destructors and Memory Cleanup functions -----*/

R_DoubleDbAccount::~R_DoubleDbAccount()	{ cleanMem(); }

void R_DoubleDbAccount::cleanMem()	{
	cleanMem_R_DoubleDbAccount();
	DoubleDbAccount::cleanMem();
}

void R_DoubleDbAccount::cleanMem_R_DoubleDbAccount() {
	cleanMem_numer_dba();
	cleanMem_denom_dba();
}

void R_DoubleDbAccount::cleanMem_numer_dba() {
	_numer_dba=NULL;
}

void R_DoubleDbAccount::cleanMem_denom_dba() {
	_denom_dba=NULL;
}

/** ------------- Data Access Functions --------------------*/

DoubleDbAccount* R_DoubleDbAccount::numer_dba() {return _numer_dba;}
DoubleDbAccount* R_DoubleDbAccount::denom_dba() {return _denom_dba;}
bool R_DoubleDbAccount::denom_avg_flag() {return _denom_avg_flag;}
bool R_DoubleDbAccount::reverse_flag() {return _reverse_flag;}

/** ------------- Access classname dynamically --------------------*/

string R_DoubleDbAccount::className() const {return "R_DoubleDbAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void R_DoubleDbAccount::myerr_msg(string msg, string func) {
	err_msg("R_DoubleDbAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void R_DoubleDbAccount::fprint(string fname) {
	DoubleDbAccount::fprint(fname);
	fprint_R_DoubleDbAccount(fname);
}

void R_DoubleDbAccount::fprint_R_DoubleDbAccount(string fname) {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
}

void R_DoubleDbAccount::fscan(string fname) {
	DoubleDbAccount::fscan(fname);
	fscan_R_DoubleDbAccount(fname);
}

void R_DoubleDbAccount::fscan_R_DoubleDbAccount(string fname) {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
	//Insert scanning function for numer_dba here
	//Insert scanning function for denom_dba here
	//util_ofscan(fname,"denom_avg_flag",_denom_avg_flag);
}

/** ------------- Reset Functions --------------------*/

void R_DoubleDbAccount::reset() {
	reset_R_DoubleDbAccount();
	DoubleDbAccount::reset();
}

void R_DoubleDbAccount::reset_R_DoubleDbAccount() {
}

/** ----------  static instance function -----------*/


R_DoubleDbAccount* R_DoubleDbAccount::instance(DoubleDbAccount* numer_dba, DoubleDbAccount* denom_dba, bool denom_avg_flag, bool reverse_flag)	{
	R_DoubleDbAccount* ptr=new R_DoubleDbAccount();
	ptr->init(numer_dba, denom_dba, denom_avg_flag, reverse_flag);
	return ptr;
}


R_DoubleDbAccount* R_DoubleDbAccount::instance_fscan(string fname)	{
	R_DoubleDbAccount* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new R_DoubleDbAccount();
		ptr->init_NULL();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

void R_DoubleDbAccount::compute(vector<ObjectDb*>* odbv, int& xval) {
   DbAccount::compute(odbv, xval);
   if(xval>0) return;

   DoubleDbAccount* numer_dba = this->numer_dba();
   DoubleDbAccount* denom_dba = this->denom_dba();
   bool denom_avg_flag = this->denom_avg_flag();
   bool reverse_flag = this->reverse_flag();

   ObjectDb* odb0 = NULL;
   ObjectDb* odb1 = NULL;
   UtilDate* dh0 = NULL;
   UtilDate* dh1 = NULL;
   double numer, denom, x;
   int num;

   num = odbv->size();
   odb0 = odbv->at(num-1);
   dh0 = odb0->dh();
   if(denom_avg_flag) {
      odb1 = odbv->at(num-2);
      dh1 = odb1->dh();
   }

   numer = odb0->ddba(NULL,NULL,dh0,numer_dba,xval); if(xval>0) return;
   if(!denom_avg_flag) {
      denom = odb0->ddba(NULL,NULL,dh0,denom_dba,xval); if(xval>0) return;
   }
   else {
      double y0, y1;
      y0 = odb0->ddba(NULL,NULL,dh0,denom_dba,xval); if(xval>0) return;
      y1 = odb1->ddba(NULL,NULL,dh1,denom_dba,xval); if(xval>0) return;
      denom = 0.5 * (y0 + y1);
   }

   if(util_isZero(denom) || denom < 0) {xval=1; return;}

   x = numer/denom;
   if(reverse_flag) x = 1-x;
   odb0->add_ddba(this, x, xval);

   return;
}


#endif

