// Name:     DatedMatrix.cpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DatedMatrix_cpp
#define ASX_DatedMatrix_cpp


#include <stdio.h>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Matrix.hpp"
#include "UtilDate.hpp"
#include "DatedMatrix.hpp"
#include "MatrixProcessor.hpp"
#include "Regression.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMath;
using namespace aiMathUtils;
using namespace aiStatUtils;

/** --------------Constructors and init_NULL-----------*/

DatedMatrix::DatedMatrix() { init_NULL(); }
DatedMatrix::DatedMatrix(const DatedMatrix* ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }
DatedMatrix::DatedMatrix(const DatedMatrix& ptr) { myerr_msg("copy functionality disabled",__FUNCTION__); }

void DatedMatrix::init_NULL()	{
	_dm=NULL;
	_dS=NULL;
   _nc=0;
   _cmap=NULL;
   _cimap=NULL;
}

/** ---Public Data Setting Functions-----------------*/

/** --------   Init Functions -------------------------*/

void DatedMatrix::init() {
   Model::init();
	init_DatedMatrix();
}

void DatedMatrix::init_DatedMatrix() {
	init_dm();
	init_dS();
}

void DatedMatrix::init_dm() {
   _dm = new unordered_map<UtilDate*,Matrix*>();
}

void DatedMatrix::init_dS() {
   _dS = new set<int>();
}

void DatedMatrix::set_cmap_cimap(string* omap, unordered_map<string,int>* imap) {
   if(omap==NULL && imap==NULL) myerr_msg("omap==NULL && imap==NULL",__FUNCTION__);
   const int num = _nc;
   util_map_imap(omap, imap, num);
   cleanMem_cmap(); cleanMem_cimap();
   _cmap = omap; _cimap = imap;
}

/** -----Destructors and Memory Cleanup functions -----*/

DatedMatrix::~DatedMatrix()	{ cleanMem(); }

void DatedMatrix::cleanMem()	{
	cleanMem_DatedMatrix();
	Model::cleanMem();
}

void DatedMatrix::cleanMem_DatedMatrix() {
	cleanMem_dm();
	cleanMem_dS();
   cleanMem_cmap();
   cleanMem_cimap();
}

void DatedMatrix::cleanMem_dm() {
   if(_dm!=NULL) {
      unordered_map<UtilDate*,Matrix*>::iterator it;
      for(it=_dm->begin();it!=_dm->end();it++) delete it->second;
      delete _dm;
   }
	_dm=NULL;
}

void DatedMatrix::cleanMem_dS() {
   delete _dS;
	_dS=NULL;
}

void DatedMatrix::cleanMem_cmap() {
   delete [] _cmap;
   _cmap = NULL;
}

void DatedMatrix::cleanMem_cimap() {
   delete _cimap;
   _cimap = NULL;
}


/** ------------- Data Access Functions --------------------*/

unordered_map<UtilDate*,Matrix*>* DatedMatrix::dm() {return _dm;}
set<int>* DatedMatrix::dS() {return _dS;}
int DatedMatrix::nc() {return _nc;}
string* DatedMatrix::cmap() {return _cmap;}
unordered_map<string,int>* DatedMatrix::cimap() {return _cimap;}

/** ------------- Access classname dynamically --------------------*/

string DatedMatrix::className() const {return "DatedMatrix";}

/** ------------- Error Message Handling Functions ------------------*/

void DatedMatrix::myerr_msg(string msg, string func) {
	err_msg("DatedMatrix::",func," ",msg);
}

/** ------------- Printing and Scanning Options ------------------*/

void DatedMatrix::fprint(string fname) {
	Model::fprint(fname);
	fprint_DatedMatrix(fname);
}

void DatedMatrix::fprint_DatedMatrix(string fname) {
   unordered_map<UtilDate*,Matrix*>* dm = this->dm();
   unordered_map<UtilDate*,Matrix*>::iterator it;
   string fname2;
   for(it=dm->begin();it!=dm->end();it++) {
      if(it->second==NULL) continue;
      if( (*fname.rbegin())=='/' ) {
         fname2 = util_join(".",fname + this->id(),it->first->id(),"csv");
      }
      else {
         fname2 = util_join(".",fname,this->id(),it->first->id(),"csv");
      }

      it->second->fprint_table(fname2);
   }
   return;
}

void DatedMatrix::fscan(string fname) {
	Model::fscan(fname);
	fscan_DatedMatrix(fname);
}

void DatedMatrix::fscan_DatedMatrix(string fname) {
   myerr_msg("Functionality not yet implemented",__FUNCTION__);
   return;
}

/** ------------- Reset Functions --------------------*/

void DatedMatrix::reset() {
	reset_DatedMatrix();
	Model::reset();
}

void DatedMatrix::reset_DatedMatrix() {
}

/** ----------  static instance function -----------*/


DatedMatrix* DatedMatrix::instance()	{
	DatedMatrix* ptr=new DatedMatrix();
	ptr->init();
	return ptr;
}

DatedMatrix* DatedMatrix::instance(string id) {
   DatedMatrix* ptr = DatedMatrix::instance();
   ptr->set_id(id);
   return ptr;
}

DatedMatrix* DatedMatrix::instance_fscan(string fname)	{
	DatedMatrix* ptr=NULL;
	if(!util_fscan_NULL(fname)) {
		ptr=new DatedMatrix();
		ptr->init_NULL();
		ptr->fscan(fname);
	}
	return ptr;
}

