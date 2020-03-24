// Name:     NetInterestExpenseAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_NetInterestExpenseAccount_hpp
#define ASX_NetInterestExpenseAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class NetInterestExpenseAccount;
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

class NetInterestExpenseAccount : public FlowAccount  {

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
	NetInterestExpenseAccount();
	NetInterestExpenseAccount(const NetInterestExpenseAccount* ptr);
	NetInterestExpenseAccount(const NetInterestExpenseAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_NetInterestExpenseAccount();

	//Destructor
	virtual ~NetInterestExpenseAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_NetInterestExpenseAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_NetInterestExpenseAccount(string fname);
	virtual void fscan(string fname);
	void fscan_NetInterestExpenseAccount(string fname);

	//Reset
	virtual void reset();
	void reset_NetInterestExpenseAccount();


	/** ------ Static Functions ----------------*/

	static NetInterestExpenseAccount* instance();

	static NetInterestExpenseAccount* instance_fscan(string fname);

   static NetInterestExpenseAccount* __ptr_NetInterestExpenseAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

