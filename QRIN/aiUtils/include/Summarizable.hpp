// Name:     Summarizable.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_Summarizable_hpp
#define ASX_Summarizable_hpp

namespace aiUtils {
//Forword decalaration
class Summarizable;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"

using namespace std;
using namespace aiUtils;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiUtils {

class Summarizable {

/**
 * 	Class Description:
 * 		This class serves as an interface for classes that 
 * 		support "summary" function; such a function is helpful
 * 		to summarize a complicated object in the form a csv file
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
	Summarizable();
	Summarizable(const Summarizable* ptr);
	Summarizable(const Summarizable& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_Summarizable();

	//Destructor
	virtual ~Summarizable(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_Summarizable(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_Summarizable(string fname);
	virtual void fscan(string fname);
	void fscan_Summarizable(string fname);

	//Reset
	virtual void reset();
	void reset_Summarizable();


	/** ------ Static Functions ----------------*/

	static Summarizable* instance();

	static Summarizable* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual void summary(list<unordered_map<string,string>*>*& L, set<string>* headerS=NULL);
   virtual void fprint_summary(string fname, set<string>* headerS=NULL);

};

};

#endif

