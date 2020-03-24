// Name:     PropertyPlantEquipmentAccount.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_PropertyPlantEquipmentAccount_cpp
#define ASX_PropertyPlantEquipmentAccount_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "PropertyPlantEquipmentAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;

/** --------------Constructors and init_NULL-----------*/

PropertyPlantEquipmentAccount::PropertyPlantEquipmentAccount() { init_NULL(); }
PropertyPlantEquipmentAccount::PropertyPlantEquipmentAccount(const PropertyPlantEquipmentAccount* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
PropertyPlantEquipmentAccount::PropertyPlantEquipmentAccount(const PropertyPlantEquipmentAccount& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void PropertyPlantEquipmentAccount::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void PropertyPlantEquipmentAccount::init() {
   PositionAccount::init();
	init_PropertyPlantEquipmentAccount();
}

void PropertyPlantEquipmentAccount::init_PropertyPlantEquipmentAccount() {
   set_id("PropertyPlantEquipmentAccount");
}

/** -----Destructors and Memory Cleanup functions -----*/

PropertyPlantEquipmentAccount::~PropertyPlantEquipmentAccount()	{ cleanMem(); }

void PropertyPlantEquipmentAccount::cleanMem()	{
	cleanMem_PropertyPlantEquipmentAccount();
   PositionAccount::cleanMem();
}

void PropertyPlantEquipmentAccount::cleanMem_PropertyPlantEquipmentAccount() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string PropertyPlantEquipmentAccount::className() const {return "PropertyPlantEquipmentAccount";}

/** ------------- Error Message Handling Functions ------------------*/

void PropertyPlantEquipmentAccount::myerr_msg(string msg, string func) {
	err_msg("PropertyPlantEquipmentAccount::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void PropertyPlantEquipmentAccount::fprint(string fname) {
   PositionAccount::fprint(fname);
	fprint_PropertyPlantEquipmentAccount(fname);
}

void PropertyPlantEquipmentAccount::fprint_PropertyPlantEquipmentAccount(string fname) {
}

void PropertyPlantEquipmentAccount::fscan(string fname) {
   PositionAccount::fscan(fname);
	fscan_PropertyPlantEquipmentAccount(fname);
}

void PropertyPlantEquipmentAccount::fscan_PropertyPlantEquipmentAccount(string fname) {
}

/** ------------- Reset Functions --------------------*/

void PropertyPlantEquipmentAccount::reset() {
	reset_PropertyPlantEquipmentAccount();
   PositionAccount::reset();
}

void PropertyPlantEquipmentAccount::reset_PropertyPlantEquipmentAccount() {
}

/** ----------  static instance function -----------*/


PropertyPlantEquipmentAccount* PropertyPlantEquipmentAccount::instance()	{
	PropertyPlantEquipmentAccount* ptr = NULL;
   string id = "PropertyPlantEquipmentAccount";

   ptr = (PropertyPlantEquipmentAccount*) util_singleton("PropertyPlantEquipmentAccount",id);
   if(ptr==NULL) {
      ptr = new PropertyPlantEquipmentAccount();
      ptr->init();
      util_singleton("PropertyPlantEquipmentAccount",id,ptr);
   }
	return ptr;
}

PropertyPlantEquipmentAccount* PropertyPlantEquipmentAccount::instance_fscan(string fname)	{
   return PropertyPlantEquipmentAccount::instance();
}

/** ----------  Non-standard functions start here -----------*/

PropertyPlantEquipmentAccount* PropertyPlantEquipmentAccount::__ptr_PropertyPlantEquipmentAccount = PropertyPlantEquipmentAccount::instance();

#endif

