#include "Utils.hpp"
#include "SmartestFYGen.hpp"
#include "CompanyIdentifier.hpp"
#include "CompanyUniverse.hpp"
#include "DbGen.hpp"
#include "TotalAssetsAccount.hpp"
#include "OperatingRevenueAccount.hpp"

using namespace aiUtils;
using namespace aiDb;
using namespace aiFin;
using namespace aiAcctDb;
using namespace aiAcctFields;
using namespace aiAcctDbUtils;

int TestSmartestFYGen_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestSmartestFYGen.";
   const string opfx = "output/TestSmartestFYGen.";

   {
      string exS = "ex3.";
      CompanyUniverse* fdb = NULL;
      SmartestFYGen* ptr = NULL;
      string src; 
      UtilDate* d = NULL;
      AcctDb* mdl = NULL;

      src = ipfx + exS + "src.yyyymm.csv";
      d = UtilDate::instance(2017,1,31);
      fdb = CompanyUniverse::instance(CompanyIdentifier::AIID);
      ptr = SmartestFYGen::instance(fdb);

      ptr->configure(src);
      ((DbGen*)ptr)->algo_exec(d);
      mdl = ptr->extract_mdl();
      mdl->fprint_summary(opfx + exS + "output.csv");

      //test interpolation
      {
         Object* dbobj = NULL;
         Db* db = NULL;
         UtilDate* start_d = NULL;
         UtilDate* end_d = NULL;
         UtilDate* dh = NULL;
         DoubleDbAccount* dba = NULL;
         double x, _x;
         int xval;

         dbobj = fdb->obj("ai001690.01");

         {
            unordered_map<DoubleDbAccount*,double> _xm;
            unordered_map<DoubleDbAccount*,double>::iterator it;

            start_d = UtilDate::eom(2012,11);
            end_d = UtilDate::eom(2013,11);
            dh = UtilDate::eom(2012, 11);
            db = mdl->interpolate(end_d, dh, start_d, xval, db);

            _xm[OperatingRevenueAccount::instance()] = 198126482700.52667236328125000000;

            for(it=_xm.begin();it!=_xm.end();it++) {
               dba = it->first;
               x = db->ddba(dbobj, end_d, dh, dba, xval);
               _x = it->second;
               if(xval>0 || !util_isEqual(x,_x)) val++;
            }
         }

         {
            unordered_map<DoubleDbAccount*,double> _xm;
            unordered_map<DoubleDbAccount*,double>::iterator it;

            start_d = UtilDate::eom(2012,9);
            end_d = UtilDate::eom(2013,9);
            dh = UtilDate::eom(2012, 9);
            db = mdl->interpolate(end_d, dh, start_d, xval, db);

            _xm[OperatingRevenueAccount::instance()] = 195779415267.86999511718750000000;

            for(it=_xm.begin();it!=_xm.end();it++) {
               dba = it->first;
               x = db->ddba(dbobj, end_d, dh, dba, xval);
               _x = it->second;
               if(xval>0 || !util_isEqual(x,_x)) val++;
            }

         }

         db->fprint_summary(opfx + exS + "interpolate.db.csv");

         //clean memory
         delete db;
      }

      //clean memory
      delete mdl;
      delete ptr;
      delete fdb;
   }

   {
      string exS = "ex4.";
      CompanyUniverse* fdb = NULL;
      SmartestFYGen* ptr = NULL;
      string src; 
      UtilDate* d = NULL;
      AcctDb* mdl = NULL;

      src = ipfx + exS + "src.yyyymm.csv";
      d = UtilDate::instance(2017,1,31);
      fdb = CompanyUniverse::instance(CompanyIdentifier::AIID);
      ptr = SmartestFYGen::instance(fdb);

      ptr->configure(src);
      ((DbGen*)ptr)->algo_exec(d);
      mdl = ptr->extract_mdl();
      mdl->fprint_summary(opfx + exS + "output.csv");

      //clean memory
      delete mdl;
      delete ptr;
      delete fdb;
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

