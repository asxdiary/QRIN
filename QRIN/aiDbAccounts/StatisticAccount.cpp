// Name:     StatisticAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_StatisticAccount_cpp
#define ASX_StatisticAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DoubleDbAccount.hpp"
#include "StatisticAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;

/** --------------Constructors and init_NULL-----------*/

StatisticAccount::StatisticAccount() { init_NULL(); }
StatisticAccount::StatisticAccount(const StatisticAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
StatisticAccount::StatisticAccount(const StatisticAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void StatisticAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void StatisticAccount::init() {
   DoubleDbAccount::init("statistic");
	init_StatisticAccount();
}

void StatisticAccount::init_StatisticAccount() {
}

/** -----Destructors and Memory Cleanup functions -----*/

StatisticAccount::~StatisticAccount()	{ cleanMem(); }

void StatisticAccount::cleanMem()	{
	cleanMem_StatisticAccount();
   DoubleDbAccount::cleanMem();
}

void StatisticAccount::cleanMem_StatisticAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string StatisticAccount::className() const {return "StatisticAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void StatisticAccount::myerr_msg(string msg, string func) {
	err_msg("StatisticAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void StatisticAccount::fprint(string fname) {
   DoubleDbAccount::fprint(fname);
	fprint_StatisticAccount(fname);
}

void StatisticAccount::fprint_StatisticAccount(string fname) {
}

void StatisticAccount::fscan(string fname) {
   DoubleDbAccount::fscan(fname);
	fscan_StatisticAccount(fname);
}

void StatisticAccount::fscan_StatisticAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void StatisticAccount::reset() {
	reset_StatisticAccount();
   DoubleDbAccount::reset();
}

void StatisticAccount::reset_StatisticAccount() {
}

/** ----------  static instance function -----------*/


StatisticAccount* StatisticAccount::instance()	{
	StatisticAccount* ptr=new StatisticAccount();
	ptr->init();
	return ptr;
}


StatisticAccount* StatisticAccount::instance_fscan(string fname)	{
	StatisticAccount* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new StatisticAccount();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/

#endif

