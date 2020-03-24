// Name:     D_DSOAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_DSOAccount_hpp
#define ASX_D_DSOAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class D_DSOAccount;
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

class D_DSOAccount : public D_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: D.DSOAccount
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
	D_DSOAccount();
	D_DSOAccount(const D_DSOAccount* ptr);
	D_DSOAccount(const D_DSOAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_D_DSOAccount();

	//Destructor
	virtual ~D_DSOAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_D_DSOAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_D_DSOAccount(string fname);
	virtual void fscan(string fname);
	void fscan_D_DSOAccount(string fname);

	//Reset
	virtual void reset();
	void reset_D_DSOAccount();


	/** ------ Static Functions ----------------*/

	static D_DSOAccount* instance();

	static D_DSOAccount* instance_fscan(string fname);

   static D_DSOAccount* __ptr_D_DSOAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

