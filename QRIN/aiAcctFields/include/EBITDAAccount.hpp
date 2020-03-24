// Name:     EBITDAAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_EBITDAAccount_hpp
#define ASX_EBITDAAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class EBITDAAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctFields;
using namespace aiDbAccounts;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiAcctFields {

class EBITDAAccount : public FlowAccount  {

/**
 * 	Class Description:
 * 		TotalAssets Account
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
	EBITDAAccount();
	EBITDAAccount(const EBITDAAccount* ptr);
	EBITDAAccount(const EBITDAAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_EBITDAAccount();

	//Destructor
	virtual ~EBITDAAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_EBITDAAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_EBITDAAccount(string fname);
	virtual void fscan(string fname);
	void fscan_EBITDAAccount(string fname);

	//Reset
	virtual void reset();
	void reset_EBITDAAccount();


	/** ------ Static Functions ----------------*/

	static EBITDAAccount* instance();

	static EBITDAAccount* instance_fscan(string fname);

   static EBITDAAccount* __ptr_EBITDAAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

