// Name:     StringDbAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_StringDbAccount_hpp
#define ASX_StringDbAccount_hpp

namespace aiDbAccounts {
//Forword decalaration
class StringDbAccount;
};

namespace aiDb {
//Forword decalaration
class ObjectDb;
};


#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DbAccount.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiDbAccounts {

class StringDbAccount : public DbAccount  {

/**
 * 	Class Description:
 * 		Extension of DbAccount to store string attributes
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
	StringDbAccount();
	StringDbAccount(const StringDbAccount* ptr);
	StringDbAccount(const StringDbAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(string type);
	void init_StringDbAccount();

	//Destructor
	virtual ~StringDbAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_StringDbAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_StringDbAccount(string fname);
	virtual void fscan(string fname);
	void fscan_StringDbAccount(string fname);

	//Reset
	virtual void reset();
	void reset_StringDbAccount();


	/** ------ Static Functions ----------------*/

	static StringDbAccount* instance(string type);

	static StringDbAccount* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual void populate(ObjectDb* odb, string val, int& xval);

   /** The implementation in this class simply checks if the Account
    * has an available value */
   virtual void compute(vector<ObjectDb*>* odbv, int& xval);

   virtual void agg(ObjectDb* odb, vector<ObjectDb*>* odbv, UtilDate* dh, int& xval);
   virtual string agg_guts(vector<ObjectDb*>* odbv, UtilDate* dh, int& xval);

   virtual void copy(UtilDate* dh, ObjectDb* odb1, ObjectDb* odb2, int& xval);

   /** Both odb1 and odb2 need to have a value of this account.
    *   If odb and odb1 have same start/end dates use account from odb1
    *   else if odb and odb2 have same start/end dates use account from odb2
    *   else use the account information from odb2 */
   virtual void interpolate(ObjectDb* odb1, ObjectDb* odb2, ObjectDb* odb,
                            int& xval);

};

};

#endif

