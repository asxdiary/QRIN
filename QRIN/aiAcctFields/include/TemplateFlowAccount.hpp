// Name:     TemplateFlowAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_TemplateFlowAccount_hpp
#define ASX_TemplateFlowAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class TemplateFlowAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctFields;
using namespace aiDbAccounts;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiAcctFields {

class TemplateFlowAccount : public FlowAccount  {

/**
 * 	Class Description:
 * 		TotalAssets Account
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
	TemplateFlowAccount();
	TemplateFlowAccount(const TemplateFlowAccount* ptr);
	TemplateFlowAccount(const TemplateFlowAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_TemplateFlowAccount();

	//Destructor
	virtual ~TemplateFlowAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_TemplateFlowAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_TemplateFlowAccount(string fname);
	virtual void fscan(string fname);
	void fscan_TemplateFlowAccount(string fname);

	//Reset
	virtual void reset();
	void reset_TemplateFlowAccount();


	/** ------ Static Functions ----------------*/

	static TemplateFlowAccount* instance();

	static TemplateFlowAccount* instance_fscan(string fname);

   static TemplateFlowAccount* __ptr_TemplateFlowAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

