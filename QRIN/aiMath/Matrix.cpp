// Name:     Matrix.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_Matrix_cpp
#define ASX_Matrix_cpp


#include <stdio.h>
#include <math.h>
#include <algorithm>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Model.hpp"
#include "pkgMath.hpp"
#include "Matrix.hpp"
#include "MathUtils.hpp"
#include "StatUtils.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMath;
using namespace aiMathUtils;
using namespace aiStatUtils;

/** --------------Constructors and init_NULL-----------*/

Matrix::Matrix() { init_NULL(); }
Matrix::Matrix(const Matrix* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
Matrix::Matrix(const Matrix& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void Matrix::init_NULL()	{
	_X=NULL;
	_rmap=NULL;
	_rimap=NULL;
	_cmap=NULL;
	_cimap=NULL;
}

/** ---Public Data Setting Functions-----------------*/

void Matrix::set_rmap_rimap(string* omap, unordered_map<string,int>* imap) {
   if(omap==NULL && imap==NULL) myerr_msg("omap==NULL && imap==NULL",__FUNCTION__);
   const int num = _m;
   util_map_imap(omap, imap, num);
   cleanMem_rmap(); cleanMem_rimap();
   _rmap = omap; _rimap = imap;
}

void Matrix::set_cmap_cimap(string* omap, unordered_map<string,int>* imap) {
   if(omap==NULL && imap==NULL) myerr_msg("omap==NULL && imap==NULL",__FUNCTION__);
   const int num = _n;
   util_map_imap(omap, imap, num);
   cleanMem_cmap(); cleanMem_cimap();
   _cmap = omap; _cimap = imap;
}

void Matrix::set_rmap_rimap(const int i, string val) {
   unordered_map<string,int>::iterator it;
   it = _rimap->find(val);
   if(it!=_rimap->end() && it->second!=i) myerr_msg("unique name violation val = " + val,__FUNCTION__);

   _rimap->erase( _rmap[i] );
   _rmap[i] = val;
   (*_rimap)[val] = i;
   return;
}

void Matrix::set_cmap_cimap(const int i, string val) {
   unordered_map<string,int>::iterator it;
   it = _cimap->find(val);
   if(it!=_cimap->end() && it->second!=i) myerr_msg("unique name violation val = " + val,__FUNCTION__);

   _cimap->erase( _cmap[i] );
   _cmap[i] = val;
   (*_cimap)[val] = i;
   return;
}


/** --------   Init Functions -------------------------*/

void Matrix::init(const int m, const int n, double** X, 
                     string* rmap, 
                     unordered_map<string,int>* rimap, 
                     string* cmap, 
                     unordered_map<string,int>* cimap)
{
   Model::init();
	init_Matrix(m,n,X,rmap,rimap,cmap,cimap);
}

void Matrix::init_Matrix(const int m, const int n, double** X, 
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

void Matrix::init_m(const int obj) {
   _m = obj;
}

void Matrix::init_n(const int obj) {
   _n = obj;
}

void Matrix::init_X(double** obj) {
   _X = obj;
}

void Matrix::init_rmap_rimap(string* omap, unordered_map<string,int>* imap) {
   set_rmap_rimap(omap, imap);
}

void Matrix::init_cmap_cimap(string* omap, unordered_map<string,int>* imap) {
   set_cmap_cimap(omap, imap);
}

/** -----Destructors and Memory Cleanup functions -----*/

Matrix::~Matrix()	{ cleanMem(); }

void Matrix::cleanMem()	{
	cleanMem_Matrix();
   Model::cleanMem();
}

void Matrix::cleanMem_Matrix() {
	cleanMem_X();
	cleanMem_rmap();
	cleanMem_rimap();
	cleanMem_cmap();
	cleanMem_cimap();
}

void Matrix::cleanMem_X() {
   util_clean(_X,_m,_n);
	_X=NULL;
}

void Matrix::cleanMem_rmap() {
   delete [] _rmap;
	_rmap=NULL;
}

void Matrix::cleanMem_rimap() {
   delete _rimap;
	_rimap=NULL;
}

void Matrix::cleanMem_cmap() {
   delete [] _cmap;
	_cmap=NULL;
}

void Matrix::cleanMem_cimap() {
   delete _cimap;
	_cimap=NULL;
}

/** ------------- Data Access Functions --------------------*/

int Matrix::m() {return _m;}
int Matrix::n() {return _n;}
double** Matrix::X() {return _X;}
string* Matrix::rmap() {return _rmap;}
unordered_map<string,int>* Matrix::rimap() {return _rimap;}
string* Matrix::cmap() {return _cmap;}
unordered_map<string,int>* Matrix::cimap() {return _cimap;}

/** ------------- Access classname dynamically --------------------*/

string Matrix::className() const {return "Matrix";}

/** ------------- Error Message Handling Functions ------------------*/

void Matrix::myerr_msg(string msg, string func) {
	err_msg("Matrix::",func," ",msg);
}

void Matrix::mywarn_msg(string msg, string func) {
	warn_msg("Matrix::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void Matrix::fprint(string fname) {
   Model::fprint(fname);
   fprint_Matrix(fname);
}

void Matrix::fprint_Matrix(string fname) {
   this->fprint_table(util_ofname(fname,"X"));
   return;
}

void Matrix::fscan(string fname) {
   Model::fscan(fname);
   fscan_Matrix(fname);
}

void Matrix::fscan_Matrix(string fname) {
   string delimiter = Global::instance()->delimiter();
   string* cmap = NULL;
   string* rmap = NULL;

   if(util_fscan_NULL(fname)) myerr_msg("util_fscan_NULL(fname)",__FUNCTION__);
   fname = util_ofname(fname,"X");
   util_fscan(fname,_X,_m,_n,delimiter,1,&cmap,1,&rmap);
   set_rmap_rimap(rmap, NULL);
   set_cmap_cimap(cmap, NULL);

   return;
}

/** ------------- Reset Functions --------------------*/

void Matrix::reset() {
	reset_Matrix();
   Model::reset();
}

void Matrix::reset_Matrix() {
}

/** ----------  static instance function -----------*/

void Matrix::cerr_msg(string msg, string func) {
	err_msg("Matrix::",func," ",msg);
}

void Matrix::cwarn_msg(string msg, string func) {
	warn_msg("Matrix::",func," ",msg);
}

Matrix* Matrix::instance2(const int m, const int n, double** X) {
   return Matrix::instance(m, n, X, NULL, NULL, NULL, NULL, false);
}
 

Matrix* Matrix::instance(const int m, const int n, double** X,	
                         string* rmap, 
                         unordered_map<string,int>* rimap, 
                         string* cmap, 
                         unordered_map<string,int>* cimap,
                         bool rand_names_flag)
{
   Matrix* ptr=NULL;
   int val, num;

   if(rmap!=NULL && rimap!=NULL) cerr_msg("rmap!=NULL && rimap!=NULL",__FUNCTION__);
   if(cmap!=NULL && cimap!=NULL) cerr_msg("cmap!=NULL && cimap!=NULL",__FUNCTION__);

   if(rand_names_flag) num = 8;
   else num = 0;
   
   ptr = new Matrix();
   if(X==NULL) X = util_matrix(m,n,(double)0);
   if(rmap==NULL && rimap==NULL) rmap = util_names("row"+statutil_rand_str(num),m);
   if(cmap==NULL && cimap==NULL) cmap = util_names("col"+statutil_rand_str(num),n);

   ptr->init(m,n,X,rmap,rimap,cmap,cimap);
   if((val=ptr->chk())!=0) cerr_msg(string("ptr->chk() failed val = ") + util_string(val),__FUNCTION__);
   return ptr;
}

Matrix* Matrix::instance_fscan(string fname, const bool raw) {
   Matrix* ptr = NULL;
   int val;

   if(!raw && !util_fscan_NULL(fname)) {
      ptr = new Matrix();
      ptr->init_NULL();
      ptr->fscan(fname);
   }
   else if(raw) {
      double** X = NULL;
      int m,n;
      util_fscan(fname,X,m,n);
      ptr = Matrix::instance(m,n,X);
   }
   if(ptr!=NULL && (val=ptr->chk())!=0) cerr_msg(string("ptr->chk() failed val = ") + util_string(val),__FUNCTION__);
   return ptr;
}

Matrix* Matrix::identity(const int n) {
   Matrix* ptr = Matrix::instance(n,n);
   double** X = ptr->X();
   for(int i=0;i<n;i++) X[i][i] = 1.0;
   return ptr;
}

/** ----------  Non-standard functions start here -----------*/

Matrix* Matrix::copy() {
	int m = util_copy(this->m());
	int n = util_copy(this->n());
	double** X = util_copy(this->X(),m,n);
	string* rmap = util_copy(this->rmap(),m);
	unordered_map<string,int>* rimap = NULL;
	string* cmap = util_copy(this->cmap(),n);
	unordered_map<string,int>* cimap = NULL;
   Matrix* ptr = NULL;

   ptr = Matrix::instance(m,n,X,rmap,rimap,cmap,cimap);

   return ptr;
}

void Matrix::copy(const bool row_flag, const int k, double*& vec) {
   const int m = this->m();
   const int n = this->n();
   double** X = this->X();

   if(row_flag) {
      if(vec==NULL) vec = new double[n];
      for(int j=0;j<n;j++) vec[j] = X[k][j];
   }
   else {
      if(vec==NULL) vec = new double[m];
      for(int i=0;i<m;i++) vec[i] = X[i][k];
   }

   return;
}

void Matrix::copyrow(const int k, double*& vec) {this->copy(true,k,vec);}
void Matrix::copycol(const int k, double*& vec) {this->copy(false,k,vec);}

void Matrix::_add(const double fac) {
   const int m = this->m();
   const int n = this->n();
   double** X = NULL;

   X = this->X();

   for(int i=0;i<m;i++) {
      for(int j=0;j<n;j++) X[i][j] += fac;
   }

   return;
}

void Matrix::_mult(const double fac) {
   this->_hmult(fac);
   return;
}

void Matrix::_hmult(const double fac) {
   const int m = this->m();
   const int n = this->n();
   double** X = NULL;

   X = this->X();

   for(int i=0;i<m;i++) {
      for(int j=0;j<n;j++) X[i][j] *= fac;
   }

   return;
}

void Matrix::_hpow(const double eta) {
   const int m = this->m();
   const int n = this->n();
   double** X = NULL;

   X = this->X();

   for(int i=0;i<m;i++) {
      for(int j=0;j<n;j++) X[i][j] = pow(X[i][j],eta);
   }

   return;
}

void Matrix::_hlog() {
   const int m = this->m();
   const int n = this->n();
   double** X = NULL;

   X = this->X();

   for(int i=0;i<m;i++) {
      for(int j=0;j<n;j++) X[i][j] = log(X[i][j]);
   }

   return;
}

void Matrix::_hexp() {
   const int m = this->m();
   const int n = this->n();
   double** X = NULL;

   X = this->X();

   for(int i=0;i<m;i++) {
      for(int j=0;j<n;j++) X[i][j] = exp(X[i][j]);
   }

   return;
}

void Matrix::_habs() {
   const int m = this->m();
   const int n = this->n();
   double** X = NULL;

   X = this->X();

   for(int i=0;i<m;i++) {
      for(int j=0;j<n;j++) X[i][j] = fabs(X[i][j]);
   }

   return;
}

Matrix* Matrix::mult(Matrix* mat, const double fac) {
   Matrix* ptr = mat->copy();
   ptr->_mult(fac);
   return ptr;
}

bool Matrix::isEqual(Matrix* mat, bool permute_rows, bool permute_cols,
                     bool chk_rnames, bool chk_cnames) 
{
   return Matrix::isEqual(this,mat,permute_rows,permute_cols, chk_rnames, chk_cnames);
}

Matrix* Matrix::transpose(Matrix* mat) {
   Matrix* ptr = mat->copy();
   ptr->_transpose();
   return ptr;
}

void Matrix::_chmult(Matrix* Delta, bool inv_flag) {this->_hmult(false, Delta, inv_flag);}
void Matrix::_rhmult(Matrix* Delta, bool inv_flag) {this->_hmult(true, Delta, inv_flag);}

Matrix* Matrix::chmult(Matrix* mat, Matrix* Delta, bool inv_flag) {
   Matrix* ptr = mat->copy();
   ptr->_hmult(false, Delta, inv_flag);
   return ptr;
}

Matrix* Matrix::rhmult(Matrix* mat, Matrix* Delta, bool inv_flag) {
   Matrix* ptr = mat->copy();
   ptr->_hmult(true, Delta, inv_flag);
   return ptr;
}

void Matrix::_transpose() {
	int m;
	int n;
	double** X = NULL;
	string* rmap = NULL;
	unordered_map<string,int>* rimap = NULL;
	string* cmap = NULL;
	unordered_map<string,int>* cimap = NULL;

   m = this->n();
   n = this->m();
   X = util_transpose(this->X(), this->m(), this->n());
   rmap = util_copy(this->cmap(), this->n());
   cmap = util_copy(this->rmap(), this->m());

   cleanMem();
   init(m,n,X,rmap,rimap,cmap,cimap);

   return;
}

void Matrix::assign(Matrix* mat, int* _ra, int* _ca) {
   const int m = mat->m();
   const int n = mat->n();
   double** matX = mat->X();
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

Matrix* Matrix::instance_col(const double val) {
   const int m = 1;
   const int n = 1;
   double** X = NULL;
   int t;

   X = util_matrix(m,n,double(0));

   t = 0;
   X[t++][0] = val;

   return Matrix::instance(m,n,X);
}

Matrix* Matrix::instance_col(const double val1, const double val2) {
   const int m = 2;
   const int n = 1;
   double** X = NULL;
   int t;

   X = util_matrix(m,n,double(0));

   t = 0;
   X[t++][0] = val1;
   X[t++][0] = val2;

   return Matrix::instance(m,n,X);
}

Matrix* Matrix::instance_col(const double val1, const double val2, const double val3) {
   const int m = 3;
   const int n = 1;
   double** X = NULL;
   int t;

   X = util_matrix(m,n,double(0));

   t = 0;
   X[t++][0] = val1;
   X[t++][0] = val2;
   X[t++][0] = val3;

   return Matrix::instance(m,n,X);
}

bool Matrix::isEqual(Matrix* mat1, Matrix* mat2, bool permute_rows, bool permute_cols,
                     bool chk_rnames, bool chk_cnames)
{
   if(mat1==NULL && mat2==NULL) return true;
   else if(mat1==NULL || mat2==NULL) return false;

   int m1 = mat1->m();
   int n1 = mat1->n();
   double** X1 = mat1->X();
   int m2 = mat2->m();
   int n2 = mat2->n();
   double** X2 = mat2->X();
   string* rmap1 = mat1->rmap();
   string* cmap1 = mat1->cmap();
   string* rmap2 = mat2->rmap();
   string* cmap2 = mat2->cmap();
   unordered_map<string,int>* rimap2 = mat2->rimap();
   unordered_map<string,int>* cimap2 = mat2->cimap();
   unordered_map<string,int>::iterator it2;
   int i2, j2;

   if(m1!=m2 || n1!=n2) return false;
   if(permute_rows && (rmap1==NULL || rimap2==NULL)) return false;
   if(permute_cols && (cmap1==NULL || cimap2==NULL)) return false;

   for(int i1=0;i1<m1;i1++) {
      if(!permute_rows) i2=i1;
      else {
         it2 = rimap2->find(rmap1[i1]);
         if(it2==rimap2->end()) return false;
         else i2 = it2->second;
      }

      for(int j1=0;j1<n1;j1++) {
         if(!permute_cols) j2=j1;
         else {
            it2 = cimap2->find(cmap1[j1]);
            if(it2==cimap2->end()) return false;
            else j2 = it2->second;
         }

         if(! util_isEqual(X1[i1][j1],X2[i2][j2])) return false;
      }
   }

   if(!permute_rows && chk_rnames && !util_isEqual(rmap1, rmap2, m1)) return false;
   if(!permute_cols && chk_cnames && !util_isEqual(cmap1, cmap2, n1)) return false;

   return true;
}

Matrix* Matrix::lc(Matrix** mat, Matrix* w) {
   Matrix* rep = NULL;
   Matrix* ptr = NULL;
   int m,n,K;

   rep = mat[0];
   m = rep->m();
   n = rep->n();
   K = w->m();

   //check for consistency
   {
      int t;
      bool flag = true;

      for(t=0;t<K && flag;t++) {
         if(m!=mat[t]->m()) flag = false;
         if(n!=mat[t]->n()) flag = false;
      }

      if(!flag) err_msg(__FUNCTION__,": Incompatible Matrices t=",util_string(t));
   }

   {
      double** X = NULL;
      double** Xt = NULL;
      double** wX = NULL;

      ptr = Matrix::instance(m,n);
      X = ptr->X();
      wX = w->X();

      for(int t=0;t<K;t++) {
         Xt = mat[t]->X();
         for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) X[i][j] += wX[t][0] * Xt[i][j];
         }
      }
   }

   //copy the row and column names from the first matrix
   {
      string* rmap = mat[0]->rmap();
      unordered_map<string,int>* rimap = mat[0]->rimap();
      string* cmap = mat[0]->cmap();
      unordered_map<string,int>* cimap = mat[0]->cimap();

      ptr->set_rmap_rimap(util_copy(rmap,m),util_copy(rimap));
      ptr->set_cmap_cimap(util_copy(cmap,n),util_copy(cimap));
   }

   return ptr;
}

Matrix* Matrix::add(Matrix* mat1, Matrix* mat2) {
   Matrix** mat = NULL;
   Matrix* ptr = NULL;
   Matrix* w = NULL;

   w = instance_col(1,1);
   mat = Matrix_array(mat1, mat2);
   ptr = lc(mat,w);

   //clean memory
   delete w;
   delete [] mat;

   return ptr;
}

Matrix* Matrix::subtract(Matrix* mat1, Matrix* mat2) {
   Matrix** mat = NULL;
   Matrix* ptr = NULL;
   Matrix* w = NULL;

   w = instance_col(1,-1);
   mat = Matrix_array(mat1, mat2);
   ptr = lc(mat,w);

   //clean memory
   delete w;
   delete [] mat;

   return ptr;
}

Matrix** Matrix::Matrix_array(Matrix* mat1, Matrix* mat2) {
   const int K = 2;
   Matrix** mat = NULL;
   int t;

   mat = new Matrix*[K];
   t = 0;
   mat[t++] = mat1;
   mat[t++] = mat2;

   return mat;
}

Matrix** Matrix::Matrix_array(Matrix* mat1, Matrix* mat2, Matrix* mat3) {
   const int K = 3;
   Matrix** mat = NULL;
   int t;

   mat = new Matrix*[K];
   t = 0;
   mat[t++] = mat1;
   mat[t++] = mat2;
   mat[t++] = mat3;

   return mat;
}



Matrix* Matrix::lc(const double w1, Matrix* mat1, const double w2, Matrix* mat2) {
   Matrix** mat = NULL;
   Matrix* w = NULL;
   Matrix* ptr = NULL;

   mat = Matrix_array(mat1, mat2);
   w = instance_col(w1,w2);
   ptr = lc(mat,w);

   //clean memory
   delete [] mat;
   delete w;

   return ptr;
}

void Matrix::_add(Matrix* mat) {
   Matrix* ptr = NULL;
   ptr = Matrix::add(this,mat);
   this->assign(ptr);
   delete ptr;
}

void Matrix::_subtract(Matrix* mat) {
   Matrix* ptr = NULL;
   ptr = Matrix::subtract(this,mat);
   this->assign(ptr);
   delete ptr;
}

Matrix* Matrix::mult(Matrix* mat1, Matrix* mat2,
                     bool mat1T, bool mat2T,
                     Matrix* Delta, 
                     bool DeltaIflag) 
{
   if(mat1==NULL) cerr_msg("mat1==NULL",__FUNCTION__);
   if(mat2==NULL) cerr_msg("mat2==NULL",__FUNCTION__);

   double** X1 = mat1->X();
   double** X2 = mat2->X();
   double** DeltaX = NULL;
   Matrix* mat = NULL;
   double** X = NULL;
   int mm, nn, _nn, pp;
   double val1, val2, fac;

   if(Delta!=NULL) DeltaX = Delta->X();

   if(!mat1T) {mm = mat1->m(); nn = mat1->n();}
   else {mm = mat1->n(); nn = mat1->m();}

   if(!mat2T) {_nn = mat2->m(); pp = mat2->n();}
   else {_nn = mat2->n(); pp = mat2->m();}

   if(nn!=_nn) cerr_msg("Incompatible matrices",__FUNCTION__);

   mat = Matrix::instance(mm,pp);
   X = mat->X();

   for(int i=0;i<mm;i++) {
      for(int j=0;j<pp;j++) {
         for(int k=0;k<nn;k++) {
            if(!mat1T) val1 = X1[i][k];
            else val1 = X1[k][i];

            if(!mat2T) val2 = X2[k][j];
            else val2 = X2[j][k];
            
            fac = 1.0;
            if(Delta!=NULL) {
               fac = pow(DeltaX[k][0], 2);
               if(DeltaIflag) fac = 1.0/fac;
            }

            X[i][j] += val1 * val2 * fac;
         }
      }
   }

   {
      string* rmap = NULL;
      unordered_map<string,int>* rimap = NULL;
      string* cmap = NULL;
      unordered_map<string,int>* cimap = NULL;

      if(!mat1T) {rmap = mat1->rmap(); rimap = mat1->rimap();}
      else {rmap = mat1->cmap(); rimap = mat1->cimap();}

      if(mat2T) {cmap = mat2->rmap(); cimap = mat2->rimap();}
      else {cmap = mat2->cmap(); cimap = mat2->cimap();}

      mat->set_rmap_rimap(util_copy(rmap,mm),util_copy(rimap));
      mat->set_cmap_cimap(util_copy(cmap,pp),util_copy(cimap));
   }

   return mat;
}

bool Matrix::isSymmetric() {
   const int m = this->m();
   const int n = this->n();
   double** X = this->X();
   bool flag = true;

   if(m!=n) flag = false;

   for(int i=0;i<m && flag;i++){
      for(int j=0;j<n && flag;j++) flag = util_isEqual(X[i][j],X[j][i]);
   }

   return flag;
}

Matrix* Matrix::sub(int mm, int nn, int* ra, int*ca) 
{
   const int m = this->m();
   const int n = this->n();
   double** X = this->X();

   double** XX = NULL;
   Matrix* mat = NULL;
	string* rmap_ = NULL;
	unordered_map<string,int>* rimap_ = NULL;
	string* cmap_ = NULL;
	unordered_map<string,int>* cimap_ = NULL;
   int* _ra = NULL;
   int* _ca = NULL;

   if(ra==NULL) {ra = _ra = util_rangeA(0,mm=m);}
   if(ca==NULL) {ca = _ca = util_rangeA(0,nn=n);}

   XX = util_matrix(mm,nn,(double)0);

   for(int i=0;i<mm;i++) {
      for(int j=0;j<nn;j++) XX[i][j] = X[ra[i]][ca[j]];
   }

   rmap_ = util_sub(_rmap, m, ra, mm);
   cmap_ = util_sub(_cmap, n, ca, nn);

   mat = Matrix::instance(mm,nn,XX,rmap_,rimap_,cmap_,cimap_);

   //clean memory
   delete [] _ra;
   delete [] _ca;

   return mat;
}

Matrix* Matrix::sub(set<int>* rS, set<int>* cS, set<int>* xrS, set<int>* xcS,
                    int** rap, int** cap) 
{
   list<int>* rL = NULL;
   list<int>* cL = NULL;
   Matrix* Y = NULL;

   if(rS!=NULL) rL = util_list(rS);
   if(cS!=NULL) cL = util_list(cS);
   Y = this->sub2(rL, cL, xrS, xcS, rap, cap);

   //clean memory
   delete rL;
   delete cL;

   return Y;
}

Matrix* Matrix::sub2(list<int>* rS, list<int>* cS, set<int>* xrS, set<int>* xcS,
                    int** rap, int** cap) 
{
   list<set<int>*> memL;
   list<list<int>*> memLL;
   const int m = this->m();
   const int n = this->n();

   int mm, nn;
   Matrix* mat = NULL;

   int* ra = NULL;
   int* ca = NULL;

   if(rS==NULL) { memLL.push_back(rS=util_rangeL(0,m));}
   if(cS==NULL) { memLL.push_back(cS=util_rangeL(0,n));}
   if(xrS==NULL) { memL.push_back(xrS=new set<int>());}
   if(xcS==NULL) { memL.push_back(xcS=new set<int>());}

   ra = new int[m]; mm = 0;
   for(list<int>::iterator it=rS->begin();it!=rS->end();it++) {
      if(xrS->find(*it)==xrS->end()) ra[mm++] = *it;
   }

   ca = new int[n]; nn = 0;
   for(list<int>::iterator it=cS->begin();it!=cS->end();it++) {
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
   for(list<list<int>*>::iterator it=memLL.begin();it!=memLL.end();it++) delete *it;

   return mat;
}

Matrix* Matrix::inverse(Matrix* mat) {
   return pkgMath_inverse(mat);
}

Matrix* Matrix::inverse_psd(Matrix* mat) {
   return pkgMath_inverse_psd(mat);
}

Matrix* Matrix::solve(Matrix* A, Matrix* b) {
   return pkgMath_solve(A,b);
}

Matrix* Matrix::solve_sym(Matrix* A, Matrix* b) {
   return pkgMath_solve_sym(A,b);
}

int Matrix::chk() {
   int val = Model::chk();
   if(_X==NULL) val += 1;
   if(_rimap!=NULL && ((int)_rimap->size())!=_m) val += 10;
   if(_cimap!=NULL && ((int)_cimap->size())!=_n) val += 100;
   return val;
}

Matrix* Matrix::concat(const bool row_flag, Matrix** xA, const int T, string* pfx) {
   Matrix* X = NULL;
   if(!row_flag) cerr_msg("Functionality not yet implemented for row_flag=false",__FUNCTION__);
   else X = concat_col(xA, T, pfx);
   return X;
}

Matrix* Matrix::concat_row(Matrix** xA, const int T, string* pfx) {
   Matrix** cxA = NULL;
   Matrix* X = NULL;

   cxA = new Matrix*[T];
   for(int t=0;t<T;t++) cxA[t] = xA[t]->transpose();
   X = concat_col(cxA, T, pfx);
   X->_transpose();

   //clean memory
   for(int t=0;t<T;t++) delete cxA[t];
   delete [] cxA;

   return X;
}

Matrix* Matrix::concat3_row(const int T, Matrix** xA, string* pfx) {
   Matrix** cxA = NULL;
   Matrix* X = NULL;

   cxA = new Matrix*[T];
   for(int t=0;t<T;t++) cxA[t] = xA[t]->transpose();
   X = concat3_col(T, cxA, pfx);
   X->_transpose();

   //clean memory
   for(int t=0;t<T;t++) delete cxA[t];
   delete [] cxA;

   return X;
}

Matrix* Matrix::concat_col(Matrix** xA, const int T, string* pfx) {
   Matrix* mat = NULL;
   double** X = NULL;
   int m,n;

   m = 0; n = xA[0]->n();
   for(int t=0;t<T;t++) m += xA[t]->m();

   X = util_matrix(m,n,(double)0);
   mat = Matrix::instance(m,n,X);

   {
      string rid;
      int i;

      i = 0;
      for(int t=0;t<T;t++) {
         string* rmap = xA[t]->rmap();
         int t_m = xA[t]->m();
         for(int t_i=0;t_i<t_m;t_i++) {
            rid = string("row") + util_string(i);
            if(rmap!=NULL) rid = rmap[t_i];
            if(pfx!=NULL) rid = util_join(".",pfx[t],rid);
            mat->set_rmap_rimap(i++,rid);
         }
      }
   }

   for(int t=0, ii=0;t<T;t++) {
      int mt = xA[t]->m();
      int nt = xA[t]->n();
      double** Xt = xA[t]->X();
      string* cmapt = xA[t]->cmap();

      if(nt!=n) cerr_msg("nt!=n",__FUNCTION__);

      for(int i=0;i<mt;i++) {
         for(int j=0;j<nt;j++) X[ii][j] = Xt[i][j];
         ii++;
      }

      for(int j=0;j<nt && cmapt!=NULL;j++) mat->set_cmap_cimap(j, cmapt[j]);
   }


   return mat;
}

void Matrix::_hmult(bool row_flag, Matrix* Delta, bool inv_flag) {
   const int m = this->m();
   const int n = this->n();
   double** X = this->X();
   double** DeltaX = Delta->X();
   double val;

   if(row_flag && Delta->m()!=n) myerr_msg("Delta->m!=n row_flag=true",__FUNCTION__);
   if(!row_flag && Delta->m()!=m) myerr_msg("Delta->m!=n row_flag=false",__FUNCTION__);

   for(int i=0;i<m;i++) {
      for(int j=0;j<n;j++) {
         if(row_flag) val = DeltaX[j][0];
         else val = DeltaX[i][0];
         if(inv_flag) val = 1.0/val;
         X[i][j] *= val;
      }
   }

   return;
}


set<int>* Matrix::rnzS(const int j) {
   set<int>* S = NULL;
   const int m = this->m();
   const int n = this->n();
   double** X = this->X();

   if(j<0 || j>n) myerr_msg("j<0 || j>n",__FUNCTION__);
   S = new set<int>();

   for(int i=0;i<m;i++) {
      if(util_isZero(X[i][j])) continue;
      S->insert(i);
   }

   return S;
}


set<int>* Matrix::cnzS(const int i) {
   set<int>* S = NULL;
   const int m = this->m();
   const int n = this->n();
   double** X = this->X();

   if(i<0 || i>m) myerr_msg("i<0 || i>m",__FUNCTION__);
   S = new set<int>();

   for(int j=0;j<n;j++) {
      if(util_isZero(X[i][j])) continue;
      S->insert(j);
   }

   return S;
}

double Matrix::l2n() {
   const int m = this->m();
   const int n = this->n();
   double** X = this->X();
   double val;

   val = 0;
   for(int i=0;i<m;i++) {
      for(int j=0;j<n;j++) val += X[i][j] * X[i][j];
   }

   val = sqrt(val);

   return val;
}

Matrix* Matrix::l2nc(bool normalize, bool winsorize_flag, double alpha1, double alpha2,
                     Matrix* Delta, bool inv_flag) 
{
   if(winsorize_flag) {
      Matrix* tmp = Matrix::winsorize(this, false, alpha1, alpha2);
      Matrix* l2 = tmp->l2nc(normalize, false, alpha1, alpha2, Delta, inv_flag);
      delete tmp;
      return l2;
   }

   const int m = this->m();
   const int n = this->n();
   double** X = this->X();
   Matrix* l2 = NULL;
   double val;

   l2 = Matrix::instance(1,n);
   l2->copynames(this, false, true);

   if(Delta==NULL) {
      for(int j=0;j<n;j++) {
         val = 0;
         for(int i=0;i<m;i++) {
            val += X[i][j] * X[i][j];
         }
         if(normalize) val /= m;
         l2->X()[0][j] = sqrt(val);
      }
   }
   else {
      double** DeltaX = Delta->X();
      double dexp = 1.0;
      double wt, wt_val;

      if(inv_flag) dexp = -2;

      for(int j=0;j<n;j++) {
         val = 0; wt_val = 0;
         for(int i=0;i<m;i++) {
            wt = pow(DeltaX[i][0],dexp);
            val += X[i][j] * X[i][j] * wt;
            wt_val += wt;
         }
         val /= wt_val;
         l2->X()[0][j] = sqrt(val);
      }
   }

   return l2;
}

Matrix* Matrix::ones(const int m, const int n, const double val) {
   Matrix* ptr = Matrix::instance(m,n);
   double** ptrX = ptr->X();
   for(int i=0;i<m;i++) {
      for(int j=0;j<n;j++) ptrX[i][j] = val;
   }

   return ptr;
}

Matrix* Matrix::lift(int mm, int nn, int* ra, int* ca, Matrix* _XX) {
   const int m = this->m();
   const int n = this->n();
   double** X = this->X();

   double** XX = NULL;
   Matrix* mat = NULL;
   int* _ra = NULL;
   int* _ca = NULL;

   if(ra==NULL) {ra = _ra = util_rangeA(0,mm=m);}
   if(ca==NULL) {ca = _ca = util_rangeA(0,nn=n);}

   if(_XX==NULL) {
      XX = util_matrix(mm,nn,(double)0);
      mat = Matrix::instance(mm,nn,XX);
   }
   else {
      mat = _XX;
      XX = mat->X();
   }

   for(int i=0;i<m;i++) {
      for(int j=0;j<n;j++)  XX[ra[i]][ca[j]] = X[i][j];
   }

   //clean memory
   delete [] _ra;
   delete [] _ca;

   return mat;
}

void Matrix::fprint_table(string fname) {
   const int m = this->m();
   const int n = this->n();
   double** X = this->X();
	string* rmap = this->rmap();
	string* cmap = this->cmap();
   string** Xs = NULL;
   int ms, ns;
   char xval[100];

   ms = m + 1;
   ns = n + 1;

   Xs = util_matrix(ms,ns,string(""));

   Xs[0][0] = "RowHeader";
   for(int j=0;j<n;j++) Xs[0][j+1] = cmap[j];
   for(int i=0;i<m;i++) {
      Xs[i+1][0] = rmap[i];
      for(int j=0;j<n;j++) {
         sprintf(xval,"%2.20f",X[i][j]);
         Xs[i+1][j+1] = string(xval);
      }
   }

   util_fprint(fname,Xs,ms,ns);

   //clean memory
   util_clean(Xs,ms,ns);

   return;
}

Matrix* Matrix::copy(Matrix* X) {
   if(X==NULL) return NULL;
   return X->copy();
}

int Matrix::l2closest(Matrix* Y, int ii, bool row_flag) {
   if(!row_flag) myerr_msg("Functionality not yet implemented for row_flag==false",__FUNCTION__);
   if(Y->n()!=this->n()) myerr_msg("Y->n()!=this->n()",__FUNCTION__);

   const int m = this->m();
   const int n = this->n();
   double** XX = this->X();
   double** YX = Y->X();
   double optval, val;
   int idx;

   idx = -1; optval = 0;
   for(int i=0;i<m;i++) {
      val = 0;
      for(int j=0;j<n;j++) val += pow(XX[i][j]-YX[ii][j],2);
      val = sqrt(val);
      if(idx<0 || val < optval) {idx = i; optval = val;}
   }

   return idx;
}

void Matrix::copyrow(Matrix* Y, int iX, int iY) {
   if(this->n() != Y->n()) myerr_msg("this->n() != Y->n()",__FUNCTION__);
   if(iX<0) myerr_msg("iX<0",__FUNCTION__);
   if(iY<0) myerr_msg("iY<0",__FUNCTION__);
   if(iX >= this->m()) myerr_msg("iX >= this->m()",__FUNCTION__);
   if(iY >= Y->m()) myerr_msg("iY >= Y->m()",__FUNCTION__);

   const int n = this->n();
   double** YX = Y->X();
   double** XX = this->X();
   for(int j=0;j<n;j++) XX[iX][j] = YX[iY][j];

   return;
}

void Matrix::copycol(Matrix* Y, int jX, int jY) {
   if(this->m() != Y->m()) myerr_msg("this->m() != Y->m()",__FUNCTION__);
   if(jX<0) myerr_msg("jX<0",__FUNCTION__);
   if(jY<0) myerr_msg("jY<0",__FUNCTION__);
   if(jX >= this->n()) myerr_msg("jX >= this->n()",__FUNCTION__);
   if(jY >= Y->n()) myerr_msg("jY >= Y->n()",__FUNCTION__);

   const int m = this->m();
   double** YX = Y->X();
   double** XX = this->X();
   for(int i=0;i<m;i++) XX[i][jX] = YX[i][jY];

   return;
}

Matrix* Matrix::pct(double eta, bool row_flag, set<int>* S, Matrix* Delta) {
   if(!row_flag) myerr_msg("Functionality not yet implemented for row_flag=false",__FUNCTION__);

   const int n = this->n();
   const int m = this->m();

   set<int>* _S = NULL;
   Matrix* sX = NULL;
   Matrix* col = NULL;
   Matrix* sDelta = NULL;
   Matrix* pX = NULL;

   if(S==NULL) _S = S = util_rangeS(0,m);
   
   sX = this->sub(S,NULL);
   if(Delta!=NULL) sDelta = Delta->sub(S,NULL);
   pX = Matrix::instance(1,n);

   for(int j=0;j<n;j++) {
      col = sX->col(j);
      pX->X()[0][j] = mathutil_pct(col, eta, sDelta);
      delete col; col = NULL;
   }

   pX->copynames(this, false, true);

   //clean memory
   delete _S;
   delete sX;
   delete sDelta;

   return pX;
}

Matrix* Matrix::col(const int j) {
   set<int> S;
   S.insert(j);
   return this->sub(NULL,&S);
}

Matrix* Matrix::row(const int i) {
   set<int> S;
   S.insert(i);
   return this->sub(&S,NULL);
}

void Matrix::_winsorize(const bool row_flag, const double alpha1, const double alpha2) {
   const int m = this->m();
   const int n = this->n();
   double** XX = this->X();
   double* vec = NULL;
   int mm, nn;

   if(!row_flag) {mm = m; nn = n;}
   else {mm = n; nn = m;}
   vec = new double[mm];

   for(int j=0;j<nn;j++) {
      if(!row_flag) copycol(j, vec);
      else copyrow(j, vec);

      mathutil_winsorize(vec, mm, alpha1, alpha2);
      for(int i=0;i<mm;i++) {
         if(!row_flag) XX[i][j] = vec[i];
         else XX[j][i] = vec[i];
      }

   }
   
   //clean memory
   delete [] vec;

   return;
}

Matrix* Matrix::winsorize(Matrix* X, const bool row_flag,
                          const double alpha1, const double alpha2) 
{
   Matrix* Y = X->copy();
   Y->_winsorize(row_flag, alpha1, alpha2);
   return Y;
}

Matrix* Matrix::mean_row(Matrix* Delta, bool inv_flag, set<int>* S) {
   int n = this->n();

   Matrix* ptr = NULL;
   Matrix* e = NULL;
   Matrix* eTe = NULL;
   list<Object*> objL;
   double val;

   if(S==NULL) objL.push_back( e = Matrix::ones(n,1) );
   else {
         objL.push_back( e = Matrix::instance(n,1) );
         double** eX = e->X();
         set<int>::iterator it;
         for(it=S->begin();it!=S->end();it++) eX[*it][0] = 1;
   }

   ptr = Matrix::mult(this, e, false, false, Delta, inv_flag);
   objL.push_back( eTe = Matrix::mult(e, e, true, false, Delta, inv_flag) );
   val = eTe->X()[0][0];
   ptr->_mult(1.0/val);

   //clean memory
   util_clean_obj(&objL);

   return ptr;
}

Matrix* Matrix::mean_col(Matrix* Delta, bool inv_flag, set<int>* S) {
   int m = this->m();

   Matrix* ptr = NULL;
   Matrix* e = NULL;
   Matrix* eTe = NULL;
   list<Object*> objL;
   double val;

   objL.push_back( e = Matrix::ones(1,m) );
   if(S==NULL) objL.push_back( e = Matrix::ones(1,m) );
   else {
         objL.push_back( e = Matrix::instance(1, m) );
         double** eX = e->X();
         set<int>::iterator it;
         for(it=S->begin();it!=S->end();it++) eX[0][*it] = 1;
   }

   ptr = Matrix::mult(e, this, false, false, Delta, inv_flag);
   objL.push_back( eTe = Matrix::mult(e, e, false, true, Delta, inv_flag) );
   val = eTe->X()[0][0];
   ptr->_mult(1.0/val);

   //clean memory
   util_clean_obj(&objL);

   return ptr;
}

Matrix* Matrix::transpose() {
   return Matrix::transpose(this);
}

void Matrix::copynames(Matrix* X, bool rflag, bool cflag) {
   if(X==NULL) myerr_msg("X==NULL",__FUNCTION__);
   if(rflag && X->rmap()==NULL) return;
   if(cflag && X->cmap()==NULL) return;

   if(rflag) {
      if(X->m()!=this->m()) myerr_msg("X->m()!=this->m()",__FUNCTION__);
      string* Xrmap = X->rmap();
      int m = this->m();
      for(int i=0;i<m;i++) set_rmap_rimap(i, Xrmap[i]);
   }

   if(cflag) {
      if(X->n()!=this->n()) myerr_msg("X->n()!=this->n()",__FUNCTION__);
      string* Xcmap = X->cmap();
      int n = this->n();
      for(int i=0;i<n;i++) set_cmap_cimap(i, Xcmap[i]);
   }

   return;
}

Matrix* Matrix::instance_fread_table(string fname, string delimiter) {
   Matrix* ptr = NULL;
   double** X = NULL;
   string* cmap = NULL;
   string* rmap = NULL;
   int m, n;

   if(util_fscan_NULL(fname)) return ptr;
   util_fscan(fname,X,m,n,delimiter,1,&cmap,1,&rmap);
   ptr = Matrix::instance(m,n,X,rmap,NULL,cmap,NULL);
   return ptr; 
}

void Matrix::fprint_raw(string fname) {
   util_ofprint(fname,"X",_X,_m,_n);
   return;
}

Matrix* Matrix::hpow(const double eta) {
   Matrix* X = this->copy();
   X->_hpow(eta);
   return X;
}

Matrix* Matrix::hlog() {
   Matrix* X = this->copy();
   X->_hlog();
   return X;
}

Matrix* Matrix::hexp() {
   Matrix* X = this->copy();
   X->_hexp();
   return X;
}

Matrix* Matrix::habs() {
   Matrix* X = this->copy();
   X->_habs();
   return X;
}

Matrix* Matrix::cc(double row_flag, set<int>* S, bool i2_flag) {
   if(row_flag) myerr_msg("Functionality not yet implemented",__FUNCTION__);
   int n = this->n();
   Matrix* val = NULL;
   double** valX = NULL;

   val = Matrix::instance(1, n);
   val->copynames(this, false, true);
   val->set_rmap_rimap(0,"cc");
   valX = val->X();
   for(int j=0;j<n;j++) valX[0][j] = this->cc(row_flag, j, S, i2_flag);

   return val;
}

double Matrix::cc(double row_flag, int j, set<int>* S, bool i2_flag) {
   if(row_flag) myerr_msg("Functionality not yet implemented",__FUNCTION__);
   if(S!=NULL && S->size()==0) return 0;

   double** X = this->X();
   int m = this->m();
   set<int>* _S = NULL;
   set<int>::iterator it;
   double val, cval;
   double* w = NULL;
   int i, num;

   if(S==NULL) S = _S = util_rangeS(0,m);
   num = S->size();
   w = new double[num];

   if(!i2_flag) {
      for(i=0,it=S->begin();it!=S->end();it++) w[i++] = X[*it][j];
   }
   else {
      for(i=0,it=S->begin();it!=S->end();it++) w[i++] = pow(X[*it][j],-2);
   }

   val = 0;
   for(i=0;i<num;i++) val += w[i];

   cval = 0;
   for(i=0;i<num;i++) cval += pow(w[i]/val,2.0);
   cval = 1/cval;

   //clean memory
   delete _S;
   delete [] w;

   return cval;
}

Matrix* Matrix::instance_col(unordered_map<string,double>* valm, string col_id) {
   Matrix* X = NULL;
   set<string>* S = NULL;
   set<string>::iterator it;
   int i;

   S = util_keys(valm, S);
   X = Matrix::instance(S->size(),1);
   for(i=0, it=S->begin();it!=S->end();it++) {
      X->X()[i][0] = (*valm)[*it];
      X->set_rmap_rimap(i, *it);
      i++;
   }
   X->set_cmap_cimap(0, col_id);

   //clean memory
   delete S;

   return X;
}

Matrix* Matrix::instance_row(unordered_map<string,double>* valm, string row_id) {
   Matrix* X = NULL;
   set<string>* S = NULL;
   set<string>::iterator it;
   int i;

   S = util_keys(valm, S);
   X = Matrix::instance(1,S->size());
   for(i=0, it=S->begin();it!=S->end();it++) {
      X->X()[0][i] = (*valm)[*it];
      X->set_cmap_cimap(i, *it);
      i++;
   }
   X->set_rmap_rimap(0, row_id);

   //clean memory
   delete S;

   return X;
}



double Matrix::max() {
   double** X = this->X();
   double val = this->X()[0][0];
   int m, n;

   m = this->m();
   n = this->n();
   
   for(int i=0;i<m;i++) {
      for(int j=0;j<n;j++) {
         if(val < X[i][j]) val = X[i][j];
      }
   }

   return val;
}

double Matrix::min() {
   double** X = this->X();
   double val = this->X()[0][0];
   int m, n;

   m = this->m();
   n = this->n();
   
   for(int i=0;i<m;i++) {
      for(int j=0;j<n;j++) {
         if(val > X[i][j]) val = X[i][j];
      }
   }

   return val;
}

Matrix* Matrix::corr( Matrix* mat1, Matrix* mat2, Matrix* Delta, bool i2_flag) {
   

   if(mat1==NULL) cerr_msg("mat1==NULL",__FUNCTION__);
   if(mat2==NULL) cerr_msg("mat2==NULL",__FUNCTION__);
   if(mat1->n()!=mat2->n()) cerr_msg("(mat1->n()!=mat2->n()",__FUNCTION__);

   double** X = mat1->X();
   double** Y = mat2->X();
   double** DeltaX = NULL;
   if(Delta!=NULL) DeltaX = Delta->X();
   int n = mat1->n();
   int m_x = mat1->m();
   string* rmapx = mat1->rmap();
   
   // Get mappings from x_i -> y_j
   // ie. x_i maps to which row in y
   
   unordered_map<int,int> imapy;
   unordered_map<int,int> imapd;
   for( int i=0; i<m_x; i++ ) {
      if( mat2->rimap()->find(rmapx[i]) == mat2->rimap()->end() ) continue;
      if( Delta!=NULL ) {
         if( Delta->rimap()->find(rmapx[i]) == Delta->rimap()->end() ) continue; }
      imapy[i] = mat2->rimap()->find(rmapx[i])->second;
      if( Delta!=NULL ) {
         imapd[i] = Delta->rimap()->find(rmapx[i])->second; }
   }

   // Calculate mean for each column t

   double* means_x = new double[n];
   double* means_y = new double[n];

   for( int t=0;t<n;t++ ) {
      means_x[t] = 0;
      means_y[t] = 0;
      int wtsum = 0;
      for( int i=0;i<m_x;i++ ) {
         if( imapy.find(i) == imapy.end() ) continue;
         int j = imapy.find(i)->second;
         double d = 1;
         if( Delta!=NULL ) d = DeltaX[imapd.find(i)->second][0];
         if(i2_flag && !util_isZero(d)) d = pow(d,-2);
         means_x[t] += X[i][t] * d;
         means_y[t] += Y[j][t] * d;
         wtsum += d;
      }
      means_x[t] = means_x[t] / wtsum;
      means_y[t] = means_y[t] / wtsum;  
   }

   // Calculate correlations for each column t

   Matrix* ptr = NULL;
   ptr = Matrix::instance(1,n);
   ptr->copynames(mat1,false,true);
   double** C = ptr->X();

   for(int t=0;t<n;t++) {
      double numerator = 0;
      double den_x = 0;
      double den_y = 0;
      for( int i=0;i<m_x;i++ ) {
         if( imapy.find(i) == imapy.end() ) continue;
         int j = imapy.find(i)->second;
         double d = 1;
         if( Delta!=NULL ) d = DeltaX[imapd.find(i)->second][0];
         if(i2_flag && !util_isZero(d)) d = pow(d,-2);

         numerator += d * ( X[i][t] - means_x[t] ) * ( Y[j][t] - means_y[t] );
         den_x += d * pow( X[i][t] - means_x[t], 2 );
         den_y += d * pow( Y[j][t] - means_y[t], 2 );
      }

      C[0][t] = numerator / pow( den_x * den_y, 0.5 );
   }

   // Clear Memory
   delete[] means_x;
   delete[] means_y;

   return ptr;

}

void Matrix::_hmult(Matrix* F) {
   int m = this->m();
   int n = this->n();
   double** XX = this->X();
   double** FX = F->X();

   if(F->m()!=m) myerr_msg("F->m()!=m",__FUNCTION__);
   if(F->n()!=n) myerr_msg("F->n()!=n",__FUNCTION__);

   for(int i=0;i<m;i++) {
      for(int j=0;j<n;j++) XX[i][j] *= FX[i][j];
   }

   return;
}

Matrix* Matrix::concat3_col(const int T, Matrix** mA, string* pfx) {
   Matrix* mat = NULL;
   double** X = NULL;
   string* rmap = NULL;
   int m,n;

   //determine rmap and m
   {
      set<string> S;
      string* rmap_tmp = mA[0]->rmap();
      int m_tmp = mA[0]->m();
      string aid;
      bool flag;

      for(int i=0;i<m_tmp;i++) {
         aid = rmap_tmp[i];
         flag = true;
         for(int t=0;t<T && flag;t++) {
            if(mA[t]->rimap()->find(aid)==mA[t]->rimap()->end()) flag = false;
         }
         if(flag) S.insert(aid);
      }

      m = S.size();
      rmap = util_array(&S);
   }

   //determine n
   {
      n = 0;
      for(int t=0;t<T;t++) n += mA[t]->n();
   }

   X = util_matrix(m, n, (double)0);

   for(int i=0;i<m;i++) {
      string aid =rmap[i];
      int j;

      j = 0;
      for(int t=0;t<T;t++) {
         int t_i, t_n;

         t_i = mA[t]->rimap()->find(aid)->second;
         t_n = mA[t]->n();
         for(int t_j=0;t_j<t_n;t_j++) X[i][j++] = mA[t]->X()[t_i][t_j];
      }
   }

   mat = Matrix::instance(m,n,X,rmap,NULL,NULL,NULL);

   {
      string* mat_cmap = NULL;
      int j;
      
      mat->set_cmap_cimap(util_names("col",mat->n()),NULL);
      mat_cmap = mat->cmap();

      j = 0;
      for(int t=0;t<T;t++) {
         string* cmap = mA[t]->cmap();
         int nn = mA[t]->n();
         for(int jj=0;jj<nn;jj++) {
            string cid;

            if(cmap==NULL) cid = mat_cmap[j];
            else cid = cmap[jj];
            if(pfx!=NULL) cid = util_join(".",pfx[t],cid);

            mat->set_cmap_cimap(j++, cid);
         }
      }
   }

   return mat;
}

Matrix* Matrix::concat3_col(Matrix* X, Matrix* Y, string* pfx) {
   Matrix* A = NULL;
   Matrix** mA = NULL;
   int T;

   mA = new Matrix*[2];
   T = 0;
   mA[T++] = X;
   mA[T++] = Y;
   A = concat3_col(T,mA, pfx);

   //clean memory
   delete [] mA;

   return A;
}

Matrix* Matrix::concat3_col(Matrix* X, Matrix* Y, Matrix* Z, string* pfx) {
   Matrix* A = NULL;
   Matrix** mA = NULL;
   int T;

   mA = new Matrix*[3];
   T = 0;
   mA[T++] = X;
   mA[T++] = Y;
   mA[T++] = Z;
   A = concat3_col(T,mA, pfx);

   //clean memory
   delete [] mA;

   return A;
}

Matrix* Matrix::concat3_col(Matrix* X, Matrix* Y, Matrix* Z, Matrix* Z2, string* pfx) {
   Matrix* A = NULL;
   Matrix** mA = NULL;
   int T;

   mA = new Matrix*[4];
   T = 0;
   mA[T++] = X;
   mA[T++] = Y;
   mA[T++] = Z;
   mA[T++] = Z2;
   A = concat3_col(T,mA, pfx);

   //clean memory
   delete [] mA;

   return A;
}

Matrix* Matrix::colrank_normalized() {
   Matrix* cr = Matrix::colrank();
   cr->_hmult(1.0/cr->m());
   return cr;
}

Matrix* Matrix::colrank_normalized(int j) {
   Matrix* cr = Matrix::colrank(j);
   cr->_hmult(1.0/cr->m());
   return cr;
}

Matrix* Matrix::colrank(const int j) {
   struct mycomparison
   {
      bool operator() (double* lhs, double* rhs) {return (*lhs) < (*rhs);}
   };

   int m = this->m();
   double** X= this->X();
   double* val = NULL;
   double** valptr = NULL;
   double** crX = NULL;
   Matrix* cr = NULL;

   val = new double[m];
   for(int i=0;i<m;i++) val[i] = X[i][j];
   valptr = new double*[m];
   for(int i=0;i<m;i++) valptr[i] = val + i;
   std::sort(valptr, valptr+m, mycomparison());
   for(int i=0;i<m;i++) *valptr[i] = i;

   cr = Matrix::instance(m,1);
   crX = cr->X();
   for(int i=0;i<m;i++) crX[i][0] = val[i];

   cr->copynames(this, true, false);

   //clean memory
   delete [] val;
   delete [] valptr;

   return cr;
}


Matrix* Matrix::colrank() {
   int n = this->n();
   Matrix* tmp = NULL;
   Matrix* X = this->copy();

   for(int j=0;j<n;j++) {
      tmp = this->colrank(j);
      X->copycol(tmp, j, 0);
      delete tmp; tmp = NULL;
   }

   return X;
}

double Matrix::correl_col(const int j1, const int j2) {
   Matrix* c1 = this->col(j1);
   Matrix* c2 = this->col(j2);
   Matrix* tmp = Matrix::corr(c1, c2, NULL, false);
   double val = tmp->X()[0][0];
   delete c1;
   delete c2;
   delete tmp;
   return val;
}

double Matrix::sumprod_col(const int j1, const int j2) { 
   double** X = this->X();
   int m = this->m();
   double val = 0;
   for(int i=0;i<m;i++) val += X[i][j1] * X[i][j2];
   return val;
}

Matrix* Matrix::sub(Matrix* X, bool rnames_flag, bool cnames_flag) {
   int m = this->m();
   int n = this->n();
   list<int>* rL = NULL;
   list<int>* cL = NULL;
   Matrix* Xsub = NULL;

   if(rnames_flag) {
      string* rmap = this->rmap();
      unordered_map<string,int>* X_rimap = X->rimap();

      rL = new list<int>();
      for(int i=0;i<m;i++) {
         if(X_rimap->find(rmap[i])==X_rimap->end()) continue;
         rL->push_back(i);
      }
   }
   else rL = util_rangeL(0,m);

   if(cnames_flag) {
      string* cmap = this->cmap();
      unordered_map<string,int>* X_cimap = X->cimap();

      cL = new list<int>();
      for(int i=0;i<n;i++) {
         if(X_cimap->find(cmap[i])==X_cimap->end()) continue;
         cL->push_back(i);
      }
   }
   else cL = util_rangeL(0,n);

   Xsub = Matrix::sub2(rL, cL);

   //clean memory
   delete rL;
   delete cL;

   return Xsub;
}

Matrix* Matrix::subrow(Matrix* X) {return sub(X, true, false);}
Matrix* Matrix::subcol(Matrix* X) {return sub(X, false, true);}

void Matrix::summary(list<unordered_map<string,string>*>*& L, set<string>* headerS) {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
}

void Matrix::fprint_summary(string fname, set<string>* headerS) {
   this->fprint_table(fname);
}

Matrix* Matrix::sub3(set<string>* rS, set<string>* cS, set<string>* xrS, set<string>* xcS,
                    int** rap, int** cap) 
{
   unordered_map<string,int>* rimap = this->rimap();
   unordered_map<string,int>* cimap = this->cimap();

   set<int>* irS = NULL;
   set<int>* icS = NULL;
   set<int>* ixrS = NULL;
   set<int>* ixcS = NULL;
   unordered_map<string,int>::iterator it2;
   set<string>::iterator it;
   Matrix* Y = NULL;

   if(rS!=NULL) {
      irS = new set<int>();
      for(it=rS->begin();it!=rS->end();it++) {
         it2 = rimap->find(*it);
         if(it2==rimap->end()) myerr_msg((*it) + " not found in rimap",__FUNCTION__);
         irS->insert(it2->second);
      }
   }

   if(cS!=NULL) {
      icS = new set<int>();
      for(it=cS->begin();it!=cS->end();it++) {
         it2 = cimap->find(*it);
         if(it2==cimap->end()) myerr_msg((*it) + " not found in cimap",__FUNCTION__);
         icS->insert(it2->second);
      }
   }

   if(xrS!=NULL) {
      ixrS = new set<int>();
      for(it=xrS->begin();it!=xrS->end();it++) {
         it2 = rimap->find(*it);
         if(it2==rimap->end()) continue;
         ixrS->insert(it2->second);
      }
   }

   if(xcS!=NULL) {
      ixcS = new set<int>();
      for(it=xcS->begin();it!=xcS->end();it++) {
         it2 = cimap->find(*it);
         if(it2==cimap->end()) continue;
         ixcS->insert(it2->second);
      }
   }

   Y = this->sub(irS, icS, ixrS, ixcS);

   //clean memory
   delete irS;
   delete icS;
   delete ixrS;
   delete ixcS;

   return Y;
}

void Matrix::pfxnames(string pfx, bool rflag, bool cflag) {
   int m = this->m();
   int n = this->n();
   string* rmap = this->rmap();
   string* cmap = this->cmap();

   for(int i=0;i<m && rflag;i++) this->set_rmap_rimap(i, pfx + rmap[i]);
   for(int j=0;j<n && cflag;j++) this->set_cmap_cimap(j, pfx + cmap[j]);

   return;
}

set<string>* Matrix::rows_common(Matrix* X1, Matrix* X2) {
   set<string>* S1 = util_set(X1->rmap(), X1->m());
   set<string>* S2 = util_set(X2->rmap(), X2->m());
   set<string>* S = util_intersect(S1, S2);
   delete S1;
   delete S2;
   return S;
}

set<string>* Matrix::cols_common(Matrix* X1, Matrix* X2) {
   set<string>* S1 = util_set(X1->cmap(), X1->n());
   set<string>* S2 = util_set(X2->cmap(), X2->n());
   set<string>* S = util_intersect(S1, S2);
   delete S1;
   delete S2;
   return S;
}

Matrix* Matrix::concat3_row(unordered_map<string,Matrix*>* mm) {
   Matrix* X = NULL;
   Matrix** mA = NULL;
   string* pfx = NULL;
   unordered_map<string,Matrix*>::iterator it;
   int T, t;

   T = mm->size();
   mA = new Matrix*[T];
   pfx = new string[T];

   for(it=mm->begin(),t=0;it!=mm->end();it++,t++) {
      pfx[t] = it->first;
      mA[t] = it->second;
   }

   X = Matrix::concat3_row(T, mA, pfx);

   //clean memory
   delete [] pfx;
   delete [] mA;

   return X;
}

Matrix* Matrix::concat3_col(unordered_map<string,Matrix*>* mm) {
   Matrix* X = NULL;
   Matrix** mA = NULL;
   string* pfx = NULL;
   unordered_map<string,Matrix*>::iterator it;
   set<string> keys;
   set<string>::iterator keys_it;
   int T, t;

   T = mm->size();
   mA = new Matrix*[T];
   pfx = new string[T];

   for(it=mm->begin();it!=mm->end();it++) keys.insert(it->first);

   for(keys_it=keys.begin(),t=0;keys_it!=keys.end();keys_it++, t++) {
      pfx[t] = (*keys_it);
      mA[t] = (*mm)[pfx[t]];
   }

   X = Matrix::concat3_col(T, mA, pfx);

   //clean memory
   delete [] pfx;
   delete [] mA;

   return X;
}

unordered_map<string,double>* Matrix::row(const int i, string pfx, string sfx,
                                         string* cmap, 
                                         unordered_map<string,double>* valm)
{
   if(valm==NULL) valm = new unordered_map<string,double>();
   if(cmap==NULL) cmap = this->cmap();

   int n = this->n();
   double** X = this->X();
   string key;

   for(int j=0;j<n;j++) {
      key = cmap[j];
      if(pfx.length()>0) key = util_join(".",pfx,key);
      if(sfx.length()>0) key = util_join(".",key,sfx);
      (*valm)[key] = X[i][j];
   }

   return valm;
}


#endif

