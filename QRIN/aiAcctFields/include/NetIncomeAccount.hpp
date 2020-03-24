// Name:     NetIncomeAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_NetIncomeAccount_hpp
#define ASX_NetIncomeAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class NetIncomeAccount;
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

class NetIncomeAccount : public FlowAccount  {

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
	NetIncomeAccount();
	NetIncomeAccount(const NetIncomeAccount* ptr);
	NetIncomeAccount(const NetIncomeAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_NetIncomeAccount();

	//Destructor
	virtual ~NetIncomeAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_NetIncomeAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_NetIncomeAccount(string fname);
	virtual void fscan(string fname);
	void fscan_NetIncomeAccount(string fname);

	//Reset
	virtual void reset();
	void reset_NetIncomeAccount();


	/** ------ Static Functions ----------------*/

	static NetIncomeAccount* instance();

	static NetIncomeAccount* instance_fscan(string fname);

   static NetIncomeAccount* __ptr_NetIncomeAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

