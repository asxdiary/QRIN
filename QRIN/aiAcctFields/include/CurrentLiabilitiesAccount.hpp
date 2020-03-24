// Name:     CurrentLiabilitiesAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CurrentLiabilitiesAccount_hpp
#define ASX_CurrentLiabilitiesAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class CurrentLiabilitiesAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctFields;
using namespace aiDbAccounts;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiAcctFields {

class CurrentLiabilitiesAccount : public PositionAccount  {

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
	CurrentLiabilitiesAccount();
	CurrentLiabilitiesAccount(const CurrentLiabilitiesAccount* ptr);
	CurrentLiabilitiesAccount(const CurrentLiabilitiesAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_CurrentLiabilitiesAccount();

	//Destructor
	virtual ~CurrentLiabilitiesAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_CurrentLiabilitiesAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_CurrentLiabilitiesAccount(string fname);
	virtual void fscan(string fname);
	void fscan_CurrentLiabilitiesAccount(string fname);

	//Reset
	virtual void reset();
	void reset_CurrentLiabilitiesAccount();


	/** ------ Static Functions ----------------*/

	static CurrentLiabilitiesAccount* instance();

	static CurrentLiabilitiesAccount* instance_fscan(string fname);

   static CurrentLiabilitiesAccount* __ptr_CurrentLiabilitiesAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

