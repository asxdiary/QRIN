// Name:     AcctDb.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_AcctDb_hpp
#define ASX_AcctDb_hpp

namespace aiAcctDb {
//Forword decalaration
class AcctDb;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Db.hpp"
#include "FS.hpp"
#include "FSDb.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiAcctDb {

class AcctDb : public Db  {

/**
 * 	Class Description:
 * 		This class stores a database of FSDb 
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
	AcctDb();
	AcctDb(const AcctDb* ptr);
	AcctDb(const AcctDb& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_AcctDb();

	//Destructor
	virtual ~AcctDb(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_AcctDb(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_AcctDb(string fname);
	virtual void fscan(string fname);
	void fscan_AcctDb(string fname);

	//Reset
	virtual void reset();
	void reset_AcctDb();


	/** ------ Static Functions ----------------*/

	static AcctDb* instance();

	static AcctDb* instance_fscan(string fname);

	virtual AcctDb* instantiate();

	/** ----------  Non-standard functions start here -----------*/

   virtual FS* fs(Company* cmp, UtilDate* end_d, UtilDate* dh, 
                  int& xval);

   virtual FSDb* create_eaodb(Object* dbobj);

   virtual AcctDb* agg(vector<UtilDate*>* end_dv, UtilDate* dh, int& xval, AcctDb* db=NULL);

   virtual AcctDb* aggQ(list<UtilDate*>* end_dL, UtilDate* dh, int& xval, AcctDb* db=NULL);

   virtual AcctDb* aggA2(list<UtilDate*>* end_dL, UtilDate* dh, int& xval, AcctDb* db=NULL);

   virtual AcctDb* interpolateA(list<UtilDate*>* dL, int& xcal, AcctDb* db=NULL);

   virtual AcctDb* interpolateA2(UtilDate* dh, 
                                 list<UtilDate*>* dL, int& xcal, AcctDb* db=NULL);

};

};

#endif

