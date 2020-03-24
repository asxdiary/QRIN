#include "Utils.hpp"
#include "Matrix.hpp"
#include "ForecastUtils.hpp"
#include "Db.hpp"
#include "DailyMarketDbGen.hpp"
#include "Global.hpp"
#include "CompanyIdentifier.hpp"
#include "CompanyUniverse.hpp"
#include "TotalReturnsAccount.hpp"
#include "SP500BetaAccount.hpp"
#include "WealthAccount.hpp"

using namespace aiFin;
using namespace aiForecastUtils;
using namespace aiMarketFields;

Matrix* MomDM_gen(CompanyUniverse* univ, Db* dmdb, UtilDate* d, int K) {
   unordered_map<string, double> valm;
   WealthAccount* wdba = WealthAccount::instance();
   unordered_map<string,Object*>* objm = NULL;
   unordered_map<string,Object*>::iterator it;
   Matrix* X = NULL;
   int xval;
   double x;

   objm = univ->objm();
   for(it=objm->begin();it!=objm->end();it++) {
      Object* a = it->second;
      x = wdba->cumret(a, dmdb, d->next_eom(K), d, xval);
      printf("%s %d %d\n",a->id().c_str(),d->next_eom(K)->icode(),d->icode());
      if(xval>0) continue;
      valm[a->id()] = x;
   }

   X = Matrix::instance_col(&valm, util_join(".","TotalReturns",K));

   return X;
}

Db* MomDM_gen_dmdb(CompanyUniverse* univ, UtilDate* da, UtilDate* db) {
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

int MomDM_main() {
   CompanyUniverse* univ = NULL;
   Db* dmdb = NULL;
   unordered_map<UtilDate*,Matrix*>* dm = NULL;
   unordered_map<UtilDate*,Matrix*>::iterator it;
   UtilDate* da = NULL;
   UtilDate* db = NULL;
   UtilDate* d = NULL;
   Matrix* X = NULL;
   int K;

   K = -12;

   univ = CompanyUniverse::instance(CompanyIdentifier::AIID);
   da = UtilDate::eom(2002,12);
   db = UtilDate::eom(2018,1);
   dmdb = MomDM_gen_dmdb(univ, da, db);

   dm = new unordered_map<UtilDate*, Matrix*>();
   for(d=da;d->isBefore(db);d=d->next_eom()) {
      X = MomDM_gen(univ, dmdb, d,K);
      if(X==NULL) continue;
      (*dm)[d] = X;
   }

   ForecastUtils_fprint_split(dm, util_join(".","./data/momdm",K));

   //clean memory
   for(it=dm->begin();it!=dm->end();it++) delete it->second;
   delete dm;
   delete dmdb;
   delete univ;

   return 0;
}
