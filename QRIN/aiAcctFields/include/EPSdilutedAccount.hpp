// Name:     EPSdilutedAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_EPSdilutedAccount_hpp
#define ASX_EPSdilutedAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class EPSdilutedAccount;
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

class EPSdilutedAccount : public FlowAccount  {

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
	EPSdilutedAccount();
	EPSdilutedAccount(const EPSdilutedAccount* ptr);
	EPSdilutedAccount(const EPSdilutedAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_EPSdilutedAccount();

	//Destructor
	virtual ~EPSdilutedAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_EPSdilutedAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_EPSdilutedAccount(string fname);
	virtual void fscan(string fname);
	void fscan_EPSdilutedAccount(string fname);

	//Reset
	virtual void reset();
	void reset_EPSdilutedAccount();


	/** ------ Static Functions ----------------*/

	static EPSdilutedAccount* instance();

	static EPSdilutedAccount* instance_fscan(string fname);

   static EPSdilutedAccount* __ptr_EPSdilutedAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

