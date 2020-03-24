// Name:     Company.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_Company_cpp
#define ASX_Company_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Model.hpp"
#include "CompanyIdentifier.hpp"
#include "unordered_map"
#include "Company.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiFin;

/** --------------Constructors and init_NULL-----------*/

Company::Company() { init_NULL(); }
Company::Company(const Company* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
Company::Company(const Company& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void Company::init_NULL()	{
	_cid=NULL;
	_cidm=NULL;
}

/** ---Public Data Setting Functions-----------------*/

void Company::set_cidm(CompanyIdentifier* cid, string id) {
   (*_cidm)[cid] = id;
}

/** --------   Init Functions -------------------------*/

void Company::init(CompanyIdentifier* cid, string id) {
   Model::init();
   set_id(id);
	init_Company(cid);
}

void Company::init_Company(CompanyIdentifier* cid) {
	init_cid(cid);
	init_cidm();
}

void Company::init_cid(CompanyIdentifier* cid) {_cid = cid;}

void Company::init_cidm() {
   _cidm = new unordered_map<CompanyIdentifier*,string>();
}

/** -----Destructors and Memory Cleanup functions -----*/

Company::~Company()	{ cleanMem(); }

void Company::cleanMem()	{
	cleanMem_Company();
   Model::cleanMem();
}

void Company::cleanMem_Company() {
	cleanMem_cid();
	cleanMem_cidm();
}

void Company::cleanMem_cid() {
	_cid=NULL;
}

void Company::cleanMem_cidm() {
   delete _cidm;
	_cidm=NULL;
}

/** ------------- Data Access Functions --------------------*/

CompanyIdentifier* Company::cid() {return _cid;}
unordered_map<CompanyIdentifier*,string>* Company::cidm() {return _cidm;}
string Company::cidm(CompanyIdentifier* cid) {
   unordered_map<CompanyIdentifier*,string>::iterator it;
   it = _cidm->find(cid);
   if(it==_cidm->end()) myerr_msg("cid not found",__FUNCTION__);
   return it->second;
}

/** ------------- Access classname dynamically --------------------*/

string Company::className() const {return "Company";}

/** ------------- Error Message Handling Functions ------------------*/

void Company::myerr_msg(string msg, string func) {
	err_msg("Company::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void Company::fprint(string fname) {
   Model::fprint(fname);
	fprint_Company(fname);
}

void Company::fprint_Company(string fname) {
	util_ofprint_obj(fname,"cid",_cid);
   {
      unordered_map<string,string> m;
      unordered_map<CompanyIdentifier*,string>::iterator it;
      for(it=_cidm->begin();it!=_cidm->end();it++) m[it->first->id()]=it->second;
      util_ofprint(fname,"cidm",&m);
   }
}

void Company::fscan(string fname) {
   Model::fscan(fname);
	fscan_Company(fname);
}

void Company::fscan_Company(string fname) {
   _cid = CompanyIdentifier::instance_fscan( util_ofname(fname,"cid") );
   {
      unordered_map<string,string>* m = NULL;
      unordered_map<string,string>::iterator it;
      util_ofscan(fname,"cidm",m);
      init_cidm();
      for(it=m->begin();it!=m->end();it++) {
         (*_cidm)[CompanyIdentifier::instance(it->first)] = it->second;
      }

      //clean memory
      delete m;
   }
}

/** ------------- Reset Functions --------------------*/

void Company::reset() {
	reset_Company();
   Model::reset();
}

void Company::reset_Company() {
}

/** ----------  static instance function -----------*/


Company* Company::instance(CompanyIdentifier* cid, string id)	{
	Company* ptr=new Company();
	ptr->init(cid, id);
	return ptr;
}


Company* Company::instance_fscan(string fname)	{
	Company* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new Company();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

#endif

