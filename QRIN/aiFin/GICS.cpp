// Name:     GICS.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_GICS_cpp
#define ASX_GICS_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Matrix.hpp"
#include "GICS.hpp"
#include "pkgFin.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiFin;
using namespace aiMath;

/** --------------Constructors and init_NULL-----------*/

GICS::GICS() { init_NULL(); }
GICS::GICS(const GICS* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
GICS::GICS(const GICS& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void GICS::init_NULL()	{
	_gsec=NULL;
	_gsubind=NULL;
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void GICS::init() {
   Model::init();
	init_GICS();
}

void GICS::init_GICS() {
	init_gsec();
	init_gsubind();
}

void GICS::init_gsec() {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
}

void GICS::init_gsubind() {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
}

/** -----Destructors and Memory Cleanup functions -----*/

GICS::~GICS()	{ cleanMem(); }

void GICS::cleanMem()	{
	cleanMem_GICS();
	Model::cleanMem();
}

void GICS::cleanMem_GICS() {
	cleanMem_gsec();
	cleanMem_gsubind();
}

void GICS::cleanMem_gsec() {
   delete _gsec;
	_gsec=NULL;
}

void GICS::cleanMem_gsubind() {
   delete _gsubind;
	_gsubind=NULL;
}

/** ------------- Data Access Functions --------------------*/

Matrix* GICS::gsec() {return _gsec;}
Matrix* GICS::gsubind() {return _gsubind;}

/** ------------- Access classname dynamically --------------------*/

string GICS::className() const {return "GICS";}

/** ------------- Error Message Handling Functions ------------------*/

void GICS::myerr_msg(string msg, string func) {
	err_msg("GICS::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void GICS::fprint(string fname) {
	Model::fprint(fname);
	fprint_GICS(fname);
}

void GICS::fprint_GICS(string fname) {
   _gsec->fprint_table(util_ofname(fname,"gsec"));
   _gsubind->fprint_table(util_ofname(fname,"gsubind"));
}

void GICS::fscan(string fname) {
	Model::fscan(fname);
	fscan_GICS(fname);
}

void GICS::fscan_GICS(string fname) {
   _gsec = Matrix::instance_fread_table(util_join(".",fname,"gsec","csv"));
   _gsubind = Matrix::instance_fread_table(util_join(".",fname,"gsubind","csv"));
}

/** ------------- Reset Functions --------------------*/

void GICS::reset() {
	reset_GICS();
	Model::reset();
}

void GICS::reset_GICS() {
}

/** ----------  static instance function -----------*/


GICS* GICS::instance()	{
	GICS* ptr = NULL;
   string id = "GICS";

   ptr = (GICS*) util_singleton("GICS",id);
   if(ptr==NULL) {
      string fname;
      fname = Global::instance()->coin_home() + GICS_src;
      ptr = GICS::instance_fscan(fname);
      ptr->set_id("GICS");
      util_singleton("GICS",id,ptr);
   }
	return ptr;
}

GICS* GICS::instance_fscan(string fname)	{
	GICS* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new GICS();
		ptr->init_NULL();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

#endif

