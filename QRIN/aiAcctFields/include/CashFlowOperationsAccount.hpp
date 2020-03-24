// Name:     CashFlowOperationsAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CashFlowOperationsAccount_hpp
#define ASX_CashFlowOperationsAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class CashFlowOperationsAccount;
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

class CashFlowOperationsAccount : public FlowAccount  {

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
	CashFlowOperationsAccount();
	CashFlowOperationsAccount(const CashFlowOperationsAccount* ptr);
	CashFlowOperationsAccount(const CashFlowOperationsAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_CashFlowOperationsAccount();

	//Destructor
	virtual ~CashFlowOperationsAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_CashFlowOperationsAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_CashFlowOperationsAccount(string fname);
	virtual void fscan(string fname);
	void fscan_CashFlowOperationsAccount(string fname);

	//Reset
	virtual void reset();
	void reset_CashFlowOperationsAccount();


	/** ------ Static Functions ----------------*/

	static CashFlowOperationsAccount* instance();

	static CashFlowOperationsAccount* instance_fscan(string fname);

   static CashFlowOperationsAccount* __ptr_CashFlowOperationsAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

