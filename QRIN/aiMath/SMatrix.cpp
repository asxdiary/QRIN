// Name:     SMatrix.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_SMatrix_cpp
#define ASX_SMatrix_cpp


#include <stdio.h>
#include <math.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Model.hpp"
#include "SMatrix.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMath;

/** --------------Constructors and init_NULL-----------*/

SMatrix::SMatrix() { init_NULL(); }
SMatrix::SMatrix(const SMatrix* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
SMatrix::SMatrix(const SMatrix& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void SMatrix::init_NULL()	{
	_X=NULL;
	_rmap=NULL;
	_rimap=NULL;
	_cmap=NULL;
	_cimap=NULL;
}

/** ---Public Data Setting Functions-----------------*/

void SMatrix::set_rmap_rimap(string* omap, unordered_map<string,int>* imap) {
   const int num = _m;
   util_map_imap(omap, imap, num);
   cleanMem_rmap(); cleanMem_rimap();
   _rmap = omap; _rimap = imap;
}

void SMatrix::set_cmap_cimap(string* omap, unordered_map<string,int>* imap) {
   const int num = _n;
   util_map_imap(omap, imap, num);
   cleanMem_cmap(); cleanMem_cimap();
   _cmap = omap; _cimap = imap;
}


/** --------   Init Functions -------------------------*/

void SMatrix::init(const int m, const int n, string** X, 
                     string* rmap, 
                     unordered_map<string,int>* rimap, 
                     string* cmap, 
                     unordered_map<string,int>* cimap)
{
   Model::init();
	init_SMatrix(m,n,X,rmap,rimap,cmap,cimap);
}

void SMatrix::init_SMatrix(const int m, const int n, string** X, 
                         string* rmap, 
                         unordered_map<string,int>* rimap, 
                         string* cmap, 
                         unordered_map<string,int>* cimap)
{
   init_m(m);
	init_n(n);
	init_X(X);
	init_rmap_rimap(rmap, rimap);
	init_cmap_cimap(cmap, cimap);
}

void SMatrix::init_m(const int obj) {
   _m = obj;
}

void SMatrix::init_n(const int obj) {
   _n = obj;
}

void SMatrix::init_X(string** obj) {
   _X = obj;
}

void SMatrix::init_rmap_rimap(string* omap, unordered_map<string,int>* imap) {
   set_rmap_rimap(omap, imap);
}

void SMatrix::init_cmap_cimap(string* omap, unordered_map<string,int>* imap) {
   set_cmap_cimap(omap, imap);
}

/** -----Destructors and Memory Cleanup functions -----*/

SMatrix::~SMatrix()	{ cleanMem(); }

void SMatrix::cleanMem()	{
	cleanMem_SMatrix();
   Model::cleanMem();
}

void SMatrix::cleanMem_SMatrix() {
	cleanMem_X();
	cleanMem_rmap();
	cleanMem_rimap();
	cleanMem_cmap();
	cleanMem_cimap();
}

void SMatrix::cleanMem_X() {
   util_clean(_X,_m,_n);
	_X=NULL;
}

void SMatrix::cleanMem_rmap() {
   delete [] _rmap;
	_rmap=NULL;
}

void SMatrix::cleanMem_rimap() {
   delete _rimap;
	_rimap=NULL;
}

void SMatrix::cleanMem_cmap() {
   delete [] _cmap;
	_cmap=NULL;
}

void SMatrix::cleanMem_cimap() {
   delete _cimap;
	_cimap=NULL;
}

/** ------------- Data Access Functions --------------------*/

int SMatrix::m() {return _m;}
int SMatrix::n() {return _n;}
string** SMatrix::X() {return _X;}
string* SMatrix::rmap() {return _rmap;}
unordered_map<string,int>* SMatrix::rimap() {return _rimap;}
string* SMatrix::cmap() {return _cmap;}
unordered_map<string,int>* SMatrix::cimap() {return _cimap;}

/** ------------- Access classname dynamically --------------------*/

string SMatrix::className() const {return "SMatrix";}

/** ------------- Error Message Handling Functions ------------------*/

void SMatrix::myerr_msg(string msg, string func) {
	err_msg("SMatrix::",func," ",msg);
}

void SMatrix::mywarn_msg(string msg, string func) {
	warn_msg("SMatrix::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void SMatrix::fprint(string fname) {
   Model::fprint(fname);
   fprint_SMatrix(fname);
}

void SMatrix::fprint_SMatrix(string fname) {
   util_ofprint(fname,"X",_X,_m,_n);
   util_ofprint(fname,"m",_m);
   util_ofprint(fname,"n",_n);
   util_ofprint(fname,"rmap",_rmap,_m);
   util_ofprint(fname,"rimap",_rimap);
   util_ofprint(fname,"cmap",_cmap,_n);
   util_ofprint(fname,"cimap",_cimap);
   return;
}

void SMatrix::fscan(string fname) {
   Model::fscan(fname);
   fscan_SMatrix(fname);
}

void SMatrix::fscan_SMatrix(string fname) {
   int m1,n1,m2,n2;
   m1 = m2 = n1 = n2 = -1;

   util_ofscan(fname,"m",_m);
   util_ofscan(fname,"n",_n);
   util_ofscan(fname,"X",_X,m1,n1);
   util_ofscan(fname,"rmap",_rmap,m2);
   util_ofscan(fname,"rimap",_rimap);
   util_ofscan(fname,"cmap",_cmap,n2);
   util_ofscan(fname,"cimap",_cimap);

   //check 
   if(_m!=m1) myerr_msg("_m != m1",__FUNCTION__);
   if(_n!=n1) myerr_msg("_n != n1",__FUNCTION__);
   if((_rmap!=NULL) && (_m!=m2)) myerr_msg("_m != m2",__FUNCTION__);
   if((_cmap!=NULL) && (_n!=n2)) myerr_msg("_n != n2",__FUNCTION__);
   return;
}

/** ------------- Reset Functions --------------------*/

void SMatrix::reset() {
	reset_SMatrix();
   Model::reset();
}

void SMatrix::reset_SMatrix() {
}

/** ----------  static instance function -----------*/

void SMatrix::cerr_msg(string msg, string func) {
	err_msg("SMatrix::",func," ",msg);
}

void SMatrix::cwarn_msg(string msg, string func) {
	warn_msg("SMatrix::",func," ",msg);
}

SMatrix* SMatrix::instance(const int m, const int n, string** X,	
                         string* rmap, 
                         unordered_map<string,int>* rimap, 
                         string* cmap, 
                         unordered_map<string,int>* cimap)
{
   SMatrix* ptr=NULL;
   int val;

   if(rmap!=NULL && rimap!=NULL) cerr_msg("rmap!=NULL && rimap!=NULL",__FUNCTION__);
   if(cmap!=NULL && cimap!=NULL) cerr_msg("cmap!=NULL && cimap!=NULL",__FUNCTION__);
   
   ptr = new SMatrix();
   if(X==NULL) X = util_matrix(m,n,string(""));
   ptr->init(m,n,X,rmap,rimap,cmap,cimap);
   if((val=ptr->chk())!=0) cerr_msg(string("ptr->chk() failed val = ") + util_string(val),__FUNCTION__);
   return ptr;
}

SMatrix* SMatrix::instance_fscan(string fname, const bool raw, string delimiter) {
   SMatrix* ptr = NULL;
   int val;

   if(!raw && !util_fscan_NULL(fname)) {
      ptr = new SMatrix();
      ptr->fscan(fname);
   }
   else if(raw) {
      string** X = NULL;
      string* cmap = NULL;
      int m,n;
      util_fscan(fname,X,m,n,delimiter,1,&cmap);
      ptr = SMatrix::instance(m,n,X);
      ptr->set_cmap_cimap(cmap,NULL);
   }
   if(ptr!=NULL && (val=ptr->chk())!=0) cerr_msg(string("ptr->chk() failed val = ") + util_string(val),__FUNCTION__);
   return ptr;
}

/** ----------  Non-standard functions start here -----------*/

SMatrix* SMatrix::copy() {
	int m = util_copy(this->m());
	int n = util_copy(this->n());
	string** X = util_copy(this->X(),m,n);
	string* rmap = util_copy(this->rmap(),m);
	unordered_map<string,int>* rimap = NULL;
	string* cmap = util_copy(this->cmap(),n);
	unordered_map<string,int>* cimap = NULL;
   SMatrix* ptr = NULL;

   ptr = SMatrix::instance(m,n,X,rmap,rimap,cmap,cimap);

   return ptr;
}

void SMatrix::copy(const bool row_flag, const int k, string*& vec) {
   const int m = this->m();
   const int n = this->n();
   string** X = this->X();

   if(row_flag) {
      if(vec==NULL) vec = new string[n];
      for(int j=0;j<n;j++) vec[j] = X[k][j];
   }
   else {
      if(vec==NULL) vec = new string[m];
      for(int i=0;i<m;i++) vec[i] = X[i][k];
   }

   return;
}

void SMatrix::copyrow(const int k, string*& vec) {this->copy(true,k,vec);}
void SMatrix::copycol(const int k, string*& vec) {this->copy(false,k,vec);}

bool SMatrix::isEqual(SMatrix* mat) {return SMatrix::isEqual(this,mat);}

SMatrix* SMatrix::transpose(SMatrix* mat) {
   SMatrix* ptr = mat->copy();
   ptr->_transpose();
   return ptr;
}

void SMatrix::_transpose() {
	int m;
	int n;
	string** X = NULL;
	string* rmap = NULL;
	unordered_map<string,int>* rimap = NULL;
	string* cmap = NULL;
	unordered_map<string,int>* cimap = NULL;

   m = this->n();
   n = this->m();
   X = util_transpose(this->X(), this->m(), this->n());
   rmap = util_copy(cmap);
   rimap = util_copy(cimap);
   cmap = util_copy(rmap);
   cimap = util_copy(rimap);

   cleanMem();
   init(m,n,X,rmap,rimap,cmap,cimap);

   return;
}

void SMatrix::assign(SMatrix* mat, int* _ra, int* _ca) {
   const int m = mat->m();
   const int n = mat->n();
   string** matX = mat->X();
   int* ra = _ra;
   int* ca = _ca;

   if(ra==NULL) ra = util_rangeA(0,m);
   if(ca==NULL) ca = util_rangeA(0,n);

   for(int i=0;i<m;i++) {
      for(int j=0;j<n;j++) _X[ra[i]][ca[j]] = matX[i][j];
   }

   if(_ra==NULL) delete [] ra;
   if(_ca==NULL) delete [] ca;

   return;
}

bool SMatrix::isEqual(SMatrix* mat1, SMatrix* mat2) {
   if(mat1==NULL && mat2==NULL) return true;
   else if(mat1==NULL || mat2==NULL) return false;

   bool flag = true;

   for(;;) {
      const int m = mat1->m();
      const int n = mat1->n();
      flag = util_isEqual(mat1->m(),mat2->m()); if(!flag) break;
      flag = util_isEqual(mat1->n(),mat2->n()); if(!flag) break;
      flag = util_isEqual(mat1->X(),mat2->X(),m,n); if(!flag) break;
      break;
   }

   return flag;
}

SMatrix** SMatrix::SMatrix_array(SMatrix* mat1, SMatrix* mat2) {
   const int K = 2;
   SMatrix** mat = NULL;
   int t;

   mat = new SMatrix*[K];
   t = 0;
   mat[t++] = mat1;
   mat[t++] = mat2;

   return mat;
}

SMatrix** SMatrix::SMatrix_array(SMatrix* mat1, SMatrix* mat2, SMatrix* mat3) {
   const int K = 3;
   SMatrix** mat = NULL;
   int t;

   mat = new SMatrix*[K];
   t = 0;
   mat[t++] = mat1;
   mat[t++] = mat2;
   mat[t++] = mat3;

   return mat;
}

SMatrix* SMatrix::sub(int mm, int nn, int* ra, int*ca) 
{
   const int m = this->m();
   const int n = this->n();
   string** X = this->X();

   string** XX = NULL;
   SMatrix* mat = NULL;
	string* rmap_ = NULL;
	unordered_map<string,int>* rimap_ = NULL;
	string* cmap_ = NULL;
	unordered_map<string,int>* cimap_ = NULL;
   int* _ra = NULL;
   int* _ca = NULL;

   if(ra==NULL) {ra = _ra = util_rangeA(0,mm=m);}
   if(ca==NULL) {ca = _ca = util_rangeA(0,nn=n);}

   XX = util_matrix(mm,nn,string(""));

   for(int i=0;i<mm;i++) {
      for(int j=0;j<nn;j++) XX[i][j] = X[ra[i]][ca[j]];
   }

   rmap_ = util_sub(_rmap, m, ra, mm);
   cmap_ = util_sub(_cmap, n, ca, nn);

   mat = SMatrix::instance(mm,nn,XX,rmap_,rimap_,cmap_,cimap_);

   //clean memory
   delete [] _ra;
   delete [] _ca;

   return mat;
}

SMatrix* SMatrix::sub(set<int>* rS, set<int>* cS, set<int>* xrS, set<int>* xcS,
                    int** rap, int** cap) 
{
   list<set<int>*> memL;
   const int m = this->m();
   const int n = this->n();

   int mm, nn;
   SMatrix* mat = NULL;

   int* ra = NULL;
   int* ca = NULL;

   if(rS==NULL) { memL.push_back(rS=util_rangeS(0,m));}
   if(cS==NULL) { memL.push_back(cS=util_rangeS(0,n));}
   if(xrS==NULL) { memL.push_back(xrS=new set<int>());}
   if(xcS==NULL) { memL.push_back(xcS=new set<int>());}

   ra = new int[m]; mm = 0;
   for(set<int>::iterator it=rS->begin();it!=rS->end();it++) {
      if(xrS->find(*it)==xrS->end()) ra[mm++] = *it;
   }

   ca = new int[n]; nn = 0;
   for(set<int>::iterator it=cS->begin();it!=cS->end();it++) {
      if(xcS->find(*it)==xcS->end()) ca[nn++] = *it;
   }

   mat = this->sub(mm,nn,ra,ca);

   if(rap!=NULL) {
      (*rap) = new int[mm];
      for(int i=0;i<mm;i++) (*rap)[i] = ra[i];
   }

   if(cap!=NULL) {
      (*cap) = new int[nn];
      for(int j=0;j<nn;j++) (*cap)[j] = ca[j];
   }

   //clean memory
   delete [] ra;
   delete [] ca;
   for(list<set<int>*>::iterator it=memL.begin();it!=memL.end();it++) delete *it;

   return mat;
}

int SMatrix::chk() {
   int val = Model::chk();
   if(_X==NULL) val++;
   if(_rimap!=NULL && ((int)_rimap->size())!=_m) val++;
   if(_cimap!=NULL && ((int)_cimap->size())!=_n) val++;
   return val;
}

SMatrix* SMatrix::concat(const bool row_flag, SMatrix** xA, const int T) {
   if(!row_flag) cerr_msg("Functionality not yet implemented for row_flag=false",__FUNCTION__);

   SMatrix* mat = NULL;
   string** X = NULL;
   int m,n;

   m = 0; n = xA[0]->n();
   for(int t=0;t<T;t++) m += xA[t]->m();

   X = util_matrix(m,n,string(""));
   for(int t=0, ii=0;t<T;t++) {
      int mt = xA[t]->m();
      int nt = xA[t]->n();
      string** Xt = xA[t]->X();

      if(nt!=n) cerr_msg("nt!=n",__FUNCTION__);

      for(int i=0;i<mt;i++) {
         for(int j=0;j<nt;j++) X[ii][j] = Xt[i][j];
         ii++;
      }
   }

   mat = SMatrix::instance(m,n,X);

   return mat;
}

set<int>* SMatrix::rnzS(const int j) {
   set<int>* S = NULL;
   const int m = this->m();
   const int n = this->n();
   string** X = this->X();

   if(j<0 || j>n) myerr_msg("j<0 || j>n",__FUNCTION__);
   S = new set<int>();

   for(int i=0;i<m;i++) {
      if(X[i][j].compare("")==0) continue;
      S->insert(i);
   }

   return S;
}


set<int>* SMatrix::cnzS(const int i) {
   set<int>* S = NULL;
   const int m = this->m();
   const int n = this->n();
   string** X = this->X();

   if(i<0 || i>m) myerr_msg("i<0 || i>m",__FUNCTION__);
   S = new set<int>();

   for(int j=0;j<n;j++) {
      if(X[i][j].compare("")==0) continue;
      S->insert(j);
   }

   return S;
}

SMatrix* SMatrix::lift(int mm, int nn, int* ra, int* ca) {
   const int m = this->m();
   const int n = this->n();
   string** X = this->X();

   string** XX = NULL;
   SMatrix* mat = NULL;
   int* _ra = NULL;
   int* _ca = NULL;

   if(ra==NULL) {ra = _ra = util_rangeA(0,mm=m);}
   if(ca==NULL) {ca = _ca = util_rangeA(0,nn=n);}

   XX = util_matrix(mm,nn,string(""));

   for(int i=0;i<m;i++) {
      for(int j=0;j<n;j++)  XX[ra[i]][ca[j]] = X[i][j];
   }

   mat = SMatrix::instance(mm,nn,XX);

   //clean memory
   delete [] _ra;
   delete [] _ca;

   return mat;
}

void SMatrix::fprint_raw(string fname) {
   int m = this->m();
   int n = this->n();
	string* _rmap = this->rmap();
	string* _cmap = this->cmap();

   SMatrix* lmat = NULL;
   string** lmatX = NULL;
   int* ra = NULL;
   int* ca = NULL;
   int mm, nn, rval, cval;

   rval = cval = 0;
   if(_cmap!=NULL) rval++;
   if(_rmap!=NULL) cval++;

   mm = m + rval;
   nn = n + cval;

   ra = new int[m];
   ca = new int[n];

   for(int i=0;i<m;i++) ra[i] = rval + i;
   for(int j=0;j<n;j++) ca[j] = cval + j;

   lmat = this->lift(mm,nn,ra, ca);
   lmatX = lmat->X();
   
   if(_rmap!=NULL && _cmap!=NULL) lmatX[0][0] = "RowIdentifiers";
   if(_rmap!=NULL) {
      for(int i=0;i<m;i++) lmatX[i][0] = _rmap[i];
   }
   if(_cmap!=NULL) {
      for(int j=0;j<n;j++) lmatX[0][j] = _cmap[j];
   }

   util_fprint(fname,lmatX,mm,nn);

   //clean memory
   delete lmat;
   delete [] ra;
   delete [] ca;

   return;
}

SMatrix* SMatrix::instance(list<unordered_map<string,string>*>* L, set<string>* headerS) {
   if(L==NULL) return NULL;
   int m, n;
   string* cmap = NULL;
   SMatrix* mat = NULL;
   string** X = NULL;
   bool headerS_flag = (headerS==NULL);

   //create the header
   if(headerS_flag) {
      list<unordered_map<string,string>*>::iterator it;
      headerS = new set<string>();
      for(it=L->begin();it!=L->end();it++) util_keys(*it,headerS);
   }

   cmap = util_array(headerS);

   m = L->size();
   n = headerS->size();
   mat = SMatrix::instance(m,n);
   mat->set_cmap_cimap(cmap,NULL);
   X = mat->X();

   {
      unordered_map<string,int>* cimap = mat->cimap();
      list<unordered_map<string,string>*>::iterator it;
      unordered_map<string,string>::iterator it2;
      unordered_map<string,int>::iterator it3;
      string key, val;
      int i, j;

      for(i=0, it=L->begin();it!=L->end();it++, i++) {
         unordered_map<string,string>* m = *it;

         for(it2=m->begin();it2!=m->end();it2++) {
            key = it2->first;
            val = it2->second;
            it3 = cimap->find(key);
            if(it3==cimap->end()) err_msg(key," not found in the header","aiMath::SMatrix::instance");
            j = it3->second;
            X[i][j] = val;
         }
      }
   }

   if(headerS_flag) delete headerS;

   return mat;
}


#endif

