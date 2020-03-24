// Name:     MarketFieldsUtils.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_MarketFieldsUtils_hpp
#define ASX_MarketFieldsUtils_hpp

#include <unordered_map>
#include "DbAccount.hpp"

using namespace aiDbAccounts;

namespace aiMarketFields {

   /** Function to extract the correspondence between fields and accounts
    * for mmdb */
   const string marketfieldsutils_mmdb_fields_src = "aiMarketFields/notes/mmdb_fields.csv";
   unordered_map<string,DbAccount*>& marketfieldsutils_mmdb_fields();

   const string marketfieldsutils_adv3mdb_fields_src = "aiMarketFields/notes/adv3mdb_fields.csv";
   unordered_map<string,DbAccount*>& marketfieldsutils_adv3mdb_fields();

   const string marketfieldsutils_dmdb_fields_src = "aiMarketFields/notes/dmdb_fields.csv";
   unordered_map<string,DbAccount*>& marketfieldsutils_dmdb_fields();

   const string marketfieldsutils_mcapdb_fields_src = "aiMarketFields/notes/mcapdb_fields.csv";
   unordered_map<string,DbAccount*>& marketfieldsutils_mcapdb_fields();

   const string marketfieldsutils_vixdb_fields_src = "aiMarketFields/notes/vixdb_fields.csv";
   unordered_map<string,DbAccount*>& marketfieldsutils_vixdb_fields();

};

#endif

