// Name:     MatrixCentralizer.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_MatrixCentralizer_cpp
#define ASX_MatrixCentralizer_cpp


#include <stdio.h>
#include <math.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "MathUtils.hpp"
#include "MatrixProcessor.hpp"
#include "Matrix.hpp"
#include "MatrixCentralizer.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMathUtils;
using namespace aiMath;

/** --------------Constructors and init_NULL-----------*/

MatrixCentralizer::MatrixCentralizer() { init_NULL(); }
MatrixCentralizer::MatrixCentralizer(const MatrixCentralizer* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
MatrixCentralizer::MatrixCentralizer(const MatrixCentralizer& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void MatrixCentralizer::init_NULL()	{
	_loc=NULL;
	_disp=NULL;
	_Xloc=NULL;
	_Xdisp=NULL;
}

/** ---Public Data Setting Functions-----------------*/

void MatrixCentralizer::set_loc(Matrix* _obj) {
   cleanMem_loc();
   _loc = _obj;
}

void MatrixCentralizer::set_disp(Matrix* _obj) {
   cleanMem_disp();
   _disp = _obj;
}

void MatrixCentralizer::set_Xloc(Matrix* _obj) {
   cleanMem_Xloc();
   _Xloc = _obj;
}

void MatrixCentralizer::set_Xdisp(Matrix* _obj) {
   cleanMem_Xdisp();
   _Xdisp = _obj;
}

/** --------   Init Functions -------------------------*/

void MatrixCentralizer::init(bool insitu, bool row_flag, 
                            Matrix* loc, Matrix* disp)
{
   MatrixProcessor::init(insitu,row_flag);
	init_MatrixCentralizer(loc, disp);
}

void MatrixCentralizer::init_MatrixCentralizer(Matrix* loc, Matrix* disp)
{
   init_loc(loc);
   init_disp(disp);
}

void MatrixCentralizer::init_loc(Matrix* obj) {set_loc(obj);}
void MatrixCentralizer::init_disp(Matrix* obj) {set_disp(obj);}

/** -----Destructors and Memory Cleanup functions -----*/

MatrixCentralizer::~MatrixCentralizer()	{ cleanMem(); }

void MatrixCentralizer::cleanMem()	{
	cleanMem_MatrixCentralizer();
   MatrixProcessor::cleanMem();
}

void MatrixCentralizer::cleanMem_MatrixCentralizer() {
   cleanMem_loc();
   cleanMem_disp();
   cleanMem_Xloc();
   cleanMem_Xdisp();
}

void MatrixCentralizer::cleanMem_loc() {
   delete _loc;
   _loc = NULL;
}

void MatrixCentralizer::cleanMem_disp() {
   delete _disp;
   _disp = NULL;
}

void MatrixCentralizer::cleanMem_Xloc() {
   delete _Xloc;
   _Xloc = NULL;
}

void MatrixCentralizer::cleanMem_Xdisp() {
   delete _Xdisp;
   _Xdisp = NULL;
}

/** ------------- Data Access Functions --------------------*/

Matrix* MatrixCentralizer::loc() {return _loc;}
Matrix* MatrixCentralizer::disp() {return _disp;}
Matrix* MatrixCentralizer::Xloc() {return _Xloc;}
Matrix* MatrixCentralizer::Xdisp() {return _Xdisp;}

/** ------------- Access classname dynamically --------------------*/

string MatrixCentralizer::className() const {return "MatrixCentralizer";}

/** ------------- Error Message Handling Functions ------------------*/

void MatrixCentralizer::myerr_msg(string msg, string func) {
	err_msg("MatrixCentralizer::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void MatrixCentralizer::fprint(string fname) {
   MatrixProcessor::fprint(fname);
	fprint_MatrixCentralizer(fname);
}

void MatrixCentralizer::fprint_MatrixCentralizer(string fname) {
   util_ofprint_obj(fname, "loc", _loc);
   util_ofprint_obj(fname, "disp", _disp);
}

void MatrixCentralizer::fscan(string fname) {
   MatrixProcessor::fscan(fname);
	fscan_MatrixCentralizer(fname);
}

void MatrixCentralizer::fscan_MatrixCentralizer(string fname) {
   _loc = Matrix::instance_fscan( util_ofname(fname, "loc") ) ;
   _disp = Matrix::instance_fscan( util_ofname(fname, "disp") ) ;
}

/** ------------- Reset Functions --------------------*/

void MatrixCentralizer::reset() {
	reset_MatrixCentralizer();
   MatrixProcessor::reset();
}

void MatrixCentralizer::reset_MatrixCentralizer() {
   set_Xloc(NULL);
   set_Xdisp(NULL);
}

/** ----------  static instance function -----------*/


MatrixCentralizer* MatrixCentralizer::instance(bool insitu, bool row_flag,
                                             Matrix* loc, Matrix* disp)	
{
	MatrixCentralizer* ptr=new MatrixCentralizer();
	ptr->init(insitu, row_flag, loc, disp);
	return ptr;
}


MatrixCentralizer* MatrixCentralizer::instance_fscan(string fname)	{
	MatrixCentralizer* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new MatrixCentralizer();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

void MatrixCentralizer::configure(Matrix* X, Matrix* Delta) {
   MatrixProcessor::configure(X, Delta);
   return;
}

void MatrixCentralizer::algo_exec() {
   MatrixProcessor::algo_exec();
   return;
}

MatrixProcessor* MatrixCentralizer::kernel() {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
   return NULL;
}

MatrixProcessor* MatrixCentralizer::copy() {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
   return NULL;
}

#endif

