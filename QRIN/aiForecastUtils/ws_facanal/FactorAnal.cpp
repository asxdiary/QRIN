#include "Utils.hpp"
#include "DatedMatrix.hpp"

using namespace aiMath;
using namespace aiUtils;

int FactorAnal_main() {
   DatedMatrix* pmomdm = NULL;
   DatedMatrix* rpmomdm = NULL;
   DatedMatrix* n1mdm = NULL;
   list<DatedMatrix*> dmL;

   {
      UtilDate* da = UtilDate::eom(2005,12);
      UtilDate* db = UtilDate::eom(2017,11);
      DatedMatrix* dm = NULL;
      string fname;

      fname = "/home/ai_data/asxdm/20180119/retL12M/";
      dm = DatedMatrix::fscan_eom(fname, da, db);
      pmomdm = dm->project("totretL12M"); pmomdm->set_id("pmom");
      rpmomdm = dm->project("resretL12M"); rpmomdm->set_id("rpmom");
      delete dm; dm = NULL;

      fname = "/home/ai_data/asxdm/20180119/retN1M/";
      n1mdm = DatedMatrix::fscan_eom(fname, da, db);

      dmL.push_back(pmomdm);
      dmL.push_back(rpmomdm);
   }

   {
      int nb = 5;
      pmomdm->bucketizeL(nb,0,&dmL);
      rpmomdm->bucketizeL(nb,0,&dmL);
   }

   {
      Matrix* csanal = NULL;

      csanal = n1mdm->csanal(&dmL);
      csanal->fprint_table("./output/csanal.csv");
      
      //clean memory
      delete csanal;
   }

   //clean memory
   delete pmomdm;
   delete rpmomdm;
   delete n1mdm;

   return 0;
}

