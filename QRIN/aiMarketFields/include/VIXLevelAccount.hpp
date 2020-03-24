// Name:     VIXLevelAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_VIXLevelAccount_hpp
#define ASX_VIXLevelAccount_hpp

namespace aiMarketFields {
//Forword decalaration
class VIXLevelAccount;
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
#define VIXLevelAccount_cumret_window 5
/////////////////////////////////////////

namespace aiMarketFields {

class VIXLevelAccount : public PositionAccount  {

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
	VIXLevelAccount();
	VIXLevelAccount(const VIXLevelAccount* ptr);
	VIXLevelAccount(const VIXLevelAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_VIXLevelAccount();

	//Destructor
	virtual ~VIXLevelAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_VIXLevelAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_VIXLevelAccount(string fname);
	virtual void fscan(string fname);
	void fscan_VIXLevelAccount(string fname);

	//Reset
	virtual void reset();
	void reset_VIXLevelAccount();


	/** ------ Static Functions ----------------*/

	static VIXLevelAccount* instance();

	static VIXLevelAccount* instance_fscan(string fname);

   static VIXLevelAccount* __ptr_VIXLevelAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

