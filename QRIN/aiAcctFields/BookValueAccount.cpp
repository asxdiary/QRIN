// Name:     BookValueAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_BookValueAccount_cpp
#define ASX_BookValueAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "BookValueAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

BookValueAccount::BookValueAccount() { init_NULL(); }
BookValueAccount::BookValueAccount(const BookValueAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
BookValueAccount::BookValueAccount(const BookValueAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void BookValueAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void BookValueAccount::init() {
   PositionAccount::init();
	init_BookValueAccount();
}

void BookValueAccount::init_BookValueAccount() {
   set_id("BookValueAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

BookValueAccount::~BookValueAccount()	{ cleanMem(); }

void BookValueAccount::cleanMem()	{
	cleanMem_BookValueAccount();
   PositionAccount::cleanMem();
}

void BookValueAccount::cleanMem_BookValueAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string BookValueAccount::className() const {return "BookValueAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void BookValueAccount::myerr_msg(string msg, string func) {
	err_msg("BookValueAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void BookValueAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_BookValueAccount(fname);
}

void BookValueAccount::fprint_BookValueAccount(string fname) {
}

void BookValueAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_BookValueAccount(fname);
}

void BookValueAccount::fscan_BookValueAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void BookValueAccount::reset() {
	reset_BookValueAccount();
   PositionAccount::reset();
}

void BookValueAccount::reset_BookValueAccount() {
}

/** ----------  static instance function -----------*/


BookValueAccount* BookValueAccount::instance()	{
	BookValueAccount* ptr = NULL;
   string id = "BookValueAccount";

   ptr = (BookValueAccount*) util_singleton("BookValueAccount",id);
   if(ptr==NULL) {
      ptr = new BookValueAccount();
      ptr->init();
      util_singleton("BookValueAccount",id,ptr);
   }
	return ptr;
}

BookValueAccount* BookValueAccount::instance_fscan(string fname)	{
   return BookValueAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

BookValueAccount* BookValueAccount::__ptr_BookValueAccount = BookValueAccount::instance();

#endif

