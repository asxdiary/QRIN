// Name:     TemplatePositionAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_TemplatePositionAccount_hpp
#define ASX_TemplatePositionAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class TemplatePositionAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctFields;
using namespace aiDbAccounts;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiAcctFields {

class TemplatePositionAccount : public PositionAccount  {

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
	TemplatePositionAccount();
	TemplatePositionAccount(const TemplatePositionAccount* ptr);
	TemplatePositionAccount(const TemplatePositionAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_TemplatePositionAccount();

	//Destructor
	virtual ~TemplatePositionAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_TemplatePositionAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_TemplatePositionAccount(string fname);
	virtual void fscan(string fname);
	void fscan_TemplatePositionAccount(string fname);

	//Reset
	virtual void reset();
	void reset_TemplatePositionAccount();


	/** ------ Static Functions ----------------*/

	static TemplatePositionAccount* instance();

	static TemplatePositionAccount* instance_fscan(string fname);

   static TemplatePositionAccount* __ptr_TemplatePositionAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

