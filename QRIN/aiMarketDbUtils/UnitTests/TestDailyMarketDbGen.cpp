#include "Utils.hpp"
#include "DailyMarketDbGen.hpp"
#include "DbGen.hpp"
#include "WealthAccount.hpp"

using namespace aiUtils;
using namespace aiMarketDbUtils;
using namespace aiMarketFields;

int TestDailyMarketDbGen_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestDailyMarketDbGen.";
   const string opfx = "output/TestDailyMarketDbGen.";

   {
      string exS = "ex1.";
      CompanyUniverse* univ = NULL;
      DailyMarketDbGen* ptr = NULL;
      string src; 
      UtilDate* d = NULL;
      Db* mdl = NULL;

      src = ipfx + exS + "csv";
      d = UtilDate::instance(2017,1,31);
      univ = CompanyUniverse::instance(CompanyIdentifier::AIID);
      ptr = DailyMarketDbGen::instance(univ);
      ptr->set_err_flag(3);

      ptr->configure(src);
      ((DbGen*)ptr)->algo_exec(d);
      mdl = ptr->extract_mdl();
      mdl->fprint_summary(opfx + exS + "output.csv");

      //test cumret
      {
         Object* dbobj = NULL;
         WealthAccount* dba = NULL;
         UtilDate* d1 = NULL;
         UtilDate* d2 = NULL;
         double cret, _cret;
         int xval;

         dbobj = univ->obj("ai160329.01");
         dba = WealthAccount::instance();

         d1 = UtilDate::instance(2013,3,7);
         d2 = UtilDate::instance(2013,3,27);
         cret = dba->cumret(dbobj, mdl, d1, d2, xval);
			_cret = -0.03595501299549874741;
         if(xval>0 || !util_isEqual(cret,_cret)) val++;

         d1 = UtilDate::instance(2013,3,2);
         d2 = UtilDate::instance(2013,3,27);
         cret = dba->cumret(dbobj, mdl, d1, d2, xval);
			_cret = -0.00437862042446623967;
         if(xval>0 || !util_isEqual(cret,_cret)) val++;

         d1 = UtilDate::instance(2013,3,2);
         d2 = UtilDate::instance(2013,3,9);
         cret = dba->cumret(dbobj, mdl, d1, d2, xval);
			_cret = 0.03141939245091074362;
         if(xval>0 || !util_isEqual(cret,_cret)) val++;

         d1 = UtilDate::instance(2013,3,27);
         d2 = UtilDate::instance(2013,3,2);
         cret = dba->cumret(dbobj, mdl, d1, d2, xval);
         if(xval==0) val++;
      }

      {
         DbGen* dbg = NULL;
         Db* mdl2 = NULL;

         dbg = DbGen::instance(univ);
         dbg->set_err_flag(3);
         dbg->configure(opfx + exS + "output.csv");
         dbg->algo_exec(d);
         mdl2 = dbg->extract_mdl();
         mdl2->fprint_summary(opfx + exS + "output2.csv");

         //clean memory
         delete mdl2;
         delete dbg;
      }

      //clean memory
      delete mdl;
      delete ptr;
      delete univ;
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

