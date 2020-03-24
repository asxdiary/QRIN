// Name:     CompanyUniverse.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CompanyUniverse_cpp
#define ASX_CompanyUniverse_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "CompanyIdentifier.hpp"
#include "ObjectUniverse.hpp"
#include "Company.hpp"
#include "CompanyUniverse.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiFin;

/** --------------Constructors and init_NULL-----------*/

CompanyUniverse::CompanyUniverse() { init_NULL(); }
CompanyUniverse::CompanyUniverse(const CompanyUniverse* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
CompanyUniverse::CompanyUniverse(const CompanyUniverse& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void CompanyUniverse::init_NULL()	{
	_cid=NULL;
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void CompanyUniverse::init(CompanyIdentifier* cid) {
   ObjectUniverse::init();
	init_CompanyUniverse(cid);
}

void CompanyUniverse::init_CompanyUniverse(CompanyIdentifier* cid) {
	init_cid(cid);
}

void CompanyUniverse::init_cid(CompanyIdentifier* cid) {
   _cid = cid;
}

/** -----Destructors and Memory Cleanup functions -----*/

CompanyUniverse::~CompanyUniverse()	{ cleanMem(); }

void CompanyUniverse::cleanMem()	{
	cleanMem_CompanyUniverse();
	ObjectUniverse::cleanMem();
}

void CompanyUniverse::cleanMem_CompanyUniverse() {
	cleanMem_cid();
}

void CompanyUniverse::cleanMem_cid() {
	_cid=NULL;
}

/** ------------- Data Access Functions --------------------*/

CompanyIdentifier* CompanyUniverse::cid() {return _cid;}

/** ------------- Access classname dynamically --------------------*/

string CompanyUniverse::className() const {return "CompanyUniverse";}

/** ------------- Error Message Handling Functions ------------------*/

void CompanyUniverse::myerr_msg(string msg, string func) {
	err_msg("CompanyUniverse::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void CompanyUniverse::fprint(string fname) {
	ObjectUniverse::fprint(fname);
	fprint_CompanyUniverse(fname);
}

void CompanyUniverse::fprint_CompanyUniverse(string fname) {
	util_fprint(util_ofname(fname,"cid_id"),_cid->id());
}

void CompanyUniverse::fscan(string fname) {
	ObjectUniverse::fscan(fname);
	fscan_CompanyUniverse(fname);
}

void CompanyUniverse::fscan_CompanyUniverse(string fname) {
   {
      string s;
      util_fscan(util_ofname(fname,"cid_id"),s);
      _cid = CompanyIdentifier::instance(s);
   }
}

/** ------------- Reset Functions --------------------*/

void CompanyUniverse::reset() {
	reset_CompanyUniverse();
	ObjectUniverse::reset();
}

void CompanyUniverse::reset_CompanyUniverse() {
}

/** ----------  static instance function -----------*/


CompanyUniverse* CompanyUniverse::instance(CompanyIdentifier* cid)	{
	CompanyUniverse* ptr=new CompanyUniverse();
	ptr->init(cid);
	return ptr;
}


CompanyUniverse* CompanyUniverse::instance_fscan(string fname)	{
	CompanyUniverse* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new CompanyUniverse();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

Company* CompanyUniverse::obj(string id, bool create_flag) {
   return (Company*) ObjectUniverse::obj(id,create_flag);
}

Company* CompanyUniverse::gen_obj_guts(string id) {
   return Company::instance(_cid, id);
}

CompanyUniverse* CompanyUniverse::instantiate() {
   return CompanyUniverse::instance(this->cid());
}

CompanyUniverse* CompanyUniverse::sub(int m, string* cmap, bool ignore_flag) {
   return (CompanyUniverse*) ObjectUniverse::sub(m,cmap,ignore_flag);
}

CompanyUniverse* CompanyUniverse::sub(set<string>* S, bool ignore_flag) {
   return (CompanyUniverse*) ObjectUniverse::sub(S,ignore_flag);
}

#endif

