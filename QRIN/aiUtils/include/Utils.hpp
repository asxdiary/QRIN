// Name:     Utils.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_Utils_hpp
#define ASX_Utils_hpp

#include <string>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Object.hpp"
#include "Global.hpp"

using namespace std;
using namespace aiUtils;

namespace aiUtils {

   /** Global Class Support */
   const string Utils_Global_src = "/app/home/asx/QRIN/aiUtils/notes/Global";

   /** Design Pattern Support */
   Object* util_singleton(string cname, string id, Object* ptr=NULL);

   /** Error Handling Functions */

   void err_msg(string msg);
   void err_msg(string s1, string s2);
   void err_msg(string s1, string s2, string s3);
   void err_msg(string s1, string s2, string s3, string s4);
   void err_msg(string s1, string s2, string s3, string s4, string s5);
   void err_msg(string s1, string s2, string s3, string s4, string s5, string s6);

   void warn_msg(string msg);
   void warn_msg(string s1, string s2);
   void warn_msg(string s1, string s2, string s3);
   void warn_msg(string s1, string s2, string s3, string s4);
   void warn_msg(string s1, string s2, string s3, string s4, string s5);
   void warn_msg(string s1, string s2, string s3, string s4, string s5, string s6);

   void breakpoint(int x);
   void breakpoint(double x);

   /** Debugging support functions */
   void util_set_debug_id(Object* obj, string id, string oname="");
   void util_set_debug_info(Object* obj, bool debug_mode, string debug_pfx, string oname="");

   /** Primitive data elements handling functions */

   void util_convert(string x, bool& y);
   void util_convert(string x, int& y);
   void util_convert(string x, double& y);
   void util_convert(string x, string& y);

   bool util_isEqual(bool x1, bool x2);
   bool util_isEqual(int x1, int x2);
   bool util_isEqual(double x1, double x2, const double eps=Global::instance()->eps());
   bool util_isEqual(string x1, string x2);
   bool util_isZero(double x);

   string* util_names(const string pfx, const int n);
   int* util_rangeA(const int a, const int b);
   list<int>* util_rangeL(const int a, const int b);
   set<int>* util_rangeS(const int a, const int b);
   unordered_map<int,int>* util_identity_map(const int a, const int b);

   /** This function moves around k to be in [0,n-1] */
   int util_arrind(const int k, const int n);

   void util_clean_obj(Object**& X, const int m);
   void util_clean_obj(Object***& X, const int m, const int n);
   void util_clean_obj(list<Object*>* L);
   template<typename T> T** util_matrix(const int m, const int n, const T val);
   template<typename T> void util_clean(T*& X, const int m);
   template<typename T> void util_clean(T**& X, const int m, const int n);
   template<typename T1,typename T2> void util_clean(list<unordered_map<T1,T2>*>* L);
   template<typename T> T** util_transpose(T** x, const int m, const int n);

   /** STL container handling functions */
   string util_joinL(string sep, list<string>* L, string s="");

   string util_string (string val);
   string util_string (int val);
   string util_string (long val);
   string util_string (long long val);
   string util_string (unsigned val);
   string util_string (unsigned long val);
   string util_string (unsigned long long val);
   string util_string (float val);
   string util_string (double val);
   string util_string (long double val);
   string util_string_bool (bool val);

   template<typename T> set<T>* util_intersect(set<T>* S1, set<T>* S2);
   template<typename T> set<T>* util_union(set<T>* S1, set<T>* S2);

   template<typename T1>
   list<string>* util_genL(list<string>* L, T1 x1);
   template<typename T1, typename T2>
   list<string>* util_genL(list<string>* L, T1 x1, T2 x2);
   template<typename T1, typename T2, typename T3>
   list<string>* util_genL(list<string>* L, T1 x1, T2 x2, T3 x3);
   template<typename T1, typename T2, typename T3, typename T4>
   list<string>* util_genL(list<string>* L, T1 x1, T2 x2, T3 x3, T4 x4);
   template<typename T1, typename T2, typename T3, typename T4, typename T5>
   list<string>* util_genL(list<string>* L, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5);
   template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
   list<string>* util_genL(list<string>* L, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6);
   template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
   list<string>* util_genL(list<string>* L, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6, T7 x7);

   template<typename T1>
   string util_join(string L, T1 x1);
   template<typename T1, typename T2>
   string util_join(string L, T1 x1, T2 x2);
   template<typename T1, typename T2, typename T3>
   string util_join(string L, T1 x1, T2 x2, T3 x3);
   template<typename T1, typename T2, typename T3, typename T4>
   string util_join(string L, T1 x1, T2 x2, T3 x3, T4 x4);
   template<typename T1, typename T2, typename T3, typename T4, typename T5>
   string util_join(string L, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5);
   template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
   string util_join(string L, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6);
   template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
   string util_join(string L, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6, T7 x7);

