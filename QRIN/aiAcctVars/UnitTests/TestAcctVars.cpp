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

int TestAcctVars_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestAcctVars.";
   const string opfx = "output/TestAcctVars.";

   {
      string exS = "ex1.";
      ObjectUniverse* univ = NULL;
      Object* dbobj = NULL;
      DoubleDbAccount* dba = NULL;
      Db* db = NULL;
      list<vector<UtilDate*>*> end_dvL;
      list<vector<UtilDate*>*>::iterator it;
      UtilDate* dh = NULL;
      UtilDate* d0 = NULL;
      UtilDate* d1 = NULL;
      UtilDate* d2 = NULL;
      int xval;
      double x, _x;

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

      dbobj = univ->obj("ai165914.01");

      //Compute G_OperatingRevenueAccount
      {
         dba = G_OperatingRevenueAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
			_x = 0.15519259676295457662;
         if(xval>0 || !util_isEqual(x,_x)) val++;

         x = db->ddba(dbobj, d1, dh, dba, xval);
			_x = 0.21119720129326949309;
         if(xval>0 || !util_isEqual(x,_x,1e-06)) val++;
      }

      //Compute D_G_OperatingRevenueAccount
      {
         dba = D_G_OperatingRevenueAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
			_x = -0.05600460453031491648;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute G_EPSAccount
      {
         dba = G_EPSAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
			_x = 0.13427961562987497657;
         if(xval>0 || !util_isEqual(x,_x)) val++;

         x = db->ddba(dbobj, d1, dh, dba, xval);
			_x = 0.30256270094546766636;
         if(xval>0 || !util_isEqual(x,_x,1e-06)) val++;
      }

      //Compute D_G_EPSAccount
      {
         dba = D_G_EPSAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
			_x = -0.16828308531559268979;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute GrossMarginAccount
      {
         dba = GrossMarginAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = 0.26522597992814689327;
         if(xval>0 || !util_isEqual(x,_x)) val++;

         x = db->ddba(dbobj, d1, dh, dba, xval);
         _x = 0.27386159011927124762;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute D_GrossMarginAccount
      {
         dba = D_GrossMarginAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = -0.00863561019112435435;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute OperatingMarginAccount
      {
         dba = OperatingMarginAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = 0.16694402672441738256;
         if(xval>0 || !util_isEqual(x,_x)) val++;

         x = db->ddba(dbobj, d1, dh, dba, xval);
         _x = 0.17196875726646715377;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute D_OperatingMarginAccount
      {
         dba = D_OperatingMarginAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = -0.00502473054204977121;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute NetMarginAccount
      {
         dba = NetMarginAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = 0.10128002402805628968;
         if(xval>0 || !util_isEqual(x,_x)) val++;

         x = db->ddba(dbobj, d1, dh, dba, xval);
         _x = 0.10406295210817820274;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute D_NetMarginAccount
      {
         dba = D_NetMarginAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = -0.00278292808012191306;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute ROEAccount
      {
         dba = ROEAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = 0.22679927628745813473;
         if(xval>0 || !util_isEqual(x,_x)) val++;

         x = db->ddba(dbobj, d1, dh, dba, xval);
         _x = 0.23838072033330198751;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute D_ROEAccount
      {
         dba = D_ROEAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x  = -0.01158144404584385279;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute ROAAccount
      {
         dba = ROAAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
			_x = 0.17243892703639213115;
         if(xval>0 || !util_isEqual(x,_x)) val++;

         x = db->ddba(dbobj, d1, dh, dba, xval);
			_x = 0.18011943722334211593;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute D_ROAAccount
      {
         dba = D_ROAAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
			_x = -0.00768051018694998477;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute WorkingCapitalAccount 
      {
         dba = WorkingCapitalAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = 372.30299999999999727152;
         if(xval>0 || !util_isEqual(x,_x)) val++;

         x = db->ddba(dbobj, d1, dh, dba, xval);
         _x = 470.33299999999996998667;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute R_Cash_WCAccount
      {
         dba = R_Cash_WCAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = 1.29946844371385661354;
         if(xval>0 || !util_isEqual(x,_x)) val++;

         x = db->ddba(dbobj, d1, dh, dba, xval);
         _x = 1.12586826780174908968;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute D_R_Cash_WCAccount
      {
         dba = D_R_Cash_WCAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = 0.17360017591210752386;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }


      //Compute R_Debt_EquityAccount
      {
         dba = R_Debt_EquityAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = 0.32285660170113122946;
         if(xval>0 || !util_isEqual(x,_x)) val++;

         x = db->ddba(dbobj, d1, dh, dba, xval);
         _x = 0.30699042597474679450;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute D_R_Debt_EquityAccount
      {
         dba = D_R_Debt_EquityAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = 0.01586617572638443496;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute InventoryTOAccount
      {
         dba = InventoryTOAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = 198.64113162487367958420;
         if(xval>0 || !util_isEqual(x,_x)) val++;

         x = db->ddba(dbobj, d1, dh, dba, xval);
         _x = 193.12637855522135055253;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute DIOAccount
      {
         dba = DIOAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = 1.83748449786970002862;
         if(xval>0 || !util_isEqual(x,_x)) val++;

         x = db->ddba(dbobj, d1, dh, dba, xval);
         _x = 1.88995414676423489908;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute D_DIOAccount
      {
         dba = D_DIOAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = -0.05246964889453487046;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute ReceivablesTOAccount
      {
         dba = ReceivablesTOAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = 232.55578381795191944548;
         if(xval>0 || !util_isEqual(x,_x)) val++;

         x = db->ddba(dbobj, d1, dh, dba, xval);
         _x = 304.91687840290376243502;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute DSOAccount
      {
         dba = DSOAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = 1.56951589854126072332;
         if(xval>0 || !util_isEqual(x,_x)) val++;

         x = db->ddba(dbobj, d1, dh, dba, xval);
         _x = 1.19704754263457013863;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute D_DSOAccount
      {
         dba = D_DSOAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = 0.37246835590669058469;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }


      //Compute PayablesTOAccount
      {
         dba = PayablesTOAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = 36.26555988764515348066;
         if(xval>0 || !util_isEqual(x,_x)) val++;

         x = db->ddba(dbobj, d1, dh, dba, xval);
         _x = 38.03797626223783368005;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute DPOAccount
      {
         dba = DPOAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = 10.06464538616835646678;
         if(xval>0 || !util_isEqual(x,_x)) val++;

         x = db->ddba(dbobj, d1, dh, dba, xval);
         _x = 9.59567347862176944773;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute D_DPOAccount
      {
         dba = D_DPOAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = 0.46897190754658701906;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute R_Liabilities_AssetsAccount
      {
         dba = R_Liabilities_AssetsAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = 0.24406016592119875175;
         if(xval>0 || !util_isEqual(x,_x)) val++;

         x = db->ddba(dbobj, d1, dh, dba, xval);
         _x = 0.23488345428834711548;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute D_R_Liabilities_AssetsAccount
      {
         dba = D_R_Liabilities_AssetsAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = 0.00917671163285163627;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }





      //Compute CurrentRatioIAccount
      {
         dba = CurrentRatioIAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = 0.32919587034467845399;
         if(xval>0 || !util_isEqual(x,_x)) val++;

         x = db->ddba(dbobj, d1, dh, dba, xval);
         _x = 0.24193881136351183536;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute D_CurrentRatioIAccount
      {
         dba = D_CurrentRatioIAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = 0.08725705898116661863;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute CCCAccount
      {
         dba = CCCAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
		   _x = -6.65764498975739549280;
         if(xval>0 || !util_isEqual(x,_x)) val++;

         x = db->ddba(dbobj, d1, dh, dba, xval);
		   _x = -6.50867178922296396593;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute D_CCCAccount
      {
         dba = D_CCCAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
		   _x = -0.14897320053443152688;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      //Compute ResearchDevelopmentIntensityAccount
      {
         dba = ResearchDevelopmentIntensityAccount::instance();
         for(it=end_dvL.begin();it!=end_dvL.end();it++) {
            db->compute(*it, dh, dba, xval);
         }

         //check
         x = db->ddba(dbobj, d2, dh, dba, xval);
         _x = 0;
         if(xval>0 || !util_isEqual(x,_x)) val++;

         x = db->ddba(dbobj, d1, dh, dba, xval);
         _x = 0;
         if(xval>0 || !util_isEqual(x,_x)) val++;
      }

      db->fprint_summary(opfx + exS + "output.csv");

      //clean memory
      delete db;
      delete univ;
      for(it=end_dvL.begin();it!=end_dvL.end();it++) delete *it;
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

