#include "Utils.hpp"
#include "DbGen.hpp"
#include "ObjectUniverse.hpp"
#include "Db.hpp"

using namespace aiUtils;
using namespace aiDbUtils;

int TestDbGen_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestDbGen.";
   const string opfx = "output/TestDbGen.";

   {
      string exS = "ex1.";
      DbGen* ptr = NULL;
      ObjectUniverse* univ = NULL;

      univ = ObjectUniverse::instance();
      ptr = DbGen::instance(univ);
      ptr->configure(ipfx + exS + "input.csv");
      ptr->algo_exec(UtilDate::instance(2000,1,1));
      ptr->mdl()->fprint_summary(opfx + exS + "output.csv");

      {
         DbGen* ptr2 = NULL;
         Db* db = NULL;

         db = Db::instance();
         ptr2 = DbGen::instance(univ);
         ptr2->configure(opfx + exS + "output.csv", db);
         ptr2->algo_exec(UtilDate::instance(2000,1,1));
         ptr2->mdl()->fprint_summary(opfx + exS + "output2.csv");

         //clean memory
         delete ptr2;
      }

      //clean memory
      delete ptr;
      delete univ;
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

