#include "Utils.hpp"
#include "FSDb.hpp"
#include "FS.hpp"
#include "ObjectDb.hpp"
#include "Company.hpp"
#include "OperatingRevenueAccount.hpp"
#include "TotalAssetsAccount.hpp"

using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctDb;
using namespace aiAcctFields;

int TestFSDb_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestFSDb.";
   const string opfx = "output/TestFSDb.";

   {
      string exS = "ex1.";
      Company* cmp = NULL;

      UtilDate* d = NULL;
      UtilDate* start_d = NULL;
      UtilDate* end_d = NULL;
      FS* fs = NULL;
      FSDb* ptr = NULL;

      FS* fs1 = NULL;
      FS* fs2 = NULL;
      FS* fs3 = NULL;

      cmp = Company::instance(CompanyIdentifier::AIID, "A123");
      ptr = FSDb::instance(cmp);

      {
         d = UtilDate::instance(2008,3,12);
         start_d = UtilDate::instance(2007,10,1);
         end_d = UtilDate::instance(2007,12,31);

         fs = FS::instance(cmp, end_d, d, start_d);
         fs->add_ddba(OperatingRevenueAccount::instance(), 10);
         fs->add_ddba(TotalAssetsAccount::instance(), 100);

         ptr->add_odb(fs1=fs);
      }

      {
         d = UtilDate::instance(2008,3,12);
         start_d = UtilDate::instance(2008,1,1);
         end_d = UtilDate::instance(2008,3,31);

         fs = FS::instance(cmp, end_d, d, start_d);
         fs->add_ddba(OperatingRevenueAccount::instance(), 12);
         fs->add_ddba(TotalAssetsAccount::instance(), 110);

         ptr->add_odb(fs2=fs);
      }

      {
         d = UtilDate::instance(2008,2,12);
         start_d = UtilDate::instance(2008,1,1);
         end_d = UtilDate::instance(2008,3,31);

         fs = FS::instance(cmp, end_d, d, start_d);
         fs->add_ddba(OperatingRevenueAccount::instance(), 13);
         fs->add_ddba(TotalAssetsAccount::instance(), 111);

         ptr->add_odb(fs3=fs);
      }

      {
         unordered_map<UtilDate*,FS*> _m;
         unordered_map<UtilDate*,FS*>::iterator it;
         UtilDate* end_d = NULL;
         UtilDate* dh = NULL;
         FS* _fs = NULL;

         _m[UtilDate::instance(2008,2,1)] = NULL;
         _m[UtilDate::instance(2008,2,24)] = fs3;
         /*
         _m[UtilDate::instance(2008,3,12)] = fs2;
         _m[UtilDate::instance(2008,3,13)] = fs2;
         _m[UtilDate::instance(2008,3,11)] = fs3;
         */

         end_d = UtilDate::instance(2008,3,31);

         for(it=_m.begin();it!=_m.end();it++) {
            dh = it->first; _fs = it->second;
            FS* x = NULL;
            int xval;

            x = ptr->fs(cmp, end_d, dh, xval);
            if(x!=_fs) val++;
            if(x==NULL && xval==0) val++;
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

