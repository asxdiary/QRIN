#include <stdio.h>
#include "pkgUtils.hpp"
#include "TestFS.hpp"
#include "TestFSDb.hpp"
#include "TestAcctDb.hpp"

int main() {
   int val = 0;

   val += TestFS_main();
   val += TestFSDb_main();
   val += TestAcctDb_main();

   if(val!=0) printf("UnitTest ***********FAILED***********\n");

   //clean memory
   aiUtils::pkgUtils_cleanup();

   return 0;
}

