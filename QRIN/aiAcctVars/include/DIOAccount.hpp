// Name:     DIOAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DIOAccount_hpp
#define ASX_DIOAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class DIOAccount;
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

class DIOAccount : public DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: 365/InventoryTO
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
	DIOAccount();
	DIOAccount(const DIOAccount* ptr);
	DIOAccount(const DIOAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_DIOAccount();

	//Destructor
	virtual ~DIOAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_DIOAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_DIOAccount(string fname);
	virtual void fscan(string fname);
	void fscan_DIOAccount(string fname);

	//Reset
	virtual void reset();
	void reset_DIOAccount();


	/** ------ Static Functions ----------------*/

	static DIOAccount* instance();

	static DIOAccount* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual void compute(vector<ObjectDb*>* odbv, int& xval);

};

};

#endif

