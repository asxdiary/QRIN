// Name:     AvailabilityDateAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_AvailabilityDateAccount_hpp
#define ASX_AvailabilityDateAccount_hpp

namespace aiDbAccounts {
//Forword decalaration
class AvailabilityDateAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DateAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;
using namespace aiDbAccounts;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiDbAccounts {

class AvailabilityDateAccount : public DateAccount  {

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
	AvailabilityDateAccount();
	AvailabilityDateAccount(const AvailabilityDateAccount* ptr);
	AvailabilityDateAccount(const AvailabilityDateAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_AvailabilityDateAccount();

	//Destructor
	virtual ~AvailabilityDateAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_AvailabilityDateAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_AvailabilityDateAccount(string fname);
	virtual void fscan(string fname);
	void fscan_AvailabilityDateAccount(string fname);

	//Reset
	virtual void reset();
	void reset_AvailabilityDateAccount();


	/** ------ Static Functions ----------------*/

	static AvailabilityDateAccount* instance();

	static AvailabilityDateAccount* instance_fscan(string fname);

   static AvailabilityDateAccount* __ptr_AvailabilityDateAccount;

	/** ----------  Non-standard functions start here -----------*/

   virtual void agg(ObjectDb* odb, vector<ObjectDb*>* odbv, UtilDate* dh, int& xval);
   virtual double agg_guts(vector<ObjectDb*>* odbv, UtilDate* dh, int& xval);

};

};

#endif

