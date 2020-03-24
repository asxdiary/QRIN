// Name:     D_AssetTOAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_AssetTOAccount_hpp
#define ASX_D_AssetTOAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class D_AssetTOAccount;
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

class D_AssetTOAccount : public D_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: D.AssetTOAccount
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
	D_AssetTOAccount();
	D_AssetTOAccount(const D_AssetTOAccount* ptr);
	D_AssetTOAccount(const D_AssetTOAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_D_AssetTOAccount();

	//Destructor
	virtual ~D_AssetTOAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_D_AssetTOAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_D_AssetTOAccount(string fname);
	virtual void fscan(string fname);
	void fscan_D_AssetTOAccount(string fname);

	//Reset
	virtual void reset();
	void reset_D_AssetTOAccount();


	/** ------ Static Functions ----------------*/

	static D_AssetTOAccount* instance();

	static D_AssetTOAccount* instance_fscan(string fname);

   static D_AssetTOAccount* __ptr_D_AssetTOAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

