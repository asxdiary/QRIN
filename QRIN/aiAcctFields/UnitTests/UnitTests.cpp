#include <stdio.h>
#include "pkgUtils.hpp"
#include "TestAcctFieldsUtils.hpp"

int main() {
   int val = 0;

   val += TestAcctFieldsUtils_main();

   if(val!=0) printf("UnitTest ***********FAILED***********\n");

   //clean memory
   aiUtils::pkgUtils_cleanup();

   return 0;
}

