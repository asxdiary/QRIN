// Name:     AvailabilityDateAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_AvailabilityDateAccount_cpp
#define ASX_AvailabilityDateAccount_cpp


#include <stdio.h>
#include <algorithm>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DateAccount.hpp"
#include "AvailabilityDateAccount.hpp"
#include "ObjectDb.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiDbAccounts;

/** --------------Constructors and init_NULL-----------*/

AvailabilityDateAccount::AvailabilityDateAccount() { init_NULL(); }
AvailabilityDateAccount::AvailabilityDateAccount(const AvailabilityDateAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
AvailabilityDateAccount::AvailabilityDateAccount(const AvailabilityDateAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void AvailabilityDateAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void AvailabilityDateAccount::init() {
   DateAccount::init();
	init_AvailabilityDateAccount();
}

void AvailabilityDateAccount::init_AvailabilityDateAccount() {
   set_id("AvailabilityDateAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

AvailabilityDateAccount::~AvailabilityDateAccount()	{ cleanMem(); }

void AvailabilityDateAccount::cleanMem()	{
	cleanMem_AvailabilityDateAccount();
   DateAccount::cleanMem();
}

void AvailabilityDateAccount::cleanMem_AvailabilityDateAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string AvailabilityDateAccount::className() const {return "AvailabilityDateAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void AvailabilityDateAccount::myerr_msg(string msg, string func) {
	err_msg("AvailabilityDateAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void AvailabilityDateAccount::fprint(string fname) {
   DateAccount::fprint(fname);
	fprint_AvailabilityDateAccount(fname);
}

void AvailabilityDateAccount::fprint_AvailabilityDateAccount(string fname) {
}

void AvailabilityDateAccount::fscan(string fname) {
   DateAccount::fscan(fname);
	fscan_AvailabilityDateAccount(fname);
}

void AvailabilityDateAccount::fscan_AvailabilityDateAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void AvailabilityDateAccount::reset() {
	reset_AvailabilityDateAccount();
   DateAccount::reset();
}

void AvailabilityDateAccount::reset_AvailabilityDateAccount() {
}

/** ----------  static instance function -----------*/


AvailabilityDateAccount* AvailabilityDateAccount::instance()	{
	AvailabilityDateAccount* ptr = NULL;
   string id = "AvailabilityDateAccount";

   ptr = (AvailabilityDateAccount*) util_singleton("AvailabilityDateAccount",id);
   if(ptr==NULL) {
      ptr = new AvailabilityDateAccount();
      ptr->init();
      util_singleton("AvailabilityDateAccount",id,ptr);
   }
	return ptr;
}

AvailabilityDateAccount* AvailabilityDateAccount::instance_fscan(string fname)	{
   return AvailabilityDateAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

AvailabilityDateAccount* AvailabilityDateAccount::__ptr_AvailabilityDateAccount = AvailabilityDateAccount::instance();

/** Algorithm:
 * 1. Use the dba account for the last odb */
double AvailabilityDateAccount::agg_guts(vector<ObjectDb*>* odbv, UtilDate* dh, int& xval) {
   const int n = odbv->size();
   vector<double> dv(n);
   double x = 0;

   for(int i=0;i<n && (xval==0);i++) {
      dv.at(i) = odbv->at(i)->ddba(NULL,NULL,dh,this,xval);
   }

   if(xval==0) x = *max_element(dv.begin(), dv.end());

   return x;
}

void AvailabilityDateAccount::agg(ObjectDb* odb, vector<ObjectDb*>* odbv, UtilDate* dh, int& xval) {
   UtilDate* d = odb->dh();
   DateAccount::agg(odb, odbv, dh, xval);
   if(xval==0 && odb->dh()!=d) myerr_msg("agg function failed",__FUNCTION__);
   return;
}



#endif

