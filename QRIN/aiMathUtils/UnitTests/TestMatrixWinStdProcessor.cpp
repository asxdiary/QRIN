#include "Utils.hpp"
#include "MatrixWinStdProcessor.hpp"

using namespace aiUtils;
using namespace aiMathUtils;

int TestMatrixWinStdProcessor_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestMatrixWinStdProcessor.";
   const string opfx = "output/TestMatrixWinStdProcessor.";

   for(int k=0;k<2;k++) {
      if(k==1) continue;
      string exS = "ex1";
      Matrix* X = NULL;
      Matrix* Y = NULL;
      Matrix* _Y = NULL;
      MatrixWinStdProcessor* proc = NULL;
      string fname = opfx + exS + "." + to_string(k);

      X = Matrix::instance_fscan(ipfx + exS);
      proc = MatrixWinStdProcessor::instance(k==1);
      proc->set_debug_info(true,opfx + exS + ".Debug");
      proc->set_debug_id("obj");
      proc->configure(X,NULL);
      proc->algo_exec();
      proc->fprint(fname);
      {
         MatrixWinStdProcessor* ptr = MatrixWinStdProcessor::instance_fscan(fname);
         Matrix* X = ptr->X();

         delete ptr;
         delete X;
      }

      Y = proc->extract_mdl();
      _Y = Matrix::instance_fscan(ipfx + exS + ".Y");

      if(!Y->isEqual(_Y)) val++;

      //clean memory
      delete proc;
      if(k!=1) delete X;
      delete Y;
      delete _Y;
   }

   if(val>0) printf("UnitTest %s failed\n",__FUNCTION__);

   return val;
}

