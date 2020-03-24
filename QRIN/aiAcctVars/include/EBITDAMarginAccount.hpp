// Name:     EBITDAMarginAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_EBITDAMarginAccount_hpp
#define ASX_EBITDAMarginAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class EBITDAMarginAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "R_DoubleDbAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctVars;
using namespace aiDb;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiAcctVars {

class EBITDAMarginAccount : public R_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: EBITDA/OperatingRevenue
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
	EBITDAMarginAccount();
	EBITDAMarginAccount(const EBITDAMarginAccount* ptr);
	EBITDAMarginAccount(const EBITDAMarginAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_EBITDAMarginAccount();

	//Destructor
	virtual ~EBITDAMarginAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_EBITDAMarginAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_EBITDAMarginAccount(string fname);
	virtual void fscan(string fname);
	void fscan_EBITDAMarginAccount(string fname);

	//Reset
	virtual void reset();
	void reset_EBITDAMarginAccount();


	/** ------ Static Functions ----------------*/

	static EBITDAMarginAccount* instance();

	static EBITDAMarginAccount* instance_fscan(string fname);

   static EBITDAMarginAccount* __ptr_EBITDAMarginAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

