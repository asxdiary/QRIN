// Name:     D_DPOAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_DPOAccount_hpp
#define ASX_D_DPOAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class D_DPOAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "D_DoubleDbAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctVars;
using namespace aiDb;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiAcctVars {

class D_DPOAccount : public D_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: D.DPOAccount
 * 
 * 	Assumptions:
 * 		None
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

protected: 

	/** Protected Constructors */
	D_DPOAccount();
	D_DPOAccount(const D_DPOAccount* ptr);
	D_DPOAccount(const D_DPOAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_D_DPOAccount();

	//Destructor
	virtual ~D_DPOAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_D_DPOAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_D_DPOAccount(string fname);
	virtual void fscan(string fname);
	void fscan_D_DPOAccount(string fname);

	//Reset
	virtual void reset();
	void reset_D_DPOAccount();


	/** ------ Static Functions ----------------*/

	static D_DPOAccount* instance();

	static D_DPOAccount* instance_fscan(string fname);

   static D_DPOAccount* __ptr_D_DPOAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

