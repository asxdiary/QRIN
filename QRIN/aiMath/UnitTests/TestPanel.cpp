#include "Utils.hpp"
#include "Panel.hpp"

using namespace aiUtils;
using namespace aiMath;

int TestPanel_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestPanel.";
   const string opfx = "output/TestPanel.";

   for(int k=0;k<2;k++) {
      string exS = "ex1";
      const int T = 3;
      Matrix** X = NULL;
      set<int>* mS = NULL;
      set<int>* nS = NULL;
      unordered_map<int,int>** mSm = NULL;
      unordered_map<int,int>** nSm = NULL;
      unordered_map<int,string>* rmap = NULL;
      unordered_map<int,string>* cmap = NULL;
      Panel* ptr = NULL;
      int t, i;

      {
         X = new Matrix*[T];
         for(int t=0;t<T;t++) X[t] = Matrix::instance_fscan(ipfx + exS + "_X" + to_string(t));
      }

      {
         mS = util_rangeS(1,5);
         nS = util_rangeS(0,3);

         rmap = new unordered_map<int,string>();
         cmap = new unordered_map<int,string>();
         for(int i=1;i<5;i++) (*rmap)[i] = string("Asset.") + to_string(i);
         for(int i=0;i<3;i++) (*cmap)[i] = string("Factor.") + to_string(i);
      }

      {
         mSm = new unordered_map<int,int>*[T];
         t = 0;

         mSm[t] = new unordered_map<int,int>();
         i = 0;
         (* (mSm[t]))[i++] = 1;
         (* (mSm[t]))[i++] = 2;
         (* (mSm[t]))[i++] = 4;

         t++;
         mSm[t] = new unordered_map<int,int>();
         i = 0;
         (* (mSm[t]))[i++] = 2;
         (* (mSm[t]))[i++] = 1;

         t++;
         mSm[t] = new unordered_map<int,int>();
         i = 0;
         (* (mSm[t]))[i++] = 1;
         (* (mSm[t]))[i++] = 2;
         (* (mSm[t]))[i++] = 4;
         (* (mSm[t]))[i++] = 3;
      }

      ptr = Panel::instance(T,X,mS,nS,mSm,nSm,rmap,NULL,cmap,NULL);
      if(k==1) {
         Panel* tmp = ptr->copy();
         delete ptr; ptr = tmp; tmp = NULL;
      }
      ptr->fprint(opfx + exS);

      {
         Panel* tmp = NULL;
         tmp = Panel::instance_fscan(opfx + exS);
         tmp->fprint(opfx + exS + ".copy");
         delete tmp;
      }

      {
         set<int>* rS = NULL;
         set<int>* cS = NULL;
         Panel* sub = NULL;

         rS = new set<int>();
         cS = new set<int>();
         rS->insert(2); rS->insert(3);
         cS->insert(1);

         sub = ptr->sub(rS,cS);
         sub->fprint(opfx + exS + ".sub");

         //clean memory
         delete sub;
         delete rS;
         delete cS;
      }

      if(1==0) {
         Matrix* X = NULL;
         set<int>* cS = NULL;
         set<int>* xcS = NULL;
         int* ca = NULL;

         cS = util_rangeS(0,3);
         xcS = new set<int>();
         xcS->insert(1);

         X = ptr->collapse(true,cS,xcS,&ca);
         X->fprint(opfx + exS + ".collapse");

         //clean memory
         delete X;
         delete [] ca;
         delete cS;
         delete xcS;

      }

      //clean memory
      delete ptr;
   }

   return val;
}

