// Name:     IncomeBeforeIncomeTaxesAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_IncomeBeforeIncomeTaxesAccount_hpp
#define ASX_IncomeBeforeIncomeTaxesAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class IncomeBeforeIncomeTaxesAccount;
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

class IncomeBeforeIncomeTaxesAccount : public FlowAccount  {

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
	IncomeBeforeIncomeTaxesAccount();
	IncomeBeforeIncomeTaxesAccount(const IncomeBeforeIncomeTaxesAccount* ptr);
	IncomeBeforeIncomeTaxesAccount(const IncomeBeforeIncomeTaxesAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_IncomeBeforeIncomeTaxesAccount();

	//Destructor
	virtual ~IncomeBeforeIncomeTaxesAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_IncomeBeforeIncomeTaxesAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_IncomeBeforeIncomeTaxesAccount(string fname);
	virtual void fscan(string fname);
	void fscan_IncomeBeforeIncomeTaxesAccount(string fname);

	//Reset
	virtual void reset();
	void reset_IncomeBeforeIncomeTaxesAccount();


	/** ------ Static Functions ----------------*/

	static IncomeBeforeIncomeTaxesAccount* instance();

	static IncomeBeforeIncomeTaxesAccount* instance_fscan(string fname);

   static IncomeBeforeIncomeTaxesAccount* __ptr_IncomeBeforeIncomeTaxesAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

