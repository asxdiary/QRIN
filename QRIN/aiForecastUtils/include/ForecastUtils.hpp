// Name:     ForecastUtils.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ForecastUtils_hpp
#define ASX_ForecastUtils_hpp

#include "Utils.hpp"
#include "Matrix.hpp"
#include "UtilDate.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMath;

namespace aiForecastUtils {

   Matrix* ForecastUtils_concat(unordered_map<UtilDate*,Matrix*>* Xm);
   Matrix* ForecastUtils_concat(unordered_map<string,unordered_map<UtilDate*,Matrix*>*>* sm);
   Matrix* ForecastUtils_extract_data(unordered_map<UtilDate*,Matrix*>* Xm, 
                                      UtilDate* d, const int lag);

   void ForecastUtils_fprint_split(unordered_map<UtilDate*,Matrix*>* Xm, string pfx);
   void ForecastUtils_fread_split(unordered_map<UtilDate*,Matrix*>*& Xm, 
                                  UtilDate* da,
                                  UtilDate* db,
                                  string pfx);
   void ForecastUtils_cleanMem(unordered_map<UtilDate*,Matrix*>*& Xm);

};

#endif


