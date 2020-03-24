#include <stdio.h>
#include "pkgUtils.hpp"
#include "TestCompustatQGen.hpp"
#include "TestSavanetFYGen.hpp"

int main() {
   int val = 0;

   val += TestCompustatQGen_main();
   val += TestSavanetFYGen_main();

   if(val!=0) printf("UnitTest failed\n");

   //clean memory
   aiUtils::pkgUtils_cleanup();

   return 0;
}

