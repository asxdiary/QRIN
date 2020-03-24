// Name:     MarketCapAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_MarketCapAccount_hpp
#define ASX_MarketCapAccount_hpp

namespace aiMarketFields {
//Forword decalaration
class MarketCapAccount;
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
/////////////////////////////////////////

namespace aiMarketFields {

class MarketCapAccount : public PositionAccount  {

/**
 * 	Class Description:
 * 	   This accounts stores the PIT market cap in millions of dollars
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
	MarketCapAccount();
	MarketCapAccount(const MarketCapAccount* ptr);
	MarketCapAccount(const MarketCapAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_MarketCapAccount();

	//Destructor
	virtual ~MarketCapAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_MarketCapAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_MarketCapAccount(string fname);
	virtual void fscan(string fname);
	void fscan_MarketCapAccount(string fname);

	//Reset
	virtual void reset();
	void reset_MarketCapAccount();


	/** ------ Static Functions ----------------*/

	static MarketCapAccount* instance();

	static MarketCapAccount* instance_fscan(string fname);

   static MarketCapAccount* __ptr_MarketCapAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

