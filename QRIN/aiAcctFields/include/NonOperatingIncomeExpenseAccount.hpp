// Name:     NonOperatingIncomeExpenseAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_NonOperatingIncomeExpenseAccount_hpp
#define ASX_NonOperatingIncomeExpenseAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class NonOperatingIncomeExpenseAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctFields;
using namespace aiDbAccounts;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiAcctFields {

class NonOperatingIncomeExpenseAccount : public FlowAccount  {

/**
 * 	Class Description:
 * 		TotalAssets Account
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
	NonOperatingIncomeExpenseAccount();
	NonOperatingIncomeExpenseAccount(const NonOperatingIncomeExpenseAccount* ptr);
	NonOperatingIncomeExpenseAccount(const NonOperatingIncomeExpenseAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_NonOperatingIncomeExpenseAccount();

	//Destructor
	virtual ~NonOperatingIncomeExpenseAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_NonOperatingIncomeExpenseAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_NonOperatingIncomeExpenseAccount(string fname);
	virtual void fscan(string fname);
	void fscan_NonOperatingIncomeExpenseAccount(string fname);

	//Reset
	virtual void reset();
	void reset_NonOperatingIncomeExpenseAccount();


	/** ------ Static Functions ----------------*/

	static NonOperatingIncomeExpenseAccount* instance();

	static NonOperatingIncomeExpenseAccount* instance_fscan(string fname);

   static NonOperatingIncomeExpenseAccount* __ptr_NonOperatingIncomeExpenseAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

