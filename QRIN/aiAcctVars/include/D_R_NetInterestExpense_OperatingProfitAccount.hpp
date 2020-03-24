// Name:     D_R_NetInterestExpense_OperatingProfitAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_R_NetInterestExpense_OperatingProfitAccount_hpp
#define ASX_D_R_NetInterestExpense_OperatingProfitAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class D_R_NetInterestExpense_OperatingProfitAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "D_DoubleDbAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctVars;
using namespace aiDb;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiAcctVars {

class D_R_NetInterestExpense_OperatingProfitAccount : public D_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: D.R_NetInterestExpense_OperatingProfitAccount
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
	D_R_NetInterestExpense_OperatingProfitAccount();
	D_R_NetInterestExpense_OperatingProfitAccount(const D_R_NetInterestExpense_OperatingProfitAccount* ptr);
	D_R_NetInterestExpense_OperatingProfitAccount(const D_R_NetInterestExpense_OperatingProfitAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_D_R_NetInterestExpense_OperatingProfitAccount();

	//Destructor
	virtual ~D_R_NetInterestExpense_OperatingProfitAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_D_R_NetInterestExpense_OperatingProfitAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_D_R_NetInterestExpense_OperatingProfitAccount(string fname);
	virtual void fscan(string fname);
	void fscan_D_R_NetInterestExpense_OperatingProfitAccount(string fname);

	//Reset
	virtual void reset();
	void reset_D_R_NetInterestExpense_OperatingProfitAccount();


	/** ------ Static Functions ----------------*/

	static D_R_NetInterestExpense_OperatingProfitAccount* instance();

	static D_R_NetInterestExpense_OperatingProfitAccount* instance_fscan(string fname);

   static D_R_NetInterestExpense_OperatingProfitAccount* __ptr_D_R_NetInterestExpense_OperatingProfitAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

