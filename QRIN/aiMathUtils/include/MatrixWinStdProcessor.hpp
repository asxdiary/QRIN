// Name:     MatrixWinStdProcessor.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_MatrixWinStdProcessor_hpp
#define ASX_MatrixWinStdProcessor_hpp

namespace aiMathUtils {
//Forword decalaration
class MatrixWinStdProcessor;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "MatrixCentralizer.hpp"
#include "Matrix.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMath;


//Parameters/////////////////////////////
#define MatrixWinStdProcessor_row_flag  false
#define MatrixWinStdProcessor_alpha  0.025
/////////////////////////////////////////

namespace aiMathUtils {

class MatrixWinStdProcessor : public MatrixCentralizer  {

/**	Class Description  
 *
 *    This class is used to model winsorization and standardization 
 *    transformation of matrices
 *
 *    Algorithm:
 *       1. Compute robust mean and standard deviation using winsorization (alpha)
 *       2. Compute the z-score 
 *
 *    Objects:
 *       alpha: double paramaters
 *       std_flag: a boolean flag indicating whether standardization
 *       should be applied
 *
 *    Ownership:
 *       All objects are owned */

private:
/**	Data Members */
	double _alpha;
   bool _std_flag;

protected: 

	/** Protected Constructors */
	MatrixWinStdProcessor();
	MatrixWinStdProcessor(const MatrixWinStdProcessor* ptr);
	MatrixWinStdProcessor(const MatrixWinStdProcessor& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(bool insitu, bool row_flag, 
                     Matrix* loc, Matrix* disp,
                     double alpha, bool std_flag);
	void init_MatrixWinStdProcessor(double alpha, bool std_flag);
	virtual void init_alpha(double obj);
	virtual void init_std_flag(bool obj);

	//Destructor
	virtual ~MatrixWinStdProcessor(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_MatrixWinStdProcessor(); 

	/** Public Data Access Functions */
	virtual double alpha();
	virtual bool std_flag();

	/** Public data Set functions */
	virtual void set_alpha(double _obj);
	virtual void set_std_flag(bool _obj);

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_MatrixWinStdProcessor(string fname);
	virtual void fscan(string fname);
	void fscan_MatrixWinStdProcessor(string fname);

	//Reset
	virtual void reset();
	void reset_MatrixWinStdProcessor();


	/** ------ Static Functions ----------------*/

   static MatrixWinStdProcessor* instance(bool insitu,
                                     bool row_flag=MatrixWinStdProcessor_row_flag, 
                                     Matrix* loc=NULL, Matrix* disp=NULL,
                                     double alpha=MatrixWinStdProcessor_alpha,
                                     bool std_flag=true);

	static MatrixWinStdProcessor* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual void configure(Matrix* X, Matrix* Delta);
   virtual void algo_exec();
   virtual Matrix* exec(Matrix* X, Matrix* Delta);

   virtual MatrixProcessor* kernel();
   virtual MatrixProcessor* copy();

};

};

#endif

