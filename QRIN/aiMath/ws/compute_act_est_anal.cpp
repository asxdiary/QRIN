#include <iomanip>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "pkgMath.hpp"
#include "Matrix.hpp"
#include "DatedMatrix.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMath;

int compute_act_est_anal(int argc, char* argv[]) {
   int val = 0;

   UtilDate* da = NULL;
   UtilDate* db = NULL;
   string act_path, est_path, ofname;

   {
      int t = 2;

      if(argc<7) err_msg("Usage: <cmd> act_est_anal act_path est_path ofname da db");
      act_path = argv[t++];
      est_path = argv[t++];
      ofname = argv[t++];
      da = UtilDate::instance(argv[t++]);
      db = UtilDate::instance(argv[t++]);
   }

   return val;
}

