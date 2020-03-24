// Name:     R_Liabilities_AssetsAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_R_Liabilities_AssetsAccount_hpp
#define ASX_R_Liabilities_AssetsAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class R_Liabilities_AssetsAccount;
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

class R_Liabilities_AssetsAccount : public R_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: TotalLiabilitiesAccount/TotalAssetsAccount
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
	R_Liabilities_AssetsAccount();
	R_Liabilities_AssetsAccount(const R_Liabilities_AssetsAccount* ptr);
	R_Liabilities_AssetsAccount(const R_Liabilities_AssetsAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_R_Liabilities_AssetsAccount();

	//Destructor
	virtual ~R_Liabilities_AssetsAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_R_Liabilities_AssetsAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_R_Liabilities_AssetsAccount(string fname);
	virtual void fscan(string fname);
	void fscan_R_Liabilities_AssetsAccount(string fname);

	//Reset
	virtual void reset();
	void reset_R_Liabilities_AssetsAccount();


	/** ------ Static Functions ----------------*/

	static R_Liabilities_AssetsAccount* instance();

	static R_Liabilities_AssetsAccount* instance_fscan(string fname);

   static R_Liabilities_AssetsAccount* __ptr_R_Liabilities_AssetsAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

