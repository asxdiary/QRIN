// Name:     FlexMatrix.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_FlexMatrix_hpp
#define ASX_FlexMatrix_hpp

namespace aiMath {
//Forword decalaration
class FlexMatrix;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Model.hpp"
#include "Summarizable.hpp"
#include "Matrix.hpp"
#include "MathUtils.hpp"
#include "DatedMatrix.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMath;
using namespace aiMathUtils;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiMath {

class FlexMatrix : public Model , public Summarizable  {

/**
 * 	Class Description:
 * 		This class is used to represent a group of matrices that share a
 * 		common set of rows and columns; consistency checks are implemented
 * 		to avoid accidental uploading of non-confomring matrices;
 * 		support for missing entries is provided though flag matrices
 * 
 * 	Assumptions:
 * 		None
 * 
 * 	Objects:
 * 	   O Matrix* _protomat;
 * 	   row-column names protomat that across matrices
 *
 * 	   O unordered_map<string,Matrix*>* _fmval;
 * 	   value matrices
 *
 * 	   O unordered_map<string,Matrix*>* _fmflag;
 * 	   flag matrices; if the entry is present the value is set to 0;
 * 	   non-zero values can encapsulate error codes that maintained exogenously
 * 
 * 	Ownership:
 * 		All objects owned
 * 
 */

private:
/**	Data Members */
	Matrix* _protomat;
	unordered_map<string,Matrix*>* _fmval;
	unordered_map<string,Matrix*>* _fmflag;

protected: 

	/** Protected Constructors */
	FlexMatrix();
	FlexMatrix(const FlexMatrix* ptr);
	FlexMatrix(const FlexMatrix& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(Matrix* protomat);
	void init_FlexMatrix(Matrix* protomat);
	virtual void init_protomat(Matrix* protomat);
	virtual void init_fm();

	//Destructor
	virtual ~FlexMatrix(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_FlexMatrix(); 
	virtual void cleanMem_protomat();
	virtual void cleanMem_fmval();
	virtual void cleanMem_fmflag();

	/** Public Data Access Functions */
	virtual Matrix* protomat();
	virtual unordered_map<string,Matrix*>* fmval();
	virtual unordered_map<string,Matrix*>* fmflag();
   virtual Matrix* fmval(string aid, bool iflag=false);
   virtual Matrix* fmflag(string aid, bool iflag=false);

	/** Public data Set functions */
   virtual void add_fm(string aid, Matrix* Xval, Matrix* Xflag);

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_FlexMatrix(string fname);
	virtual void fscan(string fname);
	void fscan_FlexMatrix(string fname);

	//Reset
	virtual void reset();
	void reset_FlexMatrix();


	/** ------ Static Functions ----------------*/

	static FlexMatrix* instance(Matrix* protomat);

	static FlexMatrix* instance_fscan(string fname);

   static bool isEqual(FlexMatrix* fm1, FlexMatrix* fm2);

	/** ----------  Non-standard functions start here -----------*/

   virtual bool chk_consistency(Matrix* X);
   
   virtual FlexMatrix* fvix(int N=12);
   virtual void fvix(FlexMatrix* fm, string aid, int N);

   virtual bool isEqual(FlexMatrix* fm);

   /** Convert a FlexMatrix into a DataMatrix; only those rows for which 
    * all the elements are missing are dropped */
   virtual DatedMatrix* dm();

};

};

#endif

