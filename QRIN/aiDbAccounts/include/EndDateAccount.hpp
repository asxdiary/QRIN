// Name:     EndDateAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_EndDateAccount_hpp
#define ASX_EndDateAccount_hpp

namespace aiDbAccounts {
//Forword decalaration
class EndDateAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DateAccount.hpp"
#include "ObjectDb.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiDbAccounts;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiDbAccounts {

class EndDateAccount : public DateAccount  {

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
	EndDateAccount();
	EndDateAccount(const EndDateAccount* ptr);
	EndDateAccount(const EndDateAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_EndDateAccount();

	//Destructor
	virtual ~EndDateAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_EndDateAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_EndDateAccount(string fname);
	virtual void fscan(string fname);
	void fscan_EndDateAccount(string fname);

	//Reset
	virtual void reset();
	void reset_EndDateAccount();


	/** ------ Static Functions ----------------*/

	static EndDateAccount* instance();

	static EndDateAccount* instance_fscan(string fname);

   static EndDateAccount* __ptr_EndDateAccount;

	/** ----------  Non-standard functions start here -----------*/

   virtual void agg(ObjectDb* odb, vector<ObjectDb*>* odbv, UtilDate* dh, int& xval);
   virtual double agg_guts(vector<ObjectDb*>* odbv, UtilDate* dh, int& xval);

};

};

#endif

