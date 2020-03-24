// Name:     CashTaxesPaidAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CashTaxesPaidAccount_hpp
#define ASX_CashTaxesPaidAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class CashTaxesPaidAccount;
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

class CashTaxesPaidAccount : public FlowAccount  {

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
	CashTaxesPaidAccount();
	CashTaxesPaidAccount(const CashTaxesPaidAccount* ptr);
	CashTaxesPaidAccount(const CashTaxesPaidAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_CashTaxesPaidAccount();

	//Destructor
	virtual ~CashTaxesPaidAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_CashTaxesPaidAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_CashTaxesPaidAccount(string fname);
	virtual void fscan(string fname);
	void fscan_CashTaxesPaidAccount(string fname);

	//Reset
	virtual void reset();
	void reset_CashTaxesPaidAccount();


	/** ------ Static Functions ----------------*/

	static CashTaxesPaidAccount* instance();

	static CashTaxesPaidAccount* instance_fscan(string fname);

   static CashTaxesPaidAccount* __ptr_CashTaxesPaidAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

