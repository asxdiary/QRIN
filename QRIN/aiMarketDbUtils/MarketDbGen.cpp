// Name:     MarketDbGen.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_MarketDbGen_cpp
#define ASX_MarketDbGen_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DbGen.hpp"
#include "Db.hpp"
#include "ObjectDb.hpp"
#include "UtilDate.hpp"
#include "MarketDbGen.hpp"
#include "CompanyUniverse.hpp"
#include "MarketFieldsUtils.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMarketDbUtils;
using namespace aiDb;
using namespace aiDbUtils;
using namespace aiFin;
using namespace aiMarketFields;

/** --------------Constructors and init_NULL-----------*/

MarketDbGen::MarketDbGen() { init_NULL(); }
MarketDbGen::MarketDbGen(const MarketDbGen* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
MarketDbGen::MarketDbGen(const MarketDbGen& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void MarketDbGen::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void MarketDbGen::init(CompanyUniverse* univ) {
   DbGen::init(univ);
	init_MarketDbGen();
}

void MarketDbGen::init_MarketDbGen() {
}

/** -----Destructors and Memory Cleanup functions -----*/

MarketDbGen::~MarketDbGen()	{ cleanMem(); }

void MarketDbGen::cleanMem()	{
	cleanMem_MarketDbGen();
	DbGen::cleanMem();
}

void MarketDbGen::cleanMem_MarketDbGen() {
}

/** ------------- Data Access Functions --------------------*/

CompanyUniverse* MarketDbGen::univ() {return (CompanyUniverse*) DbGen::univ();}

/** ------------- Access classname dynamically --------------------*/

string MarketDbGen::className() const {return "MarketDbGen";}

/** ------------- Error Message Handling Functions ------------------*/

void MarketDbGen::myerr_msg(string msg, string func) {
	err_msg("MarketDbGen::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void MarketDbGen::fprint(string fname) {
	DbGen::fprint(fname);
	fprint_MarketDbGen(fname);
}

void MarketDbGen::fprint_MarketDbGen(string fname) {
}

void MarketDbGen::fscan(string fname) {
	DbGen::fscan(fname);
	fscan_MarketDbGen(fname);
}

void MarketDbGen::fscan_MarketDbGen(string fname) {
}

/** ------------- Reset Functions --------------------*/

void MarketDbGen::reset() {
	reset_MarketDbGen();
	DbGen::reset();
}

void MarketDbGen::reset_MarketDbGen() {
}

/** ----------  static instance function -----------*/


MarketDbGen* MarketDbGen::instance(CompanyUniverse* univ)	{
	MarketDbGen* ptr=new MarketDbGen();
	ptr->init(univ);
	return ptr;
}


MarketDbGen* MarketDbGen::instance_fscan(string fname)	{
	MarketDbGen* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new MarketDbGen();
		ptr->init_NULL();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

void MarketDbGen::algo_exec_guts(unordered_map<string,int>* header, string* row) {
   CompanyUniverse* univ = this->univ();
   Db* db = this->mdl();
   ObjectDb* odb = NULL;
   unordered_map<string,int>::iterator it;
   string key, val;
   int xval;

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
      end_d = UtilDate::format(val,df);
      end_d = UtilDate::eom(end_d);

      start_d = UtilDate::prev_eom(end_d, 12);
      dh = end_d;

      odb = ObjectDb::instance(cmp, end_d, dh, start_d);
   }

   {
      unordered_map<string,DbAccount*> dbam = marketfieldsutils_mmdb_fields();
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

