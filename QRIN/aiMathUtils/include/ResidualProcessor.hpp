// Name:     ResidualProcessor.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ResidualProcessor_hpp
#define ASX_ResidualProcessor_hpp

namespace aiMathUtils {
//Forword decalaration
class ResidualProcessor;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Matrix.hpp"
#include "MatrixProcessor.hpp"
#include "Regression.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiStatUtils;
using namespace aiStat;
using namespace aiMath;


//Parameters/////////////////////////////
#define ResidualProcessor_row_flag  false
/////////////////////////////////////////

namespace aiMathUtils {

class ResidualProcessor : public MatrixProcessor  {

/**	Class Description  
 *
 *    This class is used to orthogonalize the columns (rows) of X
 *    to those of W using (weighted) unweighted regression if Delta is (non) NULL
 *    orthoS functionality is not available for this implementation
 *
 *    Objects:
 *       W: matrices used in orthogonalization
 *
 *    Ownership:
 *       W is NOT owned by this object */

private:
/**	Data Members */
	Matrix* _W;

protected: 

	/** Protected Constructors */
	ResidualProcessor();
	ResidualProcessor(const ResidualProcessor* ptr);
	ResidualProcessor(const ResidualProcessor& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(bool insitu, bool row_flag);
	void init_ResidualProcessor();

	//Destructor
	virtual ~ResidualProcessor(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_ResidualProcessor(); 
	virtual void cleanMem_W();

	/** Public Data Access Functions */
	virtual Matrix* W();

	/** Public data Set functions */
	virtual void set_W(Matrix* _obj);
   virtual void set_log_flag(bool _obj);

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_ResidualProcessor(string fname);
	virtual void fscan(string fname);
	void fscan_ResidualProcessor(string fname);

	//Reset
	virtual void reset();
	void reset_ResidualProcessor();
	virtual void reset_W();


	/** ------ Static Functions ----------------*/

	static ResidualProcessor* instance(bool insitu, 
                                      bool row_flag=ResidualProcessor_row_flag);

	static ResidualProcessor* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual void configure(Matrix* X, Matrix* W, Matrix* Delta);
   virtual void algo_exec();

};

};

#endif

