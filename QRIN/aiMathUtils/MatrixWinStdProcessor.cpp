// Name:     MatrixWinStdProcessor.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_MatrixWinStdProcessor_cpp
#define ASX_MatrixWinStdProcessor_cpp


#include <stdio.h>
#include <math.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "MathUtils.hpp"
#include "MatrixCentralizer.hpp"
#include "Matrix.hpp"
#include "MatrixWinStdProcessor.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMathUtils;
using namespace aiMath;

/** --------------Constructors and init_NULL-----------*/

MatrixWinStdProcessor::MatrixWinStdProcessor() { init_NULL(); }
MatrixWinStdProcessor::MatrixWinStdProcessor(const MatrixWinStdProcessor* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
MatrixWinStdProcessor::MatrixWinStdProcessor(const MatrixWinStdProcessor& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void MatrixWinStdProcessor::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

void MatrixWinStdProcessor::set_alpha(double _obj) {
	_alpha=_obj;
}

void MatrixWinStdProcessor::set_std_flag(bool _obj) {
	_std_flag=_obj;
}

/** --------   Init Functions -------------------------*/

void MatrixWinStdProcessor::init(bool insitu, bool row_flag, 
                                 Matrix* loc, Matrix* disp, 
                                 double alpha, bool std_flag) {
   MatrixCentralizer::init(insitu,row_flag, loc, disp);
	init_MatrixWinStdProcessor(alpha, std_flag);
}

void MatrixWinStdProcessor::init_MatrixWinStdProcessor(double alpha, bool std_flag) {
	init_alpha(alpha);
	init_std_flag(std_flag);
}

void MatrixWinStdProcessor::init_alpha(double obj) {set_alpha(obj);}
void MatrixWinStdProcessor::init_std_flag(bool obj) {set_std_flag(obj);}

/** -----Destructors and Memory Cleanup functions -----*/

MatrixWinStdProcessor::~MatrixWinStdProcessor()	{ cleanMem(); }

void MatrixWinStdProcessor::cleanMem()	{
	cleanMem_MatrixWinStdProcessor();
   MatrixCentralizer::cleanMem();
}

void MatrixWinStdProcessor::cleanMem_MatrixWinStdProcessor() {
}

/** ------------- Data Access Functions --------------------*/

double MatrixWinStdProcessor::alpha() {return _alpha;}
bool MatrixWinStdProcessor::std_flag() {return _std_flag;}

/** ------------- Access classname dynamically --------------------*/

string MatrixWinStdProcessor::className() const {return "MatrixWinStdProcessor";}

/** ------------- Error Message Handling Functions ------------------*/

void MatrixWinStdProcessor::myerr_msg(string msg, string func) {
	err_msg("MatrixWinStdProcessor::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void MatrixWinStdProcessor::fprint(string fname) {
   MatrixCentralizer::fprint(fname);
	fprint_MatrixWinStdProcessor(fname);
}

void MatrixWinStdProcessor::fprint_MatrixWinStdProcessor(string fname) {
	util_ofprint(fname,"alpha",_alpha);
	util_ofprint(fname,"std_flag",_std_flag);
}

void MatrixWinStdProcessor::fscan(string fname) {
   MatrixCentralizer::fscan(fname);
	fscan_MatrixWinStdProcessor(fname);
}

void MatrixWinStdProcessor::fscan_MatrixWinStdProcessor(string fname) {
	util_ofscan(fname,"alpha",_alpha);
	util_ofscan(fname,"std_flag",_std_flag);
}

/** ------------- Reset Functions --------------------*/

void MatrixWinStdProcessor::reset() {
	reset_MatrixWinStdProcessor();
   MatrixCentralizer::reset();
}

void MatrixWinStdProcessor::reset_MatrixWinStdProcessor() {
}

/** ----------  static instance function -----------*/


MatrixWinStdProcessor* MatrixWinStdProcessor::instance(bool insitu, bool row_flag,
                                                       Matrix* loc, Matrix* disp,
                                                       double alpha, bool std_flag)
{
	MatrixWinStdProcessor* ptr=new MatrixWinStdProcessor();
	ptr->init(insitu, row_flag, loc, disp, alpha, std_flag);
	return ptr;
}


MatrixWinStdProcessor* MatrixWinStdProcessor::instance_fscan(string fname)	{
	MatrixWinStdProcessor* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new MatrixWinStdProcessor();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

void MatrixWinStdProcessor::configure(Matrix* X, Matrix* Delta) {
   MatrixCentralizer::configure(X, Delta);
   return;
}

void MatrixWinStdProcessor::algo_exec() {
   MatrixCentralizer::algo_exec();
   bool log_flag = this->log_flag();
   Matrix* X = this->X();
   Matrix* Y = (Matrix*) this->mdl();

   list<Object*> memL;
   Matrix* winX = NULL;
   Matrix* Xloc = NULL;
   Matrix* Xdisp = NULL;
   double* vec = NULL;
   double** YX = NULL;
   double alpha = _alpha;
   double std_flag = _std_flag;
   double mean, std, zs;
   int m, n;

   debug("X",X);
   debug("Delta",Delta());

   if(log_flag) {
      memL.push_back(X = X->hpow(-2));
      X->_hlog();
      debug("Xlogi2",X);
   }

   if(row_flag()) myerr_msg("row_flag=true functionality not yet implemented",__FUNCTION__);
   m = X->m();
   n = X->n();
   YX = Y->X();
   vec = new double[m];

   winX = Matrix::winsorize(X, false, alpha, 1-alpha);
   debug("__winX", winX);

   {
      bool loc_flag = loc()==NULL;
      bool disp_flag = disp()==NULL;

      if(!loc_flag) Xloc = loc()->copy();
      else Xloc = winX->mean_col(Delta(),true);

      if(!disp_flag) Xdisp = disp()->copy();
      else Xdisp = Matrix::instance(1,n);

      for(int j=0;j<n;j++) {
         winX->copycol(j,vec);
         mean = Xloc->X()[0][j];

         if(!disp_flag) std = Xdisp->X()[0][j];
         else {
            if(std_flag) std = mathutil_std(vec, m, &mean, Delta(), true);
            else std = 1.0;
            Xdisp->X()[0][j] = std;
         }

         for(int i=0;i<m;i++) {
            zs = (vec[i]-mean);
            if(! util_isZero(std)) zs = zs/std;
            YX[i][j] = zs; 
         }
      }
   }

   if(log_flag) {
      Y->_hexp();
      Y->_hpow(-0.5);
   }

   //orthogonalize columns in orthoS
   if(orthoS_flag()) {
      set<int>* orthoS = this->orthoS();
      set<int>::iterator it;
      double** YX = Y->X();
      int m = Y->m();
      int j;

      for(it=orthoS->begin();it!=orthoS->end();it++) {
         j = *it;
         for(int i=0;i<m;i++) YX[i][j] = 0;
      }
   }

   set_Xloc(Xloc);
   set_Xdisp(Xdisp);

   debug("Xloc",Xloc);
   debug("Xdisp",Xdisp);
   debug("mdl",mdl());

   //clean memory
   delete [] vec;
   delete winX;
   util_clean_obj(&memL);

   return;
}

Matrix* MatrixWinStdProcessor::exec(Matrix* X, Matrix* Delta) {
   if(X==NULL) return NULL;
   Matrix* mdl = NULL;
   configure(X, Delta);
   algo_exec();
   mdl = extract_mdl();
   reset();
   return mdl;
}

MatrixProcessor* MatrixWinStdProcessor::kernel() {
   MatrixWinStdProcessor* proc = MatrixWinStdProcessor::instance(this->insitu(), this->row_flag(),
                                                           Matrix::copy(this->Xloc()), 
                                                           Matrix::copy(this->Xdisp()),
                                                           this->alpha(), this->std_flag());
   proc->set_log_flag(log_flag());
   proc->add_orthoS(orthoS());
   return proc;
}

MatrixProcessor* MatrixWinStdProcessor::copy() {
   MatrixWinStdProcessor* proc = MatrixWinStdProcessor::instance(this->insitu(), this->row_flag(),
                                                           Matrix::copy(this->loc()), 
                                                           Matrix::copy(this->disp()),
                                                           this->alpha(), this->std_flag());
   proc->set_log_flag(log_flag());
   proc->add_orthoS(orthoS());
   return proc;
}

#endif

