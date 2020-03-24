// Name:     AccountsPayableAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_AccountsPayableAccount_hpp
#define ASX_AccountsPayableAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class AccountsPayableAccount;
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

class AccountsPayableAccount : public PositionAccount  {

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
	AccountsPayableAccount();
	AccountsPayableAccount(const AccountsPayableAccount* ptr);
	AccountsPayableAccount(const AccountsPayableAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_AccountsPayableAccount();

	//Destructor
	virtual ~AccountsPayableAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_AccountsPayableAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_AccountsPayableAccount(string fname);
	virtual void fscan(string fname);
	void fscan_AccountsPayableAccount(string fname);

	//Reset
	virtual void reset();
	void reset_AccountsPayableAccount();


	/** ------ Static Functions ----------------*/

	static AccountsPayableAccount* instance();

	static AccountsPayableAccount* instance_fscan(string fname);

   static AccountsPayableAccount* __ptr_AccountsPayableAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

