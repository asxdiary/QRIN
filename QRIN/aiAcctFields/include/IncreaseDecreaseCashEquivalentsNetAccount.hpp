// Name:     IncreaseDecreaseCashEquivalentsNetAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_IncreaseDecreaseCashEquivalentsNetAccount_hpp
#define ASX_IncreaseDecreaseCashEquivalentsNetAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class IncreaseDecreaseCashEquivalentsNetAccount;
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

class IncreaseDecreaseCashEquivalentsNetAccount : public FlowAccount  {

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
	IncreaseDecreaseCashEquivalentsNetAccount();
	IncreaseDecreaseCashEquivalentsNetAccount(const IncreaseDecreaseCashEquivalentsNetAccount* ptr);
	IncreaseDecreaseCashEquivalentsNetAccount(const IncreaseDecreaseCashEquivalentsNetAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_IncreaseDecreaseCashEquivalentsNetAccount();

	//Destructor
	virtual ~IncreaseDecreaseCashEquivalentsNetAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_IncreaseDecreaseCashEquivalentsNetAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_IncreaseDecreaseCashEquivalentsNetAccount(string fname);
	virtual void fscan(string fname);
	void fscan_IncreaseDecreaseCashEquivalentsNetAccount(string fname);

	//Reset
	virtual void reset();
	void reset_IncreaseDecreaseCashEquivalentsNetAccount();


	/** ------ Static Functions ----------------*/

	static IncreaseDecreaseCashEquivalentsNetAccount* instance();

	static IncreaseDecreaseCashEquivalentsNetAccount* instance_fscan(string fname);

   static IncreaseDecreaseCashEquivalentsNetAccount* __ptr_IncreaseDecreaseCashEquivalentsNetAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

