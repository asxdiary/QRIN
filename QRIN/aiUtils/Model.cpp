// Name:     Model.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_Model_cpp
#define ASX_Model_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Object.hpp"
#include "Model.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiUtils;

/** --------------Constructors and init_NULL-----------*/

Model::Model() { init_NULL(); }
Model::Model(const Model* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
Model::Model(const Model& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void Model::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void Model::init() {
   Object::init();
	init_Model();
}

void Model::init_Model() {
}

/** -----Destructors and Memory Cleanup functions -----*/

Model::~Model()	{ cleanMem(); }

void Model::cleanMem()	{
	cleanMem_Model();
   Object::cleanMem();
}

void Model::cleanMem_Model() {
}

/** ------------- Data Access Functions --------------------*/

/** ------------- Access classname dynamically --------------------*/

string Model::className() const {return "Model";}

/** ------------- Error Message Handling Functions ------------------*/

void Model::myerr_msg(string msg, string func) {
	err_msg("Model::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void Model::fprint(string fname) {
   Object::fprint(fname);
	fprint_Model(fname);
}

void Model::fprint_Model(string fname) {
}

void Model::fscan(string fname) {
   Object::fscan(fname);
	fscan_Model(fname);
}

void Model::fscan_Model(string fname) {
}

/** ------------- Reset Functions --------------------*/

void Model::reset() {
	reset_Model();
   Object::reset();
}

void Model::reset_Model() {
}

/** ----------  static instance function -----------*/


Model* Model::instance()	{
	Model* ptr=new Model();
	ptr->init();
	return ptr;
}


Model* Model::instance_fscan(string fname)	{
	Model* ptr=new Model();
	ptr->fscan(fname);
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

int Model::chk() {return 0;}

#endif

