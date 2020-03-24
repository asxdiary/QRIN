#include <stdio.h>
#include "pkgUtils.hpp"
#include "TestRUtils.hpp"

int main() {
   int val = 0;

   val += TestRUtils_main();

   if(val!=0) printf("UnitTest ***********FAILED***********\n");

   //clean memory
   aiUtils::pkgUtils_cleanup();

   return 0;
}

