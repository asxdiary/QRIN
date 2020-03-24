// Name:     SellingGeneralAdministrativeAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_SellingGeneralAdministrativeAccount_hpp
#define ASX_SellingGeneralAdministrativeAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class SellingGeneralAdministrativeAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctFields;
using namespace aiDbAccounts;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiAcctFields {

class SellingGeneralAdministrativeAccount : public FlowAccount  {

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
	SellingGeneralAdministrativeAccount();
	SellingGeneralAdministrativeAccount(const SellingGeneralAdministrativeAccount* ptr);
	SellingGeneralAdministrativeAccount(const SellingGeneralAdministrativeAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_SellingGeneralAdministrativeAccount();

	//Destructor
	virtual ~SellingGeneralAdministrativeAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_SellingGeneralAdministrativeAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_SellingGeneralAdministrativeAccount(string fname);
	virtual void fscan(string fname);
	void fscan_SellingGeneralAdministrativeAccount(string fname);

	//Reset
	virtual void reset();
	void reset_SellingGeneralAdministrativeAccount();


	/** ------ Static Functions ----------------*/

	static SellingGeneralAdministrativeAccount* instance();

	static SellingGeneralAdministrativeAccount* instance_fscan(string fname);

   static SellingGeneralAdministrativeAccount* __ptr_SellingGeneralAdministrativeAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

