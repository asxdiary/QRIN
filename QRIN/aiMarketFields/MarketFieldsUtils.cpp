// Name:     MarketFieldsUtils.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_MarketFieldsUtils_cpp
#define ASX_MarketFieldsUtils_cpp

#include "Utils.hpp"
#include "Global.hpp"
#include "MarketFieldsUtils.hpp"
#include "DbAccount.hpp"
#include "DbUtils.hpp"

using namespace aiUtils;
using namespace aiDb;
using namespace aiMarketFields;
using namespace aiDbUtils;

unordered_map<string,DbAccount*>& aiMarketFields::marketfieldsutils_vixdb_fields() {
   static int ctr = 0;
   static unordered_map<string,DbAccount*> m;
   string src = Global::instance()->coin_home() + marketfieldsutils_vixdb_fields_src;
   for(;ctr==0;ctr++) DbUtils_fields(src, m);
   return m;
}

unordered_map<string,DbAccount*>& aiMarketFields::marketfieldsutils_mmdb_fields() {
   static int ctr = 0;
   static unordered_map<string,DbAccount*> m;
   string src = Global::instance()->coin_home() + marketfieldsutils_mmdb_fields_src;
   for(;ctr==0;ctr++) DbUtils_fields(src, m);
   return m;
}

unordered_map<string,DbAccount*>& aiMarketFields::marketfieldsutils_adv3mdb_fields() {
   static int ctr = 0;
   static unordered_map<string,DbAccount*> m;
   string src = Global::instance()->coin_home() + marketfieldsutils_adv3mdb_fields_src;
   for(;ctr==0;ctr++) DbUtils_fields(src, m);
   return m;
}



unordered_map<string,DbAccount*>& aiMarketFields::marketfieldsutils_dmdb_fields() {
   static int ctr = 0;
   static unordered_map<string,DbAccount*> m;
   string src = Global::instance()->coin_home() + marketfieldsutils_dmdb_fields_src;
   for(;ctr==0;ctr++) DbUtils_fields(src, m);
   return m;
}

unordered_map<string,DbAccount*>& aiMarketFields::marketfieldsutils_mcapdb_fields() {
   static int ctr = 0;
   static unordered_map<string,DbAccount*> m;
   string src = Global::instance()->coin_home() + marketfieldsutils_mcapdb_fields_src;
   for(;ctr==0;ctr++) DbUtils_fields(src, m);
   return m;
}

#endif

