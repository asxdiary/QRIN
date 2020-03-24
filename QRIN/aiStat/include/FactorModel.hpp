// Name:     FactorModel.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_FactorModel_hpp
#define ASX_FactorModel_hpp

namespace aiStat {
//Forword decalaration
class FactorModel;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Matrix.hpp"
#include "Model.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMath;

//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiStat {

class FactorModel : public Model  {

/**	Class Description  
 *
 *    This class contains model of the form 
 *    y = Xf + u
 *    covariance (variance) matrix associated with f (u) is stored as 
 *    Omega (Delta), if available
 *
 *    Memory Management: ownership of all attributes is assumed 
 * */

private:
/**	Data Members */
	Matrix* _y;
	Matrix* _X;
	Matrix* _f;
	Matrix* _u;
	Matrix* _Omega;
	Matrix* _Delta;

protected: 

	/** Protected Constructors */
	FactorModel();
	FactorModel(const FactorModel* ptr);
	FactorModel(const FactorModel& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(Matrix* y, Matrix* X, Matrix* f, Matrix* u, Matrix* Omega, Matrix* Delta);
	void init_FactorModel(Matrix* y, Matrix* X, Matrix* f, Matrix* u, Matrix* Omega, Matrix* Delta);
	virtual void init_y(Matrix* obj);
	virtual void init_X(Matrix* obj);
	virtual void init_f(Matrix* obj);
	virtual void init_u(Matrix* obj);
	virtual void init_Omega(Matrix* obj);
	virtual void init_Delta(Matrix* obj);

	//Destructor
	virtual ~FactorModel(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_FactorModel(); 
	virtual void cleanMem_y();
	virtual void cleanMem_X();
	virtual void cleanMem_f();
	virtual void cleanMem_u();
	virtual void cleanMem_Omega();
	virtual void cleanMem_Delta();

	/** Public Data Access Functions */
	virtual Matrix* y();
	virtual Matrix* X();
	virtual Matrix* f();
	virtual Matrix* u();
	virtual Matrix* Omega();
	virtual Matrix* Delta();

	/** Public data Set functions */
	virtual void set_y(Matrix* _obj);
	virtual void set_X(Matrix* _obj);
	virtual void set_f(Matrix* _obj);
	virtual void set_u(Matrix* _obj);
	virtual void set_Omega(Matrix* _obj);
	virtual void set_Delta(Matrix* _obj);

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_FactorModel(string fname);
	virtual void fscan(string fname);
	void fscan_FactorModel(string fname);

	//Reset
	virtual void reset();
	void reset_FactorModel();


	/** ------ Static Functions ----------------*/

	static FactorModel* instance(Matrix* y, Matrix* X, Matrix* f, 
                                Matrix* u=NULL, Matrix* Omega=NULL, Matrix* Delta=NULL);

	static FactorModel* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual void compute_u();
   virtual void compute_y();

   virtual double compute_R2();

   /** nullf specifies the null hypothesis f around which the t-stats are computed */
   virtual Matrix* compute_tstat(Matrix* nullf, int xval);

};

};

#endif

