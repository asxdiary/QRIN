// Name:     pkgFin.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_pkgFin_hpp
#define ASX_pkgFin_hpp

/** This contains the functions to cleanup the static objects that are created
 * in each package */

namespace aiFin {

   //Global variables for the package
   const string GICS_src = "aiFin/notes/GICS";

   void pkgFin_cleanup();

};

#endif

