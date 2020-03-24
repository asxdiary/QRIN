// Name:     DbUtils.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DbUtils_cpp
#define ASX_DbUtils_cpp

#include "Utils.hpp"
#include "DbUtils.hpp"
#include "DbAccount.hpp"

using namespace aiUtils;
using namespace aiDb;
using namespace aiDbAccounts;
using namespace aiDbUtils;

void aiDbUtils::DbUtils_fields(string src, unordered_map<string,DbAccount*>& m) {
   unordered_map<string,string>* ms = NULL;
   unordered_map<string,string>::iterator it;
   DbAccount* ptr = NULL;
   string key, id;

   util_fscan(src,ms);
   for(it=ms->begin();it!=ms->end();it++) {
      key = it->first;
      id = it->second;
      ptr = (DbAccount*) util_singleton(id,id);
      if(ptr!=NULL) m[key] = ptr;
      else warn_msg(__FUNCTION__," ",id," Account not found");
   }

   //clean memory
   delete ms;

   return;
}



#endif

