#include "Utils.hpp"
#include "FinDb.hpp"
#include "CompanyIdentifier.hpp"

using namespace aiUtils;
using namespace aiFin;

int TestFinDb_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestFinDb.";
   const string opfx = "output/TestFinDb.";

   {
      string exS = "ex1.";
      FinDb* ptr = NULL;
      FinDb* ptr2 = NULL;
      Company* c1 = NULL;
      Company* c2 = NULL;

      ptr = FinDb::instance( CompanyIdentifier::AIID );
      c1 = ptr->cmpm("a1.12",true);
      c2 = ptr->cmpm("b1.13",true);

      if(c1!=ptr->cmpm("a1.12")) val++;
      if(c2!=ptr->cmpm("b1.13")) val++;

      ptr->fprint(opfx + exS + "ptr");

      ptr2 = FinDb::instance_fscan(opfx + exS + "ptr");
      if(ptr2->cmpm(c1->id())==NULL) val++;
      if(ptr2->cmpm(c2->id())==NULL) val++;

      //clean memory
      delete ptr;
      delete ptr2;
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

