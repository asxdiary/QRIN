#include <stdio.h>
#include <string>
#include <map>

using namespace std;

int main() {
   string s1;
   string s2("a");
   string s3("a");
   map<string,int> m;

   m[s2] = 10;

   printf("s1 %s\n",s1.c_str());
   printf("s2 %s\n",s2.c_str());
   printf("s3 %s\n",s3.c_str());
   printf("m[s2] %d\n",m[s2]);
   printf("m[s3] %d\n",m[s3]);
   if(s2==s3) printf("s2==s3\n");
   s3.assign("b");
   if(s2!=s3) printf("s2!=s3\n");

   char msg[1000];

   sprintf(msg,"Printing message s1=%s s2=%s s3=%s\n",s1.c_str(),s2.c_str(),s3.c_str());
   printf("%s",string(msg).c_str());

   string s4;
   s4.append("Trying append function ");
   s4.append("s1 = "); s4.append(s1);
   s4.append("s2 = "); s4.append(s2);
   s4.append("s3 = "); s4.append(s3);

   printf("s4 = %s\n",s4.c_str());

   return 0;
}

