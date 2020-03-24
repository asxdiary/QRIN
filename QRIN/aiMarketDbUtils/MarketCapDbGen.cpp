// Name:     MarketCapDbGen.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_MarketCapDbGen_cpp
#define ASX_MarketCapDbGen_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DbGen.hpp"
#include "Db.hpp"
#include "ObjectDb.hpp"
#include "UtilDate.hpp"
#include "MarketCapDbGen.hpp"
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

MarketCapDbGen::MarketCapDbGen() { init_NULL(); }
MarketCapDbGen::MarketCapDbGen(const MarketCapDbGen* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
MarketCapDbGen::MarketCapDbGen(const MarketCapDbGen& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void MarketCapDbGen::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void MarketCapDbGen::init(CompanyUniverse* univ) {
   DbGen::init(univ);
	init_MarketCapDbGen();
}

void MarketCapDbGen::init_MarketCapDbGen() {
}

/** -----Destructors and Memory Cleanup functions -----*/

MarketCapDbGen::~MarketCapDbGen()	{ cleanMem(); }

void MarketCapDbGen::cleanMem()	{
	cleanMem_MarketCapDbGen();
	DbGen::cleanMem();
}

void MarketCapDbGen::cleanMem_MarketCapDbGen() {
}

/** ------------- Data Access Functions --------------------*/

CompanyUniverse* MarketCapDbGen::univ() {return (CompanyUniverse*) DbGen::univ();}

/** ------------- Access classname dynamically --------------------*/

string MarketCapDbGen::className() const {return "MarketCapDbGen";}

/** ------------- Error Message Handling Functions ------------------*/

void MarketCapDbGen::myerr_msg(string msg, string func) {
	err_msg("MarketCapDbGen::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void MarketCapDbGen::fprint(string fname) {
	DbGen::fprint(fname);
	fprint_MarketCapDbGen(fname);
}

void MarketCapDbGen::fprint_MarketCapDbGen(string fname) {
}

void MarketCapDbGen::fscan(string fname) {
	DbGen::fscan(fname);
	fscan_MarketCapDbGen(fname);
}

void MarketCapDbGen::fscan_MarketCapDbGen(string fname) {
}

/** ------------- Reset Functions --------------------*/

void MarketCapDbGen::reset() {
	reset_MarketCapDbGen();
	DbGen::reset();
}

void MarketCapDbGen::reset_MarketCapDbGen() {
}

/** ----------  static instance function -----------*/


MarketCapDbGen* MarketCapDbGen::instance(CompanyUniverse* univ)	{
	MarketCapDbGen* ptr=new MarketCapDbGen();
	ptr->init(univ);
	return ptr;
}


MarketCapDbGen* MarketCapDbGen::instance_fscan(string fname)	{
	MarketCapDbGen* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new MarketCapDbGen();
		ptr->init_NULL();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

void MarketCapDbGen::algo_exec_guts(unordered_map<string,int>* header, string* row) {
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
      if(xval>0) return;
      end_d = UtilDate::format(val,df);
      if(end_d==NULL) return;
      start_d = end_d;

      dh = end_d;

      odb = ObjectDb::instance(cmp, end_d, dh, start_d);
   }

   {
      unordered_map<string,DbAccount*> dbam = marketfieldsutils_mcapdb_fields();
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

