#include "Utils.hpp"
#include "Global.hpp"
#include "Utils_templates.hpp"

using namespace aiUtils;
using namespace aiUtils;

int TestGlobal_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestGlobal.";
   const string opfx = "output/TestGlobal.";

   {
      Global* ptr = Global::instance();
      ptr->fprint(opfx + "ptr");
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

