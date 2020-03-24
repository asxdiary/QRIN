// Name:     BookValueAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_BookValueAccount_hpp
#define ASX_BookValueAccount_hpp

namespace aiAcctFields {
//Forword decalaration
class BookValueAccount;
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

class BookValueAccount : public PositionAccount  {

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
	BookValueAccount();
	BookValueAccount(const BookValueAccount* ptr);
	BookValueAccount(const BookValueAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_BookValueAccount();

	//Destructor
	virtual ~BookValueAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_BookValueAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_BookValueAccount(string fname);
	virtual void fscan(string fname);
	void fscan_BookValueAccount(string fname);

	//Reset
	virtual void reset();
	void reset_BookValueAccount();


	/** ------ Static Functions ----------------*/

	static BookValueAccount* instance();

	static BookValueAccount* instance_fscan(string fname);

   static BookValueAccount* __ptr_BookValueAccount;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

