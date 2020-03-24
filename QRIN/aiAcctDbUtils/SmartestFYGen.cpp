// Name:     SmartestFYGen.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_SmartestFYGen_cpp
#define ASX_SmartestFYGen_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DbGen.hpp"
#include "AcctDb.hpp"
#include "CompanyUniverse.hpp"
#include "SmartestFYGen.hpp"
#include "FS.hpp"
#include "AcctFieldsUtils.hpp"
#include "AvailabilityDateAccount.hpp"
#include "EndDateAccount.hpp"
#include "OperatingRevenueAccount.hpp"
#include "CostRevenueAccount.hpp"
#include "GrossMarginAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctDbUtils;
using namespace aiDbUtils;
using namespace aiDb;
using namespace aiFin;
using namespace aiAcctDb;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

SmartestFYGen::SmartestFYGen() { init_NULL(); }
SmartestFYGen::SmartestFYGen(const SmartestFYGen* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
SmartestFYGen::SmartestFYGen(const SmartestFYGen& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void SmartestFYGen::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

void SmartestFYGen::set_df(string _obj) {
	_df=_obj;
}

/** --------   Init Functions -------------------------*/

void SmartestFYGen::init(CompanyUniverse* univ) {
   DbGen::init(univ);
	init_SmartestFYGen();
}

void SmartestFYGen::init_SmartestFYGen() {
	init_df();
}

void SmartestFYGen::init_df() {
   set_df("yyyymmdd");
}

/** -----Destructors and Memory Cleanup functions -----*/

SmartestFYGen::~SmartestFYGen()	{ cleanMem(); }

void SmartestFYGen::cleanMem()	{
	cleanMem_SmartestFYGen();
	DbGen::cleanMem();
}

void SmartestFYGen::cleanMem_SmartestFYGen() {
}

/** ------------- Data Access Functions --------------------*/

CompanyUniverse* SmartestFYGen::univ() {return (CompanyUniverse*) DbGen::univ();}
AcctDb* SmartestFYGen::mdl() {return (AcctDb*) DbGen::mdl();}
string SmartestFYGen::df() {return _df;}

/** ------------- Access classname dynamically --------------------*/

string SmartestFYGen::className() const {return "SmartestFYGen";}

/** ------------- Error Message Handling Functions ------------------*/

void SmartestFYGen::myerr_msg(string msg, string func) {
	err_msg("SmartestFYGen::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void SmartestFYGen::fprint(string fname) {
	DbGen::fprint(fname);
	fprint_SmartestFYGen(fname);
}

void SmartestFYGen::fprint_SmartestFYGen(string fname) {
}

void SmartestFYGen::fscan(string fname) {
	DbGen::fscan(fname);
	fscan_SmartestFYGen(fname);
}

void SmartestFYGen::fscan_SmartestFYGen(string fname) {
}

/** ------------- Reset Functions --------------------*/

void SmartestFYGen::reset() {
	reset_SmartestFYGen();
	DbGen::reset();
}

void SmartestFYGen::reset_SmartestFYGen() {
}

/** ----------  static instance function -----------*/


SmartestFYGen* SmartestFYGen::instance(CompanyUniverse* univ)	{
	SmartestFYGen* ptr=new SmartestFYGen();
	ptr->init(univ);
	return ptr;
}


SmartestFYGen* SmartestFYGen::instance_fscan(string fname)	{
	SmartestFYGen* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new SmartestFYGen();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

Model* SmartestFYGen::gen_mdl() {return AcctDb::instance();}

void SmartestFYGen::algo_exec_guts(unordered_map<string,int>* header, string* row) {
   CompanyUniverse* univ = this->univ();
   AcctDb* acdb = this->mdl();
   FS* fs = NULL;
   unordered_map<string,int>::iterator it;
   string key, val;
   int xval;

   //upload only FY data
   {
      key = "PeriodName";
      val = _get_val(header,row,key,xval,0);
      if(xval!=0) return;
      if(val.substr(0,2).compare("FY")!=0) return;
   }

   //create fs
   {
      Company* cmp = NULL;
      UtilDate* dh = NULL;
      UtilDate* start_d = NULL;
      UtilDate* end_d = NULL;
      DoubleDbAccount* dba = NULL;
      string df = this->df();

      key = univ->cid()->id();
      val = _get_val(header,row,key,xval,0);
      cmp = univ->obj(val,true);
      if(cmp==NULL) return;

      //create end_d and start_d
      {
         dba = EndDateAccount::instance();
         key = "PeriodEndDate";
         val = _get_val(header,row,key,xval,0);
         if(xval>0 || dba->isEmpty(val)) return;

         end_d = UtilDate::format(val,df);
         start_d = UtilDate::prev_eom(end_d, 12);
         dba = NULL;
      }

      {
         dba = AvailabilityDateAccount::instance();
         key = "DataDate";
         val = _get_val(header,row,key,xval,0);
         if(xval>0 || dba->isEmpty(val)) return;

         dh = UtilDate::format(val,df);
         dh = this->lookahead(dh);
         dba = NULL;
      }

      fs = FS::instance(cmp, end_d, dh, start_d);
   }

   {
      unordered_map<string,DbAccount*> dbam = acctfieldsutils_smartest_fields();
      unordered_map<string,DbAccount*>::iterator it;

      for(it=dbam.begin();it!=dbam.end();it++) {
         key = it->first;
         val = _get_val(header,row,key,xval,2);
         if(xval!=0) continue;
         it->second->populate(fs, val,xval);
      }

   }

   /** Build cost-revenue
    * Algorithm:
    * 1. derive GM from SmartEst_GM
    * 2. derive revenue
    * 3. cost revenue = (1-GM) * REV */
   for(int _i=0;_i<1;_i++) {
      DoubleDbAccount* dba = NULL;
      double gm, rev, crev;

      dba = GrossMarginAccount::instance();
      key = "SmartEst_GM";
      val = _get_val(header,row,key,xval,2);
      if(xval!=0) continue;
      if(dba->isEmpty(val)) continue;
      gm = atof(val.c_str())/100.0;

      dba = OperatingRevenueAccount::instance();
      rev = fs->ddba(NULL, NULL, fs->dh(), dba, xval);
      if(xval!=0) continue;

      dba = CostRevenueAccount::instance();
      crev = (1-gm) * rev;
      fs->add_ddba(dba, crev);
   }

   acdb->add_odb(fs);

   return;
}

AcctDb* SmartestFYGen::extract_mdl() {return (AcctDb*) DbGen::extract_mdl();}

#endif

