// Name:     AcquisitionsDivestituresNetAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_AcquisitionsDivestituresNetAccount_hpp
#define ASX_AcquisitionsDivestituresNetAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class AcquisitionsDivestituresNetAccount;
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

class AcquisitionsDivestituresNetAccount : public FlowAccount  {

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
	AcquisitionsDivestituresNetAccount();
	AcquisitionsDivestituresNetAccount(const AcquisitionsDivestituresNetAccount* ptr);
	AcquisitionsDivestituresNetAccount(const AcquisitionsDivestituresNetAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_AcquisitionsDivestituresNetAccount();

	//Destructor
	virtual ~AcquisitionsDivestituresNetAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_AcquisitionsDivestituresNetAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_AcquisitionsDivestituresNetAccount(string fname);
	virtual void fscan(string fname);
	void fscan_AcquisitionsDivestituresNetAccount(string fname);

	//Reset
	virtual void reset();
	void reset_AcquisitionsDivestituresNetAccount();


	/** ------ Static Functions ----------------*/

	static AcquisitionsDivestituresNetAccount* instance();

	static AcquisitionsDivestituresNetAccount* instance_fscan(string fname);

   static AcquisitionsDivestituresNetAccount* __ptr_AcquisitionsDivestituresNetAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

