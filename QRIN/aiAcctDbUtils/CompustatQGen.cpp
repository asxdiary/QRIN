// Name:     CompustatQGen.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CompustatQGen_cpp
#define ASX_CompustatQGen_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DbGen.hpp"
#include "AcctDb.hpp"
#include "CompanyUniverse.hpp"
#include "CompustatQGen.hpp"
#include "FS.hpp"
#include "AcctFieldsUtils.hpp"
#include "ReportingDateAccount.hpp"
#include "EndDateAccount.hpp"
#include "AvailabilityDateAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctDbUtils;
using namespace aiDbUtils;
using namespace aiDb;
using namespace aiFin;
using namespace aiAcctDb;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

CompustatQGen::CompustatQGen() { init_NULL(); }
CompustatQGen::CompustatQGen(const CompustatQGen* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
CompustatQGen::CompustatQGen(const CompustatQGen& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void CompustatQGen::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void CompustatQGen::init(CompanyUniverse* univ) {
   DbGen::init(univ);
	init_CompustatQGen();
}

void CompustatQGen::init_CompustatQGen() {
}

/** -----Destructors and Memory Cleanup functions -----*/

CompustatQGen::~CompustatQGen()	{ cleanMem(); }

void CompustatQGen::cleanMem()	{
	cleanMem_CompustatQGen();
	DbGen::cleanMem();
}

void CompustatQGen::cleanMem_CompustatQGen() {
}

/** ------------- Data Access Functions --------------------*/

CompanyUniverse* CompustatQGen::univ() {return (CompanyUniverse*) DbGen::univ();}
AcctDb* CompustatQGen::mdl() {return (AcctDb*) DbGen::mdl();}

/** ------------- Access classname dynamically --------------------*/

string CompustatQGen::className() const {return "CompustatQGen";}

/** ------------- Error Message Handling Functions ------------------*/

void CompustatQGen::myerr_msg(string msg, string func) {
	err_msg("CompustatQGen::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void CompustatQGen::fprint(string fname) {
	DbGen::fprint(fname);
	fprint_CompustatQGen(fname);
}

void CompustatQGen::fprint_CompustatQGen(string fname) {
}

void CompustatQGen::fscan(string fname) {
	DbGen::fscan(fname);
	fscan_CompustatQGen(fname);
}

void CompustatQGen::fscan_CompustatQGen(string fname) {
}

/** ------------- Reset Functions --------------------*/

void CompustatQGen::reset() {
	reset_CompustatQGen();
	DbGen::reset();
}

void CompustatQGen::reset_CompustatQGen() {
}

/** ----------  static instance function -----------*/


CompustatQGen* CompustatQGen::instance(CompanyUniverse* univ)	{
	CompustatQGen* ptr=new CompustatQGen();
	ptr->init(univ);
	return ptr;
}


CompustatQGen* CompustatQGen::instance_fscan(string fname)	{
	CompustatQGen* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new CompustatQGen();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

Model* CompustatQGen::gen_mdl() {return AcctDb::instance();}

void CompustatQGen::algo_exec_guts(unordered_map<string,int>* header, string* row) {
   CompanyUniverse* univ = this->univ();
   AcctDb* acdb = this->mdl();
   FS* fs = NULL;
   unordered_map<string,int>::iterator it;
   string key, val;
   int xval;

   //create fs
   {
      Company* cmp = NULL;
      UtilDate* dh = NULL;
      UtilDate* start_d = NULL;
      UtilDate* end_d = NULL;
      DoubleDbAccount* dba = NULL;
      string df;

      key = univ->cid()->id();
      val = _get_val(header,row,key, xval,0);
      cmp = univ->obj(val,true);
      if(cmp==NULL) return;

      {
         dba = EndDateAccount::instance();
         df = "yyyymmdd";
         key = "statement_date";
         val = _get_val(header,row,key,xval,0);
         if(xval>0 || dba->isEmpty(val)) return;

         end_d = UtilDate::format(val,df);
         start_d = UtilDate::prev_eom(end_d, 3);
         dba = NULL;
      }

      {
         dba = AvailabilityDateAccount::instance();
         key = "effdate_final_max";
         val = _get_val(header,row,key,xval,0);
         if(xval>0 || dba->isEmpty(val)) return;

         dh = UtilDate::format(val,df);
         dh = this->lookahead(dh);
         dba = NULL;
      }

      fs = FS::instance(cmp, end_d, dh, start_d);

      {
         int icode = dh->icode();

         dba = ReportingDateAccount::instance();
         key = "filedate_final";
         val = _get_val(header,row,key,xval,3);
         if(xval==0 && ! dba->isEmpty(val)) icode = UtilDate::format(val,df)->icode();
         fs->add_ddba(dba, icode, xval);

         dba = NULL;
      }

   }

   {
      unordered_map<string,DbAccount*> dbam = acctfieldsutils_compustatQ_fields();
      unordered_map<string,DbAccount*>::iterator it;

      for(it=dbam.begin();it!=dbam.end();it++) {
         val = _get_val(header,row,it->first,xval);
         if(xval!=0) continue;
         it->second->populate(fs, val,xval);
      }

   }

   acdb->add_odb(fs);

   return;
}

AcctDb* CompustatQGen::extract_mdl() {return (AcctDb*) DbGen::extract_mdl();}

#endif

