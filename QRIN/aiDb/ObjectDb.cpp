// Name:     ObjectDb.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ObjectDb_cpp
#define ASX_ObjectDb_cpp


#include <unordered_map>
#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "UtilDate.hpp"
#include "Model.hpp"
#include "Dated.hpp"
#include "Summarizable.hpp"
#include "DbAccount.hpp"
#include "DoubleDbAccount.hpp"
#include "StringDbAccount.hpp"
#include "ObjectDb.hpp"
#include "StartDateAccount.hpp"
#include "EndDateAccount.hpp"
#include "AvailabilityDateAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiDbAccounts;

/** --------------Constructors and init_NULL-----------*/

ObjectDb::ObjectDb() { init_NULL(); }
ObjectDb::ObjectDb(const ObjectDb* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
ObjectDb::ObjectDb(const ObjectDb& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void ObjectDb::init_NULL()	{
	_dbobj=NULL;
	_ddbam=NULL;
	_sdbam=NULL;
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void ObjectDb::init(Object* dbobj, UtilDate* end_d, UtilDate* dh, UtilDate* start_d) {
   Model::init();
   Dated::init(end_d);
   Summarizable::init();
	init_ObjectDb(dbobj, end_d, dh, start_d);
}

void ObjectDb::init_ObjectDb(Object* dbobj, UtilDate* end_d, UtilDate* dh, UtilDate* start_d) {
	init_dbobj(dbobj);
	init_ddbam();
	init_sdbam();

   (*_ddbam)[StartDateAccount::instance()] = start_d->icode();
   (*_ddbam)[EndDateAccount::instance()] = end_d->icode();
   (*_ddbam)[AvailabilityDateAccount::instance()] = dh->icode();
}

void ObjectDb::init_dbobj(Object* obj) {_dbobj=obj;}

void ObjectDb::init_ddbam() {
   _ddbam = new unordered_map<DoubleDbAccount*,double>();
}

void ObjectDb::init_sdbam() {_sdbam = new unordered_map<StringDbAccount*,string>();}

/** -----Destructors and Memory Cleanup functions -----*/

ObjectDb::~ObjectDb()	{ cleanMem(); }

void ObjectDb::cleanMem()	{
	cleanMem_ObjectDb();
   Model::cleanMem();
   Dated::cleanMem();
   Summarizable::cleanMem();
}

void ObjectDb::cleanMem_ObjectDb() {
	cleanMem_dbobj();
	cleanMem_ddbam();
	cleanMem_sdbam();
}

void ObjectDb::cleanMem_dbobj() {
	_dbobj=NULL;
}

void ObjectDb::cleanMem_ddbam() {
   delete _ddbam;
	_ddbam=NULL;
}

void ObjectDb::cleanMem_sdbam() {
   delete _sdbam;
	_sdbam=NULL;
}


/** ------------- Data Access Functions --------------------*/

Object* ObjectDb::dbobj() {return _dbobj;}
UtilDate* ObjectDb::end_d() {
   return UtilDate::instance( int(_ddbam->find(EndDateAccount::instance())->second) );
}
UtilDate* ObjectDb::start_d() {
   return UtilDate::instance( int(_ddbam->find(StartDateAccount::instance())->second) );
}
UtilDate* ObjectDb::dh() {
   return UtilDate::instance( int(_ddbam->find(AvailabilityDateAccount::instance())->second) );
}
unordered_map<DoubleDbAccount*,double>* ObjectDb::ddbam() {return _ddbam;}
unordered_map<StringDbAccount*,string>* ObjectDb::sdbam() {return _sdbam;}

/** ------------- Access classname dynamically --------------------*/

string ObjectDb::className() const {return "ObjectDb";}

/** ------------- Error Message Handling Functions ------------------*/

void ObjectDb::myerr_msg(string msg, string func) {
	err_msg("ObjectDb::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void ObjectDb::fprint(string fname) {
   Model::fprint(fname);
   Dated::fprint(fname);
   Summarizable::fprint(fname);
	fprint_ObjectDb(fname);
}

void ObjectDb::fprint_ObjectDb(string fname) {
	util_ofprint_obj(fname,"dbobj",_dbobj);
	util_ofprint_obj(fname,"end_d",this->end_d());
	util_ofprint_obj(fname,"dh",this->dh());
	util_ofprint_obj(fname,"start_d",this->start_d());
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
}

void ObjectDb::fscan(string fname) {
   Summarizable::fscan(fname);
   Dated::fscan(fname);
   Model::fscan(fname);
	fscan_ObjectDb(fname);
}

void ObjectDb::fscan_ObjectDb(string fname) {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
	//Insert scanning function for end_d here
	//Insert scanning function for dh here
	//Insert scanning function for start_d here
}

/** ------------- Reset Functions --------------------*/

void ObjectDb::reset() {
	reset_ObjectDb();
   Summarizable::reset();
   Dated::reset();
   Model::reset();
}

void ObjectDb::reset_ObjectDb() {
}

/** ----------  static instance function -----------*/

ObjectDb* ObjectDb::instantiate(Object* dbobj, UtilDate* end_d, UtilDate* dh, UtilDate* start_d)	{
   return ObjectDb::instance(dbobj, end_d, dh, start_d);
}

ObjectDb* ObjectDb::instance(Object* dbobj, UtilDate* end_d, UtilDate* dh, UtilDate* start_d)	{
	ObjectDb* ptr=new ObjectDb();
	ptr->init(dbobj, end_d, dh, start_d);
	return ptr;
}


ObjectDb* ObjectDb::instance_fscan(string fname)	{
	ObjectDb* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new ObjectDb();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

double ObjectDb::ddba(Object* dbobj, UtilDate* end_d, UtilDate* dh,
                    DoubleDbAccount* dba, int& xval)
{
   unordered_map<DoubleDbAccount*,double>::iterator it;
   double x = 0;

   xval = 0;
   chk_dbobj(dbobj, xval); if(xval>0) return x;
   chk_end_d(end_d, xval); if(xval>0) return x;
   chk_dh(dh, xval); if(xval>0) return x;

   it = _ddbam->find(dba);
   if(it==_ddbam->end()) {xval=4; return x;}
   x = it->second; return x;
   return x;
}

string ObjectDb::sdba(Object* dbobj, UtilDate* end_d, UtilDate* dh,
                       StringDbAccount* dba, int& xval)
{
   unordered_map<StringDbAccount*,string>::iterator it;
   string x="";

   xval = 0;
   chk_dbobj(dbobj, xval); if(xval>0) return x;
   chk_end_d(end_d, xval); if(xval>0) return x;
   chk_dh(dh, xval); if(xval>0) return x;

   it = _sdbam->find(dba);
   if(it==_sdbam->end()) {xval=4; return x;}
   x = it->second; return x;
   return x;
}

void ObjectDb::add_ddba(DoubleDbAccount* dba, double x, int xval) {
   if(xval==0) (*_ddbam)[dba] = x;
}

void ObjectDb::add_sdba(StringDbAccount* dba, string x, int xval) {
   if(xval==0) (*_sdbam)[dba] = x;
}

void ObjectDb::summary(list<unordered_map<string,string>*>*& L, set<string>* headerS) {
   Summarizable::summary(L, headerS);

   unordered_map<string,string>* m = NULL;
   string key, val;

   m = new unordered_map<string,string>();

   (*m)[key=util_join(".","ObjectDb","dbobj")] = _dbobj->id(); 
   if(headerS!=NULL) headerS->insert(key);
   /*
   (*m)[key=util_join(".","ObjectDb","start_d")] = this->start_d()->id();
   if(headerS!=NULL) headerS->insert(key);
   (*m)[key=util_join(".","ObjectDb","dh")] = this->dh()->id();
   if(headerS!=NULL) headerS->insert(key);
   (*m)[key=util_join(".","ObjectDb","end_d")] = this->end_d()->id();
   if(headerS!=NULL) headerS->insert(key);
   */

   {
      unordered_map<DoubleDbAccount*,double>::iterator it;
      for(it=_ddbam->begin();it!=_ddbam->end();it++) {
         key = it->first->id();
         val = it->second;
         if(headerS!=NULL && headerS->find(key)==headerS->end()) continue;
         (*m)[key]= util_string(it->second);
      }
   }

   {
      unordered_map<StringDbAccount*,string>::iterator it;
      for(it=_sdbam->begin();it!=_sdbam->end();it++) {
         key = it->first->id();
         val = it->second;
         if(headerS!=NULL && headerS->find(key)==headerS->end()) continue;
         (*m)[key]= val;
      }
   }


   L->push_back(m);

   return;
}

set<DbAccount*>* ObjectDb::dbaS(set<DbAccount*>* S) {
   if(S==NULL) S = new set<DbAccount*>();
   unordered_map<DoubleDbAccount*,double>::iterator itd;
   unordered_map<StringDbAccount*,string>::iterator its;
   for(itd=_ddbam->begin();itd!=_ddbam->end();itd++) S->insert(itd->first);
   for(its=_sdbam->begin();its!=_sdbam->end();its++) S->insert(its->first);
   return S;
}

void ObjectDb::isContiguous(vector<ObjectDb*>* odbv, int& xval) {
   const int n = odbv->size();
   ObjectDb* tmp = NULL;

   xval = 0;
   tmp = odbv->front();
   for(int i=1;i<n && xval==0;i++) {
      if(tmp->end_d()!=odbv->at(i)->start_d()) xval = 1;
      tmp = odbv->at(i);
   }

   return;
}

void ObjectDb::chk_dbobj(Object* dbobj, int& xval) {
   xval = 0;
   if(dbobj!=NULL && dbobj!=_dbobj) xval = 1;
}

void ObjectDb::chk_end_d(UtilDate* end_d, int& xval) {
   xval = 0;
   if(end_d!=NULL && end_d!=this->end_d()) xval = 2;
}

void ObjectDb::chk_dh(UtilDate* dh, int& xval) {
   xval = 0;
   if(this->dh()->isAfter(dh)) xval=3; 
}

ObjectDb* ObjectDb::clone() {
   ObjectDb* odb = NULL;
	unordered_map<DoubleDbAccount*,double>::iterator itD;
	unordered_map<StringDbAccount*,string>::iterator itS;
   int xval;

   odb = this->instantiate(this->dbobj(),this->end_d(),this->dh(),this->start_d());

   xval = 0;
   for(itD=_ddbam->begin();itD!=_ddbam->end();itD++) odb->add_ddba(itD->first,itD->second,xval);
   for(itS=_sdbam->begin();itS!=_sdbam->end();itS++) odb->add_sdba(itS->first,itS->second,xval);

   return odb;
}

#endif

