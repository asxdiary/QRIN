#include <iomanip>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "pkgMath.hpp"
#include "Matrix.hpp"
#include "ext_lapacke.hpp"
#include "StatUtils.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMath;
using namespace aiExt;
using namespace aiStatUtils;

int TestMatrix_main() {
   printf("UnitTest %s\n",__FUNCTION__);

   int val = 0;
   const string ipfx = "input/TestMatrix.";
   const string opfx = "output/TestMatrix.";

   {
      string id = "colrank.";
      Matrix* X = NULL;
      Matrix* cr = NULL;
      Matrix* _cr = NULL;

      X = Matrix::instance_fread_table(ipfx + id + "X.csv");
      _cr = Matrix::instance_fread_table(ipfx + id + "cr.csv");
      cr = X->colrank(0);

      if(!cr->isEqual(_cr)) val++;

      //clean memory
      delete X;
      delete cr;
      delete _cr;
   }

   {
      string id = "concat3_col.";
      Matrix** mA = NULL;
      Matrix* X = NULL;
      Matrix* _X = NULL;
      string* pfx = NULL;
      int T;

      mA = new Matrix*[3];
      pfx = new string[3];

      T = 0;
      mA[T++] = Matrix::instance_fread_table(ipfx + id + "X1.csv");
      mA[T++] = Matrix::instance_fread_table(ipfx + id + "X2.csv");
      mA[T++] = Matrix::instance_fread_table(ipfx + id + "X3.csv");
      _X = Matrix::instance_fread_table(ipfx + id + "X.csv");

      T = 0;
      pfx[T++] = "X1";
      pfx[T++] = "X2";
      pfx[T++] = "X3";

      X = Matrix::concat3_col(T, mA, pfx);
      if(!X->isEqual(_X)) val++;

      //clean memory
      for(int t=0;t<T;t++) delete mA[t];
      delete [] mA;
      delete X;
      delete _X;
      delete [] pfx;
   }

   {
      const int m = 3;
      const int n = 4;
      double** XX = NULL;
      double tmp = 1;
      Matrix* X = NULL;
      string fname;

      fname = string(opfx).append("ex1");
      XX = util_matrix(m,n,tmp);
      X = Matrix::instance(m,n,XX);
      X->fprint(fname);

      {
         Matrix* cpy = X->copy();
         if(!Matrix::isEqual(X,cpy)) val++;
         if(!X->isEqual(cpy)) val++;
         if(!cpy->isEqual(X)) val++;
         delete cpy;
      }

      //clean memory
      delete X;
   }

   {
      Matrix* X = NULL;
      string fname;

      fname = string(ipfx).append("ex2");
      X = Matrix::instance_fscan(fname);
      fname = string(opfx).append("ex2");
      X->fprint(fname);

      {
         Matrix* cpy = X->copy();
         if(!Matrix::isEqual(X,cpy)) val++;
         delete cpy;
      }

      //clean memory
      delete X;
   }

   {
      const int m = 3;
      const int n = 4;
      double** XX = NULL;
      double tmp = 1;
      Matrix* X = NULL;
      string* rmap = NULL;
      string* cmap = NULL;
      string fname;

      fname = string(opfx).append("ex3");
      rmap = util_names("R",m);
      cmap = util_names("C",n);
      XX = util_matrix(m,n,tmp);
      for(int i=0;i<m;i++) {
         for(int j=0;j<n;j++) {
            XX[i][j] = i*100 + j - 12;
         }
      }
      X = Matrix::instance(m,n,XX,rmap,NULL,cmap,NULL);
      X->fprint(fname);
      X->fprint_table(fname + ".table.csv");

      {
         Matrix* cpy = X->copy();
         if(!Matrix::isEqual(X,cpy)) val++;
         delete cpy;
      }

      //clean memory
      delete X;
   }

   {
      Matrix* X = NULL;
      string fname;

      fname = string(ipfx).append("ex4");
      X = Matrix::instance_fscan(fname);
      fname = string(opfx).append("ex4");
      X->fprint(fname);
      X->_transpose();
      X->_transpose();

      {
         Matrix* XT = NULL;
         Matrix* XTT = NULL;

         XT = X->transpose();
         XTT = Matrix::transpose(XT);

         if(!XTT->isEqual(X)) val++;
         XT->fprint(opfx + "ex4.XT");

         //clean memory
         delete XT;
         delete XTT;
      }

      {
         Matrix* cpy = X->copy();
         if(!Matrix::isEqual(X,cpy)) val++;
         delete cpy;
      }

      {
         const double fac = 3.5;
         Matrix* m1 = Matrix::mult(X,fac);
         Matrix* m2 = Matrix::mult(m1,1.0/fac);

         if(!Matrix::isEqual(m2,X)) val++;
         if(Matrix::isEqual(m2,m1)) val++;

         //clean memory
         delete m1;
         delete m2;
      }

      //clean memory
      delete X;
   }

   {
      Matrix* X1 = NULL;
      Matrix* X2 = NULL;
      Matrix* Y = NULL;
      Matrix* _Y = NULL;
      
      X1 = Matrix::instance_fscan(ipfx + "add.ex1.X1");
      X2 = Matrix::instance_fscan(ipfx + "add.ex1.X2");
      _Y = Matrix::instance_fscan(ipfx + "add.ex1.Y");

      {
         Matrix** arr = NULL;
         arr = new Matrix*[2];
         arr[0] = X1;
         arr[1] = X2;
         util_fprint_obj(opfx + "matarray_fprint",(Object**)arr,2);
         arr[0] = Matrix::instance_fscan(util_ofname(opfx + "matarray_fprint",0));
         arr[1] = Matrix::instance_fscan(util_ofname(opfx + "matarray_fprint",1));

         //clean memory
         for(int i=0;i<2;i++) delete arr[i];
         delete [] arr;
      }

      Y = Matrix::add(X1,X2);
      if(! Y->isEqual(_Y)) val++;

      //clean memory
      delete X1;
      delete X2;
      delete Y;
      delete _Y;
   }

   //Test mult, vectorize, inverse and sub
   {
      Matrix* X1 = NULL;
      Matrix* X2 = NULL;
      Matrix* X1T = NULL;
      Matrix* X2T = NULL;
      Matrix* _X = NULL;
      Matrix* _XT = NULL;
      Matrix* X = NULL;
      int ctr = 0;

      X1 = Matrix::instance_fscan(ipfx + "mult.ex.X1");
      X2 = Matrix::instance_fscan(ipfx + "mult.ex.X2");
      _X = Matrix::instance_fscan(ipfx + "mult.ex.X");
      X1T = Matrix::transpose(X1);
      X2T = Matrix::transpose(X2);
      _XT = Matrix::transpose(_X);

      X1->set_rmap_rimap(util_names("row_X1_",X1->m()),NULL);
      X1->set_cmap_cimap(util_names("col_X1_",X1->n()),NULL);
      X2->set_rmap_rimap(util_names("row_X2_",X2->m()),NULL);
      X2->set_cmap_cimap(util_names("col_X2_",X2->n()),NULL);

      X = Matrix::mult(X1,X2);
      X->fprint(opfx + "mult_X" + to_string(ctr++));
      if(! X->isEqual(_X)) val++;
      delete X; X = NULL;

      X = Matrix::mult(X1T,X2,true,false);
      X->fprint(opfx + "mult_X" + to_string(ctr++));
      if(! X->isEqual(_X)) val++;
      delete X; X = NULL;

      X = Matrix::mult(X1,X2T,false,true);
      X->fprint(opfx + "mult_X" + to_string(ctr++));
      if(! X->isEqual(_X)) val++;
      delete X; X = NULL;

      X = Matrix::mult(X1T,X2T,true,true);
      X->fprint(opfx + "mult_X" + to_string(ctr++));
      if(! X->isEqual(_X)) val++;
      delete X; X = NULL;

      X = Matrix::mult(X2,X1,true,true);
      X->fprint(opfx + "mult_X" + to_string(ctr++));
      if(! X->isEqual(_XT)) val++;
      delete X; X = NULL;

      {
         const int m = X1->m();
         const int n = X1->n();
         double* vec = ext_lapacke_vectorize(X1,true);
         Matrix* X1c = ext_lapacke_devectorize(vec, m, n);
         if(!X1c->isEqual(X1)) val++;

         //clean memory
         delete [] vec;
         delete X1c;
      }

      {
         Matrix* XXT = Matrix::mult(X1,X1,false,true);
         Matrix* XXTI = Matrix::inverse(XXT);
         Matrix* I = Matrix::mult(XXT,XXTI);
         Matrix* _I = Matrix::identity(I->m());
         if(!I->isEqual(_I)) val++;

         //clean memory
         delete XXT;
         delete XXTI;
         delete I;
         delete _I;
      }

      {
         set<int>* rS = NULL;
         set<int>* cS = NULL;
         set<int>* xrS = NULL;
         set<int>* xcS = NULL;
         Matrix* Y = NULL;
         Matrix* _Y = NULL;
         int* ra = NULL;
         int* ca = NULL;
         int T;

         T = 0;

         Y = X1->sub(rS,cS,xrS,xcS);
         _Y = Matrix::instance_fscan(ipfx + "sub.ex" + to_string(T++));
         if(! _Y->isEqual(Y) ) val++;
         delete rS; delete cS; delete xrS; delete xcS; delete Y; delete _Y;
         rS = cS = xrS = xcS = NULL; Y = _Y = NULL;

         rS = new set<int>();
         rS->insert(1);
         rS->insert(2);
         Y = X1->sub(rS,cS,xrS,xcS,&ra,&ca);
         _Y = Matrix::instance_fscan(ipfx + "sub.ex" + to_string(T++));
         if(! _Y->isEqual(Y) ) val++;
         delete rS; delete cS; delete xrS; delete xcS; delete Y; delete _Y;
         delete [] ra; ra=NULL;
         delete [] ca; ca=NULL;
         rS = cS = xrS = xcS = NULL; Y = _Y = NULL;

         cS = new set<int>();
         cS->insert(0);
         cS->insert(3);
         Y = X1->sub(rS,cS,xrS,xcS);
         _Y = Matrix::instance_fscan(ipfx + "sub.ex" + to_string(T++));
         if(! _Y->isEqual(Y) ) val++;
         delete rS; delete cS; delete xrS; delete xcS; delete Y; delete _Y;
         rS = cS = xrS = xcS = NULL; Y = _Y = NULL;

         xrS = new set<int>();
         xrS->insert(0);
         Y = X1->sub(rS,cS,xrS,xcS);
         _Y = Matrix::instance_fscan(ipfx + "sub.ex" + to_string(T++));
         if(! _Y->isEqual(Y) ) val++;
         delete rS; delete cS; delete xrS; delete xcS; delete Y; delete _Y;
         rS = cS = xrS = xcS = NULL; Y = _Y = NULL;

         xcS = new set<int>();
         xcS->insert(2);
         Y = X1->sub(rS,cS,xrS,xcS);
         _Y = Matrix::instance_fscan(ipfx + "sub.ex" + to_string(T++));
         if(! _Y->isEqual(Y) ) val++;
         delete rS; delete cS; delete xrS; delete xcS; delete Y; delete _Y;
         rS = cS = xrS = xcS = NULL; Y = _Y = NULL;

      }

      //clean memory
      delete X1;
      delete X2;
      delete _X;
      delete X1T;
      delete X2T;
      delete _XT;
      delete X;
   }

   //Test devectorize with Dflag and Iflag turned on
   {
      const int m = 5;
      Matrix* X = NULL;
      Matrix* XD = NULL;
      Matrix* XDI = NULL;
      Matrix* _XD = NULL;
      Matrix* _XDI = NULL;
      double* vec = NULL;


      X = Matrix::instance_fscan(ipfx + "devectorize.X");
      _XD = Matrix::instance_fscan(ipfx + "devectorize.XD");
      _XDI = Matrix::instance_fscan(ipfx + "devectorize.XDI");

      vec = ext_lapacke_vectorize(X,true);
      XD = ext_lapacke_devectorize(vec,m,m,true,false);
      XDI = ext_lapacke_devectorize(vec,m,m,true,true);

      if(! XD->isEqual(_XD)) val++;
      if(! XDI->isEqual(_XDI)) val++;

      //clean memory
      delete XD;
      delete XDI;
      delete _XD;
      delete _XDI;
      delete [] vec;
      delete X;
   }

   {
      Matrix* X = NULL;
      Matrix* XXT = NULL;
      Matrix* XI = NULL;
      Matrix* XXTI = NULL;
      Matrix* _I = NULL;
      Matrix* I = NULL;

      X = Matrix::instance_fscan(ipfx + "inverse.ex1");
      _I = Matrix::identity(X->m());
      XI = Matrix::inverse(X);

      I = Matrix::mult(X,XI);
      if(!I->isEqual(_I)) val++;
      delete I; I = NULL;

      I = Matrix::mult(XI,X);
      if(!I->isEqual(_I)) val++;
      delete I; I = NULL;

      XXT = Matrix::mult(X,X,false,true);

      for(int i=0;i<2;i++) {
         if(i==0) XXTI = Matrix::inverse(XXT);
         else XXTI = Matrix::inverse_psd(XXT);
         I = Matrix::mult(XXT,XXTI);
         if(!I->isEqual(_I)) val++;
         delete I; I = NULL;
         delete XXTI; XXTI = NULL;
      }

      //clean memory
      delete X;
      delete XXT;
      delete XI;
      delete XXTI;
      delete _I;
      delete I;
   }

   //Test solve
   {
      Matrix* A = NULL;
      Matrix* ATA = NULL;
      Matrix* b = NULL;
      Matrix* x = NULL;
      Matrix* Ax = NULL;
      Matrix* y = NULL;
      Matrix* ATAy = NULL;

      A = Matrix::instance_fscan(ipfx + "solve.ex1.A");
      b = Matrix::instance_fscan(ipfx + "solve.ex1.b");
      x = Matrix::solve(A,b);
      Ax = Matrix::mult(A,x);

      ATA = Matrix::mult(A,A,true,false);
      y = Matrix::solve_sym(ATA,b);
      ATAy = Matrix::mult(ATA,y);

      if(!Ax->isEqual(b)) val++;
      if(!ATAy->isEqual(b)) val++;

      //clean memory
      delete A;
      delete b;
      delete ATA;
      delete x;
      delete Ax;
      delete y;
      delete ATAy;
   }

   {
      string exS = "ex5.";
      Matrix* X = NULL;
      Matrix* DeltaR = NULL;
      Matrix* DeltaC = NULL;
      Matrix* XR = NULL;
      Matrix* XC = NULL;
      Matrix* _XR = NULL;
      Matrix* _XC = NULL;

      X = Matrix::instance_fscan(ipfx + exS + "X");
      DeltaR = Matrix::instance_fscan(ipfx + exS + "DeltaR");
      DeltaC = Matrix::instance_fscan(ipfx + exS + "DeltaC");
      _XR = Matrix::instance_fscan(ipfx + exS + "XR");
      _XC = Matrix::instance_fscan(ipfx + exS + "XC");
      XR = Matrix::rhmult(X,DeltaR);
      XC = Matrix::chmult(X,DeltaC);

      if(!XR->isEqual(_XR)) val++;
      if(!XC->isEqual(_XC)) val++;

      //clean memory
      delete XR;
      delete XC;
      delete _XR;
      delete _XC;
      delete DeltaR;
      delete DeltaC;
      delete X;
   }

   {
      string exS = "lift.ex1.";
      Matrix* X = NULL;
      Matrix* Y = NULL;
      Matrix* _Y = NULL;
      int* ca = NULL;
      int* ra = NULL;

      X = Matrix::instance_fscan(ipfx + exS + "X");
      _Y = Matrix::instance_fscan(ipfx + exS + "Y");

      ca = util_rangeA(0,4);
      ca[0] = 5; ca[1] = 6;
      ra = util_rangeA(0,3);
      for(int i=0;i<3;i++) ra[i] = ra[i]+1;
      Y = X->lift(4,7,ra,ca);

      if(!Y->isEqual(_Y)) val++;

      //clean memory
      delete X;
      delete Y;
      delete _Y;
      delete [] ca;
      delete [] ra;
   }

   {
      string exS = "l2closest.ex1.";
      Matrix* X = NULL;
      Matrix* Y = NULL;

      X = Matrix::instance_fscan(ipfx + exS + "X");
      Y = Matrix::instance_fscan(ipfx + exS + "Y");

      if(X->l2closest(Y,5,true)!=7) val++;

      //clean memory
      delete X;
      delete Y;
   }

   {
      string exS = "pct.ex1.";
      Matrix* X = NULL;
      Matrix* medX = NULL;
      Matrix* _medX = NULL;
      set<int>* S = NULL;

      X = Matrix::instance_fscan(ipfx + exS + "X");
      _medX = Matrix::instance_fscan(ipfx + exS + "medX");
      S = util_rangeS(1,15);
      medX = X->pct(0.5, true, S);

      if(!medX->isEqual(_medX)) val++;

      //clean memory
      delete X;
      delete medX;
      delete _medX;
      delete S;
   }

   {
      string exS = "winsorize.ex1.";
      Matrix* X = NULL;
      Matrix* winX = NULL;
      Matrix* _winX = NULL;

      X = Matrix::instance_fscan(ipfx + exS + "X");

      winX = Matrix::winsorize(X, false, 0.1,0.9);
      _winX = Matrix::instance_fscan(ipfx + exS + "winX");

      if(! winX->isEqual(_winX) ) val++;

      //clean memory
      delete X;
      delete winX;
      delete _winX;
   }

   {
      string exS = "winsorize.ex1.";
      Matrix* X = NULL;
      Matrix* l2 = NULL;
      Matrix* _winX = NULL;
      Matrix* _l2 = NULL;

      X = Matrix::instance_fscan(ipfx + exS + "X");
      l2 = X->l2nc(true, true, 0.1, 0.9);

      _winX = Matrix::instance_fscan(ipfx + exS + "winX");
      _l2 = _winX->l2nc(true);

      if(! l2->isEqual(_l2) ) val++;

      //clean memory
      delete X;
      delete l2;
      delete _l2;
      delete _winX;
   }

   {
      string exS = "winsorize.ex2.";
      Matrix* X = NULL;
      Matrix* l2 = NULL;
      Matrix* _winX = NULL;
      Matrix* _l2 = NULL;
      Matrix* Delta = NULL;

      X = Matrix::instance_fread_table(ipfx + exS + "X");
      Delta = Matrix::ones(X->m(),1);
      l2 = X->l2nc(true, true, 0.1, 0.9, Delta, true);

      _winX = Matrix::instance_fread_table(ipfx + exS + "winX");
      _l2 = _winX->l2nc(true);

      if(! l2->isEqual(_l2) ) val++;

      //clean memory
      delete X;
      delete l2;
      delete _l2;
      delete _winX;
      delete Delta;
   }

   {
      string exS = "mean.ex1.";
      Matrix* rDelta = NULL;
      Matrix* cDelta = NULL;
      Matrix* X = NULL;
      Matrix* cmX = NULL;
      Matrix* rmX = NULL;
      Matrix* _cmX = NULL;
      Matrix* _rmX = NULL;
      Matrix* cmDeltaX = NULL;
      Matrix* rmDeltaX = NULL;
      Matrix* _cmDeltaX = NULL;
      Matrix* _rmDeltaX = NULL;

      X = Matrix::instance_fscan(ipfx + exS + "X");
      rDelta = Matrix::instance_fscan(ipfx + exS + "rDelta");
      cDelta = Matrix::instance_fscan(ipfx + exS + "cDelta");

      rmX = X->mean_row(NULL,true);
      cmX = X->mean_col(NULL,true);
      _rmX = Matrix::instance_fscan(ipfx + exS + "rmX");
      _cmX = Matrix::instance_fscan(ipfx + exS + "cmX");
      if(! _rmX->isEqual(rmX) ) val++;
      if(! _cmX->isEqual(cmX) ) val++;

      rmDeltaX = X->mean_row(rDelta,false);
      cmDeltaX = X->mean_col(cDelta,false);
      _rmDeltaX = Matrix::instance_fscan(ipfx + exS + "rmDeltaX");
      _cmDeltaX = Matrix::instance_fscan(ipfx + exS + "cmDeltaX");
      if(! _rmDeltaX->isEqual(rmDeltaX) ) val++;
      if(! _cmDeltaX->isEqual(cmDeltaX) ) val++;

      //clean memory
      delete X;

      delete rmX;
      delete cmX;
      delete _rmX;
      delete _cmX;
      delete rmDeltaX;
      delete cmDeltaX;
      delete _rmDeltaX;
      delete _cmDeltaX;

      delete rDelta;
      delete cDelta;
   }

   {
      string exS = "cmap_cimap.ex1.";
      Matrix* X = Matrix::instance(10,2);
      X->set_cmap_cimap(0,"asx_col0");
      X->set_rmap_rimap(5,"asx_row5");
      delete X;
   }

   {
      string exS = "fread_table.ex1.csv";
      Matrix* X = Matrix::instance_fread_table(ipfx + exS);
      X->fprint_table(opfx + exS);
      Matrix* Y = Matrix::instance_fread_table(opfx + exS);
      if(!Y->isEqual(X)) val++;

      //clean memory
      delete X;
      delete Y;
   }

   {
      Matrix* X = Matrix::ones(127,1);
      if(X->cc(false,0) != 127) val++;
      delete X;
   }

   {
      int n = 19;
      Matrix* X = Matrix::instance(n,1);
      double cc = 13.8648648648649000;
      double ccS = 3.9389067524115800;
      set<int> S;

      for(int i=0;i<n;i++) X->X()[i][0] = i;
      if(!util_isEqual(X->cc(false,0),cc)) val++;

      S.insert(0);
      S.insert(1);
      S.insert(2);
      S.insert(4);
      S.insert(5);
      S.insert(11);
      S.insert(12);

      if(!util_isEqual(X->cc(false,0,&S),ccS)) val++;

      //clean memory
      delete X;
   }

   {
      unordered_map<string,double> valm;
      Matrix* X = NULL;

      valm["b"] = 2;
      valm["a"] = 1;
      valm["c"] = 3;
      X = Matrix::instance_col(&valm);

      //clean memory
      delete X;
   }

   {
      string exS = "sub.";
      Matrix* X1 = NULL;
      Matrix* X2 = NULL;
      Matrix* X = NULL;

      X1 = Matrix::instance_fread_table(ipfx + exS + "X1.csv");
      X2 = Matrix::instance_fread_table(ipfx + exS + "X2.csv");

      X = X1->sub(X2,true,true);

      delete X1;
      delete X2;
      delete X;
   }

   return val;
}

