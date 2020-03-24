// Name:     Object_templates.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_Object_templates_hpp
#define ASX_Object_templates_hpp

namespace aiUtils {
//Forword decalaration
class Object;
};

#include <string>
#include "Utils.hpp"
#include "Utils_templates.hpp"

using namespace aiUtils;
using namespace std;

//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiUtils {

   template<typename T> void Object::debug2(string oname, T const& val) {
      if(!debug_mode()) return;
      util_ofprint(debug_pfx() + "." + debug_id(), oname, val);
   }

   template<typename T> void Object::debug2(string oname, const T* val, const int n) {
      if(!debug_mode()) return;
      util_ofprint(debug_pfx() + "." + debug_id(), oname, val, n);
   }

   template<typename T> void Object::debug2(string oname, T** val, 
                                    const int m, const int n) 
   {
      if(!debug_mode()) return;
      util_ofprint(debug_pfx() + "." + debug_id(), oname, val, m, n);
   }

   template<typename T> void Object::debug2(string oname, list<T>* val) {
      if(!debug_mode()) return;
      util_ofprint(debug_pfx() + "." + debug_id(), oname, val);
   }

   template<typename T> void Object::debug2(string oname, set<T>* val) {
      if(!debug_mode()) return;
      util_ofprint(debug_pfx() + "." + debug_id(), oname, val);
   }

   template<typename T1, typename T2> void Object::debug2(string oname, 
                                                  unordered_map<T1,T2>* val) 
   {
      if(!debug_mode()) return;
      util_ofprint(debug_pfx() + "." + debug_id(), oname, val);
   }

   template<typename T1, typename T2> void Object::debug2(string oname, 
                                                  unordered_map<T1,T2>** val, const int num)
   {
      if(!debug_mode()) return;
      util_ofprint(debug_pfx() + "." + debug_id(), oname, val, num);
   }
  
   template<typename T1, typename T2> void Object::debug2(string oname, 
                                                  unordered_map<T1,set<T2>*>* val)
   {
      if(!debug_mode()) return;
      util_ofprint(debug_pfx() + "." + debug_id(), oname, val);
   }

};

#endif

