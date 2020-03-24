// Name:     CompanyIdentifier.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CompanyIdentifier_hpp
#define ASX_CompanyIdentifier_hpp

namespace aiFin {
//Forword decalaration
class CompanyIdentifier;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Object.hpp"

using namespace std;
using namespace aiUtils;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiFin {

class CompanyIdentifier : public Object  {

/**
 * 	Class Description:
 * 		This class is used to designate various kinds of company identifiers
 * 		such as CUSIP, GVKEY, etc
 * 
 * 	Assumptions:
 * 	   Implements specialized form of singleton pattern
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
	CompanyIdentifier();
	CompanyIdentifier(const CompanyIdentifier* ptr);
	CompanyIdentifier(const CompanyIdentifier& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(string id);
	void init_CompanyIdentifier(string id);

	//Destructor
	virtual ~CompanyIdentifier(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_CompanyIdentifier(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_CompanyIdentifier(string fname);
	virtual void fscan(string fname);
	void fscan_CompanyIdentifier(string fname);

	//Reset
	virtual void reset();
	void reset_CompanyIdentifier();


	/** ------ Static Functions ----------------*/

	static CompanyIdentifier* instance(string id);

	static CompanyIdentifier* instance_fscan(string fname);

   static CompanyIdentifier* AIID;
   static CompanyIdentifier* name;

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

