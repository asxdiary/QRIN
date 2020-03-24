// Name:     DoubleDbAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DoubleDbAccount_cpp
#define ASX_DoubleDbAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DbAccount.hpp"
#include "DoubleDbAccount.hpp"
#include "ObjectDb.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;

/** --------------Constructors and init_NULL-----------*/

DoubleDbAccount::DoubleDbAccount() { init_NULL(); }
DoubleDbAccount::DoubleDbAccount(const DoubleDbAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
DoubleDbAccount::DoubleDbAccount(const DoubleDbAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void DoubleDbAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void DoubleDbAccount::init(string type) {
   DbAccount::init(type,"double");
	init_DoubleDbAccount();
}

void DoubleDbAccount::init_DoubleDbAccount() {
}

/** -----Destructors and Memory Cleanup functions -----*/

DoubleDbAccount::~DoubleDbAccount()	{ cleanMem(); }

void DoubleDbAccount::cleanMem()	{
	cleanMem_DoubleDbAccount();
   DbAccount::cleanMem();
}

void DoubleDbAccount::cleanMem_DoubleDbAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string DoubleDbAccount::className() const {return "DoubleDbAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void DoubleDbAccount::myerr_msg(string msg, string func) {
	err_msg("DoubleDbAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void DoubleDbAccount::fprint(string fname) {
   DbAccount::fprint(fname);
	fprint_DoubleDbAccount(fname);
}

void DoubleDbAccount::fprint_DoubleDbAccount(string fname) {
}

void DoubleDbAccount::fscan(string fname) {
   DbAccount::fscan(fname);
	fscan_DoubleDbAccount(fname);
}

void DoubleDbAccount::fscan_DoubleDbAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void DoubleDbAccount::reset() {
	reset_DoubleDbAccount();
   DbAccount::reset();
}

void DoubleDbAccount::reset_DoubleDbAccount() {
}

/** ----------  static instance function -----------*/


DoubleDbAccount* DoubleDbAccount::instance(string type)	{
	DoubleDbAccount* ptr=new DoubleDbAccount();
	ptr->init(type);
	return ptr;
}


DoubleDbAccount* DoubleDbAccount::instance_fscan(string fname)	{
	DoubleDbAccount* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new DoubleDbAccount();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

void DoubleDbAccount::populate(ObjectDb* odb, string val, int& xval) {
   if(isEmpty(val)) xval = 1;
   else this->populate(odb, atof(val.c_str()), xval);
   return;
}

void DoubleDbAccount::populate(ObjectDb* odb, double val, int& xval) {
   xval = 0;
   odb->add_ddba(this, val, xval);
}

bool DoubleDbAccount::isEmpty(string val) {
   static set<string> S;

   if(S.size()==0) {
      S.insert("");
      S.insert(".");
      S.insert("na");
      S.insert("NA");
      S.insert("nan");
      S.insert("NaN");
      S.insert("NULL");
   }

   return S.find(val) != S.end();
}

void DoubleDbAccount::compute(vector<ObjectDb*>* odbv, int& xval) {
   DbAccount::compute(odbv, xval);
   if(xval>0) return;
   ObjectDb* odb = odbv->back();
   odb->ddba(NULL,NULL,odb->dh(),this,xval);
   return;
}

void DoubleDbAccount::agg(ObjectDb* odb, vector<ObjectDb*>* odbv, UtilDate* dh, int& xval) {
   double x = this->agg_guts(odbv, dh, xval);
   if(xval==0) odb->add_ddba(this, x, xval);
   return;
}

/** Algorithm:
 * 1. Use the dba account for the last odb */
double DoubleDbAccount::agg_guts(vector<ObjectDb*>* odbv, UtilDate* dh, int& xval) {
   ObjectDb* lodb = NULL;
   double x;

   xval = 0;
   lodb = odbv->back();
   x = lodb->ddba(NULL, NULL, dh, this, xval);

   return x;
}

void DoubleDbAccount::copy(UtilDate* dh, ObjectDb* odb1, ObjectDb* odb2, int& xval) {
   double x = odb1->ddba(NULL, NULL, dh, this, xval);
   odb2->add_ddba(this, x, xval);
   return;
}

void DoubleDbAccount::interpolate(ObjectDb* odb1, ObjectDb* odb2, ObjectDb* odb,
                                  int& xval) 
{
   UtilDate* dh = odb->dh();
   double x1, x2, eta, x;
   int n1, n2;

   //check if odb1 and odb2 are contigous
   if(odb1->end_d()!=odb2->start_d()) {xval=1; return;}

   xval = 0;
   x1 = odb1->ddba(NULL, NULL, dh, this, xval); if(xval>0) return;
   x2 = odb2->ddba(NULL, NULL, dh, this, xval); if(xval>0) return;

   n1 = UtilDate::nmonths(odb->start_d(), odb1->end_d());
   n2 = UtilDate::nmonths(odb2->start_d(), odb->end_d());

   if(n1<0 || n2<0) {xval=2; return;}
   eta = n1*1.0/(n1+n2);

   x = eta*x1 + (1-eta)*x2;
   odb->add_ddba(this, x, xval);

   return;
}

#endif

