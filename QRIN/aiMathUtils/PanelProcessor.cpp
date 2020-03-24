// Name:     PanelProcessor.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_PanelProcessor_cpp
#define ASX_PanelProcessor_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Panel.hpp"
#include "ModelGen.hpp"
#include "Model.hpp"
#include "PanelProcessor.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMathUtils;
using namespace aiMath;

/** --------------Constructors and init_NULL-----------*/

PanelProcessor::PanelProcessor() { init_NULL(); }
PanelProcessor::PanelProcessor(const PanelProcessor* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
PanelProcessor::PanelProcessor(const PanelProcessor& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void PanelProcessor::init_NULL()	{
	_X=NULL;
}

/** ---Public Data Setting Functions-----------------*/

void PanelProcessor::set_insitu(bool _obj) {
	_insitu=_obj;
}

void PanelProcessor::set_X(Panel* _obj) {
   cleanMem_X();
   _X = _obj;
}

/** --------   Init Functions -------------------------*/

void PanelProcessor::init(bool insitu) {
   ModelGen::init();
	init_PanelProcessor(insitu);
}

void PanelProcessor::init_PanelProcessor(bool insitu) {
	init_insitu(insitu);
}

void PanelProcessor::init_insitu(bool obj) {set_insitu(obj);}

/** -----Destructors and Memory Cleanup functions -----*/

PanelProcessor::~PanelProcessor()	{ cleanMem(); }

void PanelProcessor::cleanMem()	{
	cleanMem_PanelProcessor();
   ModelGen::cleanMem();
}

void PanelProcessor::cleanMem_PanelProcessor() {
	cleanMem_X();
}

void PanelProcessor::cleanMem_X() {
	_X=NULL;
}

/** ------------- Data Access Functions --------------------*/

bool PanelProcessor::insitu() {return _insitu;}
Panel* PanelProcessor::X() {return _X;}

Panel* PanelProcessor::mdl() {return (Panel*) ModelGen::mdl();}

/** ------------- Access classname dynamically --------------------*/

string PanelProcessor::className() const {return "PanelProcessor";}

/** ------------- Error Message Handling Functions ------------------*/

void PanelProcessor::myerr_msg(string msg, string func) {
	err_msg("PanelProcessor::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void PanelProcessor::fprint(string fname) {
   ModelGen::fprint(fname);
	fprint_PanelProcessor(fname);
}

void PanelProcessor::fprint_PanelProcessor(string fname) {
	util_ofprint(fname,"insitu",_insitu);
	util_ofprint_obj(fname,"X",_X);
}

void PanelProcessor::fscan(string fname) {
   ModelGen::fscan(fname);
	fscan_PanelProcessor(fname);
}

void PanelProcessor::fscan_PanelProcessor(string fname) {
	util_ofscan(fname,"insitu",_insitu);
   _X = Panel::instance_fscan(util_ofname(fname,"X"));
}

/** ------------- Reset Functions --------------------*/

void PanelProcessor::reset() {
	reset_PanelProcessor();
   ModelGen::reset();
}

void PanelProcessor::reset_PanelProcessor() {
	reset_X();
}

void PanelProcessor::reset_X() {
   cleanMem_X();
}

/** ----------  static instance function -----------*/


PanelProcessor* PanelProcessor::instance(bool insitu)	{
	PanelProcessor* ptr=new PanelProcessor();
	ptr->init(insitu);
	return ptr;
}


PanelProcessor* PanelProcessor::instance_fscan(string fname)	{
	PanelProcessor* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new PanelProcessor();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

void PanelProcessor::configure(Panel* X) {
   ModelGen::configure();
   set_X(X);
}

void PanelProcessor::algo_exec() {
   ModelGen::algo_exec();
   Panel* Y = NULL;
   if(_insitu) Y = X();
   else Y = X()->copy();
   set_mdl(Y);
   return;
}

Panel* PanelProcessor::extract_mdl() {return (Panel*) ModelGen::extract_mdl();}

#endif

