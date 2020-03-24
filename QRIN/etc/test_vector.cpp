#include <iostream>
#include <vector>

using namespace std;

int main ()
{
   int n = 4;
   vector<double> vec(n);

   for(int i=0;i<n;i++) vec[i] = 2*i+1;

   vec.push_back(1001);
   printf("size %zd\n",vec.size());
   for(int i=0;i<vec.size();i++) printf("vec[%d] = %2.8f\n",i,vec[i]);

   return 0;
}