DatedMatrix* DatedMatrix::fscan_eom(string fname, UtilDate* da, UtilDate* db, string id,
                                    bool use_dmid, int nlag) 
{
   DatedMatrix* dm = NULL;
   UtilDate* d = NULL;
   string dfname;
   string dmid;

   dm = DatedMatrix::instance();
   if(id.length()==0) util_ofscan(fname,"id",id);
   dm->set_id(id);

   dmid = dm->id();
   if(!use_dmid) dmid = "";

   for(d=da;d->isBefore(db);d=d->next_eom(nlag)) {

      if( (*fname.rbegin())=='/' ) {
         if(dmid.length()>0) dfname = util_join(".",fname + dmid,d->id(),"csv");
         else dfname = fname + d->id() + ".csv";
      }
      else {
         list<string> L;

         L.push_back(fname);
         if(use_dmid) L.push_back(dmid);
         L.push_back(d->id());
         L.push_back("csv");

         dfname = util_joinL(".",&L);
      }
      dm->add(d, Matrix::instance_fread_table(dfname));
   }

   return dm;
}

/** ----------  Non-standard functions start here -----------*/

void DatedMatrix::add(UtilDate* d, Matrix* X) {
   if(X==NULL) myerr_msg(d->id() + " X==NULL",__FUNCTION__);
   (*_dm)[d] = X;
   _dS->insert(d->icode());
   if(cmap()==NULL) {
      _nc = X->n();
      set_cmap_cimap(util_copy(X->cmap(), _nc), NULL);
   }
   else {
      if(X->n()!=_nc) myerr_msg(d->id() + " violation: X->n()!=_nc",__FUNCTION__);
      if(!util_isEqual(X->cmap(),_cmap,_nc)) {
         myerr_msg(d->id() + " violation: cmap mismatch",__FUNCTION__);
      }
   }
}

Matrix* DatedMatrix::dm(UtilDate* d) {
   Matrix* X = NULL;
   unordered_map<UtilDate*,Matrix*>::iterator it;
   it = _dm->find(d);
   if(it!=_dm->end()) X = it->second;
   return X;
}

Matrix* DatedMatrix::dm(int dic) {return this->dm(UtilDate::instance(dic));}

