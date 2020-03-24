#include "Utils.hpp"
#include "Matrix.hpp"
#include "ForecastUtils.hpp"
#include "Db.hpp"
#include "MarketDbGen.hpp"
#include "DailyMarketDbGen.hpp"
#include "Global.hpp"
#include "CompanyIdentifier.hpp"
#include "CompanyUniverse.hpp"
#include "TotalReturnsAccount.hpp"
#include "SP500BetaAccount.hpp"
#include "WealthAccount.hpp"
#include "MarketDbUtils.hpp"

using namespace aiFin;
using namespace aiForecastUtils;
using namespace aiMarketFields;
using namespace aiMarketDbUtils;

Matrix* GenMomDM_gen(CompanyUniverse* univ, Db* mmdb, Db* dmdb, UtilDate* d, int K,
                     bool resflag) 
{
   printf("%s processing %d\n",__FUNCTION__,d->icode());
   DoubleDbAccount* beta_act = SP500BetaAccount::instance();
   unordered_map<string, double> valm;
   WealthAccount* wdba = WealthAccount::instance();
   unordered_map<string,Object*>* objm = NULL;
   unordered_map<string,Object*>::iterator it;
   Matrix* X = NULL;
   int xval;
   double x, xmkt, beta;
   string cid;

   xmkt = 0;
   if(resflag) cid = "ResReturn";
   else cid = "TotalReturn";

   cid = util_join(".",cid,K);

   //determine market return
   if(resflag) {
      string mkt_id = MarketDbUtils_mkt();
      Object* a = univ->obj(mkt_id);
      if(a==NULL) err_msg("could not find market asset for date ",d->id());
      xmkt = wdba->cumret(a, dmdb, d, d->next_eom(K), xval);
      if(xval>0) err_msg("could not find market return for date ",d->id());
   }

   objm = univ->objm();
   for(it=objm->begin();it!=objm->end();it++) {
      Object* a = it->second;

      beta = 0;

      if(resflag) {
         beta = mmdb->ddba(a, d, d, beta_act, xval);
         if(xval>0) continue;
      }

      x = wdba->cumret(a, dmdb, d, d->next_eom(K), xval);
      if(xval>0) continue;

      x = x - beta * xmkt;
      valm[a->id()] = x;
   }

   X = Matrix::instance_col(&valm, cid);
   return X;
}


Db* GenMomDM_gen_mmdb(CompanyUniverse* univ, UtilDate* da, UtilDate* db) {
   list<UtilDate*> dL;
   Db* mmdb = NULL;
   MarketDbGen* ptr = NULL;
   string src;

   src = Global::instance()->mmdb_src();
   ptr = MarketDbGen::instance(univ);
   ptr->configure(src);
   UtilDate::eomL(da, db, &dL);
   ((DbGen*)ptr)->algo_exec(&dL);
   mmdb = ptr->extract_mdl();
   mmdb->set_id("mmdb");

   //clean memory 
   delete ptr;

   return mmdb;
}


Db* GenMomDM_gen_dmdb(CompanyUniverse* univ, UtilDate* da, UtilDate* db) {
   list<UtilDate*> dL;
   Db* dmdb = NULL;
   DailyMarketDbGen* ptr = NULL;
   string src;

   src = Global::instance()->dmdb_src();
   ptr = DailyMarketDbGen::instance(univ);
   ptr->configure(src);
   UtilDate::eomL(da, db, &dL);
   ((DbGen*)ptr)->algo_exec(&dL);
   dmdb = ptr->extract_mdl();
   dmdb->set_id("dmdb");

   //clean memory 
   delete ptr;

   return dmdb;
}

int GenMomDM_main() {
   CompanyUniverse* univ = NULL;
   Db* dmdb = NULL;
   Db* mmdb = NULL;
   unordered_map<UtilDate*,Matrix*>* tot_m12_dm = NULL;
   unordered_map<UtilDate*,Matrix*>* res_m12_dm = NULL;
   unordered_map<UtilDate*,Matrix*>* tot_1_dm = NULL;
   unordered_map<UtilDate*,Matrix*>* res_1_dm = NULL;
   unordered_map<UtilDate*,Matrix*>::iterator it;
   UtilDate* da = NULL;
   UtilDate* db = NULL;
   UtilDate* d = NULL;
   Matrix* X = NULL;
   int K;

   K = 1;

   univ = CompanyUniverse::instance(CompanyIdentifier::AIID);
   da = UtilDate::eom(2005,12);
   db = UtilDate::eom(2018,1);
   dmdb = GenMomDM_gen_dmdb(univ, da, db);
   mmdb = GenMomDM_gen_mmdb(univ, da, db);

   dm = new unordered_map<UtilDate*, Matrix*>();
   for(d=da;d->isBefore(db);d=d->next_eom()) {
      X = GenMomDM_gen(univ, mmdb, dmdb, d,K);
      if(X==NULL) continue;
      (*dm)[d] = X;
   }

   ForecastUtils_fprint_split(dm, util_join(".","./data/GenMomDM",K));

   //clean memory
   for(it=dm->begin();it!=dm->end();it++) delete it->second;
   delete dm;
   delete dmdb;
   delete mmdb;
   delete univ;

   return 0;
}
