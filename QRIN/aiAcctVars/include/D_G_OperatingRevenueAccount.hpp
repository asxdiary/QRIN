// Name:     D_G_OperatingRevenueAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_G_OperatingRevenueAccount_hpp
#define ASX_D_G_OperatingRevenueAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class D_G_OperatingRevenueAccount;
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

class D_G_OperatingRevenueAccount : public D_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: D.G_OperatingRevenueAccount
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
	D_G_OperatingRevenueAccount();
	D_G_OperatingRevenueAccount(const D_G_OperatingRevenueAccount* ptr);
	D_G_OperatingRevenueAccount(const D_G_OperatingRevenueAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_D_G_OperatingRevenueAccount();

	//Destructor
	virtual ~D_G_OperatingRevenueAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_D_G_OperatingRevenueAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_D_G_OperatingRevenueAccount(string fname);
	virtual void fscan(string fname);
	void fscan_D_G_OperatingRevenueAccount(string fname);

	//Reset
	virtual void reset();
	void reset_D_G_OperatingRevenueAccount();


	/** ------ Static Functions ----------------*/

	static D_G_OperatingRevenueAccount* instance();

	static D_G_OperatingRevenueAccount* instance_fscan(string fname);

   static D_G_OperatingRevenueAccount* __ptr_D_G_OperatingRevenueAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

