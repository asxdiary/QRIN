// Name:     Summarizable.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_Summarizable_cpp
#define ASX_Summarizable_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Summarizable.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiUtils;

/** --------------Constructors and init_NULL-----------*/

Summarizable::Summarizable() { init_NULL(); }
Summarizable::Summarizable(const Summarizable* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
Summarizable::Summarizable(const Summarizable& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void Summarizable::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void Summarizable::init() {
	init_Summarizable();
}

void Summarizable::init_Summarizable() {
}

/** -----Destructors and Memory Cleanup functions -----*/

Summarizable::~Summarizable()	{ cleanMem(); }

void Summarizable::cleanMem()	{
	cleanMem_Summarizable();
}

void Summarizable::cleanMem_Summarizable() {
}

/** ------------- Data Access Functions --------------------*/


/** ------------- Access classname dynamically --------------------*/

string Summarizable::className() const {return "Summarizable";}

/** ------------- Error Message Handling Functions ------------------*/

void Summarizable::myerr_msg(string msg, string func) {
	err_msg("Summarizable::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void Summarizable::fprint(string fname) {
	fprint_Summarizable(fname);
}

void Summarizable::fprint_Summarizable(string fname) {
}

void Summarizable::fscan(string fname) {
	fscan_Summarizable(fname);
}

void Summarizable::fscan_Summarizable(string fname) {
}

/** ------------- Reset Functions --------------------*/

void Summarizable::reset() {
	reset_Summarizable();
}

void Summarizable::reset_Summarizable() {
}

/** ----------  static instance function -----------*/


Summarizable* Summarizable::instance()	{
	Summarizable* ptr=new Summarizable();
	ptr->init();
	return ptr;
}


Summarizable* Summarizable::instance_fscan(string fname)	{
	Summarizable* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new Summarizable();
		ptr->fscan(fname);
	}
	return ptr;
}

/** ----------  Non-standard functions start here -----------*/


void Summarizable::summary(list<unordered_map<string,string>*>*& L, set<string>* headerS) {
   if(L==NULL) L = new list<unordered_map<string,string>*>();
   return;
}

void Summarizable::fprint_summary(string fname, set<string>* headerS) {
   list<unordered_map<string,string>*>* L = NULL;
   this->summary(L, headerS);
   util_fprint(fname, L, headerS);
   util_clean(L);
}

#endif

