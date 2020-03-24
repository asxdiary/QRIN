// Name:     R_Cash_WCAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_R_Cash_WCAccount_hpp
#define ASX_R_Cash_WCAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class R_Cash_WCAccount;
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

class R_Cash_WCAccount : public R_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: CashShortTermInvestmentsAccount/WorkingCapitalAccount
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
	R_Cash_WCAccount();
	R_Cash_WCAccount(const R_Cash_WCAccount* ptr);
	R_Cash_WCAccount(const R_Cash_WCAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_R_Cash_WCAccount();

	//Destructor
	virtual ~R_Cash_WCAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_R_Cash_WCAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_R_Cash_WCAccount(string fname);
	virtual void fscan(string fname);
	void fscan_R_Cash_WCAccount(string fname);

	//Reset
	virtual void reset();
	void reset_R_Cash_WCAccount();


	/** ------ Static Functions ----------------*/

	static R_Cash_WCAccount* instance();

	static R_Cash_WCAccount* instance_fscan(string fname);

   static R_Cash_WCAccount* __ptr_R_Cash_WCAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

