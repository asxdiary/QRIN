// Name:     GrossMarginAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_GrossMarginAccount_hpp
#define ASX_GrossMarginAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class GrossMarginAccount;
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

class GrossMarginAccount : public R_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: 1 - CostRevenue/OperatingRevenue
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
	GrossMarginAccount();
	GrossMarginAccount(const GrossMarginAccount* ptr);
	GrossMarginAccount(const GrossMarginAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_GrossMarginAccount();

	//Destructor
	virtual ~GrossMarginAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_GrossMarginAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_GrossMarginAccount(string fname);
	virtual void fscan(string fname);
	void fscan_GrossMarginAccount(string fname);

	//Reset
	virtual void reset();
	void reset_GrossMarginAccount();


	/** ------ Static Functions ----------------*/

	static GrossMarginAccount* instance();

	static GrossMarginAccount* instance_fscan(string fname);

   static GrossMarginAccount* __ptr_GrossMarginAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

