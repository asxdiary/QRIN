// Name:     DebtObligationsLongTermAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DebtObligationsLongTermAccount_hpp
#define ASX_DebtObligationsLongTermAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class DebtObligationsLongTermAccount;
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

class DebtObligationsLongTermAccount : public PositionAccount  {

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
	DebtObligationsLongTermAccount();
	DebtObligationsLongTermAccount(const DebtObligationsLongTermAccount* ptr);
	DebtObligationsLongTermAccount(const DebtObligationsLongTermAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_DebtObligationsLongTermAccount();

	//Destructor
	virtual ~DebtObligationsLongTermAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_DebtObligationsLongTermAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_DebtObligationsLongTermAccount(string fname);
	virtual void fscan(string fname);
	void fscan_DebtObligationsLongTermAccount(string fname);

	//Reset
	virtual void reset();
	void reset_DebtObligationsLongTermAccount();


	/** ------ Static Functions ----------------*/

	static DebtObligationsLongTermAccount* instance();

	static DebtObligationsLongTermAccount* instance_fscan(string fname);

   static DebtObligationsLongTermAccount* __ptr_DebtObligationsLongTermAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

