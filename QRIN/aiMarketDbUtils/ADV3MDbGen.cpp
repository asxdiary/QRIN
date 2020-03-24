// Name:     ADV3MDbGen.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ADV3MDbGen_cpp
#define ASX_ADV3MDbGen_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DbGen.hpp"
#include "Db.hpp"
#include "ObjectDb.hpp"
#include "UtilDate.hpp"
#include "ADV3MDbGen.hpp"
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

ADV3MDbGen::ADV3MDbGen() { init_NULL(); }
ADV3MDbGen::ADV3MDbGen(const ADV3MDbGen* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
ADV3MDbGen::ADV3MDbGen(const ADV3MDbGen& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void ADV3MDbGen::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void ADV3MDbGen::init(CompanyUniverse* univ) {
   DbGen::init(univ);
	init_ADV3MDbGen();
}

void ADV3MDbGen::init_ADV3MDbGen() {
}

/** -----Destructors and Memory Cleanup functions -----*/

ADV3MDbGen::~ADV3MDbGen()	{ cleanMem(); }

void ADV3MDbGen::cleanMem()	{
	cleanMem_ADV3MDbGen();
	DbGen::cleanMem();
}

void ADV3MDbGen::cleanMem_ADV3MDbGen() {
}

/** ------------- Data Access Functions --------------------*/

CompanyUniverse* ADV3MDbGen::univ() {return (CompanyUniverse*) DbGen::univ();}

/** ------------- Access classname dynamically --------------------*/

string ADV3MDbGen::className() const {return "ADV3MDbGen";}

/** ------------- Error Message Handling Functions ------------------*/

void ADV3MDbGen::myerr_msg(string msg, string func) {
	err_msg("ADV3MDbGen::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void ADV3MDbGen::fprint(string fname) {
	DbGen::fprint(fname);
	fprint_ADV3MDbGen(fname);
}

void ADV3MDbGen::fprint_ADV3MDbGen(string fname) {
}

void ADV3MDbGen::fscan(string fname) {
	DbGen::fscan(fname);
	fscan_ADV3MDbGen(fname);
}

void ADV3MDbGen::fscan_ADV3MDbGen(string fname) {
}

/** ------------- Reset Functions --------------------*/

void ADV3MDbGen::reset() {
	reset_ADV3MDbGen();
	DbGen::reset();
}

void ADV3MDbGen::reset_ADV3MDbGen() {
}

/** ----------  static instance function -----------*/


ADV3MDbGen* ADV3MDbGen::instance(CompanyUniverse* univ)	{
	ADV3MDbGen* ptr=new ADV3MDbGen();
	ptr->init(univ);
	return ptr;
}


ADV3MDbGen* ADV3MDbGen::instance_fscan(string fname)	{
	ADV3MDbGen* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new ADV3MDbGen();
		ptr->init_NULL();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

void ADV3MDbGen::algo_exec_guts(unordered_map<string,int>* header, string* row) {
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
      start_d = end_d;

      dh = end_d;

      odb = ObjectDb::instance(cmp, end_d, dh, start_d);
   }

   {
      unordered_map<string,DbAccount*> dbam = marketfieldsutils_adv3mdb_fields();
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

