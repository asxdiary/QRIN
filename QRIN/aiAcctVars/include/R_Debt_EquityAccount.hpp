// Name:     R_Debt_EquityAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_R_Debt_EquityAccount_hpp
#define ASX_R_Debt_EquityAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class R_Debt_EquityAccount;
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

class R_Debt_EquityAccount : public R_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: TotalLiabilitiesAccount/TotalEquityCapitalAccount
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
	R_Debt_EquityAccount();
	R_Debt_EquityAccount(const R_Debt_EquityAccount* ptr);
	R_Debt_EquityAccount(const R_Debt_EquityAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_R_Debt_EquityAccount();

	//Destructor
	virtual ~R_Debt_EquityAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_R_Debt_EquityAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_R_Debt_EquityAccount(string fname);
	virtual void fscan(string fname);
	void fscan_R_Debt_EquityAccount(string fname);

	//Reset
	virtual void reset();
	void reset_R_Debt_EquityAccount();


	/** ------ Static Functions ----------------*/

	static R_Debt_EquityAccount* instance();

	static R_Debt_EquityAccount* instance_fscan(string fname);

   static R_Debt_EquityAccount* __ptr_R_Debt_EquityAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

