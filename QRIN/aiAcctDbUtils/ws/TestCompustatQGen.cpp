#include "Utils.hpp"
#include "CompustatQGen.hpp"
#include "CompanyIdentifier.hpp"
#include "CompanyUniverse.hpp"
#include "Global.hpp"

using namespace aiUtils;
using namespace aiFin;
using namespace aiAcctDbUtils;

int TestCompustatQGen_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestCompustatQGen.";
   const string opfx = "output/TestCompustatQGen.";
   Global* global = Global::instance();

   {
      string exS = "ex1.";
      CompanyUniverse* univ = NULL;
      CompustatQGen* ptr = NULL;
      AcctDb* cQ = NULL;
      string src; 
      list<UtilDate*> dL;

      src = global->compustatQ_src();
      UtilDate::eomL(UtilDate::eom(2010,1),UtilDate::eom(2014,1),&dL);
      univ = CompanyUniverse::instance(CompanyIdentifier::AIID);
      ptr = CompustatQGen::instance(univ);

      ptr->configure(src);
      ((DbGen*)ptr)->algo_exec(&dL);
      cQ = ptr->extract_mdl();
      cQ->fprint_summary(opfx + exS + "cQ.output.csv");

      {
         AcctDb* cA = NULL;
         UtilDate* dh = UtilDate::eom(2014,1);
         int xval;
         cA = cQ->aggQ(&dL, dh, xval);
         cA->fprint_summary(opfx + exS + "cA.output.csv");
      }

      //clean memory
      delete ptr;
      delete univ;
      delete cQ;
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