Matrix* DatedMatrix::csanal(list<DatedMatrix*>* dm1L, 
                            set<string>* analS,
                            list<DatedMatrix*>* dmDL)
{
   DatedMatrix* dm2 = this;
   set<int>* S = NULL;
   Matrix** xA = NULL;
   Matrix* c = NULL;
   set<int>::iterator it;
   list<DatedMatrix*>::iterator dm1it;
   list<DatedMatrix*>::iterator dmDit;
   bool p_correl_flag;
   bool sp_correl_flag;
   bool posfrac_flag;
   bool exp_flag;
   bool colmatch_flag;
   bool loginfo_flag;
   int nS,t;

   //memory management
   list<DatedMatrix*>* _dmDL = NULL;

   p_correl_flag = (analS==NULL) || (analS->find("p_correl")!=analS->end());
   sp_correl_flag = (analS==NULL) || (analS->find("sp_correl")!=analS->end());
   exp_flag = (analS==NULL) || (analS->find("exp")!=analS->end());
   colmatch_flag = (analS!=NULL) && (analS->find("colmatch")!=analS->end());
   loginfo_flag = (analS!=NULL) && (analS->find("loginfo")!=analS->end());
   posfrac_flag = (analS==NULL) || (analS->find("posfrac")!=analS->end());

   if(dmDL==NULL) {
      DatedMatrix* dmD = NULL;
      set<int>* S = dm2->dS();

      dmDL = _dmDL = new list<DatedMatrix*>();
      dmDL->push_back( dmD = DatedMatrix::instance() );
      dmD->set_id("_DeltaOne");

      for(it=S->begin(),t=0;it!=S->end();it++) {
         UtilDate* d = UtilDate::instance(*it);
         Matrix* X2 = dm2->dm(d);
         Matrix* Delta = Matrix::ones(X2->m(),1);
         Delta->copynames(X2, true, false);
         Delta->set_cmap_cimap(0,"Delta");
         dmD->add(d, Delta);
      }
   }

   {
      set<int>* tmp = NULL;

      S = util_copy(dm2->dS());
      for(dm1it=dm1L->begin();dm1it!=dm1L->end();dm1it++) {
         tmp = util_intersect((*dm1it)->dS(), S);
         delete S; S = tmp; tmp = NULL;
      }

      for(dmDit=dmDL->begin();dmDit!=dmDL->end();dmDit++) {
         tmp = util_intersect((*dmDit)->dS(), S);
         delete S; S = tmp; tmp = NULL;
      }
   }

   nS = S->size();
   xA = new Matrix*[nS];

   for(it=S->begin(),t=0;it!=S->end();it++) {
      Matrix* X2 = NULL;
      string* X2cmap = NULL;
      unordered_map<string,double> valm;
      int dic, n2;

      dic = *it;
      X2 = dm2->dm(dic);
      n2 = dm2->nc();
      X2cmap = dm2->cmap();

      for(dmDit=dmDL->begin();dmDit!=dmDL->end();dmDit++) {
         DatedMatrix* dmD = *dmDit;
         Matrix* Delta = dmD->dm(dic);

         for(dm1it=dm1L->begin();dm1it!=dm1L->end();dm1it++) {
            DatedMatrix* dm1 = *dm1it;
            Matrix* X1 = NULL;
            Matrix* comX = NULL;
            Matrix* rcomX = NULL;
            string* X1cmap = NULL;
            string cid;
            int n1;
            string* pfxA = NULL;
            string pfx;

            pfx = util_join2(".",dm1->id(),dm2->id(),dmD->id());
            valm[util_join(".",pfx,"n2")] = X2->m();

            if(loginfo_flag) printf("%s::%s %d %s starting\n",className().c_str(),
                                    __FUNCTION__,dic, pfx.c_str());

            pfxA = new string[3];
            pfxA[0] = dm1->id();
            pfxA[1] = dm2->id();
            pfxA[2] = dmD->id();

            X1 = dm1->dm(dic);
            comX = Matrix::concat3_col(X1, X2, Delta, pfxA);
            rcomX = comX->colrank();
            n1 = dm1->nc();
            X1cmap = dm1->cmap();

            valm[util_join(".",pfx,"n1")] = X1->m();
            valm[util_join(".",pfx,"com_n")] = comX->m();

            //compute the mean-rows for dm1 and dm2
            {
               Matrix* mr = NULL;

               mr = comX->mean_col(NULL,false,NULL);
               for(int j1=0;j1<n1;j1++) {
                  cid = util_join(".",pfx,X1cmap[j1],"mean1");
                  valm[cid] = mr->X()[0][j1];
               }
               for(int j2=0;j2<n2;j2++) {
                  cid = util_join(".",pfx,X2cmap[j2],"mean2");
                  valm[cid] = mr->X()[0][n1+j2];
               }

               //clean memory
               delete mr; mr = NULL;
            }

            //compute the l2n for dm1 and dm2
            {
               Matrix* mr = NULL;
               double alpha1 = 0.025;
               double alpha2 = 1-alpha1;

               mr = comX->l2nc(true, true, alpha1, alpha2, Delta, true);
               for(int j1=0;j1<n1;j1++) {
                  cid = util_join(".",pfx,X1cmap[j1],"l2n1_win025");
                  valm[cid] = mr->X()[0][j1];
               }
               for(int j2=0;j2<n2;j2++) {
                  cid = util_join(".",pfx,X2cmap[j2],"l2n2_win025");
                  valm[cid] = mr->X()[0][n1+j2];
               }

               //clean memory
               delete mr; mr = NULL;
            }

            if(loginfo_flag) printf("%s::%s %d %s completed univar anal\n",className().c_str(),
                                    __FUNCTION__,dic, pfx.c_str());

            for(int j1=0;j1<n1;j1++) {
               for(int j2=0;j2<n2;j2++) {

                  if(colmatch_flag && X1cmap[j1].compare(X2cmap[j2])!=0) continue;

                  if(loginfo_flag) printf("%s::%s %d %s bivar anal %s %s\n",className().c_str(),
                                          __FUNCTION__,dic,pfx.c_str(),
                                          X1cmap[j1].c_str(),X2cmap[j2].c_str());

                  if(p_correl_flag) {
                     cid = util_join(".",pfx,X1cmap[j1],X2cmap[j2],"p_correl");
                     valm[cid] = comX->correl_col(j1,n1+j2);
                  }
                  if(sp_correl_flag) {
                     cid = util_join(".",pfx,X1cmap[j1],X2cmap[j2],"sp_correl");
                     valm[cid] = rcomX->correl_col(j1,n1+j2);
                  }
                  if(exp_flag) {
                     double denom1, denom2, numer;
                     cid = util_join(".",pfx,X1cmap[j1],X2cmap[j2],"sumprod");
                     numer = valm[cid] = comX->sumprod_col(j1,n1+j2);

                     cid = util_join(".",pfx,X1cmap[j1],"l2n1");
                     denom1 = valm[cid];

                     cid = util_join(".",pfx,X2cmap[j2],"l2n2");
                     denom2 = valm[cid];

                     cid = util_join(".",pfx,X1cmap[j1],X2cmap[j2],"cosine");
                     if(!util_isZero(denom1) && !util_isZero(denom2)) {
                        valm[cid] = numer/(denom1*denom2);
                     }
                     else valm[cid] = 0.0;
                  }

                  if(posfrac_flag) {
                     double** comXX = comX->X();
                     double** rcomXX = rcomX->X();

                     unordered_map<string,int> posm;
                     unordered_map<string,int> totm;
                     unordered_map<string,double> thm;
                     unordered_map<string,double>::iterator thm_it;
                     double pct, val;
                     string id;
                     int m;

                     {
                        int N = 20;
                        for(int k=0;k<N;k++) {
                           pct = k*1.0/N;
                           id = util_join(".","pct",int(pct*100));
                           posm[id] = 0;
                           totm[id] = 0;
                           thm[id] = pct;
                        }
                     }

                     m = comX->m();

                     for(int i=0;i<m;i++) {
                        pct = rcomXX[i][n1+j2]/m;
                        val = comXX[i][j1];
                        for(thm_it=thm.begin();thm_it!=thm.end();thm_it++) {
                           id = thm_it->first;
                           if(pct<thm_it->second) continue;
                           if(val>0) posm[id]++;
                           totm[id]++;
                        }
                     }

                     for(thm_it=thm.begin();thm_it!=thm.end();thm_it++) {
                        id = thm_it->first;
                        cid = util_join(".",pfx,X1cmap[j1],X2cmap[j2],"posfrac",id);
                        val = posm[id] * 1.0/totm[id];
                        valm[cid] = val;
                     }

                     //compute regression coefficient
                     {
                        Regression* reg = NULL;
                        Matrix* regX = NULL;
                        Matrix* regy = NULL;
                        Matrix* regf = NULL;
                        double** regXX = NULL;
                        double** regyX = NULL;
                        double R2;
                        int nreg, i;

                        reg = Regression::instance();

                        nreg = posm.size();
                        regy = Matrix::instance(nreg, 1);
                        regX = Matrix::ones(nreg, 2);
                        regyX = regy->X();
                        regXX = regX->X();

                        for(thm_it=thm.begin(),i=0;thm_it!=thm.end();thm_it++,i++) {
                           id = thm_it->first;
                           val = posm[id] * 1.0/totm[id];

                           regy->set_rmap_rimap(i, id);
                           regX->set_rmap_rimap(i, id);
                           regyX[i][0] = val;
                           regXX[i][1] = thm_it->second;
                        }

                        reg->configure(regy, regX, NULL);
                        reg->algo_exec();
                        regf = reg->f();
                        R2 = reg->mdl()->compute_R2();

                        {
                           int nvar = regX->n();

                           for(int j=0;j<nvar;j++) {
                              cid = util_join(".",pfx,X1cmap[j1],X2cmap[j2],"posfrac.reg.cf",j);
                              valm[cid] = regf->X()[j][0];
                           }

                           cid = util_join(".",pfx,X1cmap[j1],X2cmap[j2],"posfrac.reg.R2");
                           valm[cid] = R2;
                        }

                        //clean memory
                        delete reg;
                        delete regy;
                        delete regX;
                     }

                  }
               }
            }

            //clean memory
            delete comX;
            delete rcomX;
            delete [] pfxA;
         }

      }

      xA[t++] = Matrix::instance_row(&valm, UtilDate::instance(dic)->id());
   }

   c = Matrix::concat3_row(nS, xA);

   //clean memory
   for(int t=0;t<nS;t++) delete xA[t];
   delete [] xA;
   delete S;
   if(_dmDL!=NULL) {
      for(dmDit=_dmDL->begin();dmDit!=_dmDL->end();dmDit++) delete *dmDit;
      delete _dmDL;
   }

   return c;
}

