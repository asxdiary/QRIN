// Name:     StartDateAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_StartDateAccount_hpp
#define ASX_StartDateAccount_hpp

namespace aiDbAccounts {
//Forword decalaration
class StartDateAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DateAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiDbAccounts;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiDbAccounts {

class StartDateAccount : public DateAccount  {

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
	StartDateAccount();
	StartDateAccount(const StartDateAccount* ptr);
	StartDateAccount(const StartDateAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_StartDateAccount();

	//Destructor
	virtual ~StartDateAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_StartDateAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_StartDateAccount(string fname);
	virtual void fscan(string fname);
	void fscan_StartDateAccount(string fname);

	//Reset
	virtual void reset();
	void reset_StartDateAccount();


	/** ------ Static Functions ----------------*/

	static StartDateAccount* instance();

	static StartDateAccount* instance_fscan(string fname);

   static StartDateAccount* __ptr_StartDateAccount;

	/** ----------  Non-standard functions start here -----------*/

   virtual void agg(ObjectDb* odb, vector<ObjectDb*>* odbv, UtilDate* dh, int& xval);
   virtual double agg_guts(vector<ObjectDb*>* odbv, UtilDate* dh, int& xval);

};

};

#endif

