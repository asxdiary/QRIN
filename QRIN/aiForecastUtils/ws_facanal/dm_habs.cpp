#include "Utils.hpp"
#include "DatedMatrix.hpp"

using namespace aiMath;
using namespace aiUtils;

int dm_habs_main(int argc, char* argv[]) {
   DatedMatrix* dm = NULL;
   list<DatedMatrix*> dmL;
   string path1, opath;

   {
      int t;
      if(argc<4) err_msg("Usage: dm_habs <prog> <fc-location-1> <output-location>");

      t = 2;
      path1 = argv[t++];
      opath = argv[t++];
   }

   {
      UtilDate* da = UtilDate::eom(2005,12);
      UtilDate* db = UtilDate::eom(2017,1);

      dm = DatedMatrix::fscan_eom(path1, da, db, "dm", false);
      dm->_habs();
   }

   dm->fprint(opath);

   //clean memory
   delete dm;

   return 0;
}

