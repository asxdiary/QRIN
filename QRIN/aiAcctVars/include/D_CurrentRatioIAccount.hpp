// Name:     D_CurrentRatioIAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_CurrentRatioIAccount_hpp
#define ASX_D_CurrentRatioIAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class D_CurrentRatioIAccount;
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

class D_CurrentRatioIAccount : public D_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: D.CurrentRatioIAccount
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
	D_CurrentRatioIAccount();
	D_CurrentRatioIAccount(const D_CurrentRatioIAccount* ptr);
	D_CurrentRatioIAccount(const D_CurrentRatioIAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_D_CurrentRatioIAccount();

	//Destructor
	virtual ~D_CurrentRatioIAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_D_CurrentRatioIAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_D_CurrentRatioIAccount(string fname);
	virtual void fscan(string fname);
	void fscan_D_CurrentRatioIAccount(string fname);

	//Reset
	virtual void reset();
	void reset_D_CurrentRatioIAccount();


	/** ------ Static Functions ----------------*/

	static D_CurrentRatioIAccount* instance();

	static D_CurrentRatioIAccount* instance_fscan(string fname);

   static D_CurrentRatioIAccount* __ptr_D_CurrentRatioIAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

