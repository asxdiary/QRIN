#include "Utils.hpp"
#include "DatedMatrix.hpp"

using namespace aiMath;
using namespace aiUtils;

int compute_wtcsanal_main(int argc, char* argv[]) {
   DatedMatrix* dm1= NULL;
   DatedMatrix* dm2= NULL;
   DatedMatrix* dmD= NULL;
   list<DatedMatrix*> dmL;
   list<DatedMatrix*> dmDL;
   string path1, path2, pathD, opath;

   {
      int t;
      if(argc<6) err_msg("Usage: <cmd> <prog> <fc-location-1> <fc-location-2> <Delta-location> <output-location>");

      t = 2;
      path1 = argv[t++];
      path2 = argv[t++];
      pathD = argv[t++];
      opath = argv[t++];
   }

   {
      UtilDate* da = UtilDate::eom(2005,12);
      UtilDate* db = UtilDate::eom(2018,9);
      string fname;

      dm1 = DatedMatrix::fscan_eom(path1, da, db, "dm1", false);
      dm1->set_id("dm1");

      dm2 = DatedMatrix::fscan_eom(path2, da, db, "dm2", false);
      dm2->set_id("dm2");

      dmD = DatedMatrix::fscan_eom(pathD, da, db, "dmD", false);
      dmD->set_id("dmD");
   }

   {
      string* cmap = dmD->cmap();
      int nc = dmD->nc();
      DatedMatrix* tmp = NULL;

      for(int t=0;t<nc;t++) {
         dmDL.push_back(tmp = dmD->project(t));
         tmp->set_id(cmap[t]);
      }
   }

   {
      Matrix* tmp = NULL;
      set<string> analS;

      analS.insert("colmatch");
      analS.insert("loginfo");
      analS.insert("sigreg");
      tmp = dm1->csanal(dm2, &analS, &dmDL);
      tmp->fprint_table(opath);

      //clean memory
      delete tmp;
   }

   //clean memory
   delete dm1;
   delete dm2;
   delete dmD;
   for(list<DatedMatrix*>::iterator it=dmDL.begin();it!=dmDL.end();it++) delete *it;

   return 0;
}

