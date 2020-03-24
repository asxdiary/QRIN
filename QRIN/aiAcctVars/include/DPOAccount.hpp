// Name:     DPOAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DPOAccount_hpp
#define ASX_DPOAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class DPOAccount;
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

class DPOAccount : public DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: 365/PayablesTO
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
	DPOAccount();
	DPOAccount(const DPOAccount* ptr);
	DPOAccount(const DPOAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_DPOAccount();

	//Destructor
	virtual ~DPOAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_DPOAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_DPOAccount(string fname);
	virtual void fscan(string fname);
	void fscan_DPOAccount(string fname);

	//Reset
	virtual void reset();
	void reset_DPOAccount();


	/** ------ Static Functions ----------------*/

	static DPOAccount* instance();

	static DPOAccount* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual void compute(vector<ObjectDb*>* odbv, int& xval);

};

};

#endif

