// Name:     D_R_Debt_EquityAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_R_Debt_EquityAccount_hpp
#define ASX_D_R_Debt_EquityAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class D_R_Debt_EquityAccount;
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

class D_R_Debt_EquityAccount : public D_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: D.R_Debt_EquityAccount
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
	D_R_Debt_EquityAccount();
	D_R_Debt_EquityAccount(const D_R_Debt_EquityAccount* ptr);
	D_R_Debt_EquityAccount(const D_R_Debt_EquityAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_D_R_Debt_EquityAccount();

	//Destructor
	virtual ~D_R_Debt_EquityAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_D_R_Debt_EquityAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_D_R_Debt_EquityAccount(string fname);
	virtual void fscan(string fname);
	void fscan_D_R_Debt_EquityAccount(string fname);

	//Reset
	virtual void reset();
	void reset_D_R_Debt_EquityAccount();


	/** ------ Static Functions ----------------*/

	static D_R_Debt_EquityAccount* instance();

	static D_R_Debt_EquityAccount* instance_fscan(string fname);

   static D_R_Debt_EquityAccount* __ptr_D_R_Debt_EquityAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