Matrix* DatedMatrix::csanal(DatedMatrix* dm1, 
                            set<string>* analS,
                            list<DatedMatrix*>* dmDL)
{
   list<DatedMatrix*> dm1L;
   dm1L.push_back(dm1);
   return csanal(&dm1L, analS, dmDL);
}

DatedMatrix* DatedMatrix::proc(MatrixProcessor* proc) {
   DatedMatrix* ptr = NULL;
   unordered_map<UtilDate*,Matrix*>* dm = this->dm();
   unordered_map<UtilDate*,Matrix*>::iterator it;

   ptr = DatedMatrix::instance();
   for(it=dm->begin();it!=dm->end();it++) {
      ptr->add(it->first, proc->exec(it->second, NULL) );
   }

   ptr->set_id(util_join(".",this->id(),"proc",proc->id()));

   return ptr;
}

DatedMatrix* DatedMatrix::univfilter(DatedMatrix* univ) {
   DatedMatrix* ptr = NULL;
   unordered_map<UtilDate*,Matrix*>* dm = this->dm();
   unordered_map<UtilDate*,Matrix*>::iterator it;

   ptr = DatedMatrix::instance();
   for(it=dm->begin();it!=dm->end();it++) {
      UtilDate* d = it->first;
      Matrix* X1 = it->second;
      Matrix* X = univ->dm(d);
      if(X==NULL) myerr_msg(d->id() + " data not available for universe",__FUNCTION__);
      ptr->add(d, X1->subrow(X));
   }

   ptr->set_id(util_join(".",this->id(),"univ",univ->id()));

   return ptr;
}

DatedMatrix** DatedMatrix::bucketizeA(int K, int _j) {
   int nc = this->nc();

   DatedMatrix** dmA = NULL;
   DatedMatrix** dmAj = NULL;
   int t;

   {
      int num;
      if(_j>=0) num = K;
      else num = K*nc;
      dmA = new DatedMatrix*[num];
   }

   t = 0;
   for(int j=0;j<nc;j++) {
      if(_j>=0 && (j!=_j)) continue;
      dmAj = this->bucketizeA_guts(K, j);
      for(int k=0;k<K;k++) dmA[t++] = dmAj[k];
      delete [] dmAj;
   }

   return dmA;
}

