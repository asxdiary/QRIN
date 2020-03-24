// Name:     NetChangeDebtAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_NetChangeDebtAccount_hpp
#define ASX_NetChangeDebtAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class NetChangeDebtAccount;
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

class NetChangeDebtAccount : public FlowAccount  {

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
	NetChangeDebtAccount();
	NetChangeDebtAccount(const NetChangeDebtAccount* ptr);
	NetChangeDebtAccount(const NetChangeDebtAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_NetChangeDebtAccount();

	//Destructor
	virtual ~NetChangeDebtAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_NetChangeDebtAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_NetChangeDebtAccount(string fname);
	virtual void fscan(string fname);
	void fscan_NetChangeDebtAccount(string fname);

	//Reset
	virtual void reset();
	void reset_NetChangeDebtAccount();


	/** ------ Static Functions ----------------*/

	static NetChangeDebtAccount* instance();

	static NetChangeDebtAccount* instance_fscan(string fname);

   static NetChangeDebtAccount* __ptr_NetChangeDebtAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

