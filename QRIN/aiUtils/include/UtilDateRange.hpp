// Name:     UtilDateRange.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_UtilDateRange_hpp
#define ASX_UtilDateRange_hpp

namespace aiUtils {
//Forword decalaration
class UtilDateRange;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "UtilDate.hpp"

using namespace std;
using namespace aiUtils;
using namespace aiUtils;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiUtils {

class UtilDateRange : public Object  {

/**
 * 	Class Description:
 * 		This class is used to model date ranges defined by a starting
 * 		date and an ending date
 * 
 * 	Assumptions:
 * 		- at least one of start and end dates is non-NULL
 * 		- if both sd and ed are non-NULL, then ed is NOT before sd
 * 
 * 	Objects:
 * 		sd: start date
 * 		ed: end date
 * 
 * 	Ownership:
 * 		All objects owned
 * 
 */

private:
/**	Data Members */
	UtilDate* _sd;
	UtilDate* _ed;

protected: 

	/** Protected Constructors */
	UtilDateRange();
	UtilDateRange(const UtilDateRange* ptr);
	UtilDateRange(const UtilDateRange& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init(UtilDate* sd, UtilDate* ed);
	void init_UtilDateRange(UtilDate* sd, UtilDate* ed);
	virtual void init_sd(UtilDate* obj);
	virtual void init_ed(UtilDate* obj);

	//Destructor
	virtual ~UtilDateRange(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_UtilDateRange(); 
	virtual void cleanMem_sd();
	virtual void cleanMem_ed();

	/** Public Data Access Functions */
	virtual UtilDate* sd();
	virtual UtilDate* ed();

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_UtilDateRange(string fname);
	virtual void fscan(string fname);
	void fscan_UtilDateRange(string fname);

	//Reset
	virtual void reset();
	void reset_UtilDateRange();


	/** ------ Static Functions ----------------*/

	static UtilDateRange* instance(UtilDate* sd, UtilDate* ed);

	static UtilDateRange* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   /** if ptr==NULL then return false */
   virtual bool overlap(UtilDate* ptr);
   virtual bool overlap(UtilDateRange* ptr);

};

};

#endif

