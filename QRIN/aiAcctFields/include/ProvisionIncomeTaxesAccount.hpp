// Name:     ProvisionIncomeTaxesAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ProvisionIncomeTaxesAccount_hpp
#define ASX_ProvisionIncomeTaxesAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class ProvisionIncomeTaxesAccount;
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

class ProvisionIncomeTaxesAccount : public FlowAccount  {

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
	ProvisionIncomeTaxesAccount();
	ProvisionIncomeTaxesAccount(const ProvisionIncomeTaxesAccount* ptr);
	ProvisionIncomeTaxesAccount(const ProvisionIncomeTaxesAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_ProvisionIncomeTaxesAccount();

	//Destructor
	virtual ~ProvisionIncomeTaxesAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_ProvisionIncomeTaxesAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_ProvisionIncomeTaxesAccount(string fname);
	virtual void fscan(string fname);
	void fscan_ProvisionIncomeTaxesAccount(string fname);

	//Reset
	virtual void reset();
	void reset_ProvisionIncomeTaxesAccount();


	/** ------ Static Functions ----------------*/

	static ProvisionIncomeTaxesAccount* instance();

	static ProvisionIncomeTaxesAccount* instance_fscan(string fname);

   static ProvisionIncomeTaxesAccount* __ptr_ProvisionIncomeTaxesAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

