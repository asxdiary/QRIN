// Name:     OtherCashFlowsFinancingActivitiesNetAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_OtherCashFlowsFinancingActivitiesNetAccount_hpp
#define ASX_OtherCashFlowsFinancingActivitiesNetAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class OtherCashFlowsFinancingActivitiesNetAccount;
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

class OtherCashFlowsFinancingActivitiesNetAccount : public FlowAccount  {

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
	OtherCashFlowsFinancingActivitiesNetAccount();
	OtherCashFlowsFinancingActivitiesNetAccount(const OtherCashFlowsFinancingActivitiesNetAccount* ptr);
	OtherCashFlowsFinancingActivitiesNetAccount(const OtherCashFlowsFinancingActivitiesNetAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_OtherCashFlowsFinancingActivitiesNetAccount();

	//Destructor
	virtual ~OtherCashFlowsFinancingActivitiesNetAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_OtherCashFlowsFinancingActivitiesNetAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_OtherCashFlowsFinancingActivitiesNetAccount(string fname);
	virtual void fscan(string fname);
	void fscan_OtherCashFlowsFinancingActivitiesNetAccount(string fname);

	//Reset
	virtual void reset();
	void reset_OtherCashFlowsFinancingActivitiesNetAccount();


	/** ------ Static Functions ----------------*/

	static OtherCashFlowsFinancingActivitiesNetAccount* instance();

	static OtherCashFlowsFinancingActivitiesNetAccount* instance_fscan(string fname);

   static OtherCashFlowsFinancingActivitiesNetAccount* __ptr_OtherCashFlowsFinancingActivitiesNetAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

