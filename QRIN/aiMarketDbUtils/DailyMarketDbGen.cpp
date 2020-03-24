// Name:     DailyMarketDbGen.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DailyMarketDbGen_cpp
#define ASX_DailyMarketDbGen_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DbGen.hpp"
#include "Db.hpp"
#include "ObjectDb.hpp"
#include "UtilDate.hpp"
#include "DailyMarketDbGen.hpp"
#include "CompanyUniverse.hpp"
#include "MarketFieldsUtils.hpp"
#include "MarketDbUtils.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMarketDbUtils;
using namespace aiDb;
using namespace aiDbUtils;
using namespace aiFin;
using namespace aiMarketFields;

/** --------------Constructors and init_NULL-----------*/

DailyMarketDbGen::DailyMarketDbGen() { init_NULL(); }
DailyMarketDbGen::DailyMarketDbGen(const DailyMarketDbGen* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
DailyMarketDbGen::DailyMarketDbGen(const DailyMarketDbGen& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void DailyMarketDbGen::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void DailyMarketDbGen::init(CompanyUniverse* univ) {
   DbGen::init(univ);
	init_DailyMarketDbGen();
}

void DailyMarketDbGen::init_DailyMarketDbGen() {
}

/** -----Destructors and Memory Cleanup functions -----*/

DailyMarketDbGen::~DailyMarketDbGen()	{ cleanMem(); }

void DailyMarketDbGen::cleanMem()	{
	cleanMem_DailyMarketDbGen();
	DbGen::cleanMem();
}

void DailyMarketDbGen::cleanMem_DailyMarketDbGen() {
}

/** ------------- Data Access Functions --------------------*/

CompanyUniverse* DailyMarketDbGen::univ() {return (CompanyUniverse*) DbGen::univ();}

/** ------------- Access classname dynamically --------------------*/

string DailyMarketDbGen::className() const {return "DailyMarketDbGen";}

/** ------------- Error Message Handling Functions ------------------*/

void DailyMarketDbGen::myerr_msg(string msg, string func) {
	err_msg("DailyMarketDbGen::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void DailyMarketDbGen::fprint(string fname) {
	DbGen::fprint(fname);
	fprint_DailyMarketDbGen(fname);
}

void DailyMarketDbGen::fprint_DailyMarketDbGen(string fname) {
}

void DailyMarketDbGen::fscan(string fname) {
	DbGen::fscan(fname);
	fscan_DailyMarketDbGen(fname);
}

void DailyMarketDbGen::fscan_DailyMarketDbGen(string fname) {
}

/** ------------- Reset Functions --------------------*/

void DailyMarketDbGen::reset() {
	reset_DailyMarketDbGen();
	DbGen::reset();
}

void DailyMarketDbGen::reset_DailyMarketDbGen() {
}

/** ----------  static instance function -----------*/


DailyMarketDbGen* DailyMarketDbGen::instance(CompanyUniverse* univ)	{
	DailyMarketDbGen* ptr=new DailyMarketDbGen();
	ptr->init(univ);
	return ptr;
}


DailyMarketDbGen* DailyMarketDbGen::instance_fscan(string fname)	{
	DailyMarketDbGen* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new DailyMarketDbGen();
		ptr->init_NULL();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

void DailyMarketDbGen::algo_exec_guts(unordered_map<string,int>* header, string* row) {
   CompanyUniverse* univ = this->univ();
   Db* db = this->mdl();
   ObjectDb* odb = NULL;
   unordered_map<string,int>::iterator it;
   string key, val;
   int xval;

   //exclude entries where the daily return is missing
   {
      key = "stock_ret_daily";
      val = _get_val(header,row,key, xval, 0);
      if(xval>0 || val.compare("")==0) return;
   }

   //create odb
   {
      Company* cmp = NULL;
      UtilDate* dh = NULL;
      UtilDate* start_d = NULL;
      UtilDate* end_d = NULL;
      string df;

      key = univ->cid()->id();
      val = _get_val(header,row,key, xval, 0);
      cmp = univ->obj(val,true);
      if(cmp==NULL) return;

      df = "yyyymmdd";
      key = "Date";
      val = _get_val(header,row,key,xval,0);
      if(xval>0) return;
      end_d = UtilDate::format(val,df);
      if(end_d==NULL) return;

      df = "yyyymmdd";
      key = "date_stock_ret_lag1";
      val = _get_val(header,row,key,xval,0);
      if(xval>0) return;
      start_d = UtilDate::format(val,df);
      if(start_d==NULL) return;

      dh = end_d;

      odb = ObjectDb::instance(cmp, end_d, dh, start_d);
   }

   {
      unordered_map<string,DbAccount*> dbam = marketfieldsutils_dmdb_fields();
      unordered_map<string,DbAccount*>::iterator it;

      for(it=dbam.begin();it!=dbam.end();it++) {
         val = _get_val(header,row,it->first,xval);
         if(xval!=0) continue;
         it->second->populate(odb, val,xval);
      }
   }

   db->add_odb(odb);

   return;
}



#endif

