// Name:     PayablesTOAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_PayablesTOAccount_hpp
#define ASX_PayablesTOAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class PayablesTOAccount;
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

class PayablesTOAccount : public R_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: CostRevenueAccount/Avg AccountsPayableAccount
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
	PayablesTOAccount();
	PayablesTOAccount(const PayablesTOAccount* ptr);
	PayablesTOAccount(const PayablesTOAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_PayablesTOAccount();

	//Destructor
	virtual ~PayablesTOAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_PayablesTOAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_PayablesTOAccount(string fname);
	virtual void fscan(string fname);
	void fscan_PayablesTOAccount(string fname);

	//Reset
	virtual void reset();
	void reset_PayablesTOAccount();


	/** ------ Static Functions ----------------*/

	static PayablesTOAccount* instance();

	static PayablesTOAccount* instance_fscan(string fname);

   static PayablesTOAccount* __ptr_PayablesTOAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

