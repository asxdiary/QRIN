// Name:     GenericDoubleDbAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_GenericDoubleDbAccount_cpp
#define ASX_GenericDoubleDbAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DoubleDbAccount.hpp"
#include "GenericDoubleDbAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiDbAccounts;

/** --------------Constructors and init_NULL-----------*/

GenericDoubleDbAccount::GenericDoubleDbAccount() { init_NULL(); }
GenericDoubleDbAccount::GenericDoubleDbAccount(const GenericDoubleDbAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
GenericDoubleDbAccount::GenericDoubleDbAccount(const GenericDoubleDbAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void GenericDoubleDbAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void GenericDoubleDbAccount::init(string id) {
   DoubleDbAccount::init("generic");
	init_GenericDoubleDbAccount(id);
}

void GenericDoubleDbAccount::init_GenericDoubleDbAccount(string id) {
   set_id(id);
}

/** -----Destructors and Memory Cleanup functions -----*/

GenericDoubleDbAccount::~GenericDoubleDbAccount()	{ cleanMem(); }

void GenericDoubleDbAccount::cleanMem()	{
	cleanMem_GenericDoubleDbAccount();
   DoubleDbAccount::cleanMem();
}

void GenericDoubleDbAccount::cleanMem_GenericDoubleDbAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string GenericDoubleDbAccount::className() const {return "GenericDoubleDbAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void GenericDoubleDbAccount::myerr_msg(string msg, string func) {
	err_msg("GenericDoubleDbAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void GenericDoubleDbAccount::fprint(string fname) {
   DoubleDbAccount::fprint(fname);
	fprint_GenericDoubleDbAccount(fname);
}

void GenericDoubleDbAccount::fprint_GenericDoubleDbAccount(string fname) {
}

void GenericDoubleDbAccount::fscan(string fname) {
   DoubleDbAccount::fscan(fname);
	fscan_GenericDoubleDbAccount(fname);
}

void GenericDoubleDbAccount::fscan_GenericDoubleDbAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void GenericDoubleDbAccount::reset() {
	reset_GenericDoubleDbAccount();
   DoubleDbAccount::reset();
}

void GenericDoubleDbAccount::reset_GenericDoubleDbAccount() {
}

/** ----------  static instance function -----------*/


GenericDoubleDbAccount* GenericDoubleDbAccount::instance(string id)	{
	GenericDoubleDbAccount* ptr = NULL;

   ptr = (GenericDoubleDbAccount*) util_singleton("GenericDoubleDbAccount",id);
   if(ptr==NULL) {
      ptr = new GenericDoubleDbAccount();
      ptr->init(id);
      util_singleton("GenericDoubleDbAccount",id,ptr);
   }
	return ptr;
}

GenericDoubleDbAccount* GenericDoubleDbAccount::instance_fscan(string fname)	{
   err_msg("GenericDoubleDbAccount::instance_fscan Functionality not yet implemented");
   return NULL;
}

/** ----------  Non-standard functions start here -----------*/

#endif

