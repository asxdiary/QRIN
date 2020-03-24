// Name:     GICS.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_GICS_hpp
#define ASX_GICS_hpp

namespace aiFin {
//Forword decalaration
class GICS;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Matrix.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMath;
using namespace aiFin;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiFin {

class GICS : public Model  {

/**
 * 	Class Description:
 * 		This class is used for maintaining GICS related information
 * 
 * 	Assumptions:
 * 		gsec: a matrix representing the sector codes; also stores
 * 		the mapping from sectors to integers through the rmap
 * 		gsubind: sub-industry counter part to gsec
 * 
 * 	Objects:
 * 		None
 * 
 * 	Ownership:
 * 		All objects owned
 * 
 */

private:
/**	Data Members */
	Matrix* _gsec;
	Matrix* _gsubind;

protected: 

	/** Protected Constructors */
	GICS();
	GICS(const GICS* ptr);
	GICS(const GICS& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_GICS();
	virtual void init_gsec();
	virtual void init_gsubind();

	//Destructor
	virtual ~GICS(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_GICS(); 
	virtual void cleanMem_gsec();
	virtual void cleanMem_gsubind();

	/** Public Data Access Functions */
	virtual Matrix* gsec();
	virtual Matrix* gsubind();

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_GICS(string fname);
	virtual void fscan(string fname);
	void fscan_GICS(string fname);

	//Reset
	virtual void reset();
	void reset_GICS();


	/** ------ Static Functions ----------------*/

	static GICS* instance();

	static GICS* instance_fscan(string fname);

   static GICS* __ptr_GICS;

	/** ----------  Non-standard functions start here -----------*/


};

};

#endif