   template<typename T1>
   string util_join2(string L, T1 x1);
   template<typename T1, typename T2>
   string util_join2(string L, T1 x1, T2 x2);
   template<typename T1, typename T2, typename T3>
   string util_join2(string L, T1 x1, T2 x2, T3 x3);
   template<typename T1, typename T2, typename T3, typename T4>
   string util_join2(string L, T1 x1, T2 x2, T3 x3, T4 x4);
   template<typename T1, typename T2, typename T3, typename T4, typename T5>
   string util_join2(string L, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5);
   template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
   string util_join2(string L, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6);
   template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
   string util_join2(string L, T1 x1, T2 x2, T3 x3, T4 x4, T5 x5, T6 x6, T7 x7);

   template<typename T> unordered_map<T,int>* util_imap(const T* arr, const int n);
   template<typename T> T* util_imap(const unordered_map<T,int>* rmap, int& n);
   template<typename T> void util_map_imap(T*& rmap, 
                                           unordered_map<T,int>*& rimap, 
                                           const int n);

   template<typename T1, typename T2> unordered_map<T2,T1>* util_imap(unordered_map<T1,T2>* rmap);
   template<typename T1, typename T2> void util_map_imap(unordered_map<T1,T2>*& rmap,
                                                         unordered_map<T2,T1>*& rimap);

   template<typename T> T* util_sub(const T* arr, const int n, const int* cmap, const int m);
   template<typename T> unordered_map<T,int>* util_sub(const unordered_map<T,int>* rmap, 
                                                       const int* cmap, const int m);
   template<typename T> unordered_map<int,T>* util_sub(const unordered_map<int,T>* rmap, 
                                                       const set<int>* rS);

   template<typename T> T util_copy(T val);
   template<typename T> T* util_copy(T* val, const int  n);
   template<typename T> T** util_copy(T** val, const int  m, const int  n);
   template<typename T> list<T>* util_copy(list<T>* val);
   template<typename T> set<T>* util_copy(set<T>* val);
   template<typename T1, typename T2> unordered_map<T1,T2>* util_copy(unordered_map<T1,T2>* val);
   template<typename T1, typename T2> unordered_map<T1,T2>** util_copy(unordered_map<T1,T2>** val, const int T);

   template<typename T> bool util_isEqual(T* val1, T* val2, const int  n);
   template<typename T> bool util_isEqual(T** val1, T** val2, const int  m, const int  n);
   template<typename T> bool util_isEqual(list<T>* val1, list<T>* val2);
   template<typename T> bool util_isEqual(set<T>* val1, set<T>* val2);
   template<typename T1, typename T2> bool util_isEqual(unordered_map<T1,T2>* val1, 
                                                        unordered_map<T1,T2>* val2);

   template<typename T> set<T>* util_set(list<T>* val, set<T>* S=NULL);
   template<typename T> list<T>* util_list(set<T>* val, list<T>* L=NULL);
   template<typename T> set<T>* util_set(T* arr, int n, set<T>* S=NULL);
   template<typename T> T* util_array(set<T>* val);
   template<typename T> T* util_array(list<T>* val);

   template<typename T1,typename T2> set<T1>* util_keys(unordered_map<T1,T2>* m, set<T1>* S=NULL);
   template<typename T1,typename T2> list<T1>* util_keys(unordered_map<T1,T2>* m, list<T1>* S=NULL);

   /** File I/O functions */

   string util_ofname(string fname, string oname);
   string util_ofname(string fname, int oname);
   bool util_chk(string fname); //Check if the file exists for reading
   void util_chk(ofstream& fp, string fname);
   void util_chk(ifstream& fp, string fname);
   void util_fprint_NULL(string fname);
   bool util_fscan_NULL(string fname);

   void util_ofprint_obj(string fname, string oname, Object* val);
   void util_ofprint_obj(string fname, string oname, Object** val, const int n);
   void util_ofprint_obj(string fname, string oname, Object*** val, const int m, const int n);
   void util_ofprint_obj(string fname, string oname, list<Object*>* val);
   void util_ofprint_obj(string fname, string oname, set<Object*>* val);
   template<typename T> void util_ofprint_obj(string fname, string oname, unordered_map<T,Object*>* val);

   template<typename T> void util_ofprint(string fname, string oname, T const& val);
   template<typename T> void util_ofprint(string fname, string oname, const T* val, const int n);
   template<typename T> void util_ofprint(string fname, string oname, T** val, const int m, const int n);
   template<typename T> void util_ofprint(string fname, string oname, list<T>* val);
   template<typename T> void util_ofprint(string fname, string oname, set<T>* val);
   template<typename T1, typename T2> void util_ofprint(string fname, string oname, unordered_map<T1,T2>* val);
   template<typename T1, typename T2> void util_ofprint(string fname, string oname, unordered_map<T1,T2>** val, const int num);
   template<typename T1, typename T2> void util_ofprint(string fname, string oname, unordered_map<T1,set<T2>*>* val);

