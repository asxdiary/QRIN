// Name:     StatisticAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_StatisticAccount_hpp
#define ASX_StatisticAccount_hpp

namespace aiDbAccounts {
//Forword decalaration
class StatisticAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DoubleDbAccount.hpp"

using namespace std;
using namespace aiUtils;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiDbAccounts {

class StatisticAccount : public DoubleDbAccount  {

/**
 * 	Class Description:
 * 	   This class is used to store various kinds of statistics such
 * 	   as beta, volatility, skew etc
 * 
 * 	Assumptions:
 * 		None
 * 
 * 	Objects: (P=Parent; NO=Not Ownwed; O=Owned)
 * 		None
 * 
 * 	Ownership:
 * 		Indicated above
 * 
 */

private:
/**	Data Members */

protected: 

	/** Protected Constructors */
	StatisticAccount();
	StatisticAccount(const StatisticAccount* ptr);
	StatisticAccount(const StatisticAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_StatisticAccount();

	//Destructor
	virtual ~StatisticAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_StatisticAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_StatisticAccount(string fname);
	virtual void fscan(string fname);
	void fscan_StatisticAccount(string fname);

	//Reset
	virtual void reset();
	void reset_StatisticAccount();


	/** ------ Static Functions ----------------*/

	static StatisticAccount* instance();

	static StatisticAccount* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

