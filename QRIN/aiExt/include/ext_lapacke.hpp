#ifndef ASX_EXT_LAPACKE_HPP
#define ASX_EXT_LAPACKE_HPP

#include <stdio.h>
#include "Utils.hpp"
#include "Matrix.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMath;

namespace aiExt {

   //Functions to support BLAS/LAPACK routines
   //If Dflag=true then it is assumed that the matrix is a diagonal matrix with
   //only m diagonal elements reported in vec
   //If Iflag=true then the elements of vec are inverted (i.e 1/val) before use
   //If uplo=L (uplo=U) then it is assumed that the matrix is symmetric and 
   //only lower (upper) triangular part is specified
   //If row_flag is true then the matrix is printed row wise else column wise
   Matrix* ext_lapacke_devectorize(const double* vec, 
                       const int m,
                       const int n, 
                       const bool Dflag=false,
                       const bool Iflag=false,
                       const string uplo="",
                       const bool row_flag=true);

   double* ext_lapacke_vectorize(Matrix* mat, const bool row_flag);

   Matrix* ext_lapacke_inverse(Matrix* mat);
   Matrix* ext_lapacke_inverse_psd(Matrix* mat);
   Matrix* ext_lapacke_solve(Matrix* A, Matrix* b);
   Matrix* ext_lapacke_solve_sym(Matrix* A, Matrix* b);

   void lapack_chk(const int info, string lfunc, string func, string cname="");

};

#endif

