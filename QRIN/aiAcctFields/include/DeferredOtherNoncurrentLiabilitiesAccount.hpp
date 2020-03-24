// Name:     DeferredOtherNoncurrentLiabilitiesAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DeferredOtherNoncurrentLiabilitiesAccount_hpp
#define ASX_DeferredOtherNoncurrentLiabilitiesAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class DeferredOtherNoncurrentLiabilitiesAccount;
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

class DeferredOtherNoncurrentLiabilitiesAccount : public PositionAccount  {

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
	DeferredOtherNoncurrentLiabilitiesAccount();
	DeferredOtherNoncurrentLiabilitiesAccount(const DeferredOtherNoncurrentLiabilitiesAccount* ptr);
	DeferredOtherNoncurrentLiabilitiesAccount(const DeferredOtherNoncurrentLiabilitiesAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_DeferredOtherNoncurrentLiabilitiesAccount();

	//Destructor
	virtual ~DeferredOtherNoncurrentLiabilitiesAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_DeferredOtherNoncurrentLiabilitiesAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_DeferredOtherNoncurrentLiabilitiesAccount(string fname);
	virtual void fscan(string fname);
	void fscan_DeferredOtherNoncurrentLiabilitiesAccount(string fname);

	//Reset
	virtual void reset();
	void reset_DeferredOtherNoncurrentLiabilitiesAccount();


	/** ------ Static Functions ----------------*/

	static DeferredOtherNoncurrentLiabilitiesAccount* instance();

	static DeferredOtherNoncurrentLiabilitiesAccount* instance_fscan(string fname);

   static DeferredOtherNoncurrentLiabilitiesAccount* __ptr_DeferredOtherNoncurrentLiabilitiesAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

