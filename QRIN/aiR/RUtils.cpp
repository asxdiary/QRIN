// Name:     RUtils.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_RUtils_cpp
#define ASX_RUtils_cpp

#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <algorithm>
#include "RUtils.hpp"
#include "Utils.hpp"
#include "Object.hpp"
#include "Global.hpp"
#include "Utils_templates.hpp"
#include "Matrix.hpp"
#include "ext_csvparser.hpp"

using namespace aiR;
using namespace aiMath;
using namespace aiExt;

string aiR::rutil_rdir() {return Global::instance()->r_home();}
string aiR::rutil_tmpdir() {return Global::instance()->r_tmpdir();}

string aiR::rutil_wspfx(string func) {
   static int ctr = 0;
   list<string> L;
   L.push_back(rutil_tmpdir() + "_ai");
   L.push_back(util_string(getpid()));
   L.push_back(func);
   L.push_back(util_string(ctr++));
   L.push_back("");
   return util_joinL(".",&L);
}

Matrix* aiR::rutil_fscan_matrix(string fname) {
   Matrix* c = NULL;
   string** cS = NULL;
   double** cX = NULL;
   int m, n;

   CsvParser_readmatrix(m,n,cS,fname,Global::instance()->delimiter(),1);
   n--;

   c = Matrix::instance(m,n);
   cX = c->X();

   for(int i=0;i<m;i++) {
      for(int j=0;j<n;j++) cX[i][j] = atof(cS[i][j+1].c_str());
   }

   //clean memory
   util_clean(cS, m, n);

   return c;
}

string aiR::rutil_matrix_fname(string pfx, string vname, Matrix* X) {
   string fname = pfx + vname;
   if(X!=NULL) X->fprint_raw(fname);
   return util_ofname(fname,"X");
}

void aiR::rutil_exec(string prog, list<string>* argsL) {
   string cmd, cmdline;
   int val;

   cmd = "Rscript ";
   cmd.append(rutil_rdir());
   cmd.append(prog);

   cmdline = util_joinL(" ",argsL,cmd);
   //printf("%s::executing %s\n",__FUNCTION__,cmdline.c_str());

   val = system(cmdline.c_str());
   if(val!=0) err_msg("aiR::",__FUNCTION__," failed cmdline = ",cmdline);

   return;
}

#endif

