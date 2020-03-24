#include <stdio.h>
#include "pkgUtils.hpp"
#include "TestFactorModel.hpp"

int main() {
   int val = 0;

   val += TestFactorModel_main();

   if(val!=0) printf("UnitTest ***********FAILED***********\n");

   //clean memory
   aiUtils::pkgUtils_cleanup();

   return 0;
}

