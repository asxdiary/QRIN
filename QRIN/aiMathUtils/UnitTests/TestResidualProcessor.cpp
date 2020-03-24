#include "Utils.hpp"
#include "ResidualProcessor.hpp"

using namespace aiUtils;
using namespace aiMathUtils;

int TestResidualProcessor_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestResidualProcessor.";
   const string opfx = "output/TestResidualProcessor.";

   {
      string exS = "ex1";
      Matrix* X = NULL;
      Matrix* W = NULL;
      Matrix* Delta = NULL;
      Matrix* Y = NULL;
      Matrix* _Y = NULL;
      ResidualProcessor* ptr = NULL;

      X = Matrix::instance_fscan(ipfx + exS + ".X");
      W = Matrix::instance_fscan(ipfx + exS + ".W");
      _Y = Matrix::instance_fscan(ipfx + exS + ".Y");

      ptr = ResidualProcessor::instance(false);
      ptr->configure(X,W,Delta);
      ptr->algo_exec();
      Y = ptr->extract_mdl();
      if(!Y->isEqual(_Y)) val++;

      //clean memory
      delete X;
      delete W;
      delete Y;
      delete _Y;
      delete ptr;
   }

   return val;
}

