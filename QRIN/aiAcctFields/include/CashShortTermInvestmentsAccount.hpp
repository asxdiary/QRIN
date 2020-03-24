// Name:     CashShortTermInvestmentsAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CashShortTermInvestmentsAccount_hpp
#define ASX_CashShortTermInvestmentsAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class CashShortTermInvestmentsAccount;
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

class CashShortTermInvestmentsAccount : public PositionAccount  {

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
	CashShortTermInvestmentsAccount();
	CashShortTermInvestmentsAccount(const CashShortTermInvestmentsAccount* ptr);
	CashShortTermInvestmentsAccount(const CashShortTermInvestmentsAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_CashShortTermInvestmentsAccount();

	//Destructor
	virtual ~CashShortTermInvestmentsAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_CashShortTermInvestmentsAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_CashShortTermInvestmentsAccount(string fname);
	virtual void fscan(string fname);
	void fscan_CashShortTermInvestmentsAccount(string fname);

	//Reset
	virtual void reset();
	void reset_CashShortTermInvestmentsAccount();


	/** ------ Static Functions ----------------*/

	static CashShortTermInvestmentsAccount* instance();

	static CashShortTermInvestmentsAccount* instance_fscan(string fname);

   static CashShortTermInvestmentsAccount* __ptr_CashShortTermInvestmentsAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

