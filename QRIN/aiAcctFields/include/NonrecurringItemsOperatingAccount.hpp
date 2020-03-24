// Name:     NonrecurringItemsOperatingAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_NonrecurringItemsOperatingAccount_hpp
#define ASX_NonrecurringItemsOperatingAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class NonrecurringItemsOperatingAccount;
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

class NonrecurringItemsOperatingAccount : public FlowAccount  {

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
	NonrecurringItemsOperatingAccount();
	NonrecurringItemsOperatingAccount(const NonrecurringItemsOperatingAccount* ptr);
	NonrecurringItemsOperatingAccount(const NonrecurringItemsOperatingAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_NonrecurringItemsOperatingAccount();

	//Destructor
	virtual ~NonrecurringItemsOperatingAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_NonrecurringItemsOperatingAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_NonrecurringItemsOperatingAccount(string fname);
	virtual void fscan(string fname);
	void fscan_NonrecurringItemsOperatingAccount(string fname);

	//Reset
	virtual void reset();
	void reset_NonrecurringItemsOperatingAccount();


	/** ------ Static Functions ----------------*/

	static NonrecurringItemsOperatingAccount* instance();

	static NonrecurringItemsOperatingAccount* instance_fscan(string fname);

   static NonrecurringItemsOperatingAccount* __ptr_NonrecurringItemsOperatingAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

