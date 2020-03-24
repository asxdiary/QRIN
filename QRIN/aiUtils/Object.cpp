// Name:     Object.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_Object_cpp
#define ASX_Object_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Object.hpp"
#include "Summarizable.hpp"

using namespace aiUtils;

/** --------------Constructors and init_NULL-----------*/

Object::Object() { init_NULL(); }
Object::Object(const Object* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
Object::Object(const Object& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void Object::init_NULL()	{
   _debug_mode = false;
   _debug_pfx = "./tmp/";
   _debug_id = "Object.";
	_debug_objm=NULL;
   _debug_objm = new unordered_map<string,Object**>();
}

/** ---Protected Data Setting Functions-----------------*/

void Object::set_id(const string _obj) {
	_id=_obj;
}

void Object::set_debug_mode(bool _obj) {_debug_mode = _obj;}
void Object::set_debug_pfx(string _obj) {_debug_pfx = _obj;}

void Object::add_debug_objm(string str, Object** ptr) {
   (*_debug_objm)[str] = ptr;
}

/** --------   Init Functions -------------------------*/

void Object::init() {
	init_Object();
}

void Object::init_Object() {
	init_id();
   init_debug_mode();
   init_debug_pfx();
   init_debug_id();
	init_debug_objm();
}

void Object::init_id() {
   static int ctr = 0;
   _id = "Object." + util_string(ctr++);
}

void Object::init_debug_mode() {_debug_mode = false;}
void Object::init_debug_pfx() {_debug_pfx = "./tmp/Info";}
void Object::init_debug_id() {_debug_id = util_join(".",className(),"Debug");}

void Object::init_debug_objm() {}

/** -----Destructors and Memory Cleanup functions -----*/

Object::~Object()	{ cleanMem(); }

void Object::cleanMem()	{
	cleanMem_Object();
}

void Object::cleanMem_Object() {
	cleanMem_debug_objm();
}

void Object::cleanMem_debug_objm() {
   delete _debug_objm;
	_debug_objm=NULL;
}

/** ------------- Data Access Functions --------------------*/

string Object::id() {return _id;}
bool Object::debug_mode() {return _debug_mode;}
string Object::debug_pfx() {return _debug_pfx;}
string Object::debug_id() {return _debug_id;}
unordered_map<string,Object**>* Object::debug_objm() {return _debug_objm;}

/** ------------- Access classname dynamically --------------------*/

string Object::className() const {return "Object";}

/** ------------- Error Message Handling Functions ------------------*/

void Object::myerr_msg(string msg, string func) {
	string emsg;
	emsg.append("Object::");
	emsg.append(func);
	emsg.append(" ");
	emsg.append(msg);
	err_msg(emsg);
}

/** ------------- Printing and Scanning Options ------------------*/

void Object::fprint(string fname) {
   util_ofprint(fname, "id", _id);
}

void Object::fscan(string fname) {
   if(util_chk(util_ofname(fname,"id"))) util_ofscan(fname, "id", _id);
   else init_id();
}

/** ------------- Reset Functions --------------------*/

void Object::reset() {
	reset_Object();
}

void Object::reset_Object() {
}

/** ----------  static instance function -----------*/


Object* Object::instance()	{
	Object* ptr=new Object();
	ptr->init();
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

Object* Object::instantiate() {return Object::instance();}

void Object::fprint_table(string pfx) {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
}

void Object::debug(string oname, Object* obj) {
   if(!debug_mode()) return;
   util_ofprint_obj(util_join(".",debug_pfx(),debug_id()), oname, obj);
}

void Object::debug3(string oname, Summarizable* obj) {
   if(!debug_mode()) return;
   string fname = util_join(".",debug_pfx(),oname,debug_id());
   if(obj==NULL) util_fprint_NULL(fname);
   else obj->fprint_summary(util_join(".",fname,"csv"));
}

void Object::set_debug_info(bool debug_mode, string debug_pfx) {
   unordered_map<string,Object**>* debug_objm = this->debug_objm();
   unordered_map<string,Object**>::iterator it;

   set_debug_mode(debug_mode);
   set_debug_pfx(debug_pfx);

   for(it=debug_objm->begin();it!=debug_objm->end();it++) {
      util_set_debug_info(*(it->second),debug_mode,debug_pfx,it->first);
   }

   return;
}

void Object::set_debug_id(string _obj) {
   unordered_map<string,Object**>* debug_objm = this->debug_objm();
   unordered_map<string,Object**>::iterator it;

   _debug_id = _obj;

   for(it=debug_objm->begin();it!=debug_objm->end();it++) {
      util_set_debug_id(*(it->second),_obj);
   }

   return;
}


#endif

