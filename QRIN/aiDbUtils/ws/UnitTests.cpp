#include <stdio.h>
#include <stdlib.h>
#include "pkgUtils.hpp"
#include "Utils.hpp"

using namespace std;
using namespace aiUtils;

int main(int argc, char* argv[]) {
   int val = 0;
   string prog;

   if(argc<2) err_msg("Usage: <cmd> prog\n");
   else prog = argv[1];

   if(val!=0) printf("UnitTest ***********FAILED***********\n");

   //clean memory
   aiUtils::pkgUtils_cleanup();

   return 0;
}

