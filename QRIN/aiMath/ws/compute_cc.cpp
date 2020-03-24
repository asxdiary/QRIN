#include <iomanip>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "pkgMath.hpp"
#include "Matrix.hpp"
#include "DatedMatrix.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMath;

int compute_cc(int argc, char* argv[]) {
   int val = 0;

   UtilDate* da = NULL;
   UtilDate* db = NULL;
   DatedMatrix* holdings = NULL;
   DatedMatrix* cc = NULL;
   Matrix* X = NULL;
   string ifname, ofname;

   {
      int t = 2;

      if(argc<6) err_msg("Usage: <cmd> cc ifname da db ofname");
      ifname = argv[t++];
      da = UtilDate::instance(argv[t++]);
      db = UtilDate::instance(argv[t++]);
      ofname = argv[t++];
   }

   holdings = DatedMatrix::fscan_eom(ifname, da, db, "holdings", false);

   //compute cc
   {
      UtilDate* d = NULL;
      Matrix* h = NULL;
      Matrix* c = NULL;

      cc = DatedMatrix::instance();
      for(d=da;d->isBefore(db);d=d->next_eom()) {
         h = holdings->dm(d); h->_habs();
         h->_mult(1.0/h->max());
         c = Matrix::instance(1,1);
         c->X()[0][0] = h->cc(false,0);
         cc->add(d, c);
      }

   }

   X = cc->concat();
   X->fprint_table(ofname);

   //clean memory
   delete holdings;
   delete cc;
   delete X;

   return val;
}

