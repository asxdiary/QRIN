// Name:     G_OperatingRevenueAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_G_OperatingRevenueAccount_hpp
#define ASX_G_OperatingRevenueAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class G_OperatingRevenueAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "G_DoubleDbAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctVars;
using namespace aiDb;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiAcctVars {

class G_OperatingRevenueAccount : public G_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: OperatingRevenue1/OperatingRevenue0 - 1
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
	G_OperatingRevenueAccount();
	G_OperatingRevenueAccount(const G_OperatingRevenueAccount* ptr);
	G_OperatingRevenueAccount(const G_OperatingRevenueAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(bool geom_flag);
	void init_G_OperatingRevenueAccount();

	//Destructor
	virtual ~G_OperatingRevenueAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_G_OperatingRevenueAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_G_OperatingRevenueAccount(string fname);
	virtual void fscan(string fname);
	void fscan_G_OperatingRevenueAccount(string fname);

	//Reset
	virtual void reset();
	void reset_G_OperatingRevenueAccount();


	/** ------ Static Functions ----------------*/

	static G_OperatingRevenueAccount* instance(bool geom_flag=true);

	static G_OperatingRevenueAccount* instance_fscan(string fname);

   static G_OperatingRevenueAccount* __ptr_G_OperatingRevenueAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

