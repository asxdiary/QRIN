// Name:     LegalEnvironmentalAROAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_LegalEnvironmentalAROAccount_hpp
#define ASX_LegalEnvironmentalAROAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class LegalEnvironmentalAROAccount;
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

class LegalEnvironmentalAROAccount : public PositionAccount  {

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
	LegalEnvironmentalAROAccount();
	LegalEnvironmentalAROAccount(const LegalEnvironmentalAROAccount* ptr);
	LegalEnvironmentalAROAccount(const LegalEnvironmentalAROAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_LegalEnvironmentalAROAccount();

	//Destructor
	virtual ~LegalEnvironmentalAROAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_LegalEnvironmentalAROAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_LegalEnvironmentalAROAccount(string fname);
	virtual void fscan(string fname);
	void fscan_LegalEnvironmentalAROAccount(string fname);

	//Reset
	virtual void reset();
	void reset_LegalEnvironmentalAROAccount();


	/** ------ Static Functions ----------------*/

	static LegalEnvironmentalAROAccount* instance();

	static LegalEnvironmentalAROAccount* instance_fscan(string fname);

   static LegalEnvironmentalAROAccount* __ptr_LegalEnvironmentalAROAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