DatedMatrix** DatedMatrix::bucketizeA_guts(int K, int j) {
   string* cmap = this->cmap();
   DatedMatrix** dmA = NULL;
   set<int>* dS = this->dS();
   set<int>::iterator it;

   dmA = new DatedMatrix*[K];
   for(int k=0;k<K;k++) {
      dmA[k] = DatedMatrix::instance();
      dmA[k]->set_id(util_join(".",this->id(),cmap[j],"nb",k,"K",K));
   }

   for(it=dS->begin();it!=dS->end();it++) {
      UtilDate* d = UtilDate::instance(*it);
      Matrix* X = this->dm(d);
      Matrix* cr = X->colrank(j);
      double** crX = cr->X();
      int m = X->m();
      double denom;
      set<int>** SA = NULL;
      
      denom = m*1.0/K;

      SA = new set<int>*[K];
      for(int k=0;k<K;k++) SA[k] = new set<int>();
      for(int i=0;i<m;i++) SA[int(crX[i][0]/denom)]->insert(i);
      for(int k=0;k<K;k++) dmA[k]->add(d,X->sub(SA[k],NULL));

      //clean memory
      for(int k=0;k<K;k++) delete SA[k];
      delete [] SA;
      delete cr;
   }

   return dmA;
}

DatedMatrix* DatedMatrix::excise_tails(int K, int j) {
   DatedMatrix* dme = NULL;
   set<int>* dS = this->dS();
   set<int>::iterator it;

   dme = DatedMatrix::instance();
   dme->set_id(util_join(".",this->id(),"field",j,"et",K));

   for(it=dS->begin();it!=dS->end();it++) {
      UtilDate* d = UtilDate::instance(*it);
      Matrix* X = this->dm(d);
      Matrix* cr = X->colrank(j);
      double** crX = cr->X();
      int m = X->m();
      set<int>* SA = NULL;
      double denom;
      int k;
      
      denom = m*1.0/K;

      SA = new set<int>();
      for(int i=0;i<m;i++) {
         k = int(crX[i][0]/denom);
         if(k==0 || k==(K-1)) continue;
         SA->insert(i);
      }
      dme->add(d,X->sub(SA,NULL));

      //clean memory
      delete SA;
      delete cr;
   }

   return dme;
}


bool DatedMatrix::isEqual(DatedMatrix* dm) {
   DatedMatrix* dm1 = this;
   DatedMatrix* dm2 = dm;
   set<int>* dS = this->dS();
   set<int>::iterator it;
   bool flag;

   if(dm2==NULL) return false;
   if(!util_isEqual(dm1->dS(),dm2->dS())) return false;

   flag = true;
   for(it=dS->begin();flag && (it!=dS->end());it++) {
      flag = flag && dm1->dm(*it)->isEqual(dm2->dm(*it),true,true);
   }

   return flag;
}

Matrix* DatedMatrix::csanal(DatedMatrix** dmA, int ndmA, set<string>* analS,
                            list<DatedMatrix*>* dmDL)
{
   list<DatedMatrix*> dmL;
   for(int i=0;i<ndmA;i++) dmL.push_back(dmA[i]);
   return this->csanal(&dmL,analS,dmDL);
}

DatedMatrix* DatedMatrix::project(set<int>* cinc, set<int>* cexc) {
   DatedMatrix* ptr = NULL;
   unordered_map<UtilDate*,Matrix*>* dm = this->dm();
   unordered_map<UtilDate*,Matrix*>::iterator it;

   ptr = DatedMatrix::instance();
   for(it=dm->begin();it!=dm->end();it++) {
      UtilDate* d = it->first;
      Matrix* X1 = it->second;
      ptr->add(d, X1->sub(NULL,cinc,NULL,cexc));
   }

   return ptr;
}

DatedMatrix* DatedMatrix::project(int j) {
   set<int> S;
   S.insert(j);
   return this->project(&S, NULL);
}

DatedMatrix* DatedMatrix::project(string cname) {
   unordered_map<string,int>::iterator it = cimap()->find(cname);
   if(it==cimap()->end()) myerr_msg(cname + " field not found",__FUNCTION__);
   return this->project(it->second);
}

DatedMatrix* DatedMatrix::project(string cname1, string cname2) {
   unordered_map<string,int>::iterator it1 = cimap()->find(cname1);
   unordered_map<string,int>::iterator it2 = cimap()->find(cname2);
   if(it1==cimap()->end()) myerr_msg(cname1 + " field not found",__FUNCTION__);
   if(it2==cimap()->end()) myerr_msg(cname2 + " field not found",__FUNCTION__);

   set<int> incS;
   incS.insert(it1->second);
   incS.insert(it2->second);

   return this->project(&incS, NULL);
}

list<DatedMatrix*>* DatedMatrix::bucketizeL(int K, int j, list<DatedMatrix*>* dmL) {
   if(dmL==NULL) dmL = new list<DatedMatrix*>();
   DatedMatrix** dmA = this->bucketizeA(K,j);
   int num = K;
   if(j<0) num = num * this->nc();
   for(int k=0;k<num;k++) dmL->push_back(dmA[k]);
   delete [] dmA;
   return dmL;
}

Matrix* DatedMatrix::cc(bool i2_flag) {
   DatedMatrix* dm2 = this;
   set<int>* S = NULL;
   Matrix** xA = NULL;
   Matrix* c = NULL;
   set<int>::iterator it;
   list<DatedMatrix*>::iterator dm1it;
   int nS,t;


   S = util_copy(dm2->dS());
   nS = S->size();
   xA = new Matrix*[nS];

   for(it=S->begin(),t=0;it!=S->end();it++,t++) {
      UtilDate* d = UtilDate::instance(*it);
      xA[t] = dm2->dm(d)->cc(false, NULL, i2_flag);
      xA[t]->set_rmap_rimap(0,d->id());
   }

   c = Matrix::concat3_row(nS, xA);

   //clean memory
   for(int t=0;t<nS;t++) delete xA[t];
   delete [] xA;
   delete S;

   return c;
}




