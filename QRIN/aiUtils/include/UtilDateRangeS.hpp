// Name:     UtilDateRangeS.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_UtilDateRangeS_hpp
#define ASX_UtilDateRangeS_hpp

namespace aiUtils {
//Forword decalaration
class UtilDateRangeS;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "UtilDateRange.hpp"
#include "UtilDate.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiUtils;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiUtils {

class UtilDateRangeS : public Object  {

/**
 * 	Class Description:
 * 		This class contains a collection of UtilDateRange objects
 * 
 * 	Assumptions:
 * 		None
 * 
 * 	Objects:
 * 		drS: collection of UtilDateRange objects
 * 
 * 	Ownership:
 * 		All objects owned
 * 
 */

private:
/**	Data Members */
	set<UtilDateRange*>* _drS;

protected: 

	/** Protected Constructors */
	UtilDateRangeS();
	UtilDateRangeS(const UtilDateRangeS* ptr);
	UtilDateRangeS(const UtilDateRangeS& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_UtilDateRangeS();
	virtual void init_drS();

	//Destructor
	virtual ~UtilDateRangeS(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_UtilDateRangeS(); 
	virtual void cleanMem_drS();

	/** Public Data Access Functions */
	virtual set<UtilDateRange*>* drS();

	/** Public data Set functions */
	virtual void add(UtilDateRange* _obj);
	virtual void add(UtilDate* sd, UtilDate* ed);

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_UtilDateRangeS(string fname);
	virtual void fscan(string fname);
	void fscan_UtilDateRangeS(string fname);

	//Reset
	virtual void reset();
	void reset_UtilDateRangeS();


	/** ------ Static Functions ----------------*/

	static UtilDateRangeS* instance();

	static UtilDateRangeS* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual bool overlap(UtilDate* ptr);
   virtual bool overlap(UtilDateRange* ptr);

};

};

#endif

