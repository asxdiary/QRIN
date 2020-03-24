// Name:     LiabilitiesStockholdersEquityAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_LiabilitiesStockholdersEquityAccount_hpp
#define ASX_LiabilitiesStockholdersEquityAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class LiabilitiesStockholdersEquityAccount;
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

class LiabilitiesStockholdersEquityAccount : public PositionAccount  {

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
	LiabilitiesStockholdersEquityAccount();
	LiabilitiesStockholdersEquityAccount(const LiabilitiesStockholdersEquityAccount* ptr);
	LiabilitiesStockholdersEquityAccount(const LiabilitiesStockholdersEquityAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_LiabilitiesStockholdersEquityAccount();

	//Destructor
	virtual ~LiabilitiesStockholdersEquityAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_LiabilitiesStockholdersEquityAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_LiabilitiesStockholdersEquityAccount(string fname);
	virtual void fscan(string fname);
	void fscan_LiabilitiesStockholdersEquityAccount(string fname);

	//Reset
	virtual void reset();
	void reset_LiabilitiesStockholdersEquityAccount();


	/** ------ Static Functions ----------------*/

	static LiabilitiesStockholdersEquityAccount* instance();

	static LiabilitiesStockholdersEquityAccount* instance_fscan(string fname);

   static LiabilitiesStockholdersEquityAccount* __ptr_LiabilitiesStockholdersEquityAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