Matrix* DatedMatrix::unianal() {
   DatedMatrix* dm2 = this;
   set<int>* S = NULL;
   Matrix** xA = NULL;
   Matrix* c = NULL;
   set<int>::iterator it;
   list<DatedMatrix*>::iterator dm1it;
   int nS,t;


   S = util_copy(dm2->dS());
   nS = S->size();
   xA = new Matrix*[nS];

   for(it=S->begin(),t=0;it!=S->end();it++) {
      Matrix* X2 = NULL;
      string* X2cmap = NULL;
      unordered_map<string,double> valm;
      int dic;

      dic = *it;
      X2 = dm2->dm(dic);
      X2cmap = dm2->cmap();

      {
         Matrix* tmp = NULL;
         string cid;
         string pfx;

         pfx = dm2->id();
         valm[util_join(".",pfx,"n")] = X2->m();

         //compute the mean-rows for dm1 and dm2
         tmp = X2->mean_col(NULL,false,NULL);
         tmp->row(0, pfx, "mean", X2cmap, &valm);
         delete tmp; tmp = NULL;

         //compute the l2-norm
         tmp = X2->l2nc(true);
         tmp->row(0, pfx, "l2n", X2cmap, &valm);
         delete tmp; tmp = NULL;

         //compute the l2-norm
         tmp = X2->l2nc(true,true);
         tmp->row(0, pfx, "l2n_win025", X2cmap, &valm);
         delete tmp; tmp = NULL;

         //compute the various percentiles
         {
            list<double> etaL;
            list<double>::iterator it;
            double eta;

            etaL.push_back(0.01);
            for(int k=5;k<=95;k+=5) etaL.push_back(k*0.01);
            etaL.push_back(0.99);

            for(it=etaL.begin();it!=etaL.end();it++) {
               eta = *it;
               tmp = X2->pct(eta, true);
               tmp->row(0, pfx, util_join(".","pct",int(eta*100)), X2cmap, &valm);
               delete tmp; tmp = NULL;
            }
         }
      }

      xA[t++] = Matrix::instance_row(&valm, UtilDate::instance(dic)->id());
   }

   c = Matrix::concat3_row(nS, xA);

   //clean memory
   for(int t=0;t<nS;t++) delete xA[t];
   delete [] xA;
   delete S;

   return c;
}

DatedMatrix* DatedMatrix::eom_lag(int K) {
   unordered_map<UtilDate*,Matrix*>* dm = this->dm();
   DatedMatrix* ptr = NULL;
   unordered_map<UtilDate*,Matrix*>::iterator it;
   Matrix* X = NULL;
   string* cmap = NULL;
   string sfx;
   int n;

   sfx = string("L") + util_string(K);
   ptr = DatedMatrix::instance();
   ptr->set_id(util_join(".",this->id(),sfx));
   for(it=dm->begin();it!=dm->end();it++) {
      X = it->second->copy();
      cmap = X->cmap();
      n = X->n();
      for(int j=0;j<n;j++) X->set_cmap_cimap(j, util_join(".",cmap[j],sfx));
      ptr->add(it->first->prev_eom((-1)*K),X);
   }

   return ptr;
}

Matrix* DatedMatrix::eom_autoanal(int K, set<string>* analS) {
   DatedMatrix* ptr = this->eom_lag(K); 
   Matrix* X = this->csanal(ptr,analS);
   delete ptr;
   return X;
}

Matrix* DatedMatrix::concat() {
   set<int>* dS = this->dS();
   set<int>::iterator it;
   UtilDate* d = NULL;

   Matrix** mA = NULL;
   string* pfx = NULL;
   Matrix* X = NULL;
   int T, t;

   T = dS->size();
   mA = new Matrix*[T];
   pfx = new string[T];

   for(t=0,it=dS->begin();it!=dS->end();it++,t++) {
      d = UtilDate::instance(*it);
      mA[t] = this->dm(d);
      pfx[t] = d->id();
   }

   X = Matrix::concat_col(mA, T, pfx);

   //clean memory 
   delete [] mA;
   delete [] pfx;

   return X;
}

DatedMatrix* DatedMatrix::lc(DatedMatrix* dm1, double val1,
                          DatedMatrix* dm2, double val2)
{
   unordered_map<UtilDate*,double> theta1m;
   unordered_map<UtilDate*,double> theta2m;
   set<int>::iterator it;
   set<int>* S = dm1->dS();
   UtilDate* d = NULL;
   for(it=S->begin();it!=S->end();it++) {
      d = UtilDate::instance(*it);
      theta1m[d] = val1;
      theta2m[d] = val2;
   }
   return DatedMatrix::lc(dm1, &theta1m, dm2, &theta2m);
}

