#include "Utils.hpp"
#include "DatedMatrix.hpp"

using namespace aiMath;
using namespace aiUtils;

int tmp_main() {
   DatedMatrix* ds1dm= NULL;
   DatedMatrix* ds2dm= NULL;
   list<DatedMatrix*> dmL;

   {
      UtilDate* da = UtilDate::eom(2005,12);
      UtilDate* db = UtilDate::eom(2018,1);
      string fname;

      fname = "/home/asx/COIN_Greco8_mna_OrthoF_rfixed2/aiForecastGen/UnitTests/glam/glam";
      ds1dm = DatedMatrix::fscan_eom(fname, da, db, "glam", false);
      ds1dm->set_id("glam");

      fname = "/home/asx/COIN_Greco8_mna_OrthoF_rfixed2/aiForecastGen/UnitTests/glam/glam";
      ds2dm = DatedMatrix::fscan_eom(fname, da, db, "glam_copy", false);
      ds2dm->set_id("glam_copy");
   }

   for(int lag=3;lag<=12;lag+=3) {
      DatedMatrix* dm2 = ds1dm->eom_lag(lag);
      DatedMatrix** dm1A = ds1dm->bucketizeA(10);
      DatedMatrix** dm2A = dm2->bucketizeA(4);
      Matrix** tmpA = NULL;
      Matrix* tmp = NULL;
      string fname;
      int t;

      fname = util_join(".","./output/anal",lag,"csv");

      tmpA = new Matrix*[4];
      t = 0;
      tmpA[t++] = dm2A[1]->csanal(dm1A[0]);
      tmpA[t++] = dm2A[1]->csanal(dm1A[9]);
      tmpA[t++] = dm2A[2]->csanal(dm1A[0]);
      tmpA[t++] = dm2A[2]->csanal(dm1A[9]);

      tmp = Matrix::concat_row(tmpA, 4);
      tmp->fprint_table(fname);

      //clean memory
      delete tmp;
   }

   //clean memory
   delete ds1dm;
   delete ds2dm;

   return 0;
}