   void util_fprint_obj(string fname, Object* val);
   void util_fprint_obj(string fname, Object** val, const int n);
   void util_fprint_obj(string fname, Object*** val, const int m, const int n);
   void util_fprint_obj(string fname, list<Object*>* val);
   void util_fprint_obj(string fname, set<Object*>* val);
   template<typename T> void util_fprint_obj(string fname, unordered_map<T,Object*>* val);

   template<typename T> void util_fprint(string fname, T const& val, ios_base::openmode mode=ios_base::trunc);
   template<typename T> void util_fprint(string fname, const T* val, const int n, ios_base::openmode mode=ios_base::trunc);
   template<typename T> void util_fprint(string fname, T** val, const int m, const int n, ios_base::openmode mode=ios_base::trunc);
   template<typename T> void util_fprint(string fname, list<T>* val, ios_base::openmode mode=ios_base::trunc);
   template<typename T> void util_fprint(string fname, set<T>* val, ios_base::openmode mode=ios_base::trunc);
   template<typename T1, typename T2> void util_fprint(string fname, unordered_map<T1,T2>* val, ios_base::openmode mode=ios_base::trunc);
   template<typename T1, typename T2> void util_fprint(string fname, unordered_map<T1,T2>** val, const int num);
   template<typename T1, typename T2> void util_fprint(string fname, unordered_map<T1,set<T2>*>* val, ios_base::openmode mode=ios_base::trunc);

   template<typename T> void util_ofscan(string fname, string oname, T& val);
   template<typename T> void util_ofscan(string fname, string oname, T*& val, int& n);
   template<typename T> void util_ofscan(string fname, string oname, T**& val, int& m, int& n);
   template<typename T> void util_ofscan(string fname, string oname, list<T>*& val);
   template<typename T> void util_ofscan(string fname, string oname, set<T>*& val);
   template<typename T1, typename T2> void util_ofscan(string fname, string oname, unordered_map<T1,T2>*& val);
   template<typename T1, typename T2> void util_ofscan(string fname, string oname, unordered_map<T1,T2>**& val, int& num);

   template<typename T> void util_fscan(string fname, T& val);
   template<typename T> void util_fscan(string fname, T*& val, int& n);
   template<typename T> void util_fscan(string fname, T**& val, int& m, int& n, 
                                        string delimiter=Global::instance()->delimiter(), 
                                        int firstLineIsHeader=0, string** headerp=NULL, 
                                        int firstColIsPrimary=0, string** rmapp=NULL);
   template<typename T> void util_fscan(string fname, list<T>*& val);
   template<typename T> void util_fscan(string fname, set<T>*& val);
   template<typename T1, typename T2> void util_fscan(string fname, unordered_map<T1,T2>*& val);
   template<typename T1, typename T2> void util_fscan(string fname, unordered_map<T1,T2>**& val, int& num);

   /** it is set to an element of m that satisfies it->first <= x;
    * if there is a tie, it is broken by considering the element closest to x
    * if there is no such element, it is set to m->end() */
   template<typename T1, typename T2> void util_closest_le(map<T1,T2>* m, T1 x, 
                                                           typename map<T1,T2>::iterator& it);
   template<typename T1, typename T2> void util_closest_le(map<T1,set<T2>*>* m, T1 x, 
                                                           typename map<T1,set<T2>*>::iterator& it);
   template<typename T> void util_closest_le(set<T>* S, T x, 
                                             typename set<T>::iterator& it);

   void util_fprint(string fname,list<unordered_map<string,string>*>* L, set<string>* headerS=NULL);

   /** System related utilities */
   int util_system(string arg1);
   int util_system(string arg1, string arg2);
   int util_system(string arg1, string arg2, string arg3);
   int util_system(string arg1, string arg2, string arg3, string arg4);
   int util_system(string arg1, string arg2, string arg3, string arg4, string arg5);
   int util_system(string arg1, string arg2, string arg3, string arg4, string arg5, string arg6);

   int util_system2(string arg1);
   int util_system2(string arg1, string arg2);
   int util_system2(string arg1, string arg2, string arg3);
   int util_system2(string arg1, string arg2, string arg3, string arg4);
   int util_system2(string arg1, string arg2, string arg3, string arg4, string arg5);
   int util_system2(string arg1, string arg2, string arg3, string arg4, string arg5, string arg6);

   int util_mkdir(string dir);

};

#endif

