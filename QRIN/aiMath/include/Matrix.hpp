// Name:     Matrix.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_Matrix_hpp
#define ASX_Matrix_hpp

namespace aiMath {
//Forword decalaration
class Matrix;
};

#include <unordered_map>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Summarizable.hpp"
#include "Model.hpp"

using namespace std;
using namespace aiUtils;

//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiMath {

class Matrix : public Model, public Summarizable  {

/**	Class Description  
 * This class is used to represent double** dense matrices 
 *
 * Assumptions:
 *
 * */

private:
/**	Data Members */
	int _m;
	int _n;
	double** _X;
	string* _rmap;
	unordered_map<string,int>* _rimap;
	string* _cmap;
	unordered_map<string,int>* _cimap;

protected: 

	/** Protected Constructors */
	Matrix();
	Matrix(const Matrix* ptr);
	Matrix(const Matrix& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(const int m, const int n, double** X, 
                     string* rmap, 
                     unordered_map<string,int>* rimap, 
                     string* cmap, 
                     unordered_map<string,int>* cimap);
	void init_Matrix(const int m, const int n, double** X,
                     string* rmap, 
                     unordered_map<string,int>* rimap, 
                     string* cmap, 
                     unordered_map<string,int>* cimap);
	virtual void init_m(const int obj);
	virtual void init_n(const int obj);
	virtual void init_X(double** obj);
	virtual void init_rmap_rimap(string* omap, unordered_map<string,int>* imap);
	virtual void init_cmap_cimap(string* omap, unordered_map<string,int>* imap);

	//Destructor
	virtual ~Matrix(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_Matrix(); 
	virtual void cleanMem_X();
	virtual void cleanMem_rmap();
	virtual void cleanMem_rimap();
	virtual void cleanMem_cmap();
	virtual void cleanMem_cimap();

	/** Public Data Access Functions */
	virtual int m();
	virtual int n();
	virtual double** X();
	virtual string* rmap();
	virtual unordered_map<string,int>* rimap();
	virtual string* cmap();
	virtual unordered_map<string,int>* cimap();

	/** Public data Set functions */
	virtual void set_rmap_rimap(string* omap, unordered_map<string,int>* imap);
	virtual void set_cmap_cimap(string* omap, unordered_map<string,int>* imap);
   virtual void set_rmap_rimap(const int i, string val);
   virtual void set_cmap_cimap(const int i, string val);

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);
	void mywarn_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string str);
	void fprint_Matrix(string str);
	virtual void fscan(string str);
	void fscan_Matrix(string str);

	//Reset
	virtual void reset();
	void reset_Matrix();


	/** ------ Static Functions ----------------*/

	//For error message handling
	static void cerr_msg(string msg, string func);
	static void cwarn_msg(string msg, string func);

   /** Assumptions:
    * Both rmap and rimap cannot be non-NULL at the same time; same
    * applies for cmap and cimap. This is done to avoid creating 
    * inconsistent row and column names */
	static Matrix* instance(const int m, const int n, double** X=NULL,
                     string* rmap = NULL, 
                     unordered_map<string,int>* rimap = NULL, 
                     string* cmap = NULL, 
                     unordered_map<string,int>* cimap = NULL,
                     bool rand_names_flag = true);

	static Matrix* instance2(const int m, const int n, double** X=NULL);

   static Matrix* instance_fscan(string fname, const bool raw=false);

   /** This function reads a matrix specified in a csv format
    * with row and column names */
   static Matrix* instance_fread_table(string fname,
                                       string delimiter=Global::instance()->delimiter());


   static Matrix* ones(const int m, const int n, const double val=1.0);
   static Matrix* instance_col(const double val);
   static Matrix* instance_col(const double val1, const double val2);
   static Matrix* instance_col(const double val1, const double val2, const double val3);

   /** This function creates a matrix with a single column using the valm
    * map; the keys are sorted before being inserted in the matrix */
   static Matrix* instance_col(unordered_map<string,double>* valm, string col_id="value");
   static Matrix* instance_row(unordered_map<string,double>* valm, string row_id="value");

   //Identity matrix
   static Matrix* identity(const int n);

   static bool isEqual(Matrix* mat, Matrix* mat2, 
                       bool permute_rows=false, bool permute_cols=false,
                       bool chk_rnames=false, bool chk_cnames=false);
   static Matrix** Matrix_array(Matrix* mat1, Matrix* mat2);
   static Matrix** Matrix_array(Matrix* mat1, Matrix* mat2, Matrix* mat3);

   /** perform linear combination of matrices in mat using weights specified in w */
   static Matrix* lc(Matrix** mat, Matrix* w);
   static Matrix* lc(const double w1, Matrix* mat1, const double w2, Matrix* mat2);
   static Matrix* add(Matrix* mat1, Matrix* mat2);
   static Matrix* subtract(Matrix* mat1, Matrix* mat2);

