// Name:     CapitalExpendituresAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CapitalExpendituresAccount_hpp
#define ASX_CapitalExpendituresAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class CapitalExpendituresAccount;
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

class CapitalExpendituresAccount : public FlowAccount  {

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
	CapitalExpendituresAccount();
	CapitalExpendituresAccount(const CapitalExpendituresAccount* ptr);
	CapitalExpendituresAccount(const CapitalExpendituresAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_CapitalExpendituresAccount();

	//Destructor
	virtual ~CapitalExpendituresAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_CapitalExpendituresAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_CapitalExpendituresAccount(string fname);
	virtual void fscan(string fname);
	void fscan_CapitalExpendituresAccount(string fname);

	//Reset
	virtual void reset();
	void reset_CapitalExpendituresAccount();


	/** ------ Static Functions ----------------*/

	static CapitalExpendituresAccount* instance();

	static CapitalExpendituresAccount* instance_fscan(string fname);

   static CapitalExpendituresAccount* __ptr_CapitalExpendituresAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

