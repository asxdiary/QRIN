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
#include "MarketCapAccount.hpp"

using namespace aiFin;
using namespace aiForecastUtils;
using namespace aiMarketFields;

Matrix* McapDM_gen(CompanyUniverse* univ, Db* dmdb, UtilDate* d) {
   unordered_map<string, double> valm;
   MarketCapAccount* dba = MarketCapAccount::instance();
   unordered_map<string,Object*>* objm = NULL;
   unordered_map<string,Object*>::iterator it;
   Matrix* X = NULL;
   int xval;
   double x;

   objm = univ->objm();
   for(it=objm->begin();it!=objm->end();it++) {
      Object* dbobj = it->second;
      ObjectDb* odb = NULL;

      odb = dmdb->odb_closest_le(dbobj, d, d->prev_eom(1), d, d->prev_eom(1),true, xval);
      if(xval>0 || odb==NULL) continue;
      x = odb->ddba(dbobj, odb->end_d(), odb->dh(), dba, xval);
      if(xval>0) continue;

      valm[dbobj->id()] = x;
   }

   X = Matrix::instance_col(&valm, dba->id());

   return X;
}

Db* McapDM_gen_dmdb(CompanyUniverse* univ, UtilDate* da, UtilDate* db) {
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

int McapDM_main() {
   CompanyUniverse* univ = NULL;
   Db* dmdb = NULL;
   unordered_map<UtilDate*,Matrix*>* dm = NULL;
   unordered_map<UtilDate*,Matrix*>::iterator it;
   UtilDate* da = NULL;
   UtilDate* db = NULL;
   UtilDate* d = NULL;
   Matrix* X = NULL;

   univ = CompanyUniverse::instance(CompanyIdentifier::AIID);
   da = UtilDate::eom(2005,12);
   db = UtilDate::eom(2018,6);
   dmdb = McapDM_gen_dmdb(univ, da, db);

   dm = new unordered_map<UtilDate*, Matrix*>();
   for(d=da;d->isBefore(db);d=d->next_eom()) {
      X = McapDM_gen(univ, dmdb, d);
      if(X==NULL) continue;
      (*dm)[d] = X;
   }

   ForecastUtils_fprint_split(dm, "./data/McapDM");

   //clean memory
   for(it=dm->begin();it!=dm->end();it++) delete it->second;
   delete dm;
   delete dmdb;
   delete univ;

   return 0;
}
