// Name:     DbUtils.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DbUtils_hpp
#define ASX_DbUtils_hpp

#include <unordered_map>
#include "DbAccount.hpp"

using namespace aiDbAccounts;

namespace aiDbUtils {

   void DbUtils_fields(string src, unordered_map<string,DbAccount*>& m);

};

#endif

