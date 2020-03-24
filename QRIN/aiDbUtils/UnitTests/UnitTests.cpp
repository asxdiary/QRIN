#include <stdio.h>
#include "pkgUtils.hpp"
#include "TestDbGen.hpp"
#include "TestGenericDbGen.hpp"

int main() {
   int val = 0;

   val += TestDbGen_main();
   val += TestGenericDbGen_main();

   if(val!=0) printf("UnitTest ***********FAILED***********\n");

   //clean memory
   aiUtils::pkgUtils_cleanup();

   return 0;
}

