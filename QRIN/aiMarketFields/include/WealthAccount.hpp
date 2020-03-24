// Name:     WealthAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_WealthAccount_hpp
#define ASX_WealthAccount_hpp

namespace aiMarketFields {
//Forword decalaration
class WealthAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "PositionAccount.hpp"
#include "Db.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMarketFields;
using namespace aiDbAccounts;


//Parameters/////////////////////////////
#define WealthAccount_cumret_window 5
/////////////////////////////////////////

namespace aiMarketFields {

class WealthAccount : public PositionAccount  {

/**
 * 	Class Description:
 * 		This account stores cumulative returns on an security on some
 * 		nominal starting amount. This account facilitates efficient
 * 		computation of returns over periods with varyling lengths. For
 * 		instance, computing reporting date to reporting date returns (or a 
 * 		minor variant thereof) can be done efficiently using the wealth account
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
	WealthAccount();
	WealthAccount(const WealthAccount* ptr);
	WealthAccount(const WealthAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_WealthAccount();

	//Destructor
	virtual ~WealthAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_WealthAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_WealthAccount(string fname);
	virtual void fscan(string fname);
	void fscan_WealthAccount(string fname);

	//Reset
	virtual void reset();
	void reset_WealthAccount();


	/** ------ Static Functions ----------------*/

	static WealthAccount* instance();

	static WealthAccount* instance_fscan(string fname);

   static WealthAccount* __ptr_WealthAccount;

	/** ----------  Non-standard functions start here -----------*/

   virtual double cumret(Object* dbobj, Db* db, UtilDate* d1, UtilDate* d2, 
                         int& xval);

};

};

#endif

