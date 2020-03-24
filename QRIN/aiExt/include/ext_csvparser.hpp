#ifndef ASX_EXT_CSVPARSER_H
#define ASX_EXT_CSVPARSER_H

#include <stdio.h>
#include <list>
#include <unordered_map>
#include "Utils.hpp"

using namespace std;
using namespace aiUtils;

namespace aiExt {

   typedef struct CsvRow {
      char **fields_;
      int numOfFields_;
   } CsvRow;

   typedef struct CsvParser {
      char *filePath_;
      char delimiter_;
      int firstLineIsHeader_;
      char *errMsg_;
      CsvRow *header_;
      FILE *fileHandler_;
      int fromString_;
      char *csvString_;
      int csvStringIter_;
   } CsvParser;


   // Public
   template<typename T1, typename T2>
      void CsvParser_readmap(string fname, 
                             string delimiter, 
                             const int firstLineIsHeader,
                             unordered_map<T1,T2>*& m);

   template<typename T>
      void CsvParser_readmatrix(int& m,
                                int& n,
                                T**& X,
                                string fname,
                                string delimiter, 
                                const int firstLineIsHeader,
                                string** headerp=NULL,
                                const int firstColIsPrimary=0,
                                string** rmapp=NULL);


      CsvParser *CsvParser_new(const char *filePath, const char *delimiter, int firstLineIsHeader);
   CsvParser *CsvParser_new_from_string(const char *csvString, const char *delimiter, int firstLineIsHeader);
   void CsvParser_destroy(CsvParser *csvParser);
   void CsvParser_destroy_row(CsvRow *csvRow);
   CsvRow *CsvParser_getHeader(CsvParser *csvParser);
   CsvRow *CsvParser_getRow(CsvParser *csvParser);
   int CsvParser_getNumFields(CsvRow *csvRow);
   char **CsvParser_getFields(CsvRow *csvRow);
   const char* CsvParser_getErrorMessage(CsvParser *csvParser);

   // Private
   CsvRow *_CsvParser_getRow(CsvParser *csvParser);    
   int _CsvParser_delimiterIsAccepted(const char *delimiter);
   void _CsvParser_setErrorMessage(CsvParser *csvParser, const char *errorMessage);

   //Template Implementations
   template<typename T>
   void CsvParser_readmatrix(int& m,
                                    int& n,
                                    T**& X,
                                    string fname,
                                    string delimiter, 
                                    const int firstLineIsHeader,
                                    string** headerp,
                                    const int firstColIsPrimary,
                                    string** rmapp)
   {
      if(!util_chk(fname)) err_msg("aiExt",__FUNCTION__,"File does not exist: fname =",fname);

      CsvParser* csvparser = NULL;
      CsvRow *row = NULL;
      CsvRow *header = NULL;
      list<T*>* XL = NULL;
      list<string> rnameL;
      unordered_map<int,string> mrmap;
      int jD = 0;

      csvparser = CsvParser_new(fname.c_str(), delimiter.c_str(), firstLineIsHeader);
      m = n = 0;

      if(firstLineIsHeader) {
         header = CsvParser_getHeader(csvparser);
         if(header==NULL) err_msg("aiExt::CsvParser_readmatrix header==NULL");
      }

      if(firstColIsPrimary) jD = 1; 

      if(headerp!=NULL) {
         if(!firstLineIsHeader) err_msg("aiExt::CsvParser_readmatrix headerp!=NULL && !firstLineIsHeader");
         char **rowFields = CsvParser_getFields(header);

         n = CsvParser_getNumFields(header);
         n -= jD;

         (*headerp) = new string[n];
         for(int j=0;j<n;j++) (*headerp)[j] = rowFields[j+jD];
      }

      XL = new list<T*>();
      for(m=n=0;(row = CsvParser_getRow(csvparser));m++,CsvParser_destroy_row(row)) {
         char **rowFields = CsvParser_getFields(row);
         T* arr = NULL;
         T val;
         n = CsvParser_getNumFields(row);

         n -= jD;

         arr = new T[n];
         for(int j=0;j<n;j++) {
            util_convert(rowFields[j+jD],val);
            arr[j] = val;
         }
         XL->push_back(arr);

         if(firstColIsPrimary) mrmap[m] = rowFields[0];
      }

      {
         typename list<T*>::iterator it;
         string* rmap = NULL;
         int i;

         X = new T*[m];
         if(firstColIsPrimary && rmapp!=NULL) (*rmapp) = rmap = new string[m];
         for(i=0, it=XL->begin();it!=XL->end();it++, i++) {
            X[i] = *it;
            if(rmap!=NULL) rmap[i] = mrmap[i];
         }
      }

      //clean memory
      delete XL;
      CsvParser_destroy(csvparser);

      return;
   }

   template<typename T1, typename T2>
      void CsvParser_readmap(string fname, 
                             string delimiter, 
                             const int firstLineIsHeader,
                             unordered_map<T1,T2>*& m) 
   {
      if(!util_chk(fname)) err_msg("aiExt",__FUNCTION__,"File does not exist: fname =",fname);
      CsvParser *csvparser = CsvParser_new(fname.c_str(), delimiter.c_str(), firstLineIsHeader);
      CsvRow *row;
      T1 key;
      T2 value;

      if(m==NULL) m = new unordered_map<T1,T2>();
      while ((row = CsvParser_getRow(csvparser)) ) {
         char **rowFields = CsvParser_getFields(row);
         util_convert(rowFields[0], key);
         util_convert(rowFields[1], value);
         (*m)[key] = value;
         CsvParser_destroy_row(row);
      }

      //clean memory
      CsvParser_destroy(csvparser);

      return;
   }



};

#endif
