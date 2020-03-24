// Name:     Utils.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_Utils_cpp
#define ASX_Utils_cpp


#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Global.hpp"
#include "Object.hpp"
#include "SMatrix.hpp"

using namespace aiUtils;
using namespace aiMath;

bool aiUtils::util_chk(string fname) {
   FILE* fp = fopen(fname.c_str(), "r");
   if(fp==NULL) return false;
   fclose(fp);
   return true;
}

void aiUtils::util_chk(ifstream& fp, string fname) {
   if(!fp.is_open()) {
      string msg;
      msg.append("Failed to open the file ");
      msg.append(fname);
      err_msg(msg);
   }
   return;
}

void aiUtils::util_chk(ofstream& fp, string fname) {
   if(!fp.is_open()) {
      string msg;
      msg.append("Failed to open the file ");
      msg.append(fname);
      err_msg(msg);
   }
   return;
}

void aiUtils::err_msg(string msg) {
   const int pid=getpid();
   char* cmsg=new char[msg.length()+100];

   sprintf(cmsg,"Error (PID=%d) %s\n",pid,msg.c_str());
   fprintf(stderr,"%s",cmsg);
   
   util_fprint("instances.txt",string(cmsg),ios::app);

   //clean memory
   delete [] cmsg;

   exit(-1);
}

void aiUtils::err_msg(string s1, string s2) {
   err_msg(s1.append(s2));
}

void aiUtils::err_msg(string s1, string s2, string s3) {
   err_msg(s1.append(s2),s3);
}

void aiUtils::err_msg(string s1, string s2, string s3, string s4) {
   err_msg(s1.append(s2),s3, s4);
}

void aiUtils::err_msg(string s1, string s2, string s3, string s4, string s5) {
   err_msg(s1.append(s2),s3, s4, s5);
}

void aiUtils::err_msg(string s1, string s2, string s3, string s4, string s5, string s6) {
   err_msg(s1.append(s2),s3, s4, s5, s6);
}


void aiUtils::util_fprint_NULL(string fname) {
   fname.append(".isNULL");
   ofstream fp;
   fp.open(fname.c_str(), ios::trunc); util_chk(fp, fname);
   fp << "NULL";
   fp.close();
}

bool aiUtils::util_fscan_NULL(string fname) {
   bool val = false;
   ofstream fp;

   fname.append(".isNULL");
   fp.open(fname.c_str(), ios::in); 
   val = fp.is_open();
   fp.close();
   return val;
}

void aiUtils::util_convert(string x, bool& y) {
   int val = atoi(x.c_str());
   if(val==0) y = false;
   else y = true;
}

void aiUtils::util_convert(string x, int& y) {y=atoi(x.c_str());}
void aiUtils::util_convert(string x, double& y) {y=atof(x.c_str());}
void aiUtils::util_convert(string x, string& y) {y=x;}

string* aiUtils::util_names(const string pfx, const int n) {
   string* x = NULL;
   x = new string[n];
   for(int i=0;i<n;i++) x[i] = string(pfx).append(util_string(i));
   return x;
}

string aiUtils::util_ofname(string fname, string oname) {
   return string(fname).append(".").append(oname);
}

string aiUtils::util_ofname(string fname, int oname) {
   return util_ofname(fname,util_string(oname));
}

bool aiUtils::util_isEqual(bool x1, bool x2) {return x1==x2;}
bool aiUtils::util_isEqual(int x1, int x2) {return x1==x2;}
bool aiUtils::util_isEqual(double x1, double x2, const double eps) {return fabs(x1-x2) <= eps;}
bool aiUtils::util_isEqual(string x1, string x2) {return x1.compare(x2)==0;}

void aiUtils::warn_msg(string msg) {
   const int pid=getpid();
   char* cmsg=new char[msg.length()+100];

   sprintf(cmsg,"Warning (PID=%d) %s\n",pid,msg.c_str());
   fprintf(stderr,"%s",cmsg);

   util_fprint("instances.txt",string(cmsg),ios_base::app);

   //clean memory
   delete [] cmsg;
}

