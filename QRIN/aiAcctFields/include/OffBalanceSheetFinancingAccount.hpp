// Name:     OffBalanceSheetFinancingAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_OffBalanceSheetFinancingAccount_hpp
#define ASX_OffBalanceSheetFinancingAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class OffBalanceSheetFinancingAccount;
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

class OffBalanceSheetFinancingAccount : public PositionAccount  {

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
	OffBalanceSheetFinancingAccount();
	OffBalanceSheetFinancingAccount(const OffBalanceSheetFinancingAccount* ptr);
	OffBalanceSheetFinancingAccount(const OffBalanceSheetFinancingAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_OffBalanceSheetFinancingAccount();

	//Destructor
	virtual ~OffBalanceSheetFinancingAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_OffBalanceSheetFinancingAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_OffBalanceSheetFinancingAccount(string fname);
	virtual void fscan(string fname);
	void fscan_OffBalanceSheetFinancingAccount(string fname);

	//Reset
	virtual void reset();
	void reset_OffBalanceSheetFinancingAccount();


	/** ------ Static Functions ----------------*/

	static OffBalanceSheetFinancingAccount* instance();

	static OffBalanceSheetFinancingAccount* instance_fscan(string fname);

   static OffBalanceSheetFinancingAccount* __ptr_OffBalanceSheetFinancingAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

