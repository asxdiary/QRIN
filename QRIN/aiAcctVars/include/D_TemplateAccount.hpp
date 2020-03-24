// Name:     D_TemplateAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_TemplateAccount_hpp
#define ASX_D_TemplateAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class D_TemplateAccount;
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

class D_TemplateAccount : public D_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: D.TemplateAccount
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
	D_TemplateAccount();
	D_TemplateAccount(const D_TemplateAccount* ptr);
	D_TemplateAccount(const D_TemplateAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_D_TemplateAccount();

	//Destructor
	virtual ~D_TemplateAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_D_TemplateAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_D_TemplateAccount(string fname);
	virtual void fscan(string fname);
	void fscan_D_TemplateAccount(string fname);

	//Reset
	virtual void reset();
	void reset_D_TemplateAccount();


	/** ------ Static Functions ----------------*/

	static D_TemplateAccount* instance();

	static D_TemplateAccount* instance_fscan(string fname);

   static D_TemplateAccount* __ptr_D_TemplateAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

