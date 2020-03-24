#include <stdio.h>
#include "pkgUtils.hpp"
#include "TestUtils.hpp"
#include "TestObject.hpp"
#include "TestGlobal.hpp"
#include "TestUtilDate.hpp"
#include "TestUtilDateRange.hpp"
#include "TestDated.hpp"
#include "TestDatedTables.hpp"
#include "TestObjectUniverse.hpp"

int main() {
   int val = 0;

   val += TestUtils_main();
   val += TestObject_main();
   val += TestGlobal_main();
   val += TestUtilDate_main();
   val += TestUtilDateRange_main();
   val += TestDated_main();
   val += TestDatedTables_main();
   val += TestObjectUniverse_main();

   if(val!=0) printf("UnitTest ***********FAILED***********\n");

   //clean memory
   aiUtils::pkgUtils_cleanup();

   return 0;
}

