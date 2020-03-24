// Name:     EPSAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_EPSAccount_hpp
#define ASX_EPSAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class EPSAccount;
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

class EPSAccount : public FlowAccount  {

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
	EPSAccount();
	EPSAccount(const EPSAccount* ptr);
	EPSAccount(const EPSAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_EPSAccount();

	//Destructor
	virtual ~EPSAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_EPSAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_EPSAccount(string fname);
	virtual void fscan(string fname);
	void fscan_EPSAccount(string fname);

	//Reset
	virtual void reset();
	void reset_EPSAccount();


	/** ------ Static Functions ----------------*/

	static EPSAccount* instance();

	static EPSAccount* instance_fscan(string fname);

   static EPSAccount* __ptr_EPSAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

