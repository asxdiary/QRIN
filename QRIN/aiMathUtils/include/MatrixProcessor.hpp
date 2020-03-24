// Name:     MatrixProcessor.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_MatrixProcessor_hpp
#define ASX_MatrixProcessor_hpp

namespace aiMathUtils {
//Forword decalaration
class MatrixProcessor;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Matrix.hpp"
#include "ModelGen.hpp"
#include "Model.hpp"
#include "MatrixProcessor.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMath;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiMathUtils {

class MatrixProcessor : public ModelGen  {

/**	Class Description 
 *
 *    This class serves as the super class of matrix processors
 *
 *    Objects:
 *       row_flag: a boolean flag indicating whether the operation
 *       is performed on columns (row_flag=false) or on rows (row_flag=true)
 *       insitu: a boolean flag indicating whether the original is to be
 *       replaced by the model matrix
 *       log_flag: a boolean flag indicating whether the transformation
 *       should be applied to log(power(X_ij,-2))
 *       X: input matrix to be processed
 *       Delta: sqrt of the inverse weights; NOTE: Not all sub-classes implement
 *       the weighted option
 *
 *       O set<int>* orthoS; 
 *       set of columns which should be orthogonalized; these are set to
 *       0 after the other operations have been applied
 *
 *       O bool orthoS_flag;
 *       a boolean flag indicating whether orthoS functionality is to be used
 *
 *    Ownership:
 *       All objects except X and Delta; note that if insitu=true then ownership
 *       of X is assumed implicitly through mdl object */

private:
/**	Data Members */
	bool _row_flag;
	bool _log_flag;
	bool _insitu;
	Matrix* _X;
	Matrix* _Delta;
	bool _orthoS_flag;
	set<int>* _orthoS;

protected: 

	/** Protected Constructors */
	MatrixProcessor();
	MatrixProcessor(const MatrixProcessor* ptr);
	MatrixProcessor(const MatrixProcessor& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(bool insitu, bool row_flag);
	void init_MatrixProcessor(bool insitu, bool row_flag);
	virtual void init_row_flag(bool obj);
	virtual void init_log_flag(bool obj);
	virtual void init_insitu(bool obj);
	virtual void init_orthoS_flag();
   virtual void init_orthoS();

	//Destructor
	virtual ~MatrixProcessor(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_MatrixProcessor(); 
	virtual void cleanMem_X();
	virtual void cleanMem_Delta();
	virtual void cleanMem_orthoS();

	/** Public Data Access Functions */
	virtual bool row_flag();
	virtual bool log_flag();
	virtual bool insitu();
	virtual Matrix* X();
	virtual Matrix* Delta();
	virtual bool orthoS_flag();
	virtual set<int>* orthoS();
   virtual Matrix* mdl();

	/** Public data Set functions */
	virtual void set_row_flag(bool _obj);
	virtual void set_log_flag(bool _obj);
	virtual void set_insitu(bool _obj);
	virtual void set_X(Matrix* _obj);
	virtual void set_Delta(Matrix* _obj);
	virtual void set_orthoS_flag(bool _obj);
	virtual void add_orthoS(int j);
	virtual void add_orthoS(set<int>* orthoS);

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_MatrixProcessor(string fname);
	virtual void fscan(string fname);
	void fscan_MatrixProcessor(string fname);

	//Reset
	virtual void reset();
	void reset_MatrixProcessor();
	virtual void reset_X();
	virtual void reset_Delta();


	/** ------ Static Functions ----------------*/

	static MatrixProcessor* instance(bool insitu, bool row_flag);

	static MatrixProcessor* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual Matrix* extract_mdl();
   virtual void configure(Matrix* X, Matrix* Delta);
   virtual void algo_exec();
   virtual Matrix* exec(Matrix* X, Matrix* Delta, MatrixProcessor** kernelp=NULL);

   virtual MatrixProcessor* kernel();
   virtual MatrixProcessor* copy();

};

};

#endif

