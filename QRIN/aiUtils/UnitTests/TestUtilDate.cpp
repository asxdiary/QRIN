#include "Utils.hpp"
#include "UtilDate.hpp"

using namespace aiUtils;
using namespace aiUtils;

int TestUtilDate_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestUtilDate.";
   const string opfx = "output/TestUtilDate.";

   {
      string exS = "ex1.";
      UtilDate* ptr = UtilDate::instance(2004,1,13);
      ptr->fprint(opfx + exS + "ptr");
      UtilDate* ptr2 = UtilDate::instance_fscan(opfx + exS + "ptr");
      ptr2->fprint(opfx + exS + "ptr2");

      ptr = UtilDate::instance(2004,1,14);
      ptr2 = UtilDate::instance(2004,1,14);
      if(ptr!=ptr2) val++;
   }

   {
      UtilDate* d = UtilDate::instance(2007,1,31);
      string s = "/datadump/savanet/estimates/split/yyyymm.csv";
      string s2 = d->format(s);
      string _s2 = "/datadump/savanet/estimates/split/200701.csv";
      if(s2.compare(_s2)!=0) val++;
   }

   {
      UtilDate* d1 = UtilDate::instance(2007,1,13);
      UtilDate* d2 = UtilDate::instance(2007,2,14);
      UtilDate* d = UtilDate::instance(2007,1,31);

      if(d2->isBefore(d1)) val++;
      if(d1->isAfter(d2)) val++;
      if(d2->isBefore(d2)) val++;
      if(d2->isAfter(d2)) val++;
      if(! d->isBetween(d1,d2) ) val++;
      if(! d1->isBetween(d1,d2,true,false) ) val++;
      if(! d2->isBetween(d1,d2,false,true) ) val++;
      if(d1->isBetween(d,d2)) val++;
   }

   {
      UtilDate* d = NULL;
      d = UtilDate::format("20080123","yyyymmdd");
      if(d!=UtilDate::instance(2008,1,23)) val++;
      d = UtilDate::format("2002-01-23","yyyy-mm-dd");
      if(d!=UtilDate::instance(2002,1,23)) val++;
   }

   {
      UtilDate* d = NULL;
      d = UtilDate::eom(UtilDate::instance(2008,2,1)); 
      if(d!=UtilDate::instance(2008,2,29)) val++;
      d = UtilDate::eom(UtilDate::instance(2008,3,1)); 
      if(d!=UtilDate::instance(2008,3,31)) val++;
      d = UtilDate::prev_eom(UtilDate::instance(2008,1,31),3);
      if(d!=UtilDate::instance(2007,10,31)) val++;
      d = UtilDate::next_eom(UtilDate::instance(2008,1,31),3);
      if(d!=UtilDate::instance(2008,4,30)) val++;
      d = UtilDate::next_eom(UtilDate::instance(2008,1,31),1);
      if(d!=UtilDate::instance(2008,2,29)) val++;
   }

   {
      list<UtilDate*> L;
      list<UtilDate*>::iterator it;
      list<UtilDate*>* sL;
      UtilDate* a[4];
      UtilDate* b[4];
      int i;

      i = 0;
      L.push_back(a[i++]=UtilDate::instance(2008,2,24));
      L.push_back(a[i++]=UtilDate::instance(2008,1,12));
      L.push_back(a[i++]=UtilDate::instance(2008,3,11));
      L.push_back(a[i++]=UtilDate::instance(2007,12,12));

      i = 0;
      b[i++] = a[3];
      b[i++] = a[1];
      b[i++] = a[0];
      b[i++] = a[2];

      sL = UtilDate::sort_algo_insertion(&L);

      i = 0;
      for(it=sL->begin();it!=sL->end();it++) if((*it)!=b[i++]) val++;

      //clean memory
      delete sL;
   }

   {
      set<UtilDate*> L;
      list<UtilDate*>::iterator it;
      list<UtilDate*>* sL;
      UtilDate* a[4];
      UtilDate* b[4];
      int i;

      i = 0;
      L.insert(a[i++]=UtilDate::instance(2008,2,24));
      L.insert(a[i++]=UtilDate::instance(2008,1,12));
      L.insert(a[i++]=UtilDate::instance(2008,3,11));
      L.insert(a[i++]=UtilDate::instance(2007,12,12));

      i = 0;
      b[i++] = a[3];
      b[i++] = a[1];
      b[i++] = a[0];
      b[i++] = a[2];

      sL = UtilDate::sort_algo_insertion(&L);

      i = 0;
      for(it=sL->begin();it!=sL->end();it++) if((*it)!=b[i++]) val++;

      //clean memory
      delete sL;
   }

   {
      UtilDate* d1 = UtilDate::eom(2008,1);
      UtilDate* d2 = UtilDate::eom(2008,5);
      UtilDate* d3 = UtilDate::eom(2008,9);
      UtilDate* d4 = UtilDate::eom(2009,1);
      UtilDate* d5 = UtilDate::eom(2009,5);

      if(UtilDate::nmonths(d1,d2)!=4) val++;
      if(UtilDate::nmonths(d3,d2)!=-4) val++;
      if(UtilDate::nmonths(d3,d4)!=4) val++;
      if(UtilDate::nmonths(d1,d5)!=16) val++;
   }

   {
      vector<UtilDate*> dV;
      UtilDate* d = UtilDate::eom(2011,1);
      UtilDate::eoq(d,&dV);
      int i;

      i = 0;
      if(dV[i++]!=UtilDate::eom(2010,4)) val++;
      if(dV[i++]!=UtilDate::eom(2010,7)) val++;
      if(dV[i++]!=UtilDate::eom(2010,10)) val++;
      if(dV[i++]!=UtilDate::eom(2011,1)) val++;
   }

   {
      if(UtilDate::instance("D20100103")!=UtilDate::instance(2010,1,3)) val++;
   }

   {
      UtilDate* d = NULL;

      d = UtilDate::instance(2011,1,20);
      if(UtilDate::next_d(d)!=UtilDate::instance(2011,1,21)) val++;
      if(UtilDate::next_d(d,11)!=UtilDate::instance(2011,1,31)) val++;
      if(UtilDate::next_d(d,12)!=UtilDate::instance(2011,2,1)) val++;

      if(UtilDate::prev_d(d)!=UtilDate::instance(2011,1,19)) val++;
      if(UtilDate::prev_d(d,20)!=UtilDate::instance(2010,12,31)) val++;
      if(UtilDate::prev_d(d,19)!=UtilDate::instance(2011,1,1)) val++;
   }

   {
      vector<UtilDate*> dv(3);
      dv[0] = UtilDate::instance(2010,1,12);
      dv[1] = UtilDate::instance(1998,1,12);
      dv[2] = UtilDate::instance(2015,1,12);

      if(UtilDate::max(&dv)!=dv[2]) val++;
      if(UtilDate::min(&dv)!=dv[1]) val++;
   }

   {
      UtilDate* d = NULL;

      d = UtilDate::instance(2011,1,20);
      if(UtilDate::next_m(d)!=UtilDate::instance(2011,2,20)) val++;
      d = UtilDate::eom(2011,1);
      if(UtilDate::next_m(d,1)!=UtilDate::instance(2011,2,28)) val++;
      d = UtilDate::instance(2012,11,28);
      if(UtilDate::next_m(d,2)!=UtilDate::instance(2013,1,28)) val++;

      d = UtilDate::instance(2011,1,20);
      if(UtilDate::prev_m(d)!=UtilDate::instance(2010,12,20)) val++;
      d = UtilDate::eom(2011,1);
      if(UtilDate::prev_m(d,1)!=UtilDate::instance(2010,12,31)) val++;
      d = UtilDate::instance(2012,11,28);
      if(UtilDate::prev_m(d,2)!=UtilDate::instance(2012,9,28)) val++;
   }

   {
      UtilDate* d1 = UtilDate::eom(2006,1);
      UtilDate* d2 = UtilDate::eom(2016,7);
      list<UtilDate*> dL;
      list<UtilDate*>::iterator it;
      UtilDate::eoqL(d1,d2,&dL);
   }

   {
      if(! UtilDate::isEmpty("")) val++;
      if(! UtilDate::isEmpty("NA")) val++;
      if(UtilDate::format("","yyyymmdd")!=NULL) val++;
      if(UtilDate::format("NA","yyyymmdd")!=NULL) val++;
      if(UtilDate::format("20131231","yyyymmdd")==NULL) val++;
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

