// Name:     PreferredStockDividendsOtherAdjustmentsAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_PreferredStockDividendsOtherAdjustmentsAccount_hpp
#define ASX_PreferredStockDividendsOtherAdjustmentsAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class PreferredStockDividendsOtherAdjustmentsAccount;
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

class PreferredStockDividendsOtherAdjustmentsAccount : public FlowAccount  {

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
	PreferredStockDividendsOtherAdjustmentsAccount();
	PreferredStockDividendsOtherAdjustmentsAccount(const PreferredStockDividendsOtherAdjustmentsAccount* ptr);
	PreferredStockDividendsOtherAdjustmentsAccount(const PreferredStockDividendsOtherAdjustmentsAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_PreferredStockDividendsOtherAdjustmentsAccount();

	//Destructor
	virtual ~PreferredStockDividendsOtherAdjustmentsAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_PreferredStockDividendsOtherAdjustmentsAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_PreferredStockDividendsOtherAdjustmentsAccount(string fname);
	virtual void fscan(string fname);
	void fscan_PreferredStockDividendsOtherAdjustmentsAccount(string fname);

	//Reset
	virtual void reset();
	void reset_PreferredStockDividendsOtherAdjustmentsAccount();


	/** ------ Static Functions ----------------*/

	static PreferredStockDividendsOtherAdjustmentsAccount* instance();

	static PreferredStockDividendsOtherAdjustmentsAccount* instance_fscan(string fname);

   static PreferredStockDividendsOtherAdjustmentsAccount* __ptr_PreferredStockDividendsOtherAdjustmentsAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