   static Matrix* transpose(Matrix* mat);
   static Matrix* mult(Matrix* mat, const double fac);

   /** 
    * Delta is assumed to be a mx1 column matrix;
    * columns of matrix mat are scaled by elements of Delta
    * if inv_flag=true then inverse of elements of Delta are used instead */
   static Matrix* chmult(Matrix* mat, Matrix* Delta, bool inv_flag=false);
   /**    row-counterpart of chmult  */
   static Matrix* rhmult(Matrix* mat, Matrix* Delta, bool inv_flag=false);

   /**   compute X*Y where X and Y can be transposed based on the flags
    *    If non-NULL Delta is used to scale the conforming dimensions of both the
    *    matrices; it is assumed to be a column vector and computation becomes
    *    X * Diag(Delta) * Diag(Delta) * Y
    *    If DeltaIflag=true then the inverse elements of Delta are used instead
    * */
   static Matrix* mult(Matrix* X1, Matrix* X2, 
                       bool X1T=false,
                       bool X2T=false,
                       Matrix* Delta=NULL,
                       bool DeltaIflag=true);

   //Inverse function
   static Matrix* inverse(Matrix* mat);
   static Matrix* inverse_psd(Matrix* mat);

   //Solve Ax = b
   static Matrix* solve(Matrix* A, Matrix* b);
   static Matrix* solve_sym(Matrix* A, Matrix* b);

   static Matrix* concat(const bool row_flag, Matrix** mA, const int T, 
                         string* pfx=NULL);

   static Matrix* concat_col(Matrix** mA, const int T, string* pfx=NULL);
   static Matrix* concat_row(Matrix** mA, const int T, string* pfx=NULL);

   /** This function allows the matrices of mA to have different set of row
    * names; only those row-names that occur in all matrices are included */
   static Matrix* concat3_col(const int T, Matrix** mA, string* pfx=NULL);
   static Matrix* concat3_col(Matrix* X, Matrix* Y, string* pfx=NULL);
   static Matrix* concat3_col(Matrix* X, Matrix* Y, Matrix* Z, string* pfx=NULL);
   static Matrix* concat3_col(Matrix* X, Matrix* Y, Matrix* Z, Matrix* Z2, string* pfx=NULL);
   static Matrix* concat3_col(unordered_map<string,Matrix*>* mm);

   static Matrix* concat3_row(const int T, Matrix** mA, string* pfx=NULL);
   static Matrix* concat3_row(unordered_map<string,Matrix*>* mm);

   static Matrix* copy(Matrix* X);

   //element level operations
   virtual Matrix* hpow(const double eta);
   virtual Matrix* hlog();
   virtual Matrix* hexp();
   virtual Matrix* habs();

   /** Winsorize the row (row_flag=true) using (alpha1,alpha2) */
   static Matrix* winsorize(Matrix* X, 
                            const bool row_flag, const double alpha1, const double alpha2);

   /** Computes the unweighted correlation for each column j;
    * Assumes mat1 and mat2 have the same number of columns;
    * Does not assume they have the same number of rows as it maps 
    * each row in mat1 to its corresponding row in mat2 using rmap(); */
   static Matrix* corr(Matrix* mat1, Matrix* mat2, Matrix* Delta, bool i2_flag); 

   /** Return the set of common rows */
   static set<string>* rows_common(Matrix* X1, Matrix* X2);
   static set<string>* cols_common(Matrix* X1, Matrix* X2);

   /** ----------  Non-standard functions start here -----------*/

   virtual int chk();
   virtual bool isSymmetric();
   virtual bool isEqual(Matrix* mat,
                        bool permute_rows=false, bool permute_cols=false,
                        bool chk_rnames=false, bool chk_cnames=false);
   virtual double l2n();

   /** l2-norm of the columns */
   virtual Matrix* l2nc(bool normalize=false,
                        bool winsorize_flag=false,
                        double alpha1=0.025,
                        double alpha2=0.975,
                        Matrix* Delta=NULL,
                        bool inv_flag=true);

   virtual void _transpose();
   virtual void _mult(const double fac);
   virtual void _add(const double fac);
   virtual void _hmult(const double fac);
   virtual void _hmult(Matrix* F);
   virtual void _hmult(bool row_flag, Matrix* Delta, bool inv_flag);
   virtual void _chmult(Matrix* Delta, bool inv_flag);
   virtual void _rhmult(Matrix* Delta, bool inv_flag);
   virtual void _add(Matrix* mat);
   virtual void _subtract(Matrix* mat);
   virtual void _hpow(const double eta);
   virtual void _hlog();
   virtual void _hexp();
   virtual void _habs();
   virtual void _winsorize(const bool row_flag, const double alpha1, const double alpha2);

