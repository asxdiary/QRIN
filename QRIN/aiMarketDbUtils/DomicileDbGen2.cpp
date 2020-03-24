// Name:     DomicileDbGen2.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DomicileDbGen2_cpp
#define ASX_DomicileDbGen2_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DbGen.hpp"
#include "Db.hpp"
#include "CompanyUniverse.hpp"
#include "DomicileDbGen2.hpp"
#include "ObjectDb.hpp"
#include "AcctFieldsUtils.hpp"
#include "EndDateAccount.hpp"
#include "AvailabilityDateAccount.hpp"
#include "DomicileAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMarketDbUtils;
using namespace aiDbUtils;
using namespace aiDb;
using namespace aiFin;

/** --------------Constructors and init_NULL-----------*/

DomicileDbGen2::DomicileDbGen2() { init_NULL(); }
DomicileDbGen2::DomicileDbGen2(const DomicileDbGen2* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
DomicileDbGen2::DomicileDbGen2(const DomicileDbGen2& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void DomicileDbGen2::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void DomicileDbGen2::init(CompanyUniverse* univ) {
   DbGen::init(univ);
	init_DomicileDbGen2();
}

void DomicileDbGen2::init_DomicileDbGen2() {
}

/** -----Destructors and Memory Cleanup functions -----*/

DomicileDbGen2::~DomicileDbGen2()	{ cleanMem(); }

void DomicileDbGen2::cleanMem()	{
	cleanMem_DomicileDbGen2();
	DbGen::cleanMem();
}

void DomicileDbGen2::cleanMem_DomicileDbGen2() {
}

/** ------------- Data Access Functions --------------------*/

CompanyUniverse* DomicileDbGen2::univ() {return (CompanyUniverse*) DbGen::univ();}
Db* DomicileDbGen2::mdl() {return (Db*) DbGen::mdl();}

/** ------------- Access classname dynamically --------------------*/

string DomicileDbGen2::className() const {return "DomicileDbGen2";}

/** ------------- Error Message Handling Functions ------------------*/

void DomicileDbGen2::myerr_msg(string msg, string func) {
	err_msg("DomicileDbGen2::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void DomicileDbGen2::fprint(string fname) {
	DbGen::fprint(fname);
	fprint_DomicileDbGen2(fname);
}

void DomicileDbGen2::fprint_DomicileDbGen2(string fname) {
}

void DomicileDbGen2::fscan(string fname) {
	DbGen::fscan(fname);
	fscan_DomicileDbGen2(fname);
}

void DomicileDbGen2::fscan_DomicileDbGen2(string fname) {
}

/** ------------- Reset Functions --------------------*/

void DomicileDbGen2::reset() {
	reset_DomicileDbGen2();
	DbGen::reset();
}

void DomicileDbGen2::reset_DomicileDbGen2() {
}

/** ----------  static instance function -----------*/


DomicileDbGen2* DomicileDbGen2::instance(CompanyUniverse* univ)	{
	DomicileDbGen2* ptr=new DomicileDbGen2();
	ptr->init(univ);
	return ptr;
}


DomicileDbGen2* DomicileDbGen2::instance_fscan(string fname)	{
	DomicileDbGen2* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new DomicileDbGen2();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

Model* DomicileDbGen2::gen_mdl() {return Db::instance();}

void DomicileDbGen2::algo_exec_guts(unordered_map<string,int>* header, string* row) {
   CompanyUniverse* univ = this->univ();
   Company* cmp = NULL;
   UtilDate* d = NULL;
   Db* acdb = this->mdl();
   string key, val, country;
   int xval;

   {
      key = univ->cid()->id();
      val = _get_val(header,row,key, xval,0);
      cmp = univ->obj(val,true);
      if(cmp==NULL) return;
   }

   {
      string df = "yyyymmdd";

      key = "Date";
      val = _get_val(header,row,key, xval,0);
      if(xval!=0) return;
      d = UtilDate::format(val, df)->eom();

      key = "loc";
      val = _get_val(header,row,key, xval,0);
      if(xval!=0) return;
      country = val;

      {
         StringDbAccount* dba = NULL;
         UtilDate* start_d = NULL;
         UtilDate* end_d = NULL;
         UtilDate* dh = NULL;
         ObjectDb* fs = NULL;

         start_d = d->prev_eom();
         end_d = d;
         dh = d;

         fs = ObjectDb::instance(cmp, end_d, dh, start_d);

         dba = DomicileAccount::instance();
         fs->add_sdba(dba, country);

         acdb->add_odb(fs);
      }
   }

   return;
}

Db* DomicileDbGen2::extract_mdl() {return (Db*) DbGen::extract_mdl();}

#endif

