// Name:     FS.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_FS_hpp
#define ASX_FS_hpp

namespace aiAcctDb {
//Forword decalaration
class FS;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "ObjectDb.hpp"
#include "Company.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiFin;
using namespace aiDb;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiAcctDb {

class FS : public ObjectDb  {

/**
 * 	Class Description:
 * 		This class is used to store financial statement information which includes
 * 		B/S, I/S, C/F data, and also derived ratios.
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
	FS();
	FS(const FS* ptr);
	FS(const FS& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(Company* dbobj, UtilDate* end_d, UtilDate* dh, UtilDate* start_d);
	void init_FS();

	//Destructor
	virtual ~FS(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_FS(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_FS(string fname);
	virtual void fscan(string fname);
	void fscan_FS(string fname);

	//Reset
	virtual void reset();
	void reset_FS();


	/** ------ Static Functions ----------------*/

	static FS* instance(Company* dbobj, UtilDate* end_d, UtilDate* dh, UtilDate* start_d);

	static FS* instance_fscan(string fname);

	virtual FS* instantiate(Object* dbobj, UtilDate* end_d, UtilDate* dh, UtilDate* start_d);

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

