// Name:     StatUtils.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_StatUtils_hpp
#define ASX_StatUtils_hpp

#include <algorithm>
#include "Utils.hpp"
#include "Object.hpp"
#include "Global.hpp"
#include "Matrix.hpp"

using namespace std;
using namespace aiMath;

namespace aiStatUtils {

   //RANDOM NUMBER UTILITIES
   
   default_random_engine* statutil_rand_engine();

   /** uniform distribution */
   double statutil_rand_uniform(double a=0, double b=1);

   /** N(mu,sigma) */
   double statutil_rand_normal(double mu=0, double sigma=1);
   double* statutil_rand_normalA(const int n, double mu=0, double sigma=1);
   Matrix* statutil_rand_normalM(const int m, const int n, double mu=0, double sigma=1);

   /** N(mu,sigma) */
   double statutil_rand_fattail1(double prob,
                                 double mu1, double sigma1, double mu2, double sigma2);

   /** Random integer */

   //interval = [0,b)
   int statutil_rand_int(int b);

   //interval = [a,b)
   int statutil_rand_int(int a, int b);

   /** Random string */
   string statutil_rand_str(int len=8);

   /** Generate a permutation of numbers in [a,b) */
   int* statutil_rand_range(const int a, const int b);
   
   //Statistical utilities
   
   /** This function computes correlation between j1 and j2 columns
    * of X assuming col_flag = true */
   double statutil_corel(Matrix* X, int j1, int j2, bool col_flag);

};

#endif


