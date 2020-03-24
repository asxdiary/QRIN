// Name:     AcctFieldsUtils.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_AcctFieldsUtils_hpp
#define ASX_AcctFieldsUtils_hpp

#include <unordered_map>
#include "DbAccount.hpp"

using namespace aiDbAccounts;

namespace aiAcctFields {

   /** Function to extract the correspondence between fields and accounts
    * for CompustatQ */
   const string acctfieldsutils_compustatQ_fields_src = "aiAcctFields/notes/compustatQ_fields.csv";
   unordered_map<string,DbAccount*>& acctfieldsutils_compustatQ_fields();

   /** Function to extract the correspondence between fields and accounts
    * for savanet*/
   const string acctfieldsutils_savanet_fields_src = "aiAcctFields/notes/savanet_fields.csv";
   unordered_map<string,DbAccount*>& acctfieldsutils_savanet_fields();

   /** Function to extract the correspondence between fields and accounts
    * for savanet EA*/
   const string acctfieldsutils_savanet_EA_fields_src = "aiAcctFields/notes/savanet_EA_fields.csv";
   unordered_map<string,DbAccount*>& acctfieldsutils_savanet_EA_fields();



   /** Function to extract the correspondence between fields and accounts
    * for smart estimates*/
   const string acctfieldsutils_smartest_fields_src = "aiAcctFields/notes/smartest_fields.csv";
   unordered_map<string,DbAccount*>& acctfieldsutils_smartest_fields();



};

#endif

