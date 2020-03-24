// Name:     FlexMatrix.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_FlexMatrix_cpp
#define ASX_FlexMatrix_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Model.hpp"
#include "Summarizable.hpp"
#include "Matrix.hpp"
#include "FlexMatrix.hpp"
#include "DatedMatrix.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMath;

/** --------------Constructors and init_NULL-----------*/

FlexMatrix::FlexMatrix() { init_NULL(); }
FlexMatrix::FlexMatrix(const FlexMatrix* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
FlexMatrix::FlexMatrix(const FlexMatrix& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void FlexMatrix::init_NULL()	{
	_protomat=NULL;
	_fmval=NULL;
	_fmflag=NULL;
}

/** ---Public Data Setting Functions-----------------*/

void FlexMatrix::add_fm(string aid, Matrix* Xval, Matrix* Xflag) {
   if(this->fmval(aid,true)!=NULL) myerr_msg(aid + " already present in fmal",__FUNCTION__);

   if(! chk_consistency(Xval)) myerr_msg(aid + " chk_consistency failed for Xval",__FUNCTION__);
   if(! chk_consistency(Xflag)) myerr_msg(aid + " chk_consistency failed for Xflag",__FUNCTION__);

   (*_fmval) [aid] = Xval;
   (*_fmflag) [aid] = Xflag;

   return;
}

/** --------   Init Functions -------------------------*/

void FlexMatrix::init(Matrix* protomat) {
   Model::init();
	init_FlexMatrix(protomat);
}

void FlexMatrix::init_FlexMatrix(Matrix* protomat) {
	init_protomat(protomat);
	init_fm();
}

void FlexMatrix::init_protomat(Matrix* protomat) {_protomat = protomat;}

void FlexMatrix::init_fm() {
   _fmval = new unordered_map<string, Matrix*>();
   _fmflag = new unordered_map<string, Matrix*>();
}

/** -----Destructors and Memory Cleanup functions -----*/

FlexMatrix::~FlexMatrix()	{ cleanMem(); }

void FlexMatrix::cleanMem()	{
	cleanMem_FlexMatrix();
	Model::cleanMem();
	Summarizable::cleanMem();
}

void FlexMatrix::cleanMem_FlexMatrix() {
	cleanMem_protomat();
	cleanMem_fmval();
	cleanMem_fmflag();
}

void FlexMatrix::cleanMem_protomat() {
   delete _protomat;
	_protomat=NULL;
}

void FlexMatrix::cleanMem_fmval() {
   if(_fmval!=NULL) {
      unordered_map<string, Matrix*>::iterator it;
      for(it=_fmval->begin();it!=_fmval->end();it++) delete it->second;
      delete _fmval;
   }
	_fmval=NULL;
}

void FlexMatrix::cleanMem_fmflag() {
   if(_fmflag!=NULL) {
      unordered_map<string, Matrix*>::iterator it;
      for(it=_fmflag->begin();it!=_fmflag->end();it++) delete it->second;
      delete _fmflag;
   }
	_fmflag=NULL;
}

/** ------------- Data Access Functions --------------------*/

Matrix* FlexMatrix::protomat() {return _protomat;}
unordered_map<string,Matrix*>* FlexMatrix::fmval() {return _fmval;}
unordered_map<string,Matrix*>* FlexMatrix::fmflag() {return _fmflag;}

Matrix* FlexMatrix::fmval(string aid, bool iflag) {
   unordered_map<string, Matrix*>::iterator it;
   it = _fmval->find(aid);
   if(it==_fmval->end()) {
      if(iflag) return NULL;
      else myerr_msg(aid + " not found",__FUNCTION__);
   }
   return it->second;
}

Matrix* FlexMatrix::fmflag(string aid, bool iflag) {
   unordered_map<string, Matrix*>::iterator it;
   it = _fmflag->find(aid);
   if(it==_fmflag->end()) {
      if(iflag) return NULL;
      else myerr_msg(aid + " not found",__FUNCTION__);
   }
   return it->second;
}

/** ------------- Access classname dynamically --------------------*/

string FlexMatrix::className() const {return "FlexMatrix";}

/** ------------- Error Message Handling Functions ------------------*/

void FlexMatrix::myerr_msg(string msg, string func) {
	err_msg("FlexMatrix::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void FlexMatrix::fprint(string fname) {
	Model::fprint(fname);
	Summarizable::fprint(fname);
	fprint_FlexMatrix(fname);
}

void FlexMatrix::fprint_FlexMatrix(string fname) {
	util_ofprint_obj(fname,"protomat",_protomat);

   {
      set<string> aidS;
      util_keys(_fmval, &aidS);
      util_ofprint(fname,"aidS",&aidS);
   }

   {
      unordered_map<string,Matrix*>::iterator itval;
      unordered_map<string,Matrix*>::iterator itflag;
      Matrix* Xval = NULL;
      Matrix* Xflag = NULL;
      string aid;

      for(itval=_fmval->begin();itval!=_fmval->end();itval++) {
         aid = itval->first;
         itflag = _fmflag->find(aid);
         if(itflag==_fmflag->end()) myerr_msg(aid + " not found in fmflag",__FUNCTION__);
         Xval = itval->second;
         Xflag = itflag->second;

         util_ofprint_obj(fname,util_join(".","fmval",aid),Xval);
         util_ofprint_obj(fname,util_join(".","fmflag",aid),Xflag);
      }
   }
}

void FlexMatrix::fscan(string fname) {
	Model::fscan(fname);
	Summarizable::fscan(fname);
	fscan_FlexMatrix(fname);
}

void FlexMatrix::fscan_FlexMatrix(string fname) {
   set<string>* aidS = NULL;
   set<string>::iterator it;

   _protomat = Matrix::instance_fscan( util_ofname(fname, "protomat") );
   init_fm();

   util_ofscan(fname, "aidS", aidS);
   for(it=aidS->begin();it!=aidS->end();it++) {
      string aid = *it;
      Matrix* val = NULL;
      Matrix* flag = NULL;

      val = Matrix::instance_fscan( util_ofname(fname, util_join(".","fmval", aid)) );
      flag = Matrix::instance_fscan( util_ofname(fname, util_join(".","fmflag", aid)) );

      add_fm(aid, val, flag);
   }

   //clean memory
   delete aidS;

   return;
}

/** ------------- Reset Functions --------------------*/

void FlexMatrix::reset() {
	reset_FlexMatrix();
	Model::reset();
	Summarizable::reset();
}

void FlexMatrix::reset_FlexMatrix() {
}

/** ----------  static instance function -----------*/


FlexMatrix* FlexMatrix::instance(Matrix* protomat)	{
	FlexMatrix* ptr=new FlexMatrix();
	ptr->init(protomat);
	return ptr;
}


FlexMatrix* FlexMatrix::instance_fscan(string fname)	{
	FlexMatrix* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new FlexMatrix();
		ptr->init_NULL();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

bool FlexMatrix::chk_consistency(Matrix* X) {
   Matrix* protomat = this->protomat();
   bool flag;

   flag = true;
   flag = flag && (X->m() == protomat->m());
   flag = flag && (X->n() == protomat->n());
   flag = flag && util_isEqual(protomat->rmap(), X->rmap(), protomat->m());
   flag = flag && util_isEqual(protomat->cmap(), X->cmap(), protomat->n());
   return flag;
}

FlexMatrix* FlexMatrix::fvix(int N) {
   Matrix* fm_protomat = NULL;
   FlexMatrix* fm = NULL;

   {
      Matrix* protomat = this->protomat();
      set<int> xrS;

      for(int i=0;i<N;i++) xrS.insert(i);
      fm_protomat = protomat->sub(NULL, NULL, &xrS, NULL);
      fm = FlexMatrix::instance(fm_protomat);
   }

   {
      set<string> aidS;
      set<string>::iterator it;

      util_keys(_fmval, &aidS);
      for(it=aidS.begin();it!=aidS.end();it++) this->fvix(fm, *it, N);
   }

   return fm;
}

void FlexMatrix::fvix(FlexMatrix* fvix, string aid, int N) {
   Matrix* val = this->fmval(aid);
   Matrix* flag = this->fmflag(aid);

   Matrix* fvix_val = NULL;
   Matrix* fvix_flag = NULL;

   double** valX = NULL;
   double** flagX = NULL;
   double** fvix_valX = NULL;
   double** fvix_flagX = NULL;

   double* x = NULL;
   double avg, std;
   int m, n, ii;

   fvix_val = fvix->protomat()->copy();
   fvix_flag = fvix->protomat()->copy();

   m = fvix_val->m();
   n = fvix_val->n();

   valX = val->X();
   flagX = flag->X();
   fvix_valX = fvix_val->X();
   fvix_flagX = fvix_flag->X();

   x = new double[N];
   for(int i=0;i<m;i++) {
      for(int j=0;j<n;j++) {
         for(int k=0;k<N && util_isZero(fvix_flagX[i][j]);k++) {
            ii = i + k;
            if(! util_isZero(flagX[ii][j])) fvix_flagX[i][j] = 1;
            else x[k] = valX[ii][j];
         }

         if(! util_isZero(fvix_flagX[i][j])) continue;

         ii = i+N;
         avg = mathutil_mean(x, N);
         std = mathutil_std(x, N, &avg, NULL, false);
         if(util_isZero(std)) fvix_flagX[i][j] = 1;
         if(! util_isZero(fvix_flagX[i][j])) continue;

         fvix_valX[i][j] = (valX[ii][j]-avg)/std;
      }
   }

   fvix->add_fm(aid, fvix_val, fvix_flag);

   //clean memory
   delete [] x;

   return;
}

bool FlexMatrix::isEqual(FlexMatrix* fm1) {return FlexMatrix::isEqual(this, fm1);}

bool FlexMatrix::isEqual(FlexMatrix* fm1, FlexMatrix* fm2) {
   if(fm1==NULL && fm2==NULL) return true;
   if(fm1==NULL || fm2==NULL) return false;
   if(!Matrix::isEqual(fm1->protomat(),fm2->protomat(),false,false,true,true)) return false;

   Matrix* val1 = NULL;
   Matrix* flag1 = NULL;
   Matrix* val2 = NULL;
   Matrix* flag2 = NULL;
   set<string> aidS;
   set<string>::iterator it;
   string aid;

   util_keys(fm1->fmval(),&aidS);
   for(it=aidS.begin();it!=aidS.end();it++) {
      aid = *it;

      val1 = fm1->fmval(aid, true);
      flag1 = fm1->fmflag(aid, true);
      val2 = fm2->fmval(aid, true);
      flag2 = fm2->fmflag(aid, true);

      if(!Matrix::isEqual(val1, val2)) return false;
      if(!Matrix::isEqual(flag1, flag2)) return false;
   }

   return true;
}

DatedMatrix* FlexMatrix::dm() {
   Matrix* protomat = this->protomat();
   unordered_map<string,Matrix*>* fmval = this->fmval();
   unordered_map<string,Matrix*>* fmflag = this->fmflag();

   int ndates = protomat->m();
   string* dates = protomat->rmap();

   DatedMatrix* dm = NULL;
   unordered_map<string,Matrix*>::iterator it;

   dm = DatedMatrix::instance();

   for(int i=0;i<ndates;i++) {
      UtilDate* d = UtilDate::instance(dates[i]);
      Matrix* X = NULL;

      string* rmap = NULL;
      string* cmap = NULL;
      double** XX = NULL;
      int mX, nX;

      nX = protomat->n();
      cmap = util_copy(protomat->cmap(), nX);

      rmap = new string[fmval->size()];
      mX = 0;
      for(it=fmval->begin();it!=fmval->end();it++) {
         string aid = it->first;
         double** flagX = fmflag->find(aid)->second->X();
         bool flag = false;
         for(int k=0;k<nX && (!flag);k++) if(util_isZero(flagX[i][k])) flag = true;
         if(flag) rmap[mX++] = aid;
      }

      X = Matrix::instance(mX, nX, NULL, rmap, NULL, cmap, NULL);
      XX = X->X();

      for(int ii=0;ii<mX;ii++) {
         string aid = rmap[ii];
         double** valX = fmval->find(aid)->second->X();
         for(int j=0;j<nX;j++) XX[ii][j] = valX[i][j];
      }

      dm->add(d, X);
   }

   return dm;
}

#endif

