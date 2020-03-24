// Name:     MathUtils.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_MathUtils_cpp
#define ASX_MathUtils_cpp


#include <math.h>
#include <algorithm>
#include "MathUtils.hpp"
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Matrix.hpp"
#include "ext_lapacke.hpp"

using namespace aiMathUtils;
using namespace aiMath;
using namespace aiExt;

void aiMathUtils::mathutil_winsorize(double* x, int n, double lalpha, double halpha) {
   if(util_isZero(lalpha) && util_isZero(halpha-1)) return;

   double* sortx = NULL;
   double lval, hval;

   sortx = util_copy(x,n);
   sort(sortx,sortx+n);

   lval = sortx[ util_arrind(int(lalpha*n),n) ];
   hval = sortx[ util_arrind(int(halpha*n),n) ];

   for(int i=0;i<n;i++) {
      if(x[i] < lval) x[i] = lval;
      else if(x[i] > hval) x[i] = hval;
   }

   //clean memory
   delete [] sortx;

   return;
}


double aiMathUtils::mathutil_mean(double* x, int n) {
   double sum = 0;
   for(int i=0;i<n;i++) sum += x[i];
   return sum/n;
}

double aiMathUtils::mathutil_std(double* x, int n, double* meanp, Matrix* Delta, 
                                 bool inv_flag) 
{
   double avg;
   double val;

   if(meanp!=NULL) avg = *meanp;
   else avg = mathutil_mean(x,n);

   val = 0;

   if(Delta==NULL) {
      for(int i=0;i<n;i++) val += (x[i]-avg)*(x[i]-avg);
      val /= n-1;
   }
   else {
      double** deltaX = Delta->X();
      double denom, dval;
      int p;

      p = 2;
      if(inv_flag) p = -2;
      denom = 0;
      for(int i=0;i<n;i++) {
         dval = pow(deltaX[i][0], p);
         val += (x[i]-avg)*(x[i]-avg) * dval;
         denom += dval;
      }

      val /= denom;
   }
   val = sqrt(val);

   return val;
}

Matrix* aiMathUtils::mathutil_Xfpu(Matrix* X, Matrix* f, Matrix* u) {
   Matrix* Xf = NULL;
   Matrix* y = NULL;
   Xf = Matrix::mult(X,f);
   y = Matrix::add(Xf,u);
   delete Xf;
   return y;
}

Matrix* aiMathUtils::mathutil_ymXf(Matrix* y, Matrix* X, Matrix* f) {
   Matrix* Xf = NULL;
   Matrix* u = NULL;
   Xf = Matrix::mult(X,f);
   u = Matrix::subtract(y,Xf);
   delete Xf;
   return u;
}

double aiMathUtils::mathutil_pct(Matrix* X, const double eta) {
   double* arr = NULL;
   double val;
   int N, i1, i2;

   N = X->m() * X->n();
   arr = ext_lapacke_vectorize(X, true);
   sort(arr, arr+N);

   i1 = util_arrind(int(N*eta+0.5)-1,N);
   i2 = util_arrind(int(N*eta+1.0)-1,N);
   val = 0.5 * (arr[i1] + arr[i2]);

   //clean memory
   delete [] arr;

   return val;
}

double aiMathUtils::mathutil_pct(Matrix* X, const double eta, Matrix* Delta) {
   if( eta <= 0 || eta >= 1 || Delta == NULL ) { return mathutil_pct( X, eta ); }
   vector<vector<double>> vect;
   double* X_tmp = NULL;
   double* Delta_tmp = NULL;
   int N, N_d;
 
   N = X->m() * X->n();
   vect.resize(N);
   N_d = Delta->m() * Delta->n();
   if( N != N_d ) err_msg(__FUNCTION__," N != N_Delta ");
   
   X_tmp = ext_lapacke_vectorize(X, true);
   Delta_tmp = ext_lapacke_vectorize(Delta, true);

   double W = 0;
   for( int i=0; i<N; i++) {
      vect[i] = { X_tmp[i], pow( Delta_tmp[i], -2 ) };
      W += pow( Delta_tmp[i], -2 );
   }

   sort( vect.begin(), vect.end(), 
         []( const vector<double>& a, const vector<double>& b ) {return a[0] < b[0];} );

   double val = 0;
   double chk = 0;
   int j = 0;
   while( chk <= eta * W ) {
      chk += vect[j][1];
      j++;
   }

   double o_low = chk - eta * W;
   double o_high = eta * W + vect[j-1][1] - chk;

   if( j!=0 ) val = ( vect[j-1][0]*o_high + vect[j-2][0]*o_low ) /
                     ( o_high + o_low );

   // clean memory
   delete[] X_tmp;
   delete[] Delta_tmp;

   return val;
}


