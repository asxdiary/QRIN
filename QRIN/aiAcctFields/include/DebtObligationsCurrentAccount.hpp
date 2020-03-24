// Name:     DebtObligationsCurrentAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DebtObligationsCurrentAccount_hpp
#define ASX_DebtObligationsCurrentAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class DebtObligationsCurrentAccount;
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

class DebtObligationsCurrentAccount : public PositionAccount  {

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
	DebtObligationsCurrentAccount();
	DebtObligationsCurrentAccount(const DebtObligationsCurrentAccount* ptr);
	DebtObligationsCurrentAccount(const DebtObligationsCurrentAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_DebtObligationsCurrentAccount();

	//Destructor
	virtual ~DebtObligationsCurrentAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_DebtObligationsCurrentAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_DebtObligationsCurrentAccount(string fname);
	virtual void fscan(string fname);
	void fscan_DebtObligationsCurrentAccount(string fname);

	//Reset
	virtual void reset();
	void reset_DebtObligationsCurrentAccount();


	/** ------ Static Functions ----------------*/

	static DebtObligationsCurrentAccount* instance();

	static DebtObligationsCurrentAccount* instance_fscan(string fname);

   static DebtObligationsCurrentAccount* __ptr_DebtObligationsCurrentAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

