// Name:     SP500BetaAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_SP500BetaAccount_hpp
#define ASX_SP500BetaAccount_hpp

namespace aiMarketFields {
//Forword decalaration
class SP500BetaAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "StatisticAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMarketFields;
using namespace aiDbAccounts;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiMarketFields {

class SP500BetaAccount : public StatisticAccount  {

/**
 * 	Class Description:
 * 	   This account stores the beta computed w.r.t to SP500;
 * 	   see specs/db/Betas for additional computational details
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
	SP500BetaAccount();
	SP500BetaAccount(const SP500BetaAccount* ptr);
	SP500BetaAccount(const SP500BetaAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_SP500BetaAccount();

	//Destructor
	virtual ~SP500BetaAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_SP500BetaAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_SP500BetaAccount(string fname);
	virtual void fscan(string fname);
	void fscan_SP500BetaAccount(string fname);

	//Reset
	virtual void reset();
	void reset_SP500BetaAccount();


	/** ------ Static Functions ----------------*/

	static SP500BetaAccount* instance();

	static SP500BetaAccount* instance_fscan(string fname);

   static SP500BetaAccount* __ptr_SP500BetaAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

