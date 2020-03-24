// Name:     FSDb.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_FSDb_hpp
#define ASX_FSDb_hpp

namespace aiAcctDb {
//Forword decalaration
class FSDb;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "EADatedObjectDb.hpp"
#include "Company.hpp"
#include "FS.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiFin;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiAcctDb {

class FSDb : public EADatedObjectDb  {

/**
 * 	Class Description:
 * 		This class is used to store databases of financial statements
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
	FSDb();
	FSDb(const FSDb* ptr);
	FSDb(const FSDb& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(Company* dbobj);
	void init_FSDb();

	//Destructor
	virtual ~FSDb(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_FSDb(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_FSDb(string fname);
	virtual void fscan(string fname);
	void fscan_FSDb(string fname);

	//Reset
	virtual void reset();
	void reset_FSDb();


	/** ------ Static Functions ----------------*/

	static FSDb* instance(Company* dbobj);

	static FSDb* instance_fscan(string fname);

	virtual FSDb* instantiate(Object* dbobj);

	/** ----------  Non-standard functions start here -----------*/

   virtual FS* fs(Company* cmp, UtilDate* end_d, UtilDate* dh, 
                        int& xval);

};

};

#endif

