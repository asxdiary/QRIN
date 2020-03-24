#include "Utils.hpp"
#include "AcctDb.hpp"
#include "FS.hpp"
#include "Company.hpp"
#include "OperatingRevenueAccount.hpp"
#include "TotalAssetsAccount.hpp"

using namespace aiUtils;
using namespace aiAcctDb;
using namespace aiAcctFields;
using namespace aiDb;

int TestAcctDb_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestAcctDb.";
   const string opfx = "output/TestAcctDb.";

   {
      string exS = "ex1.";
      AcctDb* ptr = NULL;
      Company* cmp = NULL;

      ptr = AcctDb::instance();

      {

         UtilDate* d = NULL;
         UtilDate* start_d = NULL;
         UtilDate* end_d = NULL;
         FS* fs = NULL;

         cmp = Company::instance(CompanyIdentifier::AIID, "A123");

         {
            d = UtilDate::instance(2008,3,12);
            start_d = UtilDate::instance(2007,10,1);
            end_d = UtilDate::instance(2007,12,31);

            fs = FS::instance(cmp, end_d, d, start_d);
            fs->add_ddba(OperatingRevenueAccount::instance(), 10);
            fs->add_ddba(TotalAssetsAccount::instance(), 100);

            ptr->add_odb(fs);
         }

         {
            d = UtilDate::instance(2008,3,12);
            start_d = UtilDate::instance(2008,1,1);
            end_d = UtilDate::instance(2008,3,31);

            fs = FS::instance(cmp, end_d, d, start_d);
            fs->add_ddba(OperatingRevenueAccount::instance(), 12);
            fs->add_ddba(TotalAssetsAccount::instance(), 110);

            ptr->add_odb(fs);
         }

         {
            d = UtilDate::instance(2008,2,12);
            start_d = UtilDate::instance(2008,1,1);
            end_d = UtilDate::instance(2008,3,31);

            fs = FS::instance(cmp, end_d, d, start_d);
            fs->add_ddba(OperatingRevenueAccount::instance(), 13);
            fs->add_ddba(TotalAssetsAccount::instance(), 111);

            ptr->add_odb(fs);
         }
      }

      ptr->fprint_summary(opfx + exS + "summary.csv");

      //clean memory
      delete ptr;
      delete cmp;
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

