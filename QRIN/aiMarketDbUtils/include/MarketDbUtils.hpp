// Name:     MarketDbUtils.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_MarketDbUtils_hpp
#define ASX_MarketDbUtils_hpp

#include "Utils.hpp"
#include "Utils_templates.hpp"

using namespace std;
using namespace aiUtils;

namespace aiMarketDbUtils{

   /** market security AIID */
   string MarketDbUtils_mkt();

   /** VIX security AIID */
   string MarketDbUtils_vix();

};

#endif