   virtual Matrix* copy();
   virtual Matrix* transpose();
   virtual void copy(const bool row_flag, const int k, double*& vec);
   virtual void copyrow(const int k, double*& vec);
   virtual void copycol(const int k, double*& vec);
   virtual void assign(Matrix* mat, int* ra=NULL, int* ca = NULL);
   virtual void copyrow(Matrix* Y, int iX, int iY);
   virtual void copycol(Matrix* Y, int jX, int jY);

   virtual void copynames(Matrix* X, bool rflag, bool cflag);
   virtual void pfxnames(string pfx, bool rflag, bool cflag);

   virtual Matrix* col(const int j);
   virtual Matrix* row(const int i);

   virtual unordered_map<string,double>* row(const int i, string pfx, string sfx,
                                            string* cmap = NULL,
                                            unordered_map<string,double>* valm=NULL);

   /** Creates a sub-matrix using only those row-names that are also 
    * present in X */
   virtual Matrix* subrow(Matrix* X);
   virtual Matrix* subcol(Matrix* X);
   virtual Matrix* sub(Matrix* X, bool rnames_flag, bool cnames_flag);

   /** Creates a sub-matrix using the specified ordering and numbers
    * of rows/columns */
   virtual Matrix* sub(int mm, int nn, 
                       int* ra, int* ca);

   /** Creates a sub-matrix using the inclusion/exclusing criterion
    * and returns the ordering in rap and cap (if non-NULL) */
   virtual Matrix* sub2(list<int>* rS, list<int>* cS,
                       set<int>* xrS=NULL, set<int>* xcS=NULL,
                       int** rap=NULL, int** cap=NULL);

   virtual Matrix* sub(set<int>* rS, set<int>* cS,
                       set<int>* xrS=NULL, set<int>* xcS=NULL,
                       int** rap=NULL, int** cap=NULL);

   virtual Matrix* sub3(set<string>* rS, set<string>* cS,
                       set<string>* xrS=NULL, set<string>* xcS=NULL,
                       int** rap=NULL, int** cap=NULL);

   /** This function extends the current matrix to a larger matrix;
    * it is meant to serve as an inverse of sub 
    * rmap, cmap, rimap and cimap variables are abdandoned */
   virtual Matrix* lift(int mm, int nn,
                        int* ra, int* ca,
                        Matrix* XX=NULL);

   /** This function returns the indices of rows in the jth colum with
    * non-zero entries; cnzS does the same for columns */
   virtual set<int>* rnzS(const int j);
   virtual set<int>* cnzS(const int i);

   /** This function prints a single csv file that contains 
    * - row names
    * - column names
    * - matrix data */
   virtual void fprint_table(string fname);

   virtual void fprint_raw(string fname);

   /** When row_flag is true, this function returns the row index
    * of the incumbent matrix that is closest to the i'th row of Y
    * under the l2-norm.
    *
    * When row_flag is false, the same operation is applied on columns
    * of the incumbent matrix and Y */
   virtual int l2closest(Matrix* Y, int i, bool row_flag);

   /** This function returns the eta percentile of rows (row_flag=true);
    * if S is not NULL then subset of rows specified by S is used */
   virtual Matrix* pct(double eta, bool row_flag, set<int>* S=NULL, 
                       Matrix* Delta=NULL);

   /** This function returns the mean values of the rows (row_flag=true);
    * if Delta is non-NULL then weighted mean is returned instead;
    * if inv_flag=true then inverse of Delta is used instead 
    * if S!=NULL then only those columns that are present in S are used */
   virtual Matrix* mean_row(Matrix* Delta, bool inv_flag, set<int>* S=NULL);
   virtual Matrix* mean_col(Matrix* Delta, bool inv_flag, set<int>* S=NULL);

   /** Compute the concentration coefficient; it is assumed
    * that matrix entries are non-negative */
   virtual double cc(double row_flag, int j, set<int>* S = NULL, 
                     bool i2_flag=false);

   virtual Matrix* cc(double row_flag, set<int>* S = NULL, bool i2_flag=false);

   virtual double max();
   virtual double min();

   /** This matrix returns a matrix composed of ranks of the jth column */
   virtual Matrix* colrank(const int j);
   virtual Matrix* colrank();

   virtual Matrix* colrank_normalized(const int j);
   virtual Matrix* colrank_normalized();

   /** compute the correlation between columns j1 and j2 */
   virtual double correl_col(const int j1, const int j2);
   virtual double sumprod_col(const int j1, const int j2);

   /** For summarizable interface */
   virtual void summary(list<unordered_map<string,string>*>*& L, set<string>* headerS=NULL);
   virtual void fprint_summary(string fname, set<string>* headerS=NULL);

};

};

#endif

