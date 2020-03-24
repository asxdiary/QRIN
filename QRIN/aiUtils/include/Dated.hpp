// Name:     Dated.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_Dated_hpp
#define ASX_Dated_hpp

namespace aiUtils {
//Forword decalaration
class Dated;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "UtilDate.hpp"
#include "Object.hpp"
#include "Object_templates.hpp"

using namespace std;
using namespace aiUtils;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiUtils {

class Dated : public Object  {

/**
 * 	Class Description:
 * 		This class is used to represent the date at which the information
 * 		becomes available; all access functions to sub-classes of this
 * 		class should have an explicit date attribute that is specified as
 * 		the first argument
 * 
 * 	Assumptions:
 * 		We assume that the information becomes available just
 * 		available before the end of the day
 * 
 * 	Objects:
 * 		d: date at which the object information becomes available
 * 
 * 	Ownership:
 * 		All objects owned
 * 
 */

private:
/**	Data Members */
	UtilDate* _d;

protected: 

	/** Protected Constructors */
	Dated();
	Dated(const Dated* ptr);
	Dated(const Dated& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

	/** Protected data Set function to avoid accidental reset of 
    * date; note that since d is not a protected member, an unscrupulous
    * agent can still change the date directly */
	virtual void set_d(UtilDate* _obj);

public:

	//Initializer
	virtual void init(UtilDate* d);
	void init_Dated(UtilDate* d);
	virtual void init_d(UtilDate* d);

	//Destructor
	virtual ~Dated(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_Dated(); 
	virtual void cleanMem_d();

	/** Public Data Access Functions */
	virtual UtilDate* d();

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_Dated(string fname);
	virtual void fscan(string fname);
	void fscan_Dated(string fname);

	//Reset
	virtual void reset();
	void reset_Dated();


	/** ------ Static Functions ----------------*/

	static Dated* instance(UtilDate* d);

	static Dated* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual bool validate(UtilDate* d);

};

};

#endif

