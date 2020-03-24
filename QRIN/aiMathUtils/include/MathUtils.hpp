// Name:     MathUtils.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_MathUtils_hpp
#define ASX_MathUtils_hpp

#include "Utils.hpp"
#include "Object.hpp"
#include "Global.hpp"
#include "Matrix.hpp"

using namespace std;
using namespace aiMath;

namespace aiMathUtils {

   //scalar functions
   double sigmoid(double x);

   //ARRAY FUNCTIONS

   double* mathutil_copy(double* x, int n);


   //STATISTICAL ROUTINES
   
   void mathutil_winsorize(double* vec, int n, double alpha1, double alpha2);
   double mathutil_mean(double* x, int n);
   double mathutil_std(double* x, int n, double* meanp, Matrix* Delta, bool inv_flag);
   double mathutil_pct(Matrix* x, const double eta);
   double mathutil_pct(Matrix* x, const double eta, Matrix* Delta);

   //LINEAR ALGEBRA ROUTINES

   /** Compute y = X*f + u */
   Matrix* mathutil_Xfpu(Matrix* X, Matrix* f, Matrix* u);
   /** Compute u = y - X*f */
   Matrix* mathutil_ymXf(Matrix* y, Matrix* X, Matrix* f);

   /** Compute X = Diag (A * B * A.t + diag(C) */
   Matrix* mathutil_diag_ABAT_p_diagC(Matrix* A, Matrix* B, Matrix* C=NULL);

   //Matrix utilities
   
   /** This function removes those rows of X and xvalM for which the mean 
    * row value of xvalM computing using Delta is strictly positive */
   set<int>* mathutil_strict_filter(Matrix*& X, Matrix*& xvalM, Matrix* Delta=NULL);

   /** This function removes those rows of X and xvalM for which all of the
    * elements of xvalM in columns cS have positive values */
   set<int>* mathutil_soft_filter(Matrix*& X, Matrix*& xvalM, list<int>* cS=NULL);

   //This function populates the Delta matrix with 1 for elements in cL
   void mathutil_supportvector(list<int>* cL, Matrix*& Delta);


   //This function lifts matrix c using the mapping specified in clsm
   //Key Functionality:
   //for(int i=0;i<clsm->m();i++) {
   //   for(int j=0;j<c->n();j++) lcX[i][j] = cX[int(clsmX[i][0])][j];
   //}
   Matrix* mathutil_lift(Matrix* c, Matrix* clsm);

};

#endif


