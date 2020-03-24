#include "Utils.hpp"
#include "CompanyIdentifier.hpp"

using namespace aiUtils;
using namespace aiFin;

int TestCompanyIdentifier_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestCompanyIdentifier.";
   const string opfx = "output/TestCompanyIdentifier.";

   {
      CompanyIdentifier* ptr = NULL;
      ptr = CompanyIdentifier::instance("CUSIP"); ptr->fprint(opfx + ptr->id());
      ptr = CompanyIdentifier::AIID; ptr->fprint(opfx + ptr->id());
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

