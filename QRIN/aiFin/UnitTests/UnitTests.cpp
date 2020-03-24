#include <stdio.h>
#include "pkgUtils.hpp"
#include "TestCompanyIdentifier.hpp"
#include "TestCompany.hpp"
#include "TestCompanyUniverse.hpp"
#include "TestGICS.hpp"

int main() {
   int val = 0;

   val += TestCompany_main();
   val += TestCompanyIdentifier_main();
   val += TestCompanyUniverse_main();
   val += TestGICS_main();

   if(val!=0) printf("UnitTest ***********FAILED***********\n");

   //clean memory
   aiUtils::pkgUtils_cleanup();

   return 0;
}