void aiUtils::warn_msg(string s1, string s2) {
   warn_msg(s1.append(s2));
}

void aiUtils::warn_msg(string s1, string s2, string s3) {
   warn_msg(s1.append(s2),s3);
}

void aiUtils::warn_msg(string s1, string s2, string s3, string s4) {
   warn_msg(s1.append(s2),s3, s4);
}

void aiUtils::warn_msg(string s1, string s2, string s3, string s4, string s5) {
   warn_msg(s1.append(s2),s3, s4, s5);
}

void aiUtils::warn_msg(string s1, string s2, string s3, string s4, string s5, string s6) {
   warn_msg(s1.append(s2),s3, s4, s5, s6);
}

list<int>* aiUtils::util_rangeL(const int a, const int b) {
   list<int>* L = new list<int>();
   for(int i=a;i<b;i++) L->push_back(i);
   return L;
}

set<int>* aiUtils::util_rangeS(const int a, const int b) {
   set<int>* L = new set<int>();
   for(int i=a;i<b;i++) L->insert(i);
   return L;
}

unordered_map<int,int>* aiUtils::util_identity_map(const int a, const int b) {
   unordered_map<int,int>* m = new unordered_map<int,int>();
   for(int i=a;i<b;i++) (*m)[i] = i;
   return m;
}

void aiUtils::util_fprint_obj(string fname, Object* val) {
   if(val==NULL) {util_fprint_NULL(fname); return;}
   val->fprint(fname);
   return;
}

void aiUtils::util_ofprint_obj(string fname, string oname, Object* val) {
   util_fprint_obj(util_ofname(fname,oname),val);
}

void aiUtils::util_ofprint_obj(string fname, string oname, Object** val, const int n) {util_fprint_obj(util_ofname(fname,oname),val,n);} 
void aiUtils::util_ofprint_obj(string fname, string oname, Object*** val, const int m, const int n) {util_fprint_obj(util_ofname(fname,oname),val,m,n);} 
void aiUtils::util_ofprint_obj(string fname, string oname, list<Object*>* val) {util_fprint_obj(util_ofname(fname,oname),val);} 
void aiUtils::util_ofprint_obj(string fname, string oname, set<Object*>* val) {util_fprint_obj(util_ofname(fname,oname),val);} 

void aiUtils::util_fprint_obj(string fname, Object** val, const int n) {
   if(val==NULL) {util_fprint_NULL(fname); return;}
   for(int i=0;i<n;i++) util_fprint_obj(util_ofname(fname,util_string(i)), val[i]);
}

void aiUtils::util_fprint_obj(string fname, Object*** val, const int m, const int n) {
   if(val==NULL) {util_fprint_NULL(fname); return;}
   for(int i=0;i<m;i++) {
      for(int j=0;j<n;j++) {
         util_fprint_obj(util_ofname(fname,util_string(i)+"."+util_string(j)),val[i][j]);
      }
   }
}


void aiUtils::util_fprint_obj(string fname, list<Object*>* val) {
   if(val==NULL) {util_fprint_NULL(fname); return;}
   const int n = val->size();
   ofstream fp;
   list<Object*>::const_iterator it;
   int i;

   fp.open((fname + ".size").c_str(), ios::trunc); util_chk(fp, fname);
   fp << n;
   fp << "\n";
   fp.close();

   for(i=0, it=val->begin();it!=val->end();it++,i++) {
      util_fprint_obj(util_ofname(fname,util_string(i)),*it);
   }
}

void aiUtils::util_fprint_obj(string fname, set<Object*>* val) {
   if(val==NULL) {util_fprint_NULL(fname); return;}
   const int n = val->size();
   ofstream fp;
   set<Object*>::const_iterator it;
   int i;

   fp.open((fname + ".size").c_str(), ios::trunc); util_chk(fp, fname);
   fp << n;
   fp << "\n";
   fp.close();

   for(i=0, it=val->begin();it!=val->end();it++,i++) {
      util_fprint_obj(util_ofname(fname,util_string(i)),*it);
   }
}

