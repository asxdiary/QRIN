#include <unordered_map>
#include "Utils.hpp"
#include "MathUtils.hpp"
#include "StatUtils.hpp"

using namespace aiUtils;
using namespace aiMathUtils;
using namespace aiStatUtils;

int TestMathUtils_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestMathUtils.";
   const string opfx = "output/TestMathUtils.";

   {
      string exS = "WtdPct.ex1.";
      Matrix* X =  NULL;
      Matrix* Delta = NULL;

      X = Matrix::instance_fscan(ipfx + exS + "X");
      Delta = Matrix::instance_fscan(ipfx + exS + "Delta");
      unordered_map<double,double> pm;
      unordered_map<double,double> _pm;
      unordered_map<double,double>::iterator it;
      double eta;

      _pm[1.20]=217259.45980000;
      _pm[-0.10]=7658.02950000;
      _pm[0.25]=103986.29800000;
      _pm[1.00]=217259.45980000;
      _pm[0.00]=7658.02950000;
      _pm[0.70]=116082.48765101;
      _pm[0.50]=110602.55764953;
      _pm[0.30]=105384.72886871;


      eta = 0.3; pm[eta] = mathutil_pct(X, eta, Delta);
      eta = 0.5; pm[eta] = mathutil_pct(X, eta, Delta);
      eta = 0.7; pm[eta] = mathutil_pct(X, eta, Delta);
      eta = 0.0; pm[eta] = mathutil_pct(X, eta, Delta);
      eta = 1.0; pm[eta] = mathutil_pct(X, eta, Delta);
      eta = 0.25; pm[eta] = mathutil_pct(X, eta, NULL);
      eta = -0.1; pm[eta] = mathutil_pct(X, eta, Delta);
      eta = 1.2; pm[eta] = mathutil_pct(X, eta, Delta);
      
      for(it=pm.begin();it!=pm.end();it++) {
         if(!util_isEqual(_pm[eta],pm[eta])) val++;
      }

      //clean memory
      delete X;
      delete Delta;
   }

   {
      string exS = "ex1.";
      Matrix* X = NULL;
      unordered_map<double,double>* _valm = NULL;
      unordered_map<double,double>* valm = NULL;
      double eta;

      X = Matrix::instance_fscan(ipfx + exS + "X");
      util_fscan(ipfx + exS + "valm",_valm);
      valm = new unordered_map<double,double>();

      eta = 0.5; (*valm)[eta] = mathutil_pct(X, eta);
      eta = 0.25; (*valm)[eta] = mathutil_pct(X, eta);
      eta = 0.79; (*valm)[eta] = mathutil_pct(X, eta);

      if(!util_isEqual(valm,_valm)) val++;

      //clean memory
      delete X;
      delete _valm;
      delete valm;
   }

   {
      string exS = "diag_ABAT_p_diagC.";
      Matrix* A = NULL;
      Matrix* B = NULL;
      Matrix* C = NULL;
      Matrix* X = NULL;
      Matrix* _X = NULL;

      A = Matrix::instance_fscan(ipfx + exS + "A");
      B = Matrix::instance_fscan(ipfx + exS + "B");
      C = Matrix::instance_fscan(ipfx + exS + "C");
      _X = Matrix::instance_fscan(ipfx + exS + "X");

      X = mathutil_diag_ABAT_p_diagC(A,B,C);

      if(! X->isEqual(_X) ) val++;

      //clean memory
      delete A;
      delete B;
      delete C;
      delete X;
      delete _X;
   }

   {
      string exS = "strict_filter.ex1.";
      Matrix* X = NULL;
      Matrix* xvalM = NULL;
      Matrix* _X = NULL;
      Matrix* _xvalM = NULL;
      set<int>* S = NULL;

      X = Matrix::instance_fscan(ipfx + exS + "X");
      xvalM = Matrix::instance_fscan(ipfx + exS + "xvalM");
      _X = Matrix::instance_fscan(ipfx + exS + "_X");
      _xvalM = Matrix::instance_fscan(ipfx + exS + "_xvalM");

      S = mathutil_strict_filter(X,xvalM); 

      if(! X->isEqual(_X)) val++;
      if(! xvalM->isEqual(_xvalM)) val++;

      //clean memory
      delete X;
      delete xvalM;
      delete _X;
      delete _xvalM;
      delete S;
   }

   {
      string exS = "strict_filter.ex2.";
      Matrix* X = NULL;
      Matrix* xvalM = NULL;
      Matrix* _X = NULL;
      Matrix* _xvalM = NULL;
      Matrix* Delta = NULL;
      set<int>* S = NULL;
      list<int> L;

      X = Matrix::instance_fscan(ipfx + exS + "X");
      xvalM = Matrix::instance_fscan(ipfx + exS + "xvalM");
      _X = Matrix::instance_fscan(ipfx + exS + "_X");
      _xvalM = Matrix::instance_fscan(ipfx + exS + "_xvalM");

      L.push_back(1);
      L.push_back(2);
      Delta = Matrix::instance(3,1);
      mathutil_supportvector(&L,Delta);

      S = mathutil_strict_filter(X,xvalM,Delta);

      if(! X->isEqual(_X)) val++;
      if(! xvalM->isEqual(_xvalM)) val++;

      //clean memory
      delete X;
      delete xvalM;
      delete _X;
      delete _xvalM;
      delete S;
      delete Delta;
   }

   {
      string exS = "soft_filter.ex1.";
      Matrix* X = NULL;
      Matrix* xvalM = NULL;
      Matrix* _X = NULL;
      Matrix* _xvalM = NULL;
      set<int>* S = NULL;

      X = Matrix::instance_fscan(ipfx + exS + "X");
      xvalM = Matrix::instance_fscan(ipfx + exS + "xvalM");
      _X = Matrix::instance_fscan(ipfx + exS + "_X");
      _xvalM = Matrix::instance_fscan(ipfx + exS + "_xvalM");

      S = mathutil_soft_filter(X,xvalM); 

      if(! X->isEqual(_X)) val++;
      if(! xvalM->isEqual(_xvalM)) val++;

      //clean memory
      delete X;
      delete xvalM;
      delete _X;
      delete _xvalM;
      delete S;
   }

   {
      string exS = "mathutil_lift.ex1.";
      Matrix* X = NULL;
      Matrix* clsm = NULL;
      Matrix* lX = NULL;
      Matrix* _lX = NULL;

      X = Matrix::instance_fread_table(ipfx + exS + "X");
      clsm = Matrix::instance_fread_table(ipfx + exS + "clsm");
      _lX = Matrix::instance_fread_table(ipfx + exS + "lX");

      lX = mathutil_lift(X, clsm);

      if(! lX->isEqual(_lX)) val++;

      //clean memory
      delete X;
      delete clsm;
      delete lX;
      delete _lX;
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

