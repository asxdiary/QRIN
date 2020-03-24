#include "Utils.hpp"
#include "UtilDateRange.hpp"

using namespace aiUtils;
using namespace aiUtils;

int TestUtilDateRange_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestUtilDateRange.";
   const string opfx = "output/TestUtilDateRange.";

   {
      string exS = "ex1.";
      UtilDateRange* ptr = NULL;

      for(int i=0;i<3;i++) {
         UtilDate* sd = NULL;
         UtilDate* ed = NULL;
         UtilDate* d = NULL;
         bool flag;

         if(i!=1) sd = UtilDate::eom(2006,1);
         if(i!=2) ed = UtilDate::eom(2006,3);

         ptr = UtilDateRange::instance(sd, ed);
         if(sd!=NULL && !ptr->overlap(sd)) val++;
         if(ed!=NULL && !ptr->overlap(ed)) val++;
         if(ptr->overlap(d)) val++;

         d = UtilDate::instance(2006,1,30); 
         flag = ptr->overlap(d);
         if(i==0 && flag) val++;
         if(i==1 && !flag) val++;
         if(i==2 && flag) val++;

         d = UtilDate::instance(2006,2,15); 
         flag = ptr->overlap(d);
         if(i==0 && !flag) val++;
         if(i==1 && !flag) val++;
         if(i==2 && !flag) val++;

         d = UtilDate::instance(2006,6,15); 
         flag = ptr->overlap(d);
         if(i==0 && flag) val++;
         if(i==1 && flag) val++;
         if(i==2 && !flag) val++;

         //clean memory
         delete ptr;
      }
   }

   {
      UtilDate* d1 = UtilDate::eom(2004,1);
      UtilDate* d2 = UtilDate::eom(2004,3);
      UtilDate* d3 = UtilDate::eom(2003,12);
      UtilDate* d4 = UtilDate::eom(2004,1);
      UtilDateRange* ptr1 = UtilDateRange::instance(d1, d2);
      UtilDateRange* ptr2 = UtilDateRange::instance(d3, d4);
      UtilDateRange* ptr3 = UtilDateRange::instance(d3, d1);
      UtilDateRange* ptr4 = UtilDateRange::instance(d2, NULL);
      if(! ptr1->overlap(ptr2)) val++;
      if(! ptr2->overlap(ptr1)) val++;
      if( ptr3->overlap(ptr4)) val++;
      if( ptr4->overlap(ptr3)) val++;

      //clean memory
      delete ptr1;
      delete ptr2;
      delete ptr3;
      delete ptr4;
   }

   {
      UtilDate* d1 = UtilDate::eom(2004,1);
      UtilDate* d2 = UtilDate::eom(2004,12);
      UtilDate* d3 = UtilDate::eom(2004,3);
      UtilDate* d4 = UtilDate::eom(2004,4);
      UtilDateRange* ptr1 = UtilDateRange::instance(d1,d2);
      UtilDateRange* ptr2 = UtilDateRange::instance(d3,d4);

      if(!ptr1->overlap(ptr2)) val++;

      //clean memory
      delete ptr1;
      delete ptr2;
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

