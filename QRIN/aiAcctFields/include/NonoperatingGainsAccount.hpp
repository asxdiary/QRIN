// Name:     NonoperatingGainsAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_NonoperatingGainsAccount_hpp
#define ASX_NonoperatingGainsAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class NonoperatingGainsAccount;
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

class NonoperatingGainsAccount : public FlowAccount  {

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
	NonoperatingGainsAccount();
	NonoperatingGainsAccount(const NonoperatingGainsAccount* ptr);
	NonoperatingGainsAccount(const NonoperatingGainsAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_NonoperatingGainsAccount();

	//Destructor
	virtual ~NonoperatingGainsAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_NonoperatingGainsAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_NonoperatingGainsAccount(string fname);
	virtual void fscan(string fname);
	void fscan_NonoperatingGainsAccount(string fname);

	//Reset
	virtual void reset();
	void reset_NonoperatingGainsAccount();


	/** ------ Static Functions ----------------*/

	static NonoperatingGainsAccount* instance();

	static NonoperatingGainsAccount* instance_fscan(string fname);

   static NonoperatingGainsAccount* __ptr_NonoperatingGainsAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

