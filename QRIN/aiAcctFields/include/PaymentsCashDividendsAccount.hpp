// Name:     PaymentsCashDividendsAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_PaymentsCashDividendsAccount_hpp
#define ASX_PaymentsCashDividendsAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class PaymentsCashDividendsAccount;
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

class PaymentsCashDividendsAccount : public FlowAccount  {

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
	PaymentsCashDividendsAccount();
	PaymentsCashDividendsAccount(const PaymentsCashDividendsAccount* ptr);
	PaymentsCashDividendsAccount(const PaymentsCashDividendsAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_PaymentsCashDividendsAccount();

	//Destructor
	virtual ~PaymentsCashDividendsAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_PaymentsCashDividendsAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_PaymentsCashDividendsAccount(string fname);
	virtual void fscan(string fname);
	void fscan_PaymentsCashDividendsAccount(string fname);

	//Reset
	virtual void reset();
	void reset_PaymentsCashDividendsAccount();


	/** ------ Static Functions ----------------*/

	static PaymentsCashDividendsAccount* instance();

	static PaymentsCashDividendsAccount* instance_fscan(string fname);

   static PaymentsCashDividendsAccount* __ptr_PaymentsCashDividendsAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

