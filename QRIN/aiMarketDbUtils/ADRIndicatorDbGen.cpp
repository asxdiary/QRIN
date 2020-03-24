// Name:     ADRIndicatorDbGen.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ADRIndicatorDbGen_cpp
#define ASX_ADRIndicatorDbGen_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DbGen.hpp"
#include "Db.hpp"
#include "CompanyUniverse.hpp"
#include "ADRIndicatorDbGen.hpp"
#include "ObjectDb.hpp"
#include "AcctFieldsUtils.hpp"
#include "EndDateAccount.hpp"
#include "AvailabilityDateAccount.hpp"
#include "ADRIndicatorAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMarketDbUtils;
using namespace aiMarketFields;
using namespace aiDbUtils;
using namespace aiDb;
using namespace aiFin;

/** --------------Constructors and init_NULL-----------*/

ADRIndicatorDbGen::ADRIndicatorDbGen() { init_NULL(); }
ADRIndicatorDbGen::ADRIndicatorDbGen(const ADRIndicatorDbGen* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
ADRIndicatorDbGen::ADRIndicatorDbGen(const ADRIndicatorDbGen& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void ADRIndicatorDbGen::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void ADRIndicatorDbGen::init(CompanyUniverse* univ) {
   DbGen::init(univ);
	init_ADRIndicatorDbGen();
}

void ADRIndicatorDbGen::init_ADRIndicatorDbGen() {
}

/** -----Destructors and Memory Cleanup functions -----*/

ADRIndicatorDbGen::~ADRIndicatorDbGen()	{ cleanMem(); }

void ADRIndicatorDbGen::cleanMem()	{
	cleanMem_ADRIndicatorDbGen();
	DbGen::cleanMem();
}

void ADRIndicatorDbGen::cleanMem_ADRIndicatorDbGen() {
}

/** ------------- Data Access Functions --------------------*/

CompanyUniverse* ADRIndicatorDbGen::univ() {return (CompanyUniverse*) DbGen::univ();}
Db* ADRIndicatorDbGen::mdl() {return (Db*) DbGen::mdl();}

/** ------------- Access classname dynamically --------------------*/

string ADRIndicatorDbGen::className() const {return "ADRIndicatorDbGen";}

/** ------------- Error Message Handling Functions ------------------*/

void ADRIndicatorDbGen::myerr_msg(string msg, string func) {
	err_msg("ADRIndicatorDbGen::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void ADRIndicatorDbGen::fprint(string fname) {
	DbGen::fprint(fname);
	fprint_ADRIndicatorDbGen(fname);
}

void ADRIndicatorDbGen::fprint_ADRIndicatorDbGen(string fname) {
}

void ADRIndicatorDbGen::fscan(string fname) {
	DbGen::fscan(fname);
	fscan_ADRIndicatorDbGen(fname);
}

void ADRIndicatorDbGen::fscan_ADRIndicatorDbGen(string fname) {
}

/** ------------- Reset Functions --------------------*/

void ADRIndicatorDbGen::reset() {
	reset_ADRIndicatorDbGen();
	DbGen::reset();
}

void ADRIndicatorDbGen::reset_ADRIndicatorDbGen() {
}

/** ----------  static instance function -----------*/


ADRIndicatorDbGen* ADRIndicatorDbGen::instance(CompanyUniverse* univ)	{
	ADRIndicatorDbGen* ptr=new ADRIndicatorDbGen();
	ptr->init(univ);
	return ptr;
}


ADRIndicatorDbGen* ADRIndicatorDbGen::instance_fscan(string fname)	{
	ADRIndicatorDbGen* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new ADRIndicatorDbGen();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

Model* ADRIndicatorDbGen::gen_mdl() {return Db::instance();}

void ADRIndicatorDbGen::algo_exec_guts(unordered_map<string,int>* header, string* row) {
   CompanyUniverse* univ = this->univ();
   Company* cmp = NULL;
   UtilDate* d = NULL;
   Db* acdb = this->mdl();
   string key, val, adr_str;
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

      key = "adr";
      val = _get_val(header,row,key, xval,0);
      if(xval!=0) return;
      adr_str = val;

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

         dba = ADRIndicatorAccount::instance();
         fs->add_sdba(dba, adr_str);

         acdb->add_odb(fs);
      }
   }

   return;
}

Db* ADRIndicatorDbGen::extract_mdl() {return (Db*) DbGen::extract_mdl();}

#endif

