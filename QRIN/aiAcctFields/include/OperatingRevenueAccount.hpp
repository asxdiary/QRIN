// Name:     OperatingRevenueAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_OperatingRevenueAccount_hpp
#define ASX_OperatingRevenueAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class OperatingRevenueAccount;
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

class OperatingRevenueAccount : public FlowAccount  {

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
	OperatingRevenueAccount();
	OperatingRevenueAccount(const OperatingRevenueAccount* ptr);
	OperatingRevenueAccount(const OperatingRevenueAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_OperatingRevenueAccount();

	//Destructor
	virtual ~OperatingRevenueAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_OperatingRevenueAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_OperatingRevenueAccount(string fname);
	virtual void fscan(string fname);
	void fscan_OperatingRevenueAccount(string fname);

	//Reset
	virtual void reset();
	void reset_OperatingRevenueAccount();


	/** ------ Static Functions ----------------*/

	static OperatingRevenueAccount* instance();

	static OperatingRevenueAccount* instance_fscan(string fname);

   static OperatingRevenueAccount* __ptr_OperatingRevenueAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

