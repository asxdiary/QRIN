// Name:     DeferredPrepaidExpensesAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DeferredPrepaidExpensesAccount_hpp
#define ASX_DeferredPrepaidExpensesAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class DeferredPrepaidExpensesAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctFields;
using namespace aiDbAccounts;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiAcctFields {

class DeferredPrepaidExpensesAccount : public PositionAccount  {

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
	DeferredPrepaidExpensesAccount();
	DeferredPrepaidExpensesAccount(const DeferredPrepaidExpensesAccount* ptr);
	DeferredPrepaidExpensesAccount(const DeferredPrepaidExpensesAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_DeferredPrepaidExpensesAccount();

	//Destructor
	virtual ~DeferredPrepaidExpensesAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_DeferredPrepaidExpensesAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_DeferredPrepaidExpensesAccount(string fname);
	virtual void fscan(string fname);
	void fscan_DeferredPrepaidExpensesAccount(string fname);

	//Reset
	virtual void reset();
	void reset_DeferredPrepaidExpensesAccount();


	/** ------ Static Functions ----------------*/

	static DeferredPrepaidExpensesAccount* instance();

	static DeferredPrepaidExpensesAccount* instance_fscan(string fname);

   static DeferredPrepaidExpensesAccount* __ptr_DeferredPrepaidExpensesAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

