// Name:     CostRevenueAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CostRevenueAccount_hpp
#define ASX_CostRevenueAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class CostRevenueAccount;
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

class CostRevenueAccount : public FlowAccount  {

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
	CostRevenueAccount();
	CostRevenueAccount(const CostRevenueAccount* ptr);
	CostRevenueAccount(const CostRevenueAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_CostRevenueAccount();

	//Destructor
	virtual ~CostRevenueAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_CostRevenueAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_CostRevenueAccount(string fname);
	virtual void fscan(string fname);
	void fscan_CostRevenueAccount(string fname);

	//Reset
	virtual void reset();
	void reset_CostRevenueAccount();


	/** ------ Static Functions ----------------*/

	static CostRevenueAccount* instance();

	static CostRevenueAccount* instance_fscan(string fname);

   static CostRevenueAccount* __ptr_CostRevenueAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

