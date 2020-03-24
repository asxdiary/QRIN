// Name:     BenefitPlansFundingAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_BenefitPlansFundingAccount_hpp
#define ASX_BenefitPlansFundingAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class BenefitPlansFundingAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctFields;
using namespace aiDbAccounts;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiAcctFields {

class BenefitPlansFundingAccount : public PositionAccount  {

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
	BenefitPlansFundingAccount();
	BenefitPlansFundingAccount(const BenefitPlansFundingAccount* ptr);
	BenefitPlansFundingAccount(const BenefitPlansFundingAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_BenefitPlansFundingAccount();

	//Destructor
	virtual ~BenefitPlansFundingAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_BenefitPlansFundingAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_BenefitPlansFundingAccount(string fname);
	virtual void fscan(string fname);
	void fscan_BenefitPlansFundingAccount(string fname);

	//Reset
	virtual void reset();
	void reset_BenefitPlansFundingAccount();


	/** ------ Static Functions ----------------*/

	static BenefitPlansFundingAccount* instance();

	static BenefitPlansFundingAccount* instance_fscan(string fname);

   static BenefitPlansFundingAccount* __ptr_BenefitPlansFundingAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

