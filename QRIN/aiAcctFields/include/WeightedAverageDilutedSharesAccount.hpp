// Name:     WeightedAverageDilutedSharesAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_WeightedAverageDilutedSharesAccount_hpp
#define ASX_WeightedAverageDilutedSharesAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class WeightedAverageDilutedSharesAccount;
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

class WeightedAverageDilutedSharesAccount : public FlowAccount  {

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
	WeightedAverageDilutedSharesAccount();
	WeightedAverageDilutedSharesAccount(const WeightedAverageDilutedSharesAccount* ptr);
	WeightedAverageDilutedSharesAccount(const WeightedAverageDilutedSharesAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_WeightedAverageDilutedSharesAccount();

	//Destructor
	virtual ~WeightedAverageDilutedSharesAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_WeightedAverageDilutedSharesAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_WeightedAverageDilutedSharesAccount(string fname);
	virtual void fscan(string fname);
	void fscan_WeightedAverageDilutedSharesAccount(string fname);

	//Reset
	virtual void reset();
	void reset_WeightedAverageDilutedSharesAccount();


	/** ------ Static Functions ----------------*/

	static WeightedAverageDilutedSharesAccount* instance();

	static WeightedAverageDilutedSharesAccount* instance_fscan(string fname);

   static WeightedAverageDilutedSharesAccount* __ptr_WeightedAverageDilutedSharesAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

