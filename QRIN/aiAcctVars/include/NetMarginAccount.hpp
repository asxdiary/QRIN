// Name:     NetMarginAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_NetMarginAccount_hpp
#define ASX_NetMarginAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class NetMarginAccount;
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

class NetMarginAccount : public R_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: NetIncome/OperatingRevenue
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
	NetMarginAccount();
	NetMarginAccount(const NetMarginAccount* ptr);
	NetMarginAccount(const NetMarginAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_NetMarginAccount();

	//Destructor
	virtual ~NetMarginAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_NetMarginAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_NetMarginAccount(string fname);
	virtual void fscan(string fname);
	void fscan_NetMarginAccount(string fname);

	//Reset
	virtual void reset();
	void reset_NetMarginAccount();


	/** ------ Static Functions ----------------*/

	static NetMarginAccount* instance();

	static NetMarginAccount* instance_fscan(string fname);

   static NetMarginAccount* __ptr_NetMarginAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

