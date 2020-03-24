#include "Utils.hpp"
#include "DatedMatrix.hpp"

using namespace aiMath;
using namespace aiUtils;

int compute_aggdm_main(int argc, char* argv[]) {
   DatedMatrix* dm = NULL;
   Matrix* X = NULL;
   string path, opath;
   UtilDate* s_d = NULL;
   UtilDate* e_d = NULL;

   {
      int t;
      if(argc<5) err_msg("Usage: <cmd> aggdm <fc-location> <start-date> <end-date> <output-location>");

      t = 2;
      path = argv[t++];
      s_d = UtilDate::instance( argv[t++] );
      e_d = UtilDate::instance( argv[t++] );
      opath = argv[t++];
   }

   {
      UtilDate* da = s_d;
      UtilDate* db = e_d;
      string fname;

      dm = DatedMatrix::fscan_eom(path, da, db, "dm", false);
      dm->set_id("dm");
   }

   X = dm->concat();
   X->fprint_table(opath);

   //clean memory
   delete dm;
   delete X;

   return 0;
}

