#include <stdio.h>
#include <stdlib.h>
#include "pkgUtils.hpp"
#include "Utils.hpp"
#include "compute_cc.hpp"
#include "compute_act_est_anal.hpp"

using namespace std;
using namespace aiUtils;

int main(int argc, char* argv[]) {
   int val = 0;
   string prog;

   if(argc<2) err_msg("Usage: <cmd> prog\n");
   else prog = argv[1];

   if(prog.compare("cc")==0) compute_cc(argc, argv);
   else if(prog.compare("act_est_anal")==0) compute_act_est_anal(argc, argv);
   else err_msg(prog + " not found");

   if(val!=0) printf("UnitTest ***********FAILED***********\n");

   //clean memory
   aiUtils::pkgUtils_cleanup();

   return 0;
}

