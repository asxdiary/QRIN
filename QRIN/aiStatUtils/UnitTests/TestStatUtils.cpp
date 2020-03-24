#include "Utils.hpp"
#include "StatUtils.hpp"

using namespace aiUtils;
using namespace aiStatUtils;

int TestStatUtils_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestStatUtils.";
   const string opfx = "output/TestStatUtils.";

   {
      int* a = NULL;
      const int n = 50;
      const int num = 10;
      for(int i=0;i<num;i++) {
         a = statutil_rand_range(0,n); 
         delete [] a; a = NULL;
      }
   }

   {
      string exS = "corel.ex1.";
      Matrix* X = NULL;

      X = Matrix::instance_fread_table(ipfx + exS + "X.csv");
      val = statutil_corel(X, 0, 2, true);

      //clean memory
      delete X;
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

