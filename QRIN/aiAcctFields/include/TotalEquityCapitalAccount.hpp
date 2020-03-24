// Name:     TotalEquityCapitalAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_TotalEquityCapitalAccount_hpp
#define ASX_TotalEquityCapitalAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class TotalEquityCapitalAccount;
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

class TotalEquityCapitalAccount : public PositionAccount  {

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
	TotalEquityCapitalAccount();
	TotalEquityCapitalAccount(const TotalEquityCapitalAccount* ptr);
	TotalEquityCapitalAccount(const TotalEquityCapitalAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_TotalEquityCapitalAccount();

	//Destructor
	virtual ~TotalEquityCapitalAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_TotalEquityCapitalAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_TotalEquityCapitalAccount(string fname);
	virtual void fscan(string fname);
	void fscan_TotalEquityCapitalAccount(string fname);

	//Reset
	virtual void reset();
	void reset_TotalEquityCapitalAccount();


	/** ------ Static Functions ----------------*/

	static TotalEquityCapitalAccount* instance();

	static TotalEquityCapitalAccount* instance_fscan(string fname);

   static TotalEquityCapitalAccount* __ptr_TotalEquityCapitalAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

