// Name:     AcctFieldsUtils.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_AcctFieldsUtils_cpp
#define ASX_AcctFieldsUtils_cpp

#include "Utils.hpp"
#include "Global.hpp"
#include "AcctFieldsUtils.hpp"
#include "DbAccount.hpp"
#include "SMatrix.hpp"

using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiAcctFields;
using namespace aiMath;

unordered_map<string,DbAccount*>& aiAcctFields::acctfieldsutils_compustatQ_fields() {
   static int ctr = 0;
   static unordered_map<string,DbAccount*> m;
   Global* global = Global::instance();
   string src = global->coin_home() + acctfieldsutils_compustatQ_fields_src;

   if(ctr==0) {ctr++;
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
   }

   return m;
}

unordered_map<string,DbAccount*>& aiAcctFields::acctfieldsutils_savanet_fields() {
   static int ctr = 0;
   static unordered_map<string,DbAccount*> m;
   Global* global = Global::instance();
   string src = global->coin_home() + acctfieldsutils_savanet_fields_src;

   if(ctr==0) {ctr++;
      SMatrix* ptr = NULL;
      DbAccount* dba = NULL;
      string** X = NULL;
      string key, id;
      int num;

      ptr = SMatrix::instance_fscan(src,true,":");
      num = ptr->m();
      X = ptr->X();

      for(int i=0;i<num;i++) {
         key = X[i][0] + ":" + X[i][1];
         if(X[i][1].compare("COMPSdiluted")==0) X[i][1] = "EPS";
         id = X[i][1] + "Account";
         dba = (DbAccount*) util_singleton(id,id);
         if(dba!=NULL) m[key] = dba;
         else warn_msg(__FUNCTION__," ",id," Account not found");
      }

      //clean memory
      delete ptr;
   }

   return m;
}

unordered_map<string,DbAccount*>& aiAcctFields::acctfieldsutils_smartest_fields() {
   static int ctr = 0;
   static unordered_map<string,DbAccount*> m;
   Global* global = Global::instance();
   string src = global->coin_home() + acctfieldsutils_smartest_fields_src;

   if(ctr==0) {ctr++;
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
   }

   return m;
}

unordered_map<string,DbAccount*>& aiAcctFields::acctfieldsutils_savanet_EA_fields() {
   static int ctr = 0;
   static unordered_map<string,DbAccount*> m;
   Global* global = Global::instance();
   string src = global->coin_home() + acctfieldsutils_savanet_EA_fields_src;

   if(ctr==0) {ctr++;
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
   }

   return m;
}


#endif

