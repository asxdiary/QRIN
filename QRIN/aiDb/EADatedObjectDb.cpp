// Name:     EADatedObjectDb.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_EADatedObjectDb_cpp
#define ASX_EADatedObjectDb_cpp


#include <vector>
#include <map>
#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "ADatedObjectDb.hpp"
#include "Model.hpp"
#include "Summarizable.hpp"
#include "DoubleDbAccount.hpp"
#include "EADatedObjectDb.hpp"
#include "EndDateAccount.hpp"
#include "StartDateAccount.hpp"
#include "AvailabilityDateAccount.hpp"
#include "Matrix.hpp"
#include "MathUtils.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiDbAccounts;
using namespace aiMath;
using namespace aiMathUtils;

/** --------------Constructors and init_NULL-----------*/

EADatedObjectDb::EADatedObjectDb() { init_NULL(); }
EADatedObjectDb::EADatedObjectDb(const EADatedObjectDb* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
EADatedObjectDb::EADatedObjectDb(const EADatedObjectDb& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void EADatedObjectDb::init_NULL()	{
	_dbobj=NULL;
	_aodbm=NULL;
	_dh2end_dSm=NULL;
	_dh2start_dSm=NULL;
	_start2end_dm=NULL;
	_end2start_dm=NULL;
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void EADatedObjectDb::init(Object* dbobj) {
   Model::init();
   Summarizable::init();
	init_EADatedObjectDb(dbobj);
}

void EADatedObjectDb::init_EADatedObjectDb(Object* dbobj) {
	init_dbobj(dbobj);
	init_aodbm();
	init_dh2end_dSm();
	init_dh2start_dSm();
	init_start2end_dm();
	init_end2start_dm();
}

void EADatedObjectDb::init_dbobj(Object* dbobj) {
   _dbobj = dbobj;
}

void EADatedObjectDb::init_aodbm() {
   _aodbm = new unordered_map<UtilDate*, ADatedObjectDb*>();
}

void EADatedObjectDb::init_dh2end_dSm() {
   _dh2end_dSm = new map<int,set<int>*>(); 
}

void EADatedObjectDb::init_dh2start_dSm() {
   _dh2start_dSm = new map<int,set<int>*>(); 
}

void EADatedObjectDb::init_start2end_dm() {
   _start2end_dm = new unordered_map<int,int>();
}

void EADatedObjectDb::init_end2start_dm() {
   _end2start_dm = new unordered_map<int,int>();
}

/** -----Destructors and Memory Cleanup functions -----*/

EADatedObjectDb::~EADatedObjectDb()	{ cleanMem(); }

void EADatedObjectDb::cleanMem()	{
	cleanMem_EADatedObjectDb();
   Model::cleanMem();
   Summarizable::cleanMem();
}

void EADatedObjectDb::cleanMem_EADatedObjectDb() {
	cleanMem_dbobj();
	cleanMem_aodbm();
	cleanMem_dh2end_dSm();
	cleanMem_dh2start_dSm();
	cleanMem_start2end_dm();
	cleanMem_end2start_dm();
}

void EADatedObjectDb::cleanMem_dbobj() {
	_dbobj=NULL;
}

void EADatedObjectDb::cleanMem_aodbm() {
   if(_aodbm!=NULL) {
      unordered_map<UtilDate*,ADatedObjectDb*>::iterator it;
      for(it=_aodbm->begin();it!=_aodbm->end();it++) delete it->second;
      delete _aodbm;
   }
	_aodbm=NULL;
}

void EADatedObjectDb::cleanMem_dh2end_dSm() {
   if(_dh2end_dSm!=NULL) {
      map<int,set<int>*>::iterator it;
      for(it=_dh2end_dSm->begin();it!=_dh2end_dSm->end();it++) delete it->second;
      delete _dh2end_dSm;
      _dh2end_dSm = NULL;
   }
   _dh2end_dSm = NULL;
}

void EADatedObjectDb::cleanMem_dh2start_dSm() {
   if(_dh2start_dSm!=NULL) {
      map<int,set<int>*>::iterator it;
      for(it=_dh2start_dSm->begin();it!=_dh2start_dSm->end();it++) delete it->second;
      delete _dh2start_dSm;
      _dh2start_dSm = NULL;
   }
   _dh2start_dSm = NULL;
}

void EADatedObjectDb::cleanMem_start2end_dm() {
   delete _start2end_dm;
	_start2end_dm=NULL;
}

void EADatedObjectDb::cleanMem_end2start_dm() {
   delete _end2start_dm;
	_end2start_dm=NULL;
}

/** ------------- Data Access Functions --------------------*/

Object* EADatedObjectDb::dbobj() {return _dbobj;}
unordered_map<UtilDate*,ADatedObjectDb*>* EADatedObjectDb::aodbm() {return _aodbm;}
map<int,set<int>*>* EADatedObjectDb::dh2end_dSm() {return _dh2end_dSm;}
map<int,set<int>*>* EADatedObjectDb::dh2start_dSm() {return _dh2start_dSm;}
unordered_map<int,int>* EADatedObjectDb::start2end_dm() {return _start2end_dm;}
unordered_map<int,int>* EADatedObjectDb::end2start_dm() {return _end2start_dm;}

/** ------------- Access classname dynamically --------------------*/

string EADatedObjectDb::className() const {return "EADatedObjectDb";}

/** ------------- Error Message Handling Functions ------------------*/

void EADatedObjectDb::myerr_msg(string msg, string func) {
	err_msg("EADatedObjectDb::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void EADatedObjectDb::fprint(string fname) {
   Model::fprint(fname);
   Summarizable::fprint(fname);
	fprint_EADatedObjectDb(fname);
}

void EADatedObjectDb::fprint_EADatedObjectDb(string fname) {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
   /*
	util_ofprint_obj(fname,"dbobj",_dbobj);
	util_ofprint_obj(fname,"aodbm",_aodbm);
   */
}

void EADatedObjectDb::fscan(string fname) {
   Model::fscan(fname);
   Summarizable::fscan(fname);
	fscan_EADatedObjectDb(fname);
}

void EADatedObjectDb::fscan_EADatedObjectDb(string fname) {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
	//Insert scanning function for aodbm here
}

/** ------------- Reset Functions --------------------*/

void EADatedObjectDb::reset() {
	reset_EADatedObjectDb();
   Model::reset();
   Summarizable::reset();
}

void EADatedObjectDb::reset_EADatedObjectDb() {
}

/** ----------  static instance function -----------*/

EADatedObjectDb* EADatedObjectDb::instantiate(Object* dbobj)	{
   return EADatedObjectDb::instance(dbobj);
}

EADatedObjectDb* EADatedObjectDb::instance(Object* dbobj)	{
	EADatedObjectDb* ptr=new EADatedObjectDb();
	ptr->init(dbobj);
	return ptr;
}

EADatedObjectDb* EADatedObjectDb::instance_fscan(string fname)	{
	EADatedObjectDb* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new EADatedObjectDb();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

void EADatedObjectDb::add_odb(ObjectDb* odb) {
   unordered_map<UtilDate*,ADatedObjectDb*>::iterator it;
   UtilDate* end_d = NULL;
   UtilDate* start_d = NULL;

   if(odb==NULL) return;

   if(odb->dbobj()!=dbobj()) myerr_msg("dbobj mismatch",__FUNCTION__);
   end_d = odb->end_d();
   start_d = odb->start_d();

   while( (it=_aodbm->find(end_d))==_aodbm->end() ) {
      (*_aodbm)[end_d] = create_aodb(end_d);
   }
   it->second->add_odb(odb);

   //update dh2end_dSm
   //update dh2start_dSm
   {
      set<int>* S = NULL;
      int end_di = end_d->icode();
      int start_di = start_d->icode();
      int dhi = odb->dh()->icode();

      for(;_dh2end_dSm->find(dhi)==_dh2end_dSm->end();(*_dh2end_dSm)[dhi] = new set<int>());
      S = _dh2end_dSm->find(dhi)->second;
      S->insert(end_di);

      for(;_dh2start_dSm->find(dhi)==_dh2start_dSm->end();(*_dh2start_dSm)[dhi] = new set<int>());
      S = _dh2start_dSm->find(dhi)->second;
      S->insert(start_di);
   }

   //update start2end_dm and end2start_dm
   {
      unordered_map<int,int>::iterator it;
      int end_di = end_d->icode();
      int start_di = start_d->icode();
      string msg;

      msg = "start-end dates mismatch";
      msg = msg + " dbobj->id = " + this->dbobj()->id();
      msg = msg + " start_d = " + util_string(start_di);
      msg = msg + " end_d = " + util_string(end_di);
      msg = msg + " supplied ";

      it = _start2end_dm->find(start_di);
      if(it!=_start2end_dm->end() && it->second != end_di) myerr_msg(msg + "end_di = " + util_string(it->second),__FUNCTION__);
      it = _end2start_dm->find(end_di);
      if(it!=_end2start_dm->end() && it->second != start_di) myerr_msg(msg + "start_di = " + util_string(it->second),__FUNCTION__);

      (*_start2end_dm)[start_di] = end_di;
      (*_end2start_dm)[end_di] = start_di;
   }

   return;
}

ADatedObjectDb* EADatedObjectDb::aodb(Object* dbobj, UtilDate* end_d, 
                                       int& xval) 
{
   ADatedObjectDb* x = NULL;
   unordered_map<UtilDate*,ADatedObjectDb*>::iterator it;

   xval = 0;
   chk_dbobj(dbobj,xval);
   if(xval>0) return x;

   it = _aodbm->find(end_d);
   if(it==_aodbm->end()) {xval=2; return x;}
   x = it->second;

   return x;
}

double EADatedObjectDb::ddba(Object* dbobj, UtilDate* end_d, UtilDate* dh,
                             DoubleDbAccount* dba, int& xval) 
{
   ADatedObjectDb* aodb = NULL;
   double x = 0;
   aodb = this->aodb(dbobj, end_d, xval);
   if(xval>0) return x;
   x = aodb->ddba(dbobj, end_d, dh, dba, xval);
   return x;
}

string EADatedObjectDb::sdba(Object* dbobj, UtilDate* end_d, UtilDate* dh,
                             StringDbAccount* dba, int& xval) 
{
   ADatedObjectDb* aodb = NULL;
   string x = "";
   aodb = this->aodb(dbobj, end_d, xval);
   if(xval>0) return x;
   x = aodb->sdba(dbobj, end_d, dh, dba, xval);
   return x;
}

void EADatedObjectDb::summary(list<unordered_map<string,string>*>*& L, set<string>* headerS) {
   Summarizable::summary(L, headerS);
   unordered_map<UtilDate*,ADatedObjectDb*>::iterator it;
   for(it=_aodbm->begin();it!=_aodbm->end();it++) it->second->summary(L, headerS);
   return;
}

ObjectDb* EADatedObjectDb::odb(Object* dbobj, UtilDate* end_d, UtilDate* dh,
                                int& xval) 
{
   ADatedObjectDb* aodb = NULL;
   ObjectDb* x = NULL;
   aodb = this->aodb(dbobj, end_d, xval);
   if(xval>0) return x;
   x = aodb->odb(dbobj, end_d, dh, xval);
   return x;
}

/** Algorithm
 *  1. Create odbv
 *  2. If odbv is incomplete OR contiguity test fails, return NULL
 *  3. Create odb
 *  4. create a union of all DbAccounts, dbaS
 *  5. For each dba in dbaS, apply the agg function 
 *
 *  Assumptions:
 *   Failure of agg function on one or more of the DbAccount does
 *   not change xval to be positive */

ObjectDb* EADatedObjectDb::agg(Object* dbobj, vector<UtilDate*>* end_dv, UtilDate* dh, 
                               int& xval)
{
   const int n = end_dv->size();
   ObjectDb* odb = NULL;
   vector<ObjectDb*>* odbv = NULL;
   set<DbAccount*> S;
   set<DbAccount*>::iterator it;

   xval = 0;
   chk_dbobj(dbobj, xval);
   if(xval>0) return odb;

   //create odbv
   odbv = this->odbv(dbobj, end_dv, dh, xval);
   if(xval>0) return odb;

   //check for contiguity
   ObjectDb::isContiguous(odbv, xval);
   if(xval>0) {delete odbv; return odb;}

   //create odb
   {
      UtilDate* end_d = NULL;
      UtilDate* start_d = NULL;
      UtilDate* dh_d = NULL;
      double end_d_icode, start_d_icode, dh_d_icode;

      end_d_icode = EndDateAccount::instance()->agg_guts(odbv, dh, xval);
      start_d_icode = StartDateAccount::instance()->agg_guts(odbv, dh, xval);
      dh_d_icode = AvailabilityDateAccount::instance()->agg_guts(odbv, dh, xval);

      end_d = UtilDate::instance(int(end_d_icode));
      start_d = UtilDate::instance(int(start_d_icode));
      dh_d = UtilDate::instance(int(dh_d_icode));

      odb = odbv->back()->instantiate(dbobj, end_d, dh_d, start_d);
   }

   //create union of all DbAccounts
   for(int i=0;i<n;i++) odbv->at(i)->dbaS(&S);

   //perform aggregation on each account
   for(it=S.begin();it!=S.end();it++) (*it)->agg(odb, odbv, dh, xval);
   xval = 0;

   //clean memory
   delete odbv;

   return odb;
}

ADatedObjectDb* EADatedObjectDb::create_aodb(UtilDate* end_d) {
   return ADatedObjectDb::instance(dbobj(),end_d);
}

vector<ObjectDb*>* EADatedObjectDb::odbv(Object* dbobj, vector<UtilDate*>* end_dv, UtilDate* dh, 
                                         int& xval)
{
   vector<ObjectDb*>* odbv = NULL;
   int n;

   xval = 0;

   chk_dbobj(dbobj, xval);
   if(xval>0) return odbv;

   n = end_dv->size();
   odbv = new vector<ObjectDb*>(n);
   for(int i=0;i<n && (xval==0);i++) {
      (*odbv)[i] = this->odb(dbobj, end_dv->at(i), dh, xval);
   }
   if(xval>0) {delete odbv; odbv=NULL;}

   return odbv;
}

void EADatedObjectDb::compute(Object* dbobj, vector<UtilDate*>* end_dv, UtilDate* dh,
                              DbAccount* dba, int& xval)
{
   vector<ObjectDb*>* odbv = NULL;

   xval = 0;

   chk_dbobj(dbobj, xval);
   if(xval>0) return;
   odbv = this->odbv(dbobj, end_dv, dh, xval);
   if(xval>0) return;
   dba->compute(odbv, xval);

   //clean memory
   delete odbv;

   return;
}

void EADatedObjectDb::chk_dbobj(Object* dbobj, int& xval) {
   xval = 0;
   if(dbobj!=NULL && dbobj!=_dbobj) xval = 1;
}

ObjectDb* EADatedObjectDb::odb_closest_le(Object* dbobj, 
                                          UtilDate* dh, UtilDate* dh_floor,
                                          UtilDate* dstar, UtilDate* dstar_floor,
                                          bool end_flag, int& xval) 
{
   ObjectDb* odb = NULL;
   UtilDate* cdh = NULL;
   UtilDate* d = NULL;
   UtilDate* end_d = NULL;
   map<int,set<int>*>* dh2dSm = NULL;

   xval = 0;
   chk_dbobj(dbobj, xval);

   if(end_flag) dh2dSm = _dh2end_dSm;
   else dh2dSm = _dh2start_dSm;

   //find end_d and cdh
   if(xval==0) {
      map<int,set<int>*>::iterator it;
      set<int>::iterator itS;

      util_closest_le(dh2dSm, dh->icode(), it);
      if(it==dh2dSm->end()) xval=1;

      for(;xval==0;) {
         cdh = UtilDate::instance(it->first);
         if(dh_floor!=NULL && cdh->isBefore(dh_floor)) {xval=1; break;}

         util_closest_le(it->second, dstar->icode(), itS);
         if(itS!=it->second->end()) {
            d = UtilDate::instance(*itS);
            if(dstar_floor!=NULL && d->isBefore(dstar_floor)) {}
            else break;
         }

         if(it==dh2dSm->begin()) xval=1;
         else it--;
      }
   }

   if(xval==0) {
      if(end_flag) end_d = d;
      else {
         int end_di, di;
         di = d->icode();

         if(_start2end_dm->find(di)==_start2end_dm->end()) myerr_msg("could not find end_d with end_flag=false",__FUNCTION__);

         end_di = _start2end_dm->find(di)->second;
         end_d = UtilDate::instance(end_di);
      }

   }
   
   if(xval==0) odb = this->odb(dbobj, end_d, cdh, xval);
   return odb;
}

/** Algorithm
 * 1. s1 = dh2start_dSm[dh]->closest_le(start_d)
 * 2. e1 = start2end[s1]
 * 3. s2 = e1
 * 4. e2 = start2end[s2]
 * 5. odb1 = odb(e1, dh)
 * 6. odb2 = odb(e2, dh)
 * 7. odb = ObjectDb::instance(end_d, dh, start_d)
 * 8. For all accounts dba in odb1 or odb2: dba->interpolate(odb1, odb2, odb)
 * 9. return odb */
ObjectDb* EADatedObjectDb::obsolete_interpolate(Object* dbobj, UtilDate* end_d, UtilDate* dh, 
                                       UtilDate* start_d, int& xval)
{
   UtilDate* s1 = NULL;
   UtilDate* e1 = NULL;
   UtilDate* s2 = NULL;
   UtilDate* e2 = NULL;
   ObjectDb* odb1 = NULL;
   ObjectDb* odb2 = NULL;
   ObjectDb* odb = NULL;
   unordered_map<int,int>::iterator it;

   xval = 0;

   //determine s1
   {
      map<int,set<int>*>::iterator it1;
      util_closest_le(_dh2start_dSm, dh->icode(), it1);
      if(it1==_dh2start_dSm->end()) xval = 1;
      else {
         set<int>::iterator it2;
         util_closest_le(it1->second, start_d->icode(), it2);
         if(it2==it1->second->end()) xval = 2;
         else s1 = UtilDate::instance(*it2);
      }
   }
   if(xval>0) return odb;

   //determine e1
   {
      it = _start2end_dm->find(s1->icode());
      if(it==_start2end_dm->end()) xval=1;
      else e1 = UtilDate::instance(it->second);
   }
   if(xval>0) return odb;

   //determine s2
   s2 = e1;

   //determine e2
   {
      it = _start2end_dm->find(s2->icode());
      if(it==_start2end_dm->end()) xval=1;
      else e2 = UtilDate::instance(it->second);
   }
   if(xval>0) return odb;

   odb1 = this->odb(dbobj, e1, dh, xval);
   if(xval>0) return odb;
   odb2 = this->odb(dbobj, e2, dh, xval);
   if(xval>0) return odb;
   odb = odb1->instantiate(dbobj, end_d, dh, start_d);

   //For all accounts dba in odb1 or odb2: dba->interpolate(odb1, odb2, odb)
   {
      set<DbAccount*> S;
      set<DbAccount*>::iterator it;
      odb1->dbaS(&S);
      odb2->dbaS(&S);

      for(it=S.begin();it!=S.end();it++) (*it)->interpolate(odb1, odb2, odb, xval);
      xval = 0;
   }

   return odb;
}

ObjectDb* EADatedObjectDb::interpolate(Object* dbobj, UtilDate* end_d, UtilDate* dh, 
                                       UtilDate* start_d, int& xval)
{
   ObjectDb* odb1 = NULL;
   ObjectDb* odb2 = NULL;
   ObjectDb* odb = NULL;
   unordered_map<int,int>::iterator it;

   xval = 1;

   //determine odb1 and odb2
   for(int _i=0;_i<1;_i++) {
      UtilDate* s1 = NULL;
      UtilDate* e1 = NULL;
      UtilDate* s2 = NULL;
      UtilDate* e2 = NULL;
      map<int,set<int>*>* dh2dSm = NULL;
      map<int,set<int>*>::iterator itdh;
      set<int>::iterator itdS;
      unordered_map<int,int>::iterator it;

      dh2dSm = _dh2start_dSm;
      util_closest_le(dh2dSm, dh->icode(), itdh);

      for(;xval>0 && itdh!=dh2dSm->end();itdh--) {
         util_closest_le(itdh->second, start_d->icode(), itdS);

         for(;xval>0 && itdS!=itdh->second->end(); itdS--) {
            s1 = UtilDate::instance(*itdS);
            it = _start2end_dm->find(s1->icode());

            for(;xval>0 && it!=_start2end_dm->end();) {
               e1 = UtilDate::instance(it->second);
               s2 = e1;

               it = _start2end_dm->find(s2->icode());
               for(;xval>0 && it!=_start2end_dm->end();) {
                  e2 = UtilDate::instance(it->second);
                  odb1 = this->odb(dbobj, e1, dh, xval); if(xval>0) break;
                  odb2 = this->odb(dbobj, e2, dh, xval); if(xval>0) break;
                  break;
               }

               break;
            }

            if(itdS==itdh->second->begin()) break;
         }

         if(itdh==dh2dSm->begin()) break;
      }

   }

   if(xval>0) return odb;

   odb = odb1->instantiate(dbobj, end_d, dh, start_d);

   //For all accounts dba in odb1 or odb2: dba->interpolate(odb1, odb2, odb)
   {
      set<DbAccount*> S;
      set<DbAccount*>::iterator it;
      odb1->dbaS(&S);
      odb2->dbaS(&S);

      for(it=S.begin();it!=S.end();it++) (*it)->interpolate(odb1, odb2, odb, xval);
      xval = 0;
   }

   return odb;
}



/** Algorithm
 *
 * 1. Determine m by iterating over the aodbm
 * 2. Initialize X and xvalM
 * 3. Initialize the column names of X 
 * 4. Iterate over members of aodbm
 *    4.1 Iterate over members of odbm 
 *       4.1.1 Extract odb
 *       4.1.2 Populate the columns of X */
Matrix* EADatedObjectDb::ddba_summary(Object* dbobj,
                                      int m, DoubleDbAccount** dbaa, 
                                      Matrix*& xvalM,
                                      bool strict_filter, Matrix* Delta) 
{
	unordered_map<UtilDate*,ADatedObjectDb*>* aodbm = this->aodbm();

	unordered_map<UtilDate*,ObjectDb*>* odbm = NULL;
	unordered_map<UtilDate*,ADatedObjectDb*>::iterator it1;
	unordered_map<UtilDate*,ObjectDb*>::iterator it2;

   ObjectDb* odb = NULL;
   Matrix* X = NULL;
   double** XX = NULL;
   double** xvalMX = NULL;
   set<int>* S = NULL;
   int xval, n, j;
   string id;

   for(n=0,it1=aodbm->begin();it1!=aodbm->end();it1++) n += it1->second->odbm()->size();

   X = Matrix::instance(n,m);
   if(xvalM==NULL) xvalM = Matrix::instance(n,m);
   for(int i=0;i<m;i++) X->set_cmap_cimap(i, dbaa[i]->id());

   XX = X->X();
   xvalMX = xvalM->X();

   for(j=0,it1=aodbm->begin();it1!=aodbm->end();it1++) {
      odbm = it1->second->odbm();

      for(it2=odbm->begin();it2!=odbm->end();it2++,j++) {
         odb = it2->second;

         id = util_join(".",dbobj->id(),odb->start_d()->id(),
                        odb->end_d()->id(),
                        odb->dh()->id());
         X->set_rmap_rimap(j, id);
         xvalM->set_rmap_rimap(j, id);

         for(int i=0;i<m;i++) {
            XX[j][i] = odb->ddba(dbobj, NULL, odb->dh(), dbaa[i], xval);
            xvalMX[j][i] = xval;
         }
      }

   }

   if(strict_filter) S = mathutil_strict_filter(X,xvalM, Delta);

   //clean memory
   delete S;

   return X;
}



#endif

