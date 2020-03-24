#include "Utils.hpp"
#include "DatedMatrix.hpp"

using namespace aiMath;
using namespace aiUtils;

int compute_csanal_main(int argc, char* argv[]) {
   DatedMatrix* dm1= NULL;
   DatedMatrix* dm2= NULL;
   list<DatedMatrix*> dmL;
   string path1, path2, opath;

   {
      int t;
      if(argc<5) err_msg("Usage: <cmd> <prog> <fc-location-1> <fc-location-2> <output-location>");

      t = 2;
      path1 = argv[t++];
      path2 = argv[t++];
      opath = argv[t++];
   }

   {
      UtilDate* da = UtilDate::eom(2005,12);
      UtilDate* db = UtilDate::eom(2019,1);
      string fname;

      dm1 = DatedMatrix::fscan_eom(path1, da, db, "dm1", false);
      dm1->set_id("dm1");

      dm2 = DatedMatrix::fscan_eom(path2, da, db, "dm2", false);
      dm2->set_id("dm2");
   }

   {
      Matrix* tmp = NULL;
      set<string> analS;

      //analS.insert("colmatch");
      analS.insert("loginfo");
      analS.insert("p_correl");
      analS.insert("sp_correl");
      analS.insert("sigreg");
      tmp = dm1->csanal(dm2, &analS);
      tmp->fprint_table(opath);
      delete tmp; tmp = NULL;

      //clean memory
      delete tmp;
   }

   //clean memory
   delete dm1;
   delete dm2;

   return 0;
}

