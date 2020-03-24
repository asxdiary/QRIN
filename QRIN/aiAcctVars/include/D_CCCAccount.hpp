// Name:     D_CCCAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_CCCAccount_hpp
#define ASX_D_CCCAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class D_CCCAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "D_DoubleDbAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctVars;
using namespace aiDb;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiAcctVars {

class D_CCCAccount : public D_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: D.CCCAccount
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
	D_CCCAccount();
	D_CCCAccount(const D_CCCAccount* ptr);
	D_CCCAccount(const D_CCCAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_D_CCCAccount();

	//Destructor
	virtual ~D_CCCAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_D_CCCAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_D_CCCAccount(string fname);
	virtual void fscan(string fname);
	void fscan_D_CCCAccount(string fname);

	//Reset
	virtual void reset();
	void reset_D_CCCAccount();


	/** ------ Static Functions ----------------*/

	static D_CCCAccount* instance();

	static D_CCCAccount* instance_fscan(string fname);

   static D_CCCAccount* __ptr_D_CCCAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

