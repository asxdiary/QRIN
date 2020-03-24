#include "Utils.hpp"
#include "Dated.hpp"

using namespace aiUtils;
using namespace aiUtils;

int TestDated_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestDated.";
   const string opfx = "output/TestDated.";

   {
      string exS = "ex1.";
      Dated* ptr = NULL;
      Dated* ptr2 = NULL;
      ptr = Dated::instance(UtilDate::instance(2008,1,12));
      ptr->fprint(opfx + exS + "ptr");
      ptr2 = Dated::instance_fscan(opfx + exS + "ptr");
      ptr2->fprint(opfx + exS + "ptr2");
      if(! ptr2->validate(UtilDate::instance(2008,1,12))) val++;
      if(! ptr2->validate(UtilDate::instance(2009,1,12))) val++;
      delete ptr;
      delete ptr2;
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

