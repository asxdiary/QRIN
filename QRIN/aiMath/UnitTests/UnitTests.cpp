#include <stdio.h>
#include "pkgUtils.hpp"
#include "TestMatrix.hpp"
#include "TestDatedMatrix.hpp"
#include "TestPanel.hpp"
#include "TestSMatrix.hpp"
#include "TestFlexMatrix.hpp"

int main() {
   int val = 0;

   val += TestMatrix_main();
   val += TestDatedMatrix_main();
   val += TestSMatrix_main();
   val += TestFlexMatrix_main();
   val += TestPanel_main();

   if(val!=0) printf("UnitTest ***********FAILED***********\n");

   //clean memory
   aiUtils::pkgUtils_cleanup();

   return 0;
}

