// Name:     G_TemplateAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_G_TemplateAccount_hpp
#define ASX_G_TemplateAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class G_TemplateAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "G_DoubleDbAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctVars;
using namespace aiDb;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiAcctVars {

class G_TemplateAccount : public G_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: TemplateAccount1/TemplateAccount0 - 1
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
	G_TemplateAccount();
	G_TemplateAccount(const G_TemplateAccount* ptr);
	G_TemplateAccount(const G_TemplateAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(bool geom_flag);
	void init_G_TemplateAccount();

	//Destructor
	virtual ~G_TemplateAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_G_TemplateAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_G_TemplateAccount(string fname);
	virtual void fscan(string fname);
	void fscan_G_TemplateAccount(string fname);

	//Reset
	virtual void reset();
	void reset_G_TemplateAccount();


	/** ------ Static Functions ----------------*/

	static G_TemplateAccount* instance(bool geom_flag=true);

	static G_TemplateAccount* instance_fscan(string fname);

   static G_TemplateAccount* __ptr_G_TemplateAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

