#include "Utils.hpp"
#include "MarketDbGen.hpp"
#include "DbGen.hpp"

using namespace aiUtils;
using namespace aiMarketDbUtils;

int TestMarketDbGen_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestMarketDbGen.";
   const string opfx = "output/TestMarketDbGen.";

   {
      string exS = "ex1.";
      CompanyUniverse* univ = NULL;
      MarketDbGen* ptr = NULL;
      string src; 
      UtilDate* d = NULL;

      src = ipfx + exS + "csv";
      d = UtilDate::instance(2017,1,31);
      univ = CompanyUniverse::instance(CompanyIdentifier::AIID);
      ptr = MarketDbGen::instance(univ);
      ptr->set_err_flag(3);

      ptr->configure(src);
      ((DbGen*)ptr)->algo_exec(d);

      {
         DbGen* dbg = NULL;
         Db* mdl = NULL;
         Db* mdl2 = NULL;

         mdl = ptr->extract_mdl();
         mdl->fprint_summary(opfx + exS + "output.csv");
         dbg = DbGen::instance(univ);
         dbg->set_err_flag(3);
         dbg->configure(opfx + exS + "output.csv");
         dbg->algo_exec(d);
         mdl2 = dbg->extract_mdl();
         mdl2->fprint_summary(opfx + exS + "output2.csv");

         //clean memory
         delete mdl;
         delete mdl2;
         delete dbg;
      }

      //clean memory
      delete ptr;
      delete univ;
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

