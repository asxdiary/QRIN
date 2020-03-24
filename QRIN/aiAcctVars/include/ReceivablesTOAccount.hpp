// Name:     ReceivablesTOAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ReceivablesTOAccount_hpp
#define ASX_ReceivablesTOAccount_hpp

namespace aiAcctVars {
//Forword decalaration
class ReceivablesTOAccount;
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

class ReceivablesTOAccount : public R_DoubleDbAccount  {

/**
 * 	Class Description:
 * 		formula: OperatingRevenueAccount/Avg ReceivablesNetAccount
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
	ReceivablesTOAccount();
	ReceivablesTOAccount(const ReceivablesTOAccount* ptr);
	ReceivablesTOAccount(const ReceivablesTOAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_ReceivablesTOAccount();

	//Destructor
	virtual ~ReceivablesTOAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_ReceivablesTOAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_ReceivablesTOAccount(string fname);
	virtual void fscan(string fname);
	void fscan_ReceivablesTOAccount(string fname);

	//Reset
	virtual void reset();
	void reset_ReceivablesTOAccount();


	/** ------ Static Functions ----------------*/

	static ReceivablesTOAccount* instance();

	static ReceivablesTOAccount* instance_fscan(string fname);

   static ReceivablesTOAccount* __ptr_ReceivablesTOAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

