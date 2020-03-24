// Name:     Panel.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_Panel_cpp
#define ASX_Panel_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Model.hpp"
#include "Matrix.hpp"
#include "Panel.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMath;

/** --------------Constructors and init_NULL-----------*/

Panel::Panel() { init_NULL(); }
Panel::Panel(const Panel* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
Panel::Panel(const Panel& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void Panel::init_NULL()	{
	_X=NULL;
	_mS=NULL;
	_nS=NULL;
	_mSm=NULL;
	_nSm=NULL;
	_rmap=NULL;
	_cmap=NULL;
	_rimap=NULL;
	_cimap=NULL;
}

/** ---Public Data Setting Functions-----------------*/

void Panel::set_rmap_rimap(unordered_map<int,string>* omap, unordered_map<string,int>* imap) {
   util_map_imap(omap, imap);
   cleanMem_rmap(); cleanMem_rimap();
   _rmap = omap; _rimap = imap;
}

void Panel::set_cmap_cimap(unordered_map<int,string>* omap, unordered_map<string,int>* imap) {
   util_map_imap(omap, imap);
   cleanMem_cmap(); cleanMem_cimap();
   _cmap = omap; _cimap = imap;
}

/** --------   Init Functions -------------------------*/

void Panel::init(const int T, Matrix** X,
                 set<int>* mS, 
                 set<int>* nS, 
                 unordered_map<int,int>** mSm, 
                 unordered_map<int,int>** nSm, 
                 unordered_map<int,string>* rmap, unordered_map<string,int>* rimap, 
                 unordered_map<int,string>* cmap, unordered_map<string,int>* cimap)
{
   Model::init();
	init_Panel(T,X,mS,nS,mSm,nSm,rmap,rimap,cmap,cimap);
}

void Panel::init_Panel(const int T, Matrix** X,
                       set<int>* mS, 
                       set<int>* nS, 
                       unordered_map<int,int>** mSm, 
                       unordered_map<int,int>** nSm, 
                       unordered_map<int,string>* rmap, unordered_map<string,int>* rimap, 
                       unordered_map<int,string>* cmap, unordered_map<string,int>* cimap)
{
   init_T(T);
   init_X(X);
   init_mS(mS);
	init_nS(nS);
	init_mSm(mSm);
	init_nSm(nSm);
	init_rmap_rimap(rmap,rimap);
	init_cmap_cimap(cmap,cimap);
}

void Panel::init_T(const int obj) {
   _T = obj;
}

void Panel::init_X(Matrix** obj) {
   _X = obj;
}

void Panel::init_mS(set<int>* obj) {
   _mS = obj;
}

void Panel::init_nS(set<int>* obj) {
   _nS = obj;
}

void Panel::init_mSm(unordered_map<int,int>** obj) {
   _mSm = obj;
   if(_mSm==NULL) {
      _mSm = new unordered_map<int,int>*[_T];
      for(int t=0;t<_T;t++) {
         Matrix* Xt = _X[t];
         if(Xt->m()!= (int)_mS->size()) myerr_msg(string("Xt->m()!=_mS->size() at t=") + util_string(t),__FUNCTION__);
         _mSm[t] = util_identity_map(0,Xt->m());
      }
   }
}

void Panel::init_nSm(unordered_map<int,int>** obj) {
   _nSm = obj;
   if(_nSm==NULL) {
      _nSm = new unordered_map<int,int>*[_T];
      for(int t=0;t<_T;t++) {
         Matrix* Xt = _X[t];
         if(Xt->n()!= (int)_nS->size()) myerr_msg(string("Xt->n()!=_nS->size() at t=") + util_string(t),__FUNCTION__);
         _nSm[t] = util_identity_map(0,Xt->n());
      }
   }
}

void Panel::init_rmap_rimap(unordered_map<int,string>* omap, unordered_map<string,int>* imap) {
   set_rmap_rimap(omap, imap);
}

void Panel::init_cmap_cimap(unordered_map<int,string>* omap, unordered_map<string,int>* imap) {
   set_cmap_cimap(omap, imap);
}

/** -----Destructors and Memory Cleanup functions -----*/

Panel::~Panel()	{ cleanMem(); }

void Panel::cleanMem()	{
	cleanMem_Panel();
   Model::cleanMem();
}

void Panel::cleanMem_Panel() {
	cleanMem_X();
	cleanMem_mS();
	cleanMem_nS();
	cleanMem_mSm();
	cleanMem_nSm();
	cleanMem_rmap();
	cleanMem_cmap();
	cleanMem_rimap();
	cleanMem_cimap();
}

void Panel::cleanMem_X() {
   util_clean_obj((Object**&)_X,_T);
	_X=NULL;
}

void Panel::cleanMem_mS() {
   delete _mS;
	_mS=NULL;
}

void Panel::cleanMem_nS() {
   delete _nS;
	_nS=NULL;
}

void Panel::cleanMem_mSm() {
   if(_mSm!=NULL) {
      for(int t=0;t<_T;t++) delete _mSm[t];
      delete [] _mSm;
   }
	_mSm=NULL;
}

void Panel::cleanMem_nSm() {
   if(_nSm!=NULL) {
      for(int t=0;t<_T;t++) delete _nSm[t];
      delete [] _nSm;
   }
	_nSm=NULL;
}

void Panel::cleanMem_rmap() {
   delete _rmap;
	_rmap=NULL;
}

void Panel::cleanMem_cmap() {
   delete _cmap;
	_cmap=NULL;
}

void Panel::cleanMem_rimap() {
   delete _rimap;
	_rimap=NULL;
}

void Panel::cleanMem_cimap() {
   delete _cimap;
	_cimap=NULL;
}

/** ------------- Data Access Functions --------------------*/

int Panel::T() {return _T;}
Matrix** Panel::X() {return _X;}
set<int>* Panel::mS() {return _mS;}
set<int>* Panel::nS() {return _nS;}
unordered_map<int,int>** Panel::mSm() {return _mSm;}
unordered_map<int,int>** Panel::nSm() {return _nSm;}
unordered_map<int,string>* Panel::rmap() {return _rmap;}
unordered_map<int,string>* Panel::cmap() {return _cmap;}
unordered_map<string,int>* Panel::rimap() {return _rimap;}
unordered_map<string,int>* Panel::cimap() {return _cimap;}

/** ------------- Access classname dynamically --------------------*/

string Panel::className() const {return "Panel";}

/** ------------- Error Message Handling Functions ------------------*/

void Panel::myerr_msg(string msg, string func) {
	err_msg("Panel::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void Panel::cerr_msg(string msg, string func) {
	err_msg("Panel::",func," ",msg);
}

void Panel::cwarn_msg(string msg, string func) {
	warn_msg("Panel::",func," ",msg);
}

void Panel::fprint(string fname) {
   Model::fprint(fname);
	fprint_Panel(fname);
}

void Panel::fprint_Panel(string fname) {
	util_ofprint(fname,"T",_T);
	util_ofprint_obj(fname,"X",(Object**)_X,_T);
	util_ofprint(fname,"mS",_mS);
	util_ofprint(fname,"nS",_nS);
	util_ofprint(fname,"mSm",_mSm,_T);
	util_ofprint(fname,"nSm",_nSm,_T);
	util_ofprint(fname,"rmap",_rmap);
	util_ofprint(fname,"cmap",_cmap);
	util_ofprint(fname,"rimap",_rimap);
	util_ofprint(fname,"cimap",_cimap);
}

void Panel::fscan(string fname) {
   Model::fscan(fname);
	fscan_Panel(fname);
}

void Panel::fscan_Panel(string fname) {
   int T, T1, T2;
   string str;

	util_ofscan(fname,"T",_T); T = _T;
   if(T>0) {
      str = util_ofname(fname,"X");
      _X = new Matrix*[T];
      for(int t=0;t<T;t++) {
         _X[t] = Matrix::instance_fscan( util_ofname(str,t) );
      }
   }

   util_ofscan(fname,"mS",_mS);
   util_ofscan(fname,"nS",_nS);
   util_ofscan(fname,"mSm",_mSm,T1);
   util_ofscan(fname,"nSm",_nSm,T2);
   util_ofscan(fname,"rmap",_rmap);
   util_ofscan(fname,"rimap",_rimap);
   util_ofscan(fname,"cmap",_cmap);
   util_ofscan(fname,"cimap",_cimap);

   //check
   if(T1!=T) myerr_msg("mSm->size() != T",__FUNCTION__);
   if(T2!=T) myerr_msg("nSm->size() != T",__FUNCTION__);

   return;
}

/** ------------- Reset Functions --------------------*/

void Panel::reset() {
	reset_Panel();
   Model::reset();
}

void Panel::reset_Panel() {
}

/** ----------  static instance function -----------*/


Panel* Panel::instance(const int T, Matrix** X,
                       set<int>* mS, 
                       set<int>* nS, 
                       unordered_map<int,int>** mSm, 
                       unordered_map<int,int>** nSm, 
                       unordered_map<int,string>* rmap, unordered_map<string,int>* rimap, 
                       unordered_map<int,string>* cmap, unordered_map<string,int>* cimap)
{
   Panel* ptr=NULL;
   int val;
   
   ptr=new Panel();
	ptr->init(T,X,mS,nS,mSm,nSm,rmap,rimap,cmap,cimap);
   if((val=ptr->chk())!=0) cerr_msg(string("ptr->chk() failed val = ") + util_string(val),__FUNCTION__);
	return ptr;
}


Panel* Panel::instance_fscan(string fname)	{
	Panel* ptr=NULL;
   int val;

	if(!util_fscan_NULL(fname)) {
		ptr=new Panel();
      ptr->init_NULL();
		ptr->fscan(fname);
	}
   if(ptr!=NULL && (val=ptr->chk())!=0) cerr_msg(string("ptr->chk() failed val = ") + util_string(val),__FUNCTION__);
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

int Panel::chk() {
   int val = Model::chk();

   if(_X==NULL) val++;
   if(_mS==NULL) val++;
   if(_nS==NULL) val++;
   if(_mSm==NULL) val++;
   if(_nSm==NULL) val++;

   //evaluate the consistency of ms, nS, mSm and nSm
   {
      for(int t=0;t<_T;t++) {
         if(_X[t]==NULL) {val++; continue;}
         Matrix* Xt = _X[t];
         const int m = Xt->m();
         const int n = Xt->n();
         unordered_map<int,int>* mSmt = _mSm[t];
         unordered_map<int,int>* nSmt = _nSm[t];
         unordered_map<int,int>::iterator it;

         if((int)mSmt->size() != m) {val++; continue;}
         if((int)nSmt->size() != n) {val++; continue;}

         for(int i=0;i<m;i++) {
            it = mSmt->find(i);
            if(it==mSmt->end()) {val++; continue;}
            if(_mS->find(it->second)==_mS->end()) {val++; continue;}
         }

         for(int j=0;j<n;j++) {
            it = nSmt->find(j);
            if(it==nSmt->end()) {val++; continue;}
            if(_nS->find(it->second)==_nS->end()) {val++; continue;}
         }

      }
   }

   if(_rimap!=NULL && _rimap->size()!=_mS->size()) val++;
   if(_cimap!=NULL && _cimap->size()!=_nS->size()) val++;
   if(_rmap!=NULL && _rmap->size()!=_mS->size()) val++;
   if(_cmap!=NULL && _cmap->size()!=_nS->size()) val++;

   return val;
}

Panel* Panel::sub(set<int>* rS, set<int>* cS, set<int>* xrS, set<int>* xcS) {

	int T = _T;
	Matrix** X = _X;
	set<int>* mS = _mS;
	set<int>* nS = _nS;
	unordered_map<int,int>** mSm = _mSm;
	unordered_map<int,int>** nSm = _nSm;
	unordered_map<int,string>* rmap = _rmap;
	unordered_map<int,string>* cmap = _cmap;
	//unordered_map<string,int>* rimap = _rimap;
	//unordered_map<string,int>* cimap = _cimap;

	int sub_T;
	Matrix** sub_X = NULL;
	set<int>* sub_mS = NULL;
	set<int>* sub_nS = NULL;
	unordered_map<int,int>** sub_mSm = NULL;
	unordered_map<int,int>** sub_nSm = NULL;
	unordered_map<int,string>* sub_rmap = NULL;
	unordered_map<int,string>* sub_cmap = NULL;
	unordered_map<string,int>* sub_rimap = NULL;
	unordered_map<string,int>* sub_cimap = NULL;
   Panel* ptr = NULL;

   list<set<int>*> memL;
   set<int>::iterator it;

   if(rS==NULL) { memL.push_back(rS=util_copy(mS));}
   if(cS==NULL) { memL.push_back(cS=util_copy(nS));}
   if(xrS==NULL) { memL.push_back(xrS=new set<int>());}
   if(xcS==NULL) { memL.push_back(xcS=new set<int>());}

   //create sub_mS and sub_nS
   {
      sub_mS = new set<int>();
      for(it=rS->begin();it!=rS->end();it++) {
         if(mS->find(*it)==mS->end()) myerr_msg("rS/mS is non-empty",__FUNCTION__);
         if(xrS->find(*it)==xrS->end()) sub_mS->insert(*it);
      }

      sub_nS = new set<int>();
      for(it=cS->begin();it!=cS->end();it++) {
         if(nS->find(*it)==nS->end()) myerr_msg("cS/nS is non-empty",__FUNCTION__);
         if(xcS->find(*it)==xcS->end()) sub_nS->insert(*it);
      }
   }

   sub_T = T;
   sub_X = new Matrix*[T];
   sub_mSm = new unordered_map<int,int>*[T];
   sub_nSm = new unordered_map<int,int>*[T];

   for(int t=0;t<T;t++) {
      Matrix* Xt = X[t];
      unordered_map<int,int>* mSmt = mSm[t];
      unordered_map<int,int>* nSmt = nSm[t];
      const int m = Xt->m();
      const int n = Xt->n();

      Matrix* sub_Xt = NULL;
      unordered_map<int,int>* sub_mSmt = NULL;
      unordered_map<int,int>* sub_nSmt = NULL;
      set<int>* rSt = NULL;
      set<int>* cSt = NULL;
      int* ra = NULL;
      int* ca = NULL;
      int ii, jj, mm, nn;
      unordered_map<int,int>::iterator mit;

      rSt = new set<int>();
      for(int i=0;i<m;i++) {
         mit = mSmt->find(i);
         if(mit==mSmt->end()) myerr_msg("integrity error",__FUNCTION__);
         ii = mit->second;
         it = sub_mS->find(ii);
         if(it==sub_mS->end()) continue;
         rSt->insert(i);
      }

      cSt = new set<int>();
      for(int j=0;j<n;j++) {
         mit = nSmt->find(j);
         if(mit==nSmt->end()) myerr_msg("integrity error",__FUNCTION__);
         jj = mit->second;
         it = sub_nS->find(jj);
         if(it==sub_nS->end()) continue;
         cSt->insert(j);
      }

      sub_Xt = Xt->sub(rSt,cSt,NULL,NULL,&ra,&ca);
      mm = sub_Xt->m();
      nn = sub_Xt->n();

      sub_mSmt = new unordered_map<int,int>();
      for(int i=0;i<mm;i++) (*sub_mSmt)[i] = (*mSmt)[ra[i]];
      sub_nSmt = new unordered_map<int,int>();
      for(int j=0;j<nn;j++) (*sub_nSmt)[j] = (*nSmt)[ca[j]];

      sub_X[t] = sub_Xt;
      sub_mSm[t] = sub_mSmt;
      sub_nSm[t] = sub_nSmt;

      //clean memory
      delete rSt;
      delete cSt;
      delete [] ra;
      delete [] ca;
   }

   sub_rmap = util_sub(rmap, sub_mS);
   sub_cmap = util_sub(cmap, sub_nS);
   sub_rimap = util_imap(sub_rmap);
   sub_cimap = util_imap(sub_cmap);

	ptr = Panel::instance(sub_T,sub_X,sub_mS,sub_nS,sub_mSm,sub_nSm,sub_rmap,sub_rimap,sub_cmap,sub_cimap);

   //clean memory
   for(list<set<int>*>::iterator it=memL.begin();it!=memL.end();it++) delete *it;

   return ptr;
}

Matrix* Panel::collapse(bool row_flag,
                        set<int>* cS,
                        set<int>* xcS,
                        int** cap) 
{
   myerr_msg("Functionality currently decommissioned due to unresolved row name conflicts in concat function",__FUNCTION__);
   if(!row_flag) myerr_msg("row_flag=false functionality not yet implemented",__FUNCTION__);

	int T = _T;
	Matrix** X = _X;
	set<int>* nS = _nS;
	unordered_map<int,int>** nSm = _nSm;

   int* ca = NULL;
   unordered_map<int,int>* ica = NULL;
   Matrix** cX = NULL;
   Matrix* mat = NULL;
   int nn;

   list<set<int>*> memL;
   set<int>::iterator it;

   if(cS==NULL) { memL.push_back(cS=util_copy(nS));}
   if(xcS==NULL) { memL.push_back(xcS=new set<int>());}

   //construct ca and ica
   {
      ca = new int[cS->size()];
      nn = 0;
      for(it=cS->begin();it!=cS->end();it++) {
         if(xcS->find(*it)==xcS->end()) ca[nn++] = *it;
      }
      ica = util_imap(ca,nn);
   }

   //construct cX
   cX = new Matrix*[T];
   for(int t=0;t<T;t++) {
      Matrix* Xt = X[t];
      unordered_map<int,int>::iterator it;
      int* cat = NULL;
      int nt, jj, nnt;

      cat = new int[nn];
      nt = Xt->n();
      nnt = 0;
      for(int j=0;j<nt;j++) {
         jj = nSm[t]->find(j)->second;
         it = ica->find(jj);
         if(it==ica->end()) continue;
         cat[it->second] = j;
         nnt++;
      }

      if(nnt!=nn) myerr_msg(string("Could not find all columns in matrix t=") + util_string(t),__FUNCTION__);
      cX[t] = Xt->sub(-1,nnt,NULL,cat);

      //clean memory
      delete [] cat;
   }

   //construct mat
   mat = Matrix::concat(true,cX,T);


   if(cap!=NULL) {*cap = ca; ca = NULL;}

   //clean memory
   delete [] ca;
   delete ica;
   for(list<set<int>*>::iterator it=memL.begin();it!=memL.end();it++) delete *it;
   for(int t=0;t<T;t++) delete cX[t];
   delete [] cX;

   return mat;
}

Panel* Panel::copy() {

   int T = this->T();
   Matrix** X = this->X();
   set<int>* mS = this->mS();
   set<int>* nS = this->nS();
   unordered_map<int,int>** mSm = this->mSm();
   unordered_map<int,int>** nSm = this->nSm();
   unordered_map<int,string>* rmap = this->rmap();
   unordered_map<int,string>* cmap = this->cmap();
   unordered_map<string,int>* rimap = this->rimap();
   unordered_map<string,int>* cimap = this->cimap();

   int _T;
   Matrix** _X = NULL;
   set<int>* _mS = NULL;
   set<int>* _nS = NULL;
   unordered_map<int,int>** _mSm = NULL;
   unordered_map<int,int>** _nSm = NULL;
   unordered_map<int,string>* _rmap = NULL;
   unordered_map<int,string>* _cmap = NULL;
   unordered_map<string,int>* _rimap = NULL;
   unordered_map<string,int>* _cimap = NULL;
   Panel* Y = NULL;

   _T = T;
   _X = new Matrix*[T];
   for(int t=0;t<T;t++) _X[t] = X[t]->copy();
   _mS = util_copy(mS);
   _nS = util_copy(nS);
   _mSm = util_copy(mSm,T);
   _nSm = util_copy(nSm,T);
   _rmap = util_copy(rmap);
   _cmap = util_copy(cmap);
   _rimap = util_copy(rimap);
   _cimap = util_copy(cimap);

	Y = Panel::instance(_T,_X,_mS,_nS,_mSm,_nSm,_rmap,_rimap,_cmap,_cimap);

   return Y;
}

#endif

