// Name:     CsvModelGen.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CsvModelGen_cpp
#define ASX_CsvModelGen_cpp


#include <stdio.h>
#include <list>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "SMatrix.hpp"
#include "ModelGen.hpp"
#include "Model.hpp"
#include "CsvModelGen.hpp"
#include "DatedTables.hpp"
#include "UtilDate.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiUtils;
using namespace aiMath;

/** --------------Constructors and init_NULL-----------*/

CsvModelGen::CsvModelGen() { init_NULL(); }
CsvModelGen::CsvModelGen(const CsvModelGen* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
CsvModelGen::CsvModelGen(const CsvModelGen& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void CsvModelGen::init_NULL()	{
   _algo_exec_d = NULL;
}

/** ---Public Data Setting Functions-----------------*/

void CsvModelGen::set_src(string _obj) {
	_src=_obj;
}

void CsvModelGen::set_err_flag(int _obj) {
	_err_flag=_obj;
}

/** --------   Init Functions -------------------------*/

void CsvModelGen::init() {
   ModelGen::init();
	init_CsvModelGen();
}

void CsvModelGen::init_CsvModelGen() {
   init_err_flag();
}

void CsvModelGen::init_err_flag() {set_err_flag(0);}

/** -----Destructors and Memory Cleanup functions -----*/

CsvModelGen::~CsvModelGen()	{ cleanMem(); }

void CsvModelGen::cleanMem()	{
	cleanMem_CsvModelGen();
   ModelGen::cleanMem();
}

void CsvModelGen::cleanMem_CsvModelGen() {
   cleanMem_algo_exec_d();
}

void CsvModelGen::cleanMem_algo_exec_d() {
   _algo_exec_d = NULL;
}

/** ------------- Data Access Functions --------------------*/

string CsvModelGen::src() {return _src;}
int CsvModelGen::err_flag() {return _err_flag;}
UtilDate* CsvModelGen::algo_exec_d() {return _algo_exec_d;}

/** ------------- Access classname dynamically --------------------*/

string CsvModelGen::className() const {return "CsvModelGen";}

/** ------------- Error Message Handling Functions ------------------*/

void CsvModelGen::myerr_msg(string msg, string func) {
	err_msg("CsvModelGen::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void CsvModelGen::fprint(string fname) {
   ModelGen::fprint(fname);
	fprint_CsvModelGen(fname);
}

void CsvModelGen::fprint_CsvModelGen(string fname) {
	util_ofprint(fname,"src",_src);
	util_ofprint(fname,"err_flag",_err_flag);
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
}

void CsvModelGen::fscan(string fname) {
   ModelGen::fscan(fname);
	fscan_CsvModelGen(fname);
}

void CsvModelGen::fscan_CsvModelGen(string fname) {
	util_ofscan(fname,"src",_src);
	util_ofscan(fname,"err_flag",_err_flag);
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
}

/** ------------- Reset Functions --------------------*/

void CsvModelGen::reset() {
	reset_CsvModelGen();
   ModelGen::reset();
}

void CsvModelGen::reset_CsvModelGen() {
}

void CsvModelGen::reset_univ() {}

/** ----------  static instance function -----------*/


CsvModelGen* CsvModelGen::instance()	{
	CsvModelGen* ptr=new CsvModelGen();
	ptr->init();
	return ptr;
}


CsvModelGen* CsvModelGen::instance_fscan(string fname)	{
	CsvModelGen* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new CsvModelGen();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

void CsvModelGen::configure(string src, Model* _mdl) {
   ModelGen::configure();
   set_src(src);
   if(mdl()==NULL) {
      while(_mdl==NULL) _mdl = gen_mdl();
      set_mdl(_mdl);
   }
   return;
}

Model* CsvModelGen::gen_mdl() {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
   return NULL;
}

void CsvModelGen::algo_exec(list<UtilDate*>* dL) {
   list<UtilDate*>::iterator it;
   for(it=dL->begin();it!=dL->end();it++) algo_exec(*it);
   return;
}

void CsvModelGen::algo_exec(UtilDate* d) {
   //printf("%s::%s loading %s for %s\n",className().c_str(),__FUNCTION__,d->id().c_str(),src().c_str());
   DatedTables* ptr = NULL;
	unordered_map<UtilDate*,SMatrix*>::iterator it;

   ptr = DatedTables::instance(_src);
   ptr->load(d,1);

   _algo_exec_d = d;
   for(it=ptr->data()->begin();it!=ptr->data()->end();it++) algo_exec(it->second);
   _algo_exec_d = NULL;

   //clean memory
   delete ptr;
}

void CsvModelGen::algo_exec(SMatrix* smat) {
   int m = smat->m();
	unordered_map<string,int>* cimap = smat->cimap();
   string** X = smat->X();
   for(int i=0;i<m;i++) {
      algo_exec_guts(cimap, X[i]);
   }
   return;
}

void CsvModelGen::algo_exec_guts(unordered_map<string,int>* header, string* row) {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
   return;
}

string CsvModelGen::_get_val(unordered_map<string,int>* header, string* row, string key, 
                       int& xval, int err_flag) 
{
   unordered_map<string,int>::iterator it;

   if(err_flag<0) err_flag = this->err_flag();

   xval = 0;
   it = header->find(key);
   if(it==header->end()) {
      xval = 1;
      if(err_flag==0) myerr_msg(key + " not found",__FUNCTION__);
      if(err_flag==1) warn_msg(className(),"::",__FUNCTION__," ",key + " not found ");
      return "";
   }
   return row[it->second];
}

#endif

