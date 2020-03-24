#ifndef ASX_ext_lapacke_cpp
#define ASX_ext_lapacke_cpp

#include "ext_lapacke.hpp"
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Matrix.hpp"
#include "lapacke.h"

using namespace std;

using namespace aiExt;
using namespace aiUtils;
using namespace aiMath;

Matrix* aiExt::ext_lapacke_inverse(Matrix* mat) {
   if(mat->m()!=mat->n()) err_msg("mat->m()!=mat->n()",__FUNCTION__);

   int n = mat->m();
   double* A = NULL;
   int* ipiv = NULL;
   double* work = NULL;
   Matrix* matI = NULL;
   int lwork, info;

   A = ext_lapacke_vectorize(mat, true);
   ipiv = new int[n+1];
   lwork = n*n;
   work = new double[lwork];

   dgetrf_(&n,&n,A,&n,ipiv,&info);
   lapack_chk(info,"dgetrf",__FUNCTION__,"Matrix");
   dgetri_(&n,A,&n,ipiv,work,&lwork,&info);
   lapack_chk(info,"dgetri",__FUNCTION__,"Matrix");

   n = mat->m();
   matI = ext_lapacke_devectorize(A,n,n);
   matI->copynames(mat, true, true);

   //clean memory
   delete [] ipiv;
   delete [] work;
   delete [] A;

   return matI;
}

Matrix* aiExt::ext_lapacke_inverse_psd(Matrix* mat) {
   if(mat->m()!=mat->n()) err_msg("mat->m()!=mat->n()",__FUNCTION__);

   Matrix* matI = NULL;
   double* A = NULL;
   int info, n;
   char uplo;

   n = mat->m();
   uplo = 'l';
   A = ext_lapacke_vectorize(mat, true);
   dpotrf_(&uplo, &n, A, &n, &info);
   lapack_chk(info,"dpotrf",__FUNCTION__,"Matrix");
   dpotri_(&uplo, &n, A, &n, &info);
   lapack_chk(info,"dpotri",__FUNCTION__,"Matrix");

   n = mat->m();
   matI = ext_lapacke_devectorize(A,n,n,false,false,"u");

   //clean memory
   delete [] A;

   return matI;
}

void aiExt::lapack_chk(const int info, string lfunc, string func, string cname) {
   if(info==0) return;
   string msg;
   if(cname.length()>0) msg.append(cname + "::");
   msg.append(func + " LAPACK function ");
   msg.append(lfunc + " failed info = ");
   msg.append(util_string(info));
   err_msg(msg);
   return;
}

Matrix* aiExt::ext_lapacke_solve(Matrix* A, Matrix* b) {
   Matrix* x = NULL;
   double* avec = NULL;
   double* bvec = NULL;
   int* ipiv = NULL;
   int n, nrhs, lda, ldb, info;

   n = A->m();
   nrhs = b->n();
   lda = ldb = n;
   avec = ext_lapacke_vectorize(A,false);
   bvec = ext_lapacke_vectorize(b,false);
   ipiv = new int[n+1];
   dgesv_(&n, &nrhs, avec, &lda, ipiv, bvec, &ldb, &info);
   lapack_chk(info,"dgesv",__FUNCTION__,"Matrix");
   x = ext_lapacke_devectorize(bvec, n, nrhs, false, false, "", false);

   //clean memory
   delete [] avec;
   delete [] bvec;
   delete [] ipiv;

   return x;
}

Matrix* aiExt::ext_lapacke_solve_sym(Matrix* A, Matrix* b) {
   Matrix* x = NULL;
   double* avec = NULL;
   double* bvec = NULL;
   int* ipiv = NULL;
   int n, nrhs, lda, ldb, info;
   char uplo = 'U';

   n = A->m();
   nrhs = b->n();
   lda = ldb = n;
   avec = ext_lapacke_vectorize(A,false);
   bvec = ext_lapacke_vectorize(b,false);
   ipiv = new int[n+1];
   dposv_( &uplo, &n, &nrhs, avec, &lda, bvec, &ldb, &info );
   lapack_chk(info,"dgesv",__FUNCTION__,"Matrix");
   x = ext_lapacke_devectorize(bvec, n, nrhs, false, false, "", false);

   //clean memory
   delete [] avec;
   delete [] bvec;
   delete [] ipiv;

   return x;
}

Matrix* aiExt::ext_lapacke_devectorize(const double* vec, 
                            const int m,
                            const int n,
                            const bool Dflag,
                            const bool Iflag,
                            const string uplo,
                            const bool row_flag)
{
   Matrix* mat = NULL;
   double** X = NULL;
   double val;
   int t;

   if(!Dflag) {
      X = util_matrix(m,n,(double)0);
      t = 0;
      if(row_flag) {
         for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
               val = vec[t++];
               if(Iflag) val = 1.0/val;
               X[i][j] = val;
            }
         }
      }
      else {
         for(int j=0;j<n;j++) {
            for(int i=0;i<m;i++) {
               val = vec[t++];
               if(Iflag) val = 1.0/val;
               X[i][j] = val;
            }
         }
      }
      if(uplo.length()>0) {
         if(uplo.compare("l")==0) {
            if(m!=n) err_msg("uplo.length()>0 and m!=n",__FUNCTION__);
            for(int i=0;i<m;i++) {
               for(int j=i+1;j<m;j++) X[i][j] = X[j][i];
            }
         }
         else if(uplo.compare("u")==0) {
            if(m!=n) err_msg("uplo.length()>0 and m!=n",__FUNCTION__);
            for(int i=0;i<m;i++) {
               for(int j=0;j<i;j++) X[i][j] = X[j][i];
            }
         }
         else err_msg(string("Invalid uplo = ") + uplo + " specified",__FUNCTION__);
      }
   }
   else {
      X = util_matrix(m,m,(double)0);
      t = 0;
      for(int i=0;i<m;i++) {
         val = vec[t++];
         if(Iflag) val = 1.0/val;
         X[i][i] = val;
      }
   }

   mat = Matrix::instance(m,n,X);
   return mat;
}

double* aiExt::ext_lapacke_vectorize(Matrix* mat, const bool row_flag) {
   const int m = mat->m();
   const int n = mat->n();
   double** X = mat->X();
   double* vec = NULL;
   int t;

   vec = new double[m*n];
   t = 0;

   if(row_flag) {
      for(int i=0;i<m;i++) {
         for(int j=0;j<n;j++) vec[t++] = X[i][j];
      }
   }
   else {
      for(int j=0;j<n;j++) {
         for(int i=0;i<m;i++) vec[t++] = X[i][j];
      }
   }

   return vec;
}

#endif

