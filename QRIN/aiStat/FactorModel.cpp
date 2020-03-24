// Name:     FactorModel.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_FactorModel_cpp
#define ASX_FactorModel_cpp


#include <stdio.h>
#include <math.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "MathUtils.hpp"
#include "Matrix.hpp"
#include "Model.hpp"
#include "FactorModel.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMath;
using namespace aiMathUtils;
using namespace aiStat;

/** --------------Constructors and init_NULL-----------*/

FactorModel::FactorModel() { init_NULL(); }
FactorModel::FactorModel(const FactorModel* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
FactorModel::FactorModel(const FactorModel& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void FactorModel::init_NULL()	{
	_y=NULL;
	_X=NULL;
	_f=NULL;
	_u=NULL;
	_Omega=NULL;
	_Delta=NULL;
}

/** ---Public Data Setting Functions-----------------*/

void FactorModel::set_y(Matrix* _obj) {
   cleanMem_y();
   _y = _obj;
}

void FactorModel::set_X(Matrix* _obj) {
   cleanMem_X();
   _X = _obj;
}

void FactorModel::set_f(Matrix* _obj) {
   cleanMem_f();
   _f = _obj;
}

void FactorModel::set_u(Matrix* _obj) {
   cleanMem_u();
   _u = _obj;
}

void FactorModel::set_Omega(Matrix* _obj) {
   cleanMem_Omega();
   _Omega = _obj;
}

void FactorModel::set_Delta(Matrix* _obj) {
   cleanMem_Delta();
   _Delta = _obj;
}

/** --------   Init Functions -------------------------*/

void FactorModel::init(Matrix* y, Matrix* X, Matrix* f, Matrix* u, Matrix* Omega, Matrix* Delta) {
   Model::init();
	init_FactorModel(y,X,f,u,Omega,Delta);
}

void FactorModel::init_FactorModel(Matrix* y, Matrix* X, Matrix* f, Matrix* u, Matrix* Omega, Matrix* Delta) {
	init_y(y);
	init_X(X);
	init_f(f);
	init_u(u);
	init_Omega(Omega);
	init_Delta(Delta);
}

void FactorModel::init_y(Matrix* obj) { set_y(obj);}
void FactorModel::init_X(Matrix* obj) { set_X(obj);}
void FactorModel::init_f(Matrix* obj) { set_f(obj);}
void FactorModel::init_u(Matrix* obj) { set_u(obj);}
void FactorModel::init_Omega(Matrix* obj) { set_Omega(obj);}
void FactorModel::init_Delta(Matrix* obj) { set_Delta(obj);}

/** -----Destructors and Memory Cleanup functions -----*/

FactorModel::~FactorModel()	{ cleanMem(); }

void FactorModel::cleanMem()	{
	cleanMem_FactorModel();
   Model::cleanMem();
}

void FactorModel::cleanMem_FactorModel() {
	cleanMem_y();
	cleanMem_X();
	cleanMem_f();
	cleanMem_u();
	cleanMem_Omega();
	cleanMem_Delta();
}

void FactorModel::cleanMem_y() {delete _y; _y = NULL;}
void FactorModel::cleanMem_X() {delete _X; _X = NULL;}
void FactorModel::cleanMem_f() {delete _f; _f = NULL;}
void FactorModel::cleanMem_u() {delete _u; _u = NULL;}
void FactorModel::cleanMem_Omega() {delete _Omega; _Omega = NULL;}
void FactorModel::cleanMem_Delta() {delete _Delta; _Delta = NULL;}

/** ------------- Data Access Functions --------------------*/

Matrix* FactorModel::y() {return _y;}
Matrix* FactorModel::X() {return _X;}
Matrix* FactorModel::f() {return _f;}
Matrix* FactorModel::u() {return _u;}
Matrix* FactorModel::Omega() {return _Omega;}
Matrix* FactorModel::Delta() {return _Delta;}

/** ------------- Access classname dynamically --------------------*/

string FactorModel::className() const {return "FactorModel";}

/** ------------- Error Message Handling Functions ------------------*/

void FactorModel::myerr_msg(string msg, string func) {
	err_msg("FactorModel::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void FactorModel::fprint(string fname) {
   Model::fprint(fname);
	fprint_FactorModel(fname);
}

void FactorModel::fprint_FactorModel(string fname) {
	util_ofprint_obj(fname,"y",_y);
	util_ofprint_obj(fname,"X",_X);
	util_ofprint_obj(fname,"f",_f);
	util_ofprint_obj(fname,"u",_u);
	util_ofprint_obj(fname,"Omega",_Omega);
	util_ofprint_obj(fname,"Delta",_Delta);
}

void FactorModel::fscan(string fname) {
   Model::fscan(fname);
	fscan_FactorModel(fname);
}

void FactorModel::fscan_FactorModel(string fname) {
   _y = Matrix::instance_fscan( util_ofname(fname,"y"));
   _X = Matrix::instance_fscan( util_ofname(fname,"X"));
   _f = Matrix::instance_fscan( util_ofname(fname,"f"));
   _u = Matrix::instance_fscan( util_ofname(fname,"u"));
   _Omega = Matrix::instance_fscan( util_ofname(fname,"Omega"));
   _Delta = Matrix::instance_fscan( util_ofname(fname,"Delta"));
}

/** ------------- Reset Functions --------------------*/

void FactorModel::reset() {
	reset_FactorModel();
   Model::reset();
}

void FactorModel::reset_FactorModel() {
}

/** ----------  static instance function -----------*/


FactorModel* FactorModel::instance(Matrix* y, Matrix* X, Matrix* f, Matrix* u, Matrix* Omega, Matrix* Delta)	{
	FactorModel* ptr=new FactorModel();
	ptr->init(y,X,f,u,Omega,Delta);
	return ptr;
}


FactorModel* FactorModel::instance_fscan(string fname)	{
	FactorModel* ptr=NULL;
   if(!util_fscan_NULL(fname)) {
      ptr = new FactorModel();
      ptr->fscan(fname);
   }
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

void FactorModel::compute_u() {
   if(u()!=NULL) return;
   if(f()==NULL) myerr_msg("f==NULL",__FUNCTION__);
   if(X()==NULL) myerr_msg("X==NULL",__FUNCTION__);
   if(y()==NULL) myerr_msg("y==NULL",__FUNCTION__);

   set_u(mathutil_ymXf(y(),X(),f()));

   return;
}

void FactorModel::compute_y() {
   if(f()==NULL) myerr_msg("f==NULL",__FUNCTION__);
   if(X()==NULL) myerr_msg("X==NULL",__FUNCTION__);
   if(u()==NULL) myerr_msg("u==NULL",__FUNCTION__);

   set_y(mathutil_Xfpu(X(),f(),u()));

   return;
}

double FactorModel::compute_R2() {
   if(y()==NULL) myerr_msg("y==NULL",__FUNCTION__);
   double numer, denom, R2;

   compute_u();
   numer = u()->l2n();
   denom = y()->l2n();

   R2 = 1.0;
   if(! util_isZero(denom)) R2 = 1 - pow(numer/denom, 2.0);

   return R2;
}

Matrix* FactorModel::compute_tstat(Matrix* nullf, int xval) {
   if(Omega()==NULL) {xval=1; return NULL;}

   Matrix* _nullf = NULL;
   double** nullfX = NULL;
   double** OmegaX = this->Omega()->X();
   double** fX = this->f()->X();
   int m = this->f()->m();

   Matrix* tstat = NULL;
   double** tstatX = NULL;

   tstat = Matrix::instance(m,1);
   tstat->copynames(this->f(), true, false);
   tstat->set_cmap_cimap(0, "tstat");
   tstatX = tstat->X();

   if(nullf!=NULL) nullfX = nullf->X();
   else {nullfX = (_nullf=Matrix::instance(m,1))->X();}

   for(int i=0;i<m;i++) tstatX[i][0] = (fX[i][0]-nullfX[i][0])/sqrt(OmegaX[i][i]);

   //clean memory
   delete _nullf;

   return tstat;
}

#endif

