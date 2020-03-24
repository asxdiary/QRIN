// Name:     TotalReturnsAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_TotalReturnsAccount_hpp
#define ASX_TotalReturnsAccount_hpp

namespace aiMarketFields {
//Forword decalaration
class TotalReturnsAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "FlowAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiMarketFields;
using namespace aiDbAccounts;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiMarketFields {

class TotalReturnsAccount : public FlowAccount  {

/**
 * 	Class Description:
 * 		This account stores the total returns for a security; in the
 * 		spirit of flow variables, the period over which the return is measured
 * 		is stored by means of start and end dates. This allows us to 
 * 		use the same account for daily, weekly, monthly, etc returns, and
 * 		also perform aggregation in a seamless fashion
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
	TotalReturnsAccount();
	TotalReturnsAccount(const TotalReturnsAccount* ptr);
	TotalReturnsAccount(const TotalReturnsAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_TotalReturnsAccount();

	//Destructor
	virtual ~TotalReturnsAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_TotalReturnsAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_TotalReturnsAccount(string fname);
	virtual void fscan(string fname);
	void fscan_TotalReturnsAccount(string fname);

	//Reset
	virtual void reset();
	void reset_TotalReturnsAccount();


	/** ------ Static Functions ----------------*/

	static TotalReturnsAccount* instance();

	static TotalReturnsAccount* instance_fscan(string fname);

   static TotalReturnsAccount* __ptr_TotalReturnsAccount;

	/** ----------  Non-standard functions start here -----------*/

   virtual double agg_guts(vector<ObjectDb*>* odbv, UtilDate* dh, int& xval);

};

};

#endif

