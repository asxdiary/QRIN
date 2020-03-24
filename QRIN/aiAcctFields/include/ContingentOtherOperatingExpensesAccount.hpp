// Name:     ContingentOtherOperatingExpensesAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ContingentOtherOperatingExpensesAccount_hpp
#define ASX_ContingentOtherOperatingExpensesAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class ContingentOtherOperatingExpensesAccount;
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

class ContingentOtherOperatingExpensesAccount : public FlowAccount  {

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
	ContingentOtherOperatingExpensesAccount();
	ContingentOtherOperatingExpensesAccount(const ContingentOtherOperatingExpensesAccount* ptr);
	ContingentOtherOperatingExpensesAccount(const ContingentOtherOperatingExpensesAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_ContingentOtherOperatingExpensesAccount();

	//Destructor
	virtual ~ContingentOtherOperatingExpensesAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_ContingentOtherOperatingExpensesAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_ContingentOtherOperatingExpensesAccount(string fname);
	virtual void fscan(string fname);
	void fscan_ContingentOtherOperatingExpensesAccount(string fname);

	//Reset
	virtual void reset();
	void reset_ContingentOtherOperatingExpensesAccount();


	/** ------ Static Functions ----------------*/

	static ContingentOtherOperatingExpensesAccount* instance();

	static ContingentOtherOperatingExpensesAccount* instance_fscan(string fname);

   static ContingentOtherOperatingExpensesAccount* __ptr_ContingentOtherOperatingExpensesAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

