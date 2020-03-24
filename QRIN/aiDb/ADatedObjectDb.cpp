// Name:     ADatedObjectDb.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ADatedObjectDb_cpp
#define ASX_ADatedObjectDb_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "UtilDate.hpp"
#include "Model.hpp"
#include "Dated.hpp"
#include "Summarizable.hpp"
#include "ObjectDb.hpp"
#include "ADatedObjectDb.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiDbAccounts;

/** --------------Constructors and init_NULL-----------*/

ADatedObjectDb::ADatedObjectDb() { init_NULL(); }
ADatedObjectDb::ADatedObjectDb(const ADatedObjectDb* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
ADatedObjectDb::ADatedObjectDb(const ADatedObjectDb& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void ADatedObjectDb::init_NULL()	{
	_dbobj=NULL;
	_end_d=NULL;
	_odbm=NULL;
	_dhS=NULL;
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void ADatedObjectDb::init(Object* dbobj, UtilDate* end_d) {
   Model::init();
   Dated::init(end_d);
   Summarizable::init();
	init_ADatedObjectDb(dbobj, end_d);
}

void ADatedObjectDb::init_ADatedObjectDb(Object* dbobj, UtilDate* end_d) {
	init_dbobj(dbobj);
	init_end_d(end_d);
	init_odbm();
	init_dhS();
}

void ADatedObjectDb::init_dbobj(Object* obj) {_dbobj = obj;}

void ADatedObjectDb::init_end_d(UtilDate* obj) {_end_d = obj;}

void ADatedObjectDb::init_odbm() {
   _odbm = new unordered_map<UtilDate*, ObjectDb*>();
}

void ADatedObjectDb::init_dhS() {
   _dhS = new set<int>();
}

/** -----Destructors and Memory Cleanup functions -----*/

ADatedObjectDb::~ADatedObjectDb()	{ cleanMem(); }

void ADatedObjectDb::cleanMem()	{
	cleanMem_ADatedObjectDb();
   Summarizable::cleanMem();
   Dated::cleanMem();
   Model::cleanMem();
}

void ADatedObjectDb::cleanMem_ADatedObjectDb() {
	cleanMem_dbobj();
	cleanMem_end_d();
	cleanMem_odbm();
	cleanMem_dhS();
}

void ADatedObjectDb::cleanMem_dbobj() {
	_dbobj=NULL;
}

void ADatedObjectDb::cleanMem_end_d() {
	_end_d=NULL;
}

void ADatedObjectDb::cleanMem_odbm() {
   if(_odbm!=NULL) {
      unordered_map<UtilDate*,ObjectDb*>::iterator it;
      for(it=_odbm->begin();it!=_odbm->end();it++) delete it->second;
      delete _odbm;
   }
	_odbm=NULL;
}

void ADatedObjectDb::cleanMem_dhS() {
   delete _dhS;
	_dhS=NULL;
}

/** ------------- Data Access Functions --------------------*/

Object* ADatedObjectDb::dbobj() {return _dbobj;}
UtilDate* ADatedObjectDb::end_d() {return _end_d;}
unordered_map<UtilDate*,ObjectDb*>* ADatedObjectDb::odbm() {return _odbm;}
set<int>* ADatedObjectDb::dhS() {return _dhS;}

/** ------------- Access classname dynamically --------------------*/

string ADatedObjectDb::className() const {return "ADatedObjectDb";}

/** ------------- Error Message Handling Functions ------------------*/

void ADatedObjectDb::myerr_msg(string msg, string func) {
	err_msg("ADatedObjectDb::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void ADatedObjectDb::fprint(string fname) {
   Model::fprint(fname);
   Dated::fprint(fname);
   Summarizable::fprint(fname);
	fprint_ADatedObjectDb(fname);
}

void ADatedObjectDb::fprint_ADatedObjectDb(string fname) {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
   /**
	util_ofprint_obj(fname,"dbobj",_dbobj);
	util_ofprint_obj(fname,"end_d",_end_d);
	util_ofprint_obj(fname,"odbm",_odbm);
	util_ofprint_obj(fname,"dhS",_dhS);
   */
}

void ADatedObjectDb::fscan(string fname) {
   Model::fscan(fname);
   Dated::fscan(fname);
   Summarizable::fscan(fname);
	fscan_ADatedObjectDb(fname);
}

void ADatedObjectDb::fscan_ADatedObjectDb(string fname) {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
	//Insert scanning function for end_d here
	//Insert scanning function for odbm here
}

/** ------------- Reset Functions --------------------*/

void ADatedObjectDb::reset() {
	reset_ADatedObjectDb();
   Model::reset();
   Dated::reset();
   Summarizable::reset();
}

void ADatedObjectDb::reset_ADatedObjectDb() {
}

/** ----------  static instance function -----------*/

ADatedObjectDb* ADatedObjectDb::instantiate(Object* dbobj, UtilDate* end_d)	{
   return ADatedObjectDb::instance(dbobj, end_d);
}

ADatedObjectDb* ADatedObjectDb::instance(Object* dbobj, UtilDate* end_d)	{
	ADatedObjectDb* ptr=new ADatedObjectDb();
	ptr->init(dbobj, end_d);
	return ptr;
}


ADatedObjectDb* ADatedObjectDb::instance_fscan(string fname)	{
	ADatedObjectDb* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new ADatedObjectDb();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

void ADatedObjectDb::add_odb(ObjectDb* odb) {
   UtilDate* dh = NULL;
   unordered_map<UtilDate*,ObjectDb*>::iterator it;

   if(odb==NULL) return;
   if(odb->dbobj()!=dbobj()) myerr_msg("dbobj mismatch",__FUNCTION__);
   if(odb->end_d()!=end_d()) myerr_msg("end_d mismatch",__FUNCTION__);

   dh = odb->dh();
   it = _odbm->find(dh);
   if(it!=_odbm->end()) delete it->second;
   (*_odbm)[dh] = odb;
   _dhS->insert(dh->icode());

   return;
}

UtilDate* ADatedObjectDb::dh(UtilDate* dh) {
   UtilDate* dret = NULL;
   UtilDate* tmp = NULL;
   unordered_map<UtilDate*,ObjectDb*>::iterator it;

   for(it=_odbm->begin();it!=_odbm->end();it++) {
      tmp = it->first;
      if(tmp->isAfter(dh)) continue;
      if(dret!=NULL && dret->isAfter(tmp)) continue;
      dret = tmp;
   }

   return dret;
}


double ADatedObjectDb::ddba(Object* dbobj, UtilDate* end_d, UtilDate* dh,
                            DoubleDbAccount* dba, int& xval)
{
   ObjectDb* odb = NULL;
   double x = 0;
   odb = this->odb(dbobj, end_d, dh, xval);
   if(xval>0) return x;
   x = odb->ddba(dbobj, end_d, dh, dba, xval);
   return x;
}

string ADatedObjectDb::sdba(Object* dbobj, UtilDate* end_d, UtilDate* dh,
                            StringDbAccount* dba, int& xval)
{
   ObjectDb* odb = NULL;
   string x = "";
   odb = this->odb(dbobj, end_d, dh, xval);
   if(xval>0) return x;
   x = odb->sdba(dbobj, end_d, dh, dba, xval);
   return x;
}

void ADatedObjectDb::summary(list<unordered_map<string,string>*>*& L, set<string>* headerS) {
   Summarizable::summary(L, headerS);
   unordered_map<UtilDate*,ObjectDb*>::iterator it;
   for(it=_odbm->begin();it!=_odbm->end();it++) it->second->summary(L, headerS);
   return;
}

ObjectDb* ADatedObjectDb::odb(Object* dbobj, UtilDate* end_d, UtilDate* dh, 
                               int& xval)
{
   UtilDate* _dh = NULL;
   ObjectDb* x = NULL;

   xval = 0;
   if(dbobj!=_dbobj) {xval=1; return x;}
   if(end_d!=_end_d) {xval=2; return x;}
   _dh = this->dh(dh);
   if(_dh==NULL) {xval=3;return x;}
   x = (*_odbm)[_dh];
   if(x==NULL) {xval=4; return x;}

   return x;
}



#endif

