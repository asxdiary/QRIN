// Name:     Db.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_Db_cpp
#define ASX_Db_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Model.hpp"
#include "Summarizable.hpp"
#include "EADatedObjectDb.hpp"
#include "UtilDate.hpp"
#include "DoubleDbAccount.hpp"
#include "Db.hpp"
#include "MathUtils.hpp"
#include "ObjectUniverse.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiDbAccounts;
using namespace aiMathUtils;

/** --------------Constructors and init_NULL-----------*/

Db::Db() { init_NULL(); }
Db::Db(const Db* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
Db::Db(const Db& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void Db::init_NULL()	{
	_eaodbm=NULL;
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void Db::init() {
   Model::init();
   Summarizable::init();
	init_Db();
}

void Db::init_Db() {
	init_eaodbm();
}

void Db::init_eaodbm() {
   _eaodbm = new unordered_map<Object*, EADatedObjectDb*>();
}

/** -----Destructors and Memory Cleanup functions -----*/

Db::~Db()	{ cleanMem(); }

void Db::cleanMem()	{
	cleanMem_Db();
   Model::cleanMem();
   Summarizable::cleanMem();
}

void Db::cleanMem_Db() {
	cleanMem_eaodbm();
}

void Db::cleanMem_eaodbm() {
   if(_eaodbm!=NULL) {
      unordered_map<Object*, EADatedObjectDb*>::iterator it;
      for(it=_eaodbm->begin();it!=_eaodbm->end();it++) delete it->second;
      delete _eaodbm;
   }
	_eaodbm=NULL;
}

/** ------------- Data Access Functions --------------------*/

unordered_map<Object*,EADatedObjectDb*>* Db::eaodbm() {return _eaodbm;}

/** ------------- Access classname dynamically --------------------*/

string Db::className() const {return "Db";}

/** ------------- Error Message Handling Functions ------------------*/

void Db::myerr_msg(string msg, string func) {
	err_msg("Db::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void Db::fprint(string fname) {
   Model::fprint(fname);
   Summarizable::fprint(fname);
	fprint_Db(fname);
}

void Db::fprint_Db(string fname) {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
   /*
	util_ofprint_obj(fname,"eaodbm",_eaodbm);
   */
}

void Db::fscan(string fname) {
   Model::fscan(fname);
   Summarizable::fscan(fname);
	fscan_Db(fname);
}

void Db::fscan_Db(string fname) {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
	//Insert scanning function for eaodbm here
}

/** ------------- Reset Functions --------------------*/

void Db::reset() {
	reset_Db();
   Model::reset();
   Summarizable::reset();
}

void Db::reset_Db() {
}

/** ----------  static instance function -----------*/

Db* Db::instantiate()	{
   return Db::instance();
}

Db* Db::instance()	{
	Db* ptr=new Db();
	ptr->init();
	return ptr;
}


Db* Db::instance_fscan(string fname)	{
	Db* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new Db();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

void Db::add_odb(ObjectDb* odb) {
   unordered_map<Object*, EADatedObjectDb*>::iterator it;
   Object* dbobj = NULL;

   if(odb==NULL) return;

   dbobj = odb->dbobj();
   while( (it=_eaodbm->find(dbobj)) == _eaodbm->end()) {
      (*_eaodbm)[dbobj] = create_eaodb(dbobj);
   }
   it->second->add_odb(odb);
}


EADatedObjectDb* Db::eaodb(Object* dbobj, int& xval) 
{
   EADatedObjectDb* x = NULL;
   unordered_map<Object*, EADatedObjectDb*>::iterator it;

   xval = 0;
   it = _eaodbm->find(dbobj);
   if(it==_eaodbm->end()) {xval=1; return x;}
   x = it->second;
   return x;
}

double Db::ddba(Object* dbobj, UtilDate* end_d, UtilDate* dh, 
             DoubleDbAccount* dba, int& xval)
{
   EADatedObjectDb* eaodb = NULL;
   double x = 0;
   eaodb = this->eaodb(dbobj, xval);
   if(xval>0) return x;
   x = eaodb->ddba(dbobj, end_d, dh, dba, xval);
   return x;
}

string Db::sdba(Object* dbobj, UtilDate* end_d, UtilDate* dh, 
             StringDbAccount* dba, int& xval)
{
   EADatedObjectDb* eaodb = NULL;
   string x = "";
   eaodb = this->eaodb(dbobj, xval);
   if(xval>0) return x;
   x = eaodb->sdba(dbobj, end_d, dh, dba, xval);
   return x;
}

void Db::summary(list<unordered_map<string,string>*>*& L, set<string>* headerS) {
   Summarizable::summary(L, headerS);
   unordered_map<Object*, EADatedObjectDb*>::iterator it;
   for(it=_eaodbm->begin();it!=_eaodbm->end();it++) it->second->summary(L, headerS);
   return;
}

ObjectDb* Db::odb(Object* dbobj, UtilDate* end_d, UtilDate* dh, 
                   int& xval)
{
   EADatedObjectDb* eaodb = NULL;
   ObjectDb* x = NULL;
   eaodb = this->eaodb(dbobj, xval);
   if(xval>0) return x;
   x = eaodb->odb(dbobj, end_d, dh, xval);
   return x;
}

ObjectDb* Db::odb_closest_le(Object* dbobj, 
                             UtilDate* dh, UtilDate* dh_floor, 
                             UtilDate* dstar, UtilDate* dstar_floor, 
                             bool end_flag, int& xval)
{
   EADatedObjectDb* eaodb = NULL;
   ObjectDb* x = NULL;
   eaodb = this->eaodb(dbobj, xval);
   if(xval>0) return x;
   x = eaodb->odb_closest_le(dbobj, dh, dh_floor, dstar, dstar_floor, end_flag, xval);
   return x;
}

EADatedObjectDb* Db::create_eaodb(Object* dbobj) {
   return EADatedObjectDb::instance(dbobj);
}

Db* Db::agg(vector<UtilDate*>* end_dv, UtilDate* dh, int& xval, Db* db) {
   if(db==NULL) db = this->instantiate();
   unordered_map<Object*, EADatedObjectDb*>::iterator it;
   for(it=_eaodbm->begin();it!=_eaodbm->end();it++) {
      xval = 0;
      db->add_odb(it->second->agg(it->first, end_dv, dh, xval) );
   }
   xval = 0;

   return db;
}

void Db::compute(vector<UtilDate*>* end_dv, UtilDate* dh, DbAccount* dba, int& xval) {
   unordered_map<Object*, EADatedObjectDb*>::iterator it;
   for(it=_eaodbm->begin();it!=_eaodbm->end();it++) {
      xval = 0;
      it->second->compute(it->first, end_dv, dh, dba, xval);
   }
   xval = 0;
   return;
}

Db* Db::interpolate(UtilDate* end_d, UtilDate* dh, UtilDate* start_d, int& xval, Db* db) {
   if(db==NULL) db = this->instantiate();
   unordered_map<Object*, EADatedObjectDb*>::iterator it;
   for(it=_eaodbm->begin();it!=_eaodbm->end();it++) {
      xval = 0;
      db->add_odb(it->second->interpolate(it->first, end_d, dh, start_d, xval) );
   }
   xval = 0;

   return db;
}

Matrix* Db::ddba_closest_le(int n, Object** oba,
                            UtilDate* dh, UtilDate* dh_floor, 
                            UtilDate* dstar, UtilDate* dstar_floor, 
                            bool end_flag, 
                            int m, DoubleDbAccount** dbaa, 
                            Matrix*& xvalM,
                            bool strict_filter, Matrix* Delta)
{
   Object* dbobj = NULL;
   ObjectDb* odb = NULL;
   Matrix* X = NULL;
   double** XX = NULL;
   double** xvalMX = NULL;
   set<int>* S = NULL;
   int xval;

   X = Matrix::instance(n,m);
   if(xvalM==NULL) xvalM = Matrix::instance(n,m);
   for(int i=0;i<m;i++) X->set_cmap_cimap(i, dbaa[i]->id());
   for(int j=0;j<n;j++) X->set_rmap_rimap(j, oba[j]->id());

   XX = X->X();
   xvalMX = xvalM->X();

   for(int j=0;j<n;j++) {
      dbobj = oba[j];
      odb = this->odb_closest_le(dbobj, dh, dh_floor, dstar, dstar_floor, end_flag, xval);

      if(xval>0) for(int i=0;i<m;i++) xvalMX[j][i] = xval;
      else {
         for(int i=0;i<m;i++) {
            XX[j][i] = odb->ddba(dbobj, NULL, dh, dbaa[i], xval);
            xvalMX[j][i] = xval;
         }
      }
   }

   if(strict_filter) S = mathutil_strict_filter(X,xvalM,Delta);

   //clean memory
   delete S;

   return X;
}

Matrix* Db::ddba_closest_le(list<Object*>* dbobjL, 
                            UtilDate* dh, UtilDate* dh_floor, 
                            UtilDate* dstar, UtilDate* dstar_floor, 
                            bool end_flag, 
                            list<DoubleDbAccount*>* dbaL,
                            Matrix*& xvalM,
                            bool strict_filter, Matrix* Delta)
{
   Object** oba = NULL;
   DoubleDbAccount** dbaa = NULL;
   Matrix* X = NULL;

   list<Object*>::iterator it;
   list<DoubleDbAccount*>::iterator it1;
   int n, m, i, j;

   oba = new Object*[ n = dbobjL->size() ];
   for(j =0, it=dbobjL->begin();it!=dbobjL->end();it++) oba[j++]= *it;

   dbaa = new DoubleDbAccount*[m = dbaL->size()];
   for(i=0, it1=dbaL->begin();it1!=dbaL->end();it1++) dbaa[i++] = *it1;

   X = this->ddba_closest_le(n, oba, dh, dh_floor, 
                             dstar, dstar_floor, 
                             end_flag, m, dbaa, xvalM, strict_filter, Delta);

   //clean memory
   delete [] oba;
   delete [] dbaa;

   return X;
}

Matrix* Db::ddba_summary(int n, Object** oba,
                         int m, DoubleDbAccount** dbaa, 
                         Matrix*& xvalM,
                         Matrix*& xsm,
                         bool strict_filter, Matrix* Delta)
{
   Matrix* X = NULL;
   Matrix** Xarr = NULL;
   Matrix** xvalMarr = NULL;
   Matrix** xsmarr = NULL;
   EADatedObjectDb* eaodb = NULL;
   int xval;

   Xarr = new Matrix*[n];
   xvalMarr = new Matrix*[n];
   xsmarr = new Matrix*[n];

   for(int i=0;i<n;i++) {
      Xarr[i] = xvalMarr[i] = xsmarr[i] = NULL;
      eaodb = this->eaodb(oba[i], xval);
      if(xval>0) {
         Xarr[i] = Matrix::instance(0,m);
         xvalMarr[i] = Matrix::ones(0,m);
         xsmarr[i] = Matrix::ones(Xarr[i]->m(),1,i);
         continue;
      }
      Xarr[i] = eaodb->ddba_summary(oba[i], m, dbaa, xvalMarr[i], strict_filter, Delta);
      xsmarr[i] = Matrix::ones(Xarr[i]->m(),1,i);
   }

   //set row names for xsm matrices
   for(int i=0;i<n;i++) {
      int mi = Xarr[i]->m();
      string* rmap = Xarr[i]->rmap();
      for(int ii=0;ii<mi;ii++) xsmarr[i]->set_rmap_rimap(ii, rmap[ii]);
   }

   X = Matrix::concat(true, Xarr, n);
   xvalM = Matrix::concat(true, xvalMarr, n);
   xsm = Matrix::concat(true, xsmarr, n);

   //set the column names for X
   for(int j=0;j<m;j++) X->set_cmap_cimap(j, dbaa[j]->id());
   for(int j=0;j<m;j++) xvalM->set_cmap_cimap(j, dbaa[j]->id());

   //clean memory
   for(int i=0;i<n;i++) delete Xarr[i];
   for(int i=0;i<n;i++) delete xvalMarr[i];
   for(int i=0;i<n;i++) delete xsmarr[i];
   delete [] Xarr;
   delete [] xvalMarr;
   delete [] xsmarr;

   return X;
}

Matrix* Db::ddba_summary(list<Object*>* dbobjL, 
                         list<DoubleDbAccount*>* dbaL,
                         Matrix*& xvalM,
                         Matrix*& xsm,
                         bool strict_filter, Matrix* Delta)
{
   Object** oba = NULL;
   DoubleDbAccount** dbaa = NULL;
   Matrix* X = NULL;

   list<Object*>::iterator it;
   list<DoubleDbAccount*>::iterator it1;
   int n, m, i, j;

   oba = new Object*[ n = dbobjL->size() ];
   for(j =0, it=dbobjL->begin();it!=dbobjL->end();it++) oba[j++]= *it;

   dbaa = new DoubleDbAccount*[m = dbaL->size()];
   for(i=0, it1=dbaL->begin();it1!=dbaL->end();it1++) dbaa[i++] = *it1;

   X = this->ddba_summary(n, oba, m, dbaa, xvalM, xsm, strict_filter, Delta);

   //clean memory
   delete [] oba;
   delete [] dbaa;

   return X;
}

Matrix* Db::ddba_closest_le(ObjectUniverse* univ,
                            UtilDate* dh, UtilDate* dh_floor, 
                            UtilDate* dstar, UtilDate* dstar_floor, 
                            bool end_flag, 
                            list<DoubleDbAccount*>* dbaL,
                            Matrix*& xvalM,
                            bool strict_filter, Matrix* Delta)
{
   list<Object*>* objL = univ->objL();
   Matrix* X = this->ddba_closest_le(objL,dh, dh_floor, dstar, dstar_floor, end_flag, 
                                     dbaL, xvalM, strict_filter, Delta);
   delete objL;
   return X;
}

Matrix* Db::ddba_summary(ObjectUniverse* univ,
                         list<DoubleDbAccount*>* dbaL,
                         Matrix*& xvalM,
                         Matrix*& xsm,
                         bool strict_filter, Matrix* Delta)
{
   list<Object*>* objL = univ->objL();
   Matrix* X = this->ddba_summary(objL, dbaL, xvalM, xsm, strict_filter, Delta);
   delete objL;
   return X;
}

ObjectUniverse* Db::objuniv(ObjectUniverse* univ) {
	unordered_map<Object*,EADatedObjectDb*>::iterator it;
   if(univ==NULL) univ = ObjectUniverse::instance();
   for(it=_eaodbm->begin();it!=_eaodbm->end();it++) univ->add_obj(it->first);
   return univ;
}

Db* Db::merge(Db* db2, UtilDate* end_d, UtilDate* dh, int& xval, Db* db) {
   if(db==NULL) db = this->instantiate();
   Db* db1 = this;

   Object* obj = NULL;
   ObjectDb* odb1 = NULL;
   ObjectDb* odb2 = NULL;
   ObjectDb* odb = NULL;
   unordered_map<Object*, EADatedObjectDb*>::iterator it;

   for(it=_eaodbm->begin();it!=_eaodbm->end();it++) {
      xval = 0;

      obj = it->first;
      odb1 = db1->odb(obj, end_d, dh, xval); 
      odb2 = db2->odb(obj, end_d, dh, xval); 

      odb = NULL;
      if(odb1!=NULL) odb = odb1;
      else if(odb2!=NULL) odb = odb2;
      if(odb!=NULL) db->add_odb( odb->clone() );
   }
   xval = 0;

   return db;
}

Db* Db::merge(Db* db2, list<UtilDate*>* end_dL, UtilDate* dh, int& xval, Db* db) {
   list<UtilDate*>::iterator it;
   for(it=end_dL->begin();it!=end_dL->end();it++) db = this->merge(db2,*it,dh,xval,db);
   return db;
}

#endif

