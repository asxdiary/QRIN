#include "Utils.hpp"
#include "Company.hpp"
#include "CompanyIdentifier.hpp"

using namespace aiUtils;
using namespace aiFin;

int TestCompany_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestCompany.";
   const string opfx = "output/TestCompany.";

   {
      string exS = "ex1.";
      Company* ptr = NULL;
      Company* ptr2 = NULL;

      ptr = Company::instance(CompanyIdentifier::AIID,"ai.123.1");
      ptr->set_cidm(CompanyIdentifier::instance("CUSIP"),"012912012");
      ptr->set_cidm(CompanyIdentifier::instance("SEDOL"),"aaxxas1");
      ptr->fprint(opfx + exS + "ptr");
      ptr2 = Company::instance_fscan(opfx + exS + "ptr");
      ptr2->fprint(opfx + exS + "ptr2");

      //clean memory
      delete ptr;
      delete ptr2;
   }

   {
      string exS = "ex2.";
      Company* ptr = NULL;
      Company* ptr2 = NULL;

      ptr = Company::instance(CompanyIdentifier::AIID,"ai.123.2");
      ptr->fprint(opfx + exS + "ptr");
      ptr2 = Company::instance_fscan(opfx + exS + "ptr");
      ptr2->fprint(opfx + exS + "ptr2");

      //clean memory
      delete ptr;
      delete ptr2;
   }



   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

