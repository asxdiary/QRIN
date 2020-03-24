#include <stdio.h>
#include "pkgUtils.hpp"
#include "TestAcctVars.hpp"
#include "TestAcctVars2.hpp"

int main() {
   int val = 0;

   val += TestAcctVars_main();
   val += TestAcctVars2_main();

   if(val!=0) printf("UnitTest ***********FAILED***********\n");

   //clean memory
   aiUtils::pkgUtils_cleanup();

   return 0;
}

