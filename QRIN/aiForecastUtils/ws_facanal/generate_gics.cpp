#include "Utils.hpp"
#include "DatedMatrix.hpp"

using namespace aiMath;
using namespace aiUtils;

int generate_gics_main(int argc, char* argv[]) {
   list<DatedMatrix*> dmL;
   string path1, opfx;

   {
      int t;
      if(argc<4) err_msg("Usage: <cmd> <prog> <fc-location-1> <output-location>");

      t = 2;
      path1 = argv[t++];
      opfx = argv[t++];
   }

   {
      UtilDate* da = UtilDate::eom(2005,12);
      UtilDate* db = UtilDate::eom(2018,6);
      UtilDate* d = NULL;
      string fname;

      for(d=da;d->isBefore(db);d=d->next_eom()) {
         fname = path1 + "/fcfk." + d->id() + ".gcode";
         Matrix* X = Matrix::instance_fscan(fname);
         X->fprint_table(opfx + "gics." + d->id() + ".csv");
         delete X;
      }

   }

   return 0;
}

