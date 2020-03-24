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
#include "MarketDbUtils.hpp"

using namespace aiFin;
using namespace aiForecastUtils;
using namespace aiMarketFields;
using namespace aiMarketDbUtils;

Matrix* BetaDM_gen(CompanyUniverse* univ, Db* mmdb, UtilDate* d) {
   printf("%s processing %d\n",__FUNCTION__,d->icode());
   DoubleDbAccount* beta_act = SP500BetaAccount::instance();
   unordered_map<string, double> valm;
   unordered_map<string,Object*>* objm = NULL;
   unordered_map<string,Object*>::iterator it;
   Matrix* X = NULL;
   int xval;
   double beta;

   objm = univ->objm();
   for(it=objm->begin();it!=objm->end();it++) {
      Object* a = it->second;
      beta = mmdb->ddba(a, d, d, beta_act, xval);
      if(xval>0) continue;
      valm[a->id()] = beta;
   }

   X = Matrix::instance_col(&valm, "Beta");

   return X;
}


Db* BetaDM_gen_mmdb(CompanyUniverse* univ, UtilDate* da, UtilDate* db) {
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


int BetaDM_main() {
   CompanyUniverse* univ = NULL;
   Db* mmdb = NULL;
   unordered_map<UtilDate*,Matrix*>* dm = NULL;
   unordered_map<UtilDate*,Matrix*>::iterator it;
   UtilDate* da = NULL;
   UtilDate* db = NULL;
   UtilDate* d = NULL;
   Matrix* X = NULL;

   univ = CompanyUniverse::instance(CompanyIdentifier::AIID);
   da = UtilDate::eom(2005,12);
   db = UtilDate::eom(2018,1);
   mmdb = BetaDM_gen_mmdb(univ, da, db);

   dm = new unordered_map<UtilDate*, Matrix*>();
   for(d=da;d->isBefore(db);d=d->next_eom()) {
      X = BetaDM_gen(univ, mmdb, d);
      if(X==NULL) continue;
      (*dm)[d] = X;
   }

   ForecastUtils_fprint_split(dm, "./data/BetaDM");

   //clean memory
   for(it=dm->begin();it!=dm->end();it++) delete it->second;
   delete dm;
   delete mmdb;
   delete univ;

   return 0;
}
