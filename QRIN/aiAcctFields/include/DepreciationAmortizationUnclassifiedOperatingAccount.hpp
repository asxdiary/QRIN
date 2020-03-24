// Name:     DepreciationAmortizationUnclassifiedOperatingAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DepreciationAmortizationUnclassifiedOperatingAccount_hpp
#define ASX_DepreciationAmortizationUnclassifiedOperatingAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class DepreciationAmortizationUnclassifiedOperatingAccount;
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

class DepreciationAmortizationUnclassifiedOperatingAccount : public FlowAccount  {

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
	DepreciationAmortizationUnclassifiedOperatingAccount();
	DepreciationAmortizationUnclassifiedOperatingAccount(const DepreciationAmortizationUnclassifiedOperatingAccount* ptr);
	DepreciationAmortizationUnclassifiedOperatingAccount(const DepreciationAmortizationUnclassifiedOperatingAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_DepreciationAmortizationUnclassifiedOperatingAccount();

	//Destructor
	virtual ~DepreciationAmortizationUnclassifiedOperatingAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_DepreciationAmortizationUnclassifiedOperatingAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_DepreciationAmortizationUnclassifiedOperatingAccount(string fname);
	virtual void fscan(string fname);
	void fscan_DepreciationAmortizationUnclassifiedOperatingAccount(string fname);

	//Reset
	virtual void reset();
	void reset_DepreciationAmortizationUnclassifiedOperatingAccount();


	/** ------ Static Functions ----------------*/

	static DepreciationAmortizationUnclassifiedOperatingAccount* instance();

	static DepreciationAmortizationUnclassifiedOperatingAccount* instance_fscan(string fname);

   static DepreciationAmortizationUnclassifiedOperatingAccount* __ptr_DepreciationAmortizationUnclassifiedOperatingAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

