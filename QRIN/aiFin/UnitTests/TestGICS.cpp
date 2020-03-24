#include "Utils.hpp"
#include "GICS.hpp"

using namespace aiUtils;
using namespace aiFin;

int TestGICS_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestGICS.";
   const string opfx = "output/TestGICS.";

   {
      GICS* ptr = NULL;
      ptr = GICS::instance();
      ptr->fprint(opfx + "GICS.ex1");
   }

   {
      GICS* ptr = NULL;
      ptr = GICS::instance();
      ptr->fprint(opfx + "GICS.ex2");
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

