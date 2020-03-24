// Name:     ADRIndicatorDbGen.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_ADRIndicatorDbGen_hpp
#define ASX_ADRIndicatorDbGen_hpp

namespace aiMarketDbUtils {
//Forword decalaration
class ADRIndicatorDbGen;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DbGen.hpp"
#include "Db.hpp"
#include "CompanyUniverse.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDbUtils;
using namespace aiDb;
using namespace aiMarketDbUtils;
using namespace aiFin;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiMarketDbUtils {

class ADRIndicatorDbGen : public DbGen  {

/**
 * 	Class Description:
 * 		This class is used to load the stock domicile information
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
	ADRIndicatorDbGen();
	ADRIndicatorDbGen(const ADRIndicatorDbGen* ptr);
	ADRIndicatorDbGen(const ADRIndicatorDbGen& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(CompanyUniverse* univ);
	void init_ADRIndicatorDbGen();

	//Destructor
	virtual ~ADRIndicatorDbGen(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_ADRIndicatorDbGen(); 

	/** Public Data Access Functions */
   virtual CompanyUniverse* univ();
   virtual Db* mdl();

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_ADRIndicatorDbGen(string fname);
	virtual void fscan(string fname);
	void fscan_ADRIndicatorDbGen(string fname);

	//Reset
	virtual void reset();
	void reset_ADRIndicatorDbGen();


	/** ------ Static Functions ----------------*/

	static ADRIndicatorDbGen* instance(CompanyUniverse* univ);

	static ADRIndicatorDbGen* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual void algo_exec_guts(unordered_map<string,int>* header, string* row);

   virtual Model* gen_mdl();
   virtual Db* extract_mdl();

};

};

#endif

