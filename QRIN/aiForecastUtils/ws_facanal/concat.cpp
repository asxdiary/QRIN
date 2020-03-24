#include "Utils.hpp"
#include "DatedMatrix.hpp"

using namespace aiMath;
using namespace aiUtils;

int concat_main(int argc, char* argv[]) {
   DatedMatrix* dm = NULL;
   Matrix* X = NULL;
   list<DatedMatrix*> dmL;
   string path1, opath;
   UtilDate* s_d = NULL;
   UtilDate* e_d = NULL;

   {
      int t;
      if(argc<6) err_msg("Usage: concat <prog> <fc-location-1> <output-location> <start-date> <end-date>");

      t = 2;
      path1 = argv[t++];
      opath = argv[t++];
      s_d = UtilDate::instance(argv[t++]);
      e_d = UtilDate::instance(argv[t++]);
   }

   {
      UtilDate* da = s_d;
      UtilDate* db = e_d;

      dm = DatedMatrix::fscan_eom(path1, da, db, "dm", false);
   }

   X = dm->concat();
   X->fprint_table(opath);

   //clean memory
   delete dm;
   delete X;

   return 0;
}

