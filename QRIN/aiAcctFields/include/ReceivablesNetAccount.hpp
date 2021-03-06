// Name:     ReceivablesNetAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ReceivablesNetAccount_hpp
#define ASX_ReceivablesNetAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class ReceivablesNetAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiAcctFields;
using namespace aiDbAccounts;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiAcctFields {

class ReceivablesNetAccount : public PositionAccount  {

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
	ReceivablesNetAccount();
	ReceivablesNetAccount(const ReceivablesNetAccount* ptr);
	ReceivablesNetAccount(const ReceivablesNetAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_ReceivablesNetAccount();

	//Destructor
	virtual ~ReceivablesNetAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_ReceivablesNetAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_ReceivablesNetAccount(string fname);
	virtual void fscan(string fname);
	void fscan_ReceivablesNetAccount(string fname);

	//Reset
	virtual void reset();
	void reset_ReceivablesNetAccount();


	/** ------ Static Functions ----------------*/

	static ReceivablesNetAccount* instance();

	static ReceivablesNetAccount* instance_fscan(string fname);

   static ReceivablesNetAccount* __ptr_ReceivablesNetAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

