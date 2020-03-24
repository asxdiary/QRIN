#include <iostream>
#include <unordered_map>
#include "ext_csvparser.hpp"
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Global.hpp"

using namespace std;
using namespace aiExt;
using namespace aiUtils;

int Testext_csvparser_main() {
   int val = 0;

   {
      string fname = "input/Testext_csvparser1.txt";
      unordered_map<string,string>* m = NULL;
      string delimiter = Global::instance()->delimiter();
      CsvParser *csvparser = CsvParser_new(fname.c_str(), delimiter.c_str(), 0);
      CsvRow *row;
      string key, value;

      m = new unordered_map<string,string>();
      while ((row = CsvParser_getRow(csvparser)) ) {
         char **rowFields = CsvParser_getFields(row);
         key = rowFields[0];
         value = rowFields[1];
         (*m)[key] = value;
         CsvParser_destroy_row(row);
      }

      for(unordered_map<string,string>::iterator it=m->begin();it!=m->end();it++) {
         //cout << "key = " << it->first << " value = " << it->second << "\n";
      }

      //clean memory
      delete m;
      CsvParser_destroy(csvparser);
   }

   {
      string fname;
      string delimitor = "|";
      unordered_map<string,string>* m = NULL;
      
      fname = "input/Testext_csvparser1.txt";
      CsvParser_readmap(fname,delimitor,0, m); delete m; m = NULL;
      fname = "input/Testext_csvparser2.txt";
      CsvParser_readmap(fname,delimitor,1, m); delete m; m = NULL;
   }

   {
      string fname;
      string delimitor = "|";
      string** X = NULL;
      int m,n;
      
      fname = "input/Testext_csvparser3.txt";
      CsvParser_readmatrix(m,n,X,fname,delimitor, 0);

      //clean memory
      util_clean(X,m,n);
   }

   return val;
}

