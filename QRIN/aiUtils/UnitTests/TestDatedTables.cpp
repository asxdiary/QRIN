#include "Utils.hpp"
#include "DatedTables.hpp"

using namespace aiUtils;
using namespace aiUtils;

int TestDatedTables_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestDb.";
   const string opfx = "output/TestDb.";

   {
      string exS = "ex1.";
      DatedTables* ptr = NULL;
      string src;

      src = ipfx + exS + "yyyymm.csv";
      ptr = DatedTables::instance(src);
      ptr->load(UtilDate::instance(2007,1,31));
      ptr->fprint(opfx + exS + "db");

      //clean memory
      delete ptr;
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

