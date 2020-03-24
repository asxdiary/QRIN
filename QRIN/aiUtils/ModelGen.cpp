// Name:     ModelGen.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ModelGen_cpp
#define ASX_ModelGen_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Model.hpp"
#include "Object.hpp"
#include "ModelGen.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiUtils;

/** --------------Constructors and init_NULL-----------*/

ModelGen::ModelGen() { init_NULL(); }
ModelGen::ModelGen(const ModelGen* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
ModelGen::ModelGen(const ModelGen& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void ModelGen::init_NULL()	{
	_mdl=NULL;
}

/** ---Public Data Setting Functions-----------------*/

void ModelGen::set_mdl(Model* _obj) {
   cleanMem_mdl();
   _mdl = _obj;
}

void ModelGen::set_mdl_flag(bool _obj) {_mdl_flag = _obj;}

/** --------   Init Functions -------------------------*/

void ModelGen::init() {
   Object::init();
	init_ModelGen();
}

void ModelGen::init_ModelGen() {
   init_mdl_flag();
}

void ModelGen::init_mdl_flag() {_mdl_flag = true;}

/** -----Destructors and Memory Cleanup functions -----*/

ModelGen::~ModelGen()	{ cleanMem(); }

void ModelGen::cleanMem()	{
	cleanMem_ModelGen();
   Object::cleanMem();
}

void ModelGen::cleanMem_ModelGen() {
	cleanMem_mdl();
}

void ModelGen::cleanMem_mdl() {
   delete _mdl;
	_mdl=NULL;
}

/** ------------- Data Access Functions --------------------*/

Model* ModelGen::mdl() {return _mdl;}
bool ModelGen::mdl_flag() {return _mdl_flag;}

/** ------------- Access classname dynamically --------------------*/

string ModelGen::className() const {return "ModelGen";}

/** ------------- Error Message Handling Functions ------------------*/

void ModelGen::myerr_msg(string msg, string func) {
	err_msg("ModelGen::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void ModelGen::fprint(string fname) {
   Object::fprint(fname);
	fprint_ModelGen(fname);
}

void ModelGen::fprint_ModelGen(string fname) {
	util_ofprint_obj(fname,"mdl",_mdl);
	util_ofprint(fname,"mdl_flag",_mdl_flag);
}

void ModelGen::fscan(string fname) {
   Object::fscan(fname);
	fscan_ModelGen(fname);
}

void ModelGen::fscan_ModelGen(string fname) {
   /** mdl Scanning is left to sub-classes */
   util_ofscan(fname,"mdl_flag",_mdl_flag);
}

/** ------------- Reset Functions --------------------*/

void ModelGen::reset() {
	reset_ModelGen();
   Object::reset();
}

void ModelGen::reset_ModelGen() {
	reset_mdl();
}

void ModelGen::reset_mdl() {
   set_mdl(NULL);
}

/** ----------  static instance function -----------*/


ModelGen* ModelGen::instance()	{
	ModelGen* ptr=new ModelGen();
	ptr->init();
	return ptr;
}


ModelGen* ModelGen::instance_fscan(string fname)	{
	ModelGen* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new ModelGen();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

Model* ModelGen::extract_mdl() {
   Model* mdl = _mdl;
   _mdl = NULL;
   set_mdl(NULL);
   return mdl;
}

void ModelGen::configure() {  
   this->reset();
}

void ModelGen::algo_exec() {return;}

#endif

