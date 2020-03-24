#include <stdio.h>
#include <map>
#include <set>
#include <list>

using namespace std;

int main_map() {
   map<int,string> m;
   map<int,string>::iterator it;

   m[20100211] = "a";
   m[20100216] = "b";
   m[20100220] = "c";

   it = m.lower_bound(20100222);
   if(it==m.end()) printf("no closest match found\n");
   it = m.lower_bound(20100202);
   printf("%d %s\n",it->first,it->second.c_str());
   it = m.lower_bound(20100215);
   printf("%d %s\n",it->first,it->second.c_str());
   it = m.lower_bound(20100216);
   printf("%d %s\n",it->first,it->second.c_str());
   it = m.lower_bound(20100217);
   printf("%d %s\n",it->first,it->second.c_str());

   return 0;
}

int main_set() {
   set<int> m;
   set<int>::iterator it;
   int num;
   list<int> L;
   list<int>::iterator itL;

   m.insert(20100211);
   m.insert(20100216);
   m.insert(20100220);

   L.push_back(20100222);
   L.push_back(20100210);
   L.push_back(20100214);

   for(itL=L.begin();itL!=L.end();itL++) {
      num = *itL;

      printf("%s::lower_bound\n",__FUNCTION__);
      it = m.lower_bound(num);
      if(it==m.end()) printf("num = %d no closest match found end reached \n",num);
      else if(it==m.begin()) printf("num = %d no closest match found begin reached\n",num);
      else printf("num = %d closest match = %d\n",num,(*it));

      printf("%s::upper_bound\n",__FUNCTION__);
      it = m.upper_bound(num);
      if(it==m.end()) printf("num = %d no closest match found end reached \n",num);
      else if(it==m.begin()) printf("num = %d no closest match found begin reached\n",num);
      else printf("num = %d closest match = %d\n",num,(*it));
   }

   return 0;
}



int main() {
   int val = 0;
   val += main_map();
   val += main_set();
   return val;
}

