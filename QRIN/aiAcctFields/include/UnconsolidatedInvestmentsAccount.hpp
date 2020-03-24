// Name:     UnconsolidatedInvestmentsAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_UnconsolidatedInvestmentsAccount_hpp
#define ASX_UnconsolidatedInvestmentsAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class UnconsolidatedInvestmentsAccount;
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

class UnconsolidatedInvestmentsAccount : public PositionAccount  {

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
	UnconsolidatedInvestmentsAccount();
	UnconsolidatedInvestmentsAccount(const UnconsolidatedInvestmentsAccount* ptr);
	UnconsolidatedInvestmentsAccount(const UnconsolidatedInvestmentsAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_UnconsolidatedInvestmentsAccount();

	//Destructor
	virtual ~UnconsolidatedInvestmentsAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_UnconsolidatedInvestmentsAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_UnconsolidatedInvestmentsAccount(string fname);
	virtual void fscan(string fname);
	void fscan_UnconsolidatedInvestmentsAccount(string fname);

	//Reset
	virtual void reset();
	void reset_UnconsolidatedInvestmentsAccount();


	/** ------ Static Functions ----------------*/

	static UnconsolidatedInvestmentsAccount* instance();

	static UnconsolidatedInvestmentsAccount* instance_fscan(string fname);

   static UnconsolidatedInvestmentsAccount* __ptr_UnconsolidatedInvestmentsAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

