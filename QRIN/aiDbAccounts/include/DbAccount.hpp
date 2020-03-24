// Name:     DbAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DbAccount_hpp
#define ASX_DbAccount_hpp

namespace aiDbAccounts {
//Forword decalaration
class DbAccount;
};

namespace aiDb {
//Forword decalaration
class ObjectDb;
};

#include <vector>
#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "UtilDate.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiDbAccounts {

class DbAccount : public Object  {

/**
 * 	Class Description:
 * 		This class is used to represent an arbitrary database account
 * 		e.g revenue account, COGS account, annual returns, etc
 * 
 * 	Assumptions:
 * 		None
 * 
 * 	Objects: (P=Parent; NO=Not Ownwed; O=Owned)
 * 		type: type of the account (Flow, Position, Growth, etc)
 * 		dtype: type of underlying data (double, string, etc)
 * 		nhistory: number of Db required to compute the DbAccount;
 * 		for instance, revenue growth requires two FS.
 * 
 * 	Ownership:
 * 		Indicated above
 * 
 */

private:
/**	Data Members */
	string _type;
	string _dtype;
	int _nhistory;

protected: 

	/** Protected Constructors */
	DbAccount();
	DbAccount(const DbAccount* ptr);
	DbAccount(const DbAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

	/** Protected data Set functions */
   virtual void set_type(string obj);
   virtual void set_dtype(string obj);

public:

	//Initializer
	virtual void init(string type, string dtype);
	void init_DbAccount(string type, string dtype);
	virtual void init_type(string obj);
	virtual void init_dtype(string obj);
	virtual void init_nhistory();

	//Destructor
	virtual ~DbAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_DbAccount(); 

	/** Public Data Access Functions */
	virtual string type();
	virtual string dtype();
	virtual int nhistory();

	/** Public data Set functions */
   virtual void set_nhistory(int obj);

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_DbAccount(string fname);
	virtual void fscan(string fname);
	void fscan_DbAccount(string fname);

	//Reset
	virtual void reset();
	void reset_DbAccount();


	/** ------ Static Functions ----------------*/

	static DbAccount* instance(string type, string dtype);

	static DbAccount* instance_fscan(string fname);

   static bool check_type(string obj);
   static bool check_dtype(string obj);

	/** ----------  Non-standard functions start here -----------*/

   virtual void populate(ObjectDb* odb, string val, int& xval);

   virtual void agg(ObjectDb* odb, vector<ObjectDb*>* odbv, UtilDate* dh, int& xval);

   /** This function computes the DbAccount under consideration
    * - if all goes well, xval is set to 0
    * - the last element of odbv is updated by the computed value
    * - if odbv->size < nhistory then xval is set to 1
    *   
    * Assumptions:
    *    - The final computed value (if any) is stored in the last element of
    *    odbv
    *    - odbv is assumed to be in chronological order */
   virtual void compute(vector<ObjectDb*>* odbv, int& xval);

   /** This function copies the account from odb1 (if available) to odb2 */
   virtual void copy(UtilDate* dh, ObjectDb* odb1, ObjectDb* odb2, int& xval);

   virtual void interpolate(ObjectDb* odb1, ObjectDb* odb2, ObjectDb* odb,
                            int& xval);

};

};

#endif

