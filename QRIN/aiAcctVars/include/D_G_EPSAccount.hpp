// Name:     D_G_EPSAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_G_EPSAccount_hpp
#define ASX_D_G_EPSAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class D_G_EPSAccount;
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

class D_G_EPSAccount : public D_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: D.G_EPSAccount
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
	D_G_EPSAccount();
	D_G_EPSAccount(const D_G_EPSAccount* ptr);
	D_G_EPSAccount(const D_G_EPSAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_D_G_EPSAccount();

	//Destructor
	virtual ~D_G_EPSAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_D_G_EPSAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_D_G_EPSAccount(string fname);
	virtual void fscan(string fname);
	void fscan_D_G_EPSAccount(string fname);

	//Reset
	virtual void reset();
	void reset_D_G_EPSAccount();


	/** ------ Static Functions ----------------*/

	static D_G_EPSAccount* instance();

	static D_G_EPSAccount* instance_fscan(string fname);

   static D_G_EPSAccount* __ptr_D_G_EPSAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

