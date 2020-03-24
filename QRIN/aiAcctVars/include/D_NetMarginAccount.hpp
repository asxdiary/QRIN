// Name:     D_NetMarginAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_NetMarginAccount_hpp
#define ASX_D_NetMarginAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class D_NetMarginAccount;
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

class D_NetMarginAccount : public D_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: D.R_NetMarginAccount
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
	D_NetMarginAccount();
	D_NetMarginAccount(const D_NetMarginAccount* ptr);
	D_NetMarginAccount(const D_NetMarginAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_D_NetMarginAccount();

	//Destructor
	virtual ~D_NetMarginAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_D_NetMarginAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_D_NetMarginAccount(string fname);
	virtual void fscan(string fname);
	void fscan_D_NetMarginAccount(string fname);

	//Reset
	virtual void reset();
	void reset_D_NetMarginAccount();


	/** ------ Static Functions ----------------*/

	static D_NetMarginAccount* instance();

	static D_NetMarginAccount* instance_fscan(string fname);

   static D_NetMarginAccount* __ptr_D_NetMarginAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

