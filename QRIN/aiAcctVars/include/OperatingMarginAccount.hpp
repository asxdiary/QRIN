// Name:     OperatingMarginAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_OperatingMarginAccount_hpp
#define ASX_OperatingMarginAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class OperatingMarginAccount;
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

class OperatingMarginAccount : public R_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: OperatingProfit/OperatingRevenue
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
	OperatingMarginAccount();
	OperatingMarginAccount(const OperatingMarginAccount* ptr);
	OperatingMarginAccount(const OperatingMarginAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_OperatingMarginAccount();

	//Destructor
	virtual ~OperatingMarginAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_OperatingMarginAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_OperatingMarginAccount(string fname);
	virtual void fscan(string fname);
	void fscan_OperatingMarginAccount(string fname);

	//Reset
	virtual void reset();
	void reset_OperatingMarginAccount();


	/** ------ Static Functions ----------------*/

	static OperatingMarginAccount* instance();

	static OperatingMarginAccount* instance_fscan(string fname);

   static OperatingMarginAccount* __ptr_OperatingMarginAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

