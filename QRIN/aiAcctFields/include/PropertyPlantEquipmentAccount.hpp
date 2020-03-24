// Name:     PropertyPlantEquipmentAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_PropertyPlantEquipmentAccount_hpp
#define ASX_PropertyPlantEquipmentAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class PropertyPlantEquipmentAccount;
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

class PropertyPlantEquipmentAccount : public PositionAccount  {

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
	PropertyPlantEquipmentAccount();
	PropertyPlantEquipmentAccount(const PropertyPlantEquipmentAccount* ptr);
	PropertyPlantEquipmentAccount(const PropertyPlantEquipmentAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_PropertyPlantEquipmentAccount();

	//Destructor
	virtual ~PropertyPlantEquipmentAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_PropertyPlantEquipmentAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_PropertyPlantEquipmentAccount(string fname);
	virtual void fscan(string fname);
	void fscan_PropertyPlantEquipmentAccount(string fname);

	//Reset
	virtual void reset();
	void reset_PropertyPlantEquipmentAccount();


	/** ------ Static Functions ----------------*/

	static PropertyPlantEquipmentAccount* instance();

	static PropertyPlantEquipmentAccount* instance_fscan(string fname);

   static PropertyPlantEquipmentAccount* __ptr_PropertyPlantEquipmentAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

