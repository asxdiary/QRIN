#include <stdio.h>
#include "pkgUtils.hpp"

int main() {
   int val = 0;

   if(val!=0) printf("UnitTest ***********FAILED***********\n");

   //clean memory
   aiUtils::pkgUtils_cleanup();

   return 0;
}

