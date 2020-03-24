// Name:     InventoryTOAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_InventoryTOAccount_hpp
#define ASX_InventoryTOAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class InventoryTOAccount;
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

class InventoryTOAccount : public R_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: CostRevenueAccount/Avg InventoriesNetAccount
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
	InventoryTOAccount();
	InventoryTOAccount(const InventoryTOAccount* ptr);
	InventoryTOAccount(const InventoryTOAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_InventoryTOAccount();

	//Destructor
	virtual ~InventoryTOAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_InventoryTOAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_InventoryTOAccount(string fname);
	virtual void fscan(string fname);
	void fscan_InventoryTOAccount(string fname);

	//Reset
	virtual void reset();
	void reset_InventoryTOAccount();


	/** ------ Static Functions ----------------*/

	static InventoryTOAccount* instance();

	static InventoryTOAccount* instance_fscan(string fname);

   static InventoryTOAccount* __ptr_InventoryTOAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

