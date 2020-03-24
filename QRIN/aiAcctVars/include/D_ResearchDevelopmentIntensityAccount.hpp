// Name:     D_ResearchDevelopmentIntensityAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_D_ResearchDevelopmentIntensityAccount_hpp
#define ASX_D_ResearchDevelopmentIntensityAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class D_ResearchDevelopmentIntensityAccount;
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

class D_ResearchDevelopmentIntensityAccount : public D_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: D.R_ResearchDevelopmentIntensityAccount
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
	D_ResearchDevelopmentIntensityAccount();
	D_ResearchDevelopmentIntensityAccount(const D_ResearchDevelopmentIntensityAccount* ptr);
	D_ResearchDevelopmentIntensityAccount(const D_ResearchDevelopmentIntensityAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_D_ResearchDevelopmentIntensityAccount();

	//Destructor
	virtual ~D_ResearchDevelopmentIntensityAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_D_ResearchDevelopmentIntensityAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_D_ResearchDevelopmentIntensityAccount(string fname);
	virtual void fscan(string fname);
	void fscan_D_ResearchDevelopmentIntensityAccount(string fname);

	//Reset
	virtual void reset();
	void reset_D_ResearchDevelopmentIntensityAccount();


	/** ------ Static Functions ----------------*/

	static D_ResearchDevelopmentIntensityAccount* instance();

	static D_ResearchDevelopmentIntensityAccount* instance_fscan(string fname);

   static D_ResearchDevelopmentIntensityAccount* __ptr_D_ResearchDevelopmentIntensityAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

