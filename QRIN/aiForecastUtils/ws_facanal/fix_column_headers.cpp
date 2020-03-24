#include "Utils.hpp"
#include "DatedMatrix.hpp"

using namespace aiMath;
using namespace aiUtils;

int fix_column_headers_main(int argc, char* argv[]) {
   list<DatedMatrix*> dmL;
   string path1;

   {
      int t;
      if(argc<3) err_msg("Usage: <cmd> <prog> <fc-location-1>");

      t = 2;
      path1 = argv[t++];
   }

   {
      UtilDate* da = UtilDate::eom(2005,12);
      UtilDate* db = UtilDate::eom(2018,6);
      UtilDate* d = NULL;
      string fname;

      for(d=da;d->isBefore(db);d=d->next_eom()) {
         fname = path1 + d->id() + ".csv";
         Matrix* X = Matrix::instance_fread_table(fname);
         X->set_cmap_cimap(0,"col0");
         X->fprint_table(fname);
         delete X;
      }

   }

   return 0;
}

