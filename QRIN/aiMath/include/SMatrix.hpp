// Name:     SMatrix.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_SMatrix_hpp
#define ASX_SMatrix_hpp

namespace aiMath {
//Forword decalaration
class SMatrix;
};

#include <unordered_map>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Global.hpp"
#include "Model.hpp"

using namespace std;
using namespace aiUtils;

//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiMath {

class SMatrix : public Model  {

/**	Class Description  
 * This class is used to represent string** matrices 
 *
 * Assumptions:
 *    - uniqueness of row and column names is assumed but not checked
 *    for the sake of efficiency
 *
 * */

private:
/**	Data Members */
	int _m;
	int _n;
	string** _X;
	string* _rmap;
	unordered_map<string,int>* _rimap;
	string* _cmap;
	unordered_map<string,int>* _cimap;

protected: 

	/** Protected Constructors */
	SMatrix();
	SMatrix(const SMatrix* ptr);
	SMatrix(const SMatrix& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(const int m, const int n, string** X, 
                     string* rmap, 
                     unordered_map<string,int>* rimap, 
                     string* cmap, 
                     unordered_map<string,int>* cimap);
	void init_SMatrix(const int m, const int n, string** X,
                     string* rmap, 
                     unordered_map<string,int>* rimap, 
                     string* cmap, 
                     unordered_map<string,int>* cimap);
	virtual void init_m(const int obj);
	virtual void init_n(const int obj);
	virtual void init_X(string** obj);
	virtual void init_rmap_rimap(string* omap, unordered_map<string,int>* imap);
	virtual void init_cmap_cimap(string* omap, unordered_map<string,int>* imap);

	//Destructor
	virtual ~SMatrix(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_SMatrix(); 
	virtual void cleanMem_X();
	virtual void cleanMem_rmap();
	virtual void cleanMem_rimap();
	virtual void cleanMem_cmap();
	virtual void cleanMem_cimap();

	/** Public Data Access Functions */
	virtual int m();
	virtual int n();
	virtual string** X();
	virtual string* rmap();
	virtual unordered_map<string,int>* rimap();
	virtual string* cmap();
	virtual unordered_map<string,int>* cimap();

	/** Public data Set functions */
	virtual void set_rmap_rimap(string* omap, unordered_map<string,int>* imap);
	virtual void set_cmap_cimap(string* omap, unordered_map<string,int>* imap);

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);
	void mywarn_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string str);
	void fprint_SMatrix(string str);
	virtual void fscan(string str);
	void fscan_SMatrix(string str);

	//Reset
	virtual void reset();
	void reset_SMatrix();


	/** ------ Static Functions ----------------*/

	//For error message handling
	static void cerr_msg(string msg, string func);
	static void cwarn_msg(string msg, string func);

   /** Assumptions:
    * Both rmap and rimap cannot be non-NULL at the same time; same
    * applies for cmap and cimap. This is done to avoid creating 
    * inconsistent row and column names */
	static SMatrix* instance(const int m, const int n, string** X=NULL,
                     string* rmap = NULL, 
                     unordered_map<string,int>* rimap = NULL, 
                     string* cmap = NULL, 
                     unordered_map<string,int>* cimap = NULL);

   static SMatrix* instance_fscan(string fname, const bool raw=false,
                                  string delimiter=Global::instance()->delimiter());

   static SMatrix* instance(list<unordered_map<string,string>*>* L, set<string>* headerS=NULL);

   static bool isEqual(SMatrix* mat, SMatrix* mat2);
   static SMatrix** SMatrix_array(SMatrix* mat1, SMatrix* mat2);
   static SMatrix** SMatrix_array(SMatrix* mat1, SMatrix* mat2, SMatrix* mat3);

   static SMatrix* transpose(SMatrix* mat);

   static SMatrix* concat(const bool row_flag, SMatrix** mA, const int T);

   /** ----------  Non-standard functions start here -----------*/

   virtual int chk();
   virtual bool isEqual(SMatrix* mat);

   virtual void _transpose();

   virtual SMatrix* copy();
   virtual void copy(const bool row_flag, const int k, string*& vec);
   virtual void copyrow(const int k, string*& vec);
   virtual void copycol(const int k, string*& vec);
   virtual void assign(SMatrix* mat, int* ra=NULL, int* ca = NULL);

   /** Creates a sub-SMatrix using the specified ordering and numbers
    * of rows/columns */
   virtual SMatrix* sub(int mm, int nn, 
                       int* ra, int* ca);

   /** Creates a sub-SMatrix using the inclusion/exclusing criterion
    * and returns the ordering in rap and cap (if non-NULL) */
   virtual SMatrix* sub(set<int>* rS, set<int>* cS,
                       set<int>* xrS=NULL, set<int>* xcS=NULL,
                       int** rap=NULL, int** cap=NULL);

   /** This function extends the current SMatrix to a larger SMatrix;
    * it is meant to serve as an inverse of sub 
    * rmap, cmap, rimap and cimap variables are abdandoned */
   virtual SMatrix* lift(int mm, int nn,
                        int* ra, int* ca);

   /** This function returns the indices of rows in the jth colum with
    * non-zero entries; cnzS does the same for columns */
   virtual set<int>* rnzS(const int j);
   virtual set<int>* cnzS(const int i);

   virtual void fprint_raw(string fname);

};

};

#endif

