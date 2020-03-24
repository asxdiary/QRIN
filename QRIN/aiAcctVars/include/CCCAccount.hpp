// Name:     CCCAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CCCAccount_hpp
#define ASX_CCCAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class CCCAccount;
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

class CCCAccount : public DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: CCC = DIO + DSO - DPO
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
	CCCAccount();
	CCCAccount(const CCCAccount* ptr);
	CCCAccount(const CCCAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_CCCAccount();

	//Destructor
	virtual ~CCCAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_CCCAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_CCCAccount(string fname);
	virtual void fscan(string fname);
	void fscan_CCCAccount(string fname);

	//Reset
	virtual void reset();
	void reset_CCCAccount();


	/** ------ Static Functions ----------------*/

	static CCCAccount* instance();

	static CCCAccount* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual void compute(vector<ObjectDb*>* odbv, int& xval);

};

};

#endif

