// Name:     IntangibleAssetsAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_IntangibleAssetsAccount_hpp
#define ASX_IntangibleAssetsAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class IntangibleAssetsAccount;
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

class IntangibleAssetsAccount : public PositionAccount  {

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
	IntangibleAssetsAccount();
	IntangibleAssetsAccount(const IntangibleAssetsAccount* ptr);
	IntangibleAssetsAccount(const IntangibleAssetsAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_IntangibleAssetsAccount();

	//Destructor
	virtual ~IntangibleAssetsAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_IntangibleAssetsAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_IntangibleAssetsAccount(string fname);
	virtual void fscan(string fname);
	void fscan_IntangibleAssetsAccount(string fname);

	//Reset
	virtual void reset();
	void reset_IntangibleAssetsAccount();


	/** ------ Static Functions ----------------*/

	static IntangibleAssetsAccount* instance();

	static IntangibleAssetsAccount* instance_fscan(string fname);

   static IntangibleAssetsAccount* __ptr_IntangibleAssetsAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

