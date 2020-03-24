#include <stdio.h>
#include "pkgUtils.hpp"
#include "TestMatrixWinStdProcessor.hpp"
#include "TestResidualProcessor.hpp"
#include "TestMathUtils.hpp"

int main() {
   int val = 0;

   val += TestMatrixWinStdProcessor_main();
   val += TestResidualProcessor_main();
   val += TestMathUtils_main();

   if(val!=0) printf("UnitTest ***********FAILED***********\n");

   //clean memory
   aiUtils::pkgUtils_cleanup();

   return 0;
}

