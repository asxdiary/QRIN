// Name:     pkgMath.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_pkgMath_cpp
#define ASX_pkgMath_cpp

#include "Utils.hpp"
#include "pkgMath.hpp"
#include "Matrix.hpp"
#include "ext_lapacke.hpp"

using namespace aiExt;
using namespace aiUtils;
using namespace aiMath;

void aiMath::pkgMath_cleanup() {
   return;
}

Matrix* aiMath::pkgMath_inverse(Matrix* mat) {
   return aiExt::ext_lapacke_inverse(mat);
}

Matrix* aiMath::pkgMath_inverse_psd(Matrix* mat) {
   return aiExt::ext_lapacke_inverse_psd(mat);
}

Matrix* aiMath::pkgMath_solve(Matrix* A, Matrix* b) {
   return aiExt::ext_lapacke_solve(A,b);
}

Matrix* aiMath::pkgMath_solve_sym(Matrix* A, Matrix* b) {
   return aiExt::ext_lapacke_solve_sym(A,b);
}

#endif

