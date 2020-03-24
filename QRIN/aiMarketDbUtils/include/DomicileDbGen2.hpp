// Name:     DomicileDbGen2.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DomicileDbGen2_hpp
#define ASX_DomicileDbGen2_hpp

namespace aiMarketDbUtils {
//Forword decalaration
class DomicileDbGen2;
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

class DomicileDbGen2 : public DbGen  {

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
	DomicileDbGen2();
	DomicileDbGen2(const DomicileDbGen2* ptr);
	DomicileDbGen2(const DomicileDbGen2& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(CompanyUniverse* univ);
	void init_DomicileDbGen2();

	//Destructor
	virtual ~DomicileDbGen2(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_DomicileDbGen2(); 

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
	void fprint_DomicileDbGen2(string fname);
	virtual void fscan(string fname);
	void fscan_DomicileDbGen2(string fname);

	//Reset
	virtual void reset();
	void reset_DomicileDbGen2();


	/** ------ Static Functions ----------------*/

	static DomicileDbGen2* instance(CompanyUniverse* univ);

	static DomicileDbGen2* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual void algo_exec_guts(unordered_map<string,int>* header, string* row);

   virtual Model* gen_mdl();
   virtual Db* extract_mdl();

};

};

#endif

