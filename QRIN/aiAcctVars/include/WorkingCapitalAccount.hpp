// Name:     WorkingCapitalAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_WorkingCapitalAccount_hpp
#define ASX_WorkingCapitalAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class WorkingCapitalAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DoubleDbAccount.hpp"
#include "CurrentAssetsAccount.hpp"
#include "CurrentLiabilitiesAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiAcctFields;
using namespace aiAcctVars;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiAcctVars {

class WorkingCapitalAccount : public DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: CurrentAssets - CurrentLiabilties
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
	WorkingCapitalAccount();
	WorkingCapitalAccount(const WorkingCapitalAccount* ptr);
	WorkingCapitalAccount(const WorkingCapitalAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_WorkingCapitalAccount();

	//Destructor
	virtual ~WorkingCapitalAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_WorkingCapitalAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_WorkingCapitalAccount(string fname);
	virtual void fscan(string fname);
	void fscan_WorkingCapitalAccount(string fname);

	//Reset
	virtual void reset();
	void reset_WorkingCapitalAccount();


	/** ------ Static Functions ----------------*/

	static WorkingCapitalAccount* instance();

	static WorkingCapitalAccount* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual void compute(vector<ObjectDb*>* odbv, int& xval);

};

};

#endif

