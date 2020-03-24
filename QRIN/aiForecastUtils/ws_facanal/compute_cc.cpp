#include "Utils.hpp"
#include "DatedMatrix.hpp"

using namespace aiMath;
using namespace aiUtils;

int compute_cc_main(int argc, char* argv[]) {
   DatedMatrix* dm1= NULL;
   list<DatedMatrix*> dmL;
   string path1, opath;

   {
      int t;
      if(argc<4) err_msg("Usage: <cmd> <prog> <fc-location-1> <opath>");

      t = 2;
      path1 = argv[t++];
      opath = argv[t++];
   }

   {
      UtilDate* da = UtilDate::eom(2005,12);
      UtilDate* db = UtilDate::eom(2019,8);
      string fname;

      dm1 = DatedMatrix::fscan_eom(path1, da, db, "dm1", false);
      dm1->set_id("dm1");
   }

   {
      Matrix* tmp = NULL;

      tmp = dm1->cc(true);
      tmp->fprint_table(opath);
      delete tmp; tmp = NULL;

      //clean memory
      delete tmp;
   }

   //clean memory
   delete dm1;

   return 0;
}

