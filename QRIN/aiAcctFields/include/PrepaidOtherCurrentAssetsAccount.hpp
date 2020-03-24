// Name:     PrepaidOtherCurrentAssetsAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_PrepaidOtherCurrentAssetsAccount_hpp
#define ASX_PrepaidOtherCurrentAssetsAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class PrepaidOtherCurrentAssetsAccount;
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

class PrepaidOtherCurrentAssetsAccount : public PositionAccount  {

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
	PrepaidOtherCurrentAssetsAccount();
	PrepaidOtherCurrentAssetsAccount(const PrepaidOtherCurrentAssetsAccount* ptr);
	PrepaidOtherCurrentAssetsAccount(const PrepaidOtherCurrentAssetsAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_PrepaidOtherCurrentAssetsAccount();

	//Destructor
	virtual ~PrepaidOtherCurrentAssetsAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_PrepaidOtherCurrentAssetsAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_PrepaidOtherCurrentAssetsAccount(string fname);
	virtual void fscan(string fname);
	void fscan_PrepaidOtherCurrentAssetsAccount(string fname);

	//Reset
	virtual void reset();
	void reset_PrepaidOtherCurrentAssetsAccount();


	/** ------ Static Functions ----------------*/

	static PrepaidOtherCurrentAssetsAccount* instance();

	static PrepaidOtherCurrentAssetsAccount* instance_fscan(string fname);

   static PrepaidOtherCurrentAssetsAccount* __ptr_PrepaidOtherCurrentAssetsAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

