// Name:     CompanyUniverse.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CompanyUniverse_hpp
#define ASX_CompanyUniverse_hpp

namespace aiFin {
//Forword decalaration
class CompanyUniverse;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "CompanyIdentifier.hpp"
#include "ObjectUniverse.hpp"
#include "Company.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiFin;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiFin {

class CompanyUniverse : public ObjectUniverse  {

/**
 * 	Class Description:
 * 		This class is used to store a group of companies, and acts as
 * 		the primary owner of Company pointers
 * 
 * 	Assumptions:
 * 		None
 * 
 * 	Objects: (P=Parent; NO=Not Ownwed; O=Owned)
 * 		NO cid : CompanyIdentifier
 * 
 * 	Ownership:
 * 		Indicated above
 * 
 */

private:
/**	Data Members */
	CompanyIdentifier* _cid;

protected: 

	/** Protected Constructors */
	CompanyUniverse();
	CompanyUniverse(const CompanyUniverse* ptr);
	CompanyUniverse(const CompanyUniverse& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(CompanyIdentifier* cid);
	void init_CompanyUniverse(CompanyIdentifier* cid);
	virtual void init_cid(CompanyIdentifier* cid);

	//Destructor
	virtual ~CompanyUniverse(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_CompanyUniverse(); 
	virtual void cleanMem_cid();

	/** Public Data Access Functions */
	virtual CompanyIdentifier* cid();

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_CompanyUniverse(string fname);
	virtual void fscan(string fname);
	void fscan_CompanyUniverse(string fname);

	//Reset
	virtual void reset();
	void reset_CompanyUniverse();


	/** ------ Static Functions ----------------*/

	static CompanyUniverse* instance(CompanyIdentifier* cid);

	static CompanyUniverse* instance_fscan(string fname);

   virtual CompanyUniverse* instantiate();

	/** ----------  Non-standard functions start here -----------*/

   virtual Company* obj(string id, bool create_flag=false);
   virtual Company* gen_obj_guts(string id);

   virtual CompanyUniverse* sub(int n, string* cmap, bool ignore_flag=false);
   virtual CompanyUniverse* sub(set<string>* S, bool ignore_flag=false);

};

};

#endif

