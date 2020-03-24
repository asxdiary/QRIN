// Name:     NonContinuingOperationsItemsAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_NonContinuingOperationsItemsAccount_hpp
#define ASX_NonContinuingOperationsItemsAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class NonContinuingOperationsItemsAccount;
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

class NonContinuingOperationsItemsAccount : public FlowAccount  {

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
	NonContinuingOperationsItemsAccount();
	NonContinuingOperationsItemsAccount(const NonContinuingOperationsItemsAccount* ptr);
	NonContinuingOperationsItemsAccount(const NonContinuingOperationsItemsAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_NonContinuingOperationsItemsAccount();

	//Destructor
	virtual ~NonContinuingOperationsItemsAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_NonContinuingOperationsItemsAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_NonContinuingOperationsItemsAccount(string fname);
	virtual void fscan(string fname);
	void fscan_NonContinuingOperationsItemsAccount(string fname);

	//Reset
	virtual void reset();
	void reset_NonContinuingOperationsItemsAccount();


	/** ------ Static Functions ----------------*/

	static NonContinuingOperationsItemsAccount* instance();

	static NonContinuingOperationsItemsAccount* instance_fscan(string fname);

   static NonContinuingOperationsItemsAccount* __ptr_NonContinuingOperationsItemsAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

