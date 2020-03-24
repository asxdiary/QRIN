// Name:     D_ROEAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_ROEAccount_hpp
#define ASX_D_ROEAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class D_ROEAccount;
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

class D_ROEAccount : public D_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: D.ROEAccount
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
	D_ROEAccount();
	D_ROEAccount(const D_ROEAccount* ptr);
	D_ROEAccount(const D_ROEAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_D_ROEAccount();

	//Destructor
	virtual ~D_ROEAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_D_ROEAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_D_ROEAccount(string fname);
	virtual void fscan(string fname);
	void fscan_D_ROEAccount(string fname);

	//Reset
	virtual void reset();
	void reset_D_ROEAccount();


	/** ------ Static Functions ----------------*/

	static D_ROEAccount* instance();

	static D_ROEAccount* instance_fscan(string fname);

   static D_ROEAccount* __ptr_D_ROEAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

