// Name:     MatrixProcessor.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_MatrixProcessor_cpp
#define ASX_MatrixProcessor_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Matrix.hpp"
#include "ModelGen.hpp"
#include "Model.hpp"
#include "MatrixProcessor.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMathUtils;
using namespace aiMath;

/** --------------Constructors and init_NULL-----------*/

MatrixProcessor::MatrixProcessor() { init_NULL(); }
MatrixProcessor::MatrixProcessor(const MatrixProcessor* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
MatrixProcessor::MatrixProcessor(const MatrixProcessor& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void MatrixProcessor::init_NULL()	{
	_X=NULL;
	_Delta=NULL;
	_orthoS=NULL;
}

/** ---Public Data Setting Functions-----------------*/

void MatrixProcessor::set_row_flag(bool _obj) {
	_row_flag=_obj;
   if(_row_flag) myerr_msg("Functionality not yet implemented for _row_flag=true",__FUNCTION__);
}

void MatrixProcessor::set_log_flag(bool _obj) {_log_flag = _obj;}

void MatrixProcessor::set_insitu(bool _obj) {
	_insitu=_obj;
   if(_insitu) myerr_msg("Functionality not supported for insitu=true",__FUNCTION__);
}

void MatrixProcessor::set_X(Matrix* _obj) {
   cleanMem_X();
   _X = _obj;
}

void MatrixProcessor::set_Delta(Matrix* _obj) {
   cleanMem_Delta();
   _Delta = _obj;
}

void MatrixProcessor::add_orthoS(int j) {_orthoS->insert(j);}

void MatrixProcessor::add_orthoS(set<int>* orthoS) {
   if(orthoS==NULL) return;
   set<int>::iterator it;
   for(it=orthoS->begin();it!=orthoS->end();it++) this->add_orthoS(*it);
}

void MatrixProcessor::set_orthoS_flag(bool _obj) {
	_orthoS_flag=_obj;
}

/** --------   Init Functions -------------------------*/

void MatrixProcessor::init(bool insitu, bool row_flag) {
   ModelGen::init();
	init_MatrixProcessor(insitu,row_flag);
}

void MatrixProcessor::init_MatrixProcessor(bool insitu, bool row_flag) {
	init_insitu(insitu);
	init_row_flag(row_flag);
   init_log_flag(false);
	init_orthoS_flag();
	init_orthoS();
}

void MatrixProcessor::init_row_flag(bool obj) {set_row_flag(obj);}
void MatrixProcessor::init_log_flag(bool obj) {set_log_flag(obj);}
void MatrixProcessor::init_insitu(bool obj) {set_insitu(obj);}
void MatrixProcessor::init_orthoS_flag() {set_orthoS_flag(true);}
void MatrixProcessor::init_orthoS() {_orthoS = new set<int>();}

/** -----Destructors and Memory Cleanup functions -----*/

MatrixProcessor::~MatrixProcessor()	{ cleanMem(); }

void MatrixProcessor::cleanMem()	{
	cleanMem_MatrixProcessor();
   ModelGen::cleanMem();
}

void MatrixProcessor::cleanMem_MatrixProcessor() {
	cleanMem_X();
	cleanMem_orthoS();
}

void MatrixProcessor::cleanMem_X() {
	_X=NULL;
}

void MatrixProcessor::cleanMem_Delta() {
	_Delta=NULL;
}

void MatrixProcessor::cleanMem_orthoS() {
   delete _orthoS;
	_orthoS=NULL;
}

/** ------------- Data Access Functions --------------------*/

bool MatrixProcessor::row_flag() {return _row_flag;}
bool MatrixProcessor::log_flag() {return _log_flag;}
bool MatrixProcessor::insitu() {return _insitu;}
Matrix* MatrixProcessor::X() {return _X;}
Matrix* MatrixProcessor::Delta() {return _Delta;}
bool MatrixProcessor::orthoS_flag() {return _orthoS_flag;}
set<int>* MatrixProcessor::orthoS() {return _orthoS;}

Matrix* MatrixProcessor::mdl() {return (Matrix*) ModelGen::mdl();}

/** ------------- Access classname dynamically --------------------*/

string MatrixProcessor::className() const {return "MatrixProcessor";}

/** ------------- Error Message Handling Functions ------------------*/

void MatrixProcessor::myerr_msg(string msg, string func) {
	err_msg("MatrixProcessor::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void MatrixProcessor::fprint(string fname) {
   ModelGen::fprint(fname);
	fprint_MatrixProcessor(fname);
}

void MatrixProcessor::fprint_MatrixProcessor(string fname) {
	util_ofprint(fname,"row_flag",_row_flag);
	util_ofprint(fname,"log_flag",_log_flag);
	util_ofprint(fname,"insitu",_insitu);
	util_ofprint_obj(fname,"X",_X);
	util_ofprint(fname,"orthoS_flag",_orthoS_flag);
	util_ofprint(fname,"orthoS",_orthoS);
}

void MatrixProcessor::fscan(string fname) {
   ModelGen::fscan(fname);
	fscan_MatrixProcessor(fname);
}

void MatrixProcessor::fscan_MatrixProcessor(string fname) {
	util_ofscan(fname,"row_flag",_row_flag);
	util_ofscan(fname,"log_flag",_log_flag);
	util_ofscan(fname,"insitu",_insitu);
   _X = Matrix::instance_fscan(util_ofname(fname,"X"));
	util_ofscan(fname,"orthoS_flag",_orthoS_flag);
   util_ofscan(fname, "orthoS", _orthoS);
}

/** ------------- Reset Functions --------------------*/

void MatrixProcessor::reset() {
	reset_MatrixProcessor();
   ModelGen::reset();
}

void MatrixProcessor::reset_MatrixProcessor() {
	reset_X();
	reset_Delta();
}

void MatrixProcessor::reset_X() {
   cleanMem_X();
}

void MatrixProcessor::reset_Delta() {
   cleanMem_Delta();
}


/** ----------  static instance function -----------*/


MatrixProcessor* MatrixProcessor::instance(bool insitu, bool row_flag)	{
	MatrixProcessor* ptr=new MatrixProcessor();
	ptr->init(insitu,row_flag);
	return ptr;
}


MatrixProcessor* MatrixProcessor::instance_fscan(string fname)	{
	MatrixProcessor* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new MatrixProcessor();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

void MatrixProcessor::configure(Matrix* X, Matrix* Delta) {
   ModelGen::configure();
   set_X(X);
   set_Delta(Delta);
}

void MatrixProcessor::algo_exec() {
   ModelGen::algo_exec();
   Matrix* Y = NULL;
   if(_insitu) Y = X();
   else Y = X()->copy();
   set_mdl(Y);
   return;
}

Matrix* MatrixProcessor::extract_mdl() {return (Matrix*) ModelGen::extract_mdl();}

MatrixProcessor* MatrixProcessor::copy() {
   MatrixProcessor* proc = MatrixProcessor::instance(this->insitu(), this->row_flag());
   proc->add_orthoS(orthoS());
   return proc;
}

Matrix* MatrixProcessor::exec(Matrix* X, Matrix* Delta, MatrixProcessor** kernelp) {
   Matrix* mdl = NULL;
   configure(X, Delta);
   algo_exec();
   if(kernelp!=NULL) (*kernelp) = this->kernel();
   mdl = extract_mdl();
   reset();
   return mdl;
}

MatrixProcessor* MatrixProcessor::kernel() {
   return this->copy();
}

#endif

