// Name:     NetCashFlowsProvidedUsedInvestingActivitiesAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_NetCashFlowsProvidedUsedInvestingActivitiesAccount_hpp
#define ASX_NetCashFlowsProvidedUsedInvestingActivitiesAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class NetCashFlowsProvidedUsedInvestingActivitiesAccount;
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

class NetCashFlowsProvidedUsedInvestingActivitiesAccount : public FlowAccount  {

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
	NetCashFlowsProvidedUsedInvestingActivitiesAccount();
	NetCashFlowsProvidedUsedInvestingActivitiesAccount(const NetCashFlowsProvidedUsedInvestingActivitiesAccount* ptr);
	NetCashFlowsProvidedUsedInvestingActivitiesAccount(const NetCashFlowsProvidedUsedInvestingActivitiesAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_NetCashFlowsProvidedUsedInvestingActivitiesAccount();

	//Destructor
	virtual ~NetCashFlowsProvidedUsedInvestingActivitiesAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_NetCashFlowsProvidedUsedInvestingActivitiesAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_NetCashFlowsProvidedUsedInvestingActivitiesAccount(string fname);
	virtual void fscan(string fname);
	void fscan_NetCashFlowsProvidedUsedInvestingActivitiesAccount(string fname);

	//Reset
	virtual void reset();
	void reset_NetCashFlowsProvidedUsedInvestingActivitiesAccount();


	/** ------ Static Functions ----------------*/

	static NetCashFlowsProvidedUsedInvestingActivitiesAccount* instance();

	static NetCashFlowsProvidedUsedInvestingActivitiesAccount* instance_fscan(string fname);

   static NetCashFlowsProvidedUsedInvestingActivitiesAccount* __ptr_NetCashFlowsProvidedUsedInvestingActivitiesAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

