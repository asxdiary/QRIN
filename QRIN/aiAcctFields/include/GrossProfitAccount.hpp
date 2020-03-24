// Name:     GrossProfitAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_GrossProfitAccount_hpp
#define ASX_GrossProfitAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class GrossProfitAccount;
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

class GrossProfitAccount : public FlowAccount  {

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
	GrossProfitAccount();
	GrossProfitAccount(const GrossProfitAccount* ptr);
	GrossProfitAccount(const GrossProfitAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_GrossProfitAccount();

	//Destructor
	virtual ~GrossProfitAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_GrossProfitAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_GrossProfitAccount(string fname);
	virtual void fscan(string fname);
	void fscan_GrossProfitAccount(string fname);

	//Reset
	virtual void reset();
	void reset_GrossProfitAccount();


	/** ------ Static Functions ----------------*/

	static GrossProfitAccount* instance();

	static GrossProfitAccount* instance_fscan(string fname);

   static GrossProfitAccount* __ptr_GrossProfitAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

