// Name:     DateAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DateAccount_cpp
#define ASX_DateAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DoubleDbAccount.hpp"
#include "DateAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;

/** --------------Constructors and init_NULL-----------*/

DateAccount::DateAccount() { init_NULL(); }
DateAccount::DateAccount(const DateAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
DateAccount::DateAccount(const DateAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void DateAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void DateAccount::init() {
   DoubleDbAccount::init("date");
	init_DateAccount();
}

void DateAccount::init_DateAccount() {
}

/** -----Destructors and Memory Cleanup functions -----*/

DateAccount::~DateAccount()	{ cleanMem(); }

void DateAccount::cleanMem()	{
	cleanMem_DateAccount();
	DoubleDbAccount::cleanMem();
}

void DateAccount::cleanMem_DateAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string DateAccount::className() const {return "DateAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void DateAccount::myerr_msg(string msg, string func) {
	err_msg("DateAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void DateAccount::fprint(string fname) {
	DoubleDbAccount::fprint(fname);
	fprint_DateAccount(fname);
}

void DateAccount::fprint_DateAccount(string fname) {
}

void DateAccount::fscan(string fname) {
	DoubleDbAccount::fscan(fname);
	fscan_DateAccount(fname);
}

void DateAccount::fscan_DateAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void DateAccount::reset() {
	reset_DateAccount();
	DoubleDbAccount::reset();
}

void DateAccount::reset_DateAccount() {
}

/** ----------  static instance function -----------*/


DateAccount* DateAccount::instance()	{
	DateAccount* ptr=new DateAccount();
	ptr->init();
	return ptr;
}


DateAccount* DateAccount::instance_fscan(string fname)	{
	DateAccount* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new DateAccount();
		ptr->init_NULL();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

void DateAccount::interpolate(ObjectDb* odb1, ObjectDb* odb2, ObjectDb* odb,
                              int& xval) 
{
   DbAccount::interpolate(odb1, odb2, odb, xval);
   return;
}

#endif

