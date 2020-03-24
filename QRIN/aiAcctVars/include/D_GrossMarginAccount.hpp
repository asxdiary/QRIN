// Name:     D_GrossMarginAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_GrossMarginAccount_hpp
#define ASX_D_GrossMarginAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class D_GrossMarginAccount;
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

class D_GrossMarginAccount : public D_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: D.R_GrossMarginAccount
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
	D_GrossMarginAccount();
	D_GrossMarginAccount(const D_GrossMarginAccount* ptr);
	D_GrossMarginAccount(const D_GrossMarginAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_D_GrossMarginAccount();

	//Destructor
	virtual ~D_GrossMarginAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_D_GrossMarginAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_D_GrossMarginAccount(string fname);
	virtual void fscan(string fname);
	void fscan_D_GrossMarginAccount(string fname);

	//Reset
	virtual void reset();
	void reset_D_GrossMarginAccount();


	/** ------ Static Functions ----------------*/

	static D_GrossMarginAccount* instance();

	static D_GrossMarginAccount* instance_fscan(string fname);

   static D_GrossMarginAccount* __ptr_D_GrossMarginAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

