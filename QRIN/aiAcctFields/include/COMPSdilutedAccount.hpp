// Name:     COMPSdilutedAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_COMPSdilutedAccount_hpp
#define ASX_COMPSdilutedAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class COMPSdilutedAccount;
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

class COMPSdilutedAccount : public FlowAccount  {

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
	COMPSdilutedAccount();
	COMPSdilutedAccount(const COMPSdilutedAccount* ptr);
	COMPSdilutedAccount(const COMPSdilutedAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_COMPSdilutedAccount();

	//Destructor
	virtual ~COMPSdilutedAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_COMPSdilutedAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_COMPSdilutedAccount(string fname);
	virtual void fscan(string fname);
	void fscan_COMPSdilutedAccount(string fname);

	//Reset
	virtual void reset();
	void reset_COMPSdilutedAccount();


	/** ------ Static Functions ----------------*/

	static COMPSdilutedAccount* instance();

	static COMPSdilutedAccount* instance_fscan(string fname);

   static COMPSdilutedAccount* __ptr_COMPSdilutedAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

