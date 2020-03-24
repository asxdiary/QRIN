// Name:     ROAAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ROAAccount_hpp
#define ASX_ROAAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class ROAAccount;
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

class ROAAccount : public R_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: NetIncomeAccount/Avg TotalAssetsAccount
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
	ROAAccount();
	ROAAccount(const ROAAccount* ptr);
	ROAAccount(const ROAAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_ROAAccount();

	//Destructor
	virtual ~ROAAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_ROAAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_ROAAccount(string fname);
	virtual void fscan(string fname);
	void fscan_ROAAccount(string fname);

	//Reset
	virtual void reset();
	void reset_ROAAccount();


	/** ------ Static Functions ----------------*/

	static ROAAccount* instance();

	static ROAAccount* instance_fscan(string fname);

   static ROAAccount* __ptr_ROAAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

