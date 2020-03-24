// Name:     ReportingDateAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ReportingDateAccount_cpp
#define ASX_ReportingDateAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DateAccount.hpp"
#include "ReportingDateAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctDbs;
using namespace aiAcctDbs;

/** --------------Constructors and init_NULL-----------*/

ReportingDateAccount::ReportingDateAccount() { init_NULL(); }
ReportingDateAccount::ReportingDateAccount(const ReportingDateAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
ReportingDateAccount::ReportingDateAccount(const ReportingDateAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void ReportingDateAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void ReportingDateAccount::init() {
   DateAccount::init();
	init_ReportingDateAccount();
}

void ReportingDateAccount::init_ReportingDateAccount() {
   set_id("ReportingDateAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

ReportingDateAccount::~ReportingDateAccount()	{ cleanMem(); }

void ReportingDateAccount::cleanMem()	{
	cleanMem_ReportingDateAccount();
   DateAccount::cleanMem();
}

void ReportingDateAccount::cleanMem_ReportingDateAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string ReportingDateAccount::className() const {return "ReportingDateAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void ReportingDateAccount::myerr_msg(string msg, string func) {
	err_msg("ReportingDateAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void ReportingDateAccount::fprint(string fname) {
   DateAccount::fprint(fname);
	fprint_ReportingDateAccount(fname);
}

void ReportingDateAccount::fprint_ReportingDateAccount(string fname) {
}

void ReportingDateAccount::fscan(string fname) {
   DateAccount::fscan(fname);
	fscan_ReportingDateAccount(fname);
}

void ReportingDateAccount::fscan_ReportingDateAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void ReportingDateAccount::reset() {
	reset_ReportingDateAccount();
   DateAccount::reset();
}

void ReportingDateAccount::reset_ReportingDateAccount() {
}

/** ----------  static instance function -----------*/


ReportingDateAccount* ReportingDateAccount::instance()	{
	ReportingDateAccount* ptr = NULL;
   string id = "ReportingDateAccount";

   ptr = (ReportingDateAccount*) util_singleton("ReportingDateAccount",id);
   if(ptr==NULL) {
      ptr = new ReportingDateAccount();
      ptr->init();
      util_singleton("ReportingDateAccount",id,ptr);
   }
	return ptr;
}

ReportingDateAccount* ReportingDateAccount::instance_fscan(string fname)	{
   return ReportingDateAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

ReportingDateAccount* ReportingDateAccount::__ptr_ReportingDateAccount = ReportingDateAccount::instance();

/** Algorithm:
 * 1. Use the max of all reporting dates; if any reporting date is missing
 * set xval = 1*/
double ReportingDateAccount::agg_guts(vector<ObjectDb*>* odbv, UtilDate* dh, int& xval) {
   double x, xx;
   int n;

   xval = 0; x = -1;
   n = odbv->size();
   for(int i=0;i<n && (xval==0);i++) {
      xx = odbv->at(i)->ddba(NULL, NULL, dh, this, xval);
      if(xval==0 && xx>x) x = xx;
   }

   return x;
}

void ReportingDateAccount::agg(ObjectDb* odb, vector<ObjectDb*>* odbv, UtilDate* dh, int& xval) {
   UtilDate* d = odb->end_d();
   DateAccount::agg(odb, odbv, dh, xval);
   if(xval==0 && odb->end_d()!=d) myerr_msg("agg function failed",__FUNCTION__);
   return;
}

#endif

