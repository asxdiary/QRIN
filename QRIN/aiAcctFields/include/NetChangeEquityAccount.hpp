// Name:     NetChangeEquityAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_NetChangeEquityAccount_hpp
#define ASX_NetChangeEquityAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class NetChangeEquityAccount;
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

class NetChangeEquityAccount : public FlowAccount  {

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
	NetChangeEquityAccount();
	NetChangeEquityAccount(const NetChangeEquityAccount* ptr);
	NetChangeEquityAccount(const NetChangeEquityAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_NetChangeEquityAccount();

	//Destructor
	virtual ~NetChangeEquityAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_NetChangeEquityAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_NetChangeEquityAccount(string fname);
	virtual void fscan(string fname);
	void fscan_NetChangeEquityAccount(string fname);

	//Reset
	virtual void reset();
	void reset_NetChangeEquityAccount();


	/** ------ Static Functions ----------------*/

	static NetChangeEquityAccount* instance();

	static NetChangeEquityAccount* instance_fscan(string fname);

   static NetChangeEquityAccount* __ptr_NetChangeEquityAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

