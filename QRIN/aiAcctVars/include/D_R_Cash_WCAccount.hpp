// Name:     D_R_Cash_WCAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_R_Cash_WCAccount_hpp
#define ASX_D_R_Cash_WCAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class D_R_Cash_WCAccount;
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

class D_R_Cash_WCAccount : public D_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: D.R_Cash_WCAccount
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
	D_R_Cash_WCAccount();
	D_R_Cash_WCAccount(const D_R_Cash_WCAccount* ptr);
	D_R_Cash_WCAccount(const D_R_Cash_WCAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_D_R_Cash_WCAccount();

	//Destructor
	virtual ~D_R_Cash_WCAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_D_R_Cash_WCAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_D_R_Cash_WCAccount(string fname);
	virtual void fscan(string fname);
	void fscan_D_R_Cash_WCAccount(string fname);

	//Reset
	virtual void reset();
	void reset_D_R_Cash_WCAccount();


	/** ------ Static Functions ----------------*/

	static D_R_Cash_WCAccount* instance();

	static D_R_Cash_WCAccount* instance_fscan(string fname);

   static D_R_Cash_WCAccount* __ptr_D_R_Cash_WCAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

