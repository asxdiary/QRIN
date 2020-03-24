#include "Utils.hpp"
#include "UtilDate.hpp"
#include "Matrix.hpp"

using namespace aiMath;
using namespace aiUtils;

int chgdate_preveom_main(int argc, char* argv[]) {
   Matrix* X = NULL;
   string path, opath;
   UtilDate* d = NULL;

   {
      int t;
      if(argc<5) err_msg("Usage: <cmd> chgdate_preveom <input-location> <output-path> <date>");

      t = 2;
      path = argv[t++];
      opath = argv[t++];
      d = UtilDate::instance(argv[t++]);
      d = UtilDate::eom(d)->prev_eom();
   }

   {
      string fname;

      fname = path;
      X = Matrix::instance_fread_table(fname);
      fname = opath + d->id() + ".csv";
      X->fprint_table(fname);
   }

   //clean memory
   delete X;

   return 0;
}

