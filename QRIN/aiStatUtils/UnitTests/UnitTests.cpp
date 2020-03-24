#include <stdio.h>
#include "pkgUtils.hpp"
#include "TestRegression.hpp"
#include "TestStatUtils.hpp"

int main() {
   int val = 0;

   val += TestRegression_main();
   val += TestStatUtils_main();

   if(val!=0) printf("UnitTest ***********FAILED***********\n");

   //clean memory
   aiUtils::pkgUtils_cleanup();

   return 0;
}

