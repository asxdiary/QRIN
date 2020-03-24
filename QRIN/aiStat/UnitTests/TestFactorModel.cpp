#include <iomanip>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "TestFactorModel.hpp"
#include "Matrix.hpp"
#include "FactorModel.hpp"
#include "Regression.hpp"
#include "StatUtils.hpp"
#include "MathUtils.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMath;
using namespace aiStat;
using namespace aiStatUtils;
using namespace aiMathUtils;

int TestFactorModel_main() {
   printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   string ipfx = "input/TestFactorModel.";
   string opfx = "output/TestFactorModel.";

   {
      FactorModel* ptr = NULL;

      ptr = FactorModel::instance_fscan(ipfx + "ex1");
      ptr->fprint(opfx + "ex1");

      {
         Matrix* y = NULL;
         y = ptr->y()->copy();
         ptr->compute_u();
         ptr->set_y(NULL);
         ptr->compute_y();
         if(!ptr->y()->isEqual(y)) val++;
         //clean memory
         delete y;
      }

      //clean memory
      delete ptr;
   }

   {
      string exS = "ex2";
      FactorModel* ptr = NULL;
      Matrix* tstat = NULL;
      Matrix* _tstat = NULL;
      double R2, _R2;
      int xval;

      ptr = FactorModel::instance_fscan(ipfx + exS);
      _tstat = Matrix::instance_fread_table(ipfx + exS + ".tstat.csv");

      xval = 0;
      tstat = ptr->compute_tstat(NULL, xval);
      R2 = ptr->compute_R2();
      _R2 = 0.733890756727435;

      if(!util_isEqual(R2, _R2)) val++;
      if(!tstat->isEqual(_tstat)) val++;

      //clean memory
      delete ptr;
      delete tstat;
      delete _tstat;
   }

   return val;
}

