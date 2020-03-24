// Name:     TotalLiabilitiesAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_TotalLiabilitiesAccount_hpp
#define ASX_TotalLiabilitiesAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class TotalLiabilitiesAccount;
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

class TotalLiabilitiesAccount : public PositionAccount  {

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
	TotalLiabilitiesAccount();
	TotalLiabilitiesAccount(const TotalLiabilitiesAccount* ptr);
	TotalLiabilitiesAccount(const TotalLiabilitiesAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_TotalLiabilitiesAccount();

	//Destructor
	virtual ~TotalLiabilitiesAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_TotalLiabilitiesAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_TotalLiabilitiesAccount(string fname);
	virtual void fscan(string fname);
	void fscan_TotalLiabilitiesAccount(string fname);

	//Reset
	virtual void reset();
	void reset_TotalLiabilitiesAccount();


	/** ------ Static Functions ----------------*/

	static TotalLiabilitiesAccount* instance();

	static TotalLiabilitiesAccount* instance_fscan(string fname);

   static TotalLiabilitiesAccount* __ptr_TotalLiabilitiesAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

