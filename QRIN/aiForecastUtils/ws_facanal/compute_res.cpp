#include "Utils.hpp"
#include "DatedMatrix.hpp"
#include "Regression.hpp"
#include "MathUtils.hpp"

using namespace aiMath;
using namespace aiUtils;
using namespace aiStatUtils;
using namespace aiMathUtils;

int compute_res_main(int argc, char* argv[]) {
   UtilDate* da = UtilDate::eom(2005,12);
   UtilDate* db = UtilDate::eom(2018,5);

   DatedMatrix* dm1= NULL;
   DatedMatrix* dm2= NULL;
   DatedMatrix* resdm = NULL;
   list<DatedMatrix*> dmL;
   string path1, path2, opath;

   {
      int t;
      if(argc<5) err_msg("Usage: <cmd> <prog> <fc-location-1> <fc-location-2> <output-res-location>");

      t = 2;
      path1 = argv[t++];
      path2 = argv[t++];
      opath = argv[t++];
   }

   {
      string fname;

      dm1 = DatedMatrix::fscan_eom(path1, da, db, "dm1", false);
      dm1->set_id("dm1");

      dm2 = DatedMatrix::fscan_eom(path2, da, db, "dm2", false);
      dm2->set_id("dm2");
   }

   resdm = DatedMatrix::instance();
   resdm->set_id("res");

   {
      UtilDate* d = NULL;
      string* pfx = NULL;

      pfx = new string[3];
      pfx[0] = "Y"; pfx[1] = "e"; pfx[2] = "X";

      for(d=da;d->isBefore(db);d=d->next_eom()) {
         Matrix* Y = dm1->dm(d);
         Matrix* X = dm2->dm(d);
         Matrix* tmp = NULL;
         Matrix* regY = NULL;
         Matrix* regX = NULL;
         Matrix* e = NULL;
         set<int> cS;
         Regression* reg = NULL;

         e = Matrix::ones(X->m(),1);
         e->copynames(X,true,false);
         e->set_cmap_cimap(0,"intc");

         tmp = Matrix::concat3_col(Y,e,X,pfx);
         cS.insert(1);
         cS.insert(2);
         regY = tmp->col(0);
         regX = tmp->sub(NULL,&cS);

         if(Y->n()!=1) err_msg("Y->n()!=1");
         reg = Regression::instance();
         reg->configure(regY, regX, NULL);
         reg->algo_exec();
         resdm->add(d, mathutil_ymXf(regY,regX,reg->f()));

         //clean memory
         delete tmp;
         delete e;
         delete regY;
         delete regX;
         delete reg;
      }

   }

   resdm->fprint(opath);

   //clean memory
   delete dm1;
   delete dm2;

   return 0;
}

