// Name:     DividendsPerShareAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DividendsPerShareAccount_hpp
#define ASX_DividendsPerShareAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class DividendsPerShareAccount;
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

class DividendsPerShareAccount : public FlowAccount  {

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
	DividendsPerShareAccount();
	DividendsPerShareAccount(const DividendsPerShareAccount* ptr);
	DividendsPerShareAccount(const DividendsPerShareAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_DividendsPerShareAccount();

	//Destructor
	virtual ~DividendsPerShareAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_DividendsPerShareAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_DividendsPerShareAccount(string fname);
	virtual void fscan(string fname);
	void fscan_DividendsPerShareAccount(string fname);

	//Reset
	virtual void reset();
	void reset_DividendsPerShareAccount();


	/** ------ Static Functions ----------------*/

	static DividendsPerShareAccount* instance();

	static DividendsPerShareAccount* instance_fscan(string fname);

   static DividendsPerShareAccount* __ptr_DividendsPerShareAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

