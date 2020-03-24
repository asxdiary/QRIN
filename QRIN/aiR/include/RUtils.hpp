// Name:     RUtils.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_RUtils_hpp
#define ASX_RUtils_hpp

#include <stdlib.h>
#include "Utils.hpp"
#include "Object.hpp"
#include "Global.hpp"
#include "Matrix.hpp"

using namespace std;
using namespace aiMath;

namespace aiR {

   //SYSTEM UTILITIES TO INVOKE R CODE

   /** R code directory */
   string rutil_rdir();
   /** Temporary directory to be used for communication with R codes */
   string rutil_tmpdir();
   /** Workspace prefix to be used during communication with R codes */
   string rutil_wspfx(string func);
   /** execute R code named prog using the supplied arguments */
   void rutil_exec(string prog, list<string>* argsL);

   /** This function reads a matrix outputted by R code
    * Assumptions:
    * - The first column is dropped
    * - The first row is assumed to be a header row
    * - All other entries are assumed to be double */
   Matrix* rutil_fscan_matrix(string fname);

   /** This function returns the file name to be used in communication with 
    * R code; if X!=NULL then matrix X is printed appropriately */
   string rutil_matrix_fname(string pfx, string vname, Matrix* X=NULL);

};

#endif


