#include <stdio.h>
#include <string>
#include <map>
#include <iostream>
#include <fstream>

using namespace std;

int main1() {
   int val1;
   double val2;
   string val3;

   cin >> val1; printf("val1 = %d\n",val1);
   cin >> val2; printf("val2 = %2.8f\n",val2);
   cin >> val3; printf("val3 = %s\n",val3.c_str());

   return 0;
}

template<typename T>
void read_generic(string fname, T& val) {
   ifstream fp;
   fp.open(fname,ios::in);
   fp >> val;
   fp.close();
}

int main2() {
   int val1;
   double val2;
   string val3;

   read_generic("input/tmp_int.txt",val1); printf("val1 = %d\n",val1);
   read_generic("input/tmp_double.txt",val2); printf("val2 = %2.8f\n",val2);
   read_generic("input/tmp_string.txt",val3); printf("val3 = %s\n",val3.c_str());

   return 0;
}

void read_intarr(string fname, int*& x, int& n) {
   ifstream fp;
   fp.open(fname,ios::in);
   fp >> n;
   x = new int[n];
   for(int i=0;i<n;i++) fp >> x[i];
   fp.close();
}

int main() {
   int* x = NULL;
   int n;
   string fname;

   fname = "input/tmp_intarr.txt";
   read_intarr(fname,x,n);
   printf("n = %d\n",n);
   for(int i=0;i<n;i++) printf("%d ",x[i]);
   printf("\n");

   return 0;
}

