// Name:     CurrentAssetsAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CurrentAssetsAccount_hpp
#define ASX_CurrentAssetsAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class CurrentAssetsAccount;
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

class CurrentAssetsAccount : public PositionAccount  {

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
	CurrentAssetsAccount();
	CurrentAssetsAccount(const CurrentAssetsAccount* ptr);
	CurrentAssetsAccount(const CurrentAssetsAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_CurrentAssetsAccount();

	//Destructor
	virtual ~CurrentAssetsAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_CurrentAssetsAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_CurrentAssetsAccount(string fname);
	virtual void fscan(string fname);
	void fscan_CurrentAssetsAccount(string fname);

	//Reset
	virtual void reset();
	void reset_CurrentAssetsAccount();


	/** ------ Static Functions ----------------*/

	static CurrentAssetsAccount* instance();

	static CurrentAssetsAccount* instance_fscan(string fname);

   static CurrentAssetsAccount* __ptr_CurrentAssetsAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

