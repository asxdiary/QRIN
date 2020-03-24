// Name:     pkgUtils.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_pkgUtils_cpp
#define ASX_pkgUtils_cpp

#include "pkgUtils.hpp"
#include "UtilDate.hpp"

void aiUtils::pkgUtils_cleanup() {
   UtilDate::instance(-1,-1,-1);
   util_singleton("","");
   return;
}

#endif

