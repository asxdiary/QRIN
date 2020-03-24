// Name:     ADVAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ADVAccount_hpp
#define ASX_ADVAccount_hpp

namespace aiMarketFields {
//Forword decalaration
class ADVAccount;
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

class ADVAccount : public StatisticAccount  {

/**
 * 	Class Description:
 * 		This account stores the average daily volume computed over
 *       3 months of data
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
	ADVAccount();
	ADVAccount(const ADVAccount* ptr);
	ADVAccount(const ADVAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_ADVAccount();

	//Destructor
	virtual ~ADVAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_ADVAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_ADVAccount(string fname);
	virtual void fscan(string fname);
	void fscan_ADVAccount(string fname);

	//Reset
	virtual void reset();
	void reset_ADVAccount();


	/** ------ Static Functions ----------------*/

	static ADVAccount* instance();

	static ADVAccount* instance_fscan(string fname);

   static ADVAccount* __ptr_ADVAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