Matrix* aiMathUtils::mathutil_diag_ABAT_p_diagC(Matrix* A, Matrix* B, Matrix* C) {
   Matrix* X = NULL;
   double** XX = NULL;
   double** AX = NULL;
   double** BX = NULL;
   double** CX = NULL;
   int n, m;
   double val;

   m = A->m();
   n = A->n();

   if(B->m()!=B->n()) err_msg(__FUNCTION__," B->m()!=B->n() ");
   if(n!=B->m()) err_msg(__FUNCTION__," n!=B->m() ");
   if(C!=NULL && C->m()!=m) err_msg(__FUNCTION__," C!=NULL && C->m()!=m ");

   X = Matrix::instance(m,1);

   XX = X->X();
   AX = A->X();
   BX = B->X();
   if(C!=NULL) CX = C->X();

   for(int t=0;t<m;t++) {
      val = 0;
      for(int i=0;i<n;i++) {
         for(int j=0;j<n;j++) val += AX[t][i] * BX[i][j] * AX[t][j];
      }
      if(CX!=NULL) val += CX[t][0];
      XX[t][0] = val;
   }

   return X;
}

void aiMathUtils::mathutil_supportvector(list<int>* cL, Matrix*& Delta) {
   if(cL==NULL) return;
   list<int>::iterator it;
   double** DeltaX = Delta->X();
   for(it=cL->begin();it!=cL->end();it++) DeltaX[*it][0] = 1;
}

set<int>* aiMathUtils::mathutil_strict_filter(Matrix*& X, Matrix*& xvalM, Matrix* Delta) {
   if(X->m()!=xvalM->m()) err_msg("aiMathUtils::",__FUNCTION__," X->m()!=xvalM->m()");
   if(X->n()!=xvalM->n()) err_msg("aiMathUtils::",__FUNCTION__," X->n()!=xvalM->n()");

   int n = X->m();
   Matrix* tmp = NULL;
   double** tmpX = NULL;
   set<int>* S = NULL;

   S = new set<int>();
   tmp = xvalM->mean_row(Delta, false);
   tmpX = tmp->X();

   for(int j=0;j<n;j++) {
      if(tmpX[j][0]>0) S->insert(j);
   }

   if(S->size()>0) {
      Matrix* Y = NULL;
      Y = X->sub(NULL,NULL,S,NULL);
      delete X; X = Y; Y = NULL;
      Y = xvalM->sub(NULL,NULL,S,NULL);
      delete xvalM; xvalM = Y; Y = NULL;
   }

   //clean memory
   delete tmp;

   return S;
}

set<int>* aiMathUtils::mathutil_soft_filter(Matrix*& X, Matrix*& xvalM, 
                                            list<int>* cL) 
{
   if(X->m()!=xvalM->m()) err_msg("aiMathUtils::",__FUNCTION__," X->m()!=xvalM->m()");
   if(X->n()!=xvalM->n()) err_msg("aiMathUtils::",__FUNCTION__," X->n()!=xvalM->n()");

   int m = X->m();
   double** xvalMX = xvalM->X();
   set<int>* S = NULL;
   list<int>* _cL = NULL;

   list<int>::iterator it;
   bool flag;
   int j;

   if(cL==NULL) cL = _cL = util_rangeL(0,X->n());

   S = new set<int>();

   for(int i=0;i<m;i++) {
      flag = false;

      for(it=cL->begin();it!=cL->end() && !flag;it++) {
         j = *it;
         if(util_isZero(xvalMX[i][j])) flag = true;
      }

      if(!flag) S->insert(i);
   }

   if(S->size()>0) {
      Matrix* Y = NULL;
      Y = X->sub(NULL,NULL,S,NULL);
      delete X; X = Y; Y = NULL;
      Y = xvalM->sub(NULL,NULL,S,NULL);
      delete xvalM; xvalM = Y; Y = NULL;
   }

   //clean memory
   delete _cL;

   return S;
}

double aiMathUtils::sigmoid(double x) {
   if(x<-50) return 0;
   if(x>50) return 1;
   return 1.0/(1+exp((-1)*x));
}

Matrix* aiMathUtils::mathutil_lift(Matrix* c, Matrix* clsm) {
   Matrix* lc = NULL;

   double** cX = NULL;
   double** clsmX = NULL;
   double** lcX = NULL;

   int n, ncol;

   n = clsm->m();
   ncol = c->n();
   lc = Matrix::instance(n,ncol);

   cX = c->X();
   clsmX = clsm->X();
   lcX = lc->X();

   for(int i=0;i<n;i++) {
      for(int j=0;j<ncol;j++) lcX[i][j] = cX[int(clsmX[i][0])][j];
   }

   return lc;
}


#endif

