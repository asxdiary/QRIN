// Name:     Global.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_Global_cpp
#define ASX_Global_cpp


#include <unordered_map>
#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Object.hpp"
#include "Global.hpp"
#include "ext_csvparser.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiUtils;

/** --------------Constructors and init_NULL-----------*/

Global::Global() { init_NULL(); }
Global::Global(const Global* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
Global::Global(const Global& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void Global::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void Global::init() {
   Object::init();
	init_Global();
}

void Global::init_Global() {
   _int_var = 0;
   _precision = 20;
   _double_var = 1.0;
   _eps = 1e-12;
   _string_var = "NA";
   _coin_home = "";
   _data_home = "";
   _compustatQ_home = "";
   _smartestFY_home = "";
   _savanetFY_home = "";
   _savanetQA_home = "";
   _mmdb_home = "";
   _adv3mdb_home = "";
   _dmdb_home = "";
   _vixdb_home = "";
   _mcapdb_home = "";
   _mna_home = "";
   _adrdb_home = "";
   _domdb_home = "";
   _vix_252d75pct_home = "";
   _vix_90davg_home = "";
   _r_home = "/home/asx/COIN/R/";
   _r_tmpdir = "";
   _delimiter = "|";
   _eom_src = "";
   _eom_format = "yyyymmdd";
}

/** -----Destructors and Memory Cleanup functions -----*/

Global::~Global()	{ cleanMem(); }

void Global::cleanMem()	{
	cleanMem_Global();
	Object::cleanMem();
}

void Global::cleanMem_Global() {
}

/** ------------- Data Access Functions --------------------*/

int Global::int_var() {return _int_var;}
int Global::precision() {return _precision;}
double Global::double_var() {return _double_var;}
double Global::eps() {return _eps;}
string Global::string_var() {return _string_var;}
string Global::coin_home() {return _coin_home;}
string Global::data_home() {return _data_home;}
string Global::compustatQ_home() {return _compustatQ_home;}
string Global::smartestFY_home() {return _smartestFY_home;}
string Global::savanetFY_home() {return _savanetFY_home;}
string Global::savanetQA_home() {return _savanetQA_home;}
string Global::mmdb_home() {return _mmdb_home;}
string Global::adv3mdb_home() {return _adv3mdb_home;}
string Global::dmdb_home() {return _dmdb_home;}
string Global::vixdb_home() {return _vixdb_home;}
string Global::mcapdb_home() {return _mcapdb_home;}
string Global::mna_home() {return _mna_home;}
string Global::adrdb_home() {return _adrdb_home;}
string Global::domdb_home() {return _domdb_home;}
string Global::vix_252d75pct_home() {return _vix_252d75pct_home;}
string Global::vix_90davg_home() {return _vix_90davg_home;}
string Global::r_home() {return _r_home;}
string Global::r_tmpdir() {return _r_tmpdir;}
string Global::delimiter() {return _delimiter;}
string Global::eom_src() {return _eom_src;}
string Global::eom_format() {return _eom_format;}

string Global::compustatQ_src() {return data_home() + compustatQ_home();}
string Global::smartestFY_src() {return data_home() + smartestFY_home();}
string Global::savanetFY_src() {return data_home() + savanetFY_home();}
string Global::savanetQA_src() {return data_home() + savanetQA_home();}
string Global::mmdb_src() {return mmdb_home();}
string Global::adv3mdb_src() {return adv3mdb_home();}
string Global::dmdb_src() {return dmdb_home();}
string Global::vixdb_src() {return vixdb_home();}
string Global::mcapdb_src() {return mcapdb_home();}
string Global::mna_src() {return mna_home();}
string Global::adrdb_src() {return adrdb_home();}
string Global::domdb_src() {return domdb_home();}
string Global::vix_252d75pct_src() {return vix_252d75pct_home();}
string Global::vix_90davg_src() {return vix_90davg_home();}

/** ------------- Access classname dynamically --------------------*/

string Global::className() const {return "Global";}

/** ------------- Error Message Handling Functions ------------------*/

void Global::myerr_msg(string msg, string func) {
	err_msg("Global::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void Global::fprint(string fname) {
	Object::fprint(fname);
	fprint_Global(fname);
}

void Global::fprint_Global(string fname) {
   unordered_map<string,string> m;
   m["int_var"] = util_string(int_var());
   m["precision"] = util_string(precision());
   m["double_var"] = util_string(double_var());
   m["eps"] = util_string(eps());
   m["string_var"] = util_string(string_var());
   m["coin_home"] = util_string(coin_home());
   m["data_home"] = util_string(data_home());
   m["compustatQ_home"] = util_string(compustatQ_home());
   m["smartestFY_home"] = util_string(smartestFY_home());
   m["savanetFY_home"] = util_string(savanetFY_home());
   m["savanetQA_home"] = util_string(savanetQA_home());
   m["mmdb_home"] = util_string(mmdb_home());
   m["adv3mdb_home"] = util_string(adv3mdb_home());
   m["dmdb_home"] = util_string(dmdb_home());
   m["vixdb_home"] = util_string(vixdb_home());
   m["mcapdb_home"] = util_string(mcapdb_home());
   m["mna_home"] = util_string(mna_home());
   m["mna_home"] = util_string(mna_home());
   m["adrdb_home"] = util_string(adrdb_home());
   m["domdb_home"] = util_string(domdb_home());
   m["vix_252d75pct_home"] = util_string(vix_252d75pct_home());
   m["vix_90davg_home"] = util_string(vix_90davg_home());
   m["r_home"] = util_string(r_home());
   m["r_tmpdir"] = util_string(r_tmpdir());
   m["eom_src"] = util_string(eom_src());
   m["eom_format"] = util_string(eom_format());
   /** The delimiter is never read/printer from/to the file */
   //m["delimiter"] = util_string(delimiter());
   util_ofprint(fname,"objm",&m);
}

void Global::fscan(string fname) {
	Object::fscan(fname);
	fscan_Global(fname);
}

void Global::fscan_Global(string fname) {
   unordered_map<string,string>* m = NULL;

   _delimiter = "|";
   aiExt::CsvParser_readmap(util_ofname(fname,"objm"),_delimiter,0,m);

   util_convert((*m)["int_var"],_int_var);
   util_convert((*m)["precision"],_precision);
   util_convert((*m)["double_var"],_double_var);
   util_convert((*m)["eps"],_eps);
   util_convert((*m)["string_var"],_string_var);
   util_convert((*m)["coin_home"],_coin_home);
   util_convert((*m)["data_home"],_data_home);
   util_convert((*m)["compustatQ_home"],_compustatQ_home);
   util_convert((*m)["smartestFY_home"],_smartestFY_home);
   util_convert((*m)["savanetFY_home"],_savanetFY_home);
   util_convert((*m)["savanetQA_home"],_savanetQA_home);
   util_convert((*m)["mmdb_home"],_mmdb_home);
   util_convert((*m)["adv3mdb_home"],_adv3mdb_home);
   util_convert((*m)["dmdb_home"],_dmdb_home);
   util_convert((*m)["vixdb_home"],_vixdb_home);
   util_convert((*m)["mcapdb_home"],_mcapdb_home);
   util_convert((*m)["mna_home"],_mna_home);
   util_convert((*m)["adrdb_home"],_adrdb_home);
   util_convert((*m)["domdb_home"],_domdb_home);
   util_convert((*m)["vix_252d75pct_home"],_vix_252d75pct_home);
   util_convert((*m)["vix_90davg_home"],_vix_90davg_home);
   util_convert((*m)["r_home"],_r_home);
   util_convert((*m)["r_tmpdir"],_r_tmpdir);
   util_convert((*m)["eom_src"],_eom_src);
   util_convert((*m)["eom_format"],_eom_format);
   /** The delimiter is never read/printer from/to the file */
   //util_convert((*m)["delimiter"],_delimiter);

   //clean memory
   delete m;
}

/** ------------- Reset Functions --------------------*/

void Global::reset() {
	reset_Global();
	Object::reset();
}

void Global::reset_Global() {
}

/** ----------  static instance function -----------*/

Global* Global::instance()	{
   Global* ptr = NULL;
   string id = "Global";

   ptr = (Global*) util_singleton("Global",id);
   if(ptr==NULL) {
      string fname = Utils_Global_src;
      ptr=new Global();
      ptr->init_NULL();
      ptr->fscan(fname);
      util_singleton("Global",ptr->id(),ptr);
   }
   return ptr;
}

/** ----------  Non-standard functions start here -----------*/

#endif

