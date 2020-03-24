// Name:     D_EBITDAMarginAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_EBITDAMarginAccount_hpp
#define ASX_D_EBITDAMarginAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class D_EBITDAMarginAccount;
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

class D_EBITDAMarginAccount : public D_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: D.R_EBITDAMarginAccount
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
	D_EBITDAMarginAccount();
	D_EBITDAMarginAccount(const D_EBITDAMarginAccount* ptr);
	D_EBITDAMarginAccount(const D_EBITDAMarginAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_D_EBITDAMarginAccount();

	//Destructor
	virtual ~D_EBITDAMarginAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_D_EBITDAMarginAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_D_EBITDAMarginAccount(string fname);
	virtual void fscan(string fname);
	void fscan_D_EBITDAMarginAccount(string fname);

	//Reset
	virtual void reset();
	void reset_D_EBITDAMarginAccount();


	/** ------ Static Functions ----------------*/

	static D_EBITDAMarginAccount* instance();

	static D_EBITDAMarginAccount* instance_fscan(string fname);

   static D_EBITDAMarginAccount* __ptr_D_EBITDAMarginAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

