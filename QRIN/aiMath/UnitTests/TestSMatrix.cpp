#include <list>
#include <unordered_map>
#include "Utils.hpp"
#include "SMatrix.hpp"

using namespace aiUtils;
using namespace aiMath;

int TestSMatrix_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestSMatrix.";
   const string opfx = "output/TestSMatrix.";

   {
      string exS = "ex1.";
      SMatrix* ptr = NULL;
      SMatrix* ptr2 = NULL;

      ptr = SMatrix::instance(4,5);
      ptr->fprint(opfx + exS + "ptr");
      ptr2 = SMatrix::instance_fscan(opfx + exS + "ptr");
      ptr2->fprint(opfx + exS + "ptr2");

      //clean memory
      delete ptr;
      delete ptr2;
   }

   {
      string exS = "ex2.";
      SMatrix* ptr = NULL;
      string fname = ipfx + exS + "raw.csv";
      ptr = SMatrix::instance_fscan(fname,true,"|");
      ptr->fprint(opfx + exS + "raw");
      ptr->fprint_raw(opfx + exS + "raw2");
      delete ptr;
   }

   {
      string exS = "ex3.";
      list<unordered_map<string,string>*>* L = NULL;
      unordered_map<string,string>* m = NULL;
      
      L = new list<unordered_map<string,string>*>();

      m = new unordered_map<string,string>();
      (*m)["h1"] = "val1.1";
      (*m)["h2"] = "val2.1";
      L->push_back(m);

      m = new unordered_map<string,string>();
      (*m)["h2"] = "val2.2";
      (*m)["h3"] = "val3.2";
      L->push_back(m);

      m = new unordered_map<string,string>();
      (*m)["h3"] = "val3.3";
      (*m)["h1"] = "val1.3";
      L->push_back(m);

      SMatrix* ptr = SMatrix::instance(L);
      ptr->fprint_raw(opfx + exS + "raw");
      SMatrix* ptr2 = SMatrix::instance_fscan(opfx + exS + "raw", true);
      ptr2->fprint_raw(opfx + exS + "raw2");

      //clean memory
      delete ptr;
      delete ptr2;
      util_clean(L);
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

