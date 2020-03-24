// Name:     RegressionKernel.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_RegressionKernel_hpp
#define ASX_RegressionKernel_hpp

namespace aiStatUtils {
//Forword decalaration
class RegressionKernel;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "MatrixProcessor.hpp"
#include "Matrix.hpp"
#include "ModelGen.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMathUtils;
using namespace aiMath;
using namespace aiStatUtils;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiStatUtils {

class RegressionKernel : public ModelGen  {

/**
 * 	Class Description:
 * 		This class is used to store the results of estimation, and
 * 		generate forecasts on an ongoing basis
 * 
 * 	Assumptions:
 * 		forecast = sum_{j} beta_j * x_j
 * 		m2 = sqrt ( x.T * Omega_beta * x + sigma_u^2 )
 * 
 * 	Objects:
 * 		O proc: MatrixProcessor that is used to process the inputs
 * 		        before applying the formula
 * 		O Delta_proc: MatrixProcessor that is used to process the Delta inputs
 * 		        before applying the formula
 * 		O beta: estimated OLS coefficients
 * 		O Omega_beta: covariance of estimated coefficients
 * 		O sigma_u: standard error
 * 		NO X: input matrix (independent variables)
 * 		NO Delta: input matrix (estimate of idiosyncratic risk)
 * 		P mdl: forecast 
 * 		O m2: second moment of the forecast
 * 
 * 	Ownership:
 * 		All objects owned
 * 
 */

private:
/**	Data Members */
	MatrixProcessor* _proc;
	MatrixProcessor* _Delta_proc;
	Matrix* _beta;
	Matrix* _Omega_beta;
	double _sigma_u;
	Matrix* _X;
	Matrix* _Delta;
	Matrix* _m2;

protected: 

	/** Protected Constructors */
	RegressionKernel();
	RegressionKernel(const RegressionKernel* ptr);
	RegressionKernel(const RegressionKernel& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
   virtual void init(MatrixProcessor* proc, 
                     MatrixProcessor* Delta_proc,
                     Matrix* beta, 
                     Matrix* Omega_beta, double sigma_u);
   void init_RegressionKernel(MatrixProcessor* proc, 
                              MatrixProcessor* Delta_proc,
                              Matrix* beta, 
                            Matrix* Omega_beta, double sigma_u);
	virtual void init_proc(MatrixProcessor* proc);
	virtual void init_Delta_proc(MatrixProcessor* proc);
	virtual void init_beta(Matrix* obj);
	virtual void init_Omega_beta(Matrix* obj);
	virtual void init_sigma_u(double obj);

	//Destructor
	virtual ~RegressionKernel(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_RegressionKernel(); 
	virtual void cleanMem_proc();
	virtual void cleanMem_Delta_proc();
	virtual void cleanMem_beta();
	virtual void cleanMem_Omega_beta();
	virtual void cleanMem_X();
	virtual void cleanMem_Delta();
	virtual void cleanMem_m2();

	/** Public Data Access Functions */
	virtual MatrixProcessor* proc();
	virtual MatrixProcessor* Delta_proc();
	virtual Matrix* beta();
	virtual Matrix* Omega_beta();
	virtual double sigma_u();
	virtual Matrix* X();
	virtual Matrix* Delta();
	virtual Matrix* m2();

	/** Public data Set functions */
	virtual void set_proc(MatrixProcessor* _obj);
	virtual void set_Delta_proc(MatrixProcessor* _obj);
	virtual void set_beta(Matrix* _obj);
	virtual void set_Omega_beta(Matrix* _obj);
	virtual void set_sigma_u(double _obj);
	virtual void set_X(Matrix* _obj);
	virtual void set_Delta(Matrix* _obj);
	virtual void set_m2(Matrix* _obj);

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_RegressionKernel(string fname);
	virtual void fscan(string fname);
	void fscan_RegressionKernel(string fname);

	//Reset
	virtual void reset();
	void reset_RegressionKernel();
	virtual void reset_proc();
	virtual void reset_Delta_proc();
	virtual void reset_X();
	virtual void reset_Delta();
	virtual void reset_m2();


	/** ------ Static Functions ----------------*/

   static RegressionKernel* instance(MatrixProcessor* proc, 
                                     MatrixProcessor* Delta_proc,
                                     Matrix* beta, 
                                   Matrix* Omega_beta, double sigma_u);

	static RegressionKernel* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual Matrix* mdl();
   virtual Matrix* extract_mdl();
   virtual Matrix* extract_m2();

   virtual void configure(Matrix* X, Matrix* Delta);
   virtual void algo_exec();

   /** This function only compares beta, Omega_beta and sigma_u */
   virtual bool isEqual(RegressionKernel* fk);

   virtual RegressionKernel* copy();

};

};

#endif

