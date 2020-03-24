#include <iostream>
#include <algorithm>

struct mycomparison
{
   bool operator() (int* lhs, int* rhs) {return (*lhs) < (*rhs);}
};

int main(int argc, char* argv[])
{
   int myarray[] = {1, 3, 6, 2, 4, 9, 5, 12, 10};
   const size_t size = sizeof(myarray) / sizeof(myarray[0]);
   int *arrayofpointers[size];
   for(int i = 0; i < size; ++i)
   {
      arrayofpointers[i] = myarray + i;
   }
   std::sort(arrayofpointers, arrayofpointers + size, mycomparison());
   for(int i = 0; i < size; ++i)
   {
      *arrayofpointers[i] = i + 1;
   }
   for(int i = 0; i < size; ++i)
   {
      std::cout << myarray[i] << " ";
   }
   std::cout << std::endl;
   return 0;
}
