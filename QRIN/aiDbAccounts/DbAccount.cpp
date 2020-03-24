// Name:     DbAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DbAccount_cpp
#define ASX_DbAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DbAccount.hpp"
#include "ObjectDb.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;

/** --------------Constructors and init_NULL-----------*/

DbAccount::DbAccount() { init_NULL(); }
DbAccount::DbAccount(const DbAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
DbAccount::DbAccount(const DbAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void DbAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

void DbAccount::set_nhistory(int obj) {_nhistory = obj;}

void DbAccount::set_type(string obj) {
   if(!check_type(obj)) myerr_msg(obj + " is an invalid type",__FUNCTION__);
   _type = obj;
}

void DbAccount::set_dtype(string obj) {
   if(!check_dtype(obj)) myerr_msg(obj + " is an invalid dtype",__FUNCTION__);
   _dtype = obj;
}

/** --------   Init Functions -------------------------*/

void DbAccount::init(string type, string dtype) {
   Object::init();
	init_DbAccount(type, dtype);
}

void DbAccount::init_DbAccount(string type, string dtype) {
	init_type(type);
	init_dtype(dtype);
	init_nhistory();
}

void DbAccount::init_type(string obj) {set_type(obj);}
void DbAccount::init_dtype(string obj) {set_dtype(obj);}
void DbAccount::init_nhistory() {set_nhistory(1);}

/** -----Destructors and Memory Cleanup functions -----*/

DbAccount::~DbAccount()	{ cleanMem(); }

void DbAccount::cleanMem()	{
	cleanMem_DbAccount();
   Object::cleanMem();
}

void DbAccount::cleanMem_DbAccount() {
}

/** ------------- Data Access Functions --------------------*/

string DbAccount::type() {return _type;}
string DbAccount::dtype() {return _dtype;}
int DbAccount::nhistory() {return _nhistory;}

/** ------------- Access classname dynamically --------------------*/

string DbAccount::className() const {return "DbAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void DbAccount::myerr_msg(string msg, string func) {
	err_msg("DbAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void DbAccount::fprint(string fname) {
   Object::fprint(fname);
	fprint_DbAccount(fname);
}

void DbAccount::fprint_DbAccount(string fname) {
	util_ofprint(fname,"type",_type);
	util_ofprint(fname,"dtype",_dtype);
	util_ofprint(fname,"nhistory",_nhistory);
}

void DbAccount::fscan(string fname) {
   Object::fscan(fname);
	fscan_DbAccount(fname);
}

void DbAccount::fscan_DbAccount(string fname) {
	util_ofscan(fname,"type",_type);
	util_ofscan(fname,"dtype",_dtype);
	util_ofscan(fname,"nhistory",_nhistory);
}

/** ------------- Reset Functions --------------------*/

void DbAccount::reset() {
	reset_DbAccount();
   Object::reset();
}

void DbAccount::reset_DbAccount() {
}

/** ----------  static instance function -----------*/


DbAccount* DbAccount::instance(string type, string dtype)	{
	DbAccount* ptr=new DbAccount();
	ptr->init(type, dtype);
	return ptr;
}


DbAccount* DbAccount::instance_fscan(string fname)	{
	DbAccount* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new DbAccount();
		ptr->fscan(fname);
	}
	return ptr;
}

bool DbAccount::check_type(string obj) {
   static set<string> S;
   if(S.size()==0) {
      S.insert("position");
      S.insert("flow");
      S.insert("growth");
      S.insert("ratio");
      S.insert("statistic");
      S.insert("days");
      S.insert("classification");
      S.insert("date");
      S.insert("generic");
   }
   return S.find(obj)!=S.end();
}

bool DbAccount::check_dtype(string obj) {
   static set<string> S;
   if(S.size()==0) {
      S.insert("double");
      S.insert("string");
   }
   return S.find(obj)!=S.end();
}

/** ----------  Non-standard functions start here -----------*/

void DbAccount::populate(ObjectDb* odb, string val, int& xval) {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
}

void DbAccount::agg(ObjectDb* odb, vector<ObjectDb*>* odbv, UtilDate* dh, int& xval) {
   xval=1;
   return;
}

void DbAccount::compute(vector<ObjectDb*>* odbv, int& xval) {
   xval = 0;
   if( (int) (odbv->size()) < nhistory()) {xval=1;}
   return;
}

void DbAccount::copy(UtilDate* dh, ObjectDb* odb1, ObjectDb* odb2, int& xval) {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
   xval=1;
   return;
}

void DbAccount::interpolate(ObjectDb* odb1, ObjectDb* odb2, ObjectDb* odb, 
                            int& xval) 
{
   xval = 1;
   return;
}

#endif

