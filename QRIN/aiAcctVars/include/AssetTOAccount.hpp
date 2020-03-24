// Name:     AssetTOAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_AssetTOAccount_hpp
#define ASX_AssetTOAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class AssetTOAccount;
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

class AssetTOAccount : public R_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: OperatingRevenueAccount/Avg TotalAssetsAccount
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
	AssetTOAccount();
	AssetTOAccount(const AssetTOAccount* ptr);
	AssetTOAccount(const AssetTOAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_AssetTOAccount();

	//Destructor
	virtual ~AssetTOAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_AssetTOAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_AssetTOAccount(string fname);
	virtual void fscan(string fname);
	void fscan_AssetTOAccount(string fname);

	//Reset
	virtual void reset();
	void reset_AssetTOAccount();


	/** ------ Static Functions ----------------*/

	static AssetTOAccount* instance();

	static AssetTOAccount* instance_fscan(string fname);

   static AssetTOAccount* __ptr_AssetTOAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

