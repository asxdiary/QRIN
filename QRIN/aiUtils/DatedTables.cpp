// Name:     DatedTables.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DatedTables_cpp
#define ASX_DatedTables_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "UtilDate.hpp"
#include "SMatrix.hpp"
#include "DatedTables.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiUtils;
using namespace aiMath;

/** --------------Constructors and init_NULL-----------*/

DatedTables::DatedTables() { init_NULL(); }
DatedTables::DatedTables(const DatedTables* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
DatedTables::DatedTables(const DatedTables& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void DatedTables::init_NULL()	{
	_data=NULL;
}

/** ---Public Data Setting Functions-----------------*/

void DatedTables::set_src(string _obj) {_src = _obj;}
void DatedTables::set_lookback(int _obj) {_lookback = _obj;}

void DatedTables::set_data(unordered_map<UtilDate*,SMatrix*>* _obj) {
   cleanMem_data();
   _data = _obj;
}

void DatedTables::set_data(UtilDate* d, SMatrix* smat) {
   if(_data->find(d)!=_data->end()) {delete (*_data)[d]; (*_data)[d] = NULL;}
   (*_data)[d] = smat;
   return;
}

/** --------   Init Functions -------------------------*/

void DatedTables::init(string src, unordered_map<UtilDate*,SMatrix*>* data) {
   Object::init();
	init_DatedTables(src, data);
}

void DatedTables::init_DatedTables(string src, unordered_map<UtilDate*,SMatrix*>* data) {
	init_src(src);
	init_lookback(DatedTables_lookback_default);
	init_data(data);
}

void DatedTables::init_src(string obj) { set_src(obj);}
void DatedTables::init_lookback(int obj) { set_lookback(obj);}
void DatedTables::init_data(unordered_map<UtilDate*,SMatrix*>* obj) { 
   if(obj==NULL) obj = new unordered_map<UtilDate*,SMatrix*>();
   set_data(obj);
}

/** -----Destructors and Memory Cleanup functions -----*/

DatedTables::~DatedTables()	{ cleanMem(); }

void DatedTables::cleanMem()	{
	cleanMem_DatedTables();
   Object::cleanMem();
}

void DatedTables::cleanMem_DatedTables() {
	cleanMem_data();
}

void DatedTables::cleanMem_data() {
   if(_data!=NULL) {
      unordered_map<UtilDate*,SMatrix*>::iterator it;
      for(it=_data->begin();it!=_data->end();it++) delete it->second;
      delete _data;
   }
	_data=NULL;
}

/** ------------- Data Access Functions --------------------*/

string DatedTables::src() {return _src;}
int DatedTables::lookback() {return _lookback;}
unordered_map<UtilDate*,SMatrix*>* DatedTables::data() {return _data;}
SMatrix* DatedTables::data(UtilDate* d) {
   unordered_map<UtilDate*,SMatrix*>::iterator it;
   it = _data->find(d);
   if(it==_data->end()) return NULL;
   return it->second;
}

/** ------------- Access classname dynamically --------------------*/

string DatedTables::className() const {return "DatedTables";}

/** ------------- Error Message Handling Functions ------------------*/

void DatedTables::myerr_msg(string msg, string func) {
	err_msg("DatedTables::",func," ",msg);
}

void DatedTables::mywarn_msg(string msg, string func) {
   warn_msg("DatedTables::",func," ",msg);
}


/** ------------- Printing and Scanning Options ------------------*/

void DatedTables::fprint(string fname) {
   Object::fprint(fname);
	fprint_DatedTables(fname);
}

void DatedTables::fprint_DatedTables(string fname) {
	util_ofprint(fname,"src",_src);
	util_ofprint(fname,"lookback",_lookback);
   {
      UtilDate* d = NULL;
      SMatrix* smat = NULL;
      list<string> L;
      unordered_map<UtilDate*,SMatrix*>::iterator it;
      string did;

      for(it=_data->begin();it!=_data->end();it++) {
         d = it->first; smat = it->second;
         L.push_back(did = d->id());
         util_ofprint_obj(fname,string("data.") + did,smat);
      }

      util_ofprint(fname,"data.L",&L);
   }

   return;
}

void DatedTables::fscan(string fname) {
   Object::fscan(fname);
	fscan_DatedTables(fname);
}

void DatedTables::fscan_DatedTables(string fname) {
	util_ofscan(fname,"src",_src);
	util_ofscan(fname,"lookback",_lookback);
   myerr_msg("Functionality not yet implemented for _data",__FUNCTION__);
}

/** ------------- Reset Functions --------------------*/

void DatedTables::reset() {
	reset_DatedTables();
   Object::reset();
}

void DatedTables::reset_DatedTables() {
}

/** ----------  static instance function -----------*/


DatedTables* DatedTables::instance(string src, unordered_map<UtilDate*,SMatrix*>* data)	{
	DatedTables* ptr=new DatedTables();
	ptr->init(src, data);
	return ptr;
}


DatedTables* DatedTables::instance_fscan(string fname)	{
	DatedTables* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new DatedTables();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

void DatedTables::load(UtilDate* ip_d, int err_flag) {
   int lookback = this->lookback();
   UtilDate* d = ip_d;
   bool flag = false;

   for(int K=0;K<lookback && (!flag);K++,d=d->prev_d()) {
      string fname = d->format(_src);
      SMatrix* smat = NULL;
      flag = util_chk(fname);
      if(flag) {
         if(K>0) printf("%s::%s Processing %s\n",className().c_str(),__FUNCTION__,fname.c_str());
         smat = SMatrix::instance_fscan(fname, true, Global::instance()->delimiter());
         set_data(d,smat);
      }
   }

   if(!flag) {
      string msg = _src + " not found for " + ip_d->id() + " after applying ";
      msg = msg + util_string(lookback) + " days of lookback";

      if(err_flag==0) myerr_msg(msg, __FUNCTION__);
      else if(err_flag==1) mywarn_msg(msg, __FUNCTION__);
   }

   return;
}

#endif

