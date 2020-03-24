// Name:     D_OperatingMarginAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_OperatingMarginAccount_hpp
#define ASX_D_OperatingMarginAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class D_OperatingMarginAccount;
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

class D_OperatingMarginAccount : public D_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: D.R_OperatingMarginAccount
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
	D_OperatingMarginAccount();
	D_OperatingMarginAccount(const D_OperatingMarginAccount* ptr);
	D_OperatingMarginAccount(const D_OperatingMarginAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_D_OperatingMarginAccount();

	//Destructor
	virtual ~D_OperatingMarginAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_D_OperatingMarginAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_D_OperatingMarginAccount(string fname);
	virtual void fscan(string fname);
	void fscan_D_OperatingMarginAccount(string fname);

	//Reset
	virtual void reset();
	void reset_D_OperatingMarginAccount();


	/** ------ Static Functions ----------------*/

	static D_OperatingMarginAccount* instance();

	static D_OperatingMarginAccount* instance_fscan(string fname);

   static D_OperatingMarginAccount* __ptr_D_OperatingMarginAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

