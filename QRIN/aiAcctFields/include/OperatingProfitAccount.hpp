// Name:     OperatingProfitAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_OperatingProfitAccount_hpp
#define ASX_OperatingProfitAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class OperatingProfitAccount;
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

class OperatingProfitAccount : public FlowAccount  {

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
	OperatingProfitAccount();
	OperatingProfitAccount(const OperatingProfitAccount* ptr);
	OperatingProfitAccount(const OperatingProfitAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_OperatingProfitAccount();

	//Destructor
	virtual ~OperatingProfitAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_OperatingProfitAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_OperatingProfitAccount(string fname);
	virtual void fscan(string fname);
	void fscan_OperatingProfitAccount(string fname);

	//Reset
	virtual void reset();
	void reset_OperatingProfitAccount();


	/** ------ Static Functions ----------------*/

	static OperatingProfitAccount* instance();

	static OperatingProfitAccount* instance_fscan(string fname);

   static OperatingProfitAccount* __ptr_OperatingProfitAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

