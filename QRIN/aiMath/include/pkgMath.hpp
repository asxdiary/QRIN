// Name:     pkgMath.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_pkgMath_hpp
#define ASX_pkgMath_hpp

#include "Matrix.hpp"

/** This contains the functions to cleanup the static objects that are created
 * in each package */

namespace aiMath {

   void pkgMath_cleanup();

   //Inverse function
   Matrix* pkgMath_inverse(Matrix* mat);
   Matrix* pkgMath_inverse_psd(Matrix* mat);

   //Solve Ax = b
   Matrix* pkgMath_solve(Matrix* A, Matrix* b);
   Matrix* pkgMath_solve_sym(Matrix* A, Matrix* b);

};

#endif

