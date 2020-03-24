// Name:     EarningsLossesEquityInvestmentsAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_EarningsLossesEquityInvestmentsAccount_hpp
#define ASX_EarningsLossesEquityInvestmentsAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class EarningsLossesEquityInvestmentsAccount;
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

class EarningsLossesEquityInvestmentsAccount : public FlowAccount  {

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
	EarningsLossesEquityInvestmentsAccount();
	EarningsLossesEquityInvestmentsAccount(const EarningsLossesEquityInvestmentsAccount* ptr);
	EarningsLossesEquityInvestmentsAccount(const EarningsLossesEquityInvestmentsAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_EarningsLossesEquityInvestmentsAccount();

	//Destructor
	virtual ~EarningsLossesEquityInvestmentsAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_EarningsLossesEquityInvestmentsAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_EarningsLossesEquityInvestmentsAccount(string fname);
	virtual void fscan(string fname);
	void fscan_EarningsLossesEquityInvestmentsAccount(string fname);

	//Reset
	virtual void reset();
	void reset_EarningsLossesEquityInvestmentsAccount();


	/** ------ Static Functions ----------------*/

	static EarningsLossesEquityInvestmentsAccount* instance();

	static EarningsLossesEquityInvestmentsAccount* instance_fscan(string fname);

   static EarningsLossesEquityInvestmentsAccount* __ptr_EarningsLossesEquityInvestmentsAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

