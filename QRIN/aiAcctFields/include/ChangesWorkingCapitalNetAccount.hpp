// Name:     ChangesWorkingCapitalNetAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ChangesWorkingCapitalNetAccount_hpp
#define ASX_ChangesWorkingCapitalNetAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class ChangesWorkingCapitalNetAccount;
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

class ChangesWorkingCapitalNetAccount : public FlowAccount  {

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
	ChangesWorkingCapitalNetAccount();
	ChangesWorkingCapitalNetAccount(const ChangesWorkingCapitalNetAccount* ptr);
	ChangesWorkingCapitalNetAccount(const ChangesWorkingCapitalNetAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_ChangesWorkingCapitalNetAccount();

	//Destructor
	virtual ~ChangesWorkingCapitalNetAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_ChangesWorkingCapitalNetAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_ChangesWorkingCapitalNetAccount(string fname);
	virtual void fscan(string fname);
	void fscan_ChangesWorkingCapitalNetAccount(string fname);

	//Reset
	virtual void reset();
	void reset_ChangesWorkingCapitalNetAccount();


	/** ------ Static Functions ----------------*/

	static ChangesWorkingCapitalNetAccount* instance();

	static ChangesWorkingCapitalNetAccount* instance_fscan(string fname);

   static ChangesWorkingCapitalNetAccount* __ptr_ChangesWorkingCapitalNetAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

