// Name:     StockExchangeAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_StockExchangeAccount_hpp
#define ASX_StockExchangeAccount_hpp

namespace aiMarketFields {
//Forword decalaration
class StockExchangeAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "StringDbAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMarketFields;
using namespace aiDbAccounts;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiMarketFields {

class StockExchangeAccount : public StringDbAccount  {

/**
 * 	Class Description:
 * 	   This account stores stock exchange information
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
	StockExchangeAccount();
	StockExchangeAccount(const StockExchangeAccount* ptr);
	StockExchangeAccount(const StockExchangeAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_StockExchangeAccount();

	//Destructor
	virtual ~StockExchangeAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_StockExchangeAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_StockExchangeAccount(string fname);
	virtual void fscan(string fname);
	void fscan_StockExchangeAccount(string fname);

	//Reset
	virtual void reset();
	void reset_StockExchangeAccount();


	/** ------ Static Functions ----------------*/

	static StockExchangeAccount* instance();

	static StockExchangeAccount* instance_fscan(string fname);

   static StockExchangeAccount* __ptr_StockExchangeAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

