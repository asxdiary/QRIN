// Name:     TotalAssetsAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_TotalAssetsAccount_hpp
#define ASX_TotalAssetsAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class TotalAssetsAccount;
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

class TotalAssetsAccount : public PositionAccount  {

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
	TotalAssetsAccount();
	TotalAssetsAccount(const TotalAssetsAccount* ptr);
	TotalAssetsAccount(const TotalAssetsAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_TotalAssetsAccount();

	//Destructor
	virtual ~TotalAssetsAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_TotalAssetsAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_TotalAssetsAccount(string fname);
	virtual void fscan(string fname);
	void fscan_TotalAssetsAccount(string fname);

	//Reset
	virtual void reset();
	void reset_TotalAssetsAccount();


	/** ------ Static Functions ----------------*/

	static TotalAssetsAccount* instance();

	static TotalAssetsAccount* instance_fscan(string fname);

   static TotalAssetsAccount* __ptr_TotalAssetsAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

