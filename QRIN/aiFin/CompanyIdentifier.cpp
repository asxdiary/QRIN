// Name:     CompanyIdentifier.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CompanyIdentifier_cpp
#define ASX_CompanyIdentifier_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Object.hpp"
#include "CompanyIdentifier.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiFin;

/** --------------Constructors and init_NULL-----------*/

CompanyIdentifier::CompanyIdentifier() { init_NULL(); }
CompanyIdentifier::CompanyIdentifier(const CompanyIdentifier* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
CompanyIdentifier::CompanyIdentifier(const CompanyIdentifier& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void CompanyIdentifier::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void CompanyIdentifier::init(string id) {
   Object::init();
	init_CompanyIdentifier(id);
}

void CompanyIdentifier::init_CompanyIdentifier(string id) {
   set_id(id);
}

/** -----Destructors and Memory Cleanup functions -----*/

CompanyIdentifier::~CompanyIdentifier()	{ cleanMem(); }

void CompanyIdentifier::cleanMem()	{
	cleanMem_CompanyIdentifier();
   Object::cleanMem();
}

void CompanyIdentifier::cleanMem_CompanyIdentifier() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string CompanyIdentifier::className() const {return "CompanyIdentifier";}

/** ------------- Error Message Handling Functions ------------------*/

void CompanyIdentifier::myerr_msg(string msg, string func) {
	err_msg("CompanyIdentifier::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void CompanyIdentifier::fprint(string fname) {
   Object::fprint(fname);
	fprint_CompanyIdentifier(fname);
}

void CompanyIdentifier::fprint_CompanyIdentifier(string fname) {
}

void CompanyIdentifier::fscan(string fname) {
   Object::fscan(fname);
	fscan_CompanyIdentifier(fname);
}

void CompanyIdentifier::fscan_CompanyIdentifier(string fname) {
}

/** ------------- Reset Functions --------------------*/

void CompanyIdentifier::reset() {
	reset_CompanyIdentifier();
   Object::reset();
}

void CompanyIdentifier::reset_CompanyIdentifier() {
}

/** ----------  static instance function -----------*/


CompanyIdentifier* CompanyIdentifier::instance(string id)	{
	CompanyIdentifier* ptr = NULL;

   ptr = (CompanyIdentifier*) util_singleton("CompanyIdentifier",id);
   if(ptr==NULL) {
      ptr = new CompanyIdentifier();
      ptr->init(id);
      util_singleton("CompanyIdentifier",id,ptr);
   }
	return ptr;
}


CompanyIdentifier* CompanyIdentifier::instance_fscan(string fname)	{
	CompanyIdentifier* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
      string id;
		ptr=new CompanyIdentifier();
		ptr->fscan(fname);
      id = ptr->id();
      delete ptr;
      ptr = CompanyIdentifier::instance(id);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

CompanyIdentifier* CompanyIdentifier::AIID = CompanyIdentifier::instance("AIID");
CompanyIdentifier* CompanyIdentifier::name = CompanyIdentifier::instance("name");

#endif

