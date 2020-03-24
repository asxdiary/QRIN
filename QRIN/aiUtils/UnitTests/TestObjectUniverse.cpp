#include "Utils.hpp"
#include "ObjectUniverse.hpp"

using namespace aiUtils;

int TestObjectUniverse_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestObjectUniverse.";
   const string opfx = "output/TestObjectUniverse.";

   {
      string exS = "ex1";
      ObjectUniverse* ptr = NULL;
      ObjectUniverse* ptr2 = NULL;
      ObjectUniverse* ptr3 = NULL;
      Object* tmp = NULL;

      ptr = ObjectUniverse::instance();
      tmp = ptr->obj("abcd");
      if(tmp!=NULL) val++;
      tmp = ptr->obj("abcd",true);
      tmp = ptr->obj("abcd");
      if(tmp==NULL) val++;
      if(tmp!=ptr->obj("abcd",true)) val++;
      ptr->obj("pqrs",true);
      ptr->fprint(opfx + exS);
      ptr2 = ObjectUniverse::instance_fscan(opfx + exS);
      ptr2->fprint(opfx + exS + "b");

      ptr3 = ObjectUniverse::instance();
      ptr3->add_obj(ptr->obj("abcd"));
      ptr3->add_obj(ptr->obj("pqrs"));
      ptr3->obj("abcd3");

      {
         int num;
         Object** arr = NULL;
         arr = ptr3->objA(num);
         if(num!=2) val++;
         delete [] arr;
      }

      //clean memory
      delete ptr;
      delete ptr2;
      delete ptr3;
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

