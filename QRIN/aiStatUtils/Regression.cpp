// Name:     Regression.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_Regression_cpp
#define ASX_Regression_cpp


#include <stdio.h>
#include <math.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Matrix.hpp"
#include "ModelGen.hpp"
#include "Model.hpp"
#include "FactorModel.hpp"
#include "Regression.hpp"
#include "RegressionKernel.hpp"
#include "MathUtils.hpp"
#include "MatrixProcessor.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMath;
using namespace aiStat;
using namespace aiStatUtils;
using namespace aiMathUtils;

/** --------------Constructors and init_NULL-----------*/

Regression::Regression() { init_NULL(); }
Regression::Regression(const Regression* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
Regression::Regression(const Regression& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void Regression::init_NULL()	{
	_y=NULL;
	_X=NULL;
	_Delta=NULL;
	_proc=NULL;
	_y_proc=NULL;
	_Delta_proc=NULL;
	_f=NULL;
	_tstat=NULL;
	_fk=NULL;

   //debugging information
   {
      Object** ptr = NULL;
      ptr = (Object**) (&_proc); add_debug_objm("proc",ptr);
      ptr = (Object**) (&_y_proc); add_debug_objm("y_proc",ptr);
      ptr = (Object**) (&_Delta_proc); add_debug_objm("Delta_proc",ptr);
      ptr = (Object**) (&_fk); add_debug_objm("fk",ptr);
   }
}

/** ---Public Data Setting Functions-----------------*/

void Regression::set_y(Matrix* _obj) {cleanMem_y(); _y = _obj;}
void Regression::set_X(Matrix* _obj) {cleanMem_X(); _X = _obj;}
void Regression::set_Delta(Matrix* _obj) {cleanMem_Delta(); _Delta = _obj;}
void Regression::set_proc(MatrixProcessor* _obj) {cleanMem_proc(); _proc = _obj;}
void Regression::set_y_proc(MatrixProcessor* _obj) {cleanMem_y_proc(); _y_proc = _obj;}
void Regression::set_Delta_proc(MatrixProcessor* _obj) {cleanMem_Delta_proc(); _Delta_proc = _obj;}
void Regression::set_f(Matrix* _obj) {cleanMem_f(); _f = _obj;}
void Regression::set_tstat(Matrix* _obj) {cleanMem_tstat(); _tstat = _obj;}
void Regression::set_fk(RegressionKernel* _obj) {cleanMem_fk(); _fk = _obj;}

/** --------   Init Functions -------------------------*/

void Regression::init() {
   ModelGen::init();
	init_Regression();
}

void Regression::init_Regression() {
}

/** -----Destructors and Memory Cleanup functions -----*/

Regression::~Regression()	{ cleanMem(); }

void Regression::cleanMem()	{
	cleanMem_Regression();
   ModelGen::cleanMem();
}

void Regression::cleanMem_Regression() {
	cleanMem_y();
	cleanMem_X();
	cleanMem_Delta();
	cleanMem_proc();
	cleanMem_y_proc();
	cleanMem_Delta_proc();
	cleanMem_f();
	cleanMem_tstat();
	cleanMem_fk();
}

void Regression::cleanMem_y() {
	_y=NULL;
}

void Regression::cleanMem_X() {
	_X=NULL;
}

void Regression::cleanMem_Delta() {
	_Delta=NULL;
}

void Regression::cleanMem_proc() {
   delete _proc;
	_proc=NULL;
}

void Regression::cleanMem_y_proc() {
   delete _y_proc;
	_y_proc=NULL;
}

void Regression::cleanMem_Delta_proc() {
   delete _Delta_proc;
	_Delta_proc=NULL;
}

void Regression::cleanMem_f() {
   delete _f;
	_f=NULL;
}

void Regression::cleanMem_tstat() {
   delete _tstat;
	_tstat=NULL;
}

void Regression::cleanMem_fk() {
   delete _fk;
	_fk=NULL;
}

/** ------------- Data Access Functions --------------------*/

Matrix* Regression::y() {return _y;}
Matrix* Regression::X() {return _X;}
Matrix* Regression::Delta() {return _Delta;}
MatrixProcessor* Regression::proc() {return _proc;}
MatrixProcessor* Regression::y_proc() {return _y_proc;}
MatrixProcessor* Regression::Delta_proc() {return _Delta_proc;}
Matrix* Regression::f() {return _f;}
Matrix* Regression::tstat() {return _tstat;}
RegressionKernel* Regression::fk() {return _fk;}

FactorModel* Regression::mdl() {return (FactorModel*) ModelGen::mdl();}

/** ------------- Access classname dynamically --------------------*/

string Regression::className() const {return "Regression";}

/** ------------- Error Message Handling Functions ------------------*/

void Regression::myerr_msg(string msg, string func) {
	err_msg("Regression::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void Regression::fprint(string fname) {
   ModelGen::fprint(fname);
	fprint_Regression(fname);
}

void Regression::fprint_Regression(string fname) {
	util_ofprint_obj(fname,"y",_y);
	util_ofprint_obj(fname,"X",_X);
	util_ofprint_obj(fname,"Delta",_Delta);
	util_ofprint_obj(fname,"proc",_proc);
	util_ofprint_obj(fname,"y_proc",_y_proc);
	util_ofprint_obj(fname,"Delta_proc",_Delta_proc);
	util_ofprint_obj(fname,"f",_f);
	util_ofprint_obj(fname,"tstat",_tstat);
	util_ofprint_obj(fname,"fk",_fk);
}

void Regression::fscan(string fname) {
   ModelGen::fscan(fname);
	fscan_Regression(fname);
}

void Regression::fscan_Regression(string fname) {
   _y = Matrix::instance_fscan(util_ofname(fname,"y"));
   _X = Matrix::instance_fscan(util_ofname(fname,"X"));
   _Delta = Matrix::instance_fscan(util_ofname(fname,"Delta"));
   //proc is not fscanned 
   //y_proc is not fscanned 
   //Delta_proc is not fscanned 
   _f = Matrix::instance_fscan(util_ofname(fname,"f"));
   _tstat = Matrix::instance_fscan(util_ofname(fname,"tstat"));
   _fk = RegressionKernel::instance_fscan(util_ofname(fname,"fk"));
}

/** ------------- Reset Functions --------------------*/

void Regression::reset() {
	reset_Regression();
   ModelGen::reset();
}

void Regression::reset_Regression() {
	reset_y();
	reset_X();
	reset_Delta();
	reset_proc();
	reset_y_proc();
	reset_Delta_proc();
	reset_f();
	reset_tstat();
	reset_fk();
}

void Regression::reset_y() {cleanMem_y();}
void Regression::reset_X() {cleanMem_X();}
void Regression::reset_Delta() {cleanMem_Delta();}
void Regression::reset_proc() { if(_proc!=NULL) _proc->reset();}
void Regression::reset_y_proc() { if(_y_proc!=NULL) _y_proc->reset();}
void Regression::reset_Delta_proc() { if(_Delta_proc!=NULL) _Delta_proc->reset();}
void Regression::reset_f() {cleanMem_f();}
void Regression::reset_tstat() {cleanMem_tstat();}
void Regression::reset_fk() {cleanMem_fk();}

/** ----------  static instance function -----------*/


Regression* Regression::instance()	{
	Regression* ptr=new Regression();
	ptr->init();
	return ptr;
}


Regression* Regression::instance_fscan(string fname)	{
	Regression* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new Regression();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

FactorModel* Regression::extract_mdl() {return (FactorModel*) ModelGen::extract_mdl();}

void Regression::configure(Matrix* y, Matrix* X, Matrix* Delta) {
   ModelGen::configure();
   set_y(y);
   set_X(X);
   set_Delta(Delta);

   //check for inconsistencies in input parameters
   {
      if(y==NULL) myerr_msg("y==NULL",__FUNCTION__);
      if(X==NULL) myerr_msg("X==NULL",__FUNCTION__);
      if(y->m()!=X->m()) myerr_msg("y->m()!=X->m()",__FUNCTION__);
      if(Delta!=NULL && (y->m()!=Delta->m())) myerr_msg("y->m()!=Delta->m()",__FUNCTION__);
   }
   
   return;
}

/** f = (XTX).I * XT.y */
void Regression::algo_exec() {
   ModelGen::algo_exec();

   Matrix* y = this->y();
   Matrix* X = this->X();
   Matrix* Delta = this->Delta();
   MatrixProcessor* proc = this->proc();
   MatrixProcessor* y_proc = this->y_proc();
   MatrixProcessor* Delta_proc = this->Delta_proc();
   Matrix* XTX = NULL;
   Matrix* XTy = NULL;
   Matrix* f = NULL;
   MatrixProcessor* fk_proc = NULL;
   MatrixProcessor* fk_Delta_proc = NULL;
   RegressionKernel* fk = NULL;
   list<Object*> objL;

   debug3("y",y);
   debug3("X",X);
   debug3("Delta",Delta);

   if(Delta_proc!=NULL && Delta!=NULL) {
      Matrix* tmp = NULL;
      bool insitu = Delta_proc->insitu();

      Delta_proc->configure(Delta,NULL);
      Delta_proc->algo_exec();
      fk_Delta_proc = Delta_proc->kernel();
      tmp = Delta_proc->extract_mdl();
      if(!insitu) objL.push_back(Delta=tmp);
      Delta_proc->reset();
   }

   if(y_proc!=NULL) {
      Matrix* tmp = NULL;
      bool insitu = y_proc->insitu();

      tmp = y_proc->exec(y,Delta);
      if(!insitu) objL.push_back(y=tmp);

      y_proc->reset();
   }

   if(proc!=NULL) {
      Matrix* tmp = NULL;
      bool insitu = proc->insitu();

      proc->configure(X,Delta);
      proc->algo_exec();
      fk_proc = proc->kernel();
      tmp = proc->extract_mdl();
      if(!insitu) objL.push_back(X=tmp);
      proc->reset();
   }

   XTX = Matrix::mult(X,X,true,false,Delta,true);
   XTy = Matrix::mult(X,y,true,false,Delta,true);
   f = Matrix::solve_sym(XTX, XTy);

   debug3("__XTX",XTX);
   debug3("__XTy",XTy);
   
   //construct fk
   {
      Matrix* beta = NULL;
      Matrix* Omega_beta = NULL;
      Matrix* y0 = NULL;
      double sigma_u;

      y0 = y->col(0);
      beta = f->col(0);

      //compute sigma_u
      {
         Matrix* ymXf = mathutil_ymXf(y0,X,beta);
         Matrix* tmp = Matrix::mult(ymXf,ymXf,true,false,Delta,true);
         int n = X->m();
         int k = X->n();
         sigma_u = sqrt(tmp->X()[0][0]/(n-k+0.0));

         //clean memory
         delete ymXf;
         delete tmp;
      }

      //compute Omega_beta
      Omega_beta = Matrix::inverse(XTX);
      Omega_beta->_mult(pow(sigma_u,2));

      fk = RegressionKernel::instance(fk_proc, fk_Delta_proc, beta, Omega_beta, sigma_u);

      //clean memory
      delete y0;
   }

   //compute inferential statistics
   if(debug_mode()) {
      Matrix* Xf = NULL;
      Matrix* reg_stats = NULL;
      double sigma_u, R2, nvar, nobs;
      double numer, denom, effnobs;
      int i;

      nvar = X->n();
      nobs = X->m();
      if(Delta==NULL) effnobs = nobs;
      else effnobs = Delta->cc(false,0,NULL,true);
      sigma_u = fk->sigma_u();
      Xf = Matrix::mult(X, fk->beta());

      numer = Xf->l2n();
      denom = y->l2n();
      if(util_isZero(denom)) R2 = 0;
      else R2 = pow(numer/denom,2.0);

      reg_stats = Matrix::instance(1,5);
      i = 0;
      reg_stats->X()[0][i] = nvar; reg_stats->set_cmap_cimap(i++,"nvar");
      reg_stats->X()[0][i] = nobs; reg_stats->set_cmap_cimap(i++,"nobs");
      reg_stats->X()[0][i] = effnobs; reg_stats->set_cmap_cimap(i++,"effnobs");
      reg_stats->X()[0][i] = R2; reg_stats->set_cmap_cimap(i++,"R2");
      reg_stats->X()[0][i] = sigma_u; reg_stats->set_cmap_cimap(i++,"sigma_u");
      reg_stats->set_rmap_rimap(0,this->debug_id());

      debug3("reg_stats",reg_stats);

      //clean memory
      delete Xf;
      delete reg_stats;
   }

   set_f(f);
   set_fk(fk);

   debug3("f",f);
   debug("fk",fk);

   if(mdl_flag()) {
      Matrix* Xmdl = X->copy();
      Matrix* ymdl = y->copy();
      Matrix* fmdl = f->copy();
      Matrix* Delta_mdl = NULL;
      Matrix* Omega_mdl = NULL;

      if(Delta!=NULL) Delta_mdl = Delta->copy();
      if(fk!=NULL && fk->Omega_beta()!=NULL) Omega_mdl = fk->Omega_beta()->copy();

      set_mdl( FactorModel::instance(ymdl,Xmdl,fmdl,NULL,Omega_mdl,Delta_mdl) );
      mdl()->compute_u();
      debug("mdl",mdl());
   }

   //clean memory
   delete XTy;
   delete XTX;
   util_clean_obj(&objL);

   return;
}

RegressionKernel* Regression::extract_fk() {
   RegressionKernel* fk = _fk; 
   _fk = NULL;
   return fk;
}

#endif

