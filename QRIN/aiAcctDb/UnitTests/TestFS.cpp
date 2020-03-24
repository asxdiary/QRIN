#include "Utils.hpp"
#include "FS.hpp"
#include "Company.hpp"
#include "OperatingRevenueAccount.hpp"
#include "TotalAssetsAccount.hpp"

using namespace aiUtils;
using namespace aiAcctFields;
using namespace aiAcctDb;

int TestFS_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestFS.";
   const string opfx = "output/TestFS.";

   {
      string exS = "ex1.";
      Company* cmp = NULL;
      UtilDate* d = NULL;
      UtilDate* start_d = NULL;
      UtilDate* end_d = NULL;
      FS* ptr = NULL;

      cmp = Company::instance(CompanyIdentifier::AIID, "A123");
      d = UtilDate::instance(2008,3,12);
      start_d = UtilDate::instance(2007,10,1);
      end_d = UtilDate::instance(2007,12,31);

      ptr = FS::instance(cmp, end_d, d, start_d);
      ptr->add_ddba(OperatingRevenueAccount::instance(), 10);
      ptr->add_ddba(OperatingRevenueAccount::instance(), 11, 1);
      ptr->add_ddba(TotalAssetsAccount::instance(), 100, 0);

      {
         UtilDate* dh = NULL;
         DoubleDbAccount* dba = NULL;
         double x;
         int xval;

         dba = OperatingRevenueAccount::instance();
         dh = d;
         xval = 0; x = 0;
         x = ptr->ddba(cmp, end_d, dh, dba, xval);
         if(xval>0) val++;
         if(xval==0 && x!=10) val++;

         dh = UtilDate::instance(2008,3,13);
         xval = 0; x = 0;
         x = ptr->ddba(cmp, end_d, dh, dba, xval);
         if(xval>0) val++;
         if(xval==0 && x!=10) val++;

         dh = UtilDate::instance(2008,2,13);
         xval = 0; x = 0;
         x = ptr->ddba(cmp, end_d, dh, dba, xval);
         if(xval==0) val++;
      }

      ptr->fprint_summary(opfx + exS + "summary.csv");

      //clean memory
      delete ptr;
      delete cmp;
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

