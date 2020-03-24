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

Matrix* ResReturnDM_gen(CompanyUniverse* univ, Db* mmdb, Db* dmdb, UtilDate* d, int K) {
   printf("%s processing %d\n",__FUNCTION__,d->icode());
   DoubleDbAccount* beta_act = SP500BetaAccount::instance();
   unordered_map<string, double> valm;
   WealthAccount* wdba = WealthAccount::instance();
   unordered_map<string,Object*>* objm = NULL;
   unordered_map<string,Object*>::iterator it;
   Matrix* X = NULL;
   int xval;
   double x, xmkt, beta;

   //determine market return
   {
      string mkt_id = MarketDbUtils_mkt();
      Object* a = univ->obj(mkt_id);
      if(a==NULL) printf("could not find market asset for %d\n",d->icode());
      if(a==NULL) return NULL;
      xmkt = wdba->cumret(a, dmdb, d, d->next_eom(K), xval);
      if(xval>0) printf("could not find market asset return for %d\n",d->icode());
      if(xval>0) return NULL;
   }

   objm = univ->objm();
   for(it=objm->begin();it!=objm->end();it++) {
      Object* a = it->second;
      beta = mmdb->ddba(a, d, d, beta_act, xval);
      if(xval>0) continue;
      x = wdba->cumret(a, dmdb, d, d->next_eom(K), xval);
      if(xval>0) continue;
      x = x - beta * xmkt;
      valm[a->id()] = x;
   }

   X = Matrix::instance_col(&valm, util_join(".","ResReturns",K));

   return X;
}


Db* ResReturnDM_gen_mmdb(CompanyUniverse* univ, UtilDate* da, UtilDate* db) {
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


Db* ResReturnDM_gen_dmdb(CompanyUniverse* univ, UtilDate* da, UtilDate* db) {
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

int ResReturnDM_main() {
   CompanyUniverse* univ = NULL;
   Db* dmdb = NULL;
   Db* mmdb = NULL;
   unordered_map<UtilDate*,Matrix*>* dm = NULL;
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
   dmdb = ResReturnDM_gen_dmdb(univ, da, db);
   mmdb = ResReturnDM_gen_mmdb(univ, da, db);

   dm = new unordered_map<UtilDate*, Matrix*>();
   for(d=da;d->isBefore(db);d=d->next_eom()) {
      X = ResReturnDM_gen(univ, mmdb, dmdb, d,K);
      if(X==NULL) continue;
      (*dm)[d] = X;
   }

   ForecastUtils_fprint_split(dm, util_join(".","./data/ResReturnDM",K));

   //clean memory
   for(it=dm->begin();it!=dm->end();it++) delete it->second;
   delete dm;
   delete dmdb;
   delete mmdb;
   delete univ;

   return 0;
}
