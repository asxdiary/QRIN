// Name:     DateAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DateAccount_hpp
#define ASX_DateAccount_hpp

namespace aiDbAccounts {
//Forword decalaration
class DateAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DoubleDbAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbAccounts;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiDbAccounts {

class DateAccount : public DoubleDbAccount  {

/**
 * 	Class Description:
 * 	   This account is used to store various kinds of dates (start, end, availiability)
 * 
 * 	Assumptions:
 * 		The dates are stored as double using the UtilDate::icode functionality
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
	DateAccount();
	DateAccount(const DateAccount* ptr);
	DateAccount(const DateAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_DateAccount();

	//Destructor
	virtual ~DateAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_DateAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_DateAccount(string fname);
	virtual void fscan(string fname);
	void fscan_DateAccount(string fname);

	//Reset
	virtual void reset();
	void reset_DateAccount();


	/** ------ Static Functions ----------------*/

	static DateAccount* instance();

	static DateAccount* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   /** Disable interpolation of date accounts */
   virtual void interpolate(ObjectDb* odb1, ObjectDb* odb2, ObjectDb* odb,
                            int& xval);

};

};

#endif

