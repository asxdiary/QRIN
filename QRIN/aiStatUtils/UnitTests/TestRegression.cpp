#include "Regression.hpp"
#include "StatUtils.hpp"

using namespace aiStatUtils;

int TestRegression_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestRegression.";
   const string opfx = "output/TestRegression.";

   {
      string exS = "ex1.";
      Matrix* X = NULL;
      Matrix* y = NULL;
      Matrix* Delta = NULL;
      Matrix* _fDelta = NULL;
      Matrix* _f = NULL;
      Regression* ptr = NULL;
      FactorModel* mdl = NULL;
      RegressionKernel* _fk = NULL;
      RegressionKernel* fk = NULL;

      X = Matrix::instance_fscan(ipfx + "ex1.X");
      y = Matrix::instance_fscan(ipfx + "ex1.y");
      Delta = Matrix::instance_fscan(ipfx + "ex1.Delta");
      _fDelta = Matrix::instance_fscan(ipfx + "ex1.fDelta");
      _f = Matrix::instance_fscan(ipfx + "ex1.f");
      _fk = RegressionKernel::instance_fscan(ipfx + exS + "fk");

      ptr = Regression::instance();
      ptr->set_debug_info(true,opfx + exS + "Debug");
      ptr->set_debug_id("debug_instance");
      ptr->configure(y, X, Delta);
      ptr->algo_exec();
      mdl = ptr->extract_mdl();
      delete mdl; mdl = NULL;
      if(! ptr->f()->isEqual(_fDelta)) val++;
      ptr->reset();

      ptr->configure(y, X, Delta);
      ptr->algo_exec();
      mdl = ptr->extract_mdl();
      delete mdl; mdl = NULL;
      if(! ptr->f()->isEqual(_fDelta)) val++;
      ptr->reset();

      ptr->configure(y, X, NULL);
      ptr->algo_exec();
      mdl = ptr->extract_mdl();
      if(! ptr->fk()->isEqual(_fk)) val++;
      delete mdl; mdl = NULL;
      if(! ptr->f()->isEqual(_f)) val++;
      ptr->reset();

      ptr->configure(y, X, NULL);
      ptr->algo_exec();
      mdl = ptr->extract_mdl();
      fk = ptr->extract_fk();
      if(! fk->isEqual(_fk)) val++;
      {
         Matrix* X = NULL;
         Matrix* _fc = NULL;
         Matrix* _m2 = NULL;

         X = Matrix::instance_fscan(ipfx + exS + "RegressionKernel.ex1.X");
         fk->configure(X,NULL);
         fk->algo_exec();
         _fc = Matrix::instance_fscan(ipfx + exS + "RegressionKernel.ex1.fc");
         _m2 = Matrix::instance_fscan(ipfx + exS + "RegressionKernel.ex1.m2");
         if(! fk->mdl()->isEqual(_fc)) val++;
         if(! fk->m2()->isEqual(_m2)) val++;
         fk->reset();

         //clean memory
         delete X;
         delete _fc;
         delete _m2;
      }
      delete mdl; mdl = NULL;
      delete fk; fk = NULL;
      if(! ptr->f()->isEqual(_f)) val++;
      ptr->reset();

      //clean memory
      delete ptr;
      delete X;
      delete y;
      delete Delta;
      delete _f;
      delete _fDelta;
      delete _fk;
      delete mdl;
   }

   return val;
}

