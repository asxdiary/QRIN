// Name:     MinorityInterestParticipationNetTaxEffectAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_MinorityInterestParticipationNetTaxEffectAccount_hpp
#define ASX_MinorityInterestParticipationNetTaxEffectAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class MinorityInterestParticipationNetTaxEffectAccount;
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

class MinorityInterestParticipationNetTaxEffectAccount : public FlowAccount  {

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
	MinorityInterestParticipationNetTaxEffectAccount();
	MinorityInterestParticipationNetTaxEffectAccount(const MinorityInterestParticipationNetTaxEffectAccount* ptr);
	MinorityInterestParticipationNetTaxEffectAccount(const MinorityInterestParticipationNetTaxEffectAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_MinorityInterestParticipationNetTaxEffectAccount();

	//Destructor
	virtual ~MinorityInterestParticipationNetTaxEffectAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_MinorityInterestParticipationNetTaxEffectAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_MinorityInterestParticipationNetTaxEffectAccount(string fname);
	virtual void fscan(string fname);
	void fscan_MinorityInterestParticipationNetTaxEffectAccount(string fname);

	//Reset
	virtual void reset();
	void reset_MinorityInterestParticipationNetTaxEffectAccount();


	/** ------ Static Functions ----------------*/

	static MinorityInterestParticipationNetTaxEffectAccount* instance();

	static MinorityInterestParticipationNetTaxEffectAccount* instance_fscan(string fname);

   static MinorityInterestParticipationNetTaxEffectAccount* __ptr_MinorityInterestParticipationNetTaxEffectAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