void aiUtils::util_clean_obj(Object**& X, const int m) {
   if(X==NULL) return;
   for(int i=0;i<m;i++) delete X[i];
   delete [] X;
   X = NULL;
   return;
}

void aiUtils::util_clean_obj(Object***& X, const int m, const int n) {
   if(X==NULL) return;
   for(int i=0;i<m;i++) {
      if(X[i]==NULL) continue;
      for(int j=0;j<n;j++) delete X[i][j];
      delete [] X[i];
   }
   delete [] X;
   X = NULL;
   return;
}

int* aiUtils::util_rangeA(const int a, const int b) {
   const int n = b-a;
   int* x = new int[n];
   for(int i=0;i<n;i++) x[i] = a+i;
   return x;
}

int aiUtils::util_arrind(const int k, const int n) {
   if(k<0) return 0;
   if(k>=n) return n-1;
   return k;
}

string aiUtils::util_joinL(string sep, list<string>* L, string s) {
   if(L==NULL) return s;
   bool flag = false;
   for(list<string>::iterator it=L->begin();it!=L->end();it++) {
      if(flag) s.append(sep + (*it));
      else {
         if(s.length()==0) s.append(*it);
         else s.append(sep + (*it));
      }
   }
   return s;
}

void aiUtils::util_clean_obj(list<Object*>* L) {
   if(L==NULL) return;
   for(list<Object*>::iterator it=L->begin();it!=L->end();it++) delete *it;
   return;
}

bool aiUtils::util_isZero(double x) {return util_isEqual(x,0.0);}

string aiUtils::util_string (string val) {return val;}
string aiUtils::util_string (int val) {return to_string(val);}
string aiUtils::util_string (long val) {return to_string(val);}
string aiUtils::util_string (long long val) {return to_string(val);}
string aiUtils::util_string (unsigned val) {return to_string(val);}
string aiUtils::util_string (unsigned long val) {return to_string(val);}
string aiUtils::util_string (unsigned long long val) {return to_string(val);}
string aiUtils::util_string (long double val) {return to_string(val);}

string aiUtils::util_string (double val) {
   stringstream st;
   st.precision(Global::instance()->precision());
   st << val;
   return st.str();
}

string aiUtils::util_string (float val) {
   stringstream st;
   st.precision(Global::instance()->precision());
   st << val;
   return st.str();
}

string aiUtils::util_string_bool (bool val) {
   if(val) return "true";
   return "false";
}

void aiUtils::breakpoint(int x) {
   fflush(stdout);
   printf("aiUtils::%s %d\n",__FUNCTION__,x);
   return;
}

void aiUtils::breakpoint(double x) {
   fflush(stdout);
   printf("aiUtils::%s %2.8f\n",__FUNCTION__,x);
   return;
}


Object* aiUtils::util_singleton(string cname, string id, Object* ptr) {
   static unordered_map<string,unordered_map<string,Object*>*> objm;
   unordered_map<string,unordered_map<string,Object*>*>::iterator it;
   unordered_map<string,Object*>::iterator it2;
   unordered_map<string,Object*>* objm2 = NULL;
   Object* val = NULL;

   if(ptr!=NULL && ptr->className().compare(cname)!=0) err_msg("ptr!=NULL && ptr->id().compare(id)!=0");
   if(ptr!=NULL && ptr->id().compare(id)!=0) err_msg("ptr!=NULL && ptr->id().compare(id)!=0");

   if(cname.length()==0) {
      for(it=objm.begin();it!=objm.end();it++) {
         objm2 = it->second;
         for(it2=objm2->begin();it2!=objm2->end();it2++) delete it2->second;
         delete objm2;
      }
      return val;
   }

   while( (it=objm.find(cname)) == objm.end()) {
      if(ptr==NULL) return val;
      objm[cname] = new unordered_map<string,Object*>();
   }

   objm2 = it->second;
   while( (it2=objm2->find(id)) == objm2->end()) {
      if(ptr==NULL) return val;
      (*objm2)[id] = ptr;
   }
   val = it2->second;

   return val;
}

