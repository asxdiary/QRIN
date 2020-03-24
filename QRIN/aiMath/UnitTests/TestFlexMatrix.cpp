#include "Utils.hpp"
#include "FlexMatrix.hpp"
#include "StatUtils.hpp"
#include "DatedMatrix.hpp"

using namespace aiUtils;
using namespace aiMath;
using namespace aiStatUtils;

int TestFlexMatrix_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestFlexMatrix.";
   const string opfx = "output/TestFlexMatrix.";

   {
      string exS = "ex1.";
      Matrix* protomat = NULL;
      FlexMatrix* ptr = NULL;
      Matrix* X = NULL;
      int m, n;

      m = 5;
      n = 10;

      protomat = Matrix::instance(5, 10);
      for(int i=0;i<m;i++) protomat->set_rmap_rimap(i, util_string("row") + util_string(i*i));
      for(int j=0;j<n;j++) protomat->set_cmap_cimap(j, util_string("col") + util_string(j*j));

      ptr = FlexMatrix::instance(protomat);

      X = statutil_rand_normalM(m, n);
      X->copynames(protomat, true, true);
      ptr->add_fm("a", X, protomat->copy());

      X = statutil_rand_normalM(m, n);
      X->copynames(protomat, true, true);
      ptr->add_fm("b", X, protomat->copy());

      ptr->fprint(opfx + exS + "ptr");

      {
         FlexMatrix* ptr2 = FlexMatrix::instance_fscan(opfx + exS + "ptr");
         ptr2->fprint(opfx + exS + "ptr2");
         if(!ptr2->isEqual(ptr)) val++;
         delete ptr2;
      }

      //clean memory
      delete ptr;
   }

   {
      string exS = "ex2/fvix";
      string exS_out = "ex2fvix/fvix";
      string exS_dm_out = "ex2.dm/";
      FlexMatrix* ptr = NULL;
      FlexMatrix* fvix = NULL;
      FlexMatrix* _fvix = NULL;
      DatedMatrix* dm = NULL;
      DatedMatrix* _dm = NULL;

      ptr = FlexMatrix::instance_fscan(ipfx + exS);
      _fvix = FlexMatrix::instance_fscan(ipfx + exS_out);
      fvix = ptr->fvix();

      dm = ptr->dm();
      dm->set_id("dm");
      _dm = DatedMatrix::fscan_eom(ipfx + exS_dm_out, 
                                   UtilDate::eom(2005,12), UtilDate::eom(2017,1),
                                   "dm");
      if(! dm->isEqual(_dm)) val++;

      if(! fvix->isEqual(_fvix)) val++;

      //clean memory
      delete ptr;
      delete fvix;
      delete _fvix;
      delete dm;
      delete _dm;
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

