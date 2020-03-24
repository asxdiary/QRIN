// Name:     ResearchDevelopmentAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ResearchDevelopmentAccount_hpp
#define ASX_ResearchDevelopmentAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class ResearchDevelopmentAccount;
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

class ResearchDevelopmentAccount : public FlowAccount  {

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
	ResearchDevelopmentAccount();
	ResearchDevelopmentAccount(const ResearchDevelopmentAccount* ptr);
	ResearchDevelopmentAccount(const ResearchDevelopmentAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_ResearchDevelopmentAccount();

	//Destructor
	virtual ~ResearchDevelopmentAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_ResearchDevelopmentAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_ResearchDevelopmentAccount(string fname);
	virtual void fscan(string fname);
	void fscan_ResearchDevelopmentAccount(string fname);

	//Reset
	virtual void reset();
	void reset_ResearchDevelopmentAccount();


	/** ------ Static Functions ----------------*/

	static ResearchDevelopmentAccount* instance();

	static ResearchDevelopmentAccount* instance_fscan(string fname);

   static ResearchDevelopmentAccount* __ptr_ResearchDevelopmentAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