void aiUtils::util_fprint(string fname,list<unordered_map<string,string>*>* L, set<string>* headerS) {
   SMatrix* X = SMatrix::instance(L,headerS);
   X->fprint_raw(fname);
   delete X;
   return;
}

void aiUtils::util_set_debug_id(Object* obj, string id, string oname) {
   if(obj==NULL) return;
   if(oname.length()>0) id = util_join(".",oname,id);
   obj->set_debug_id(id);
}

void aiUtils::util_set_debug_info(Object* obj, bool debug_mode, string debug_pfx,
                                  string oname) 
{
   if(obj==NULL) return;
   if(oname.length()>0) debug_pfx = util_join(".",debug_pfx,oname);
   obj->set_debug_info(debug_mode, debug_pfx);
}

int aiUtils::util_system(string arg1) {
   return system(arg1.c_str());
}

int aiUtils::util_system(string arg1, string arg2) {
   return util_system(util_join(" ",arg1, arg2));
}

int aiUtils::util_system(string arg1, string arg2, string arg3) {
   return util_system(util_join(" ",arg1, arg2, arg3));
}

int aiUtils::util_system(string arg1, string arg2, string arg3, string arg4) {
   return util_system(util_join(" ",arg1, arg2, arg3, arg4));
}

int aiUtils::util_system(string arg1, string arg2, string arg3, string arg4, string arg5) {
   return util_system(util_join(" ",arg1, arg2, arg3, arg4, arg5));
}

int aiUtils::util_system(string arg1, string arg2, string arg3, string arg4, string arg5,
                         string arg6) 
{
   return util_system(util_join(" ",arg1, arg2, arg3, arg4, arg5, arg6));
}


int aiUtils::util_system2(string arg1) {
   printf("%s: executing %s\n",__FUNCTION__,arg1.c_str());
   return util_system(arg1);
}

int aiUtils::util_system2(string arg1, string arg2) {
   printf("%s: executing %s %s\n",__FUNCTION__,arg1.c_str(),arg2.c_str());
   return util_system(arg1, arg2);
}

int aiUtils::util_system2(string arg1, string arg2, string arg3) {
   printf("%s: executing %s %s %s\n",__FUNCTION__,arg1.c_str(),arg2.c_str(),arg3.c_str());
   return util_system(arg1, arg2, arg3);
}

int aiUtils::util_system2(string arg1, string arg2, string arg3, string arg4) {
   printf("%s: executing %s %s %s %s\n",__FUNCTION__,arg1.c_str(),arg2.c_str(),arg3.c_str(),
          arg4.c_str());
   return util_system(arg1, arg2, arg3, arg4);
}

int aiUtils::util_system2(string arg1, string arg2, string arg3, string arg4, string arg5) {
   printf("%s: executing %s %s %s %s %s\n",__FUNCTION__,arg1.c_str(),arg2.c_str(),arg3.c_str(),
          arg4.c_str(), arg5.c_str());
   return util_system(arg1, arg2, arg3, arg4, arg5);
}

int aiUtils::util_system2(string arg1, string arg2, string arg3, string arg4, string arg5,
                          string arg6) 
{
   printf("%s: executing %s %s %s %s %s %s\n",__FUNCTION__,arg1.c_str(),arg2.c_str(),arg3.c_str(),
          arg4.c_str(), arg5.c_str(), arg6.c_str());
   return util_system(arg1, arg2, arg3, arg4, arg5, arg6);
}

int aiUtils::util_mkdir(string arg) {
   string cmd = "";
   cmd = cmd + "mkdir " + arg;
   return util_system(cmd);
}



#endif

