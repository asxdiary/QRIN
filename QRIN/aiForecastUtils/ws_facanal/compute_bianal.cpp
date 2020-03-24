#include "Utils.hpp"
#include "DatedMatrix.hpp"

using namespace aiMath;
using namespace aiUtils;

int compute_bianal_main(int argc, char* argv[]) {
   DatedMatrix* dm1= NULL;
   DatedMatrix* dm2= NULL;
   Matrix* X = NULL;
   list<DatedMatrix*> dmL;
   string path1, path2, opath;
   int K;

   {
      int t;
      if(argc<5) err_msg("Usage: <cmd> bianal <fc-location-bucketize> <fc-location-anal> <output-location>");

      t = 2;
      path1 = argv[t++];
      path2 = argv[t++];
      opath = argv[t++];

      K = 5;
   }

   {
      UtilDate* da = UtilDate::eom(2005,12);
      UtilDate* db = UtilDate::eom(2017,1);
      string fname;

      dm1 = DatedMatrix::fscan_eom(path1, da, db, "dm1", false);
      dm1->set_id("dm1");

      dm2 = DatedMatrix::fscan_eom(path2, da, db, "dm2", false);
      dm2->set_id("dm2");

      {
         DatedMatrix* tmp = dm1->univfilter(dm2);
         delete dm1; dm1 = tmp; tmp = NULL;
         dm1->set_id("dm1");
      }
   }

   X = dm2->unianal(dm1, K, -1);
   X->fprint_table(opath);

   //clean memory
   delete dm1;
   delete dm2;
   delete X;

   return 0;
}

