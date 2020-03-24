// Name:     DatedMatrix.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DatedMatrix_hpp
#define ASX_DatedMatrix_hpp

namespace aiMath {
//Forword decalaration
class DatedMatrix;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Matrix.hpp"
#include "UtilDate.hpp"
#include "FlexMatrix.hpp"
#include "MatrixProcessor.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMath;
using namespace aiMathUtils;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiMath {

class DatedMatrix : public Model  {

/**
 * 	Class Description:
 * 		This class is used to store dated matrices all of which
 * 		are assumed to have exactly the same number of columns
 * 		with identical column names and ordering
 * 
 * 	Assumptions:
 * 		See description above
 * 
 * 	Objects:
 * 		dm: map[Date -> Matrix]
 * 		dS: icodes of dates for which the matrices are available
 * 		nc: number of columns
 * 		cmap: column names
 * 		cimap: column names
 * 
 * 	Ownership:
 * 		All objects owned
 * 
 */

private:
/**	Data Members */
	unordered_map<UtilDate*,Matrix*>* _dm;
	set<int>* _dS;
   int _nc;
   string* _cmap;
   unordered_map<string,int>* _cimap;

protected: 

	/** Protected Constructors */
	DatedMatrix();
	DatedMatrix(const DatedMatrix* ptr);
	DatedMatrix(const DatedMatrix& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_DatedMatrix();
	virtual void init_dm();
	virtual void init_dS();

	//Destructor
	virtual ~DatedMatrix(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_DatedMatrix(); 
	virtual void cleanMem_dm();
	virtual void cleanMem_dS();
	virtual void cleanMem_cmap();
	virtual void cleanMem_cimap();

	/** Public Data Access Functions */
	virtual unordered_map<UtilDate*,Matrix*>* dm();
	virtual set<int>* dS();
	virtual int nc();
	virtual string* cmap();
	virtual unordered_map<string,int>* cimap();

	/** Public data Set functions */
	virtual void set_cmap_cimap(string* omap, unordered_map<string,int>* imap);

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_DatedMatrix(string fname);
	virtual void fscan(string fname);
	void fscan_DatedMatrix(string fname);

	//Reset
	virtual void reset();
	void reset_DatedMatrix();


	/** ------ Static Functions ----------------*/

	static DatedMatrix* instance();
	static DatedMatrix* instance(string id);

	static DatedMatrix* instance_fscan(string fname);
   static DatedMatrix* fscan_eom(string fname, UtilDate* da, UtilDate* db, string id="",
                                 bool use_dmid=true, int nlag=1);

   static DatedMatrix* lc(DatedMatrix* dm1, double val1,
                          DatedMatrix* dm2, double val2);

   static DatedMatrix* lc(DatedMatrix* dm1, unordered_map<UtilDate*,double>* theta1m,
                          DatedMatrix* dm2, unordered_map<UtilDate*,double>* theta2m);

   static DatedMatrix* subtract(DatedMatrix* dm1, DatedMatrix* dm2); 

   static DatedMatrix* concat3_col(unordered_map<string,DatedMatrix*>* dmm);

   static set<int>* dS_intersect(unordered_map<string,DatedMatrix*>* dmm);

	/** ----------  Non-standard functions start here -----------*/

   virtual void add(UtilDate* d, Matrix* X);
   virtual Matrix* dm(UtilDate* d);
   virtual Matrix* dm(int dic);

   /** This function restricts the cross-sectional universe to those rows
    * that are present in dm for each date */
   virtual DatedMatrix* univfilter(DatedMatrix* dm);

   /** Apply MatrixProcessor operation on all columns */
   virtual DatedMatrix* proc(MatrixProcessor* proc);

   /** This function returns performs column inclusion/exclusions as indicated */
   virtual DatedMatrix* project(set<int>* cinc, set<int>* cexc);
   virtual DatedMatrix* project(int j);
   virtual DatedMatrix* project(string cname);
   virtual DatedMatrix* project(string cname1, string cname2);

   /** This function creates a DatedMatrix with the specified lag; K<0, then
    * forward looking matrices are created; the fields are modified 
    * to have L{K} as the suffix */
   virtual DatedMatrix* eom_lag(int K);

   /** Winsorize the columns */
   virtual DatedMatrix* winsorize(double alpha1, double alpha2);

   /** This function computes cross-sectional analytics related to dm1 and dm2(=this);
    * the analysis is performed only on dates for which data is available for 
    * both dm1 and dm2; the returned matrix is indexed by dates and has
    * information in columns; if analS==NULL then all analytics are computed 
    *
    * number of elements in dm1
    * number of elements in dm2
    * number of common elements
    * Spearman Correlation for all pairs of columns in dm1 & dm2 (if sp_correl in analS)
    * Pearson Correlation for all pairs of columns in dm1 & dm2 (if p_correl in analS)
    * dm1*dm2 for all pairs of columns in dm1 & dm2 (if exp in analS)
    * */
   virtual Matrix* csanal(DatedMatrix* dm1, set<string>* analS=NULL,
                          list<DatedMatrix*>* dmDL=NULL);
   virtual Matrix* csanal(list<DatedMatrix*>* dm1L, set<string>* analS=NULL,
                          list<DatedMatrix*>* dmDL=NULL);
   virtual Matrix* csanal(DatedMatrix** dmA, int ndmA, set<string>* analS=NULL,
                          list<DatedMatrix*>* dmDL=NULL);


   /** Divide the cross-section for each date into K buckets based
    * on the j'th column; if j<0 then all columns are bucketized and K*nc 
    * DatedMatrices are returned */
   virtual DatedMatrix** bucketizeA_guts(int K, int j);
   virtual DatedMatrix** bucketizeA(int K, int j);
   virtual list<DatedMatrix*>* bucketizeL(int K, int j, list<DatedMatrix*>* dmL=NULL);

   /** Drop the first and last tail obtained from bucketizing into K buckets */
   virtual DatedMatrix* excise_tails(int K, int j);

   virtual bool isEqual(DatedMatrix* dm);

   /** This performs univariate analysis on the object */
   virtual Matrix* unianal();

   /** This computes the time series of concentration coefficients */
   virtual Matrix* cc(bool i2_flag);

   /** This performs univariate analysis on the object after 
    * bucketizing based on the first dataset */
   virtual Matrix* unianal(DatedMatrix* dm, int K, int j);

   /** This function performs auto-correlation analysis on the object at the specified
    * lag which is used in conjunction with eom_lag */
   virtual Matrix* eom_autoanal(int K, set<string>* analS=NULL);

   /** Concatenate all matrices into one matrix */
   virtual Matrix* concat();

   virtual DatedMatrix* copy();

   virtual DatedMatrix* hpow(const double eta);
   virtual DatedMatrix* habs();
   virtual DatedMatrix* hlog();
   virtual DatedMatrix* hmult(const double x);

   virtual void _hpow(const double eta);
   virtual void _habs();
   virtual void _hlog();
   virtual void _hmult(const double x);

   virtual FlexMatrix* fm();

   /** Return a union of all row names across the whole dataset */
   virtual set<string>* ridS();

};

};

#endif

