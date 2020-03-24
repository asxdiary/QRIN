// Name:     EffectExchangeRateCashCashEquivalentsAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_EffectExchangeRateCashCashEquivalentsAccount_hpp
#define ASX_EffectExchangeRateCashCashEquivalentsAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class EffectExchangeRateCashCashEquivalentsAccount;
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

class EffectExchangeRateCashCashEquivalentsAccount : public FlowAccount  {

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
	EffectExchangeRateCashCashEquivalentsAccount();
	EffectExchangeRateCashCashEquivalentsAccount(const EffectExchangeRateCashCashEquivalentsAccount* ptr);
	EffectExchangeRateCashCashEquivalentsAccount(const EffectExchangeRateCashCashEquivalentsAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_EffectExchangeRateCashCashEquivalentsAccount();

	//Destructor
	virtual ~EffectExchangeRateCashCashEquivalentsAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_EffectExchangeRateCashCashEquivalentsAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_EffectExchangeRateCashCashEquivalentsAccount(string fname);
	virtual void fscan(string fname);
	void fscan_EffectExchangeRateCashCashEquivalentsAccount(string fname);

	//Reset
	virtual void reset();
	void reset_EffectExchangeRateCashCashEquivalentsAccount();


	/** ------ Static Functions ----------------*/

	static EffectExchangeRateCashCashEquivalentsAccount* instance();

	static EffectExchangeRateCashCashEquivalentsAccount* instance_fscan(string fname);

   static EffectExchangeRateCashCashEquivalentsAccount* __ptr_EffectExchangeRateCashCashEquivalentsAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

