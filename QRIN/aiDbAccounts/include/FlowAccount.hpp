// Name:     FlowAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_FlowAccount_hpp
#define ASX_FlowAccount_hpp

namespace aiDbAccounts {
//Forword decalaration
class FlowAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DoubleDbAccount.hpp"

using namespace std;
using namespace aiUtils;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiDbAccounts {

class FlowAccount : public DoubleDbAccount  {

/**
 * 	Class Description:
 * 		This is used to store atributes.
 * 		e.g revenue, COGS, asset returns
 * 
 * 	Assumptions:
 * 		None
 * 
 * 	Objects: (P=Parent; NO=Not Ownwed; O=Owned)
 * 		None
 * 
 * 	Ownership:
 * 		Indicated above
 * 
 */

private:
/**	Data Members */

protected: 

	/** Protected Constructors */
	FlowAccount();
	FlowAccount(const FlowAccount* ptr);
	FlowAccount(const FlowAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_FlowAccount();

	//Destructor
	virtual ~FlowAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_FlowAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_FlowAccount(string fname);
	virtual void fscan(string fname);
	void fscan_FlowAccount(string fname);

	//Reset
	virtual void reset();
	void reset_FlowAccount();


	/** ------ Static Functions ----------------*/

	static FlowAccount* instance();

	static FlowAccount* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual double agg_guts(vector<ObjectDb*>* odbv, UtilDate* dh, int& xval);

};

};

#endif

