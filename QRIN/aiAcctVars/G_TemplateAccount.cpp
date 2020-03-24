// Name:     G_TemplateAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_G_TemplateAccount_cpp
#define ASX_G_TemplateAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "G_DoubleDbAccount.hpp"
#include "TemplateFlowAccount.hpp"
#include "TemplatePositionAccount.hpp"
#include "G_TemplateAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctFields;
using namespace aiAcctVars;

/** --------------Constructors and init_NULL-----------*/

G_TemplateAccount::G_TemplateAccount() { init_NULL(); }
G_TemplateAccount::G_TemplateAccount(const G_TemplateAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
G_TemplateAccount::G_TemplateAccount(const G_TemplateAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void G_TemplateAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void G_TemplateAccount::init(bool geom_flag) {
   G_DoubleDbAccount::init(TemplatePositionAccount::instance(), geom_flag);
	init_G_TemplateAccount();
}

void G_TemplateAccount::init_G_TemplateAccount() {
   set_id("G_TemplateAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

G_TemplateAccount::~G_TemplateAccount()	{ cleanMem(); }

void G_TemplateAccount::cleanMem()	{
	cleanMem_G_TemplateAccount();
   G_DoubleDbAccount::cleanMem();
}

void G_TemplateAccount::cleanMem_G_TemplateAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string G_TemplateAccount::className() const {return "G_TemplateAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void G_TemplateAccount::myerr_msg(string msg, string func) {
	err_msg("G_TemplateAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void G_TemplateAccount::fprint(string fname) {
   G_DoubleDbAccount::fprint(fname);
	fprint_G_TemplateAccount(fname);
}

void G_TemplateAccount::fprint_G_TemplateAccount(string fname) {
}

void G_TemplateAccount::fscan(string fname) {
   G_DoubleDbAccount::fscan(fname);
	fscan_G_TemplateAccount(fname);
}

void G_TemplateAccount::fscan_G_TemplateAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void G_TemplateAccount::reset() {
	reset_G_TemplateAccount();
   G_DoubleDbAccount::reset();
}

void G_TemplateAccount::reset_G_TemplateAccount() {
}

/** ----------  static instance function -----------*/


G_TemplateAccount* G_TemplateAccount::instance(bool geom_flag)	{
	G_TemplateAccount* ptr = NULL;
   string id = "G_TemplateAccount";

   if(!geom_flag) id = id + "_geom_false";

   ptr = (G_TemplateAccount*) util_singleton("G_TemplateAccount",id);
   if(ptr==NULL) {
      ptr = new G_TemplateAccount();
      ptr->init(geom_flag);
      util_singleton("G_TemplateAccount",id,ptr);
   }
	return ptr;
}

G_TemplateAccount* G_TemplateAccount::instance_fscan(string fname)	{
   return G_TemplateAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

G_TemplateAccount* G_TemplateAccount::__ptr_G_TemplateAccount = G_TemplateAccount::instance();

#endif