DatedMatrix* DatedMatrix::lc(DatedMatrix* dm1, unordered_map<UtilDate*,double>* theta1m,
                          DatedMatrix* dm2, unordered_map<UtilDate*,double>* theta2m)
{
   DatedMatrix* dm = NULL;
   set<int>* S = NULL;
   list<DatedMatrix*>::iterator dm1it;
   set<int>::iterator it;

   dm = DatedMatrix::instance();
   S = util_intersect(dm1->dS(), dm2->dS());

   for(it=S->begin();it!=S->end();it++) {
      UtilDate* d = UtilDate::instance(*it);
      Matrix* X1 = NULL;
      Matrix* X2 = NULL;
      Matrix* X = NULL;
      double** X1X = NULL;
      double** X2X = NULL;
      unordered_map<string,int>* rimap1 = NULL;
      unordered_map<string,int>* rimap2 = NULL;
      unordered_map<string,int>* cimap1 = NULL;
      unordered_map<string,int>* cimap2 = NULL;

      double** XX = NULL;
      string* rmap = NULL;
      string* cmap = NULL;
      double val1, val2;
      int m, n;

      if(theta1m->find(d)==theta1m->end()) err_msg(d->id() + " not found in DatedMatrix::lc::theta1m");
      if(theta2m->find(d)==theta2m->end()) err_msg(d->id() + " not found in DatedMatrix::lc::theta2m");

      val1 = theta1m->find(d)->second;
      val2 = theta2m->find(d)->second;

      X1 = dm1->dm(d);
      X2 = dm2->dm(d);
      rimap1 = X1->rimap();
      rimap2 = X2->rimap();
      cimap1 = X1->cimap();
      cimap2 = X2->cimap();
      X1X = X1->X();
      X2X = X2->X();

      if(dm->cmap()!=NULL) {
         cmap = util_copy(dm->cmap(), dm->nc());
         n = dm->nc();
      }
      else {
         set<string>* cS = Matrix::cols_common(X1, X2);
         n = cS->size();
         cmap = util_array(cS);
         delete cS;
      }

      {
         set<string>* rS = Matrix::rows_common(X1, X2);
         m = rS->size();
         rmap = util_array(rS);
         delete rS;
      }

      X = Matrix::instance(m, n);
      X->set_rmap_rimap(rmap, NULL);
      X->set_cmap_cimap(cmap, NULL);
      XX = X->X();

      for(int i=0;i<m;i++) {
         int i1, i2;
         i1 = rimap1->find(rmap[i])->second;
         i2 = rimap2->find(rmap[i])->second;
         for(int j=0;j<n;j++) {
            int j1, j2;
            j1 = cimap1->find(cmap[j])->second;
            j2 = cimap2->find(cmap[j])->second;

            XX[i][j] = val1 * X1X[i1][j1] + val2* X2X[i2][j2];
         }
      }

      dm->add(d, X);
   }

   //clean memory
   delete S;

   return dm;
}

DatedMatrix* DatedMatrix::subtract(DatedMatrix* dm1, DatedMatrix* dm2) {
   return lc(dm1, 1.0, dm2, -1.0);
}

DatedMatrix* DatedMatrix::winsorize(double alpha1, double alpha2) {
   DatedMatrix* ptr = NULL;
   unordered_map<UtilDate*,Matrix*>* dm = this->dm();
   unordered_map<UtilDate*,Matrix*>::iterator it;

   ptr = DatedMatrix::instance();
   for(it=dm->begin();it!=dm->end();it++) {
      UtilDate* d = it->first;
      Matrix* X1 = Matrix::winsorize(it->second, false, alpha1, alpha2);
      ptr->add(d, X1);
   }

   return ptr;
}

void DatedMatrix::_habs() {
   set<int>* S = this->dS();
   set<int>::iterator it;
   for(it=S->begin();it!=S->end();it++) this->dm(*it)->_habs();
   return;
}

void DatedMatrix::_hlog() {
   set<int>* S = this->dS();
   set<int>::iterator it;
   for(it=S->begin();it!=S->end();it++) this->dm(*it)->_hlog();
   return;
}

void DatedMatrix::_hmult(const double x) {
   set<int>* S = this->dS();
   set<int>::iterator it;
   for(it=S->begin();it!=S->end();it++) this->dm(*it)->_hmult(x);
   return;
}

void DatedMatrix::_hpow(const double x) {
   set<int>* S = this->dS();
   set<int>::iterator it;
   for(it=S->begin();it!=S->end();it++) this->dm(*it)->_hpow(x);
   return;
}

Matrix* DatedMatrix::unianal(DatedMatrix* dm, int _K, int j) {
   DatedMatrix** dmA = NULL;
   Matrix** XA = NULL;
   Matrix* X = NULL;
   int num = _K;

   if(j<0) num *= dm->nc();

   dmA = dm->bucketizeA(_K, j);
   XA = new Matrix*[num];

   for(int k=0;k<num;k++) {
      DatedMatrix* dmk = this->univfilter(dmA[k]);
      XA[k] = dmk->unianal();
      delete dmk;
   }

   X = Matrix::concat_row(XA, num);

   //clean memory
   for(int k=0;k<num;k++) delete dmA[k];
   delete [] dmA;
   for(int k=0;k<num;k++) delete XA[k];
   delete [] XA;

   return X;
}

