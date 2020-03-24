// Name:     MatrixCentralizer.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_MatrixCentralizer_hpp
#define ASX_MatrixCentralizer_hpp

namespace aiMathUtils {
//Forword decalaration
class MatrixCentralizer;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "MatrixProcessor.hpp"
#include "Matrix.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMath;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiMathUtils {

class MatrixCentralizer : public MatrixProcessor  {

/**	Class Description  
 *
 *    This class is used to serve as a super class of all 
 *    centralzing transformation of matrices
 *
 *    Objects:
 *       O loc, disp: location and dispersion to be used while Z-scoring
 *       O Xloc, Xdisp: location and dispersion of the incumbent matrix
 *
 *    Ownership:
 *       All objects are owned */

private:
/**	Data Members */
   Matrix* _loc; 
   Matrix* _disp; 
   Matrix* _Xloc; 
   Matrix* _Xdisp; 

protected: 

	/** Protected Constructors */
	MatrixCentralizer();
	MatrixCentralizer(const MatrixCentralizer* ptr);
	MatrixCentralizer(const MatrixCentralizer& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

   //Initializer
   virtual void init(bool insitu, bool row_flag, Matrix* loc, Matrix* disp);
   void init_MatrixCentralizer( Matrix* loc, Matrix* disp);
   virtual void init_loc(Matrix* obj);
   virtual void init_disp(Matrix* obj);

	//Destructor
	virtual ~MatrixCentralizer(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_MatrixCentralizer(); 
   virtual void cleanMem_loc();
   virtual void cleanMem_disp();
   virtual void cleanMem_Xloc();
   virtual void cleanMem_Xdisp();

	/** Public Data Access Functions */
   virtual Matrix* loc();
   virtual Matrix* disp();
   virtual Matrix* Xloc();
   virtual Matrix* Xdisp();

	/** Public data Set functions */
   virtual void set_loc(Matrix* obj);
   virtual void set_disp(Matrix* obj);
   virtual void set_Xloc(Matrix* obj);
   virtual void set_Xdisp(Matrix* obj);

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_MatrixCentralizer(string fname);
	virtual void fscan(string fname);
	void fscan_MatrixCentralizer(string fname);

	//Reset
	virtual void reset();
	void reset_MatrixCentralizer();


	/** ------ Static Functions ----------------*/

   static MatrixCentralizer* instance(bool insitu,
                                     bool row_flag, 
                                     Matrix* loc=NULL, Matrix* disp=NULL);

	static MatrixCentralizer* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual void configure(Matrix* X, Matrix* Delta);
   virtual void algo_exec();

   /** This function returns an instance of MatrixCentralizer that
    * captures the current location and dispersion parameters associated
    * with the incumbent input */
   virtual MatrixProcessor* kernel();

   virtual MatrixProcessor* copy();

};

};

#endif

