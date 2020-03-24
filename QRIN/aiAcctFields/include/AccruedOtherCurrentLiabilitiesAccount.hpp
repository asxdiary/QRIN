// Name:     AccruedOtherCurrentLiabilitiesAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_AccruedOtherCurrentLiabilitiesAccount_hpp
#define ASX_AccruedOtherCurrentLiabilitiesAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class AccruedOtherCurrentLiabilitiesAccount;
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

class AccruedOtherCurrentLiabilitiesAccount : public PositionAccount  {

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
	AccruedOtherCurrentLiabilitiesAccount();
	AccruedOtherCurrentLiabilitiesAccount(const AccruedOtherCurrentLiabilitiesAccount* ptr);
	AccruedOtherCurrentLiabilitiesAccount(const AccruedOtherCurrentLiabilitiesAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_AccruedOtherCurrentLiabilitiesAccount();

	//Destructor
	virtual ~AccruedOtherCurrentLiabilitiesAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_AccruedOtherCurrentLiabilitiesAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_AccruedOtherCurrentLiabilitiesAccount(string fname);
	virtual void fscan(string fname);
	void fscan_AccruedOtherCurrentLiabilitiesAccount(string fname);

	//Reset
	virtual void reset();
	void reset_AccruedOtherCurrentLiabilitiesAccount();


	/** ------ Static Functions ----------------*/

	static AccruedOtherCurrentLiabilitiesAccount* instance();

	static AccruedOtherCurrentLiabilitiesAccount* instance_fscan(string fname);

   static AccruedOtherCurrentLiabilitiesAccount* __ptr_AccruedOtherCurrentLiabilitiesAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

