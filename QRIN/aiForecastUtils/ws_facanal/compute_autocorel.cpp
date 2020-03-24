#include "Utils.hpp"
#include "DatedMatrix.hpp"

using namespace aiMath;
using namespace aiUtils;

int compute_autocorel_main(int argc, char* argv[]) {
   DatedMatrix* dm1= NULL;
   list<DatedMatrix*> dmL;
   string path1, opfx;
   int nlag;

   {
      int t;
      if(argc<5) err_msg("Usage: <cmd> <prog> <fc-location-1> <nlag> <output-location>");

      t = 2;
      path1 = argv[t++];
      nlag = atoi(argv[t++]);
      opfx = argv[t++];
   }

   {
      UtilDate* da = UtilDate::eom(2005,12);
      UtilDate* db = UtilDate::eom(2017,1);
      string fname;

      dm1 = DatedMatrix::fscan_eom(path1, da, db, "dm1", false);
      dm1->set_id("dm1");
   }

   {
      Matrix* tmp = NULL;
      set<string> analS;

      analS.insert("p_correl");
      analS.insert("sp_correl");

      tmp = dm1->eom_autoanal(nlag, &analS);
      tmp->fprint_table(opfx);
      delete tmp; tmp = NULL;

      //clean memory
      delete tmp;
   }

   //clean memory
   delete dm1;

   return 0;
}

