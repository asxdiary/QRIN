#include <stdio.h>
#include <string>
#include "pkgUtils.hpp"
#include "Utils.hpp"
#include "concat.hpp"
#include "chgdate_preveom.hpp"
#include "dm_habs.hpp"
#include "fix_column_headers.hpp"
#include "generate_gics.hpp"
#include "compute_csanal.hpp"
#include "compute_univfilter.hpp"
#include "compute_diffanal.hpp"
#include "compute_aggdm.hpp"
#include "compute_wtcsanal.hpp"
#include "compute_res.hpp"
#include "compute_autocorel.hpp"
#include "compute_unianal.hpp"
#include "compute_cc.hpp"
#include "compute_bianal.hpp"
#include "analyze_data1.hpp"

using namespace std;

int main(int argc, char* argv[]) {
   int val = 0;
   string prog;

   for(int t=0;t<argc;t++) printf("%s ",argv[t]);
   printf("\n");

   if(argc<2) err_msg("Usage: <cmd> <prog> ");
   prog = argv[1];

   if(prog.compare("csanal")==0) val += compute_csanal_main(argc, argv);
   else if(prog.compare("univfilter")==0) val += compute_univfilter_main(argc, argv);
   else if(prog.compare("diffanal")==0) val += compute_diffanal_main(argc, argv);
   else if(prog.compare("aggdm")==0) val += compute_aggdm_main(argc, argv);
   else if(prog.compare("wtcsanal")==0) val += compute_wtcsanal_main(argc, argv);
   else if(prog.compare("res")==0) val += compute_res_main(argc, argv);
   else if(prog.compare("fix")==0) val += fix_column_headers_main(argc, argv);
   else if(prog.compare("gics")==0) val += generate_gics_main(argc, argv);
   else if(prog.compare("autocorel")==0) val += compute_autocorel_main(argc, argv);
   else if(prog.compare("unianal")==0) val += compute_unianal_main(argc, argv);
   else if(prog.compare("cc")==0) val += compute_cc_main(argc, argv);
   else if(prog.compare("bianal")==0) val += compute_bianal_main(argc, argv);
   else if(prog.compare("analyze_data1")==0) val += analyze_data1_main(argc, argv);
   else if(prog.compare("concat")==0) val += concat_main(argc, argv);
   else if(prog.compare("chgdate_preveom")==0) val += chgdate_preveom_main(argc, argv);
   else if(prog.compare("habs")==0) val += dm_habs_main(argc, argv);
   else err_msg("Invalid prog");
   
   if(val!=0) printf("UnitTest ***********FAILED***********\n");

   //clean memory
   aiUtils::pkgUtils_cleanup();

   return 0;
}

