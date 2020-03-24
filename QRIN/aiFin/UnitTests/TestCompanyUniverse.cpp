#include "Utils.hpp"
#include "CompanyUniverse.hpp"
#include "CompanyIdentifier.hpp"

using namespace aiUtils;
using namespace aiFin;

int TestCompanyUniverse_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestCompanyUniverse.";
   const string opfx = "output/TestCompanyUniverse.";

   {
      string exS = "ex1.";
      CompanyUniverse* ptr = NULL;
      CompanyUniverse* ptr2 = NULL;
      Company* c1 = NULL;
      Company* c2 = NULL;

      ptr = CompanyUniverse::instance( CompanyIdentifier::AIID );
      c1 = ptr->obj("a1.12",true);
      c2 = ptr->obj("b1.13",true);

      if(c1!=ptr->obj("a1.12")) val++;
      if(c2!=ptr->obj("b1.13")) val++;

      ptr->fprint(opfx + exS + "ptr");

      ptr2 = CompanyUniverse::instance_fscan(opfx + exS + "ptr");
      if(ptr2->obj(c1->id())==NULL) val++;
      if(ptr2->obj(c2->id())==NULL) val++;

      {
         CompanyUniverse* subptr = NULL;
         string cmap[1];
         cmap[0] = c1->id();
         subptr = (CompanyUniverse*) ptr->sub(1,cmap);

         subptr->fprint(opfx + exS + "subptr");

         //clean memory
         delete subptr;
      }

      {
         CompanyUniverse* subptr = NULL;
         string cmap[2];
         cmap[0] = c1->id();
         cmap[1] = "_junk_";
         subptr = ptr->sub(2,cmap,true);

         subptr->fprint(opfx + exS + "subptr2");

         //clean memory
         delete subptr;
      }



      //clean memory
      delete ptr;
      delete ptr2;
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

