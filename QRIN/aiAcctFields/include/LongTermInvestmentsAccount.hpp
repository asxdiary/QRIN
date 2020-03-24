// Name:     LongTermInvestmentsAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_LongTermInvestmentsAccount_hpp
#define ASX_LongTermInvestmentsAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class LongTermInvestmentsAccount;
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

class LongTermInvestmentsAccount : public PositionAccount  {

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
	LongTermInvestmentsAccount();
	LongTermInvestmentsAccount(const LongTermInvestmentsAccount* ptr);
	LongTermInvestmentsAccount(const LongTermInvestmentsAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_LongTermInvestmentsAccount();

	//Destructor
	virtual ~LongTermInvestmentsAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_LongTermInvestmentsAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_LongTermInvestmentsAccount(string fname);
	virtual void fscan(string fname);
	void fscan_LongTermInvestmentsAccount(string fname);

	//Reset
	virtual void reset();
	void reset_LongTermInvestmentsAccount();


	/** ------ Static Functions ----------------*/

	static LongTermInvestmentsAccount* instance();

	static LongTermInvestmentsAccount* instance_fscan(string fname);

   static LongTermInvestmentsAccount* __ptr_LongTermInvestmentsAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

