// Name:     ResidualProcessor.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ResidualProcessor_cpp
#define ASX_ResidualProcessor_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Matrix.hpp"
#include "MatrixProcessor.hpp"
#include "Regression.hpp"
#include "ResidualProcessor.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMathUtils;
using namespace aiStatUtils;
using namespace aiStat;
using namespace aiMath;

/** --------------Constructors and init_NULL-----------*/

ResidualProcessor::ResidualProcessor() { init_NULL(); }
ResidualProcessor::ResidualProcessor(const ResidualProcessor* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
ResidualProcessor::ResidualProcessor(const ResidualProcessor& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void ResidualProcessor::init_NULL()	{
	_W=NULL;
}

/** ---Public Data Setting Functions-----------------*/

void ResidualProcessor::set_W(Matrix* _obj) {_W = _obj;}

void ResidualProcessor::set_log_flag(bool obj) {
   if(obj) myerr_msg("Functionality not available",__FUNCTION__);
}

/** --------   Init Functions -------------------------*/

void ResidualProcessor::init(bool insitu, bool row_flag) {
   MatrixProcessor::init(insitu, row_flag);
	init_ResidualProcessor();
}

void ResidualProcessor::init_ResidualProcessor() {
}

/** -----Destructors and Memory Cleanup functions -----*/

ResidualProcessor::~ResidualProcessor()	{ cleanMem(); }

void ResidualProcessor::cleanMem()	{
	cleanMem_ResidualProcessor();
   MatrixProcessor::cleanMem();
}

void ResidualProcessor::cleanMem_ResidualProcessor() {
	cleanMem_W();
}

void ResidualProcessor::cleanMem_W() {
	_W=NULL;
}

/** ------------- Data Access Functions --------------------*/

Matrix* ResidualProcessor::W() {return _W;}

/** ------------- Access classname dynamically --------------------*/

string ResidualProcessor::className() const {return "ResidualProcessor";}

/** ------------- Error Message Handling Functions ------------------*/

void ResidualProcessor::myerr_msg(string msg, string func) {
	err_msg("ResidualProcessor::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void ResidualProcessor::fprint(string fname) {
   MatrixProcessor::fprint(fname);
	fprint_ResidualProcessor(fname);
}

void ResidualProcessor::fprint_ResidualProcessor(string fname) {
	util_ofprint_obj(fname,"W",_W);
}

void ResidualProcessor::fscan(string fname) {
   MatrixProcessor::fscan(fname);
	fscan_ResidualProcessor(fname);
}

void ResidualProcessor::fscan_ResidualProcessor(string fname) {
   _W = Matrix::instance_fscan(util_ofname(fname,"W"));
}

/** ------------- Reset Functions --------------------*/

void ResidualProcessor::reset() {
	reset_ResidualProcessor();
   MatrixProcessor::reset();
}

void ResidualProcessor::reset_ResidualProcessor() {
	reset_W();
}

void ResidualProcessor::reset_W() {set_W(NULL);}

/** ----------  static instance function -----------*/


ResidualProcessor* ResidualProcessor::instance(bool insitu, bool row_flag)	{
	ResidualProcessor* ptr=new ResidualProcessor();
	ptr->init(insitu, row_flag);
	return ptr;
}


ResidualProcessor* ResidualProcessor::instance_fscan(string fname)	{
	ResidualProcessor* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new ResidualProcessor();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

void ResidualProcessor::configure(Matrix* X, Matrix* W, Matrix* Delta) {
   MatrixProcessor::configure(X, Delta);
   set_W(W);
}

void ResidualProcessor::algo_exec() {
   MatrixProcessor::algo_exec();
   Matrix* mdl = this->mdl();
   Regression* reg = NULL;

   reg = Regression::instance();
   reg->configure(X(), W(), Delta());
   reg->algo_exec();
   mdl->assign(reg->mdl()->u());

   //clean memory
   delete reg;

   return;
}

#endif

