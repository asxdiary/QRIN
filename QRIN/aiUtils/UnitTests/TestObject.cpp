#ifndef ASX_ObjectUnitTest_TestObject
#define ASX_ObjectUnitTest_TestObject

#include <unordered_map>
#include "Utils.hpp"
#include "Object.hpp"
#include "Global.hpp"
#include "TestObject.hpp"

using namespace aiUtils;

int TestObject_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;

   {
      Object* ptr = NULL;
      ptr = Object::instance();
      delete ptr;
   }

   if(val>0) printf("%s failed\n",__FUNCTION__);

   return val;
}

#endif 

