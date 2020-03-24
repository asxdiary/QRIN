// Name:     DomicileDbGen.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DomicileDbGen_cpp
#define ASX_DomicileDbGen_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DbGen.hpp"
#include "Db.hpp"
#include "CompanyUniverse.hpp"
#include "DomicileDbGen.hpp"
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

DomicileDbGen::DomicileDbGen() { init_NULL(); }
DomicileDbGen::DomicileDbGen(const DomicileDbGen* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
DomicileDbGen::DomicileDbGen(const DomicileDbGen& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void DomicileDbGen::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void DomicileDbGen::init(CompanyUniverse* univ) {
   DbGen::init(univ);
	init_DomicileDbGen();
}

void DomicileDbGen::init_DomicileDbGen() {
}

/** -----Destructors and Memory Cleanup functions -----*/

DomicileDbGen::~DomicileDbGen()	{ cleanMem(); }

void DomicileDbGen::cleanMem()	{
	cleanMem_DomicileDbGen();
	DbGen::cleanMem();
}

void DomicileDbGen::cleanMem_DomicileDbGen() {
}

/** ------------- Data Access Functions --------------------*/

CompanyUniverse* DomicileDbGen::univ() {return (CompanyUniverse*) DbGen::univ();}
Db* DomicileDbGen::mdl() {return (Db*) DbGen::mdl();}

/** ------------- Access classname dynamically --------------------*/

string DomicileDbGen::className() const {return "DomicileDbGen";}

/** ------------- Error Message Handling Functions ------------------*/

void DomicileDbGen::myerr_msg(string msg, string func) {
	err_msg("DomicileDbGen::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void DomicileDbGen::fprint(string fname) {
	DbGen::fprint(fname);
	fprint_DomicileDbGen(fname);
}

void DomicileDbGen::fprint_DomicileDbGen(string fname) {
}

void DomicileDbGen::fscan(string fname) {
	DbGen::fscan(fname);
	fscan_DomicileDbGen(fname);
}

void DomicileDbGen::fscan_DomicileDbGen(string fname) {
}

/** ------------- Reset Functions --------------------*/

void DomicileDbGen::reset() {
	reset_DomicileDbGen();
	DbGen::reset();
}

void DomicileDbGen::reset_DomicileDbGen() {
}

/** ----------  static instance function -----------*/


DomicileDbGen* DomicileDbGen::instance(CompanyUniverse* univ)	{
	DomicileDbGen* ptr=new DomicileDbGen();
	ptr->init(univ);
	return ptr;
}


DomicileDbGen* DomicileDbGen::instance_fscan(string fname)	{
	DomicileDbGen* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new DomicileDbGen();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

Model* DomicileDbGen::gen_mdl() {return Db::instance();}

void DomicileDbGen::algo_exec_guts(unordered_map<string,int>* header, string* row) {
   CompanyUniverse* univ = this->univ();
   Company* cmp = NULL;
   Db* acdb = this->mdl();
   string key, val, country;
   UtilDate* d1 = NULL;
   UtilDate* d2 = NULL;
   UtilDate* d = NULL;
   int xval;

   {
      key = univ->cid()->id();
      val = _get_val(header,row,key, xval,0);
      cmp = univ->obj(val,true);
      if(cmp==NULL) return;
   }

   //extract d1 and d2
   {
      string df = "yyyy-mm-dd";

      key = "effdate";
      val = _get_val(header,row,key, xval,0);
      if(xval!=0) return;
      d1 = UtilDate::format(val, df)->eom();

      key = "thrudate";
      val = _get_val(header,row,key, xval,0);
      if(xval!=0) return;
      d2 = UtilDate::format(val, df)->eom();

      key = "country";
      val = _get_val(header,row,key, xval,0);
      if(xval!=0) return;
      country = val;
   }

   for(d=d1;d->isBefore(d2);d=d->next_eom()) {
      StringDbAccount* dba = NULL;
      UtilDate* start_d = NULL;
      UtilDate* end_d = NULL;
      UtilDate* dh = NULL;
      ObjectDb* fs = NULL;

      start_d = d;
      end_d = d->next_eom();
      dh = d;

      fs = ObjectDb::instance(cmp, end_d, dh, start_d);

      dba = DomicileAccount::instance();
      fs->add_sdba(dba, country);
   
      acdb->add_odb(fs);
   }

   return;
}

Db* DomicileDbGen::extract_mdl() {return (Db*) DbGen::extract_mdl();}

#endif

