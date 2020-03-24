// Name:     R_TemplateAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_R_TemplateAccount_hpp
#define ASX_R_TemplateAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class R_TemplateAccount;
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

class R_TemplateAccount : public R_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: TemplateFlowAccount/TemplatePositionAccount
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
	R_TemplateAccount();
	R_TemplateAccount(const R_TemplateAccount* ptr);
	R_TemplateAccount(const R_TemplateAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_R_TemplateAccount();

	//Destructor
	virtual ~R_TemplateAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_R_TemplateAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_R_TemplateAccount(string fname);
	virtual void fscan(string fname);
	void fscan_R_TemplateAccount(string fname);

	//Reset
	virtual void reset();
	void reset_R_TemplateAccount();


	/** ------ Static Functions ----------------*/

	static R_TemplateAccount* instance();

	static R_TemplateAccount* instance_fscan(string fname);

   static R_TemplateAccount* __ptr_R_TemplateAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

