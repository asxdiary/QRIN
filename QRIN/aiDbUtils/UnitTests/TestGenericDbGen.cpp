#include "Utils.hpp"
#include "GenericDbGen.hpp"
#include "ObjectUniverse.hpp"
#include "Db.hpp"

using namespace aiUtils;
using namespace aiDbUtils;

int TestGenericDbGen_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestGenericDbGen.";
   const string opfx = "output/TestGenericDbGen.";

   {
      string exS = "ex1.";
      GenericDbGen* ptr = NULL;
      ObjectUniverse* univ = NULL;
      string oid;

      univ = ObjectUniverse::instance();
      oid = "ObjectDb.dbobj";
      ptr = GenericDbGen::instance(univ, oid);
      ptr->add_ddba_idS("OperatingRevenueAccount");
      ptr->add_ddba_idS("TotalAssetsAccount");

      ptr->configure(ipfx + exS + "input.csv");
      ptr->algo_exec(UtilDate::instance(2000,1,1));
      ptr->mdl()->fprint_summary(opfx + exS + "output.csv");

      //clean memory
      delete ptr;
      delete univ;
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

