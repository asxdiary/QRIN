// Name:     PositionAccount.hpp
// Author:   Anureet Saxena
//-----------------------------------------------------------------------------
#ifndef ASX_PositionAccount_hpp
#define ASX_PositionAccount_hpp

namespace aiDbAccounts {
//Forword decalaration
class PositionAccount;
};

#include "Utils.hpp"
#include "Utils_templates.hpp"
#include "DoubleDbAccount.hpp"

using namespace std;
using namespace aiUtils;


//Parameters/////////////////////////////
/////////////////////////////////////////

namespace aiDbAccounts {

class PositionAccount : public DoubleDbAccount  {

/**
 * 	Class Description:
 * 		This is used to store point-in-time status atributes.
 * 		e.g assets, liabilities, wealth, etc
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
	PositionAccount();
	PositionAccount(const PositionAccount* ptr);
	PositionAccount(const PositionAccount& obj);

/**	init_NULL initializes all memory related data members to 
	NULL to make sure nothing is left unclean when copy or any
	other function is called This function must NOT be virtual*/
	void init_NULL();

public:

	//Initializer
	virtual void init();
	void init_PositionAccount();

	//Destructor
	virtual ~PositionAccount(); 

	 /** Memory Clean Up functions*/
	virtual void cleanMem(); 
	void cleanMem_PositionAccount(); 

	/** Public Data Access Functions */

	/** Public data Set functions */

	//Access classname dynamically 
	virtual string className() const;

	//For error message handling
	void myerr_msg(string msg, string func);

	//Printing and Scaning Options
	virtual void fprint(string fname);
	void fprint_PositionAccount(string fname);
	virtual void fscan(string fname);
	void fscan_PositionAccount(string fname);

	//Reset
	virtual void reset();
	void reset_PositionAccount();


	/** ------ Static Functions ----------------*/

	static PositionAccount* instance();

	static PositionAccount* instance_fscan(string fname);

	/** ----------  Non-standard functions start here -----------*/

   virtual double agg_guts(vector<ObjectDb*>* odbv, UtilDate* dh, int& xval);

};

};

#endif

