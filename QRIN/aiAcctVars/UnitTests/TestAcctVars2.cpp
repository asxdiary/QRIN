#include <vector>
#include "Utils.hpp"
#include "DbGen.hpp"
#include "UtilDate.hpp"

#include "G_OperatingRevenueAccount.hpp"
#include "D_G_OperatingRevenueAccount.hpp"

#include "G_EPSAccount.hpp"
#include "D_G_EPSAccount.hpp"

#include "GrossMarginAccount.hpp"
#include "D_GrossMarginAccount.hpp"

#include "ResearchDevelopmentIntensityAccount.hpp"
#include "D_ResearchDevelopmentIntensityAccount.hpp"

#include "R_NetInterestExpense_OperatingProfitAccount.hpp"
#include "D_R_NetInterestExpense_OperatingProfitAccount.hpp"

#include "OperatingMarginAccount.hpp"
#include "D_OperatingMarginAccount.hpp"

#include "NetMarginAccount.hpp"
#include "D_NetMarginAccount.hpp"

#include "ROEAccount.hpp"
#include "D_ROEAccount.hpp"

#include "ROAAccount.hpp"
#include "D_ROAAccount.hpp"

#include "WorkingCapitalAccount.hpp"
#include "R_Cash_WCAccount.hpp"
#include "D_R_Cash_WCAccount.hpp"

#include "R_Debt_EquityAccount.hpp"
#include "D_R_Debt_EquityAccount.hpp"

#include "R_Liabilities_AssetsAccount.hpp"
#include "D_R_Liabilities_AssetsAccount.hpp"

#include "CurrentRatioIAccount.hpp"
#include "D_CurrentRatioIAccount.hpp"

#include "InventoryTOAccount.hpp"
#include "DIOAccount.hpp"
#include "D_DIOAccount.hpp"

#include "ReceivablesTOAccount.hpp"
#include "DSOAccount.hpp"
#include "D_DSOAccount.hpp"

#include "PayablesTOAccount.hpp"
#include "DPOAccount.hpp"
#include "D_DPOAccount.hpp"

#include "CCCAccount.hpp"
#include "D_CCCAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctVars;
using namespace aiDbUtils;

