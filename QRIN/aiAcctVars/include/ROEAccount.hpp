// Name:     ROEAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ROEAccount_hpp
#define ASX_ROEAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class ROEAccount;
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

class ROEAccount : public R_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: NetIncome/Avg Equity
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
	ROEAccount();
	ROEAccount(const ROEAccount* ptr);
	ROEAccount(const ROEAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_ROEAccount();

	//Destructor
	virtual ~ROEAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_ROEAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_ROEAccount(string fname);
	virtual void fscan(string fname);
	void fscan_ROEAccount(string fname);

	//Reset
	virtual void reset();
	void reset_ROEAccount();


	/** ------ Static Functions ----------------*/

	static ROEAccount* instance();

	static ROEAccount* instance_fscan(string fname);

   static ROEAccount* __ptr_ROEAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

