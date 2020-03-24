// Name:     ObjectUniverse.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ObjectUniverse_cpp
#define ASX_ObjectUniverse_cpp

#include <unordered_map>
#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Model.hpp"
#include "ObjectUniverse.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiUtils;

/** --------------Constructors and init_NULL-----------*/

ObjectUniverse::ObjectUniverse() { init_NULL(); }
ObjectUniverse::ObjectUniverse(const ObjectUniverse* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
ObjectUniverse::ObjectUniverse(const ObjectUniverse& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void ObjectUniverse::init_NULL()	{
	_objm=NULL;
	_objL=NULL;
	_genL=NULL;
   _gen_flag=true;
}

/** ---Public Data Setting Functions-----------------*/

void ObjectUniverse::set_gen_flag(bool obj) {
   _gen_flag = obj;
}

/** --------   Init Functions -------------------------*/

void ObjectUniverse::init() {
   Model::init();
	init_ObjectUniverse();
}

void ObjectUniverse::init_ObjectUniverse() {
	init_objm();
	init_objL();
	init_genL();
}

void ObjectUniverse::init_objm() {
   _objm = new unordered_map<string,Object*>();
}

void ObjectUniverse::init_objL() {
   _objL = new list<Object*>();
}

void ObjectUniverse::init_genL() {
   _genL = new list<Object*>();
}

void ObjectUniverse::init_gen_flag() {
   _gen_flag = true;
}

/** -----Destructors and Memory Cleanup functions -----*/

ObjectUniverse::~ObjectUniverse()	{ cleanMem(); }

void ObjectUniverse::cleanMem()	{
	cleanMem_ObjectUniverse();
}

void ObjectUniverse::cleanMem_ObjectUniverse() {
	cleanMem_objL();
	cleanMem_genL();
	cleanMem_objm();
}

void ObjectUniverse::cleanMem_objm() {
   if(_objm!=NULL) {
      delete _objm;
   }
	_objm=NULL;
}

void ObjectUniverse::cleanMem_objL() {
   if(_objL!=NULL) {
      delete _objL;
   }
   _objL = NULL;
}

void ObjectUniverse::cleanMem_genL() {
   if(_genL!=NULL) {
      list<Object*>::iterator it;
      for(it=_genL->begin();it!=_genL->end();it++) delete *it;
      delete _genL;
   }
   _genL = NULL;
}

/** ------------- Data Access Functions --------------------*/

unordered_map<string,Object*>* ObjectUniverse::objm() {return _objm;}
list<Object*>* ObjectUniverse::genL() {return _genL;}
bool ObjectUniverse::gen_flag() {return _gen_flag;}

/** ------------- Access classname dynamically --------------------*/

string ObjectUniverse::className() const {return "ObjectUniverse";}

/** ------------- Error Message Handling Functions ------------------*/

void ObjectUniverse::myerr_msg(string msg, string func) {
	err_msg("ObjectUniverse::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void ObjectUniverse::fprint(string fname) {
	fprint_ObjectUniverse(fname);
}

void ObjectUniverse::fprint_ObjectUniverse(string fname) {
   {
      list<string> L;
      unordered_map<string,Object*>::iterator it;
      for(it=_objm->begin();it!=_objm->end();it++) L.push_back(it->first);
      util_fprint( util_ofname(fname,"objL"),&L);
   }
}

void ObjectUniverse::fscan(string fname) {
	fscan_ObjectUniverse(fname);
}

void ObjectUniverse::fscan_ObjectUniverse(string fname) {
   init_ObjectUniverse();

   {
      list<string>* L = NULL;
      list<string>::iterator it;
      util_ofscan(fname, "objL", L);
      for(it=L->begin();it!=L->end();it++) this->obj(*it,true);
      delete L;
   }

   return;
}

/** ------------- Reset Functions --------------------*/

void ObjectUniverse::reset() {
	reset_ObjectUniverse();
}

void ObjectUniverse::reset_ObjectUniverse() {
}

/** ----------  static instance function -----------*/


ObjectUniverse* ObjectUniverse::instance()	{
	ObjectUniverse* ptr=new ObjectUniverse();
	ptr->init();
	return ptr;
}


ObjectUniverse* ObjectUniverse::instance_fscan(string fname)	{
	ObjectUniverse* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new ObjectUniverse();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

Object* ObjectUniverse::obj(string id, bool create_flag) {
   Object* ptr = NULL;
   unordered_map<string,Object*>::iterator it;

   it = _objm->find(id);
   if(it!=_objm->end()) ptr = it->second;
   else if(create_flag && gen_flag()) add_obj(ptr = gen_obj(id));
   return ptr;
}

void ObjectUniverse::add_obj(Object* ptr) {
   if(ptr==NULL) return;
   (*_objm)[ptr->id()] = ptr;
   _objL->push_back(ptr);
}

Object* ObjectUniverse::gen_obj_guts(string id) {
   Object* ptr = NULL;
   ptr = Object::instance();
   ptr->set_id(id);
   return ptr;
}

Object* ObjectUniverse::gen_obj(string id) {
   if(!gen_flag()) myerr_msg("Function called when gen_flag=false",__FUNCTION__);
   Object* ptr = this->gen_obj_guts(id);
   genL()->push_back(ptr);
   return ptr;
}

ObjectUniverse* ObjectUniverse::instantiate() {return ObjectUniverse::instance();}

ObjectUniverse* ObjectUniverse::sub(int m, string* cmap, bool ignore_flag) {
   ObjectUniverse* ptr = NULL;
   Object* obj = NULL;

   ptr = this->instantiate();
   for(int i=0;i<m;i++) {
      obj = this->obj(cmap[i]);
      if(obj!=NULL) ptr->add_obj(obj);
      else if(!ignore_flag) myerr_msg(cmap[i] + " object not found",__FUNCTION__);
   }

   return ptr;
}

list<Object*>* ObjectUniverse::objL(set<string>* S, list<Object*>* L) {
   if(L==NULL) L = new list<Object*>();
   set<string>::iterator it;
   Object* obj = NULL;

   for(it=S->begin();it!=S->end();it++) {
      obj = this->obj(*it);
      if(obj!=NULL) L->push_back(obj);
   }
   return L;
}

list<Object*>* ObjectUniverse::objL(list<Object*>* L) {
   if(L==NULL) L = new list<Object*>();
   list<Object*>::iterator it;
   for(it=_objL->begin();it!=_objL->end();it++) L->push_back(*it);
   return L;
}



list<Object*>* ObjectUniverse::objL(int m, string* cmap, list<Object*>* L) {
   if(L==NULL) L = new list<Object*>();
	unordered_map<string,Object*>::iterator it;
   for(int i=0;i<m;i++) {
      it = _objm->find(cmap[i]);
      if(it==_objm->end()) myerr_msg(cmap[i] + " object not found",__FUNCTION__);
      L->push_back(it->second);
   }
   return L;
}

ObjectUniverse* ObjectUniverse::sub(set<string>* S, bool ignore_flag) {
   ObjectUniverse* ptr = NULL;
   set<string>::iterator it;
   Object* obj = NULL;
   string aid;

   ptr = this->instantiate();
   for(it=S->begin();it!=S->end();it++) {
      aid = *it;
      obj = this->obj(aid);
      if(obj!=NULL) ptr->add_obj(obj);
      else if(!ignore_flag) myerr_msg(aid + " object not found",__FUNCTION__);
   }

   return ptr;
}

set<string>* ObjectUniverse::oidS(set<string>* S) {
   if(S==NULL) S = new set<string>();
   list<Object*>::iterator it;
   for(it=_objL->begin();it!=_objL->end();it++) S->insert((*it)->id());
   return S;
}

Object** ObjectUniverse::objA(int& num) {
   Object** arr = NULL;
   list<Object*>::iterator it;
   int i;

   num = _objL->size();
   arr = new Object*[num];
   for(it=_objL->begin(),i=0;it!=_objL->end();it++) arr[i++] = *it;
   
   return arr;
}

#endif

