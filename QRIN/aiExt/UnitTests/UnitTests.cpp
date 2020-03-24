#include <stdio.h>
#include "pkgUtils.hpp"
#include "Testext_csvparser.hpp"
#include "Testext_lapack.hpp"
#include "test_mlpack.hpp"

int main() {
   int val = 0;

   //val += test_mlpack_main();

   val += Testext_csvparser_main();
   val += Testext_lapack_main();

   if(val!=0) printf("UnitTest ***********FAILED***********\n");

   //clean memory
   aiUtils::pkgUtils_cleanup();

   return 0;
}

