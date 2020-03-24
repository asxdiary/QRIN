#include <unordered_map>
#include "Utils.hpp"
#include "AcctFieldsUtils.hpp"
#include "DbAccount.hpp"

using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctFields;

int TestAcctFieldsUtils_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestAcctFieldsUtils.";
   const string opfx = "output/TestAcctFieldsUtils.";

   {
      unordered_map<string,DbAccount*> m = acctfieldsutils_compustatQ_fields();
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

