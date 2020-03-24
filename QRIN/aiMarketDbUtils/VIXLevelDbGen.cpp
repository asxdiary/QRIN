// Name:     VIXLevelDbGen.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_VIXLevelDbGen_cpp
#define ASX_VIXLevelDbGen_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DbGen.hpp"
#include "Db.hpp"
#include "ObjectDb.hpp"
#include "UtilDate.hpp"
#include "VIXLevelDbGen.hpp"
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

VIXLevelDbGen::VIXLevelDbGen() { init_NULL(); }
VIXLevelDbGen::VIXLevelDbGen(const VIXLevelDbGen* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
VIXLevelDbGen::VIXLevelDbGen(const VIXLevelDbGen& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void VIXLevelDbGen::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void VIXLevelDbGen::init(CompanyUniverse* univ) {
   DbGen::init(univ);
	init_VIXLevelDbGen();
}

void VIXLevelDbGen::init_VIXLevelDbGen() {
}

/** -----Destructors and Memory Cleanup functions -----*/

VIXLevelDbGen::~VIXLevelDbGen()	{ cleanMem(); }

void VIXLevelDbGen::cleanMem()	{
	cleanMem_VIXLevelDbGen();
	DbGen::cleanMem();
}

void VIXLevelDbGen::cleanMem_VIXLevelDbGen() {
}

/** ------------- Data Access Functions --------------------*/

CompanyUniverse* VIXLevelDbGen::univ() {return (CompanyUniverse*) DbGen::univ();}

/** ------------- Access classname dynamically --------------------*/

string VIXLevelDbGen::className() const {return "VIXLevelDbGen";}

/** ------------- Error Message Handling Functions ------------------*/

void VIXLevelDbGen::myerr_msg(string msg, string func) {
	err_msg("VIXLevelDbGen::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void VIXLevelDbGen::fprint(string fname) {
	DbGen::fprint(fname);
	fprint_VIXLevelDbGen(fname);
}

void VIXLevelDbGen::fprint_VIXLevelDbGen(string fname) {
}

void VIXLevelDbGen::fscan(string fname) {
	DbGen::fscan(fname);
	fscan_VIXLevelDbGen(fname);
}

void VIXLevelDbGen::fscan_VIXLevelDbGen(string fname) {
}

/** ------------- Reset Functions --------------------*/

void VIXLevelDbGen::reset() {
	reset_VIXLevelDbGen();
	DbGen::reset();
}

void VIXLevelDbGen::reset_VIXLevelDbGen() {
}

/** ----------  static instance function -----------*/


VIXLevelDbGen* VIXLevelDbGen::instance(CompanyUniverse* univ)	{
	VIXLevelDbGen* ptr=new VIXLevelDbGen();
	ptr->init(univ);
	return ptr;
}


VIXLevelDbGen* VIXLevelDbGen::instance_fscan(string fname)	{
	VIXLevelDbGen* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new VIXLevelDbGen();
		ptr->init_NULL();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

void VIXLevelDbGen::algo_exec_guts(unordered_map<string,int>* header, string* row) {
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

      start_d = end_d->prev_d();
      dh = end_d;

      odb = ObjectDb::instance(cmp, end_d, dh, start_d);
   }

   {
      unordered_map<string,DbAccount*> dbam = marketfieldsutils_vixdb_fields();
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

