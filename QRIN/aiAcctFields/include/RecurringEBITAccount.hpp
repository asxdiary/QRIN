// Name:     RecurringEBITAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_RecurringEBITAccount_hpp
#define ASX_RecurringEBITAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class RecurringEBITAccount;
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

class RecurringEBITAccount : public FlowAccount  {

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
	RecurringEBITAccount();
	RecurringEBITAccount(const RecurringEBITAccount* ptr);
	RecurringEBITAccount(const RecurringEBITAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_RecurringEBITAccount();

	//Destructor
	virtual ~RecurringEBITAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_RecurringEBITAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_RecurringEBITAccount(string fname);
	virtual void fscan(string fname);
	void fscan_RecurringEBITAccount(string fname);

	//Reset
	virtual void reset();
	void reset_RecurringEBITAccount();


	/** ------ Static Functions ----------------*/

	static RecurringEBITAccount* instance();

	static RecurringEBITAccount* instance_fscan(string fname);

   static RecurringEBITAccount* __ptr_RecurringEBITAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