set<string>* DatedMatrix::ridS() {
   unordered_map<UtilDate*,Matrix*>* dm = this->dm();
   unordered_map<UtilDate*,Matrix*>::iterator it;
   Matrix* X = NULL;
   string* rmap = NULL;
   set<string>* S = NULL;
   int m;

   S = new set<string>();
   for(it=dm->begin();it!=dm->end();it++) {
      X = it->second;
      rmap = X->rmap();
      m = X->m();
      for(int i=0;i<m;i++) S->insert(rmap[i]);
   }

   return S;
}

FlexMatrix* DatedMatrix::fm() {
	unordered_map<UtilDate*,Matrix*>* dm = this->dm();
	set<int>* dS = this->dS();
   int nc = this->nc();
   string* cmap = this->cmap();

   Matrix* protomat = NULL;
   FlexMatrix* ptr = NULL;
   set<string>* ridS = NULL;
   set<string>::iterator it;
   unordered_map<UtilDate*,Matrix*>::iterator it2;

   ridS = this->ridS();

   //create protomat
   {
      string* p_rmap = NULL;
      string* p_cmap = NULL;
      set<int>::iterator it;
      int p_m, p_n, i;

      p_m = dS->size();
      p_n = nc;
      p_rmap = new string[p_m];
      p_cmap = new string[p_n];

      for(int j=0;j<p_n;j++) p_cmap[j] = cmap[j];

      for(it=dS->begin(), i=0;it!=dS->end();it++,i++) {
         p_rmap[i] = UtilDate::instance(*it)->id();
      }

      protomat = Matrix::instance(p_m, p_n, NULL, p_rmap, NULL, p_cmap, NULL, false);
   }

   ptr = FlexMatrix::instance(protomat);

   for(it=ridS->begin();it!=ridS->end();it++) {
      string rid = *it;
      Matrix* Xval = protomat->copy();
      Matrix* Xflag = protomat->copy();
      Xflag->_add(1.0);
      ptr->add_fm(rid, Xval, Xflag);
   }

   for(it2=dm->begin();it2!=dm->end();it2++) {
      UtilDate* d= it2->first;
      Matrix* X = it2->second;
      string* rmap = X->rmap();
      int m = X->m();
      int n = X->n();

      double** XX = NULL;
      double** _Xval = NULL;
      double** _Xflag = NULL;
      int _i;

      _i = protomat->rimap()->find(d->id())->second;
      XX = X->X();

      for(int i=0;i<m;i++) {
         _Xval = ptr->fmval(rmap[i])->X();
         _Xflag = ptr->fmflag(rmap[i])->X();

         for(int j=0;j<n;j++) {
            _Xval[_i][j] = XX[i][j];
            _Xflag[_i][j] = 0;
         }
      }

   }

   //clean memory
   delete ridS;

   return ptr;
}

DatedMatrix* DatedMatrix::copy() {
   DatedMatrix* ptr = NULL;
   unordered_map<UtilDate*,Matrix*>* dm = this->dm();
   unordered_map<UtilDate*,Matrix*>::iterator it;

   ptr = DatedMatrix::instance();
   for(it=dm->begin();it!=dm->end();it++) {
      ptr->add(it->first, it->second->copy());
   }

   ptr->set_id(util_join(".",this->id(),"copy"));

   return ptr;
}

DatedMatrix* DatedMatrix::habs() {
   DatedMatrix* ptr = this->copy();
   ptr->_habs();
   return ptr;
}

DatedMatrix* DatedMatrix::hlog() {
   DatedMatrix* ptr = this->copy();
   ptr->_hlog();
   return ptr;
}

DatedMatrix* DatedMatrix::hmult(const double x) {
   DatedMatrix* ptr = this->copy();
   ptr->_hmult(x);
   return ptr;
}

DatedMatrix* DatedMatrix::hpow(const double x) {
   DatedMatrix* ptr = this->copy();
   ptr->_hpow(x);
   return ptr;
}

DatedMatrix* DatedMatrix::concat3_col(unordered_map<string,DatedMatrix*>* dmm) {
   DatedMatrix* dm = NULL;
   set<int>* S = NULL;
   set<int>::iterator it;
   unordered_map<string,DatedMatrix*>::iterator dmmit;

   dm = DatedMatrix::instance();
   S = dS_intersect(dmm);

   for(it=S->begin();it!=S->end();it++) {
      UtilDate* d = UtilDate::instance(*it);
      unordered_map<string, Matrix*> mm;
      for(dmmit=dmm->begin();dmmit!=dmm->end();dmmit++) mm[dmmit->first] = dmmit->second->dm(d);
      dm->add(d, Matrix::concat3_col(&mm));
   }

   //clean memory
   delete S;

   return dm;
}

set<int>* DatedMatrix::dS_intersect(unordered_map<string,DatedMatrix*>* dmm) {
   unordered_map<string,DatedMatrix*>::iterator it;
   set<int>* S = NULL;
   set<int>* dS1 = NULL;
   set<int>::iterator dS1_it;

   S = new set<int>();
   for(it=dmm->begin();it!=dmm->end() && dS1==NULL;it++) dS1 = it->second->dS();
   if(dS1==NULL) return S;

   for(dS1_it=dS1->begin();dS1_it!=dS1->end();dS1_it++) {
      int dic = *dS1_it;
      bool flag = true;
      for(it=dmm->begin();it!=dmm->end() && flag;it++) flag = flag && (it->second->dm(dic)!=NULL);
      if(flag) S->insert(dic);
   }

   return S;
}

#endif

