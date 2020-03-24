// Name:     Utils_templates.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_Utils_templates_hpp
#define ASX_Utils_templates_hpp

namespace aiUtils {
//Forword decalaration
class Global;
};

#include <string>
#include <iostream>
#include <list>
#include <set>
#include <unordered_map>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "ext_csvparser.hpp"
#include "Global.hpp"

using namespace std;

namespace aiUtils {

   /** Template Implementations */

   template<typename T>
      T** util_matrix(const int m, const int n, const T val) {
         T** X = NULL;
         X = new T*[m];
         for(int i=0;i<m;i++) {
            X[i] = new T[n];
            for(int j=0;j<n;j++) X[i][j] = val;
         }
         return X;
      }

   template<typename T>
      T** util_transpose(T** x, const int m, const int n) {
         if(x==NULL) return NULL;
         T** y = NULL;

         y = util_matrix(n,m,x[0][0]);
         for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) y[j][i] = x[i][j];
         }

         return y;
      }

   template<typename T>
      void util_clean(T*& X, const int m) {
         if(X==NULL) return;
         delete [] X;
         X = NULL;
         return;
      }

   template<typename T>
      void util_clean(T**& X, const int m, const int n) {
         if(X==NULL) return;
         for(int i=0;i<m;i++) delete [] X[i];
         delete [] X;
         X = NULL;
         return;
      }

   template<typename T>
      void util_fprint(string fname, T const& val, ios_base::openmode mode) {
         ofstream fp;
         fp.open(fname.c_str(), mode); util_chk(fp, fname);
         fp << setprecision(Global::instance()->precision()) << val;
         fp.close();
         return;
      }

   template<typename T>
      void util_fprint(string fname, const T* val, const int n, ios_base::openmode mode) {
         if(val==NULL) {util_fprint_NULL(fname); return;}
         ofstream fp;
         int precision = Global::instance()->precision();
         fp.open(fname.c_str(), mode); util_chk(fp, fname);
         fp << n;
         fp << "\n";
         for(int i=0;i<n;i++) {
            fp << setprecision(precision) << val[i];
            if(i<n-1) {fp << "\n";}
         }
         fp.close();
      }

   template<typename T>
      void util_fprint(string fname, T** val, const int m, const int n, ios_base::openmode mode) {
         if(val==NULL) {util_fprint_NULL(fname); return;}
         ofstream fp;
         int precision = Global::instance()->precision();
         string delimiter = Global::instance()->delimiter();
         fp.open(fname.c_str(), mode); util_chk(fp, fname);
         for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
               fp << setprecision(precision) << val[i][j];
               if(j==(n-1)) {fp << "\n";}
               else {fp << delimiter;}
            }
         }
         fp.close();
      }



   template<typename T>
      void util_fprint(string fname, list<T>* val, ios_base::openmode mode) {
         if(val==NULL) {util_fprint_NULL(fname); return;}
         const int n = val->size();
         ofstream fp;
         int precision = Global::instance()->precision();
         string delimiter = Global::instance()->delimiter();
         typename list<T>::const_iterator it;
         int i;

         fp.open(fname.c_str(), mode); util_chk(fp, fname);
         fp << n;
         fp << "\n";
         for(i=0, it=val->begin();it!=val->end();it++,i++) {
            fp << setprecision(precision) << *it;
            if(i<n-1) {fp << "\n";}
         }
         fp.close();
      }

   template<typename T>
      void util_fprint(string fname, set<T>* val, ios_base::openmode mode) {
         if(val==NULL) {util_fprint_NULL(fname); return;}
         const int n = val->size();
         ofstream fp;
         int precision = Global::instance()->precision();
         string delimiter = Global::instance()->delimiter();
         typename set<T>::const_iterator it;
         int i;

         fp.open(fname.c_str(), mode); util_chk(fp, fname);
         fp << n;
         fp << "\n";
         for(i=0, it=val->begin();it!=val->end();it++,i++) {
            fp << setprecision(precision) << *it;
            if(i<n-1) {fp << "\n";}
         }
         fp.close();
      }

   template<typename T1, typename T2>
      void util_fprint(string fname, unordered_map<T1,T2>* val, ios_base::openmode mode) {
         if(val==NULL) {util_fprint_NULL(fname); return;}
         const int n = val->size();
         ofstream fp;
         int precision = Global::instance()->precision();
         string delimiter = Global::instance()->delimiter();
         typename unordered_map<T1,T2>::const_iterator it;
         int i;

         fp.open(fname.c_str(), mode); util_chk(fp, fname);
         for(i=0, it=val->begin();it!=val->end();it++,i++) {
            fp << setprecision(precision) << it->first;
            fp << delimiter;
            fp << setprecision(precision) << it->second;
            if(i<n-1) {fp << "\n";}
         }
         fp.close();
      }

   template<typename T1, typename T2>
      void util_fprint(string fname, unordered_map<T1,set<T2>*>* val, ios_base::openmode mode) {
         if(val==NULL) {util_fprint_NULL(fname); return;}
         ofstream fp;
         typename unordered_map<T1,set<T2>*>::const_iterator it;

         fp.open(fname.c_str(), mode); util_chk(fp, fname);
         fp << val->size();
         fp.close();
         for(it=val->begin();it!=val->end();it++) {
            util_fprint(fname,"\n",ios::app);
            util_fprint(fname,it->first,ios::app);
            util_fprint(fname,"\n",ios::app);
            util_fprint(fname,it->second,ios::app);
         }
         fp.close();
      }

   template<typename T> 
      void util_fscan(string fname, T& val) {
         ifstream fp;
         fp.open(fname,ios::in); util_chk(fp, fname);
         fp >> val;
         fp.close();
      }

   template<typename T> 
      void util_fscan(string fname, T*& val, int& n) {
         if(util_fscan_NULL(fname)) {val=NULL; n=0; return;}
         ifstream fp;

         fp.open(fname,ios::in); util_chk(fp, fname);
         fp >> n;
         val = new T[n];
         for(int i=0;i<n;i++) fp >> val[i];
         fp.close();
      }

   template<typename T> 
      void util_fscan(string fname, list<T>*& val) {
         if(util_fscan_NULL(fname)) {val=NULL; return;}
         ifstream fp;
         T x;
         int n;

         fp.open(fname,ios::in); util_chk(fp, fname);
         fp >> n;
         val = new list<T>();
         for(int i=0;i<n;i++) {
            fp >> x;
            val->push_back(x);
         }
         fp.close();
      }

   template<typename T> 
      void util_fscan(string fname, set<T>*& val) {
         if(util_fscan_NULL(fname)) {val=NULL; return;}
         ifstream fp;
         T x;
         int n;

         fp.open(fname,ios::in); util_chk(fp, fname);
         fp >> n;
         val = new set<T>();
         for(int i=0;i<n;i++) {
            fp >> x;
            val->insert(x);
         }
         fp.close();
      }

   template<typename T1, typename T2>
      void util_fscan(string fname, unordered_map<T1,T2>*& val) {
         if(util_fscan_NULL(fname)) {val=NULL; return;}
         aiExt::CsvParser_readmap(fname,Global::instance()->delimiter(),0,val);
         return;
      }

   template<typename T1, typename T2>
      void util_fscan(string fname, unordered_map<T1,T2>**& val, int& num) {
         if(util_fscan_NULL(fname)) {val=NULL; num=0; return;}
         util_fscan(util_ofname(fname,"size"),num);
         val = new unordered_map<T1,T2>*[num];
         for(int i=0;i<num;i++) {
            val[i] = NULL;
            util_fscan(util_ofname(fname,i),val[i]);
         }
         return;
      }

   template<typename T> 
      void util_fscan(string fname, T**& val, int& m, int& n, string delimiter, 
                      int firstLineIsHeader,
                      string** headerp,
                      int firstColIsPrimary,
                      string** rmapp)
      {
         if(util_fscan_NULL(fname)) {val=NULL; m=n=0; return;}
         aiExt::CsvParser_readmatrix(m,n,val,fname,delimiter, firstLineIsHeader, headerp,
                                     firstColIsPrimary, rmapp);
      }

   template<typename T>
      void util_map_imap(T*& rmap, 
                         unordered_map<T,int>*& rimap, 
                         const int m)
      {
         int k;
         if(rmap==NULL && rimap==NULL) return ;
         else if(rmap==NULL) {
            rmap = util_imap(rimap,k);
            if((m>=0) && (k!=m)) err_msg("rimap is not fully defined",__FUNCTION__);
         }
         else if(rimap==NULL) rimap = util_imap(rmap, m);
      }

   template<typename T>
      unordered_map<T,int>* util_imap(const T* arr, const int n)
      {
         unordered_map<T,int>* m = NULL;
         m = new unordered_map<T,int>();
         for(int i=0;i<n;i++) (*m)[arr[i]] = i;
         return m;
      }


   template<typename T> 
      T* util_imap(const unordered_map<T,int>* rmap, int& n) 
      {
         T* x = NULL;

         n = 0;
         for(typename unordered_map<T,int>::const_iterator it=rmap->begin();it!=rmap->end();it++) {
            if(it->second > n) {n = it->second;}
         }
         n++;

         x = new T[n];
         for(typename unordered_map<T,int>::const_iterator it=rmap->begin();it!=rmap->end();it++) {
            x[it->second] = it->first;
         }

         return x;
      }

   template<typename T> void util_ofprint(string fname, string oname, T const& val) {util_fprint(util_ofname(fname,oname),val);}
   template<typename T> void util_ofprint(string fname, string oname, const T* val, const int n) {util_fprint(util_ofname(fname,oname),val,n);}
   template<typename T> void util_ofprint(string fname, string oname, T** val, const int m, const int n) {util_fprint(util_ofname(fname,oname),val,m,n);}
   template<typename T> void util_ofprint(string fname, string oname, list<T>* val) {util_fprint(util_ofname(fname,oname),val);}
   template<typename T> void util_ofprint(string fname, string oname, set<T>* val) {util_fprint(util_ofname(fname,oname),val);}
   template<typename T1, typename T2> void util_ofprint(string fname, string oname, unordered_map<T1,T2>* val) {util_fprint(util_ofname(fname,oname),val);}
   template<typename T1, typename T2> void util_ofprint(string fname, string oname, unordered_map<T1,T2>** val, const int num) {util_fprint(util_ofname(fname,oname),val,num);}
   template<typename T1, typename T2> void util_ofprint(string fname, string oname, unordered_map<T1,set<T2>*>* val) {util_fprint(util_ofname(fname,oname),val);}

   template<typename T> T util_copy(T val) {return val;}
   template<typename T> T* util_copy(T* val, const int  n) {
      if(val==NULL) return NULL;
      T* x = NULL;
      x = new T[n];
      for(int i=0;i<n;i++) x[i] = val[i];
      return x;
   }
   template<typename T> T** util_copy(T** val, const int  m, const int  n) {
      if(val==NULL) return NULL;
      T** x = NULL;
      x = new T*[m];
      for(int i=0;i<m;i++) x[i] = new T[n];
      for(int i=0;i<m;i++) {
         for(int j=0;j<n;j++) x[i][j] = val[i][j];
      }
      return x;
   }
   template<typename T> list<T>* util_copy(list<T>* val) {
      if(val==NULL) return NULL;
      list<T>* x = NULL;
      x = new list<T>();
      for(typename list<T>::iterator it=val->begin();it!=val->end();it++) x->push_back(*it);
      return x;
   }
   template<typename T> set<T>* util_copy(set<T>* val) {
      if(val==NULL) return NULL;
      set<T>* x = NULL;
      x = new set<T>();
      for(typename set<T>::iterator it=val->begin();it!=val->end();it++) x->insert(*it);
      return x;
   }
   template<typename T1, typename T2> unordered_map<T1,T2>* util_copy(unordered_map<T1,T2>* val) {
      if(val==NULL) return NULL;
      unordered_map<T1,T2>* x = NULL;
      x = new unordered_map<T1,T2>();
      for(typename unordered_map<T1,T2>::iterator it=val->begin();it!=val->end();it++) {
         (*x)[it->first] = it->second;
      }
      return x;
   }

   template<typename T> bool util_isEqual(T* val1, T* val2, const int  n) {
      if(val1==NULL && val2==NULL) return true;
      else if(val1==NULL || val2==NULL) return false;

      bool flag = true;
      for(int i=0;(i<n) && flag;i++) flag = util_isEqual(val1[i],val2[i]);

      return flag;
   }

   template<typename T> bool util_isEqual(T** val1, T** val2, const int  m, const int  n) {
      if(val1==NULL && val2==NULL) return true;
      else if(val1==NULL || val2==NULL) return false;

      bool flag = true;
      for(int i=0;i<m && flag;i++) {
         for(int j=0;j<n && flag;j++) flag = util_isEqual(val1[i][j], val2[i][j]);
      }

      return flag;
   }

   template<typename T> bool util_isEqual(list<T>* val1, list<T>* val2) {
      if(val1==NULL && val2==NULL) return true;
      else if(val1==NULL || val2==NULL) return false;

      set<T>* sval1 = NULL;
      set<T>* sval2 = NULL;
      bool flag = true;

      sval1 = util_set(val1);
      sval2 = util_set(val2);
      flag = util_isEqual(sval1, sval2);

      //clean memory
      delete sval1;
      delete sval2;

      return flag;
   }

   template<typename T> bool util_isEqual(set<T>* val1, set<T>* val2) {
      if(val1==NULL && val2==NULL) return true;
      else if(val1==NULL || val2==NULL) return false;

      bool flag = true;
      for(typename set<T>::iterator it=val1->begin();it!=val1->end() && flag;it++) {
         flag = ! (val2->find(*it) == val2->end());
      }

      for(typename set<T>::iterator it=val2->begin();it!=val2->end() && flag;it++) {
         flag = ! (val1->find(*it) == val1->end());
      }

      return flag;
   }

   template<typename T1, typename T2> bool util_isEqual(unordered_map<T1,T2>* val1, 
                                                        unordered_map<T1,T2>* val2) 
   {
      if(val1==NULL && val2==NULL) return true;
      else if(val1==NULL || val2==NULL) return false;

      bool flag = true;
      typename unordered_map<T1,T2>::iterator it1;
      typename unordered_map<T1,T2>::iterator it2;

      for(it1=val1->begin();it1!=val1->end() && flag;it1++) {
         it2 = val2->find(it1->first);
         if(it2==val2->end()) flag = false;
         else flag = util_isEqual(it1->second, it2->second);
      }

      for(it2=val2->begin();it2!=val2->end() && flag;it2++) {
         it1 = val1->find(it2->first);
         if(it1==val1->end()) flag = false;
         else flag = util_isEqual(it2->second, it1->second);
      }

      return flag;
   }

   template<typename T> set<T>* util_set(T* arr, int n, set<T>* x) {
      if(x==NULL) x = new set<T>();
      for(int i=0;i<n;i++) x->insert(arr[i]);
      return x;
   }

   template<typename T> set<T>* util_set(list<T>* val, set<T>* x) {
      if(x==NULL) x = new set<T>();
      for(typename list<T>::iterator it=val->begin();it!=val->end();it++) x->insert(*it);
      return x;
   }

   template<typename T> list<T>* util_list(set<T>* val, list<T>* x) {
      if(x==NULL) x = new list<T>();
      for(typename set<T>::iterator it=val->begin();it!=val->end();it++) x->push_back(*it);
      return x;
   }

   template<typename T> void util_ofscan(string fname, string oname, T& val) {util_fscan(util_ofname(fname,oname),val);}
   template<typename T> void util_ofscan(string fname, string oname, T*& val, int& n) {util_fscan(util_ofname(fname,oname),val,n);}
   template<typename T> void util_ofscan(string fname, string oname, T**& val, int& m, int& n) {util_fscan(util_ofname(fname,oname),val,m,n);}
   template<typename T> void util_ofscan(string fname, string oname, list<T>*& val) {util_fscan(util_ofname(fname,oname),val);}
   template<typename T> void util_ofscan(string fname, string oname, set<T>*& val) {util_fscan(util_ofname(fname,oname),val);}
   template<typename T1, typename T2> void util_ofscan(string fname, string oname, unordered_map<T1,T2>*& val) {util_fscan(util_ofname(fname,oname),val);}
   template<typename T1, typename T2> void util_ofscan(string fname, string oname, unordered_map<T1,T2>**& val, int& num) {util_fscan(util_ofname(fname,oname),val,num);}

   template<typename T> T* util_sub(const T* arr, const int n, const int* cmap, const int m) {
      if(arr==NULL) return NULL;
      if(cmap==NULL) err_msg("cmap==NULL",__FUNCTION__);
      T* x = new T[m];
      for(int i=0;i<m;i++) x[i] = arr[ cmap[i] ];
      return x;
   }

   template<typename T> unordered_map<int,T>* util_sub(const unordered_map<int,T>* rmap, 
                                                       const set<int>* rS)
   {
      if(rmap==NULL) return NULL;
      unordered_map<int,T>* sub_rmap = NULL;
      typename unordered_map<int,T>::const_iterator it;
      sub_rmap = new unordered_map<int,T>();
      for(it=rmap->begin();it!=rmap->end();it++) {
         if(rS->find(it->first)==rS->end()) continue;
         (*sub_rmap)[it->first] = it->second;
      }
      return sub_rmap;
   }

   template<typename T> unordered_map<T,int>* util_sub(const unordered_map<T,int>* rmap, 
                                                       const int* cmap, const int m)
   {
      if(rmap==NULL) return NULL;
      if(cmap==NULL) err_msg("cmap==NULL",__FUNCTION__);

      unordered_map<T,int>* x = new unordered_map<T,int>();
      unordered_map<int,int>* cimap = util_imap(cmap,m);
      typename unordered_map<T,int>::const_iterator it1;
      typename unordered_map<int,int>::iterator it2;

      for(it1=rmap->begin();it1!=rmap->end();it1++) {
         const int i = it1->second;
         it2 = cimap->find(i);
         if(it2==cimap->end()) continue;
         (*x)[it1->first] = it2->second;
      }

      //clean memory
      delete cimap;

      return x;
   }

   template<typename T1, typename T2> 
      unordered_map<T2,T1>* util_imap(unordered_map<T1,T2>* rmap) {
         if(rmap==NULL) return NULL;
         unordered_map<T2,T1>* rimap = NULL;
         rimap = new unordered_map<T2,T1>();
         typename unordered_map<T1,T2>::iterator it;
         for(it=rmap->begin();it!=rmap->end();it++) (*rimap)[it->second] = it->first;
         return rimap;
      }

   template<typename T1, typename T2> 
      void util_map_imap(unordered_map<T1,T2>*& rmap,
                         unordered_map<T2,T1>*& rimap)
      {
         if(rmap==NULL && rimap==NULL) return ;
         else if(rmap==NULL) rmap = util_imap(rimap);
         else if(rimap==NULL) rimap = util_imap(rmap);
      }

   template<typename T1, typename T2> 
      void util_fprint(string fname, unordered_map<T1,T2>** val, const int num) {
         if(val==NULL) {util_fprint_NULL(fname); return;}
         util_fprint(util_ofname(fname,"size"),num);
         for(int i=0;i<num;i++) {
            util_fprint(util_ofname(fname,i),val[i]); 
         }
         return;
      }

   template<typename T1, typename T2> unordered_map<T1,T2>** util_copy(
      unordered_map<T1,T2>** val, const int T) 
   {
      if(val==NULL) return NULL;
      unordered_map<T1,T2>** x = NULL;
      x = new unordered_map<T1,T2>*[T];
      for(int t=0;t<T;t++) x[t] = util_copy(val[t]);
      return x;
   }

   template<typename T1>
   list<string>* util_genL(list<string>* L, T1 x1) {
      list<string>* ptr = L;
      if(ptr==NULL) ptr = new list<string>();
      ptr->push_back(util_string(x1));
      return ptr;
   }

   template<typename T1, typename T2>
   list<string>* util_genL(list<string>* L, T1 x1, T2 x2) {
      list<string>* ptr = util_genL(L,x1);
      ptr->push_back(util_string(x2));
      return ptr;
   }

   template<typename T1, typename T2, typename T3>
   list<string>* util_genL(list<string>* L, T1 x1, T2 x2, T3 x3) {
      list<string>* ptr = util_genL(L,x1,x2);
      ptr->push_back(util_string(x3));
      return ptr;
   }

   template<typename T1, typename T2, typename T3, typename T4>
   list<string>* util_genL(list<string>* L, T1 x1, T2 x2, T3 x3, T4 x4) {
      list<string>* ptr = util_genL(L,x1,x2,x3);
      ptr->push_back(util_string(x4));
      return ptr;
   }

   template<typename T1, typename T2, typename T3, typename T4, typename T5>
   list<string>* util_genL(list<string>* L, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5) {
      list<string>* ptr = util_genL(L,x1,x2,x3,x4);
      ptr->push_back(util_string(x5));
      return ptr;
   }

   template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
   list<string>* util_genL(list<string>* L, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6) {
      list<string>* ptr = util_genL(L,x1,x2,x3,x4,x5);
      ptr->push_back(util_string(x6));
      return ptr;
   }

   template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
   list<string>* util_genL(list<string>* L, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6, T7 x7) {
      list<string>* ptr = util_genL(L,x1,x2,x3,x4,x5,x6);
      ptr->push_back(util_string(x7));
      return ptr;
   }



   template<typename T> set<T>* util_intersect(set<T>* S1, set<T>* S2) {
      set<T>* S = NULL;
      if(S1==NULL || S2==NULL) return S = new set<T>();
      if(S1->size() > S2->size()) return util_intersect(S2,S1);
      S = new set<T>();
      for(typename set<T>::iterator it=S1->begin();it!=S1->end();it++) {
         if(S2->find(*it)==S2->end()) continue;
         S->insert(*it);
      }
      return S;
   }

   template<typename T> set<T>* util_union(set<T>* S1, set<T>* S2) {
      set<T>* S = NULL;
      if(S1==NULL && S2==NULL) return S = new set<T>();
      if(S1==NULL) return util_copy(S2);
      if(S2==NULL) return util_copy(S1);
      S = new set<T>();
      for(typename set<T>::iterator it=S1->begin();it!=S1->end();it++) S->insert(*it);
      for(typename set<T>::iterator it=S2->begin();it!=S2->end();it++) S->insert(*it);
      return S;
   }

   template<typename T1>
   string util_join(string L, T1 x1) {
      list<string>* LL = util_genL((list<string>*)(NULL),x1);
      string s = util_joinL(L,LL);
      delete LL;
      return s;
   }

   template<typename T1, typename T2>
   string util_join(string L, T1 x1, T2 x2) {
      list<string>* LL = util_genL((list<string>*)(NULL),x1,x2);
      string s = util_joinL(L,LL);
      delete LL;
      return s;
   }

   template<typename T1, typename T2, typename T3>
   string util_join(string L, T1 x1, T2 x2, T3 x3) {
      list<string>* LL = util_genL((list<string>*)(NULL),x1,x2,x3);
      string s = util_joinL(L,LL);
      delete LL;
      return s;
   }

   template<typename T1, typename T2, typename T3, typename T4>
   string util_join(string L, T1 x1, T2 x2, T3 x3, T4 x4) {
      list<string>* LL = util_genL((list<string>*)(NULL),x1,x2,x3,x4);
      string s = util_joinL(L,LL);
      delete LL;
      return s;
   }

   template<typename T1, typename T2, typename T3, typename T4, typename T5>
   string util_join(string L, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5) {
      list<string>* LL = util_genL((list<string>*)(NULL),x1,x2,x3,x4,x5);
      string s = util_joinL(L,LL);
      delete LL;
      return s;
   }

   template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
   string util_join(string L, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6) {
      list<string>* LL = util_genL((list<string>*)(NULL),x1,x2,x3,x4,x5,x6);
      string s = util_joinL(L,LL);
      delete LL;
      return s;
   }

   template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
   string util_join(string L, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6, T7 x7) {
      list<string>* LL = util_genL((list<string>*)(NULL),x1,x2,x3,x4,x5,x6,x7);
      string s = util_joinL(L,LL);
      delete LL;
      return s;
   }

   template<typename T1>
   string util_join2(string L, T1 x1) {
      list<string>* LL = util_genL((list<string>*)(NULL),x1);
      string s = util_joinL(L,LL);
      delete LL;
      return string("(") + s + ")";
   }

   template<typename T1, typename T2>
   string util_join2(string L, T1 x1, T2 x2) {
      list<string>* LL = util_genL((list<string>*)(NULL),x1,x2);
      string s = util_joinL(L,LL);
      delete LL;
      return string("(") + s + ")";
   }

   template<typename T1, typename T2, typename T3>
   string util_join2(string L, T1 x1, T2 x2, T3 x3) {
      list<string>* LL = util_genL((list<string>*)(NULL),x1,x2,x3);
      string s = util_joinL(L,LL);
      delete LL;
      return string("(") + s + ")";
   }

   template<typename T1, typename T2, typename T3, typename T4>
   string util_join2(string L, T1 x1, T2 x2, T3 x3, T4 x4) {
      list<string>* LL = util_genL((list<string>*)(NULL),x1,x2,x3,x4);
      string s = util_joinL(L,LL);
      delete LL;
      return string("(") + s + ")";
   }

   template<typename T1, typename T2, typename T3, typename T4, typename T5>
   string util_join2(string L, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5) {
      list<string>* LL = util_genL((list<string>*)(NULL),x1,x2,x3,x4,x5);
      string s = util_joinL(L,LL);
      delete LL;
      return string("(") + s + ")";
   }

   template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
   string util_join2(string L, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6) {
      list<string>* LL = util_genL((list<string>*)(NULL),x1,x2,x3,x4,x5,x6);
      string s = util_joinL(L,LL);
      delete LL;
      return string("(") + s + ")";
   }

   template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
   string util_join2(string L, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6, T7 x7) {
      list<string>* LL = util_genL((list<string>*)(NULL),x1,x2,x3,x4,x5,x6,x7);
      string s = util_joinL(L,LL);
      delete LL;
      return string("(") + s + ")";
   }

   template<typename T1,typename T2> 
      set<T1>* util_keys(unordered_map<T1,T2>* m, set<T1>* S) {
         if(m==NULL) return NULL;
         if(S==NULL) S = new set<T1>();
         typename unordered_map<T1,T2>::iterator it;
         for(it=m->begin();it!=m->end();it++) S->insert(it->first);
         return S;
      }

   template<typename T1,typename T2> 
      list<T1>* util_keys(unordered_map<T1,T2>* m, list<T1>* S) {
         set<T1> tmpS;
         util_keys(m, &tmpS);
         util_list(&tmpS,S);
         return S;
      }

   template<typename T> T* util_array(set<T>* val) {
      if(val==NULL) return NULL;
      T* a = new T[val->size()];
      typename set<T>::iterator it;
      int i;
      for(i=0, it=val->begin();it!=val->end();it++) a[i++] = *it;
      return a;
   }

   template<typename T> T* util_array(list<T>* val) {
      if(val==NULL) return NULL;
      T* a = new T[val->size()];
      typename list<T>::iterator it;
      int i;
      for(i=0, it=val->begin();it!=val->end();it++) a[i++] = *it;
      return a;
   }

   template<typename T1,typename T2> void util_clean(list<unordered_map<T1,T2>*>* L) {
      if(L==NULL) return;
      typename list<unordered_map<T1,T2>*>::iterator it;
      for(it=L->begin();it!=L->end();it++) delete *it;
      delete L;
      return;
   }

   template<typename T1,typename T2> void util_closest_le(map<T1,T2>* m, T1 x, 
                                                          typename map<T1,T2>::iterator& it)
   {
      if(m->size()==0) it = m->end();
      else {
         T1 minval, maxval;

         minval = m->begin()->first;
         maxval = m->rbegin()->first;
         if(x<minval) {it=m->end(); return;}
         if(x==minval) {it=m->begin(); return;}
         if(x>=maxval) {it=m->end(); it--; return;}

         it = m->lower_bound(x);
         if(it==m->end() || it->first > x) it--;
      }
      return;
   }

   template<typename T1,typename T2> void util_closest_le(map<T1,set<T2>*>* m, T1 x, 
                                                          typename map<T1,set<T2>*>::iterator& it)
   {
      if(m->size()==0) it = m->end();
      else {
         T1 minval, maxval;

         minval = m->begin()->first;
         maxval = m->rbegin()->first;
         if(x<minval) {it=m->end(); return;}
         if(x==minval) {it=m->begin(); return;}
         if(x>=maxval) {it=m->end(); it--; return;}

         it = m->lower_bound(x);
         if(it==m->end() || it->first > x) it--;
      }
      return;
   }

   template<typename T> void util_closest_le(set<T>* S, T x, 
                                             typename set<T>::iterator& it)
   {
      if(S->size()==0) it = S->end();
      else {
         T minval, maxval;

         minval = *(S->begin());
         maxval = *(S->rbegin());
         if(x<minval) {it=S->end(); return;}
         if(x==minval) {it=S->begin(); return;}
         if(x>=maxval) {it=S->end(); it--; return;}

         it = S->lower_bound(x);
         if(it==S->end() || *it > x) it--;
      }
      return;
   }


};

#endif

