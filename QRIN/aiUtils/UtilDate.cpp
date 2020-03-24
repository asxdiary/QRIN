// Name:     UtilDate.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_UtilDate_cpp
#define ASX_UtilDate_cpp


#include <stdio.h>
#include <vector>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "UtilDate.hpp"
#include "Model.hpp"
#include "Global.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiUtils;

/** --------------Constructors and init_NULL-----------*/

UtilDate::UtilDate() { init_NULL(); }
UtilDate::UtilDate(const UtilDate* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
UtilDate::UtilDate(const UtilDate& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void UtilDate::init_NULL()	{
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void UtilDate::init(int yyyy, int mm, int dd) {
   Model::init();
	init_UtilDate(yyyy,mm,dd);
}

void UtilDate::init_UtilDate(int yyyy, int mm, int dd) {
	init_yyyy(yyyy);
	init_mm(mm);
	init_dd(dd);
   set_id(_genid(yyyy,mm,dd));
}

void UtilDate::init_yyyy(int obj) {_yyyy=obj;}
void UtilDate::init_mm(int obj) {_mm=obj;}
void UtilDate::init_dd(int obj) {_dd=obj;}

/** -----Destructors and Memory Cleanup functions -----*/

UtilDate::~UtilDate()	{ cleanMem(); }

void UtilDate::cleanMem()	{
	cleanMem_UtilDate();
   Model::cleanMem();
}

void UtilDate::cleanMem_UtilDate() {
}

/** ------------- Data Access Functions --------------------*/

int UtilDate::yyyy() {return _yyyy;}
int UtilDate::mm() {return _mm;}
int UtilDate::dd() {return _dd;}

/** ------------- Access classname dynamically --------------------*/

string UtilDate::className() const {return "UtilDate";}

/** ------------- Error Message Handling Functions ------------------*/

void UtilDate::myerr_msg(string msg, string func) {
	err_msg("UtilDate::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void UtilDate::fprint(string fname) {
   Model::fprint(fname);
	fprint_UtilDate(fname);
}

void UtilDate::fprint_UtilDate(string fname) {
}

void UtilDate::fscan(string fname) {
   Model::fscan(fname);
	fscan_UtilDate(fname);
}

void UtilDate::fscan_UtilDate(string fname) {
   string id = this->id();
   if(id.length()!=9) myerr_msg("id.length()!=9",__FUNCTION__);

   _yyyy = atoi(id.substr(1,4).c_str());
   _mm = atoi(id.substr(5,2).c_str());
   _dd = atoi(id.substr(7,2).c_str());
}

/** ------------- Reset Functions --------------------*/

void UtilDate::reset() {
	reset_UtilDate();
   Model::reset();
}

void UtilDate::reset_UtilDate() {
}

/** ----------  static instance function -----------*/


UtilDate* UtilDate::instance(int yyyy, int mm, int dd)	{
   static UtilDate**** db = NULL;
   UtilDate* ptr = NULL;

   const int yyyya = 1950;
   const int yyyyb = 2023;
   const int mma = 1;
   const int mmb = 12;
   const int dda = 1;
   const int ddb = 31;
   int iy, im, id;

   if(db==NULL) {
      db = new UtilDate***[yyyyb-yyyya+1];
      for(int yyyy=yyyya;yyyy<=yyyyb;yyyy++) {
         iy = yyyy - yyyya;
         db[iy] = new UtilDate**[mmb-mma+1];
         for(int mm=mma;mm<=mmb;mm++) {
            im = mm - mma;
            db[iy][im] = new UtilDate*[ddb-dda+1];
            for(int dd=dda;dd<=ddb;dd++) {
               id = dd - dda;
               db[iy][im][id] = NULL;
            }
         }
      }
   }

   if(yyyy==-1) {
      for(int yyyy=yyyya;yyyy<=yyyyb;yyyy++) {
         iy = yyyy - yyyya;
         for(int mm=mma;mm<=mmb;mm++) {
            im = mm - mma;
            for(int dd=dda;dd<=ddb;dd++) {
               id = dd - dda;
               delete db[iy][im][id];
            }
            delete [] db[iy][im];
         }
         delete [] db[iy];
      }
      delete [] db;
      db = NULL;
   }
   else {
      iy = yyyy - yyyya;
      im = mm - mma;
      id = dd - dda;
      if(iy<0 || iy>yyyyb-yyyya) err_msg("UtilDate::instance invalid yyyy");
      if(im<0 || im>mmb-mma) err_msg("UtilDate::instance invalid mm");
      if(id<0 || id>ddb-dda) err_msg("UtilDate::instance invalid dd");
      ptr = db[iy][im][id];
      if(ptr==NULL) {
         ptr = new UtilDate();
         ptr->init(yyyy,mm,dd);
         db[iy][im][id] = ptr;
      }
   }

   return ptr;
}


UtilDate* UtilDate::instance_fscan(string fname)	{
   UtilDate* ptr=NULL;
   if(!util_fscan_NULL(fname)) {
      int yyyy, mm, dd;
      ptr=new UtilDate();
      ptr->fscan(fname);
      yyyy = ptr->yyyy();
      mm = ptr->mm();
      dd = ptr->dd();
      delete ptr;
      ptr = UtilDate::instance(yyyy,mm,dd);
   }
   return ptr;
}

/** ----------  Non-standard functions start here -----------*/

string UtilDate::_genid(int yyyy, int mm, int dd) {
   string yyyyS = _genid(yyyy);
   string mmS = _genid(mm);
   string ddS = _genid(dd);
   return string("D") + yyyyS + mmS + ddS;
}

string UtilDate::_genid(int mm) {
   string mmS = util_string(mm);
   if(mm<10) mmS = util_string(0).append(mmS);
   return mmS;
}

string UtilDate::format(string fname) {
   unordered_map<string,string> m;

   m["yyyy"] = _genid(_yyyy);
   m["mm"] = _genid(_mm);
   m["dd"] = _genid(_dd);

   for(unordered_map<string,string>::iterator it=m.begin();it!=m.end();it++) {
      string s1 = it->first;
      string s2 = it->second; 
      size_t idx;
      for(;;) {
         idx = fname.find(s1);
         if(idx==string::npos) break;
         fname = fname.replace(idx,s1.length(),s2);
      }
   }

   return fname;
}

bool UtilDate::isBefore(UtilDate* d, bool eqflag) {
   if(eqflag && (this->icode()==d->icode())) return true;
   return this->icode()<d->icode();
}

bool UtilDate::isAfter(UtilDate* d, bool eqflag) {
   if(eqflag && (this->icode()==d->icode())) return true;
   return this->icode()>d->icode();
}

bool UtilDate::isEmpty(string dstr) {
   static set<string> sL;
   if(sL.size()==0) {
      sL.insert("");
      sL.insert("NA");
   }
   return sL.find(dstr)!=sL.end();
}

UtilDate* UtilDate::format(string dstr, string f) {
   UtilDate* ptr = NULL;

   if(isEmpty(dstr)) return ptr;
   else if(f.compare("yyyymmdd")==0) {
      int yyyy, mm, dd;
      sscanf(dstr.c_str(),"%4d%2d%2d",&yyyy,&mm,&dd);
      ptr = UtilDate::instance(yyyy,mm,dd);
   }
   else if(f.compare("yyyy-mm-dd")==0) {
      int yyyy, mm, dd;
      sscanf(dstr.c_str(),"%4d-%2d-%2d",&yyyy,&mm,&dd);
      ptr = UtilDate::instance(yyyy,mm,dd);
   }
   else if(f.compare("mm/dd/yyyy")==0) {
      int yyyy, mm, dd;
      sscanf(dstr.c_str(),"%2d/%2d/%4d",&mm,&dd,&yyyy);
      ptr = UtilDate::instance(yyyy,mm,dd);
   }
   else err_msg("UtilDate::format(string,string) Invalid format supplied f=",f);

   return ptr;
}

UtilDate* UtilDate::eom(UtilDate* d) {return eom(d->yyyy(),d->mm());}

UtilDate* UtilDate::eom(int yyyy, int mm) {
   static unordered_map<string,UtilDate*> eomm;
   UtilDate* ptr = NULL;
   string key;

   if(eomm.size()==0) {
      list<string>* L = NULL;
      list<string>::iterator it;
      UtilDate* val = NULL;
      string eom_src = Global::instance()->eom_src();
      string eom_format = Global::instance()->eom_format();

      util_fscan(eom_src, L);
      for(it=L->begin();it!=L->end();it++) {
         val = format(*it,eom_format);
         key = _genid(val->yyyy()) + _genid(val->mm());
         eomm[key] = val;
      }

      //clean memory
      delete L;
   }

   key = _genid(yyyy) + _genid(mm);
   ptr = eomm[key];

   return ptr;
}

UtilDate* UtilDate::prev_eom(UtilDate* d, int num) {
   int yyyy = d->yyyy();
   int mm = d->mm();
   UtilDate* ptr = NULL;
   int K, delta;

   K = num; delta = 1;
   if(K<0) {K *= (-1); delta = -1;}

   for(int i=0;i<K;i++) {
      mm -= delta;
      if(mm==0) {mm=12; yyyy--;}
      if(mm==13) {mm=1; yyyy++;}
   }

   ptr = eom(yyyy,mm);

   return ptr;
}

UtilDate* UtilDate::next_eom(UtilDate* d, int num) {return prev_eom(d,(-1)*num);}

int UtilDate::ndays(UtilDate* d1, UtilDate* d2) {return d2->icode()-d1->icode();}

int UtilDate::icode() {return _yyyy*10000 + _mm*100 + _dd;}

list<UtilDate*>* UtilDate::eomL(UtilDate* d1, UtilDate* d2, list<UtilDate*>* dL) {
   if(dL==NULL) dL = new list<UtilDate*>();
   UtilDate* d = NULL;
   UtilDate* dend = NULL;
   int num;

   if(d1->isBefore(d2)) num = -1;
   else num = 1;

   dend = UtilDate::eom(d2);
   for(d=eom(d1);d!=dend;d=prev_eom(d,num)) dL->push_back(d);

   return dL;
}

list<UtilDate*>* UtilDate::eoqL(UtilDate* d1, UtilDate* d2, list<UtilDate*>* dL) {
   if(dL==NULL) dL = new list<UtilDate*>();
   UtilDate* d = NULL;
   UtilDate* dend = NULL;
   int num;

   if(d1->isBefore(d2)) num = -1;
   else num = 1;

   dend = UtilDate::eom(d2);
   for(d=eom(d1);d!=dend;d=prev_eom(d,num)) {
      if(d->mm()%3==0) dL->push_back(d);
   }

   return dL;
}



vector<UtilDate*>* UtilDate::eomV(UtilDate* d1, UtilDate* d2, vector<UtilDate*>* dV) {
   if(dV==NULL) dV = new vector<UtilDate*>();
   UtilDate* d = NULL;
   UtilDate* dend = NULL;
   int num;

   if(d1->isBefore(d2)) num = -1;
   else num = 1;

   dend = UtilDate::eom(d2);
   for(d=eom(d1);d!=dend;d=prev_eom(d,num)) dV->push_back(d);

   return dV;
}



list<UtilDate*>* UtilDate::sort_algo_insertion(list<UtilDate*>* L, bool rev_flag) {
   if(L==NULL) return NULL;
   if(L->size()==0) return new list<UtilDate*>();

   UtilDate** a = NULL;
   UtilDate* d = NULL;
   int n = L->size();
   list<UtilDate*>::iterator it;
   list<UtilDate*>* sL = NULL;
   int i;

   a = new UtilDate*[n];
   i = 0;
   for(it=L->begin();it!=L->end();it++) a[i++] = *it;

   for(int i=0;i<n;i++) {
      for(int j=i+1;j<n;j++) {
         if(!rev_flag && (!a[i]->isAfter(a[j]))) continue;
         if(rev_flag && (!a[j]->isAfter(a[i]))) continue;
         d = a[i]; a[i] = a[j]; a[j] = d;
      }
   }

   sL = new list<UtilDate*>();
   for(int i=0;i<n;i++) sL->push_back(a[i]);

   delete [] a;
   return sL;
}

list<UtilDate*>* UtilDate::sort_algo_insertion(set<UtilDate*>* L, bool rev_flag) {
   list<UtilDate*> tL;
   set<UtilDate*>::iterator it;
   for(it=L->begin();it!=L->end();it++) tL.push_back(*it);
   return sort_algo_insertion(&tL, rev_flag);
}

int UtilDate::nmonths(UtilDate* d1, UtilDate* d2) {
   return (d2->yyyy() - d1->yyyy()) * 12 + d2->mm() - d1->mm();
}

UtilDate* UtilDate::instance(string dstr) {
   if(dstr.length()!=9) err_msg("UtilDate::instance dstr.length()!=9");
   return instance( atoi(dstr.substr(1,8).c_str()) );
}

UtilDate* UtilDate::instance(int icode) {
   int yyyy = int(icode/10000);
   int mm = int( (icode-yyyy*10000)/100 );
   int dd = int( (icode-yyyy*10000-mm*100) );
   return UtilDate::instance(yyyy,mm,dd);
}

vector<UtilDate*>* UtilDate::eoq(UtilDate* d, vector<UtilDate*>* dV) {
   if(dV==NULL) dV = new vector<UtilDate*>(4);
   if(dV->size()<4) dV->resize(4,NULL);
   for(int i=3;i>=0;i--) {
      (*dV)[3-i] = UtilDate::prev_eom(d,3*i);
   }
   return dV;
}

bool UtilDate::isBetween(UtilDate* d1, UtilDate* d2, bool eqflag1, bool eqflag2) {
   bool flag = true;
   flag = flag && this->isAfter(d1,eqflag1);
   flag = flag && this->isBefore(d2,eqflag2);
   return flag;
}

UtilDate* UtilDate::prev_d(UtilDate* d, int num) {
   if(num==0) return d;
   if(num<0) return next_d(d,(-1) * num);
   if(d->dd()==1) d = UtilDate::prev_eom(UtilDate::eom(d), 1);
   else d = UtilDate::instance(d->yyyy(), d->mm(), d->dd()-1 );
   return prev_d(d,num-1);
}

UtilDate* UtilDate::next_d(UtilDate* d, int num) {
   if(num==0) return d;
   if(num<0) return prev_d(d,(-1) * num);
   if(d==UtilDate::eom(d)) {
      d = UtilDate::next_eom(d,1);
      d = UtilDate::instance(d->yyyy(), d->mm(), 1);
   }
   else d = UtilDate::instance(d->yyyy(),d->mm(),d->dd() + 1);
   return next_d(d,num-1);
}

UtilDate* UtilDate::prev_m(UtilDate* d, int num) {
   if(num==0) return d;
   if(num<0) return next_m(d,(-1) * num);
   int yyyy, mm, dd;
   UtilDate* y = NULL;

   yyyy = d->yyyy();
   mm = d->mm();
   dd = d->dd();

   mm--;
   if(mm==0) {mm=12; yyyy--;}
   y = UtilDate::eom(yyyy,mm);

   if(y->dd() < dd) d = y;
   else d = UtilDate::instance(yyyy, mm, dd);

   return prev_m(d,num-1);
}

UtilDate* UtilDate::next_m(UtilDate* d, int num) {
   if(num==0) return d;
   if(num<0) return prev_m(d,(-1) * num);

   int yyyy, mm, dd;
   UtilDate* y = NULL;

   yyyy = d->yyyy();
   mm = d->mm();
   dd = d->dd();

   mm++;
   if(mm==13) {mm=1; yyyy++;}
   y = UtilDate::eom(yyyy,mm);

   if(y->dd() < dd) d = y;
   else d = UtilDate::instance(yyyy, mm, dd);

   return next_m(d,num-1);
}

UtilDate* UtilDate::max(vector<UtilDate*>* dv) {
   UtilDate* d = NULL;
   int icode = 0;
   int s = dv->size();
   int tmp;

   for(int i=0;i<s;i++) {
      tmp = dv->at(i)->icode();
      if(icode < tmp) icode = tmp;
   }

   if(icode>0) d = UtilDate::instance(icode);

   return d;
}

UtilDate* UtilDate::min(vector<UtilDate*>* dv) {
   UtilDate* d = NULL;
   int icode = -1;
   int s = dv->size();
   int tmp;

   for(int i=0;i<s;i++) {
      tmp = dv->at(i)->icode();
      if(icode < 0 || icode > tmp) icode = tmp;
   }

   if(icode>0) d = UtilDate::instance(icode);

   return d;
}

UtilDate* UtilDate::prev_m(int num) {return UtilDate::prev_m(this, num);}
UtilDate* UtilDate::next_m(int num) {return UtilDate::next_m(this, num);}
UtilDate* UtilDate::prev_d(int num) {return UtilDate::prev_d(this, num);}
UtilDate* UtilDate::next_d(int num) {return UtilDate::next_d(this, num);}
UtilDate* UtilDate::prev_eom(int num) {return UtilDate::prev_eom(this, num);}
UtilDate* UtilDate::next_eom(int num) {return UtilDate::next_eom(this, num);}
UtilDate* UtilDate::eom() {return UtilDate::eom(this);}


#endif

