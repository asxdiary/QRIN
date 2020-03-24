// Name:     NetCashFlowsProvidedUsedFinancingActivitiesAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_NetCashFlowsProvidedUsedFinancingActivitiesAccount_hpp
#define ASX_NetCashFlowsProvidedUsedFinancingActivitiesAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class NetCashFlowsProvidedUsedFinancingActivitiesAccount;
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

class NetCashFlowsProvidedUsedFinancingActivitiesAccount : public FlowAccount  {

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
	NetCashFlowsProvidedUsedFinancingActivitiesAccount();
	NetCashFlowsProvidedUsedFinancingActivitiesAccount(const NetCashFlowsProvidedUsedFinancingActivitiesAccount* ptr);
	NetCashFlowsProvidedUsedFinancingActivitiesAccount(const NetCashFlowsProvidedUsedFinancingActivitiesAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_NetCashFlowsProvidedUsedFinancingActivitiesAccount();

	//Destructor
	virtual ~NetCashFlowsProvidedUsedFinancingActivitiesAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_NetCashFlowsProvidedUsedFinancingActivitiesAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_NetCashFlowsProvidedUsedFinancingActivitiesAccount(string fname);
	virtual void fscan(string fname);
	void fscan_NetCashFlowsProvidedUsedFinancingActivitiesAccount(string fname);

	//Reset
	virtual void reset();
	void reset_NetCashFlowsProvidedUsedFinancingActivitiesAccount();


	/** ------ Static Functions ----------------*/

	static NetCashFlowsProvidedUsedFinancingActivitiesAccount* instance();

	static NetCashFlowsProvidedUsedFinancingActivitiesAccount* instance_fscan(string fname);

   static NetCashFlowsProvidedUsedFinancingActivitiesAccount* __ptr_NetCashFlowsProvidedUsedFinancingActivitiesAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

