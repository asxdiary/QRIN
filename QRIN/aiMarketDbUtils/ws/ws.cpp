#include <stdio.h>
#include "pkgUtils.hpp"
#include "include/ReturnDM.hpp"
#include "include/ResReturnDM.hpp"
#include "include/BetaDM.hpp"
#include "include/MomDM.hpp"
#include "include/McapDM.hpp"

int main() {
   int val = 0;

   //val += ReturnDM_main();
   //val += ResReturnDM_main();
   //val += BetaDM_main();
   //val += MomDM_main();
   val += McapDM_main();

   if(val!=0) printf("UnitTest ***********FAILED***********\n");

   //clean memory
   aiUtils::pkgUtils_cleanup();

   return 0;
}

