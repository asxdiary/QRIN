// Name:     ForecastUtils.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ForecastUtils_cpp
#define ASX_ForecastUtils_cpp

#include <iostream>
#include <random>
#include <math.h>
#include <unordered_map>
#include "ForecastUtils.hpp"
#include "Utils.hpp"
#include "Matrix.hpp"
#include "UtilDate.hpp"

Matrix* aiForecastUtils::ForecastUtils_concat(unordered_map<UtilDate*,Matrix*>* Xm) {
   Matrix** mA = NULL;
   string* pfx = NULL;
   unordered_map<UtilDate*,Matrix*>::iterator it;
   Matrix* X = NULL;
   int T, t;

   T = Xm->size();
   mA = new Matrix*[T];
   pfx = new string[T];

   t = 0;
   for(it=Xm->begin();it!=Xm->end();it++) {
      pfx[t] = it->first->id();
      mA[t++] = it->second;
   }

   X = Matrix::concat(true, mA, T, pfx);

   //clean memory
   delete [] mA;
   delete [] pfx;

   return X;
}


Matrix* aiForecastUtils::ForecastUtils_concat(
   unordered_map<string,unordered_map<UtilDate*,Matrix*>*>* sm)
{
   list<string> idL;
   list<UtilDate*> dL;
   unordered_map<string,Matrix*> repXm;
   Matrix* X = NULL;

   //create idL, dL, repX
   {
      unordered_map<string,unordered_map<UtilDate*,Matrix*>*>::iterator it1;
      unordered_map<UtilDate*,Matrix*>::iterator it2;
      unordered_map<UtilDate*,Matrix*>* ds = NULL;
      set<int> dS;
      set<int>::iterator it3;

      for(it1=sm->begin();it1!=sm->end();it1++) {
         if(it1->second==NULL) continue;
         Matrix* repX = NULL;
         string id;

         id = it1->first;
         ds = it1->second;
         repX = NULL;

         for(it2=ds->begin();it2!=ds->end();it2++) {
            if(it2->second==NULL) continue;
            dS.insert(it2->first->icode());
            if(repX==NULL) repX = it2->second;
         }
         if(repX==NULL) continue;
         repXm[id] = repX;
         idL.push_back(id);
      }

      for(it3=dS.begin();it3!=dS.end();it3++) dL.push_back(UtilDate::instance(*it3));
   }

   //initialize X
   {
      int m, n;

      unordered_map<string,Matrix*>::iterator it1;
      m = dL.size();

      n = 0;
      for(it1=repXm.begin();it1!=repXm.end();it1++) n += it1->second->n();

      X = Matrix::instance(m,n);
   }

   //row and column names of X
   {
      list<UtilDate*>::iterator it1;
      list<string>::iterator it2;
      int i, j;

      i = 0;
      for(it1=dL.begin();it1!=dL.end();it1++) X->set_rmap_rimap(i++, (*it1)->id());
      if(i!=X->m()) err_msg("aiForecastUtils::ForecastUtils_concat sm i!=m");

      j = 0;
      for(it2=idL.begin();it2!=idL.end();it2++) {
         string id = (*it2);
         Matrix* repX = repXm.find(id)->second;
         string* cmap = repX->cmap();
         int nn = repX->n();
         string cid;

         for(int jj=0;jj<nn;jj++) {
            if(cmap==NULL) cid = util_join(".","col",jj);
            else cid = cmap[jj];
            X->set_cmap_cimap(j++, util_join(".",id,cid));
         }
      }
      if(j!=X->n()) err_msg("aiForecastUtils::ForecastUtils_concat sm i!=n");
   }

   //populate X
   {
      list<UtilDate*>::iterator it1;
      list<string>::iterator it2;
      unordered_map<UtilDate*,Matrix*>::iterator it3;
      double** XX = X->X();
      int i;

      i = 0;
      for(it1=dL.begin();it1!=dL.end();it1++,i++) {
         UtilDate* d = *it1;
         int j;

         j = 0;
         for(it2=idL.begin();it2!=idL.end();it2++) {
            string id = *it2;
            int nn = repXm.find(id)->second->n();
            Matrix* dsX = NULL;

            it3 = sm->find(id)->second->find(d);
            if(it3!=sm->find(id)->second->end()) dsX = it3->second;
            if(dsX==NULL) { j += nn; continue;}

            for(int jj=0;jj<nn;jj++) XX[i][j++] = dsX->X()[0][jj];
         }

      }
   }

   return X;
}

Matrix* aiForecastUtils::ForecastUtils_extract_data(unordered_map<UtilDate*,Matrix*>* Xm,
                                                    UtilDate* d, const int lag)
{
   unordered_map<UtilDate*,Matrix*>::iterator it;
   d = d->prev_eom(lag);
   it = Xm->find(d);
   if(it==Xm->end()) return NULL;
   return it->second;
}

void aiForecastUtils::ForecastUtils_fprint_split(unordered_map<UtilDate*,Matrix*>* Xm, 
                                                 string pfx)
{
   unordered_map<UtilDate*,Matrix*>::iterator it;
   for(it=Xm->begin();it!=Xm->end();it++) {
      if(it->second==NULL) continue;
      UtilDate* d = it->first;

      string tmp = pfx;
      string fname;
      if( (*tmp.rbegin())=='/' ) tmp = tmp + d->id();
      else tmp = util_join(".",tmp,d->id());
      fname = util_join(".",tmp,"csv");
      it->second->fprint_table(fname);
   }
   return;
}

void aiForecastUtils::ForecastUtils_fread_split(unordered_map<UtilDate*,Matrix*>*& Xm, 
                                                UtilDate* da, 
                                                UtilDate* db,
                                                string pfx)
{
   UtilDate* d = NULL;
   string fname;
   if(Xm==NULL) Xm = new unordered_map<UtilDate*,Matrix*>();

   for(d=da;d->isBefore(db);d=d->next_eom()) {
      string tmp = pfx;
      if( (*tmp.rbegin())=='/' ) tmp = tmp + d->id();
      else tmp = util_join(".",tmp,d->id());
      fname = util_join(".",tmp,"csv");
      (*Xm)[d] = Matrix::instance_fread_table(fname);
   }

   return;
}

void aiForecastUtils::ForecastUtils_cleanMem(unordered_map<UtilDate*,Matrix*>*& Xm)
{
   unordered_map<UtilDate*,Matrix*>::iterator it;
   for(it=Xm->begin();it!=Xm->end();it++) delete it->second;
   delete Xm; Xm = NULL;
   return;
}

#endif

