// Name:     DomicileAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DomicileAccount_hpp
#define ASX_DomicileAccount_hpp

namespace aiMarketFields {
//Forword decalaration
class DomicileAccount;
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

class DomicileAccount : public StringDbAccount  {

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
	DomicileAccount();
	DomicileAccount(const DomicileAccount* ptr);
	DomicileAccount(const DomicileAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_DomicileAccount();

	//Destructor
	virtual ~DomicileAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_DomicileAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_DomicileAccount(string fname);
	virtual void fscan(string fname);
	void fscan_DomicileAccount(string fname);

	//Reset
	virtual void reset();
	void reset_DomicileAccount();


	/** ------ Static Functions ----------------*/

	static DomicileAccount* instance();

	static DomicileAccount* instance_fscan(string fname);

   static DomicileAccount* __ptr_DomicileAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

