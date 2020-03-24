#include <math.h>
#include "Utils.hpp"
#include "DbGen.hpp"
#include "ObjectDb.hpp"
#include "CompustatQGen.hpp"
#include "CompanyIdentifier.hpp"
#include "CompanyUniverse.hpp"
#include "TotalAssetsAccount.hpp"
#include "OperatingRevenueAccount.hpp"
#include "CostRevenueAccount.hpp"
#include "G_OperatingRevenueAccount.hpp"

using namespace aiUtils;
using namespace aiFin;
using namespace aiAcctFields;
using namespace aiAcctVars;
using namespace aiAcctDbUtils;

int TestCompustatQGen_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestCompustatQGen.";
   const string opfx = "output/TestCompustatQGen.";

   {
      string exS = "ex1.";
      CompanyUniverse* univ = NULL;
      CompustatQGen* ptr = NULL;
      string src; 
      UtilDate* d = NULL;
      AcctDb* mdl = NULL;

      src = ipfx + exS + "src.yyyymm.csv";
      d = UtilDate::instance(2017,1,31);
      univ = CompanyUniverse::instance(CompanyIdentifier::AIID);
      ptr = CompustatQGen::instance(univ);
      ptr->set_err_flag(3);

      ptr->configure(src);
      ((DbGen*)ptr)->algo_exec(d);
      mdl = ptr->extract_mdl();

      {
         map<UtilDate*,UtilDate*> end_dm;
         map<UtilDate*,UtilDate*>::iterator it;
         Object* dbobj = NULL;
         ObjectDb* odb = NULL;
         UtilDate* dh = NULL;
         int xval;

         dbobj = univ->obj("ai001013.01");
         end_dm[UtilDate::instance(2008,5,14)] = UtilDate::instance(2008,1,31);
         end_dm[UtilDate::instance(2008,4,10)] = UtilDate::instance(2008,1,31);
         end_dm[UtilDate::instance(2008,4,9)] = UtilDate::instance(2007,10,31);
         end_dm[UtilDate::instance(2007,12,11)] = UtilDate::instance(2007,10,31);
         end_dm[UtilDate::instance(2007,12,10)] = UtilDate::instance(2007,10,31);
         end_dm[UtilDate::instance(2007,12,9)] = UtilDate::instance(2007,7,31);
         end_dm[UtilDate::instance(2007,8,10)] = UtilDate::instance(2007,7,31);
         end_dm[UtilDate::instance(2007,8,9)] = NULL;
         end_dm[UtilDate::instance(2007,7,31)] = NULL;

         for(it=end_dm.begin();it!=end_dm.end();it++) {
            dh = it->first;
            odb = mdl->odb_closest_le(dbobj, dh, NULL, dh, NULL, false, xval);
            if(it->second==NULL) {
               if(xval==0 && odb!=NULL) val++;
            }
            else {
               if(xval>0) val++;
               else if(odb==NULL) val++;
               else if(odb->end_d() != it->second) val++;
            }
         }
      }

      {
         DbGen* dbg = NULL;
         Db* mdl2 = NULL;

         mdl->fprint_summary(opfx + exS + "output.csv");
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

   {
      string exS = "ex2.";
      CompanyUniverse* univ = NULL;
      CompustatQGen* ptr = NULL;
      string src; 
      UtilDate* d = NULL;
      AcctDb* cQ = NULL;

      src = ipfx + exS + "src.yyyymm.csv";
      d = UtilDate::instance(2017,1,31);
      univ = CompanyUniverse::instance(CompanyIdentifier::AIID);
      ptr = CompustatQGen::instance(univ);
      ptr->set_err_flag(3);

      ptr->configure(src);
      ((DbGen*)ptr)->algo_exec(d);

      cQ = ptr->extract_mdl();
      cQ->fprint_summary(opfx + exS + "cQ.summary");

      {
         Db* cA = NULL;
         vector<UtilDate*> end_dv;
         UtilDate* dh = NULL;
         int xval;

         end_dv.push_back(UtilDate::eom(2004,9));
         end_dv.push_back(UtilDate::eom(2004,12));
         end_dv.push_back(UtilDate::eom(2005,3));
         end_dv.push_back(UtilDate::eom(2005,6));

         dh = UtilDate::eom(2005,8);
         cA = cQ->agg(&end_dv, dh, xval);

         {
            Object* dbobj = NULL;
            UtilDate* end_d = NULL;
            DoubleDbAccount* dba = NULL;
            double x, _x;
            unordered_map<DoubleDbAccount*,double> _xm;
            unordered_map<DoubleDbAccount*,double>::iterator it;

            _xm[OperatingRevenueAccount::instance()] = 205.49297199999998043;
            _xm[TotalAssetsAccount::instance()] = 54.614700999999996611;
            _xm[CostRevenueAccount::instance()] = 72.963277000000005046;

            dbobj = univ->obj("S1");
            end_d = UtilDate::eom(2005,6);
            for(it=_xm.begin();it!=_xm.end();it++) {
               dba = it->first;
               _x = it->second;
               x = cA->ddba(dbobj, end_d, dh, dba, xval);
               if(!util_isEqual(x,_x)) val++;
            }

         }

         cA->fprint_summary(opfx + exS + "cA.summary");

         //clean memory
         delete cA;
      }

      {
         AcctDb* cA = NULL;
         vector<UtilDate*> end_dv;
         UtilDate* end_d = NULL;
         UtilDate* dh = NULL;
         int xval;

         end_d = UtilDate::eom(2011,12);
         UtilDate::eoq(end_d,&end_dv);

         dh = UtilDate::eom(2013,3);
         cA = AcctDb::instance();
         cQ->agg(&end_dv, dh, xval, cA);

         {
            Object* dbobj = NULL;
            DoubleDbAccount* dba = NULL;
            double x, _x;
            unordered_map<DoubleDbAccount*,double> _xm;
            unordered_map<DoubleDbAccount*,double>::iterator it;

            _xm[OperatingRevenueAccount::instance()] = 207.429763;
            _xm[TotalAssetsAccount::instance()] = 49.626428;
            _xm[CostRevenueAccount::instance()] = 65.81922800;

            dbobj = univ->obj("S1");
            for(it=_xm.begin();it!=_xm.end();it++) {
               dba = it->first;
               _x = it->second;
               x = cA->ddba(dbobj, end_d, dh, dba, xval);
               if(!util_isEqual(x,_x,1e-06)) val++;
            }

         }

         //clean memory
         delete cA;
      }

      {
         AcctDb* cA = NULL;
         vector<UtilDate*> end_dv(2);
         DbAccount* dba = NULL;
         UtilDate* dh = NULL;
         int xval;

         cA = AcctDb::instance();
         dh = UtilDate::eom(2013,3);
         end_dv[0] = UtilDate::eom(2004,9);
         end_dv[1] = UtilDate::eom(2005,9);

         for(int i=0;i<2;i++) {
            vector<UtilDate*> tmp;
            UtilDate::eoq(end_dv[i],&tmp);
            cQ->agg(&tmp, dh, xval, cA);
         }

         dba = G_OperatingRevenueAccount::instance();
         cA->compute(&end_dv, dh, dba, xval);

         {
            Object* dbobj = NULL;
            UtilDate* end_d = NULL;
            DoubleDbAccount* dba = NULL;
            double x, _x;
            unordered_map<DoubleDbAccount*,double> _xm;
            unordered_map<DoubleDbAccount*,double>::iterator it;

            end_d = UtilDate::eom(2005,9);
            _xm[G_OperatingRevenueAccount::instance()] = log(1+0.074670271093511875193);

            dbobj = univ->obj("S1");
            for(it=_xm.begin();it!=_xm.end();it++) {
               dba = it->first;
               _x = it->second;
               x = cA->ddba(dbobj, end_d, dh, dba, xval);
               if(!util_isEqual(x,_x,1e-06)) val++;
            }
         }

         cA->fprint_summary(opfx + exS + "AcctVars.output.csv");

         //clean memory
         delete cA;
      }

      //clean memory
      delete ptr;
      delete univ;
      delete cQ;
   }

   {
      string exS = "ex3.";
      CompanyUniverse* univ = NULL;
      CompustatQGen* ptr = NULL;
      string src; 
      UtilDate* d = NULL;
      AcctDb* mdl = NULL;

      src = ipfx + exS + "src.yyyymm.csv";
      d = UtilDate::instance(2017,1,31);
      univ = CompanyUniverse::instance(CompanyIdentifier::AIID);
      ptr = CompustatQGen::instance(univ);
      ptr->set_err_flag(3);
      ptr->set_lookahead(5);

      ptr->configure(src);
      ((DbGen*)ptr)->algo_exec(d);
      mdl = ptr->extract_mdl();
      mdl->fprint_summary(opfx + exS + "summary.csv");

      //clean memory
      delete mdl;
      delete ptr;
      delete univ;
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

