// Name:     DSOAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DSOAccount_hpp
#define ASX_DSOAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class DSOAccount;
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

class DSOAccount : public DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: 365/ReceivablesTO
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
	DSOAccount();
	DSOAccount(const DSOAccount* ptr);
	DSOAccount(const DSOAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_DSOAccount();

	//Destructor
	virtual ~DSOAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_DSOAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_DSOAccount(string fname);
	virtual void fscan(string fname);
	void fscan_DSOAccount(string fname);

	//Reset
	virtual void reset();
	void reset_DSOAccount();


	/** ------ Static Functions ----------------*/

	static DSOAccount* instance();

	static DSOAccount* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual void compute(vector<ObjectDb*>* odbv, int& xval);

};

};

#endif

