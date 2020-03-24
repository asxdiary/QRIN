// Name:     SGAOtherOperatingAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_SGAOtherOperatingAccount_hpp
#define ASX_SGAOtherOperatingAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class SGAOtherOperatingAccount;
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

class SGAOtherOperatingAccount : public FlowAccount  {

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
	SGAOtherOperatingAccount();
	SGAOtherOperatingAccount(const SGAOtherOperatingAccount* ptr);
	SGAOtherOperatingAccount(const SGAOtherOperatingAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_SGAOtherOperatingAccount();

	//Destructor
	virtual ~SGAOtherOperatingAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_SGAOtherOperatingAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_SGAOtherOperatingAccount(string fname);
	virtual void fscan(string fname);
	void fscan_SGAOtherOperatingAccount(string fname);

	//Reset
	virtual void reset();
	void reset_SGAOtherOperatingAccount();


	/** ------ Static Functions ----------------*/

	static SGAOtherOperatingAccount* instance();

	static SGAOtherOperatingAccount* instance_fscan(string fname);

   static SGAOtherOperatingAccount* __ptr_SGAOtherOperatingAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

