// Name:     PreferredEquityAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_PreferredEquityAccount_hpp
#define ASX_PreferredEquityAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class PreferredEquityAccount;
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

class PreferredEquityAccount : public PositionAccount  {

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
	PreferredEquityAccount();
	PreferredEquityAccount(const PreferredEquityAccount* ptr);
	PreferredEquityAccount(const PreferredEquityAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_PreferredEquityAccount();

	//Destructor
	virtual ~PreferredEquityAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_PreferredEquityAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_PreferredEquityAccount(string fname);
	virtual void fscan(string fname);
	void fscan_PreferredEquityAccount(string fname);

	//Reset
	virtual void reset();
	void reset_PreferredEquityAccount();


	/** ------ Static Functions ----------------*/

	static PreferredEquityAccount* instance();

	static PreferredEquityAccount* instance_fscan(string fname);

   static PreferredEquityAccount* __ptr_PreferredEquityAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

