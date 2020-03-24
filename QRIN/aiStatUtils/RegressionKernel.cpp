// Name:     RegressionKernel.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_RegressionKernel_cpp
#define ASX_RegressionKernel_cpp


#include <stdio.h>
#include <math.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "MatrixProcessor.hpp"
#include "Matrix.hpp"
#include "ModelGen.hpp"
#include "RegressionKernel.hpp"
#include "MathUtils.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiStatUtils;
using namespace aiMathUtils;
using namespace aiMath;
using namespace aiMathUtils;

/** --------------Constructors and init_NULL-----------*/

RegressionKernel::RegressionKernel() { init_NULL(); }
RegressionKernel::RegressionKernel(const RegressionKernel* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
RegressionKernel::RegressionKernel(const RegressionKernel& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void RegressionKernel::init_NULL()	{
	_proc=NULL;
	_Delta_proc=NULL;
	_beta=NULL;
	_Omega_beta=NULL;
	_X=NULL;
	_Delta=NULL;
	_m2=NULL;

   //set debug information
   {
      Object** ptr = NULL;
      ptr = (Object**) (&_proc); add_debug_objm("proc",ptr);
      ptr = (Object**) (&_Delta_proc); add_debug_objm("Delta_proc",ptr);
   }
}

/** ---Public Data Setting Functions-----------------*/

void RegressionKernel::set_proc(MatrixProcessor* _obj) {
   cleanMem_proc();
   _proc = _obj;
}

void RegressionKernel::set_Delta_proc(MatrixProcessor* _obj) {
   cleanMem_Delta_proc();
   _Delta_proc = _obj;
}

void RegressionKernel::set_beta(Matrix* _obj) {
   cleanMem_beta();
   _beta = _obj;
}

void RegressionKernel::set_Omega_beta(Matrix* _obj) {
   cleanMem_Omega_beta();
   _Omega_beta = _obj;
}

void RegressionKernel::set_sigma_u(double _obj) {
	_sigma_u=_obj;
}

void RegressionKernel::set_X(Matrix* _obj) {
   cleanMem_X();
   _X = _obj;
}

void RegressionKernel::set_Delta(Matrix* _obj) {
   cleanMem_Delta();
   _Delta = _obj;
}

void RegressionKernel::set_m2(Matrix* _obj) {
   cleanMem_m2();
   _m2 = _obj;
}

/** --------   Init Functions -------------------------*/

void RegressionKernel::init(MatrixProcessor* proc, 
                            MatrixProcessor* Delta_proc,
                            Matrix* beta, 
                            Matrix* Omega_beta, double sigma_u) 
{
   ModelGen::init();
	init_RegressionKernel(proc, Delta_proc, beta, Omega_beta, sigma_u);
}

void RegressionKernel::init_RegressionKernel(MatrixProcessor* proc, 
                                             MatrixProcessor* Delta_proc,
                                             Matrix* beta, 
                                             Matrix* Omega_beta, double sigma_u) 
{
	init_proc(proc);
	init_Delta_proc(Delta_proc);
	init_beta(beta);
	init_Omega_beta(Omega_beta);
	init_sigma_u(sigma_u);
}

void RegressionKernel::init_proc(MatrixProcessor* proc) {
   set_proc(proc);
}

void RegressionKernel::init_Delta_proc(MatrixProcessor* proc) {
   set_Delta_proc(proc);
}

void RegressionKernel::init_beta(Matrix* obj) {set_beta(obj);}
void RegressionKernel::init_Omega_beta(Matrix* obj) {set_Omega_beta(obj);}
void RegressionKernel::init_sigma_u(double obj) {set_sigma_u(obj);}

/** -----Destructors and Memory Cleanup functions -----*/

RegressionKernel::~RegressionKernel()	{ cleanMem(); }

void RegressionKernel::cleanMem()	{
	cleanMem_RegressionKernel();
	ModelGen::cleanMem();
}

void RegressionKernel::cleanMem_RegressionKernel() {
	cleanMem_proc();
	cleanMem_Delta_proc();
	cleanMem_beta();
	cleanMem_Omega_beta();
	cleanMem_X();
	cleanMem_Delta();
	cleanMem_m2();
}

void RegressionKernel::cleanMem_proc() {
   delete _proc;
	_proc=NULL;
}

void RegressionKernel::cleanMem_Delta_proc() {
   delete _Delta_proc;
	_Delta_proc=NULL;
}

void RegressionKernel::cleanMem_beta() {
   delete _beta;
	_beta=NULL;
}

void RegressionKernel::cleanMem_Omega_beta() {
   delete _Omega_beta;
	_Omega_beta=NULL;
}

void RegressionKernel::cleanMem_X() {
	_X=NULL;
}

void RegressionKernel::cleanMem_Delta() {
	_Delta=NULL;
}

void RegressionKernel::cleanMem_m2() {
   delete _m2;
	_m2=NULL;
}

/** ------------- Data Access Functions --------------------*/

MatrixProcessor* RegressionKernel::proc() {return _proc;}
MatrixProcessor* RegressionKernel::Delta_proc() {return _Delta_proc;}
Matrix* RegressionKernel::beta() {return _beta;}
Matrix* RegressionKernel::Omega_beta() {return _Omega_beta;}
double RegressionKernel::sigma_u() {return _sigma_u;}
Matrix* RegressionKernel::X() {return _X;}
Matrix* RegressionKernel::Delta() {return _Delta;}
Matrix* RegressionKernel::m2() {return _m2;}

/** ------------- Access classname dynamically --------------------*/

string RegressionKernel::className() const {return "RegressionKernel";}

/** ------------- Error Message Handling Functions ------------------*/

void RegressionKernel::myerr_msg(string msg, string func) {
	err_msg("RegressionKernel::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void RegressionKernel::fprint(string fname) {
	ModelGen::fprint(fname);
	fprint_RegressionKernel(fname);
}

void RegressionKernel::fprint_RegressionKernel(string fname) {
	util_ofprint_obj(fname,"proc",_proc);
	util_ofprint_obj(fname,"Delta_proc",_Delta_proc);
	util_ofprint_obj(fname,"beta",_beta);
	util_ofprint_obj(fname,"Omega_beta",_Omega_beta);
	util_ofprint(fname,"sigma_u",_sigma_u);
}

void RegressionKernel::fscan(string fname) {
	ModelGen::fscan(fname);
	fscan_RegressionKernel(fname);
}

void RegressionKernel::fscan_RegressionKernel(string fname) {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
}

/** ------------- Reset Functions --------------------*/

void RegressionKernel::reset() {
	reset_RegressionKernel();
	ModelGen::reset();
}

void RegressionKernel::reset_RegressionKernel() {
	reset_proc();
	reset_Delta_proc();
	reset_X();
	reset_Delta();
	reset_m2();
}

void RegressionKernel::reset_proc() {if(_proc!=NULL) _proc->reset();}
void RegressionKernel::reset_Delta_proc() {if(_Delta_proc!=NULL) _Delta_proc->reset();}
void RegressionKernel::reset_X() {set_X(NULL);}
void RegressionKernel::reset_Delta() {set_Delta(NULL);}
void RegressionKernel::reset_m2() {set_m2(NULL);}

/** ----------  static instance function -----------*/


RegressionKernel* RegressionKernel::instance(MatrixProcessor* proc, 
                                             MatrixProcessor* Delta_proc,
                                             Matrix* beta, 
                                         Matrix* Omega_beta, double sigma_u)	
{
	RegressionKernel* ptr=new RegressionKernel();
	ptr->init(proc, Delta_proc, beta, Omega_beta, sigma_u);
	return ptr;
}


RegressionKernel* RegressionKernel::instance_fscan(string fname)	{
	RegressionKernel* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new RegressionKernel();
		ptr->init_NULL();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

Matrix* RegressionKernel::mdl() {return (Matrix*) ModelGen::mdl();}
Matrix* RegressionKernel::extract_mdl() {return (Matrix*) ModelGen::extract_mdl();}
Matrix* RegressionKernel::extract_m2() {
   Matrix* m2 = this->m2();
   _m2 = NULL;
   return m2;
}

void RegressionKernel::configure(Matrix* X, Matrix* Delta) {
   ModelGen::configure();
   set_X(X);
   set_Delta(Delta);
   return;
}

void RegressionKernel::algo_exec() {
   MatrixProcessor* proc = this->proc();
   MatrixProcessor* Delta_proc = this->Delta_proc();
   Matrix* beta = this->beta();
   Matrix* Omega_beta = this->Omega_beta();
   double sigma_u = this->sigma_u();

   Matrix* X = this->X();
   Matrix* Delta = this->Delta();
   Matrix* fc = NULL;
   Matrix* m2 = NULL;
   list<Object*> matL;
   int n;

   n = X->m();

   debug3("Delta",Delta);
   if(Delta_proc!=NULL && Delta!=NULL) matL.push_back(Delta=Delta_proc->exec(Delta, NULL));
   debug("Delta_proc",Delta);

   debug3("X",X);
   if(proc!=NULL && X!=NULL) matL.push_back(X=proc->exec(X, Delta));
   debug3("X_proc",X);

   fc = Matrix::mult(X,beta);
   debug3("fc",fc);

   //construct the confidence interval
   {
      Matrix* D = NULL;
      Matrix* S = NULL;
      double** m2X = NULL;
      double** SX = NULL;

      if(Delta==NULL) D = Matrix::ones(n,1);
      else D = Delta->copy();
      D->_mult(sigma_u);
      D->_hpow(2);
      matL.push_back(D);

      matL.push_back( S = mathutil_diag_ABAT_p_diagC(X,Omega_beta,D) );

      m2 = Matrix::instance(n, 1);
      m2X = m2->X();
      SX = S->X();
      for(int i=0;i<n;i++) {
         m2X[i][0] = sqrt(SX[i][0]);
      }
   }

   set_mdl(fc);
   set_m2(m2);

   //clean memory
   util_clean_obj(&matL);

   return;
}

bool RegressionKernel::isEqual(RegressionKernel* fk) {
   if(! this->beta()->isEqual(fk->beta()) ) return false;
   if(! this->Omega_beta()->isEqual(fk->Omega_beta()) ) return false;
   if(! util_isEqual(this->sigma_u(), fk->sigma_u()) ) return false;
   return true;
}

RegressionKernel* RegressionKernel::copy() {
   MatrixProcessor* proc = NULL;
   MatrixProcessor* Delta_proc = NULL;
   Matrix* beta = NULL;
   Matrix* Omega_beta = NULL;
   double sigma_u;
   RegressionKernel* ptr = NULL;

   if(this->proc()!=NULL) proc = this->proc()->copy();
   if(this->Delta_proc()!=NULL) Delta_proc = this->Delta_proc()->copy();
   if(this->beta()!=NULL) beta = this->beta()->copy();
   if(this->Omega_beta()!=NULL) Omega_beta = this->Omega_beta()->copy();
   sigma_u = this->sigma_u();

   ptr = RegressionKernel::instance(proc, Delta_proc, beta, Omega_beta, sigma_u);

   return ptr;
}

#endif

