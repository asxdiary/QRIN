// Name:     Regression.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_Regression_hpp
#define ASX_Regression_hpp

namespace aiStatUtils {
//Forword decalaration
class Regression;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Matrix.hpp"
#include "ModelGen.hpp"
#include "Model.hpp"
#include "FactorModel.hpp"
#include "RegressionKernel.hpp"
#include "MatrixProcessor.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMath;
using namespace aiMathUtils;
using namespace aiStat;
using namespace aiStatUtils;

//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiStatUtils {

class Regression : public ModelGen  {

/**	Class Description  
 *    
 *    This class is used to model GLS regressions
 *
 *    Objects
 *       y, X : dependent and independent variables; y is assumed to have 
 *       multiple columns to allow running several regressions simultaneously
 *       and efficiently
 *       Delta: if non-NULL Delta is assumed to be an estimator of idiosyncratic
 *       standard deviation
 *       y_proc: Matrix Processor that is applied to y before running regression
 *       proc: Matrix Processor that is applied to X before running regression
 *       Delta_proc: Matrix Processor that is applied to Delta before running regression
 *       f, tstat : estimated regression coefficients and t-stats
 *       fk: an instance of Forecasting Kernel
 *
 *    Assumptions
 *       The forecast kernel is generated only from the first column of
 *       y; a more sophisticated application will involve taking some
 *       form of average over multiple columns of y but for the time being
 *       the simpler implementation is used
 *
 *    Ownership:
 *       All objects except y, X and Delta
 *
 * */

private:
/**	Data Members */
	Matrix* _y;
	Matrix* _X;
	Matrix* _Delta;
   MatrixProcessor* _proc;
   MatrixProcessor* _y_proc;
   MatrixProcessor* _Delta_proc;
	Matrix* _f;
	Matrix* _tstat;
   RegressionKernel* _fk;

protected: 

	/** Protected Constructors */
	Regression();
	Regression(const Regression* ptr);
	Regression(const Regression& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_Regression();

	//Destructor
	virtual ~Regression(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_Regression(); 
	virtual void cleanMem_y();
	virtual void cleanMem_X();
	virtual void cleanMem_Delta();
	virtual void cleanMem_proc();
	virtual void cleanMem_y_proc();
	virtual void cleanMem_Delta_proc();
	virtual void cleanMem_f();
	virtual void cleanMem_tstat();
	virtual void cleanMem_fk();

	/** Public Data Access Functions */
	virtual Matrix* y();
	virtual Matrix* X();
	virtual Matrix* Delta();
	virtual MatrixProcessor* proc();
	virtual MatrixProcessor* y_proc();
	virtual MatrixProcessor* Delta_proc();
	virtual Matrix* f();
	virtual Matrix* tstat();
	virtual RegressionKernel* fk();
   virtual FactorModel* mdl();

	/** Public data Set functions */
	virtual void set_y(Matrix* _obj);
	virtual void set_X(Matrix* _obj);
	virtual void set_Delta(Matrix* _obj);
	virtual void set_proc(MatrixProcessor* _obj);
	virtual void set_y_proc(MatrixProcessor* _obj);
	virtual void set_Delta_proc(MatrixProcessor* _obj);
	virtual void set_f(Matrix* _obj);
	virtual void set_tstat(Matrix* _obj);
	virtual void set_fk(RegressionKernel* _obj);

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_Regression(string fname);
	virtual void fscan(string fname);
	void fscan_Regression(string fname);

	//Reset
	virtual void reset();
	void reset_Regression();
	virtual void reset_y();
	virtual void reset_X();
	virtual void reset_Delta();
	virtual void reset_proc();
	virtual void reset_y_proc();
	virtual void reset_Delta_proc();
	virtual void reset_f();
	virtual void reset_tstat();
	virtual void reset_fk();


	/** ------ Static Functions ----------------*/

	static Regression* instance();

	static Regression* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual void configure(Matrix* y, Matrix* X, Matrix* Delta);
   virtual void algo_exec();
   virtual FactorModel* extract_mdl();
   virtual RegressionKernel* extract_fk();

};

};

#endif

