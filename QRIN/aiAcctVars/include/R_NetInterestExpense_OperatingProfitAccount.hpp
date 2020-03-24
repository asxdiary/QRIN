// Name:     R_NetInterestExpense_OperatingProfitAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_R_NetInterestExpense_OperatingProfitAccount_hpp
#define ASX_R_NetInterestExpense_OperatingProfitAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class R_NetInterestExpense_OperatingProfitAccount;
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

class R_NetInterestExpense_OperatingProfitAccount : public R_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: NetInterestExpenseAccount/OperatingProfitAccount
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
	R_NetInterestExpense_OperatingProfitAccount();
	R_NetInterestExpense_OperatingProfitAccount(const R_NetInterestExpense_OperatingProfitAccount* ptr);
	R_NetInterestExpense_OperatingProfitAccount(const R_NetInterestExpense_OperatingProfitAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_R_NetInterestExpense_OperatingProfitAccount();

	//Destructor
	virtual ~R_NetInterestExpense_OperatingProfitAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_R_NetInterestExpense_OperatingProfitAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_R_NetInterestExpense_OperatingProfitAccount(string fname);
	virtual void fscan(string fname);
	void fscan_R_NetInterestExpense_OperatingProfitAccount(string fname);

	//Reset
	virtual void reset();
	void reset_R_NetInterestExpense_OperatingProfitAccount();


	/** ------ Static Functions ----------------*/

	static R_NetInterestExpense_OperatingProfitAccount* instance();

	static R_NetInterestExpense_OperatingProfitAccount* instance_fscan(string fname);

   static R_NetInterestExpense_OperatingProfitAccount* __ptr_R_NetInterestExpense_OperatingProfitAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

