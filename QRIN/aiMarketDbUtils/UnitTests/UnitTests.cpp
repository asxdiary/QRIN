#include <stdio.h>
#include "pkgUtils.hpp"
#include "TestMarketDbGen.hpp"
#include "TestDailyMarketDbGen.hpp"

int main() {
   int val = 0;

   val += TestMarketDbGen_main();
   val += TestDailyMarketDbGen_main();

   if(val!=0) printf("UnitTest ***********FAILED***********\n");

   //clean memory
   aiUtils::pkgUtils_cleanup();

   return 0;
}

