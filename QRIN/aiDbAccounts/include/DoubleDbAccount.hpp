// Name:     DoubleDbAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DoubleDbAccount_hpp
#define ASX_DoubleDbAccount_hpp

namespace aiDbAccounts {
//Forword decalaration
class DoubleDbAccount;
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

class DoubleDbAccount : public DbAccount  {

/**
 * 	Class Description:
 * 		Extension of DbAccount to store double attributes
 * 
 * 	Assumptions:
 * 	   None
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
	DoubleDbAccount();
	DoubleDbAccount(const DoubleDbAccount* ptr);
	DoubleDbAccount(const DoubleDbAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(string type);
	void init_DoubleDbAccount();

	//Destructor
	virtual ~DoubleDbAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_DoubleDbAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_DoubleDbAccount(string fname);
	virtual void fscan(string fname);
	void fscan_DoubleDbAccount(string fname);

	//Reset
	virtual void reset();
	void reset_DoubleDbAccount();


	/** ------ Static Functions ----------------*/

	static DoubleDbAccount* instance(string type);

	static DoubleDbAccount* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual void populate(ObjectDb* odb, string val, int& xval);
   virtual void populate(ObjectDb* odb, double val, int& xval);

   /** This function returns true if val takes any of the following values listed
    * in the code; the list is not mentioned here to avoid duplicate 
    * rendering
    *
    * Note: This function should be considered for revamping in future
    * to commission it in a systematic fashion */
   virtual bool isEmpty(string val);

   /** The implementation in this class simply checks if the Account
    * has an available value */
   virtual void compute(vector<ObjectDb*>* odbv, int& xval);

   virtual void agg(ObjectDb* odb, vector<ObjectDb*>* odbv, UtilDate* dh, int& xval);
   virtual double agg_guts(vector<ObjectDb*>* odbv, UtilDate* dh, int& xval);

   virtual void copy(UtilDate* dh, ObjectDb* odb1, ObjectDb* odb2, int& xval);

   /** This function performs a simple interpolation based on uniform
    * distribution assumption */
   virtual void interpolate(ObjectDb* odb1, ObjectDb* odb2, ObjectDb* odb,
                            int& xval);

};

};

#endif

