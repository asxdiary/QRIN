// Name:     MinorityInterestAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_MinorityInterestAccount_hpp
#define ASX_MinorityInterestAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class MinorityInterestAccount;
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

class MinorityInterestAccount : public PositionAccount  {

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
	MinorityInterestAccount();
	MinorityInterestAccount(const MinorityInterestAccount* ptr);
	MinorityInterestAccount(const MinorityInterestAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_MinorityInterestAccount();

	//Destructor
	virtual ~MinorityInterestAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_MinorityInterestAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_MinorityInterestAccount(string fname);
	virtual void fscan(string fname);
	void fscan_MinorityInterestAccount(string fname);

	//Reset
	virtual void reset();
	void reset_MinorityInterestAccount();


	/** ------ Static Functions ----------------*/

	static MinorityInterestAccount* instance();

	static MinorityInterestAccount* instance_fscan(string fname);

   static MinorityInterestAccount* __ptr_MinorityInterestAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

