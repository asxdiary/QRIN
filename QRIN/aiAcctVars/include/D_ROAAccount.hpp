// Name:     D_ROAAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_ROAAccount_hpp
#define ASX_D_ROAAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class D_ROAAccount;
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

class D_ROAAccount : public D_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: D.ROA
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
	D_ROAAccount();
	D_ROAAccount(const D_ROAAccount* ptr);
	D_ROAAccount(const D_ROAAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_D_ROAAccount();

	//Destructor
	virtual ~D_ROAAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_D_ROAAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_D_ROAAccount(string fname);
	virtual void fscan(string fname);
	void fscan_D_ROAAccount(string fname);

	//Reset
	virtual void reset();
	void reset_D_ROAAccount();


	/** ------ Static Functions ----------------*/

	static D_ROAAccount* instance();

	static D_ROAAccount* instance_fscan(string fname);

   static D_ROAAccount* __ptr_D_ROAAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

