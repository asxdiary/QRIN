// Name:     InventoriesNetAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_InventoriesNetAccount_hpp
#define ASX_InventoriesNetAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class InventoriesNetAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctFields;
using namespace aiDbAccounts;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiAcctFields {

class InventoriesNetAccount : public PositionAccount  {

/**
 * 	Class Description:
 * 		TotalAssets Account
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
	InventoriesNetAccount();
	InventoriesNetAccount(const InventoriesNetAccount* ptr);
	InventoriesNetAccount(const InventoriesNetAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_InventoriesNetAccount();

	//Destructor
	virtual ~InventoriesNetAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_InventoriesNetAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_InventoriesNetAccount(string fname);
	virtual void fscan(string fname);
	void fscan_InventoriesNetAccount(string fname);

	//Reset
	virtual void reset();
	void reset_InventoriesNetAccount();


	/** ------ Static Functions ----------------*/

	static InventoriesNetAccount* instance();

	static InventoriesNetAccount* instance_fscan(string fname);

   static InventoriesNetAccount* __ptr_InventoriesNetAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

