#ifndef ASX_UtilsUnitTest_TestUtils
#define ASX_UtilsUnitTest_TestUtils

#include <typeinfo>
#include <map>
#include <unordered_map>
#include <math.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "TestUtils.hpp"

using namespace aiUtils;

int TestUtils_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   string ipfx = "input/TestUtils.";
   string opfx = "output/TestUtils.";

   //err_msg("Just testing");

   //File Handling Functions (printing)
   {
      string fname = "output/TestUtils_util_fprint.txt";
      string ofname = string(fname).append("_obj");

      util_fprint(fname,"\nutil_fprint<bool>\n"); util_fprint(fname,1==1);
      util_fprint(fname,"\nutil_fprint<int>\n"); util_fprint(fname,1); 
      util_fprint(fname,"\nutil_fprint<double>\n"); util_fprint(fname,1.25); 
      util_fprint(fname,"\nutil_fprint<string>\n"); util_fprint(fname, string("testing 123")); 

      util_fprint(ofname,"\nutil_fprint<bool>\n"); util_ofprint(fname,"obj",1==1);
      util_fprint(ofname,"\nutil_fprint<int>\n"); util_ofprint(fname,"obj",1); 
      util_fprint(ofname,"\nutil_fprint<double>\n"); util_ofprint(fname,"obj",1.25); 
      util_fprint(ofname,"\nutil_fprint<string>\n"); util_ofprint(fname,"obj", string("testing 123")); 

      {
         const int n = 5;
         bool* bool_arr = new bool[n];
         int* int_arr = new int[n];
         double* double_arr = new double[n];
         string* string_arr = new string[n];

         list<bool> bool_list;
         list<int> int_list;
         list<double> double_list;
         list<string> string_list;

         set<bool> bool_set;
         set<int> int_set;
         set<double> double_set;
         set<string> string_set;

         unordered_map<string,double> map_string_double;

         for(int i=0;i<n;i++) bool_arr[i] = (i==2);
         for(int i=0;i<n;i++) int_arr[i] = 10-i;
         for(int i=0;i<n;i++) double_arr[i] = 10.5+i;
         for(int i=0;i<n;i++) {
            char val[100];
            sprintf(val,"a%d",i+1);
            string_arr[i].append(string(val));
         }

         for(int i=0;i<n;i++) bool_list.push_back(bool_arr[i]);
         for(int i=0;i<n;i++) int_list.push_back(int_arr[i]);
         for(int i=0;i<n;i++) double_list.push_back(double_arr[i]);
         for(int i=0;i<n;i++) string_list.push_back(string_arr[i]);

         for(int i=0;i<n;i++) bool_set.insert(bool_arr[i]);
         for(int i=0;i<n;i++) int_set.insert(int_arr[i]);
         for(int i=0;i<n;i++) double_set.insert(double_arr[i]);
         for(int i=0;i<n;i++) string_set.insert(string_arr[i]);

         for(int i=0;i<n;i++) {
            map_string_double[string_arr[i]] = double_arr[i];
         }

         //test the copy functions
         {
            bool* bool_arr_copy = util_copy(bool_arr, n);
            int* int_arr_copy = util_copy(int_arr, n);
            double* double_arr_copy = util_copy(double_arr, n);
            string* string_arr_copy = util_copy(string_arr, n);

            list<bool>* bool_list_copy = util_copy(&bool_list);
            list<int>* int_list_copy = util_copy(&int_list);
            list<double>* double_list_copy = util_copy(&double_list);
            list<string>* string_list_copy = util_copy(&string_list);

            set<bool>* bool_set_copy = util_copy(&bool_set);
            set<int>* int_set_copy = util_copy(&int_set);
            set<double>* double_set_copy = util_copy(&double_set);
            set<string>* string_set_copy = util_copy(&string_set);

            if(! util_isEqual(bool_arr_copy, bool_arr, n)) val++;
            if(! util_isEqual(int_arr_copy, int_arr, n)) val++;
            if(! util_isEqual(double_arr_copy, double_arr, n)) val++;
            if(! util_isEqual(string_arr_copy, string_arr, n)) val++;

            if(! util_isEqual(bool_list_copy, &bool_list)) val++;
            if(! util_isEqual(int_list_copy, &int_list)) val++;
            if(! util_isEqual(double_list_copy, &double_list)) val++;
            if(! util_isEqual(string_list_copy, &string_list)) val++;

            if(! util_isEqual(bool_set_copy, &bool_set)) val++;
            if(! util_isEqual(int_set_copy, &int_set)) val++;
            if(! util_isEqual(double_set_copy, &double_set)) val++;
            if(! util_isEqual(string_set_copy, &string_set)) val++;

            //clean memory
            delete [] bool_arr_copy;
            delete [] int_arr_copy;
            delete [] double_arr_copy;
            delete [] string_arr_copy;

            delete bool_list_copy;
            delete int_list_copy;
            delete double_list_copy;
            delete string_list_copy;

            delete bool_set_copy;
            delete int_set_copy;
            delete double_set_copy;
            delete string_set_copy;
         }

         util_fprint(fname,"\nutil_fprint<bool*>\n"); util_fprint(fname,bool_arr,n); 
         util_fprint(fname,"\nutil_fprint<int*>\n"); util_fprint(fname,int_arr,n); 
         util_fprint(fname,"\nutil_fprint<double*>\n"); util_fprint(fname,double_arr,n); 
         util_fprint(fname,"\nutil_fprint<string*>\n"); util_fprint(fname,string_arr,n); 

         util_fprint(fname,"\nutil_fprint<bool_list>\n"); util_fprint(fname,&bool_list); 
         util_fprint(fname,"\nutil_fprint<int_list>\n"); util_fprint(fname,&int_list); 
         util_fprint(fname,"\nutil_fprint<double_list>\n"); util_fprint(fname,&double_list); 
         util_fprint(fname,"\nutil_fprint<string_list>\n"); util_fprint(fname,&string_list); 

         util_fprint(ofname,"\nutil_fprint<bool*>\n"); util_ofprint(fname,"obj",bool_arr,n); 
         util_fprint(ofname,"\nutil_fprint<int*>\n"); util_ofprint(fname,"obj",int_arr,n); 
         util_fprint(ofname,"\nutil_fprint<double*>\n"); util_ofprint(fname,"obj",double_arr,n); 
         util_fprint(ofname,"\nutil_fprint<string*>\n"); util_ofprint(fname,"obj",string_arr,n); 

         util_fprint(ofname,"\nutil_fprint<bool_list>\n"); util_ofprint(fname,"obj",&bool_list); 
         util_fprint(ofname,"\nutil_fprint<int_list>\n"); util_ofprint(fname,"obj",&int_list); 
         util_fprint(ofname,"\nutil_fprint<double_list>\n"); util_ofprint(fname,"obj",&double_list); 
         util_fprint(ofname,"\nutil_fprint<string_list>\n"); util_ofprint(fname,"obj",&string_list); 

         util_fprint(fname,"\nutil_fprint<string_double_map>\n"); 
         util_fprint(fname,&map_string_double); 
         util_fprint(ofname,"\nutil_fprint<string_double_map>\n"); 
         util_ofprint(fname,"obj",&map_string_double); 

         util_fprint(fname,(unordered_map<string,double>*)NULL);
         util_ofprint(ofname,"obj",(unordered_map<string,double>*)NULL);

         {
            string fname;
            int n1,i;

            bool* bool_arr1 = NULL;
            int* int_arr1 = NULL;
            double* double_arr1 = NULL;
            string* string_arr1 = NULL;

            fname = "input/TestUtils_util_fscan_bool_arr.txt"; util_fscan(fname,bool_arr1,n1);
            if(n1!=n) val++;
            else {
               for(i=0;(i<n) && (bool_arr1[i]==bool_arr[i]);i++);
               if(i<n-1) val++;
            }

            fname = "input/TestUtils_util_fscan_int_arr.txt"; util_fscan(fname,int_arr1,n1);
            if(n1!=n) val++;
            else {
               for(i=0;(i<n) && (int_arr1[i]==int_arr[i]);i++);
               if(i<n-1) val++;
            }

            fname = "input/TestUtils_util_fscan_double_arr.txt"; util_fscan(fname,double_arr1,n1);
            if(n1!=n) val++;
            else {
               for(i=0;(i<n) && (double_arr1[i]==double_arr[i]);i++);
               if(i<n-1) val++;
            }

            fname = "input/TestUtils_util_fscan_string_arr.txt"; util_fscan(fname,string_arr1,n1);
            if(n1!=n) val++;
            else {
               for(i=0;(i<n) && (string_arr1[i]==string_arr[i]);i++);
               if(i<n-1) val++;
            }

            //clean memory
            delete [] bool_arr1;
            delete [] int_arr1;
            delete [] double_arr1;
            delete [] string_arr1;
         }

         {
            string fname;
            list<bool>* bool_list_ptr=NULL;
            list<int>* int_list_ptr=NULL;
            list<double>* double_list_ptr=NULL;
            list<string>* string_list_ptr=NULL;

            fname = "input/TestUtils_util_fscan_bool_list.txt"; util_fscan(fname,bool_list_ptr);
            fname = "input/TestUtils_util_fscan_int_list.txt"; util_fscan(fname,int_list_ptr);
            fname = "input/TestUtils_util_fscan_double_list.txt"; util_fscan(fname,double_list_ptr);
            fname = "input/TestUtils_util_fscan_string_list.txt"; util_fscan(fname,string_list_ptr);

            //clean memory
            delete bool_list_ptr;
            delete int_list_ptr;
            delete double_list_ptr;
            delete string_list_ptr;
         }

         {
            string fname;
            set<bool>* bool_set_ptr=NULL;
            set<int>* int_set_ptr=NULL;
            set<double>* double_set_ptr=NULL;
            set<string>* string_set_ptr=NULL;

            fname = "input/TestUtils_util_fscan_bool_set.txt"; util_fscan(fname,bool_set_ptr);
            fname = "input/TestUtils_util_fscan_int_set.txt"; util_fscan(fname,int_set_ptr);
            fname = "input/TestUtils_util_fscan_double_set.txt"; util_fscan(fname,double_set_ptr);
            fname = "input/TestUtils_util_fscan_string_set.txt"; util_fscan(fname,string_set_ptr);

            //clean memory
            delete bool_set_ptr;
            delete int_set_ptr;
            delete double_set_ptr;
            delete string_set_ptr;
         }

         {
            string fname;
            int n1,i;

            bool* bool_arr1 = NULL;
            int* int_arr1 = NULL;
            double* double_arr1 = NULL;
            string* string_arr1 = NULL;

            fname = "input/TestUtils_util_fscan_bool_arr.txt"; util_ofscan(fname,"obj",bool_arr1,n1);
            if(n1!=n) val++;
            else {
               for(i=0;(i<n) && (bool_arr1[i]==bool_arr[i]);i++);
               if(i<n-1) val++;
            }

            fname = "input/TestUtils_util_fscan_int_arr.txt"; util_ofscan(fname,"obj",int_arr1,n1);
            if(n1!=n) val++;
            else {
               for(i=0;(i<n) && (int_arr1[i]==int_arr[i]);i++);
               if(i<n-1) val++;
            }

            fname = "input/TestUtils_util_fscan_double_arr.txt"; util_ofscan(fname,"obj",double_arr1,n1);
            if(n1!=n) val++;
            else {
               for(i=0;(i<n) && (double_arr1[i]==double_arr[i]);i++);
               if(i<n-1) val++;
            }

            fname = "input/TestUtils_util_fscan_string_arr.txt"; util_ofscan(fname,"obj",string_arr1,n1);
            if(n1!=n) val++;
            else {
               for(i=0;(i<n) && (string_arr1[i]==string_arr[i]);i++);
               if(i<n-1) val++;
            }

            //clean memory
            delete [] bool_arr1;
            delete [] int_arr1;
            delete [] double_arr1;
            delete [] string_arr1;
         }

         {
            string fname;
            list<bool>* bool_list_ptr=NULL;
            list<int>* int_list_ptr=NULL;
            list<double>* double_list_ptr=NULL;
            list<string>* string_list_ptr=NULL;

            fname = "input/TestUtils_util_fscan_bool_list.txt"; util_ofscan(fname,"obj",bool_list_ptr);
            fname = "input/TestUtils_util_fscan_int_list.txt"; util_ofscan(fname,"obj",int_list_ptr);
            fname = "input/TestUtils_util_fscan_double_list.txt"; util_ofscan(fname,"obj",double_list_ptr);
            fname = "input/TestUtils_util_fscan_string_list.txt"; util_ofscan(fname,"obj",string_list_ptr);

            //clean memory
            delete bool_list_ptr;
            delete int_list_ptr;
            delete double_list_ptr;
            delete string_list_ptr;
         }

         {
            string fname;
            set<bool>* bool_set_ptr=NULL;
            set<int>* int_set_ptr=NULL;
            set<double>* double_set_ptr=NULL;
            set<string>* string_set_ptr=NULL;

            fname = "input/TestUtils_util_fscan_bool_set.txt"; util_ofscan(fname,"obj",bool_set_ptr);
            fname = "input/TestUtils_util_fscan_int_set.txt"; util_ofscan(fname,"obj",int_set_ptr);
            fname = "input/TestUtils_util_fscan_double_set.txt"; util_ofscan(fname,"obj",double_set_ptr);
            fname = "input/TestUtils_util_fscan_string_set.txt"; util_ofscan(fname,"obj",string_set_ptr);

            //clean memory
            delete bool_set_ptr;
            delete int_set_ptr;
            delete double_set_ptr;
            delete string_set_ptr;
         }

         //clean memory
         delete [] bool_arr;
         delete [] int_arr;
         delete [] double_arr;
         delete [] string_arr;
      }


      //File Handling Functions (reading)
      {
         int xint;
         double xdouble;
         string xstring;
         string fname;

         fname = "input/TestUtils_util_fscan_int.txt"; util_fscan(fname,xint);
         if(xint!=12) val++;

         fname = "input/TestUtils_util_fscan_double.txt"; util_fscan(fname,xdouble);
         if(xdouble!=12.2) val++;

         fname = "input/TestUtils_util_fscan_string.txt"; util_fscan(fname,xstring);
         if(xstring!="a12a133") val++;
      }

      //Test map reading functions
      {
         string fname;
         unordered_map<string,double>* m = NULL;

         fname = "input/TestUtils_util_fscan_string_double_map.txt";
         util_fscan(fname,m);

         //clean memory
         delete m;
      }

      {
         int xint;
         double xdouble;
         string xstring;
         string fname;

         fname = "input/TestUtils_util_fscan_int.txt"; util_ofscan(fname,"obj",xint);
         if(xint!=12) val++;

         fname = "input/TestUtils_util_fscan_double.txt"; util_ofscan(fname,"obj",xdouble);
         if(xdouble!=12.2) val++;

         fname = "input/TestUtils_util_fscan_string.txt"; util_ofscan(fname,"obj",xstring);
         if(xstring!="a12a133") val++;
      }

      //Test map reading functions
      {
         string fname;
         unordered_map<string,double>* m = NULL;

         fname = "input/TestUtils_util_fscan_string_double_map.txt";
         util_ofscan(fname,"obj",m);

         //clean memory
         delete m;
      }



      {
         double** X = NULL;
         double** XT = NULL;
         double** XTT = NULL;
         const int m = 3;
         const int n = 4;
         double xval = 1.2;

         X = util_matrix(m,n,xval);
         for(int j=0;j<n;j++) X[1][j] = j*j + 1.23;
         XT = util_transpose(X,m,n);
         XTT = util_transpose(XT,n,m);

         if(!util_isEqual(X,XTT,m,n)) val++;

         util_fprint(fname,"\nutil_fprint<double**>\n");
         util_fprint(fname,X,m,n);
         util_fprint(ofname,"\nutil_fprint<double**>\n");
         util_ofprint(fname,"obj",X,m,n);

         //clean memory
         util_clean(X,m,n);
         util_clean(XT,n,m);
         util_clean(XTT,m,n);
         if(X!=NULL) val++;
      }
   }

   /** STL container handling functions */
   {
      {
         const int m = 5;
         int mm;
         string* x = NULL;
         string* z = NULL;
         unordered_map<string,int>* y = NULL;
         unordered_map<string,int>* yy = NULL;

         x = new string[m];
         for(int i=0;i<m;i++) x[i] = string("row").append(to_string(i));
         y = util_imap(x,m);

         (*y)["row2"] = 6;
         z = util_imap(y, mm);

         util_map_imap(z,yy,-1);

         //clean memory
         delete [] x;
         delete [] z;
         delete y;
         delete yy;
      }

      {
         const int n = 5;
         string* x = util_names("asx",n);
         delete [] x;
      }

   }

   //Test util_sub
   {
      const int n = 10;
      const int m = 4;
      int mm;
      string* cmap = NULL;
      unordered_map<string,int>* cimap = NULL;
      string* sub_cmap = NULL;
      unordered_map<string,int>* sub_cimap = NULL;
      string* _sub_cmap = NULL;
      unordered_map<string,int>* _sub_cimap = NULL;
      int* ca = NULL;
      
      cmap = util_names("obj",n);
      cimap = util_imap(cmap, n);
      ca = new int[m];
      ca[0] = 1; ca[1] = 7; ca[2] = 2; ca[3] = 9;
      sub_cmap = util_sub(cmap, n, ca, m);
      sub_cimap = util_sub(cimap, ca, m);

      util_fscan(ipfx + "util_sub.ex1_sub_cmap", _sub_cmap, mm);
      util_fscan(ipfx + "util_sub.ex1_sub_cimap", _sub_cimap);

      if(! util_isEqual(sub_cmap, _sub_cmap) ) val++;
      if(! util_isEqual(sub_cimap, _sub_cimap) ) val++;

      //clean memory
      delete [] cmap;
      delete cimap;
      delete [] sub_cmap;
      delete sub_cimap;
      delete [] _sub_cmap;
      delete _sub_cimap;
      delete [] ca;
   }

   {
      string _s = "exec 1 12 -1";
      list<string> L;
      string s;

      L.push_back("1");
      L.push_back("12");
      L.push_back("-1");
      s = util_joinL(" ",&L,"exec");
      if(s.compare(_s)!=0) val++;
   }

   {
      string _s = "(exec 1 12 -1)";
      string s;
      s = util_join2(" ","exec",1,12,-1);
      if(s.compare(_s)!=0) val++;
   }

   {
      list<string>* L = NULL;
      L = util_genL(NULL,"asx",12.5,true,13,-1);
      delete L;
   }

   {
      set<int>* S1 = util_rangeS(3,6);
      set<int>* S2 = util_rangeS(1,5);
      set<int>* _S = util_rangeS(3,5);
      set<int>* S = util_intersect(S1,S2);

      if(! util_isEqual(S,_S)) val++;

      //clean memory
      delete S1;
      delete S2;
      delete S;
      delete _S;
   }

   {
      set<int>* S1 = util_rangeS(3,6);
      set<int>* S2 = util_rangeS(1,5);
      set<int>* _S = util_rangeS(1,6);
      set<int>* S = util_union(S1,S2);

      if(! util_isEqual(S,_S)) val++;

      //clean memory
      delete S1;
      delete S2;
      delete S;
      delete _S;
   }

   {
      Object* ptr1 = Object::instance();
      Object* ptr2 = Object::instance();
      ptr1->set_id("ptr1");
      ptr2->set_id("ptr2");
      util_singleton("Object","ptr1",ptr1);
      util_singleton("Object","ptr2",ptr2);

      if(util_singleton("Object","ptr1")!=ptr1) val++;
      if(util_singleton("Object","ptr2")!=ptr2) val++;
      if(util_singleton("Object","ptr3")!=NULL) val++;
   }

   {
      set<int> m;
      set<int>::iterator it;
      int num;

      m.insert(20100211);

      num = 20100222;
      util_closest_le(&m,num,it);
      if(it==m.end()) val++;
      else if(*it != 20100211) val++;

      num = 20100211;
      util_closest_le(&m,num,it);
      if(it==m.end()) val++;
      else if(*it != 20100211) val++;

      num = 20100202;
      util_closest_le(&m,num,it);
      if(it!=m.end()) val++;
   }

   {
      set<int> m;
      set<int>::iterator it;
      int num;

      m.insert(20100211);
      m.insert(20100216);
      m.insert(20100220);

      num = 20100222;
      util_closest_le(&m,num,it);
      if(it==m.end()) val++;
      else if(*it != 20100220) val++;

      num = 20100202;
      util_closest_le(&m,num,it);
      if(it!=m.end()) val++;

      num = 20100215;
      util_closest_le(&m,num,it);
      if(it==m.end()) val++;
      else if(*it != 20100211) val++;

      num = 20100216;
      util_closest_le(&m,num,it);
      if(it==m.end()) val++;
      else if(*it != 20100216) val++;

      num = 20100217;
      util_closest_le(&m,num,it);
      if(it==m.end()) val++;
      else if(*it != 20100216) val++;
   }



   {
      map<int,string> m;
      map<int,string>::iterator it;
      int num;

      m[20100211] = "a";
      m[20100216] = "b";
      m[20100220] = "c";

      num = 20100222;
      util_closest_le(&m,num,it);
      if(it==m.end()) val++;
      else if(it->first != 20100220) val++;

      num = 20100202;
      util_closest_le(&m,num,it);
      if(it!=m.end()) val++;

      num = 20100215;
      util_closest_le(&m,num,it);
      if(it==m.end()) val++;
      else if(it->first != 20100211) val++;

      num = 20100216;
      util_closest_le(&m,num,it);
      if(it==m.end()) val++;
      else if(it->first != 20100216) val++;

      num = 20100217;
      util_closest_le(&m,num,it);
      if(it==m.end()) val++;
      else if(it->first != 20100216) val++;
   }

   {
      string* arr = NULL;
      set<string>* S = NULL;
      set<string>* _S = NULL;
      int n;

      n = 5;
      arr = new string[n];
      _S = new set<string>();
      for(int i=0;i<n;i++) _S->insert(arr[i] = string("A") + util_string(i));
      S = util_set(arr, n);

      if(!util_isEqual(S,_S)) val++;

      //clean memory
      delete S;
      delete _S;
      delete [] arr;
   }

   if(val>0) printf("%s failed\n",__FUNCTION__);

   return val;
}

#endif 
