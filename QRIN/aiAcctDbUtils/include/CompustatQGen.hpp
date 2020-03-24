// Name:     CompustatQGen.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_CompustatQGen_hpp
#define ASX_CompustatQGen_hpp

namespace aiAcctDbUtils {
//Forword decalaration
class CompustatQGen;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DbGen.hpp"
#include "AcctDb.hpp"
#include "CompanyUniverse.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbUtils;
using namespace aiDb;
using namespace aiAcctDbUtils;
using namespace aiFin;
using namespace aiAcctDb;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiAcctDbUtils {

class CompustatQGen : public DbGen  {

/**
 * 	Class Description:
 * 		This class is used to load the Quarterly Compustat data
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
	CompustatQGen();
	CompustatQGen(const CompustatQGen* ptr);
	CompustatQGen(const CompustatQGen& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(CompanyUniverse* univ);
	void init_CompustatQGen();

	//Destructor
	virtual ~CompustatQGen(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_CompustatQGen(); 

	/** Public Data Access Functions */
   virtual CompanyUniverse* univ();
   virtual AcctDb* mdl();

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_CompustatQGen(string fname);
	virtual void fscan(string fname);
	void fscan_CompustatQGen(string fname);

	//Reset
	virtual void reset();
	void reset_CompustatQGen();


	/** ------ Static Functions ----------------*/

	static CompustatQGen* instance(CompanyUniverse* univ);

	static CompustatQGen* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual void algo_exec_guts(unordered_map<string,int>* header, string* row);

   virtual Model* gen_mdl();
   virtual AcctDb* extract_mdl();

};

};

#endif

