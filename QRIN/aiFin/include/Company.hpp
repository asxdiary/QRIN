// Name:     Company.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_Company_hpp
#define ASX_Company_hpp

namespace aiFin {
//Forword decalaration
class Company;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "Model.hpp"
#include "CompanyIdentifier.hpp"
#include "unordered_map"

using namespace std;
using namespace aiUtils;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiFin {

class Company : public Model  {

/**
 * 	Class Description:
 * 		This class is used to store "Company" information; notably,
 * 		company is defined in the corporate finance sense and does not
 * 		necessarily refer to a specific security
 * 
 * 	Assumptions:
 * 		None
 * 
 * 	Objects:
 * 		id: company name (stored under Model)
 * 		cid: primary identifier type
 * 		cidm: map[Identifier->string] alternative ids
 * 
 * 	Ownership:
 * 		All objects owned
 * 		cf. CompanyIdentifier implements singleton
 * 
 */

private:
/**	Data Members */
	CompanyIdentifier* _cid;
	unordered_map<CompanyIdentifier*,string>* _cidm;

protected: 

	/** Protected Constructors */
	Company();
	Company(const Company* ptr);
	Company(const Company& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(CompanyIdentifier* cid, string id);
	void init_Company(CompanyIdentifier* cid);
	virtual void init_cid(CompanyIdentifier* cid);
	virtual void init_cidm();

	//Destructor
	virtual ~Company(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_Company(); 
	virtual void cleanMem_cid();
	virtual void cleanMem_cidm();

	/** Public Data Access Functions */
	virtual CompanyIdentifier* cid();
	virtual unordered_map<CompanyIdentifier*,string>* cidm();
   virtual string cidm(CompanyIdentifier* cid);

	/** Public data Set functions */
   virtual void set_cidm(CompanyIdentifier* cid, string id);

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_Company(string fname);
	virtual void fscan(string fname);
	void fscan_Company(string fname);

	//Reset
	virtual void reset();
	void reset_Company();


	/** ------ Static Functions ----------------*/

	static Company* instance(CompanyIdentifier* cid, string id);

	static Company* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

};

};

#endif

