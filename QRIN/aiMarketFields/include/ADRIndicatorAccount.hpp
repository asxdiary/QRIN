// Name:     ADRIndicatorAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ADRIndicatorAccount_hpp
#define ASX_ADRIndicatorAccount_hpp

namespace aiMarketFields {
//Forword decalaration
class ADRIndicatorAccount;
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

class ADRIndicatorAccount : public StringDbAccount  {

/**
 * 	Class Description:
 * 	   This account stores ADR indicator flag; a "1" indicates that the 
 * 	   incumbent object is an ADR
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
	ADRIndicatorAccount();
	ADRIndicatorAccount(const ADRIndicatorAccount* ptr);
	ADRIndicatorAccount(const ADRIndicatorAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_ADRIndicatorAccount();

	//Destructor
	virtual ~ADRIndicatorAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_ADRIndicatorAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_ADRIndicatorAccount(string fname);
	virtual void fscan(string fname);
	void fscan_ADRIndicatorAccount(string fname);

	//Reset
	virtual void reset();
	void reset_ADRIndicatorAccount();


	/** ------ Static Functions ----------------*/

	static ADRIndicatorAccount* instance();

	static ADRIndicatorAccount* instance_fscan(string fname);

   static ADRIndicatorAccount* __ptr_ADRIndicatorAccount;

	/** ----------  Non-standard functions start here -----------*/

   virtual bool isADR(string adr_str);

};

};

#endif

