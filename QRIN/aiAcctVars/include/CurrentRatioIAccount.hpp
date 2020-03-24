// Name:     CurrentRatioIAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CurrentRatioIAccount_hpp
#define ASX_CurrentRatioIAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class CurrentRatioIAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "R_DoubleDbAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctVars;
using namespace aiDb;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiAcctVars {

class CurrentRatioIAccount : public R_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: CurrentLiabilitiesAccount/CurrentAssetsAccount
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
	CurrentRatioIAccount();
	CurrentRatioIAccount(const CurrentRatioIAccount* ptr);
	CurrentRatioIAccount(const CurrentRatioIAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_CurrentRatioIAccount();

	//Destructor
	virtual ~CurrentRatioIAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_CurrentRatioIAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_CurrentRatioIAccount(string fname);
	virtual void fscan(string fname);
	void fscan_CurrentRatioIAccount(string fname);

	//Reset
	virtual void reset();
	void reset_CurrentRatioIAccount();


	/** ------ Static Functions ----------------*/

	static CurrentRatioIAccount* instance();

	static CurrentRatioIAccount* instance_fscan(string fname);

   static CurrentRatioIAccount* __ptr_CurrentRatioIAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

