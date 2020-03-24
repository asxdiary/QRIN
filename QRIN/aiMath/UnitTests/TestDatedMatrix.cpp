#include "Utils.hpp"
#include "DatedMatrix.hpp"

using namespace aiUtils;
using namespace aiMath;
using namespace aiMathUtils;

int TestDatedMatrix_main() { printf("UnitTest %s\n",__FUNCTION__);
   int val = 0;
   const string ipfx = "input/TestDatedMatrix.";
   const string opfx = "output/TestDatedMatrix.";

   {
      string exS = "fm.";
      DatedMatrix* dm1 = NULL;
      UtilDate* da = NULL;
      UtilDate* db = NULL;

      da = UtilDate::eom(2013,1); db = UtilDate::eom(2013,3);
      dm1 = DatedMatrix::fscan_eom(ipfx + exS + "dm1/", da, db);

      {
         FlexMatrix* ptr = dm1->fm();
         delete ptr;
      }

      //clean memory
      delete dm1;
   }


   {
      string exS = "ex5.";
      list<DatedMatrix*>::iterator it;
      DatedMatrix* dm1 = NULL;
      DatedMatrix* dm2 = NULL;
      DatedMatrix* dm = NULL;
      DatedMatrix* _dm = NULL;
      UtilDate* da = NULL;
      UtilDate* db = NULL;

      da = UtilDate::eom(2013,1); db = UtilDate::eom(2013,3);
      dm1 = DatedMatrix::fscan_eom(ipfx + exS + "dm1/", da, db);
      dm2 = DatedMatrix::fscan_eom(ipfx + exS + "dm2/", da, db);
      _dm = DatedMatrix::fscan_eom(ipfx + exS + "sol/", da, db);
      dm = DatedMatrix::subtract(dm1, dm2);
      dm->set_id("sol");

      if(!dm->isEqual(_dm)) val++;

      {
         FlexMatrix* ptr = dm1->fm();
         delete ptr;
      }

      //clean memory
      delete dm1;
      delete dm2;
      delete dm;
      delete _dm;
   }

   {
      string exS = "ex1";
      DatedMatrix* dm = NULL;
      UtilDate* da = NULL;
      UtilDate* db = NULL;
      UtilDate* d = NULL;

      da = UtilDate::eom(2011,10);
      db = UtilDate::eom(2012,3);

      dm = DatedMatrix::instance();
      for(d=da;d->isBefore(db);d=d->next_eom()) dm->add(d, Matrix::instance2(4,1));
      dm->set_id("dm");
      dm->fprint(opfx + exS);

      {
         DatedMatrix* ptr = DatedMatrix::fscan_eom(opfx + exS, da, db);
         if(!ptr->isEqual(dm)) val++;
         delete ptr;
      }

      //clean memory
      delete dm;
   }
   
   {
      string exS = "ex2";
      list<DatedMatrix*> dmL;
      list<DatedMatrix*>::iterator it;
      DatedMatrix* dm1 = NULL;
      DatedMatrix* dm2 = NULL;
      UtilDate* da = NULL;
      UtilDate* db = NULL;
      Matrix* csanal = NULL;
      Matrix* _csanal = NULL;

      da = UtilDate::eom(2013,1); db = UtilDate::eom(2013,4);

      dm1 = DatedMatrix::fscan_eom(ipfx + exS + ".dm1/", da, db);
      dm1->set_id("dm1a");
      dmL.push_back(dm1);

      dm1 = DatedMatrix::fscan_eom(ipfx + exS + ".dm1/", da, db);
      dm1->set_id("dm1b");
      dmL.push_back(dm1);

      da = UtilDate::eom(2012,12); db = UtilDate::eom(2013,3);
      dm2 = DatedMatrix::fscan_eom(ipfx + exS + ".dm2/", da, db);

      csanal = dm2->csanal(&dmL);
      _csanal = Matrix::instance_fread_table(ipfx + exS + ".csanal.csv");
      //if(!csanal->isEqual(_csanal)) val++;

      //clean memory
      for(it=dmL.begin();it!=dmL.end();it++) delete *it;
      delete dm2;
      delete csanal;
      delete _csanal;
   }

   {
      string exS = "ex3";
      list<DatedMatrix*>::iterator it;
      DatedMatrix* dm1 = NULL;
      DatedMatrix* dm2 = NULL;
      DatedMatrix* dm = NULL;
      DatedMatrix* _dm = NULL;
      UtilDate* da = NULL;
      UtilDate* db = NULL;

      da = UtilDate::eom(2013,1); db = UtilDate::eom(2013,4);

      dm1 = DatedMatrix::fscan_eom(ipfx + exS + ".dm1/", da, db);
      dm2 = DatedMatrix::fscan_eom(ipfx + exS + ".dm2/", da, db);
      _dm = DatedMatrix::fscan_eom(ipfx + exS + ".dm/", da, db);

      {
         DatedMatrix* dmproj = dm1->project(0);
         delete dmproj;
      }

      {
         FlexMatrix* fm = dm1->fm();
         delete fm;
      }

      dm = dm1->univfilter(dm2);
      if(!dm->isEqual(_dm)) val++;

      //clean memory
      delete dm1;
      delete dm2;
      delete dm;
      delete _dm;
   }

   {
      string exS = "ex4.";
      list<DatedMatrix*>::iterator it;
      DatedMatrix* dm1 = NULL;
      DatedMatrix** dmA = NULL;
      DatedMatrix** _dmA = NULL;
      Matrix* csanal = NULL;
      Matrix* _csanal = NULL;
      UtilDate* da = NULL;
      UtilDate* db = NULL;
      int K = 7;

      da = UtilDate::eom(2013,1); db = UtilDate::eom(2013,4);
      dm1 = DatedMatrix::fscan_eom(ipfx + exS + "dm1/", da, db);
      dmA = dm1->bucketizeA(K,0);

      {
         DatedMatrix* dme = dm1->excise_tails(K,0);
         DatedMatrix* _dme = DatedMatrix::fscan_eom(ipfx + exS + "excise_tails/", da, db);
         if(!dme->isEqual(_dme)) val++;
         delete dme;
         delete _dme;
      }

      _dmA = new DatedMatrix*[K];
      for(int k=0;k<K;k++) {
         _dmA[k] = DatedMatrix::fscan_eom(ipfx + exS + "dmb/dmb" + util_string(k), da, db);
      }

      for(int k=0;k<K;k++) {
         if(!dmA[k]->isEqual(_dmA[k])) val++;
      }

      {
         const int K = 12;
         DatedMatrix* ptr = dm1->eom_lag(K);
         DatedMatrix* _ptr = NULL;
         UtilDate* daK = NULL;
         UtilDate* dbK = NULL;

         daK = da->prev_eom((-1)*K);
         dbK = db->prev_eom((-1)*K);

         _ptr = DatedMatrix::fscan_eom(ipfx + exS + "lag",daK,dbK);
         if(!ptr->isEqual(_ptr)) val++;

         //clean memory
         delete _ptr;
         delete ptr;
      }

      {
         Matrix* csanal = dm1->eom_autoanal(1);
         Matrix* _csanal = Matrix::instance_fread_table(ipfx + exS + "eom_autoanal.csv");
         //if(!csanal->isEqual(_csanal)) val++;
         delete _csanal;
         delete csanal;
      }

      csanal = dm1->csanal(dmA,K);
      _csanal = Matrix::instance_fread_table(ipfx + exS + "csanal.csv");
      //if(!csanal->isEqual(_csanal)) val++;

      {
         Matrix* X = dm1->concat();
         Matrix* _X = Matrix::instance_fread_table(ipfx + exS + "concat.csv");
         if(!X->isEqual(_X)) val++;
         delete X;
         delete _X;
      }

      {
         Matrix* uanal = dm1->unianal();
         Matrix* _uanal = Matrix::instance_fread_table(ipfx + exS + "unianal.csv");
         //if(!uanal->isEqual(_uanal)) val++;
         delete uanal;
         delete _uanal;
      }


      {
         Matrix* cc = dm1->cc(true);
         Matrix* _cc = Matrix::instance_fread_table(ipfx + exS + "cc.csv");
         //if(!cc->isEqual(_cc)) val++;
         delete cc;
         delete _cc;
      }

     {
         Matrix* uanal = dm1->unianal(dm1,5,0);
         delete uanal;
      }



      //clean memory
      for(int k=0;k<K;k++) delete dmA[k];
      for(int k=0;k<K;k++) delete _dmA[k];
      delete [] dmA;
      delete [] _dmA;
      delete dm1;
      delete csanal;
      delete _csanal;
   }

   if(val>0) printf("UnitTest %s FAILED\n",__FUNCTION__);

   return val;
}

