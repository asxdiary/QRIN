// Name:     DailyMarketDbGen.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_DailyMarketDbGen_hpp
#define ASX_DailyMarketDbGen_hpp

namespace aiMarketDbUtils {
//Forword decalaration
class DailyMarketDbGen;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DbGen.hpp"
#include "Db.hpp"
#include "ObjectDb.hpp"
#include "UtilDate.hpp"
#include "CompanyUniverse.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiDb;
using namespace aiDbUtils;
using namespace aiMarketDbUtils;
using namespace aiFin;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiMarketDbUtils {

class DailyMarketDbGen : public DbGen  {

/**
 * 	Class Description:
 * 		This class is used to load daily market information
 * 
 * 	Assumptions:
 * 		None
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
	DailyMarketDbGen();
	DailyMarketDbGen(const DailyMarketDbGen* ptr);
	DailyMarketDbGen(const DailyMarketDbGen& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(CompanyUniverse* univ);
	void init_DailyMarketDbGen();

	//Destructor
	virtual ~DailyMarketDbGen(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_DailyMarketDbGen(); 

	/** Public Data Access Functions */
   virtual CompanyUniverse* univ();

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_DailyMarketDbGen(string fname);
	virtual void fscan(string fname);
	void fscan_DailyMarketDbGen(string fname);

	//Reset
	virtual void reset();
	void reset_DailyMarketDbGen();


	/** ------ Static Functions ----------------*/

	static DailyMarketDbGen* instance(CompanyUniverse* univ);

	static DailyMarketDbGen* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual void algo_exec_guts(unordered_map<string,int>* header, string* row);

};

};

#endif

