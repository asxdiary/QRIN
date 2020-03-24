// Name:     DbGen.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DbGen_cpp
#define ASX_DbGen_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "CsvModelGen.hpp"
#include "Db.hpp"
#include "ObjectUniverse.hpp"
#include "DbGen.hpp"
#include "StartDateAccount.hpp"
#include "EndDateAccount.hpp"
#include "AvailabilityDateAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbUtils;
using namespace aiMath;
using namespace aiDb;

/** --------------Constructors and init_NULL-----------*/

DbGen::DbGen() { init_NULL(); }
DbGen::DbGen(const DbGen* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
DbGen::DbGen(const DbGen& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void DbGen::init_NULL()	{
	_univ=NULL;
}

/** ---Public Data Setting Functions-----------------*/

void DbGen::set_lookahead(int _obj) {
	_lookahead=_obj;
}

/** --------   Init Functions -------------------------*/

void DbGen::init(ObjectUniverse* univ) {
   CsvModelGen::init();
	init_DbGen(univ);
}

void DbGen::init_DbGen(ObjectUniverse* univ) {
	init_univ(univ);
   init_lookahead();
}

void DbGen::init_univ(ObjectUniverse* univ) {
   _univ = univ;
}

void DbGen::init_lookahead() {set_lookahead(0);}

/** -----Destructors and Memory Cleanup functions -----*/

DbGen::~DbGen()	{ cleanMem(); }

void DbGen::cleanMem()	{
	cleanMem_DbGen();
	CsvModelGen::cleanMem();
}

void DbGen::cleanMem_DbGen() {
	cleanMem_univ();
}

void DbGen::cleanMem_univ() {
	_univ=NULL;
}

/** ------------- Data Access Functions --------------------*/

ObjectUniverse* DbGen::univ() {return _univ;}
Db* DbGen::mdl() {return (Db*) ModelGen::mdl();}
int DbGen::lookahead() {return _lookahead;}

/** ------------- Access classname dynamically --------------------*/

string DbGen::className() const {return "DbGen";}

/** ------------- Error Message Handling Functions ------------------*/

void DbGen::myerr_msg(string msg, string func) {
	err_msg("DbGen::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void DbGen::fprint(string fname) {
	CsvModelGen::fprint(fname);
	fprint_DbGen(fname);
}

void DbGen::fprint_DbGen(string fname) {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
}

void DbGen::fscan(string fname) {
	CsvModelGen::fscan(fname);
	fscan_DbGen(fname);
}

void DbGen::fscan_DbGen(string fname) {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
}

/** ------------- Reset Functions --------------------*/

void DbGen::reset() {
	reset_DbGen();
	CsvModelGen::reset();
}

void DbGen::reset_DbGen() {
}

/** ----------  static instance function -----------*/


DbGen* DbGen::instance(ObjectUniverse* univ)	{
	DbGen* ptr=new DbGen();
	ptr->init(univ);
	return ptr;
}


DbGen* DbGen::instance_fscan(string fname)	{
	DbGen* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new DbGen();
		ptr->init_NULL();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

Db* DbGen::extract_mdl() {return (Db*) ModelGen::extract_mdl();}

void DbGen::configure(string src, Db* db) {
   CsvModelGen::configure(src, db);
   return;
}

void DbGen::algo_exec_guts(unordered_map<string,int>* header, string* row) {
   unordered_map<string,int>::iterator it;
   string key, val;
   int i;
   ObjectDb* ptr = NULL;
   DbAccount* dba = NULL;
   set<string> S;
   int xval;

   //create ptr
   {
      Object* dbobj = NULL;
      UtilDate* end_d = NULL;
      UtilDate* dh = NULL;
      UtilDate* start_d = NULL;
      int icode;

      key = "ObjectDb.dbobj";
      val = _get_val(header, row, key, xval); S.insert(key);
      dbobj = _univ->obj(val,true);

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

   //initialize the accounts; this is required just once to 
   //ensure that the singleton objects are initialized
   //TemplatePositionAccount::instance();

   for(it=header->begin();it!=header->end();it++) {
      i = it->second;
      key = it->first;
      val = row[i];

      if(S.find(key)!=S.end()) continue;
      dba = (DbAccount*) util_singleton(key, key);
      if(dba==NULL) continue;
      dba->populate(ptr, val, xval);
   }

   mdl()->add_odb(ptr);

   return;
}

Model* DbGen::gen_mdl() {return Db::instance();}

UtilDate* DbGen::lookahead(UtilDate* d) {
   if(lookahead()==0) return d;
   return d->prev_eom(lookahead());
}

#endif

