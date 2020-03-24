// Name:     GenericDbGen.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_GenericDbGen_cpp
#define ASX_GenericDbGen_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DbGen.hpp"
#include "Db.hpp"
#include "ObjectUniverse.hpp"
#include "GenericDbGen.hpp"
#include "FS.hpp"
#include "ReportingDateAccount.hpp"
#include "StartDateAccount.hpp"
#include "EndDateAccount.hpp"
#include "AvailabilityDateAccount.hpp"
#include "GenericDoubleDbAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbUtils;
using namespace aiDbUtils;
using namespace aiDb;

/** --------------Constructors and init_NULL-----------*/

GenericDbGen::GenericDbGen() { init_NULL(); }
GenericDbGen::GenericDbGen(const GenericDbGen* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
GenericDbGen::GenericDbGen(const GenericDbGen& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void GenericDbGen::init_NULL()	{
	_ddba_idS=NULL;
}

/** ---Public Data Setting Functions-----------------*/

void GenericDbGen::add_ddba_idS(string _obj) {
   if(_ddba_idS==NULL) myerr_msg("_ddba_idS==NULL",__FUNCTION__);
   _ddba_idS->insert(_obj);
}

/** --------   Init Functions -------------------------*/

void GenericDbGen::init(ObjectUniverse* univ, string oid) {
   DbGen::init(univ);
	init_GenericDbGen(oid);
}

void GenericDbGen::init_GenericDbGen(string oid) {
	init_oid(oid);
	init_ddba_idS();
}

void GenericDbGen::init_oid(string oid) {_oid = oid;}

void GenericDbGen::init_ddba_idS() {
   _ddba_idS = new set<string>();
}

/** -----Destructors and Memory Cleanup functions -----*/

GenericDbGen::~GenericDbGen()	{ cleanMem(); }

void GenericDbGen::cleanMem()	{
	cleanMem_GenericDbGen();
	DbGen::cleanMem();
}

void GenericDbGen::cleanMem_GenericDbGen() {
	cleanMem_ddba_idS();
}

void GenericDbGen::cleanMem_ddba_idS() {
   delete _ddba_idS;
   _ddba_idS = NULL;
}

/** ------------- Data Access Functions --------------------*/

ObjectUniverse* GenericDbGen::univ() {return (ObjectUniverse*) DbGen::univ();}
Db* GenericDbGen::mdl() {return (Db*) DbGen::mdl();}
string GenericDbGen::oid() {return _oid;}
set<string>* GenericDbGen::ddba_idS() {return _ddba_idS;}

/** ------------- Access classname dynamically --------------------*/

string GenericDbGen::className() const {return "GenericDbGen";}

/** ------------- Error Message Handling Functions ------------------*/

void GenericDbGen::myerr_msg(string msg, string func) {
	err_msg("GenericDbGen::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void GenericDbGen::fprint(string fname) {
	DbGen::fprint(fname);
	fprint_GenericDbGen(fname);
}

void GenericDbGen::fprint_GenericDbGen(string fname) {
}

void GenericDbGen::fscan(string fname) {
	DbGen::fscan(fname);
	fscan_GenericDbGen(fname);
}

void GenericDbGen::fscan_GenericDbGen(string fname) {
}

/** ------------- Reset Functions --------------------*/

void GenericDbGen::reset() {
	reset_GenericDbGen();
	DbGen::reset();
}

void GenericDbGen::reset_GenericDbGen() {
}

/** ----------  static instance function -----------*/


GenericDbGen* GenericDbGen::instance(ObjectUniverse* univ, string oid)	{
	GenericDbGen* ptr=new GenericDbGen();
	ptr->init(univ, oid);
	return ptr;
}


GenericDbGen* GenericDbGen::instance_fscan(string fname)	{
	GenericDbGen* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new GenericDbGen();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

void GenericDbGen::algo_exec_guts(unordered_map<string,int>* header, string* row) {
   unordered_map<string,int>::iterator it;
   string key, val;
   ObjectDb* ptr = NULL;
   set<string> S;
   int xval;

   //create ptr
   {
      Object* dbobj = NULL;
      UtilDate* end_d = NULL;
      UtilDate* dh = NULL;
      UtilDate* start_d = NULL;
      int icode;

      key = this->oid();
      val = _get_val(header, row, key, xval); S.insert(key);
      dbobj = univ()->obj(val,true);
      if(dbobj==NULL) return;

      key = EndDateAccount::instance()->id();
      val = _get_val(header, row, key, xval); S.insert(key);
      util_convert(val, icode);
      end_d = UtilDate::instance(icode);

      key = AvailabilityDateAccount::instance()->id();
      val = _get_val(header, row, key, xval); S.insert(key);
      util_convert(val, icode);
      dh = UtilDate::instance(icode);
      dh = this->lookahead(dh);

      key = StartDateAccount::instance()->id();
      val = _get_val(header, row, key, xval); S.insert(key);
      util_convert(val, icode);
      start_d = UtilDate::instance(icode);

      ptr = ObjectDb::instance(dbobj, end_d, dh, start_d);
   }

   //add other fields
   {
      set<string>* ddba_idS = this->ddba_idS();
      set<string>::iterator it;
      GenericDoubleDbAccount* dba = NULL;

      for(it=ddba_idS->begin();it!=ddba_idS->end();it++) {
         key = *it; xval = 0;
         val = _get_val(header, row, key, xval);
         dba = GenericDoubleDbAccount::instance(key);
         dba->populate(ptr, val, xval);
      }
   }

   mdl()->add_odb(ptr);

   return;
}

#endif

