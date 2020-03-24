// Name:     ResearchDevelopmentIntensityAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ResearchDevelopmentIntensityAccount_hpp
#define ASX_ResearchDevelopmentIntensityAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class ResearchDevelopmentIntensityAccount;
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

class ResearchDevelopmentIntensityAccount : public R_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: R&D/OperatingRevenue
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
	ResearchDevelopmentIntensityAccount();
	ResearchDevelopmentIntensityAccount(const ResearchDevelopmentIntensityAccount* ptr);
	ResearchDevelopmentIntensityAccount(const ResearchDevelopmentIntensityAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_ResearchDevelopmentIntensityAccount();

	//Destructor
	virtual ~ResearchDevelopmentIntensityAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_ResearchDevelopmentIntensityAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_ResearchDevelopmentIntensityAccount(string fname);
	virtual void fscan(string fname);
	void fscan_ResearchDevelopmentIntensityAccount(string fname);

	//Reset
	virtual void reset();
	void reset_ResearchDevelopmentIntensityAccount();


	/** ------ Static Functions ----------------*/

	static ResearchDevelopmentIntensityAccount* instance();

	static ResearchDevelopmentIntensityAccount* instance_fscan(string fname);

   static ResearchDevelopmentIntensityAccount* __ptr_ResearchDevelopmentIntensityAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

