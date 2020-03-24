// Name:     StatUtils.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_StatUtils_cpp
#define ASX_StatUtils_cpp

#include <iostream>
#include <random>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include "StatUtils.hpp"
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Matrix.hpp"
#include "RUtils.hpp"

using namespace std;
using namespace aiStatUtils;
using namespace aiMath;
using namespace aiR;

default_random_engine* aiStatUtils::statutil_rand_engine() {
   static default_random_engine generator;
   return &generator;
}

int aiStatUtils::statutil_rand_int(int b) {return statutil_rand_int(0,b);}

int aiStatUtils::statutil_rand_int(int a, int b) {
   uniform_int_distribution<> distribution(a,b-1);
   return distribution( *(statutil_rand_engine()) );
}

double aiStatUtils::statutil_rand_uniform(double a, double b) {
   uniform_real_distribution<> distribution(a,b);
   return distribution( *(statutil_rand_engine()) );
}

double aiStatUtils::statutil_rand_normal(double mu, double sigma) {
   static normal_distribution<double> distribution(0,1);
   double val;

   val = distribution( *(statutil_rand_engine()) );
   val = val*sigma + mu;

   return val;
}

double aiStatUtils::statutil_rand_fattail1(double prob,
                                           double mu1, double sigma1,
                                           double mu2, double sigma2) 
{
   double x, mu, sigma;
   x = statutil_rand_uniform();
   if(x>=prob) {mu = mu1; sigma = sigma1;}
   else {mu = mu2; sigma = sigma2;}
   return statutil_rand_normal(mu, sigma);
}

double* aiStatUtils::statutil_rand_normalA(const int n, const double mu, const double sigma) {
   double* a = new double[n];
   for(int i=0;i<n;i++) a[i] = statutil_rand_normal(mu,sigma);
   return a;
}

int* aiStatUtils::statutil_rand_range(const int a, const int b) {
   const int n = b-a;
   int* arr = util_rangeA(a,b);
   double* rv = NULL;
   unordered_map<double,int> m;

   rv = statutil_rand_normalA(n);
   for(int i=0;i<n;i++) m[rv[i]] = arr[i];
   sort(rv,rv+n);
   for(int i=0;i<n;i++) arr[i] = m[rv[i]];
   
   //clean memory
   delete [] rv;

   return arr;
}

Matrix* aiStatUtils::statutil_rand_normalM(const int m, const int n, 
                                           double mu, double sigma) 
{
   Matrix* X = Matrix::instance(m,n);
   double** XX = X->X();
   for(int i=0;i<m;i++) {
      for(int j=0;j<n;j++) XX[i][j] = statutil_rand_normal(mu,sigma);
   }
   return X;
}

double aiStatUtils::statutil_corel(Matrix* _X, int j1, int j2, bool col_flag) {
   if(!col_flag) err_msg("statutil_corel: Functionality not yet implemented for col_flag=false");
   double** X = NULL;
   double val, m1, m2, s1, s2;
   int m, n;

   m = _X->m();
   n = _X->n();
   X = _X->X();

   if(j1<0 || j2<0) err_msg("statutil_corel: j1<0 || j2<0");
   if(j1>=n || j2>=n) err_msg("statutil_corel: j1>=n || j2>=n");

   m1 = 0;
   for(int i=0;i<m;i++) m1 += X[i][j1];
   m1 /= m;

   m2 = 0;
   for(int i=0;i<m;i++) m2 += X[i][j2];
   m2 /= m;

   s1 = 0;
   for(int i=0;i<m;i++) s1 += pow(X[i][j1]-m1, 2.0);
   s1 /= m; s1 = sqrt(s1);

   s2 = 0;
   for(int i=0;i<m;i++) s2 += pow(X[i][j2]-m2, 2.0);
   s2 /= m; s2 = sqrt(s2);

   val = 0;
   for(int i=0;i<m;i++) val += (X[i][j1]-m1) * (X[i][j2]-m2);
   val /= m; val /= (s1*s2);

   return val;
}

string aiStatUtils::statutil_rand_str(int len) {
   static const char alphanum[] =
      "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
   static int n = sizeof(alphanum)-1;
   string s = "";

   for (int i = 0; i < len; ++i) s = s + alphanum[ statutil_rand_int(n) ];
   return s;
}



#endif