int TestAcctVars2_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestAcctVars2.";
   const string opfx = "output/TestAcctVars2.";

   {
      string exS = "ex1.";
      ObjectUniverse* univ = NULL;
      Db* db = NULL;
      list<vector<UtilDate*>*> end_dvL;
      list<vector<UtilDate*>*>::iterator it2;
      UtilDate* dh = NULL;
      UtilDate* d0 = NULL;
      UtilDate* d1 = NULL;
      UtilDate* d2 = NULL;
      int xval;

      dh = UtilDate::instance(2015,1,1);
      univ = ObjectUniverse::instance();
      {
         vector<UtilDate*>* end_dv = NULL;
         UtilDate* d = NULL;

         d2 = UtilDate::eom(2013,6);
         d1 = UtilDate::prev_eom(d2,12);
         d0 = UtilDate::prev_eom(d1,12);

         d = d2;
         end_dv = new vector<UtilDate*>(3);
         for(int i=0;i<3;i++) (*end_dv)[2-i] = UtilDate::prev_eom(d, 12*i);
         end_dvL.push_back(end_dv);

         d = d1;
         end_dv = new vector<UtilDate*>(3);
         for(int i=0;i<3;i++) (*end_dv)[2-i] = UtilDate::prev_eom(d, 12*i);
         end_dvL.push_back(end_dv);

         d = d0;
         end_dv = new vector<UtilDate*>(3);
         for(int i=0;i<3;i++) (*end_dv)[2-i] = UtilDate::prev_eom(d, 12*i);
         end_dvL.push_back(end_dv);
      }

      {
         DbGen* ptr = NULL;
         string src;

         src = ipfx + exS + "csv";
         ptr = DbGen::instance(univ);
         ptr->configure(src);
         ptr->algo_exec(dh);
         db = ptr->extract_mdl();

         //clean memory
         delete ptr;
      }

      {
         list<DbAccount*> dbaL;
         list<DbAccount*>::iterator it;
         DbAccount* dba = NULL;

         dba=WorkingCapitalAccount::instance(); dbaL.push_back(dba);
         dba=G_OperatingRevenueAccount::instance(); dbaL.push_back(dba);
         dba=D_G_OperatingRevenueAccount::instance(); dbaL.push_back(dba);
         dba=G_EPSAccount::instance(); dbaL.push_back(dba);
         dba=D_G_EPSAccount::instance(); dbaL.push_back(dba);
         dba=GrossMarginAccount::instance(); dbaL.push_back(dba);
         dba=D_GrossMarginAccount::instance(); dbaL.push_back(dba);
         dba=OperatingMarginAccount::instance(); dbaL.push_back(dba);
         dba=D_OperatingMarginAccount::instance(); dbaL.push_back(dba);
         dba=ResearchDevelopmentIntensityAccount::instance(); dbaL.push_back(dba);
         dba=D_ResearchDevelopmentIntensityAccount::instance(); dbaL.push_back(dba);
         dba=NetMarginAccount::instance(); dbaL.push_back(dba);
         dba=D_NetMarginAccount::instance(); dbaL.push_back(dba);
         dba=ROEAccount::instance(); dbaL.push_back(dba);
         dba=D_ROEAccount::instance(); dbaL.push_back(dba);
         dba=ROAAccount::instance(); dbaL.push_back(dba);
         dba=D_ROAAccount::instance(); dbaL.push_back(dba);
         dba=R_NetInterestExpense_OperatingProfitAccount::instance(); dbaL.push_back(dba);
         dba=D_R_NetInterestExpense_OperatingProfitAccount::instance(); dbaL.push_back(dba);
         dba=R_Debt_EquityAccount::instance(); dbaL.push_back(dba);
         dba=D_R_Debt_EquityAccount::instance(); dbaL.push_back(dba);
         dba=CurrentRatioIAccount::instance(); dbaL.push_back(dba);
         dba=D_CurrentRatioIAccount::instance(); dbaL.push_back(dba);
         dba=R_Cash_WCAccount::instance(); dbaL.push_back(dba);
         dba=D_R_Cash_WCAccount::instance(); dbaL.push_back(dba);
         dba=R_Liabilities_AssetsAccount::instance(); dbaL.push_back(dba);
         dba=D_R_Liabilities_AssetsAccount::instance(); dbaL.push_back(dba);
         dba=InventoryTOAccount::instance(); dbaL.push_back(dba);
         dba=DIOAccount::instance(); dbaL.push_back(dba);
         dba=D_DIOAccount::instance(); dbaL.push_back(dba);
         dba=ReceivablesTOAccount::instance(); dbaL.push_back(dba);
         dba=DSOAccount::instance(); dbaL.push_back(dba);
         dba=D_DSOAccount::instance(); dbaL.push_back(dba);
         dba=PayablesTOAccount::instance(); dbaL.push_back(dba);
         dba=DPOAccount::instance(); dbaL.push_back(dba);
         dba=D_DPOAccount::instance(); dbaL.push_back(dba);
         dba=CCCAccount::instance(); dbaL.push_back(dba);
         dba=D_CCCAccount::instance(); dbaL.push_back(dba);

         for(it=dbaL.begin();it!=dbaL.end();it++) {
            for(it2=end_dvL.begin();it2!=end_dvL.end();it2++) {
               db->compute(*it2, dh, *it, xval);
            }
         }

      }

      db->fprint_summary(opfx + exS + "output.csv");

      //clean memory
      delete db;
      delete univ;
      for(it2=end_dvL.begin();it2!=end_dvL.end();it2++) delete *it2;
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

